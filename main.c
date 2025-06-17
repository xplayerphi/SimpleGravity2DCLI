/* #include <GL/glew.h>
#include <GLFW/glfw3.h> */ 
// will be used in the future

#include "./physics.h"

int main(int argc, char *argv[]){

printf("test FPS...");

for(int k=0; k < 300; k++){
 wait_next_frame();
 printf("time rendered: %d\n", k+1);
 system("clear");
};
scanf("clear: ");
system("clear"); // if your OS is windows, use "cls"

// the main game config:

double pos[2] = {0.0, 1.0};
double vel[2] = {0.5, 1.1};
double acc[2] = {0.0, -0.1};
double radius = 1.0; 

struct Entity *body1 = create_body(1, 1.0, pos, vel, acc, radius);

clock_t start = clock();
int k = 0;  
char *enter_res = "h";
double time = 0.0;

while(1){
double seconds = (double)(clock() - start)/CLOCKS_PER_SEC;
printf(" %d. The simulation: time: %.2f s \n\n", k+1, time + DELTA_T);
apply_physics(body1);
time = time + DELTA_T;
printf_bodyi(body1);

// only for fun:
if(body1->s[1] <= 0){
break;
system("clear");
printf("\n the ball stopped in: %d,%d \n", body1->s[0], body1->s[1]);
};

wait_next_frame();

system("clear");
k++;
};
 
clock_t end = clock();
return 0;
}
