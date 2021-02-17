#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
	if(!glfwInit()) {
		std::cerr << "Failed to initialise GLFW" << std::endl;
		glfwTerminate();
		return -1;
	}

	// ...

	glfwTerminate();

	return 0;
}
