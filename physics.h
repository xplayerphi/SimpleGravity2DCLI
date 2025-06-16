#ifndef PHYSICS_H
#define PHYSICS_H

#include <time.h>
#include <math.h>
#include <unistd.h> 
#include <stdlib.h>

#define DELTA_T (1.0 / 60.0)
#define SCALE 1000
#define MAX_D 4095
#define MAX_ENTITIES 100

struct Entity {
    double mass; // kg
    double s[2]; // position, s[0] == x, s[1] == y
    double v[2]; // velocity
    double a[2]; // acceleration
    double f[2]; // force
    double r; // radius
};

struct Entity *create_body(double mass, double pos[2], double vel[2], double acc[2], double force[2], double radius);
void check_collisions(); 
void apply_physics(); 
void wait_for_next_frame(); 

#endif

