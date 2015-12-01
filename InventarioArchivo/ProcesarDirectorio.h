#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Threading;
// Adicionales
using namespace System::IO;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace UtilesInv;


namespace InventarioArchivo {

	/// <summary>
	/// Summary for ProcesarDirectorio
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ProcesarDirectorio : public System::Windows::Forms::Form
	{
	public:
		ProcesarDirectorio(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProcesarDirectorio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txbDirectorio;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnBuscar;

	private: System::Windows::Forms::FolderBrowserDialog^  fbdBusqueda;
	private: System::Windows::Forms::DataGridView^  dgvDatos;

	private: System::Windows::Forms::Button^  btnIniciar;
	private: System::Windows::Forms::Button^  btnCargar;
	private: System::Windows::Forms::Button^  btnCancelar;
	private: System::ComponentModel::BackgroundWorker^  bgwScaner;




	private: System::Windows::Forms::ProgressBar^  pgbProgreso;

	private: static System::Data::DataTable^ dtDatos;
	private: System::Windows::Forms::CheckBox^  chkFormato;
	private: static unsigned int hilos;
	private: static Object^ MonitorObject = gcnew Object();
	private: static String^ dirPadre;
	private: static int maximo;
	private: int ajustado;
	private: System::Windows::Forms::ProgressBar^  pgbDir1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  stlblEstado;
	private: System::ComponentModel::BackgroundWorker^  bgwLoader;
	private: UtilesDb^ dbase;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ProcesarDirectorio::typeid));
			this->txbDirectorio = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->fbdBusqueda = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->dgvDatos = (gcnew System::Windows::Forms::DataGridView());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->btnCargar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->bgwScaner = (gcnew System::ComponentModel::BackgroundWorker());
			this->pgbProgreso = (gcnew System::Windows::Forms::ProgressBar());
			this->chkFormato = (gcnew System::Windows::Forms::CheckBox());
			this->pgbDir1 = (gcnew System::Windows::Forms::ProgressBar());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->stlblEstado = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->bgwLoader = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvDatos))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// txbDirectorio
			// 
			this->txbDirectorio->Location = System::Drawing::Point(79, 30);
			this->txbDirectorio->Name = L"txbDirectorio";
			this->txbDirectorio->ReadOnly = true;
			this->txbDirectorio->Size = System::Drawing::Size(167, 20);
			this->txbDirectorio->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Directorio";
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(262, 27);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(75, 23);
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"&Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &ProcesarDirectorio::btnBuscar_Click);
			// 
			// fbdBusqueda
			// 
			this->fbdBusqueda->Description = L"Directorio a revisar";
			this->fbdBusqueda->ShowNewFolderButton = false;
			// 
			// dgvDatos
			// 
			this->dgvDatos->AllowUserToAddRows = false;
			this->dgvDatos->AllowUserToDeleteRows = false;
			this->dgvDatos->AllowUserToOrderColumns = true;
			this->dgvDatos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDatos->Location = System::Drawing::Point(12, 133);
			this->dgvDatos->Name = L"dgvDatos";
			this->dgvDatos->Size = System::Drawing::Size(399, 150);
			this->dgvDatos->TabIndex = 3;
			// 
			// btnIniciar
			// 
			this->btnIniciar->Enabled = false;
			this->btnIniciar->Location = System::Drawing::Point(58, 289);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(75, 23);
			this->btnIniciar->TabIndex = 4;
			this->btnIniciar->Text = L"&Iniciar";
			this->btnIniciar->UseVisualStyleBackColor = true;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &ProcesarDirectorio::btnIniciar_Click);
			// 
			// btnCargar
			// 
			this->btnCargar->Enabled = false;
			this->btnCargar->Location = System::Drawing::Point(160, 289);
			this->btnCargar->Name = L"btnCargar";
			this->btnCargar->Size = System::Drawing::Size(75, 23);
			this->btnCargar->TabIndex = 5;
			this->btnCargar->Text = L"Car&gar";
			this->btnCargar->UseVisualStyleBackColor = true;
			this->btnCargar->Click += gcnew System::EventHandler(this, &ProcesarDirectorio::btnCargar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(262, 289);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(75, 23);
			this->btnCancelar->TabIndex = 6;
			this->btnCancelar->Text = L"&Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &ProcesarDirectorio::btnCancelar_Click);
			// 
			// bgwScaner
			// 
			this->bgwScaner->WorkerReportsProgress = true;
			this->bgwScaner->WorkerSupportsCancellation = true;
			this->bgwScaner->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &ProcesarDirectorio::bgwScaner_DoWork);
			this->bgwScaner->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &ProcesarDirectorio::bgwScaner_RunWorkerCompleted);
			this->bgwScaner->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &ProcesarDirectorio::bgwScaner_ProgressChanged);
			// 
			// pgbProgreso
			// 
			this->pgbProgreso->Location = System::Drawing::Point(41, 66);
			this->pgbProgreso->Name = L"pgbProgreso";
			this->pgbProgreso->Size = System::Drawing::Size(317, 23);
			this->pgbProgreso->TabIndex = 7;
			this->pgbProgreso->Visible = false;
			// 
			// chkFormato
			// 
			this->chkFormato->AutoSize = true;
			this->chkFormato->Location = System::Drawing::Point(343, 33);
			this->chkFormato->Name = L"chkFormato";
			this->chkFormato->Size = System::Drawing::Size(82, 17);
			this->chkFormato->TabIndex = 8;
			this->chkFormato->Text = L"Formateado";
			this->chkFormato->UseVisualStyleBackColor = true;
			// 
			// pgbDir1
			// 
			this->pgbDir1->Location = System::Drawing::Point(41, 92);
			this->pgbDir1->Name = L"pgbDir1";
			this->pgbDir1->Size = System::Drawing::Size(317, 23);
			this->pgbDir1->TabIndex = 9;
			this->pgbDir1->Visible = false;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->stlblEstado});
			this->statusStrip1->Location = System::Drawing::Point(0, 320);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(430, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 10;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// stlblEstado
			// 
			this->stlblEstado->Name = L"stlblEstado";
			this->stlblEstado->Size = System::Drawing::Size(61, 17);
			this->stlblEstado->Text = L"Preparado";
			// 
			// bgwLoader
			// 
			this->bgwLoader->WorkerReportsProgress = true;
			this->bgwLoader->WorkerSupportsCancellation = true;
			this->bgwLoader->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &ProcesarDirectorio::bgwLoader_DoWork);
			this->bgwLoader->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &ProcesarDirectorio::bgwLoader_RunWorkerCompleted);
			this->bgwLoader->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &ProcesarDirectorio::bgwLoader_ProgressChanged);
			// 
			// ProcesarDirectorio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(430, 342);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->pgbDir1);
			this->Controls->Add(this->chkFormato);
			this->Controls->Add(this->pgbProgreso);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnCargar);
			this->Controls->Add(this->btnIniciar);
			this->Controls->Add(this->dgvDatos);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txbDirectorio);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"ProcesarDirectorio";
			this->Text = L"Procesar Directorio";
			this->Load += gcnew System::EventHandler(this, &ProcesarDirectorio::ProcesarDirectorio_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvDatos))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public:
			property UtilesDb^ vDb{
				void set(UtilesDb^ valor){
					dbase = valor;
				}
			}
	private: System::Void btnBuscar_Click(System::Object^  sender, System::EventArgs^  e) {
				 // Muestro el dialogo
				 if(fbdBusqueda->ShowDialog() == ::DialogResult::OK){
					 txbDirectorio->Text = fbdBusqueda->SelectedPath;
				 }
				 if(!Directory::Exists(txbDirectorio->Text)){
					 MessageBox::Show("Directorio no valido, por favor verifique","Atencion",MessageBoxButtons::OK, MessageBoxIcon::Warning);
					 txbDirectorio->Text = "";
					 btnIniciar->Enabled = false;
					 return;
				 }
				 btnIniciar->Enabled = true;
			 }
private: System::Void btnCancelar_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(bgwScaner->IsBusy){
				 bgwScaner->CancelAsync();
				 btnIniciar->Enabled = true;
			 }
			 else if(bgwLoader->IsBusy){
				 bgwLoader->CancelAsync();
				 btnIniciar->Enabled = true;
				 btnCargar->Enabled = true;
			 }
			 else{
				Close();
			 }
		 }
private: System::Void btnIniciar_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Inicio el thread
			 pgbProgreso->Minimum = 0;
			 pgbProgreso->Maximum = 1;
			 pgbProgreso->Step = 1;
			 pgbProgreso->Visible = true;
			 pgbDir1->Minimum = 0;
			 pgbDir1->Maximum = 1;
			 pgbDir1->Step = 1;
			 pgbDir1->Visible = true;
			 dtDatos->Rows->Clear();
			 btnIniciar->Enabled = false;
			 stlblEstado->Text = "Calculando archivos";
			 bgwScaner->RunWorkerAsync();
		 }
private: System::Void bgwScaner_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 // El proceso principal
			 if(!Directory::Exists(txbDirectorio->Text)){
				 MessageBox::Show("No se puede acceder a la ruta [" + txbDirectorio->Text->ToUpper() + "]","Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }
			 try{
				 dtDatos->Rows->Clear();
				 ajustado = 0;
				 /*maximo = 1;
				 ProcesarDir(txbDirectorio->Text);*/
				 DataRow^ dr = dtDatos->NewRow();
				 dr["Nombre"] = Path::GetFileName(txbDirectorio->Text);
				 dr["Ruta"] = txbDirectorio->Text;
				 dr["Tamano"] = (double)0;
				 dr["Autor"] = "";
				 dr["Editorial"] = "";
				 dr["Tipo"] = 2;
				 dtDatos->Rows->Add(dr);
				 maximo = TraeNumArchi(txbDirectorio->Text,1);
				 bgwScaner->ReportProgress(1);
				 ProcesarDir(txbDirectorio->Text);
				 bgwScaner->ReportProgress(4);
			 }catch(IOException^ ioex){
				 MessageBox::Show("Error de IO->" + ioex->Message, "Error IO",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }catch(Exception^ ex){
				 MessageBox::Show("Error Generico->" + ex->Message, "Error Generico",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }
		 }

private: void ProcesarDir(String^ path){
			 //int activos = 0;
			 try{
				 //Monitor::Enter(MonitorObject);
				 /*while(!Monitor::TryEnter(MonitorObject));
				 hilos++;
				 Monitor::Exit(MonitorObject);
				 while(hilos >= 10){
					 Thread::Sleep(10);
				 }*/
				 DirectoryInfo^ dirInfo = gcnew DirectoryInfo((String^)path);
				 array<DirectoryInfo^>^ dirArr = dirInfo->GetDirectories();
				 //Dictionary<String^,Thread^>^ arrTh = gcnew Dictionary<String^,Thread^>();
				 for(int i = 0; i < dirArr->Length ; i++){
					 /*DataRow^ dr = dtDatos->NewRow();
					 dr["Nombre"] = dirArr[i]->Name;
					 dr["Ruta"] = dirArr[i]->FullName;
					 dr["Tamano"] = (double)0;
					 dr["Autor"] = "";
					 dr["Editorial"] = "";
					 dr["Tipo"] = 2;
					 //Monitor::Enter(MonitorObject);
					 //while(!Monitor::TryEnter(MonitorObject));
					 dtDatos->Rows->Add(dr);
					 //maximo = dirArr->Length;
					 //bgwScaner->ReportProgress(1);
					 /*Monitor::Exit(MonitorObject);
					 Thread^ th = gcnew Thread(gcnew ParameterizedThreadStart(&ProcesarDirectorio::ProcesarDir));
					 th->Name = dirArr[i]->Name;
					 th->Start(dirArr[i]->FullName);
					 arrTh->Add(dirArr[i]->Name,th);*/
					 //activos++;
					 //th->Join();
					 //Thread::Sleep(20);
					 /*while(hilos >= 50){
						 Thread::Sleep(10);
					 }*/
					 ProcesarDir(dirArr[i]->FullName);
				 }
				 array<FileInfo^>^ fileArr = dirInfo->GetFiles();
				 //Monitor::Enter(MonitorObject);
				 //pgbProgreso->Maximum += fileArr->Length;
				 //bgwScaner->ReportProgress(fileArr->Length);
				 //Monitor::Exit(MonitorObject);
				 maximo = fileArr->Length;
				 //ajustado = 0;
				 bgwScaner->ReportProgress(2);
				 //while(ajustado == 0);
				 for(int j = 0; j < fileArr->Length ; j++ ){
					 DataRow^ dr = dtDatos->NewRow();
					 dr["Nombre"] = fileArr[j]->Name;
					 dr["Ruta"] = fileArr[j]->FullName;
					 dr["Tamano"] = fileArr[j]->Length;
					 dr["Autor"] = "";
					 dr["Editorial"] = "";
					 dr["Tipo"] = 1;
					 //Monitor::Enter(MonitorObject);
					 //while(!Monitor::TryEnter(MonitorObject));
					 dtDatos->Rows->Add(dr);
					 //ajustado = 0;
					 bgwScaner->ReportProgress(3);
					 //while(ajustado == 0);
					 //Monitor::Exit(MonitorObject);
				 }
				 /*for each(KeyValuePair<String^,Thread^>^ par in arrTh){
					 if(par->Value->ThreadState == ThreadState::Running)
						 par->Value->Join();
				 }*/
				 /*while(activos > 0){
					 for each(KeyValuePair<String^,Thread^>^ par in arrTh){
						 if(par->Value->ThreadState != ThreadState::Running)
							 activos--;
					 }
				 }*/
				 //Monitor::Enter(MonitorObject);
				 /*while(!Monitor::TryEnter(MonitorObject));
				 hilos--;
				 Monitor::Exit(MonitorObject);*/
			 }catch(IOException^ ioex){
				 MessageBox::Show("Error de IO->" + ioex->Message, "Error IO",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return ;
			 }catch(Exception^ ex){
				 MessageBox::Show("Error Generico->" + ex->Message, "Error IO",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return ;
			 }
		 }

private: int TraeNumArchi(String^ path, int recurrencia){
			 int retorno = 0;
			 try{
				 DirectoryInfo^ dirInfo = gcnew DirectoryInfo(path);
				 retorno = dirInfo->GetFiles()->Length;
				 if(recurrencia == 1){
					 array<DirectoryInfo^>^ dirArr = dirInfo->GetDirectories();
					 //Dictionary<String^,Thread^>^ arrTh = gcnew Dictionary<String^,Thread^>();
					 for(int i = 0; i < dirArr->Length ; i++){
						 DataRow^ dr = dtDatos->NewRow();
						 dr["Nombre"] = dirArr[i]->Name;
						 dr["Ruta"] = dirArr[i]->FullName;
						 dr["Tamano"] = (double)0;
						 dr["Autor"] = "";
						 dr["Editorial"] = "";
						 dr["Tipo"] = 2;
						 dtDatos->Rows->Add(dr);
						 retorno += TraeNumArchi(dirArr[i]->FullName,1);
					 }
				 }
			 }catch(IOException^ ioex){
				 MessageBox::Show("Error de IO->" + ioex->Message, "Error IO",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return 0;
			 }catch(Exception^ ex){
				 MessageBox::Show("Error Generico->" + ex->Message, "Error IO",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return 0;
			 }
			 return retorno;
		 }

private: System::Void ProcesarDirectorio_Load(System::Object^  sender, System::EventArgs^  e) {
			 // Debo inicializar la tabla donde voy a almacenar la data
			 dtDatos = gcnew DataTable();
			 dtDatos->Columns->Add(gcnew DataColumn("Nombre",Type::GetType("System.String")));
			 dtDatos->Columns->Add(gcnew DataColumn("Ruta",Type::GetType("System.String")));
			 dtDatos->Columns->Add(gcnew DataColumn("Tamano",Type::GetType("System.Double")));
			 dtDatos->Columns->Add(gcnew DataColumn("Autor",Type::GetType("System.String")));
			 dtDatos->Columns->Add(gcnew DataColumn("Editorial",Type::GetType("System.String")));
			 dtDatos->Columns->Add(gcnew DataColumn("Tipo",Type::GetType("System.Int32")));
			 //dgvDatos->DataSource = dtDatos;
		 }
private: System::Void bgwScaner_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 //bgwScaner->ReportProgress(4);
			 stlblEstado->Text = "Preparado";
			 dgvDatos->DataSource = dtDatos;
			 dgvDatos->Refresh();
			 pgbProgreso->Visible = false;
			 pgbDir1->Visible = false;
			 btnIniciar->Enabled = true;
			 if(dtDatos->Rows->Count > 0)
				 btnCargar->Enabled = true;
			 MessageBox::Show("Proceso terminado");
		 }
private: System::Void bgwScaner_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			 try{
				 switch((int)e->ProgressPercentage){
					 case 1:
						 /*pgbDir1->Value = 0;
						 pgbDir1->Maximum = maximo;
						 pgbDir1->Step = 1;
						 int actValor = pgbProgreso->Value;*/
						 pgbProgreso->Value = 0;
						 pgbProgreso->Maximum = maximo;
						 stlblEstado->Text = "Procesando Archivos";
						 //pgbProgreso->Value = actValor;
						 //ajustado = 1;
				 
					 case 2:
						 pgbDir1->Value = 0;
						 pgbDir1->Maximum = maximo;
						 pgbDir1->Step = 1;
					 case 4:
						 stlblEstado->Text = "Preparado";
					 default:
						 pgbDir1->PerformStep();
						 pgbProgreso->PerformStep();
						 //ajustado = 1;
				 }
			 }catch(Exception^ ex){
				 MessageBox::Show("Error en el proceso->" + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }
		 }
private: System::Void btnCargar_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Debo iniciar el proceso de carga
			 pgbProgreso->Minimum = 0;
			 pgbProgreso->Maximum = dtDatos->Rows->Count;
			 pgbProgreso->Value = 0;
			 pgbProgreso->Visible = true;
			 stlblEstado->Text = "Procesando archivos";
			 btnCargar->Enabled = false;
			 btnIniciar->Enabled = false;
			 bgwLoader->RunWorkerAsync();
		 }
private: System::Void bgwLoader_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 // Debo iniciar el proceso de carga a la BD
			 //UtilesDb^ dbase = gcnew UtilesInv::UtilesDb("C:\\Users\\Edwin\\Documents\\Visual Studio 2005\\Ayudas\\libreria.db");
			 Dictionary<String^,int>^ dtipos = dbase->getFTypes();
			 Dictionary<String^,int>^ deditores = dbase->getFEditors();
			 int divAct = 0;
			 int libAct =0;
			 double resultados[7];
			 for(int i = 0; i< 7; i++){
				 resultados[i] = 0;
			 }
			 // Variables para el formato del archivo
			 int editor = 0;
			 int tipo = 0;
			 String^ autor;
			 DataTable^ dt = dtDatos->Copy();
			 array<String^>^ separador = {" - "};
			 // Falta crear el archivo de LOG
			 for each(DataRow^ drt in dt->Rows){
				 // Proceso fila a fila
				 if((int)drt["Tipo"] == 2){ // Division
					 if(dbase->validaDivision((String^)drt["Ruta"]) == 0){
						 divAct = dbase->crearDivision((String^)drt["Ruta"], "Proceso Automatico. Loader");
						 if(divAct > 0) 
							 resultados[0]++;
						 else 
							 resultados[1]++;
					 }
					 else
						 resultados[2]++;
				 }
				 else{ // Libro
					 editor = 1;
					 tipo = 1;
					 autor = "";
					 if(dbase->validaLibro((String^)drt["Ruta"]) == 0){
						 // Saco algunos datos 
						 if(chkFormato->Checked){
							 array<String^>^ campos = ((String^)drt[""])->Split(separador,StringSplitOptions::None);
							 if( campos->Length > 1){
								 if( deditores->ContainsKey(campos[1]) ){
									 editor = deditores[campos[1]];
								 }
							 }
						 }
						 String^ exten = Path::GetExtension((String^)drt["Ruta"]);
						 if( dtipos->ContainsKey(exten)){
							 tipo = dtipos[Path::GetExtension((String^)drt["Ruta"])];
							 // Debo sacar la informacion de la tabla
							 libAct = dbase->crearLibro((String^)drt["Ruta"],editor, autor, 0, 2012, (double)drt["Tamano"],"ISBN",tipo);
							 if (libAct > 0)
								 resultados[3]++;
							 else
								 resultados[4]++;
							 /*if(libAct == 450 )
								 MessageBox::Show("Ojo");*/
						 }
						 else
							 resultados[6]++;
					 }
					 else
						 resultados[5]++;
				 }
				 bgwLoader->ReportProgress(0);
			 }
			 StringBuilder^ strb = gcnew StringBuilder();
			 strb->Append("Proceso finalizado.\n");
			 strb->Append(resultados[0]);
			 strb->Append(" divisiones insertadas correctamente.\n");
			 strb->Append(resultados[1]);
			 strb->Append(" divisiones con errores.\n");
			 strb->Append(resultados[2]);
			 strb->Append(" divisiones ya existentes.\n");
			 strb->Append(resultados[3]);
			 strb->Append(" libros registrados correctamente.\n");
			 strb->Append(resultados[4]);
			 strb->Append(" libros con errores.\n");
			 strb->Append(resultados[5]);
			 strb->Append(" libros ya existentes.\n");
			 strb->Append(resultados[6]);
			 strb->Append(" libros de extension no procesado.");
			 MessageBox::Show(strb->ToString(),"Proceso finalizado",MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		 }
private: System::Void bgwLoader_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			 pgbProgreso->PerformStep();
		 }
private: System::Void bgwLoader_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 // Reporto que ya termine
			 if(e->Error != nullptr){
				 MessageBox::Show("Proceso terminado con error -> " + e->Error->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }
			 Close();
		 }
};
}
