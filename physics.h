#ifndef PHYSICS_H
#define PHYSICS_H

#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
 #include <windows.h>
#else
 #include <unistd.h>
#endif

#define DELTA_T (1.0/60.0)
#define MAX_D 4095

struct Entity {
 int id; // id
 double mass; // kg
 double s[2]; // position, s[0] == x, s[1] == y
 double v[2]; // velocity
 double a[2]; // acceleration
 double r; // radius
};

struct Entity *create_body(
int id, double mass, double pos[2], double vel[2], double acc[2], double radius
);

void u_sleep(int milliseconds);
void wait_next_frame();
void apply_physics(struct Entity *body); 
char *printf_bodyi(struct Entity *body);

#endif

