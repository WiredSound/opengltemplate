#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
	if(glfwInit()) {
		std::cout << "Successfully initialised GLFW" << std::endl;
	}
	else {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	glfwTerminate();

	return 0;
}
