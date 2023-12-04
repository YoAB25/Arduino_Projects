#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#include <Arduino_FreeRTOS.h>
#include <timers.h>
#include <event_groups.h>
#include <queue.h>
#include <semphr.h>
#include <list.h>

#define TacheADC_TASK_PRIORITY 3
#define TacheADC_TASK_STACK_SIZE 1024

#include "TacheADC.h"




