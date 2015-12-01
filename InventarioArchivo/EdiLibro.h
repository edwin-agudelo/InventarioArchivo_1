#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
// Las locales
using namespace UtilesInv;
using namespace System::Text::RegularExpressions;
using namespace System::IO;



namespace InventarioArchivo {

	/// <summary>
	/// Summary for EdiLibro
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class EdiLibro : public System::Windows::Forms::Form
	{
	public:
		EdiLibro(void)
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
		~EdiLibro()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txbNombre;
	protected: 

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txbEditorial;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txbAutor;



	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  nmEdicion;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txbIsbn;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::NumericUpDown^  nmCalificacion;
	private: System::Windows::Forms::CheckBox^  chkStandar;
	private: System::Windows::Forms::Button^  btnGuardar;
	private: System::Windows::Forms::Button^  btnCancelar;
	private: UtilesDb^ objDb;
	private: UtilesLog^ objLog;
	private: int idLibro;
	private: array<String^>^ datosBd;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(EdiLibro::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txbNombre = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txbEditorial = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txbAutor = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->nmEdicion = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txbIsbn = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->nmCalificacion = (gcnew System::Windows::Forms::NumericUpDown());
			this->chkStandar = (gcnew System::Windows::Forms::CheckBox());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmEdicion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmCalificacion))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre";
			// 
			// txbNombre
			// 
			this->txbNombre->Location = System::Drawing::Point(126, 47);
			this->txbNombre->Name = L"txbNombre";
			this->txbNombre->Size = System::Drawing::Size(204, 20);
			this->txbNombre->TabIndex = 1;
			this->txbNombre->TextChanged += gcnew System::EventHandler(this, &EdiLibro::txbNombre_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 76);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Editorial";
			// 
			// txbEditorial
			// 
			this->txbEditorial->Location = System::Drawing::Point(126, 73);
			this->txbEditorial->Name = L"txbEditorial";
			this->txbEditorial->Size = System::Drawing::Size(204, 20);
			this->txbEditorial->TabIndex = 3;
			this->txbEditorial->TextChanged += gcnew System::EventHandler(this, &EdiLibro::txbEditorial_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(32, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Autor";
			// 
			// txbAutor
			// 
			this->txbAutor->Location = System::Drawing::Point(126, 99);
			this->txbAutor->Name = L"txbAutor";
			this->txbAutor->Size = System::Drawing::Size(204, 20);
			this->txbAutor->TabIndex = 5;
			this->txbAutor->TextChanged += gcnew System::EventHandler(this, &EdiLibro::txbAutor_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(32, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(42, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Edicion";
			// 
			// nmEdicion
			// 
			this->nmEdicion->Location = System::Drawing::Point(126, 125);
			this->nmEdicion->Name = L"nmEdicion";
			this->nmEdicion->Size = System::Drawing::Size(43, 20);
			this->nmEdicion->TabIndex = 9;
			this->nmEdicion->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->nmEdicion->ValueChanged += gcnew System::EventHandler(this, &EdiLibro::nmEdicion_ValueChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(32, 154);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"ISBN";
			// 
			// txbIsbn
			// 
			this->txbIsbn->Location = System::Drawing::Point(126, 151);
			this->txbIsbn->Name = L"txbIsbn";
			this->txbIsbn->Size = System::Drawing::Size(204, 20);
			this->txbIsbn->TabIndex = 11;
			this->txbIsbn->TextChanged += gcnew System::EventHandler(this, &EdiLibro::txbIsbn_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(32, 179);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(61, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Calificacion";
			// 
			// nmCalificacion
			// 
			this->nmCalificacion->Location = System::Drawing::Point(126, 177);
			this->nmCalificacion->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->nmCalificacion->Name = L"nmCalificacion";
			this->nmCalificacion->Size = System::Drawing::Size(43, 20);
			this->nmCalificacion->TabIndex = 13;
			this->nmCalificacion->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->nmCalificacion->ValueChanged += gcnew System::EventHandler(this, &EdiLibro::nmCalificacion_ValueChanged);
			// 
			// chkStandar
			// 
			this->chkStandar->AutoSize = true;
			this->chkStandar->Location = System::Drawing::Point(149, 215);
			this->chkStandar->Name = L"chkStandar";
			this->chkStandar->Size = System::Drawing::Size(103, 17);
			this->chkStandar->TabIndex = 14;
			this->chkStandar->Text = L"Nombre Standar";
			this->chkStandar->UseVisualStyleBackColor = true;
			this->chkStandar->CheckedChanged += gcnew System::EventHandler(this, &EdiLibro::chkStandar_CheckedChanged);
			// 
			// btnGuardar
			// 
			this->btnGuardar->Location = System::Drawing::Point(76, 243);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(82, 38);
			this->btnGuardar->TabIndex = 15;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = true;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &EdiLibro::btnGuardar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(207, 243);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(82, 38);
			this->btnCancelar->TabIndex = 16;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &EdiLibro::btnCancelar_Click);
			// 
			// EdiLibro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(380, 296);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->chkStandar);
			this->Controls->Add(this->nmCalificacion);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->txbIsbn);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->nmEdicion);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txbAutor);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txbEditorial);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txbNombre);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"EdiLibro";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Editar Libro";
			this->Load += gcnew System::EventHandler(this, &EdiLibro::EdiLibro_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmEdicion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nmCalificacion))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public:
			property UtilesDb^ vObjDb{
				void set(UtilesDb^ valor){
					objDb = valor;
				}
			}
			
			property UtilesLog^ vObjLog{
				void set(UtilesLog^ valor){
					objLog = valor;
				}
			}
			
			property int vIdLibro{
				void set(int valor){
					idLibro = valor;
				}
			}

		private:
			bool comparaDatos(void){
				if(txbNombre->Text != datosBd[0])
					return false;
				if(txbEditorial->Text != datosBd[2])
					return false;
				if(txbAutor->Text != datosBd[1])
					return false;
				if(Decimal::ToInt32(nmEdicion->Value) != int::Parse(datosBd[6]))
					return false;
				if(txbIsbn->Text != datosBd[7])
					return false;
				if(Decimal::ToInt32(nmCalificacion->Value) != int::Parse(datosBd[8]))
					return false;
				return true;
			}


	private: System::Void EdiLibro_Load(System::Object^  sender, System::EventArgs^  e) {
				 // Cargo la data
				 /*retorno[0] = Nombre
					retorno[1] = Autor
					retorno[2] = Editorial
					retorno[3] = Cantidad
					retorno[4] = Tamano
					retorno[5] = ruta
					retorno[6] = edicion
					retorno[7] = ISBN
					retorno[8] = calificacion
				 */
				 datosBd = objDb->traerDatosLib(idLibro,0);
				 txbNombre->Text = datosBd[0];
				 txbEditorial->Text = datosBd[2];
				 txbAutor->Text = datosBd[1];
				 txbIsbn->Text = datosBd[7];
				 nmEdicion->Value = Decimal::Parse(datosBd[6]);
				 nmCalificacion->Value = Decimal::Parse(datosBd[8]);
				 txbEditorial->AutoCompleteMode = AutoCompleteMode::Suggest;
				 txbEditorial->AutoCompleteSource = AutoCompleteSource::CustomSource;
				 txbEditorial->AutoCompleteCustomSource = objDb->traeAutoCom();
				 this->Text = datosBd[0];
				 objLog->escribirLog("EdicionLibro","Editando el libro " + datosBd[0]);
			 }
private: System::Void chkStandar_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(chkStandar->Checked){
				 //
				 String^ strsep = "-";
				 array<Char>^ separador = strsep->ToCharArray();
				 array<String^>^ datPartido = datosBd[0]->Split(separador);
				 Regex^ reg = gcnew Regex("^[0-9]*$");
				 //
				 txbNombre->Text = datPartido[0];
				 if(datPartido->Length > 1){
					txbEditorial->Text = datPartido[1];
				 }
				 if(datPartido->Length > 2){
					if(!reg->IsMatch(datPartido[2])){
						txbAutor->Text = datPartido[2];
					 }
					 else{
						 txbAutor->Text = "";
					 }
				 }
				 txbIsbn->Text = "ISBN";
				 nmEdicion->Value = Decimal::Parse(datosBd[6]);
				 nmCalificacion->Value = Decimal::Parse(datosBd[8]);
				 this->Text = datosBd[0];
			 }
			 else{
				 txbNombre->Text = datosBd[0];
				 txbEditorial->Text = datosBd[2];
				 txbAutor->Text = datosBd[1];
				 txbIsbn->Text = datosBd[7];
				 nmEdicion->Value = Decimal::Parse(datosBd[6]);
				 nmCalificacion->Value = Decimal::Parse(datosBd[8]);
				 this->Text = datosBd[0];
			 }
		 }
private: System::Void btnGuardar_Click(System::Object^  sender, System::EventArgs^  e) {
			 //
			 if(validaCambios()){
				 MessageBox::Show("No hay cambios generados", "Atencion",MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				 //Close();
				 return;
			 }
			 if(MessageBox::Show("Desea cambiar los datos del archivo?","Atencion",MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes){
				 // Variables
				 String^ nombre;
				 String^ ruta;

				 nombre = txbNombre->Text->Trim() + " - " +  txbEditorial->Text->Trim() + " - " + txbAutor->Text->Trim() + " - " + txbIsbn->Text->Trim();
				 ruta = Path::GetDirectoryName(datosBd[5]) + "\\" + nombre;
				 MessageBox::Show("La ruta que quedo>" + ruta);
				 //DirArch::moverArch(datosBd[5] + "\\" + datosBd[0],ruta);
				 //objDb->moverDirectorio
			 }
			 else{
				 return;
			 }
		 }

		 bool validaCambios(void)
		 {
			 bool retorno = true;
			 if(datosBd[0] != txbNombre->Text)
				 retorno = false;
			 if(datosBd[1] != txbAutor->Text)
				 retorno = false;
			 if(datosBd[2] != txbEditorial->Text)
				 retorno = false;
			 if(Decimal::Parse(datosBd[6]) != nmEdicion->Value)
				 retorno = false;
			 if(datosBd[7] != txbIsbn->Text)
				 retorno = false;
			 if(Decimal::Parse(datosBd[8]) != nmCalificacion->Value)
				 retorno = false;
			 if(!retorno){
				 this->Text = datosBd[0] + "*";
			 }
			 else{
				 this->Text = datosBd[0];
			 }
			 return retorno;
		 }
private: System::Void txbNombre_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 validaCambios();
		 }
private: System::Void txbEditorial_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 validaCambios();
		 }
private: System::Void txbAutor_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 validaCambios();
		 }
private: System::Void nmEdicion_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 validaCambios();
		 }
private: System::Void txbIsbn_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 validaCambios();
		 }
private: System::Void nmCalificacion_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 validaCambios();
		 }
private: System::Void btnCancelar_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }
};
}
