#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void viewport_size_changer(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

int main(int, char**){
    // Vertices of the triangle
    float vertices[] = {
       -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    }; 

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

    // Generates a buffer which we are going to use to render the triangle
    unsigned int buffer;
    glGenBuffers(1, &buffer);

    // Selects the buffer we just made
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    // Buffer data that we are going to use to draw the triangle
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertices, GL_STATIC_DRAW);

    // Render loop to have the window running
    while(!glfwWindowShouldClose(window))
    {
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();    
    } 

    glfwTerminate();
    return 0;  
}