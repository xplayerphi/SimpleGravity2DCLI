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

