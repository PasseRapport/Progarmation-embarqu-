/* app.c */

#include "app.h"
void app_process(app_t *app) {
uint32_t tick = bsp_get_tick_ms();
if (tick - app->last_tick >= 250) {
app->last_tick = tick;
app->led1_on = !app->led1_on;
bsp_led_set(0, app->led1_on);
}
/* led2_on/led3_on on bsp_sw1_pressed()/bsp_sw2_pressed(): same shape */
