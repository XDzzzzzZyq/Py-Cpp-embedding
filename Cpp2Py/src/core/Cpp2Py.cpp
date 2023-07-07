// Cpp2Py.cpp: 定义应用程序的入口点。
//

#include "Cpp2Py.h"

#include <Python.h>
#include <pybind11/embed.h>

using namespace std;

int main()
{
	cout << "Hello CMake.\n" << endl;


	pybind11::scoped_interpreter guard{};

	pybind11::module_ sys = pybind11::module_::import("sys");
	
	pybind11::exec("import sys, os");
	pybind11::exec("sys.path.append(os.getcwd())");
	
	pybind11::exec("import TestModule");
	pybind11::exec("TestModule.info()");
	pybind11::exec("test = TestModule.Test(2, 3)");
	pybind11::exec("test.info()");
	pybind11::exec("test.print()");

	std::cin.get();
}
