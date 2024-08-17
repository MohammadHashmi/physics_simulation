#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void viewport_size_changer(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

int main(int, char**){
    // Initialize glfw
    glfwInit();

    // Instantiate the window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Window", NULL, NULL);

    // Handle errors with GLFW
    if (window == NULL)
    {
        printf("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }

    // Make the window the current context
    glfwMakeContextCurrent(window);

    // Makes sure GLAD is initialized
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
        printf("Failed to initialize GLAD");
        return -1;
    }

    // Creates the rendering area using viewport
    // Changes values based on the window size

    glfwSetFramebufferSizeCallback(window, viewport_size_changer);

    // Render loop to have the window running
    while(!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();    
    } 

    glfwTerminate();
    return 0;  
}