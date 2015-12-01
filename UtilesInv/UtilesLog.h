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
using namespace System::Diagnostics;

namespace UtilesInv {

	public ref class UtilesLog
	{
	private:
		TextWriterTraceListener^ log;
	public:
		UtilesLog(void){
			String^ nombre = DirArch::defRutLog() + "\\Log_Lib_" + DateTime::Now.ToString("yyyyMMddHHmmss") + ".log";
			log = gcnew TextWriterTraceListener(nombre);
			//Debug::Listeners->Remove("Default");
			Trace::Listeners->Remove("Default");
			Trace::Listeners->Add(log);
			Trace::WriteLine("Inicializando...");
			Trace::WriteLine("Fecha/Hora:" + DateTime::Now.ToString("yyyyMMddHHmmss"));
			Trace::Flush();
		}

		~UtilesLog(void){
			Trace::WriteLine("-------------------------------------------------");
			Trace::WriteLine("Fecha/Hora:" + DateTime::Now.ToString("yyyyMMddHHmmss"));
			Trace::WriteLine("Finalizando");
			Trace::Flush();
		}

		///
		/// Funciones que escriben algo
		/// 1
		void escribirLog(String^ valor){
			Trace::WriteLine("-------------------------------------------------");
			Trace::WriteLine(DateTime::Now.ToString("yyyyMMddHHmmss") + ":" + valor);
			Trace::Flush();
		}

		/// 2
		void escribirLog(String^ proceso, String^ valor){
			Trace::WriteLine("-------------------------------------------------");
			Trace::WriteLine("[" + proceso + "]" + DateTime::Now.ToString("yyyyMMddHHmmss") + ":" + valor);
			Trace::Flush();
		}
	};

}
