/* app.h */
#include "bsp.h" /* direct coupling, for now */

vois app_init(app_t *app){

	(void) app;
}

typedef struct {
uint32_t last_tick;
bool led1_on, led2_on, led3_on;
} app_t;
void app_init(app_t *app);
void app_process(app_t *app);
