#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

using namespace std;

int g_WindowsSizeX = 640;
int g_WindowsSizeY = 480;

void glfwWindowSizeCallback(GLFWwindow* pwindow, int width, int height) {
    g_WindowsSizeX = width;
    g_WindowsSizeY = height;
    glViewport(0, 0, g_WindowsSizeX, g_WindowsSizeY);
}

void glfwKeyCallBack(GLFWwindow* pwindow, int key, int scanecode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pwindow, GL_TRUE);
    }
}




int main(void)

{
    GLFWwindow* pwindow;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    pwindow = glfwCreateWindow(g_WindowsSizeX, g_WindowsSizeY, "Battle-city", nullptr, nullptr);
    if (!pwindow)
    {
        cout << "Create Wrong" << endl;
        glfwTerminate();
        return -1;
    }
    
    glfwSetWindowSizeCallback(pwindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pwindow, glfwKeyCallBack);

    /* Make the window's context current */
    glfwMakeContextCurrent(pwindow);

    if (!gladLoadGL()) {
        cout << "Can`t Load Glad!" << endl;
        return -1;
    }
    cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
    cout << "OpenGl version: " << glGetString(GL_VERSION) << endl;
    
    glClearColor(0, 1, 0, 1);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pwindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pwindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}