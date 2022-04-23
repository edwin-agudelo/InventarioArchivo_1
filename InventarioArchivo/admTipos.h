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
	/// Summary for admTipos
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class admTipos : public System::Windows::Forms::Form
	{
	public:
		admTipos(void)
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
		~admTipos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dgvTipos;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txbNombre;
	private: System::Windows::Forms::TextBox^  txbExtension;


	private: System::Windows::Forms::Button^  btnGuardar;
	private: System::Windows::Forms::Button^  btnAgregar;
	private: System::Windows::Forms::GroupBox^  grpDatosT;
	private: System::Windows::Forms::Button^  btnCerrar;
	private: UtilesDb^ objDb;
	private: System::Windows::Forms::Label^  lblIdEd;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(admTipos::typeid));
			this->dgvTipos = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txbNombre = (gcnew System::Windows::Forms::TextBox());
			this->txbExtension = (gcnew System::Windows::Forms::TextBox());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->grpDatosT = (gcnew System::Windows::Forms::GroupBox());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());
			this->lblIdEd = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTipos))->BeginInit();
			this->grpDatosT->SuspendLayout();
			this->SuspendLayout();
			// 
			// dgvTipos
			// 
			this->dgvTipos->AllowUserToAddRows = false;
			this->dgvTipos->AllowUserToDeleteRows = false;
			this->dgvTipos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvTipos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTipos->Location = System::Drawing::Point(12, 43);
			this->dgvTipos->Name = L"dgvTipos";
			this->dgvTipos->Size = System::Drawing::Size(180, 165);
			this->dgvTipos->TabIndex = 0;
			this->dgvTipos->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &admTipos::dgvTipos_CellContentClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(69, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Tipos";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Nombre";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 59);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Extension";
			// 
			// txbNombre
			// 
			this->txbNombre->Location = System::Drawing::Point(72, 15);
			this->txbNombre->Name = L"txbNombre";
			this->txbNombre->ReadOnly = true;
			this->txbNombre->Size = System::Drawing::Size(100, 20);
			this->txbNombre->TabIndex = 4;
			// 
			// txbExtension
			// 
			this->txbExtension->Location = System::Drawing::Point(72, 56);
			this->txbExtension->Name = L"txbExtension";
			this->txbExtension->ReadOnly = true;
			this->txbExtension->Size = System::Drawing::Size(100, 20);
			this->txbExtension->TabIndex = 5;
			// 
			// btnGuardar
			// 
			this->btnGuardar->Location = System::Drawing::Point(16, 82);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(75, 23);
			this->btnGuardar->TabIndex = 6;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = true;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &admTipos::btnGuardar_Click);
			// 
			// btnAgregar
			// 
			this->btnAgregar->Location = System::Drawing::Point(97, 82);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(75, 23);
			this->btnAgregar->TabIndex = 7;
			this->btnAgregar->Text = L"Agregar";
			this->btnAgregar->UseVisualStyleBackColor = true;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &admTipos::btnAgregar_Click);
			// 
			// grpDatosT
			// 
			this->grpDatosT->Controls->Add(this->btnAgregar);
			this->grpDatosT->Controls->Add(this->btnGuardar);
			this->grpDatosT->Controls->Add(this->txbExtension);
			this->grpDatosT->Controls->Add(this->txbNombre);
			this->grpDatosT->Controls->Add(this->label3);
			this->grpDatosT->Controls->Add(this->label2);
			this->grpDatosT->Location = System::Drawing::Point(198, 52);
			this->grpDatosT->Name = L"grpDatosT";
			this->grpDatosT->Size = System::Drawing::Size(189, 121);
			this->grpDatosT->TabIndex = 8;
			this->grpDatosT->TabStop = false;
			this->grpDatosT->Text = L"Datos de Tipo";
			// 
			// btnCerrar
			// 
			this->btnCerrar->Location = System::Drawing::Point(198, 185);
			this->btnCerrar->Name = L"btnCerrar";
			this->btnCerrar->Size = System::Drawing::Size(189, 23);
			this->btnCerrar->TabIndex = 9;
			this->btnCerrar->Text = L"&Cerrar";
			this->btnCerrar->UseVisualStyleBackColor = true;
			this->btnCerrar->Click += gcnew System::EventHandler(this, &admTipos::btnCerrar_Click);
			// 
			// lblIdEd
			// 
			this->lblIdEd->AutoSize = true;
			this->lblIdEd->Location = System::Drawing::Point(292, 36);
			this->lblIdEd->Name = L"lblIdEd";
			this->lblIdEd->Size = System::Drawing::Size(35, 13);
			this->lblIdEd->TabIndex = 10;
			this->lblIdEd->Text = L"label4";
			this->lblIdEd->Visible = false;
			// 
			// admTipos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(401, 235);
			this->Controls->Add(this->lblIdEd);
			this->Controls->Add(this->btnCerrar);
			this->Controls->Add(this->grpDatosT);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dgvTipos);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"admTipos";
			this->Text = L"Administracion de Tipos";
			this->Load += gcnew System::EventHandler(this, &admTipos::admTipos_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvTipos))->EndInit();
			this->grpDatosT->ResumeLayout(false);
			this->grpDatosT->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:
			property UtilesDb^ dbAcc{
				void set(UtilesDb^ val){
					objDb = val;
				}
			}
	private: System::Void admTipos_Load(System::Object^  sender, System::EventArgs^  e) {
				 // Debo traer los datos de los tipos creados
				 if(objDb == nullptr){
					 MessageBox::Show("No se tiene conexion a la base de datos","Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
					 Close();
					 return;
				 }
				 dgvTipos->DataSource = objDb->traeTipos();
			 }
private: System::Void dgvTipos_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 // PAso la informacion hacia 
			 txbNombre->ReadOnly = true;
			 txbExtension->ReadOnly = true;
			 txbNombre->Text = "";
			 txbExtension->Text = "";
			 try{
				 txbNombre->Text = (String^)dgvTipos->Rows[e->RowIndex]->Cells[2]->Value;
				 txbExtension->Text = (String^)dgvTipos->Rows[e->RowIndex]->Cells[1]->Value;
				 lblIdEd->Text = dgvTipos->Rows[e->RowIndex]->Cells[1]->Value->ToString();
			 }catch(Exception^ ex){
				 MessageBox::Show("Error cargando la informacion:" + ex->Message,"Error",MessageBoxButtons::OK,MessageBoxIcon::Error);
				 return;
			 }
		 }
private: System::Void btnCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Cierro
			 Close();
		 }
private: System::Void btnAgregar_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Debo borrar y deshabilitar
			 txbNombre->Text = "";
			 txbNombre->ReadOnly = false;
			 txbExtension->Text = "";
			 txbExtension->ReadOnly = false;
			 lblIdEd->Text = "";
			 btnAgregar->Enabled = false;
		 }
private: System::Void btnGuardar_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(lblIdEd->Text == ""){ // Creacion
				 if(objDb->crearTipo(txbNombre->Text, txbExtension->Text)){
					dgvTipos->DataSource = objDb->traeTipos();
					txbNombre->Text = "";
					txbExtension->Text = "";
					txbNombre->ReadOnly = true;
					txbExtension->ReadOnly = true;
					btnAgregar->Enabled = true;
				 }
			 }
		 }
};
}
