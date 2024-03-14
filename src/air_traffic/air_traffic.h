#ifndef AIR_TRAFFIC_H
#define AIR_TRAFFIC_H

#include <stdio.h>
#include <stdlib.h>

#define SAFELY_HEIGHT 300

void air_traffic();

int input_value();

int check_traffic(int low, int high, int aircrafts);

void output(int mode);

#endif