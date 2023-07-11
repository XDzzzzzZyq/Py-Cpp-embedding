// Cpp2Py.cpp: 定义应用程序的入口点。
//

#include "Cpp2Py.h"

#include <Python.h>
#include <pybind11/embed.h>

#include <imgui.h>
#include <imgui_internal.h>

using namespace std;

int main()
{
	cout << "Hello CMake.\n" << endl;

	while (true) {
		bool my_tool_active = true;
		ImGui::Begin("My First Tool", &my_tool_active, ImGuiWindowFlags_MenuBar);
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
				if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
				if (ImGui::MenuItem("Close", "Ctrl+W")) { my_tool_active = false; break; }
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}

		// Edit a color stored as 4 floats
		float my_color[4]{ 0.5, 0.5, 0.5, 0.5 };
		ImGui::ColorEdit4("Color", my_color);

		// Generate samples and plot them
		float samples[100];
		for (int n = 0; n < 100; n++)
			samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 1.5f);
		ImGui::PlotLines("Samples", samples, 100);

		// Display contents in a scrolling region
		ImGui::TextColored(ImVec4(1, 1, 0, 1), "Important Stuff");
		ImGui::BeginChild("Scrolling");
		for (int n = 0; n < 50; n++)
			ImGui::Text("%04d: Some text", n);
		ImGui::EndChild();
		ImGui::End();

	}

#if 0
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
#endif

	std::cin.get();
}
