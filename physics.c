#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "./physics.h"
#include "./constants.h"

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

void compute_gravity(struct Entity **bodies, int count) {
 if (count < 2 || count > MAX_BODIES) return;
 for (int i = 0; i < count; i++) {
  bodies[i]->a[0] = 0;
   bodies[i]->a[1] = 0;
   for (int j = 0; j < count; j++) {
    if (i == j) continue;
   double dx = bodies[j]->s[0] - bodies[i]->s[0];
   double dy = bodies[j]->s[1] - bodies[i]->s[1];
   double dist_sq = dx*dx + dy*dy;
   double min_dist = bodies[i]->r + bodies[j]->r;
   double min_dist_sq = min_dist * min_dist;
   if (dist_sq < min_dist_sq) dist_sq = min_dist_sq;
   double dist = sqrt(dist_sq);
   double force = CONST_G * bodies[i]->mass * bodies[j]->mass / dist_sq;
   bodies[i]->a[0] += force * dx / (dist * bodies[i]->mass);
   bodies[i]->a[1] += force * dy / (dist * bodies[i]->mass);
  }
 }
}

void apply_physics(struct Entity **bodies, int count) {
 if (count < 2 || count > MAX_BODIES) return;
 compute_gravity(bodies, count);
 for (int i = 0; i < count; i++) {
  bodies[i]->v[0] += bodies[i]->a[0] * DELTA_T;
  bodies[i]->v[1] += bodies[i]->a[1] * DELTA_T;
  bodies[i]->s[0] += bodies[i]->v[0] * DELTA_T;
  bodies[i]->s[1] += bodies[i]->v[1] * DELTA_T;
 }
}

void printf_bodyi(struct Entity *body){
 printf(
 "body %d:\n position: (%.2f, %.2f)\n velocity: (%.2f, %.2f)\n acceleration: (%.2f, %.2f)\n",
  body->id,
  body->s[0], body->s[1],
  body->v[0], body->v[1],
  body->a[0], body->a[1]
 );
}

void free_body(struct Entity* body) {
 free(body);
}

void free_bodies(struct Entity **bodies, int count) {
 for (int i = 0; i < count; i++) free(bodies[i]);
}
