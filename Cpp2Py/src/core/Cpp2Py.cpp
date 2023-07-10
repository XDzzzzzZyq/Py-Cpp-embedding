// Cpp2Py.cpp: 定义应用程序的入口点。
//

#include "Cpp2Py.h"

#include <Python.h>
#include <pybind11/embed.h>

using namespace std;

int main()
{
	cout << "Hello CMake.\n" << endl;

#if 1
	pybind11::scoped_interpreter guard{};

	pybind11::print("Hello Python.\n");

	pybind11::exec("import sys, os");
	pybind11::exec("sys.path.append(os.getcwd())");

	pybind11::exec("import TestModule");
	pybind11::exec("TestModule.info()");
	pybind11::exec("test = TestModule.Test(2, 3)");
	pybind11::exec("test.info()");
	pybind11::exec("TestModule.Test.print()");
#else
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		cout << "Failed\n" << endl;
		return 0;
	}

	PyRun_SimpleString("import sys, os");
	PyRun_SimpleString("sys.path.append(os.getcwd())");

	PyRun_SimpleString("import TestModule");
	PyRun_SimpleString("TestModule.info()");
	PyRun_SimpleString("test = TestModule.Test(2, 3)");
	PyRun_SimpleString("test.info()");
	PyRun_SimpleString("TestModule.Test.print()");
#endif

	std::cin.get();
}
