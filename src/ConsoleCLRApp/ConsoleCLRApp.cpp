// ConsoleCLRApp.cpp : main project file.

#include "stdafx.h"

using namespace System;

using namespace TestLibrary_Standard;

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");

	IRequest ^request = gcnew Message();

	Console::WriteLine(request->Foo());
	request->DoSomething();
	Console::WriteLine(request->Foo());

    return 0;
}
