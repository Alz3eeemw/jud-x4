#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *live_scane_ui;
    lv_obj_t *valeu_sens_scale;
    lv_obj_t *nadeel;
    lv_obj_t *valu_sensrgb;
    lv_obj_t *valeu_sens_ut;
    lv_obj_t *back;
    lv_obj_t *obj0;
    lv_obj_t *bluetooth;
    lv_obj_t *battry_valu;
    lv_obj_t *obj1;
    lv_obj_t *pitch_valeu;
    lv_obj_t *pitch_valeu_1;
    lv_obj_t *pitch_valeu_2;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
};

void create_screen_main();
void tick_screen_main();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/