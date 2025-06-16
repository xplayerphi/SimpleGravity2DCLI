#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char *argv[]){
 glfwInit();
 glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
 glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

 GLFWwindow* window = glfwCreateWindow(600, 600, "2D visualizer", NULL, NULL);
 glfwMakeContextCurrent(window);

 glewInit();

 glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

 while (!glfwWindowShouldClose(window)) {
  glClear(GL_COLOR_BUFFER_BIT);
  glfwSwapBuffers(window);
  glfwPollEvents();
 }

 glfwTerminate();
return 0;
}

