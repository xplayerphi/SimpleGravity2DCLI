#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "./physics.h" 

#ifdef _WIN32
  #include <windows.h>
#else 
  #include <unistd.h>
#endif

void u_sleep(int milliseconds){
 #ifdef _WIN32
        Sleep(milliseconds);
 #else
        usleep(milliseconds * 1000);
 #endif
};

void wait_next_frame() {
 int ms = (int)(DELTA_T * 1000);
 u_sleep(ms);
}

struct Entity *create_body(int id, double mass, double pos[2], double vel[2], double acc[2], double radius) {
 struct Entity *body = malloc(sizeof(struct Entity));
  body->id = id;
  body->mass = mass;
  body->s[0] = pos[0];
  body->s[1] = pos[1];
  body->v[0] = vel[0];
  body->v[1] = vel[1];
  body->a[0] = acc[0];
  body->a[1] = acc[1];
  body->r = radius;
 return body;
}

void apply_physics(struct Entity *body){
 body->v[0] += body->a[0] * DELTA_T;
 body->v[1] += body->a[1] * DELTA_T;

 body->s[0] += body->v[0] * DELTA_T;
 body->s[1] += body->v[1] * DELTA_T;
};

void printf_bodyi(struct Entity *body){ 
 printf(
  "body %d:\n position: (%.2f, %.2f)\n velocity: (%.2f, %.2f)\n acceleration: (%.2f, %.2f)\n",
  body->id,
  body->s[0], body->s[1],
  body->v[0], body->v[1],
  body->a[0], body->a[1]
 );
}
