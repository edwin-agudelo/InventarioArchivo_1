#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace InventarioArchivo {

	/// <summary>
	/// Summary for IngresoRuta
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class IngresoRuta : public System::Windows::Forms::Form
	{
	public:
		IngresoRuta(void)
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
		~IngresoRuta()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txbRuta;
	private: System::Windows::Forms::Button^  btnAceptar;
	private: System::Windows::Forms::Button^  btnCancelar;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txbDesc;



	protected: 


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(IngresoRuta::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txbRuta = (gcnew System::Windows::Forms::TextBox());
			this->btnAceptar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txbDesc = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ruta";
			// 
			// txbRuta
			// 
			this->txbRuta->Location = System::Drawing::Point(91, 39);
			this->txbRuta->Name = L"txbRuta";
			this->txbRuta->Size = System::Drawing::Size(100, 20);
			this->txbRuta->TabIndex = 1;
			// 
			// btnAceptar
			// 
			this->btnAceptar->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnAceptar->Location = System::Drawing::Point(35, 183);
			this->btnAceptar->Name = L"btnAceptar";
			this->btnAceptar->Size = System::Drawing::Size(75, 23);
			this->btnAceptar->TabIndex = 2;
			this->btnAceptar->Text = L"&Aceptar";
			this->btnAceptar->UseVisualStyleBackColor = true;
			// 
			// btnCancelar
			// 
			this->btnCancelar->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancelar->Location = System::Drawing::Point(116, 183);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(75, 23);
			this->btnCancelar->TabIndex = 3;
			this->btnCancelar->Text = L"&Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(88, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Descripcion";
			// 
			// txbDesc
			// 
			this->txbDesc->Location = System::Drawing::Point(35, 91);
			this->txbDesc->Multiline = true;
			this->txbDesc->Name = L"txbDesc";
			this->txbDesc->Size = System::Drawing::Size(156, 86);
			this->txbDesc->TabIndex = 5;
			// 
			// IngresoRuta
			// 
			this->AcceptButton = this->btnAceptar;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnCancelar;
			this->ClientSize = System::Drawing::Size(234, 225);
			this->Controls->Add(this->txbDesc);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnAceptar);
			this->Controls->Add(this->txbRuta);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"IngresoRuta";
			this->Text = L"Ingreso Ruta";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: 
			// Ruta
			property String^ vRuta{
				void set(String^ val){
					txbRuta->Text = val;
				}
				String^ get(){
					return txbRuta->Text;
				}
			}
			// Observacion
			property String^ vDesc{
				void set(String^ val){
					txbDesc->Text = val;
				}
				String^ get(){
					return txbDesc->Text;
				}
			}
	};	
}
