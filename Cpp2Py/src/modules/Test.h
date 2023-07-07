#pragma once

#include <Python.h>
#include <pybind11/embed.h>
#include <iostream>

#define DEBUG(x) std::cout << (x) << "\n"
#define DEBUG_C(x) std::cout << x << "\n"

class Test
{
public:

	int x;
	int y;

	Test();
	Test(int x, int y);

public:

	static void Print() {
		DEBUG("From C++");
	}

	void Info() {
		DEBUG_C(x << " " << y);
	}
};



PYBIND11_MODULE(TestModule, mod) {
	mod.doc() = "test module for Cpp -> Python embedding";

	mod.def("info", []{ DEBUG("TestModule v0.0.1"); });

	pybind11::class_<Test>(mod, "Test")
		.def(pybind11::init<>())
		.def(pybind11::init<int, int>(), "con 2", pybind11::arg("x"), pybind11::arg("y"))
		.def_readwrite("x", &Test::x)
		.def_readwrite("y", &Test::y)
		.def("print", &Test::Print)
		.def("info", &Test::Info)
		.def("debug", [] { DEBUG("Test"); });
}

