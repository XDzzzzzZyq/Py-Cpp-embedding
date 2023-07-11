#include <Python.h>
#include <pybind11/embed.h>

#include "Test.h"
#include "UI/GuiManager.h"

PYBIND11_MODULE(TestModule, mod) {
	mod.doc() = "test module for Cpp -> Python embedding";

	mod.def("info", [] { DEBUG("TestModule v0.0.1"); });

	pybind11::class_<Test>(mod, "Test")
		.def(pybind11::init<>())
		.def(pybind11::init<int, int>(), "con 2", pybind11::arg("x"), pybind11::arg("y"))
		.def_readwrite("x", &Test::x)
		.def_readwrite("y", &Test::y)
		.def("print", &Test::Print)
		.def("info", &Test::Info)
		.def("debug", [] { DEBUG("Test"); });


	pybind11::class_<GuiManager>(mod, "UI")
		.def(pybind11::init<>())
		.def(pybind11::init<int, int>(), "con 2", pybind11::arg("w"), pybind11::arg("h"))
		.def_readonly("scr_x", &GuiManager::scr_w)
		.def_readonly("scr_y", &GuiManager::scr_h)
		.def("init", &GuiManager::Init)
		.def("new_frame", &GuiManager::NewFrame)
		.def("render", &GuiManager::Render)
		.def("terminate", &GuiManager::Terminate)
		.def("is_window_open", &GuiManager::isWindowOpen)
		.def("info", []{ DEBUG("ImGui Manager"); });

}
#if 0
#endif