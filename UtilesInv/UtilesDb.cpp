#include "StdAfx.h"
#include "UtilesDb.h"


using namespace UtilesInv;

UtilesDb::UtilesDb(void) {
	try {
		con = gcnew SQLiteConnection();
		rutaDb = DirArch::defRutDb();
		con->ConnectionString = "Data Source=" + rutaDb + ";Version=3;Pooling=True;Max Pool Size=50"; //Password=myPassword;";
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Conexion a la DB erronea->" + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Conexion a la DB erronea->" + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

UtilesDb::UtilesDb(String^ ruta) {
	try {
		con = gcnew SQLiteConnection();
		rutaDb = ruta;
		con->ConnectionString = "Data Source=" + rutaDb + ";Version=3;Pooling=True;Max Pool Size=50"; 
		con->Open();
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error", "Conexion a la DB erronea->" + sqlex->Message, MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Conexion a la DB erronea->" + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

UtilesDb::~UtilesDb() {
	con->ClearAllPools();
	con->Close();
	delete con;
}

bool UtilesDb::crearDb() {
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	try {
		// Cargo el recurso del archivo de texto
		String^ strsql;
		SQLiteCommand^ comm = gcnew SQLiteCommand();
		comm->Connection = con;
		String^ recurso = "CreacionBD.txt";
		Assembly^ ensam = System::Reflection::Assembly::GetExecutingAssembly();
		Stream^ stre = ensam->GetManifestResourceStream(recurso);
		StreamReader^ stread = gcnew StreamReader(stre);
		while (stread->Peek() >= 0) {
			strsql = stread->ReadLine();
			comm->CommandText = strsql;
			comm->ExecuteNonQuery();
		}
		stread->Close();
		stre->Close();
		delete comm;
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Conexion a la DB erronea->" + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Conexion a la DB erronea->" + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	return true;
}

bool UtilesDb::validaBd() {
	bool retorno = true;
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	try {
		// Consulto la cantidad de tablas
		String^ strsql = "Select count(1) from sqlite_master where type='table'";
		SQLiteCommand^ comm = gcnew SQLiteCommand(strsql, con);
		int cantTablas = int::Parse(comm->ExecuteScalar()->ToString());
		if (cantTablas != 7) {
			retorno = false;
		}
		delete comm;
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Conexion a la DB erronea->" + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Conexion a la DB erronea->" + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	return retorno;
}

String^ UtilesDb::getPathDb() {
	return rutaDb;
}

array<TreeNode^>^ UtilesDb::traerDivs() {
	List<TreeNode^>^ retorno = gcnew List<TreeNode^>();
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataReader^ lec;

	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		comm->CommandText = "Select div_id,div_nombre from divisiones where div_padre is null or div_padre = 0";
		lec = comm->ExecuteReader();
		while (lec->Read()) {
			TreeNode^ nodT = gcnew TreeNode();
			nodT->Text = lec->GetString(1);
			nodT->Name = "D" + lec->GetInt32(0).ToString();
			retorno->Add(nodT);
		}
		lec->Close();
		con->Close();
		for (int j = 0; j < retorno->Count; j++) {
			if (!validaDirectorio(int::Parse(retorno[j]->Name->Substring(1)))) {
				retorno->Remove(retorno[j]);
				j--;
			}
		}
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	return retorno->ToArray();
}

array<TreeNode^>^ UtilesDb::traerDivs(int div) {
	List<TreeNode^>^ retorno = gcnew List<TreeNode^>();
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataReader^ lec;
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		comm->CommandText = "Select div_id,div_nombre from divisiones where div_padre = :div_p";
		SQLiteParameter^ param = gcnew SQLiteParameter(":div_p", DbType::Int32);
		param->Value = div;
		comm->Parameters->Add(param);
		lec = comm->ExecuteReader();
		while (lec->Read()) {
			TreeNode^ nodT = gcnew TreeNode();
			nodT->Text = lec->GetString(1);
			nodT->Name = "D" + lec->GetInt32(0).ToString();
			retorno->Add(nodT);
		}
		lec->Close();
		// Saco los libros
		comm->CommandText = "Select lib_id,lib_nombre from libros where lib_div_id = :div_p";
		SQLiteParameter^ param2 = gcnew SQLiteParameter(":div_p", DbType::Int32);
		param2->Value = div;
		comm->Parameters->Add(param2);
		lec = comm->ExecuteReader();
		while (lec->Read()) {
			TreeNode^ nodT = gcnew TreeNode();
			nodT->Text = lec->GetString(1);
			nodT->Name = "L" + lec->GetInt32(0).ToString();
			retorno->Add(nodT);
		}
		lec->Close();
		// 
		con->Close();
		// Valido los subdirectorios
		for (int j = 0; j < retorno->Count; j++) {
			if (retorno[j]->Name->Contains("D")) {
				if (!validaDirectorio(int::Parse(retorno[j]->Name->Substring(1)))) {
					retorno->Remove(retorno[j]);
					j--;
				}
			}
		}
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	return retorno->ToArray();
}

TreeNode^ UtilesDb::traerDiv(String^ path, int div) {
	TreeNode^ retorno = gcnew TreeNode();
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataReader^ lec;
	String^ rutaPadre;
	String^ nomDiv;
	// Realizo el procesamiento
	rutaPadre = Path::GetDirectoryName(path);
	nomDiv = Path::GetFileName(path);
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		comm->CommandText = "Select div_id,div_nombre From divisiones Where div_padre = :div_p and UPPER(div_ruta) = :ruta And UPPER(div_nombre) = :nombre";
		SQLiteParameter^ param = gcnew SQLiteParameter(":div_p", DbType::Int32);
		param->Value = div;
		comm->Parameters->Add(param);
		SQLiteParameter^ param1 = gcnew SQLiteParameter(":ruta", DbType::String);
		param1->Value = rutaPadre->ToUpper();
		SQLiteParameter^ param2 = gcnew SQLiteParameter(":nombre", DbType::String);
		param2->Value = nomDiv->ToUpper();
		comm->Parameters->Add(param1);
		comm->Parameters->Add(param2);
		lec = comm->ExecuteReader();
		while (lec->Read()) {
			retorno->Text = lec->GetString(1);
			retorno->Name = "D" + lec->GetInt32(0).ToString();
		}
		lec->Close();
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	return retorno;
}

Dictionary<String^, int>^ UtilesDb::getFTypes() {
	Dictionary<String^, int>^ dicRetorno = gcnew Dictionary<String^, int>();
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataReader^ lec;

	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		comm->CommandText = "Select tip_id, tip_ext from tipo_archivo order by tip_id";
		lec = comm->ExecuteReader();
		while (lec->Read()) {
			dicRetorno->Add(lec->GetString(1), lec->GetInt32(0));
		}
		lec->Close();
		// 
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	return dicRetorno;
}

DataTable^ UtilesDb::traeTipos() {
	DataTable^ retorno;
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataAdapter^ adap = gcnew SQLiteDataAdapter();
	DataSet^ ds = gcnew DataSet();
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		comm->CommandText = "Select tip_id Id, tip_ext Extension, tip_desc Desc from tipo_archivo order by tip_id";
		adap->SelectCommand = comm;
		// 
		adap->Fill(ds);
		retorno = ds->Tables[0]->Copy();
		delete ds;
		delete adap;
		delete comm;
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	return retorno;
}

Dictionary<String^, int>^ UtilesDb::getFEditors() {
	Dictionary<String^, int>^ dicRetorno = gcnew Dictionary<String^, int>();
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataReader^ lec;
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		comm->CommandText = "Select edi_id, edi_nombre from editorial order by edi_id";
		lec = comm->ExecuteReader();
		while (lec->Read()) {
			dicRetorno->Add(lec->GetString(1), lec->GetInt32(0));
		}
		lec->Close();
		// 
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	return dicRetorno;
}

int UtilesDb::validaDivision(String^ path) {
	int retorno = 0;
	String^ rutaPadre;
	String^ nomDiv;
	// Realizo el procesamiento
	rutaPadre = Path::GetDirectoryName(path);
	nomDiv = Path::GetFileName(path);
	// cargo los datos
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataReader^ lec;	
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		comm->CommandText = "Select div_id From divisiones Where UPPER(div_ruta) = :ruta And UPPER(div_nombre) = :nombre";
		SQLiteParameter^ param1 = gcnew SQLiteParameter(":ruta", DbType::String);
		param1->Value = rutaPadre->ToUpper();
		SQLiteParameter^ param2 = gcnew SQLiteParameter(":nombre", DbType::String);
		param2->Value = nomDiv->ToUpper();
		comm->Parameters->Add(param1);
		comm->Parameters->Add(param2);
		lec = comm->ExecuteReader();
		while (lec->Read()) {
			retorno = lec->GetInt32(0);
		}
		lec->Close();
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 1;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 1;
	}
	return retorno;
}

int UtilesDb::validaLibro(String^ path) {
	int retorno = 0;
	int divPadre = 0;
	String^ rutaPadre;
	String^ nomDiv;
	// Realizo el procesamiento
	rutaPadre = Path::GetDirectoryName(path);
	nomDiv = Path::GetFileName(path);
	divPadre = validaDivision(rutaPadre);
	// cargo los datos
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataReader^ lec;
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		comm->CommandText = "Select l.lib_id from libros l Where UPPER(l.lib_nombre) = :nombre And UPPER(l.lib_ruta) = :ruta And l.lib_div_id = :div";
		SQLiteParameter^ param1 = gcnew SQLiteParameter(":ruta", DbType::String);
		param1->Value = path->ToUpper();
		SQLiteParameter^ param2 = gcnew SQLiteParameter(":nombre", DbType::String);
		param2->Value = nomDiv->ToUpper();
		SQLiteParameter^ param3 = gcnew SQLiteParameter(":div", DbType::Int32);
		param3->Value = divPadre;
		comm->Parameters->Add(param1);
		comm->Parameters->Add(param2);
		comm->Parameters->Add(param3);
		lec = comm->ExecuteReader();
		while (lec->Read()) {
			retorno = lec->GetInt32(0);
		}
		lec->Close();
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0;
	}
	return retorno;
}

int UtilesDb::crearDivision(String^ path, String^ descripcion) {
	int retorno = 0;
	int divPadre = 1;
	String^ rutaPadre;
	String^ nomDiv;
	// Realizo el procesamiento
	rutaPadre = Path::GetDirectoryName(path);
	nomDiv = Path::GetFileName(path);
	divPadre = validaDivision(rutaPadre);
	// cargo los datos
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		comm->CommandText = "Insert Into divisiones(div_ruta, div_nombre, div_descripcion, div_padre, div_estado, div_usu_crea) Values(:ruta, :nombre, :descrip, :padre, 1,0)";
		SQLiteParameter^ param1 = gcnew SQLiteParameter(":ruta", DbType::String);
		param1->Value = rutaPadre;
		SQLiteParameter^ param2 = gcnew SQLiteParameter(":nombre", DbType::String);
		param2->Value = nomDiv->ToUpper();
		SQLiteParameter^ param3 = gcnew SQLiteParameter(":descrip", DbType::String);
		param3->Value = descripcion;
		SQLiteParameter^ param4 = gcnew SQLiteParameter(":padre", DbType::Int32);
		param4->Value = divPadre;
		comm->Parameters->Add(param1);
		comm->Parameters->Add(param2);
		comm->Parameters->Add(param3);
		comm->Parameters->Add(param4);
		comm->ExecuteNonQuery();
		comm->CommandText = "Select last_insert_rowid()";
		retorno = int::Parse(comm->ExecuteScalar()->ToString());
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0;
	}
	return retorno;
}

int UtilesDb::crearDivision(String^ path, String^ descripcion, int usuario) {
	int retorno = 0;
	int divPadre = 1;
	String^ rutaPadre;
	String^ nomDiv;
	// Realizo el procesamiento
	rutaPadre = Path::GetDirectoryName(path);
	nomDiv = Path::GetFileName(path);
	divPadre = validaDivision(rutaPadre);
	// cargo los datos
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		comm->CommandText = "Insert Into divisiones(div_ruta, div_nombre, div_descripcion, div_padre, div_estado, div_usu_crea) Values(:ruta, :nombre, :descrip, :padre, 1, :us)";
		SQLiteParameter^ param1 = gcnew SQLiteParameter(":ruta", DbType::String);
		param1->Value = rutaPadre;
		SQLiteParameter^ param2 = gcnew SQLiteParameter(":nombre", DbType::String);
		param2->Value = nomDiv->ToUpper();
		SQLiteParameter^ param3 = gcnew SQLiteParameter(":descrip", DbType::String);
		param3->Value = descripcion;
		SQLiteParameter^ param4 = gcnew SQLiteParameter(":padre", DbType::Int32);
		param4->Value = divPadre;
		SQLiteParameter^ param5 = gcnew SQLiteParameter(":us", DbType::Int32);
		param5->Value = usuario;
		comm->Parameters->Add(param1);
		comm->Parameters->Add(param2);
		comm->Parameters->Add(param3);
		comm->Parameters->Add(param4);
		comm->Parameters->Add(param5);
		comm->ExecuteNonQuery();
		comm->CommandText = "Select last_insert_rowid()";
		retorno = int::Parse(comm->ExecuteScalar()->ToString());
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0;
	}
	return retorno;
}

int UtilesDb::crearLibro(String^ path, int editorial, String^ autor, int edicion, int anio, double tamanio, String^ isbn, int tipo) {
	int retorno = 0;
	int divPadre = 1;
	String^ rutaPadre;
	String^ nomDiv;
	// Realizo el procesamiento
	rutaPadre = Path::GetDirectoryName(path);
	nomDiv = Path::GetFileName(path);
	divPadre = validaDivision(rutaPadre);
	if (divPadre == 0) {
		divPadre = crearDivision(rutaPadre, "Proceso Automatico. Creado desde crearLibro");
	}
	
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	if (con->State != ConnectionState::Open) {
		con->Open();
	}

	comm->Connection = con;
	try {
		comm->CommandText = "Insert Into libros(lib_nombre, lib_edi_id, lib_autor, lib_edicion, lib_anio, lib_ruta, lib_tamanio, lib_isbn, lib_tip_id, lib_div_id) Values(:nombre, :editor, :autor, :edicion, :anio, :ruta, :tamanio, :isbn, :tipo, :div);";
		// Los parametros
		SQLiteParameter^ param1 = gcnew SQLiteParameter(":nombre", DbType::String);
		param1->Value = nomDiv;
		SQLiteParameter^ param2 = gcnew SQLiteParameter(":editor", DbType::Int32);
		param2->Value = editorial;
		SQLiteParameter^ param3 = gcnew SQLiteParameter(":autor", DbType::String);
		param3->Value = autor;
		SQLiteParameter^ param4 = gcnew SQLiteParameter(":edicion", DbType::Int32);
		param4->Value = edicion;
		SQLiteParameter^ param5 = gcnew SQLiteParameter(":anio", DbType::Int32);
		param5->Value = anio;
		SQLiteParameter^ param6 = gcnew SQLiteParameter(":ruta", DbType::String);
		param6->Value = path;
		SQLiteParameter^ param7 = gcnew SQLiteParameter(":tamanio", DbType::Double);
		param7->Value = tamanio;
		SQLiteParameter^ param8 = gcnew SQLiteParameter(":isbn", DbType::String);
		param8->Value = isbn;
		SQLiteParameter^ param9 = gcnew SQLiteParameter(":tipo", DbType::Int32);
		param9->Value = tipo;
		SQLiteParameter^ param10 = gcnew SQLiteParameter(":div", DbType::Int32);
		param10->Value = divPadre;
		comm->Parameters->Add(param1);
		comm->Parameters->Add(param2);
		comm->Parameters->Add(param3);
		comm->Parameters->Add(param4);
		comm->Parameters->Add(param5);
		comm->Parameters->Add(param6);
		comm->Parameters->Add(param7);
		comm->Parameters->Add(param8);
		comm->Parameters->Add(param9);
		comm->Parameters->Add(param10);
		comm->ExecuteNonQuery();
		comm->CommandText = "Select last_insert_rowid()";
		retorno = int::Parse(comm->ExecuteScalar()->ToString());
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0;
	}
	return retorno;
}

array<String^>^ UtilesDb::traerDatosLib(int idEle, int tipo) {
	array<String^>^ retorno = gcnew array<String^>(9);
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataReader^ lec;
	
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		if (tipo == 0) // libro
			comm->CommandText = "Select l.lib_nombre, l.lib_autor, e.edi_nombre, 1 ,(l.lib_tamanio/1024) tamano, l.lib_ruta, l.lib_edicion, l.lib_isbn, l.lib_calificacion From libros l, editorial e Where l.lib_edi_id = e.edi_id And l.lib_id = :id";
		else // Division
			comm->CommandText = "Select d.div_nombre, d.div_descripcion, '', d.div_elementos, (select ifnull(sum((l.lib_tamanio/1024)),0) From libros l where l.lib_div_id = d.div_id) tamano, d.div_ruta, 0,'0',1 From divisiones d Where d.div_id = :id";
		SQLiteParameter^ param1 = gcnew SQLiteParameter(":id", DbType::Int32);
		param1->Value = idEle;
		comm->Parameters->Add(param1);
		lec = comm->ExecuteReader();
		while (lec->Read()) {
			retorno[0] = lec->GetString(0); // Nombre
			retorno[1] = lec->GetString(1); // Autor
			retorno[2] = lec->GetString(2); // Editorial
			retorno[3] = lec->GetInt32(3).ToString(); // Cantidad
			retorno[4] = lec->GetDouble(4).ToString("N2"); // Tamano
			retorno[5] = lec->GetString(5); // ruta
			retorno[6] = lec->GetInt32(6).ToString(); // edicion
			retorno[7] = lec->GetString(7); // ISBN
			retorno[8] = lec->GetInt32(8).ToString(); // calificacion
		}
		lec->Close();
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	return retorno;
}

DataTable^ UtilesDb::traerLista(String^ nom) {
	DataTable^ retorno;
	StringBuilder^ strb = gcnew StringBuilder();
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataAdapter^ adap = gcnew SQLiteDataAdapter();
	DataSet^ ds = gcnew DataSet();
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		strb->Append("Select l.lib_id Id, 0, l.lib_nombre Nombre,'Libro' Tipo , l.lib_autor Autor, e.edi_nombre Editor, 1 Elementos ,(l.lib_tamanio/1024) tamano, l.lib_ruta Ruta ");
		strb->Append("From libros l, editorial e Where l.lib_edi_id = e.edi_id And l.lib_nombre like '%");
		strb->Append(nom);
		strb->Append("%' ");
		strb->Append("union ");
		strb->Append("Select d.div_id Id, 1, d.div_nombre Nombre, 'Directorio' Tipo ,d.div_descripcion Autor, '' Editor, d.div_elementos Elementos, ");
		strb->Append("(select ifnull(sum((l.lib_tamanio/1024)),0) From libros l where l.lib_div_id = d.div_id) tamano, ");
		strb->Append("d.div_ruta Ruta from divisiones d where d.div_nombre like '%");
		strb->Append(nom);
		strb->Append("%'");
		comm->CommandText = strb->ToString();
		adap->SelectCommand = comm;
		adap->Fill(ds);
		retorno = ds->Tables[0]->Copy();
		con->Close();
		delete ds;
		delete adap;
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	return retorno;
}

DataTable^ UtilesDb::traerComentarios(int idLib) {
	DataTable^ retorno;
	StringBuilder^ strb = gcnew StringBuilder();
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataAdapter^ adap = gcnew SQLiteDataAdapter();
	DataSet^ ds = gcnew DataSet();
	
	if (con->State != ConnectionState::Open) {
		con->Open();
	}
	comm->Connection = con;
	try {
		strb->Append("Select com_fecha, com_comentario from comentarios where com_lib_id = ");
		strb->Append(idLib);
		comm->CommandText = strb->ToString();
		adap->SelectCommand = comm;
		adap->Fill(ds);
		retorno = ds->Tables[0]->Copy();
		con->Close();
		delete ds;
		delete adap;
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	return retorno;
}

int UtilesDb::depurarDivs(int inicio) {
	int retorno = 0;
	List<int>^ dirs = gcnew List<int>();
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataReader^ lec;

	if (con->State != ConnectionState::Open)
		con->Open();
	try {
		comm->Connection = con;
		comm->CommandText = "Select div_id from divisiones where div_padre = " + inicio.ToString();
		lec = comm->ExecuteReader();
		while (lec->Read()) {
			dirs->Add(lec->GetInt32(0));
		}
		lec->Close();
		// Recorro los elementos, si tiene
		if (dirs->Count > 0) {
			for (int i = 0; i < dirs->Count; i++) {
				if (depurarDivs(dirs[i]) == 0) {
					borraDiv(dirs[i]);
					dirs->Remove(dirs[i]);
					i--;
				}
			}
		}
		if (dirs->Count == 0) {
			if (con->State != ConnectionState::Open)
				con->Open();
			comm->CommandText = "Select div_elementos from divisiones where div_id = " + inicio.ToString();
			retorno = int::Parse(comm->ExecuteScalar()->ToString());
		}
		else
			retorno = dirs->Count;
	}
	catch (SQLiteException^ sqex) {
		MessageBox::Show("Error evaluando [" + inicio.ToString() + "]:" + sqex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return -1;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error evaluando [" + inicio.ToString() + "]:" + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return -1;
	}
	return retorno;
}

bool UtilesDb::crearTipo(String^ desc, String^ ext) {
	bool retorno = false;
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	if (con->State != ConnectionState::Open)
		con->Open();
	try {
		comm->Connection = con;
		comm->CommandText = "Insert Into tipo_archivo(tip_ext,tip_desc) Values(:exten,:descrip)";
		SQLiteParameter^ param1 = gcnew SQLiteParameter(":exten", DbType::String);
		param1->Direction = ParameterDirection::Input;
		param1->Value = ext;
		SQLiteParameter^ param2 = gcnew SQLiteParameter(":descrip", DbType::String);
		param2->Direction = ParameterDirection::Input;
		param2->Value = desc;
		comm->Parameters->Add(param1);
		comm->Parameters->Add(param2);
		comm->ExecuteNonQuery();
		delete param1;
		delete param2;
		delete comm;
		con->Close();
		retorno = true;
	}
	catch (SQLiteException^ sqex) {
		MessageBox::Show("Error Insertando el tipo [" + ext + "]: " + sqex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error Insertando el tipo [" + ext + "]: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	return retorno;
}

bool UtilesDb::crearComentario(int idLibro, String^ comentario) {
	bool retorno = false;
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	try {
		if (con->State != ConnectionState::Open)
			con->Open();
		comm->Connection = con;
		comm->CommandText = "Insert Into comentarios(com_lib_id,com_comentario) Values(:idLibro,:comentario)";
		SQLiteParameter^ param1 = gcnew SQLiteParameter(":idLibro", DbType::Int32);
		param1->Direction = ParameterDirection::Input;
		param1->Value = idLibro;
		SQLiteParameter^ param2 = gcnew SQLiteParameter(":comentario", DbType::String);
		param2->Direction = ParameterDirection::Input;
		param2->Value = comentario;
		comm->Parameters->Add(param1);
		comm->Parameters->Add(param2);
		comm->ExecuteNonQuery();
		delete param1;
		delete param2;
		delete comm;
		con->Close();
		retorno = true;
	}
	catch (SQLiteException^ sqex) {
		MessageBox::Show("Error Insertando el tipo [" + idLibro.ToString() + "]: " + sqex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error Insertando el tipo [" + idLibro.ToString() + "]: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	return retorno;
}

bool UtilesDb::moverDirectorio(int idLibro, String^ ruta, int idDiv) {
	bool retorno = false;
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	try {
		if (con->State != ConnectionState::Open)
			con->Open();
		comm->Connection = con;
		comm->CommandText = "Update libros Set lib_div_id = :iddiv , lib_ruta = :ruta Where lib_id = :idLib";
		SQLiteParameter^ param1 = gcnew SQLiteParameter(":iddiv", DbType::Int32);
		param1->Direction = ParameterDirection::Input;
		param1->Value = idDiv;
		SQLiteParameter^ param2 = gcnew SQLiteParameter(":ruta", DbType::String);
		param2->Direction = ParameterDirection::Input;
		param2->Value = ruta;
		SQLiteParameter^ param3 = gcnew SQLiteParameter(":idLib", DbType::Int32);
		param3->Direction = ParameterDirection::Input;
		param3->Value = idLibro;
		comm->Parameters->Add(param1);
		comm->Parameters->Add(param2);
		comm->Parameters->Add(param3);
		comm->ExecuteNonQuery();
		delete param1;
		delete param2;
		delete comm;
		con->Close();
		retorno = true;
	}
	catch (SQLiteException^ sqex) {
		MessageBox::Show("Error actualizando el libro [" + idLibro.ToString() + "]: " + sqex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error actualizando el libro [" + idLibro.ToString() + "]: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	return retorno;
}

AutoCompleteStringCollection^ UtilesDb::traeAutoCom() {
	AutoCompleteStringCollection^ retorno = gcnew AutoCompleteStringCollection();
	DataTable^ dttemp;
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataReader^ lec;
	try {
		if (con->State != ConnectionState::Open)
			con->Open();
		dttemp = gcnew DataTable();
		comm->Connection = con;
		comm->CommandText = "Select edi_nombre From editorial";
		lec = comm->ExecuteReader();
		dttemp->Load(lec);
		delete comm;
		con->Close();
		if (dttemp->Rows->Count > 0) {
			for (int i = 0; i < dttemp->Rows->Count; i++) {
				retorno->Add(dttemp->Rows[i]["edi_nombre"]->ToString());
			}
		}
		return retorno;
	}
	catch (SQLiteException^ sqex) {
		MessageBox::Show("Error trayendo informacion de editoriales[SQL]: " + sqex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error trayendo informacion de editoriales[GENERICO]: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return nullptr;
	}
}

bool UtilesDb::borraDiv(int idDiv) {
	bool retorno = false;
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	if (con->State != ConnectionState::Open)
		con->Open();
	try {
		comm->Connection = con;
		comm->CommandText = "Delete from divisiones where div_id = " + idDiv.ToString();
		comm->ExecuteNonQuery();
		delete comm;
		con->Close();
	}
	catch (SQLiteException^ sqex) {
		MessageBox::Show("Error procesando el borrado de [" + idDiv.ToString() + "]: " + sqex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error procesando el borrado de [" + idDiv.ToString() + "]: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	return retorno;
}

bool UtilesDb::validaDirectorio(int iddiv) {
	bool retorno = false;
	Dictionary<int, int>^ dicHijos = gcnew Dictionary<int, int>();
	double elementos = 0;
	if (iddiv < 2) return true;
	SQLiteCommand^ comm = gcnew SQLiteCommand();
	SQLiteDataReader^ lec;
	if (con->State != ConnectionState::Open)
		con->Open();
	comm->Connection = con;
	try {
		comm->CommandText = "Select (div_elementos + div_usu_crea) total from divisiones where div_id = :id";
		comm->Parameters->Clear();
		SQLiteParameter^ param2 = gcnew SQLiteParameter(":id", DbType::Int32);
		param2->Value = iddiv;
		comm->Parameters->Add(param2);
		elementos = double::Parse(comm->ExecuteScalar()->ToString());
		if (elementos == 0) {
			comm->CommandText = "Select div_id from divisiones where div_padre = :id";
			SQLiteParameter^ param1 = gcnew SQLiteParameter(":id", DbType::Int32);
			param1->Value = iddiv;
			comm->Parameters->Clear();
			comm->Parameters->Add(param1);
			lec = comm->ExecuteReader();
			while (lec->Read()) {
				dicHijos->Add(lec->GetInt32(0), 1);
			}
			lec->Close();

			// Valido las hijas
			for each (KeyValuePair<int, int> ^ kp in dicHijos) {
				if (validaDirectorio(kp->Key)) {
					retorno = true;
					break;
				}
			}
		}
		else {
			retorno = true;
		}
		con->Close();
	}
	catch (SQLiteException^ sqlex) {
		MessageBox::Show("Error SQL -> " + sqlex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error cargando nodos -> " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	return retorno;
}
