#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>

class HelloTriangleApplication {

	const uint32_t WIDTH = 500;
	const uint32_t HEIGHT = 500;

public:

	void run() {
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}

private:

	GLFWwindow* window;

	void initWindow() {

		// Initilizes glfw (Graphics Library Framework)
		glfwInit();

		// Tells glfw to disable the OpenGL API & to make the window non-resizable
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		// Creates the actual window
		window = glfwCreateWindow(WIDTH, HEIGHT, "Hello, Vulkan!", nullptr, nullptr);

	}

	void initVulkan() {



	}

	void mainLoop() {

		// Ensures that the window wont close until the [X] button is pressed.
		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}

	}

	void cleanup() {

		// Cleans up glfw
		glfwDestroyWindow(window);
		glfwTerminate();

	}

};

int main() {

	HelloTriangleApplication app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	EXIT_SUCCESS;

}