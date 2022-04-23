// UtilesInv.h

#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;

namespace UtilesInv {

	public ref class DirArch
	{
	private:
		static Dictionary<String^,String^>^ directorios;
	public:

		static void initDirs(){
			if(directorios == nullptr)
				directorios = gcnew Dictionary<String^, String^>();
			if(!directorios->ContainsKey("principal"))
				directorios->Add("principal",Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\LibreriaSBI");
			if (!directorios->ContainsKey("datos"))
				directorios->Add("datos",Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\LibreriaSBI\\data");
			if (!directorios->ContainsKey("temporal"))
				directorios->Add("temporal",Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\LibreriaSBI\\temp");
			if (!directorios->ContainsKey("log"))
				directorios->Add("log",Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\LibreriaSBI\\log");
			if (!directorios->ContainsKey("rutadb"))
				directorios->Add("rutadb", Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\LibreriaSBI\\data\\libreria.db");
		}

		/// Valida la existencia de los directorios de la aplicacion
		static bool testDirs(){
			bool retorno = true;
			initDirs();
			if(!Directory::Exists(directorios["principal"])){
				retorno = false;
			}
			if(!Directory::Exists(directorios["datos"])){
				retorno = false;
			}
			if(!Directory::Exists(directorios["temporal"])){
				retorno = false;
			}
			return retorno;
		}

		/// Valida los archivos (datos y configuracion)
		static bool testArch(){
			bool retorno = true;
			if(!File::Exists(directorios["rutadb"]))
				retorno = false;
			return retorno;
		}

		/// Valida la existencia de los directorios de la aplicacion
		static bool testDirs(String^ val){
			bool retorno = true;
			if(!Directory::Exists(val)){
				retorno = false;
			}
			return retorno;
		}

		/// Valida los archivos (datos y configuracion)
		static bool testArch(String^ val){
			bool retorno = true;
			if(!File::Exists(val))
				retorno = false;
			return retorno;
		}

		// Realizac creacion de directorios
		static bool creaDirsIni(){
			bool retorno = true;
			try{
				if(!Directory::Exists(directorios["principal"])){
					Directory::CreateDirectory(directorios["principal"]);
				}
				if(!Directory::Exists(directorios["datos"])){
					Directory::CreateDirectory(directorios["datos"]);
				}
				if(!Directory::Exists(directorios["temporal"])){
					Directory::CreateDirectory(directorios["temporal"]);
				}
				if(!Directory::Exists(directorios["log"])){
					Directory::CreateDirectory(directorios["log"]);
				}
			}catch(IOException^ ioex){
				UtilesLog::escribirLog("crearDirsIni", "Error creando directorios->" + ioex->Message);
				retorno = false;
			}
			return retorno;
		}

		/// Retorna la ruta por defecto de la DB
		static String^ defRutDb(){
			initDirs();
			return directorios["rutadb"];
		}

		/// Retorna la ruta del log
		static String^ defRutLog(){
			initDirs();
			return directorios["log"];
		}

		/// Crea directorio
		static bool creaDir(String^ val){
			try{
				Directory::CreateDirectory(val);
			}catch(IOException^ ioex){
				UtilesLog::escribirLog("CreateDirectory", "Error creando directorio [" + val + "]->" + ioex->Message);
				return false;
			}
			return true;
		}

		// Renombrar directorio
		static bool moverDir(String^ origen, String^ destino){
			try{
				Directory::Move(origen,destino);
			}catch(IOException^ ioex){
				UtilesLog::escribirLog("moverDir", "Error moviendo/renombrando [" + origen + "] hacia [" + destino + "]-> " + ioex->Message);
				return false;
			}
			return true;
		}

		// Eliminar directorio
		static bool borrarDir(String^ val){
			try{
				Directory::Delete(val);
			}catch(IOException^ ioex){
				UtilesLog::escribirLog("Delete", "Error eliminando [" + val + "] -> " + ioex->Message);
				return false;
			}
			return true;
		}

		/// Mover/Renombrar archivo
		static bool moverArch(String^ origen, String^ destino){
			try{
				File::Move(origen,destino);
			}catch(IOException^ ioex){
				UtilesLog::escribirLog("Move", "Error moviendo/renombrando [" + origen + "] hacia [" + destino + "]-> " + ioex->Message);
				return false;
			}
			return true;
		}

		/// Borrar archivo
		static bool borrarArch(String^ val){
			try{
				File::Delete(val);
			}catch(IOException^ ioex){
				UtilesLog::escribirLog("Delete", "Error eliminando [" + val + "] -> " + ioex->Message);
				return false;
			}
			return true;
		}

		// Funcion para abrir un archivo
		static void abrirArch(String^ val){
			try{
				Process^ proc = gcnew Process();
				proc->StartInfo->FileName = val;
				proc->StartInfo->UseShellExecute = true;
				proc->Start();
			}catch(Exception^ ex){
				UtilesLog::escribirLog("abrirArch", "Error al intentar abrir [" + val + "] -> " + ex->Message);
				return;
			}
		}

	};
}
