#pragma once

#include "UtilesInv.h"

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Data::SQLite;
using namespace System::Data;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Reflection;

namespace UtilesInv {
	
	public ref class UtilesDb
	{
	private: 
		SQLiteConnection^ con;
		String^ rutaDb;
	public:
		UtilesDb(void);
		UtilesDb(String^ ruta);
		~UtilesDb();

		/**
		* Funcion para recrear la BD
		*/
		bool crearDb();

		///
		/// Funcion para validar el estado de la BD
		///
		bool validaBd();

		///
		/// Retorna el nombre de la BD
		///
		String^ getPathDb();

		/**
		* Funcion para traer las divisiones existentes
		*/
		array<TreeNode^>^ traerDivs();

		/**
		* Funcion para traer las divisiones hijas de un div_id
		*/
		array<TreeNode^>^ traerDivs(int div);

		/// 
		/// Funcion que trae un solo nodo existente
		/// 
		/// Se le debe pasar la ruta
		///
		TreeNode^ traerDiv(String^ path, int div);

		/// Funcion que retorna los tipos de archivo a procesar
		Dictionary<String^, int>^ getFTypes();

		// Funcion que retorna los tipos de archivo a procesar
		DataTable^ traeTipos();

		/// Funcion que retorna as editoriales de archivo a procesar
		/// No recibe nada
		Dictionary<String^, int>^ getFEditors();

		/// Funcionalidad que valida y retorna el id de una division
		/// Recibe la ruta completa del directorio para validar su
		/// existencia dentro de las divisiones
		int validaDivision(String^ path);

		/// Funcionalidad que valida y retorna el id de un archivo
		/// Recibe la ruta completa del archivo para validar su
		/// existencia dentro de los archivos
		int validaLibro(String^ path);

		/// Funcionalidad que crea una nueva division
		/// Recibe la ruta completa de la division
		int crearDivision(String^ path, String^ descripcion);

		/// Funcionalidad que crea una nueva division
		/// Recibe la ruta completa de la division
		int crearDivision(String^ path, String^ descripcion, int usuario);

		/// Funcionalidad que crea una nueva division
		/// Recibe la ruta completa de la division
		int crearLibro(String^ path, int editorial, String^ autor, int edicion, int anio, double tamanio, String^ isbn, int tipo);

		///
		/// Busca informacion del objeto
		/// Recibe el id del elemento y el tipo
		/// Retorna un array de strings
		///
		array<String^>^ traerDatosLib(int idEle, int tipo);

		///
		/// Busca informacion del objeto
		/// Recibe el id del elemento y el tipo
		/// Retorna un array de strings
		///
		DataTable^ traerLista(String^ nom);

		///
		/// Busca los comentarios de un libro
		/// Recibe el id del elemento y el tipo
		/// Retorna un array de strings
		///
		DataTable^ traerComentarios(int idLib);

		/**
		* Funcion que depura una division de manera recursiva
		*/
		int depurarDivs(int inicio);

		/**
			crearTipo(): Crea un tipo
		*/
		bool crearTipo(String^ desc, String^ ext);

		/**
			crearComentario(): Crea un tipo
		*/
		bool crearComentario(int idLibro, String^ comentario);


		/**
			moverDirectorio(): Actualizar un libro
		*/
		bool moverDirectorio(int idLibro, String^ ruta, int idDiv);


		///
		/// Funcion de autocompletado para editoriales
		///
		AutoCompleteStringCollection^ traeAutoCom();

	private:

		bool borraDiv(int idDiv);
		bool validaDirectorio(int iddiv);

	};
}
