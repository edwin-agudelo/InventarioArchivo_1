#pragma once

// Includes Locales
#include "ProcesarDirectorio.h"
#include "admTipos.h"
#include "AgreComentarios.h"
#include "IngresoRuta.h"
#include "EdiLibro.h"



namespace InventarioArchivo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace UtilesInv;
	using namespace System::Diagnostics;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  archivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  salirToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ImageList^  imlIconos;
	private: System::Windows::Forms::TreeView^  trvBiblo;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::ToolStripMenuItem^  herramientaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  revisarDirectorioToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ayudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmAcerca;

	private: System::Windows::Forms::GroupBox^  grpDatos;
	private: System::Windows::Forms::Button^  btnAbrir;
	private: System::Windows::Forms::TextBox^  txbRuta;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txbCantidad;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txbEditorial;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txbNombre;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ToolStripMenuItem^  administrarTiposToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  txbBusqueda;
	private: System::Windows::Forms::DataGridView^  dgvBusRapida;
	private: System::Windows::Forms::TextBox^  txbTamano;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txbAutor;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::DataGridView^  dgvComentarios;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  btnAddComment;
	private: System::Windows::Forms::ToolStripMenuItem^  depurarDivisionesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripStatusLabel^  stlblEstado;
	private: System::Windows::Forms::Button^  btnEditar;
	private: System::Windows::Forms::Label^  lblIdLib;



	private: UtilesInv::UtilesDb^ dbObj;
	private: System::Windows::Forms::ContextMenuStrip^  ctmLibreria;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmCrearDiv;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmBorraDiv;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmBorrarLibro;




			 //private: UtilesInv::DirArch^ arObj;
	private: TreeNode^ nodoDrag;
	private: System::Windows::Forms::ToolStripMenuItem^  agregarLibroToolStripMenuItem;

	private: TreeNode^ nodoSel;
	private: static UtilesLog^ logObj;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->archivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->herramientaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->revisarDirectorioToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administrarTiposToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->depurarDivisionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->agregarLibroToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ayudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmAcerca = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->stlblEstado = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->imlIconos = (gcnew System::Windows::Forms::ImageList(this->components));
			this->trvBiblo = (gcnew System::Windows::Forms::TreeView());
			this->ctmLibreria = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tsmCrearDiv = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmBorraDiv = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tsmBorrarLibro = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->grpDatos = (gcnew System::Windows::Forms::GroupBox());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->btnAddComment = (gcnew System::Windows::Forms::Button());
			this->txbAutor = (gcnew System::Windows::Forms::TextBox());
			this->txbTamano = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btnAbrir = (gcnew System::Windows::Forms::Button());
			this->txbRuta = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txbCantidad = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txbEditorial = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txbNombre = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txbBusqueda = (gcnew System::Windows::Forms::TextBox());
			this->dgvBusRapida = (gcnew System::Windows::Forms::DataGridView());
			this->dgvComentarios = (gcnew System::Windows::Forms::DataGridView());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->lblIdLib = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->ctmLibreria->SuspendLayout();
			this->grpDatos->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvBusRapida))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvComentarios))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->archivoToolStripMenuItem, 
				this->herramientaToolStripMenuItem, this->ayudaToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(211, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->salirToolStripMenuItem});
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->archivoToolStripMenuItem->Text = L"&Archivo";
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			this->salirToolStripMenuItem->Size = System::Drawing::Size(96, 22);
			this->salirToolStripMenuItem->Text = L"&Salir";
			this->salirToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::salirToolStripMenuItem_Click);
			// 
			// herramientaToolStripMenuItem
			// 
			this->herramientaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->revisarDirectorioToolStripMenuItem, 
				this->administrarTiposToolStripMenuItem, this->depurarDivisionesToolStripMenuItem, this->agregarLibroToolStripMenuItem});
			this->herramientaToolStripMenuItem->Name = L"herramientaToolStripMenuItem";
			this->herramientaToolStripMenuItem->Size = System::Drawing::Size(90, 20);
			this->herramientaToolStripMenuItem->Text = L"&Herramientas";
			// 
			// revisarDirectorioToolStripMenuItem
			// 
			this->revisarDirectorioToolStripMenuItem->Name = L"revisarDirectorioToolStripMenuItem";
			this->revisarDirectorioToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->revisarDirectorioToolStripMenuItem->Text = L"&Revisar Directorio";
			this->revisarDirectorioToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::revisarDirectorioToolStripMenuItem_Click);
			// 
			// administrarTiposToolStripMenuItem
			// 
			this->administrarTiposToolStripMenuItem->Name = L"administrarTiposToolStripMenuItem";
			this->administrarTiposToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->administrarTiposToolStripMenuItem->Text = L"Administrar &Tipos";
			this->administrarTiposToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::administrarTiposToolStripMenuItem_Click);
			// 
			// depurarDivisionesToolStripMenuItem
			// 
			this->depurarDivisionesToolStripMenuItem->Name = L"depurarDivisionesToolStripMenuItem";
			this->depurarDivisionesToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->depurarDivisionesToolStripMenuItem->Text = L"Depurar Divisiones";
			this->depurarDivisionesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::depurarDivisionesToolStripMenuItem_Click);
			// 
			// agregarLibroToolStripMenuItem
			// 
			this->agregarLibroToolStripMenuItem->Name = L"agregarLibroToolStripMenuItem";
			this->agregarLibroToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->agregarLibroToolStripMenuItem->Text = L"A&gregar Libro";
			// 
			// ayudaToolStripMenuItem
			// 
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->tsmAcerca});
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			this->ayudaToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->ayudaToolStripMenuItem->Text = L"&Ayuda";
			// 
			// tsmAcerca
			// 
			this->tsmAcerca->Name = L"tsmAcerca";
			this->tsmAcerca->Size = System::Drawing::Size(127, 22);
			this->tsmAcerca->Text = L"Acerca &De";
			// 
			// statusStrip1
			// 
			this->statusStrip1->AutoSize = false;
			this->statusStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->stlblEstado});
			this->statusStrip1->Location = System::Drawing::Point(0, 415);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(898, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// stlblEstado
			// 
			this->stlblEstado->AutoSize = false;
			this->stlblEstado->Name = L"stlblEstado";
			this->stlblEstado->Size = System::Drawing::Size(32, 17);
			this->stlblEstado->Text = L"Listo";
			// 
			// imlIconos
			// 
			this->imlIconos->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"imlIconos.ImageStream")));
			this->imlIconos->TransparentColor = System::Drawing::Color::Transparent;
			this->imlIconos->Images->SetKeyName(0, L"Folder-icon.png");
			this->imlIconos->Images->SetKeyName(1, L"Hard-drive-icon-32.png");
			this->imlIconos->Images->SetKeyName(2, L"Home-Server-icon-32.png");
			this->imlIconos->Images->SetKeyName(3, L"Places-folder-red-icon-32.png");
			this->imlIconos->Images->SetKeyName(4, L"Book-Blank-Book-icon-64.png");
			this->imlIconos->Images->SetKeyName(5, L"address_book_add.png");
			this->imlIconos->Images->SetKeyName(6, L"address_book_error.png");
			// 
			// trvBiblo
			// 
			this->trvBiblo->AllowDrop = true;
			this->trvBiblo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->trvBiblo->ContextMenuStrip = this->ctmLibreria;
			this->trvBiblo->ImageIndex = 2;
			this->trvBiblo->ImageList = this->imlIconos;
			this->trvBiblo->Location = System::Drawing::Point(12, 47);
			this->trvBiblo->Name = L"trvBiblo";
			this->trvBiblo->SelectedImageIndex = 0;
			this->trvBiblo->Size = System::Drawing::Size(234, 338);
			this->trvBiblo->TabIndex = 2;
			this->trvBiblo->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::trvBiblo_MouseUp);
			this->trvBiblo->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::trvBiblo_DragDrop);
			this->trvBiblo->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Form1::trvBiblo_AfterSelect);
			this->trvBiblo->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::trvBiblo_DragEnter);
			this->trvBiblo->AfterExpand += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Form1::trvBiblo_AfterExpand);
			this->trvBiblo->ItemDrag += gcnew System::Windows::Forms::ItemDragEventHandler(this, &Form1::trvBiblo_ItemDrag);
			// 
			// ctmLibreria
			// 
			this->ctmLibreria->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->tsmCrearDiv, this->tsmBorraDiv, 
				this->toolStripSeparator1, this->tsmBorrarLibro});
			this->ctmLibreria->Name = L"ctmLibreria";
			this->ctmLibreria->Size = System::Drawing::Size(152, 76);
			this->ctmLibreria->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::ctmLibreria_Opening);
			// 
			// tsmCrearDiv
			// 
			this->tsmCrearDiv->Name = L"tsmCrearDiv";
			this->tsmCrearDiv->Size = System::Drawing::Size(151, 22);
			this->tsmCrearDiv->Text = L"Crear Seccion";
			this->tsmCrearDiv->Click += gcnew System::EventHandler(this, &Form1::tsmCrearDiv_Click);
			// 
			// tsmBorraDiv
			// 
			this->tsmBorraDiv->Name = L"tsmBorraDiv";
			this->tsmBorraDiv->Size = System::Drawing::Size(151, 22);
			this->tsmBorraDiv->Text = L"Borrar Division";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(148, 6);
			// 
			// tsmBorrarLibro
			// 
			this->tsmBorrarLibro->Name = L"tsmBorrarLibro";
			this->tsmBorrarLibro->Size = System::Drawing::Size(151, 22);
			this->tsmBorrarLibro->Text = L"Borrar Libro";
			this->tsmBorrarLibro->Click += gcnew System::EventHandler(this, &Form1::tsmBorrarLibro_Click);
			// 
			// grpDatos
			// 
			this->grpDatos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->grpDatos->Controls->Add(this->btnEditar);
			this->grpDatos->Controls->Add(this->btnAddComment);
			this->grpDatos->Controls->Add(this->txbAutor);
			this->grpDatos->Controls->Add(this->txbTamano);
			this->grpDatos->Controls->Add(this->label7);
			this->grpDatos->Controls->Add(this->label6);
			this->grpDatos->Controls->Add(this->btnAbrir);
			this->grpDatos->Controls->Add(this->txbRuta);
			this->grpDatos->Controls->Add(this->label4);
			this->grpDatos->Controls->Add(this->txbCantidad);
			this->grpDatos->Controls->Add(this->label3);
			this->grpDatos->Controls->Add(this->txbEditorial);
			this->grpDatos->Controls->Add(this->label2);
			this->grpDatos->Controls->Add(this->txbNombre);
			this->grpDatos->Controls->Add(this->label1);
			this->grpDatos->Location = System::Drawing::Point(266, 47);
			this->grpDatos->Name = L"grpDatos";
			this->grpDatos->Size = System::Drawing::Size(200, 356);
			this->grpDatos->TabIndex = 3;
			this->grpDatos->TabStop = false;
			this->grpDatos->Text = L"Datos";
			// 
			// btnEditar
			// 
			this->btnEditar->Location = System::Drawing::Point(22, 279);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(157, 23);
			this->btnEditar->TabIndex = 14;
			this->btnEditar->Text = L"Editar Datos";
			this->btnEditar->UseVisualStyleBackColor = true;
			this->btnEditar->Click += gcnew System::EventHandler(this, &Form1::btnEditar_Click);
			// 
			// btnAddComment
			// 
			this->btnAddComment->AutoSize = true;
			this->btnAddComment->Enabled = false;
			this->btnAddComment->Location = System::Drawing::Point(22, 308);
			this->btnAddComment->Name = L"btnAddComment";
			this->btnAddComment->Size = System::Drawing::Size(157, 23);
			this->btnAddComment->TabIndex = 13;
			this->btnAddComment->Text = L"Agregar Comentario";
			this->btnAddComment->UseVisualStyleBackColor = true;
			this->btnAddComment->Click += gcnew System::EventHandler(this, &Form1::btnAddComment_Click);
			// 
			// txbAutor
			// 
			this->txbAutor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txbAutor->Location = System::Drawing::Point(22, 117);
			this->txbAutor->Name = L"txbAutor";
			this->txbAutor->ReadOnly = true;
			this->txbAutor->Size = System::Drawing::Size(157, 20);
			this->txbAutor->TabIndex = 12;
			// 
			// txbTamano
			// 
			this->txbTamano->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txbTamano->Location = System::Drawing::Point(103, 162);
			this->txbTamano->Name = L"txbTamano";
			this->txbTamano->ReadOnly = true;
			this->txbTamano->Size = System::Drawing::Size(76, 20);
			this->txbTamano->TabIndex = 10;
			this->txbTamano->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(19, 101);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(32, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Autor";
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(100, 146);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(69, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Tamano (KB)";
			// 
			// btnAbrir
			// 
			this->btnAbrir->Location = System::Drawing::Point(22, 250);
			this->btnAbrir->Name = L"btnAbrir";
			this->btnAbrir->Size = System::Drawing::Size(157, 23);
			this->btnAbrir->TabIndex = 8;
			this->btnAbrir->Text = L"Abrir";
			this->btnAbrir->UseVisualStyleBackColor = true;
			this->btnAbrir->Click += gcnew System::EventHandler(this, &Form1::btnAbrir_Click);
			// 
			// txbRuta
			// 
			this->txbRuta->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txbRuta->Location = System::Drawing::Point(22, 204);
			this->txbRuta->Name = L"txbRuta";
			this->txbRuta->ReadOnly = true;
			this->txbRuta->Size = System::Drawing::Size(157, 20);
			this->txbRuta->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 188);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Ubicacion";
			// 
			// txbCantidad
			// 
			this->txbCantidad->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txbCantidad->Location = System::Drawing::Point(22, 162);
			this->txbCantidad->Name = L"txbCantidad";
			this->txbCantidad->ReadOnly = true;
			this->txbCantidad->Size = System::Drawing::Size(46, 20);
			this->txbCantidad->TabIndex = 5;
			this->txbCantidad->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Cantidad";
			// 
			// txbEditorial
			// 
			this->txbEditorial->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txbEditorial->Location = System::Drawing::Point(22, 77);
			this->txbEditorial->Name = L"txbEditorial";
			this->txbEditorial->ReadOnly = true;
			this->txbEditorial->Size = System::Drawing::Size(157, 20);
			this->txbEditorial->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Editorial";
			// 
			// txbNombre
			// 
			this->txbNombre->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txbNombre->Location = System::Drawing::Point(22, 35);
			this->txbNombre->Name = L"txbNombre";
			this->txbNombre->ReadOnly = true;
			this->txbNombre->Size = System::Drawing::Size(157, 20);
			this->txbNombre->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre";
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(620, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Busqueda Rapida";
			// 
			// txbBusqueda
			// 
			this->txbBusqueda->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->txbBusqueda->Location = System::Drawing::Point(582, 66);
			this->txbBusqueda->Name = L"txbBusqueda";
			this->txbBusqueda->Size = System::Drawing::Size(173, 20);
			this->txbBusqueda->TabIndex = 5;
			this->txbBusqueda->TextChanged += gcnew System::EventHandler(this, &Form1::txbBusqueda_TextChanged);
			// 
			// dgvBusRapida
			// 
			this->dgvBusRapida->AllowUserToAddRows = false;
			this->dgvBusRapida->AllowUserToDeleteRows = false;
			this->dgvBusRapida->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgvBusRapida->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvBusRapida->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvBusRapida->Location = System::Drawing::Point(487, 92);
			this->dgvBusRapida->Name = L"dgvBusRapida";
			this->dgvBusRapida->Size = System::Drawing::Size(376, 210);
			this->dgvBusRapida->TabIndex = 6;
			this->dgvBusRapida->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dgvBusRapida_CellContentDoubleClick);
			// 
			// dgvComentarios
			// 
			this->dgvComentarios->AllowUserToAddRows = false;
			this->dgvComentarios->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgvComentarios->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvComentarios->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvComentarios->Location = System::Drawing::Point(487, 326);
			this->dgvComentarios->Name = L"dgvComentarios";
			this->dgvComentarios->Size = System::Drawing::Size(376, 77);
			this->dgvComentarios->TabIndex = 13;
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(635, 310);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(65, 13);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Comentarios";
			// 
			// lblIdLib
			// 
			this->lblIdLib->AutoSize = true;
			this->lblIdLib->Location = System::Drawing::Point(821, 28);
			this->lblIdLib->Name = L"lblIdLib";
			this->lblIdLib->Size = System::Drawing::Size(35, 13);
			this->lblIdLib->TabIndex = 15;
			this->lblIdLib->Text = L"label9";
			this->lblIdLib->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(898, 437);
			this->Controls->Add(this->lblIdLib);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->dgvComentarios);
			this->Controls->Add(this->dgvBusRapida);
			this->Controls->Add(this->txbBusqueda);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->grpDatos);
			this->Controls->Add(this->trvBiblo);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Biblioteca";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ctmLibreria->ResumeLayout(false);
			this->grpDatos->ResumeLayout(false);
			this->grpDatos->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvBusRapida))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvComentarios))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 // Valido los directorios
				 DirArch::initDirs();
				 if(!DirArch::testDirs()){
					 //MessageBox::Show("Directorios validados");
					 DirArch::creaDirsIni();//creaDirsIni
				 }
				 //else {
					 //MessageBox::Show("Directorios NO validados");
				 // }

				 // Realizo una carga de prueba
				 //dbObj = gcnew UtilesDb("C:\\Users\\Edwin\\Documents\\Visual Studio 2005\\Ayudas\\libreria.db");
				 //dbObj = gcnew UtilesDb(Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\LibreriaSBI\\data\\libreria.db"));
				 dbObj = gcnew UtilesDb();
				 if(!DirArch::testArch()){
					 if(!dbObj->crearDb()){
						 MessageBox::Show("Error creando la base de datos!!!","Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
						 Close();
						 return;
					 }
				 }
				 else{
					 if(!dbObj->validaBd()){
						 DirArch::borrarArch(dbObj->getPathDb());
						 if(!dbObj->crearDb()){
							 MessageBox::Show("Error creando la base de datos!!!","Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
							 Close();
							 return;
						 }
					 }
				 }
				 trvBiblo->Nodes->AddRange(dbObj->traerDivs());
				 logObj = gcnew UtilesLog();
				 //trvBiblo->Nodes->AddRange(dbObj->traerDivs());
				 //trvBiblo->Nodes[0]->FirstNode->Nodes->AddRange(dbObj->traerDivs());
			 }
private: System::Void revisarDirectorioToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Ahora debo mostrar el otro dialogo
			 ProcesarDirectorio^ prcdlg = gcnew ProcesarDirectorio();
			 prcdlg->vDb = dbObj;
			 prcdlg->ShowDialog();
			 delete prcdlg;
			 trvBiblo->Nodes->Clear();
			 trvBiblo->Nodes->AddRange(dbObj->traerDivs());
		 }
private: System::Void trvBiblo_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
			 // Cargo la division
			 //trvBiblo->Nodes[e->Node->Name]->Nodes->AddRange(dbObj->traerDivs(int::Parse(e->Node->Name)));
			 //trvBiblo->Nodes->AddRange(dbObj->traerDivs((int)e->Node->Index));

			 // Con esta parte tengo que traer la informacion del la seleccion
			 if(e->Node->Name->Length > 1){
				 int tipo = (e->Node->Name->Contains("L") ? 0:1);
				 array<String^>^ datos = dbObj->traerDatosLib(int::Parse(e->Node->Name->Substring(1)),tipo);
				 if(datos != nullptr){
					 txbNombre->Text = datos[0];
					 txbAutor->Text = datos[1];
					 txbEditorial->Text = datos[2];
					 txbCantidad->Text = datos[3];
					 txbTamano->Text = datos[4];
					 txbRuta->Text = datos[5];
					 if(tipo == 0){
						 dgvComentarios->DataSource = dbObj->traerComentarios(int::Parse(e->Node->Name->Substring(1)));
						 btnAddComment->Enabled = true;
						 lblIdLib->Text = e->Node->Name->Substring(1);
						 btnEditar->Enabled = true;
					 }
					 else{
						 btnAddComment->Enabled = false;
						 lblIdLib->Text = "";
						 dgvComentarios->DataSource = nullptr;
						 btnEditar->Enabled = false;
					 }
				 }
			 }
			 else{
				 txbNombre->Text = "";
				 txbAutor->Text = "";
				 txbEditorial->Text = "";
				 txbCantidad->Text = "";
				 txbTamano->Text = "";
				 txbRuta->Text = "";
				 dgvComentarios->DataSource = nullptr;
				 btnEditar->Enabled = false;
				 btnAddComment->Enabled = false;
				 btnAbrir->Enabled = false;
			 }


			 if(e->Node->Nodes->Count > 0)
				 return;
			 if(e->Node->Name->Contains("L")){
				 if(DirArch::testArch(dbObj->traerDatosLib(int::Parse(e->Node->Name->Substring(1)),0)[5]))
					 e->Node->SelectedImageIndex = 5;
				 else
					 e->Node->SelectedImageIndex = 6;
			 }
			 // Con esto traigo la informacion del archivo
			 if(e->Node->Name->Contains("D") || e->Node->Name->Contains("L")){
				 if(e->Node->Name->Contains("D")){
					 array<TreeNode^>^ nodos = dbObj->traerDivs(int::Parse(e->Node->Name->Substring(1))); 
					 for(int i = 0; i < nodos->Length ; i++){
						 if(nodos[i]->Name->Contains("L")){
							 nodos[i]->ImageIndex = 4;
						 }
					 }
					 e->Node->Nodes->AddRange(nodos);
				 }
				 else{
					 // Le hago otra cosa
				 }
			 }
			 else{ // Es un archivo
				 trvBiblo->Nodes[e->Node->Name]->Nodes->AddRange(dbObj->traerDivs(int::Parse(e->Node->Name)));
			 }
			 
		 }
private: System::Void trvBiblo_AfterExpand(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
			 // Cargo la division
			 //trvBiblo->Nodes->AddRange(dbObj->traerDivs((int)e->Node->Index));
		 }

private: System::Void txbBusqueda_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 // Con esto debo buscar en toda la base de datos, tanto en divisiones
			 // como en libros
			 if(txbBusqueda->Text->Trim()->Length == 0){
				 dgvBusRapida->DataSource = nullptr;
				 dgvBusRapida->Refresh();
				 return;
			 }
			 DataTable^ dt = dbObj->traerLista(txbBusqueda->Text);
			 if(dt != nullptr){
				dgvBusRapida->DataSource = dt;
				dgvBusRapida->Columns[0]->Visible = false;
				dgvBusRapida->Columns[1]->Visible = false;
				dgvBusRapida->Columns[5]->Visible = false;
				dgvBusRapida->Columns[7]->Visible = false;
				dgvBusRapida->Columns[8]->Visible = false;

			 }
		 }
private: System::Void btnAbrir_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(txbRuta->Text == "")
				 return;
			 DirArch::abrirArch(txbRuta->Text);
		 }
private: System::Void depurarDivisionesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(MessageBox::Show("Desea borrar las divisiones con 0 libros en su interior?","Error",MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes){
				 stlblEstado->Text = "Depurando, por favor espere...";
				 dbObj->depurarDivs(0); // Inicio en el primer elemento
				 stlblEstado->Text = "Listo";
			 }
		 }
private: System::Void administrarTiposToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Creo el nuevo elemento
			 admTipos^ dlgTipo = gcnew admTipos();
			 dlgTipo->dbAcc = dbObj;
			 dlgTipo->ShowDialog();
			 delete dlgTipo;
		 }
private: System::Void dgvBusRapida_CellContentDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 // Debo abrir el archivo o directorio
			 int tipo = int::Parse(dgvBusRapida->Rows[e->RowIndex]->Cells[1]->Value->ToString());
			 if(tipo == 0){
				 if(!DirArch::testArch(dgvBusRapida->Rows[e->RowIndex]->Cells[8]->Value->ToString())){
					 MessageBox::Show("No se tiene acceso al archivo citado","Atencion",MessageBoxButtons::OK, MessageBoxIcon::Stop);
					 return;
				 }
			 }
			 else{
				 if(!DirArch::testDirs(dgvBusRapida->Rows[e->RowIndex]->Cells[8]->Value->ToString())){
					 MessageBox::Show("No se tiene acceso al archivo citado","Atencion",MessageBoxButtons::OK, MessageBoxIcon::Stop);
					 return;
				 }
			 }
			 DirArch::abrirArch(dgvBusRapida->Rows[e->RowIndex]->Cells[8]->Value->ToString());
		 }
private: System::Void trvBiblo_ItemDrag(System::Object^  sender, System::Windows::Forms::ItemDragEventArgs^  e) {
			 nodoDrag = (TreeNode^)e->Item;
			 DoDragDrop(e->Item, DragDropEffects::Move | DragDropEffects::Copy);
		 }
private: System::Void trvBiblo_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			 e->Effect = DragDropEffects::Move ;
		 }
private: System::Void trvBiblo_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			 TreeNode^ newNode;
			 if(e->Data->GetDataPresent("System.Windows.Forms.TreeNode",false)){
				 Point p(e->X,e->Y);
				 Point pt = ((TreeView^)(sender))->PointToClient(p);
				 TreeNode^ DestinationNode = ((TreeView ^)(sender))->GetNodeAt(pt);
				 newNode = (TreeNode^)(e->Data->GetData("System.Windows.Forms.TreeNode"));
				 if( (DestinationNode != newNode->Parent) && (DestinationNode->Name->Length > 1) && (DestinationNode->Name->Contains("D")) )
				 {
					 if( newNode->Name->Contains("L") ){
						 int idDivN = int::Parse(DestinationNode->Name->Substring(1));
						 int idDivA = int::Parse(newNode->Parent->Name->Substring(1));
						 int idLib = int::Parse(newNode->Name->Substring(1));
						 String^ rutaAnterior = dbObj->traerDatosLib(idLib,0)[5];
						 String^ rutaNueva = (dbObj->traerDatosLib(idDivN,1)[5]) + "\\" + (dbObj->traerDatosLib(idDivN,1)[0]) + "\\" + (dbObj->traerDatosLib(idLib,0)[0]);
						 // Realizo el procesamiento en disco primero
						 if(!DirArch::testArch(rutaAnterior)){
							 // SI no existe
							 MessageBox::Show("No se puede encontrar el archivo [" + rutaAnterior + "]","Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
							 return;
						 }
						 if(DirArch::testArch(rutaNueva)){
							 // SI existe
							 MessageBox::Show("No se puede mover el archivo [" + rutaAnterior + "] hacia [" + rutaNueva + "]","Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
							 return;
						 }
						 // ahora intento moverlo en disco
						 try{
							 DirArch::moverArch(rutaAnterior, rutaNueva);
							 if(!dbObj->moverDirectorio(idLib,rutaNueva,idDivN)){
								 DirArch::moverArch(rutaNueva,rutaAnterior);
								 MessageBox::Show("No se puede actualizar el libro, por favor verifique","Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
								 return;
							 }
							 DestinationNode->Nodes->Clear();
							 array<TreeNode^>^ nodos = dbObj->traerDivs(int::Parse(DestinationNode->Name->Substring(1))); 
							 for(int i = 0; i < nodos->Length ; i++){
								 if(nodos[i]->Name->Contains("L")){
									 nodos[i]->ImageIndex = 4;
								 }
							 }
							 DestinationNode->Nodes->AddRange(nodos);
							 newNode->Remove();
							 DestinationNode->Expand();
						 }
						 catch(Exception^ ex){
							 MessageBox::Show("Error intentando mover el libro -> " + ex->Message,"Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
							 return;
						 }
						 //DestinationNode->Nodes->Add((TreeNode^)newNode->Clone());
						 //DestinationNode->Nodes->Add((newNode->Clone()));
						 //DestinationNode->Expand();
						 //Remove Original Node
						 //newNode->Remove();
					 }
				 }
			 }
		 }
private: System::Void btnAddComment_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Agrego el comentario
			 if(lblIdLib->Text != ""){
				 AgreComentarios^ dlgComm = gcnew AgreComentarios();
				 dlgComm->ObjetoBD = dbObj;
				 dlgComm->LibroId = int::Parse(lblIdLib->Text);
				 dlgComm->ShowDialog();
				 delete  dlgComm;
				 dgvComentarios->DataSource = dbObj->traerComentarios(int::Parse(lblIdLib->Text));
			 }
		 }
private: System::Void ctmLibreria_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 // Debo identificar donde estoy
			 //TreeNode^ elemento = (TreeNode^)((ContextMenuStrip^)sender)//->SourceControl;
			 //TreeNode^ elemento = (TreeNode^)sender;
			 TreeNode^ elemento = trvBiblo->SelectedNode;
			 //MessageBox::Show("Objeto:" + elemento->Text);
		 }
private: System::Void tsmBorrarLibro_Click(System::Object^  sender, System::EventArgs^  e) {
			 // 
			 if(nodoSel != nullptr){
				 //MessageBox::Show("Objeto:" + nodoSel->Text);
				 if(MessageBox::Show("Desea eliminar el archivo [" + dbObj->traerDatosLib(int::Parse(nodoSel->Name->Substring(1)),0)[0] + "]","Atencion",MessageBoxButtons::YesNo,MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes){

				 }
			 }
		 }
private: System::Void trvBiblo_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 // Para detectar el elemento
			 if(e->Button == Windows::Forms::MouseButtons::Right){
				 Point p(e->X,e->Y);
				 //Point pt = ((TreeView^)(sender))->PointToClient(p);
				 //nodoSel = ((TreeView ^)(sender))->GetNodeAt(pt);
				 nodoSel = ((TreeView ^)(sender))->GetNodeAt(p);
				 if( nodoSel->Name->Contains("L") || nodoSel->Name->Contains("D") ){
					 if( nodoSel->Name->Contains("L") ){
						 tsmCrearDiv->Enabled = false;
						 tsmBorraDiv->Enabled = false;
						 tsmBorrarLibro->Enabled = true;
					 }
					 else{
						 tsmCrearDiv->Enabled = true;
						 tsmBorraDiv->Enabled = true;
						 tsmBorrarLibro->Enabled = false;
					 }
				 }
			 }
			 else{
				 nodoSel = nullptr;
			 }
		 }
private: System::Void tsmCrearDiv_Click(System::Object^  sender, System::EventArgs^  e) {
			 // debo crear la nueva division
			 IngresoRuta^ dlgRuta = gcnew IngresoRuta();
			 if(dlgRuta->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				 if(dlgRuta->vRuta->Length > 2){
					 Regex^ reg = gcnew Regex("^[a-zA-Z0-9 ]*$");
					 String^ rutaNueva = dlgRuta->vRuta;
					 String^ strDescripcion = dlgRuta->vDesc;
					 if(reg->IsMatch(rutaNueva)){
						 String^ pathNuevo = dbObj->traerDatosLib(int::Parse(nodoSel->Name->Substring(1)),1)[5] + "\\" + dbObj->traerDatosLib(int::Parse(nodoSel->Name->Substring(1)),1)[0] + "\\" + rutaNueva;
						 if(!DirArch::testDirs(pathNuevo)){
							 if(!DirArch::creaDir(pathNuevo)){
								 MessageBox::Show("No se puede crear el directorio en disco");
								 return;
							 }
						 }
						 if(dbObj->validaDivision(pathNuevo) > 1){ // Existe ya en la BD
							 for each(TreeNode^ t in nodoSel->Parent->Nodes){
								 if(t->Text == rutaNueva){
									 MessageBox::Show("La ruta ya se encuentra creada, por favor valide","Atencion",MessageBoxButtons::OK, MessageBoxIcon::Stop);
									 return;
								 }
							 }
						 }
						 else{ // No existe y hay que crearlo
							 if(dbObj->crearDivision(pathNuevo,strDescripcion,1) == 0){
								 MessageBox::Show("No se pudo crear la division","Atencion",MessageBoxButtons::OK, MessageBoxIcon::Stop);
								 return;
							 }
						 }
						 nodoSel->Nodes->Add(dbObj->traerDiv(pathNuevo,int::Parse(nodoSel->Name->Substring(1))));
					 }
					 else{
						 MessageBox::Show("Error en la ruta > No se admiten caracteres especiales","Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
					 }
				 }
			 }
			 delete dlgRuta;
		 }
private: System::Void salirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 delete logObj;
		 }
private: System::Void btnEditar_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Ahora ahora
			 EdiLibro^ dlgEdi = gcnew EdiLibro();
			 dlgEdi->vIdLibro = int::Parse(lblIdLib->Text);
			 dlgEdi->vObjDb = dbObj;
			 dlgEdi->vObjLog = logObj;
			 dlgEdi->ShowDialog();
			 //
			 delete dlgEdi;
		 }
};
}

