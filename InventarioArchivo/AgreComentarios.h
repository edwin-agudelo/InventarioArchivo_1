#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace UtilesInv;


namespace InventarioArchivo {

	/// <summary>
	/// Summary for AgreComentarios
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class AgreComentarios : public System::Windows::Forms::Form
	{
	public:
		AgreComentarios(void)
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
		~AgreComentarios()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txbComentario;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lblLibro;
	private: System::Windows::Forms::Button^  btnAceptar;
	private: System::Windows::Forms::Button^  btnCancelar;
	private: UtilesDb^ dbObj;
	private: int idLibro;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AgreComentarios::typeid));
			this->txbComentario = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblLibro = (gcnew System::Windows::Forms::Label());
			this->btnAceptar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txbComentario
			// 
			this->txbComentario->Location = System::Drawing::Point(27, 74);
			this->txbComentario->Multiline = true;
			this->txbComentario->Name = L"txbComentario";
			this->txbComentario->Size = System::Drawing::Size(314, 265);
			this->txbComentario->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(50, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Libro:";
			// 
			// lblLibro
			// 
			this->lblLibro->AutoSize = true;
			this->lblLibro->Location = System::Drawing::Point(95, 31);
			this->lblLibro->Name = L"lblLibro";
			this->lblLibro->Size = System::Drawing::Size(35, 13);
			this->lblLibro->TabIndex = 2;
			this->lblLibro->Text = L"label2";
			// 
			// btnAceptar
			// 
			this->btnAceptar->Location = System::Drawing::Point(65, 359);
			this->btnAceptar->Name = L"btnAceptar";
			this->btnAceptar->Size = System::Drawing::Size(96, 39);
			this->btnAceptar->TabIndex = 3;
			this->btnAceptar->Text = L"&Aceptar";
			this->btnAceptar->UseVisualStyleBackColor = true;
			this->btnAceptar->Click += gcnew System::EventHandler(this, &AgreComentarios::btnAceptar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(193, 359);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(96, 39);
			this->btnCancelar->TabIndex = 4;
			this->btnCancelar->Text = L"&Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &AgreComentarios::btnCancelar_Click);
			// 
			// AgreComentarios
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(380, 410);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnAceptar);
			this->Controls->Add(this->lblLibro);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txbComentario);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"AgreComentarios";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Agregar Comentarios";
			this->Load += gcnew System::EventHandler(this, &AgreComentarios::AgreComentarios_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		public: property UtilesDb^ ObjetoBD{
					void set(UtilesDb^ val){
						dbObj = val;
					}
				}
		public: property int LibroId{
					void set(int val){
						idLibro = val;
					}
				}
	private: System::Void btnCancelar_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }
private: System::Void AgreComentarios_Load(System::Object^  sender, System::EventArgs^  e) {
			 // Debo cargar el nombre del libro
			 if(idLibro == 0){
				 MessageBox::Show("Error en el identificador del libro","Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 Close();
				 return;
			 }
			 try{
				 lblLibro->Text = dbObj->traerDatosLib(idLibro,0)[0];
			 }catch(Exception^ ex){
				 MessageBox::Show("Error al traer la informacion del libro -> " + ex->Message, "Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 Close();
				 return;
			 }
		 }
private: System::Void btnAceptar_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Debo insertar el comentario
			 if(txbComentario->Text->Trim()->Length < 3){
				 MessageBox::Show("Por favor ingrese un comentario mas largo","Atencion",MessageBoxButtons::OK, MessageBoxIcon::Stop);
				 return;
			 }
			 if(dbObj->crearComentario(idLibro,txbComentario->Text)){
				 MessageBox::Show("Comentario Insertado Correctamente > " + lblLibro->Text->ToUpper(),"Procesado Ok",MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				 Close();
				 return;
			 }
			 else{
				 MessageBox::Show("Comentario no se pudo insertar > " + lblLibro->Text->ToUpper(),"Procesado Ok",MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			 }
		 }
};
}
