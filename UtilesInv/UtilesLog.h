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
		static TextWriterTraceListener^ log;
	public:

		
		static UtilesLog(void);
		~UtilesLog(void);

		///
		/// Funciones que escriben algo
		/// 1
		static void escribirLog(String^ valor);

		/// 2
		static void escribirLog(String^ proceso, String^ valor);
	};

}
