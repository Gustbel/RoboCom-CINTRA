#ifndef _IMU_H_
#define _IMU_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void init_IMU(void);
char* get_acelerometro(int);
char* get_velocidad(int);
char* get_magnetometro(int);

#endif
