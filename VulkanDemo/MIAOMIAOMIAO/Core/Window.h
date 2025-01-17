#pragma once

#include "Vulkan.h"

#include <functional>
#include <vector>

namespace Rendering
{
	class Window
	{
	public:
		NON_COPIABLE(Window);

		explicit Window(int width, int height, const char* title);
		~Window();

		void Run();
		void AddOnKeyChanged(std::function<void(int key, int scancode, int action, int mods)> callback);
		void AddOnCursorPositionChanged(std::function<void(double xpos, double ypos)> callback);
		void AddOnMouseButtonChanged(std::function<void(int button, int action, int mods)> callback);
		void AddOnScrollChanged(std::function<void(double xoffset, double yoffset)> callback);

		GLFWwindow* Get() const
		{
			return window;
		}

		VkExtent2D GetFramebufferSize() const;

	private:
		static void GlfwErrorCallback(int error, const char* description);
		static void GlfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void GlfwCursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
		static void GlfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void GlfwScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

		std::vector<std::function<void(int key, int scancode, int action, int mods)>> onKeyChanged;
		std::vector<std::function<void(double xpos, double ypos)>> onCursorPositionChanged;
		std::vector<std::function<void(int button, int action, int mods)>> onMouseButtonChanged;
		std::vector<std::function<void(double xoffset, double yoffset)>> onScrollChanged;

		GLFWwindow* window{};
	};
}