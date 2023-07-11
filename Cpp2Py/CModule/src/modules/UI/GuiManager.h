#pragma once

#include "support.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

class GuiManager
{
public:

	GuiManager();
	GuiManager(GLuint w, GLuint h);
	~GuiManager();

	GLuint scr_w, scr_h;
	GLFWwindow* window{ nullptr };
	ImGuiIO* io{ nullptr };

public:

	void Init();
	void NewFrame();
	void Render();
	void Terminate();

	void SetConfigFlag(ImGuiConfigFlags_ flag)	 const { io->ConfigFlags  |= flag; };
	void SetBackendFlag(ImGuiBackendFlags_ flag) const { io->BackendFlags |= flag; };

public:

	bool isWindowOpen() {
		return !glfwWindowShouldClose(window);
	}

};