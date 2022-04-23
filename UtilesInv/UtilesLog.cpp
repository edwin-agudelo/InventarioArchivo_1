#include "StdAfx.h"
#include "UtilesLog.h"

using namespace UtilesInv;

static UtilesLog::UtilesLog(void) {
	String^ nombre = DirArch::defRutLog() + "\\Log_Lib_" + DateTime::Now.ToString("yyyyMMddHHmmss") + ".log";
	log = gcnew TextWriterTraceListener(nombre);
	Trace::Listeners->Remove("Default");
	Trace::Listeners->Add(log);
	Trace::WriteLine("Inicializando...");
	Trace::WriteLine("Fecha/Hora:" + DateTime::Now.ToString("yyyyMMddHHmmss"));
	Trace::Flush();
}

UtilesLog::~UtilesLog() {
	Trace::WriteLine("-------------------------------------------------");
	Trace::WriteLine("Fecha/Hora:" + DateTime::Now.ToString("yyyyMMddHHmmss"));
	Trace::WriteLine("Finalizando");
	Trace::Flush();
}

void UtilesLog::escribirLog(String^ valor) {
	Trace::WriteLine("-------------------------------------------------");
	Trace::WriteLine(DateTime::Now.ToString("yyyyMMddHHmmss") + ":" + valor);
	Trace::Flush();
}

void UtilesLog::escribirLog(String^ proceso, String^ valor) {
	Trace::WriteLine("-------------------------------------------------");
	Trace::WriteLine("[" + proceso + "]" + DateTime::Now.ToString("yyyyMMddHHmmss") + ":" + valor);
	Trace::Flush();
}

