
#pragma once



#define MAX_BUBBLES_COUNT_PER_AREA (9.0 / (640.0 * 480.0))
#define ABSOLUTE_BUBBLES_LIMIT 25

#define BUBBLES_CREATION_TIMEOUT 0.1f

#define MIN_RADIUS 12
#define MAX_RADIUS 65

#define MIN_CLR_VAL 0x20
#define MAX_CLR_VAL 0xFF

#define VELOCITY_PER_1_DIV_RAD_2_KOEFF 300000
#define POINTS_PER_VELOCITY 0.1



#define min(x, y) (x < y ? x : y)  
#define max(x, y) (x > y ? x : y)