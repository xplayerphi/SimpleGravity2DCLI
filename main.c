/* #include <GL/glew.h>
#include <GLFW/glfw3.h> */ 
// will be used in the future

#include "./physics.h"

int main(int argc, char *argv[]){

printf("test FPS...");
system("clear"); // "cls" for windows

for(int k=0; k < 300; k++){
 wait_next_frame();
 printf("time rendered: %d\n", k+1);
 system("clear");
};
scanf("clear: ");
system("clear");
 
return 0;
}

