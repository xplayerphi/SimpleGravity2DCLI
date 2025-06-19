#include "./physics.h"

int main(int argc, char *argv[]){

printf("test FPS...");

for(int k=0; k < DELTA_T*480; k++){
 wait_next_frame();
 printf("time rendered: %d\n", k+1);
};
scanf("clear: ");
system("clear"); // if your OS is windows, use "cls"

// the main game config
 struct Entity *bodies[MAX_BODIES];
 int count = 2;
 double pos1[2] = {0.0, 0.0};
 double vel1[2] = {0.0, 0.0};
 double acc1[2] = {0.0, 0.0};
 bodies[0] = create_body(1, 1000.0, pos1, vel1, acc1, 1.0);

 double pos2[2] = {10.0, 0.0};
 double vel2[2] = {0.0, 5.0};
 double acc2[2] = {0.0, 0.0};
 bodies[1] = create_body(2, 1.0, pos2, vel2, acc2, 0.5);

 for(int step = 0; 1; step++) {
  apply_physics(bodies, count);
  printf("Step %d:\n", step);
  for(int i = 0; i < count; i++) printf_bodyi(bodies[i]);
   wait_next_frame();
 }

  free_bodies(bodies, count);
  return 0;
}
