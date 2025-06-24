#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

static void event_handler_cb_main_valu_sensrgb(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            set_var_tesla_value(value);
        }
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // LIVE_SCANE_UI
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.live_scane_ui = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // valeu_SENS_SCALE
                    lv_obj_t *obj = lv_scale_create(parent_obj);
                    objects.valeu_sens_scale = obj;
                    lv_obj_set_pos(obj, 79, 45);
                    lv_obj_set_size(obj, 120, 120);
                    lv_scale_set_mode(obj, LV_SCALE_MODE_ROUND_OUTER);
                    lv_scale_set_range(obj, -100, 100);
                    lv_scale_set_total_tick_count(obj, 101);
                    lv_scale_set_major_tick_every(obj, 5);
                    lv_scale_set_label_show(obj, true);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_length(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff2a00ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(0xffe2cccc), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_letter_space(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_length(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xff69c812), LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_rounded(obj, false, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_width(obj, 2, LV_PART_ITEMS | LV_STATE_DEFAULT);
                }
                {
                    // NADEEL
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.nadeel = obj;
                    lv_obj_set_pos(obj, 129, 45);
                    lv_obj_set_size(obj, 20, 70);
                    lv_image_set_src(obj, &img_n);
                    lv_image_set_pivot(obj, 12, 69);
                    lv_image_set_rotation(obj, -1);
                }
            }
        }
        {
            // VALU_SENSRGB
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.valu_sensrgb = obj;
            lv_obj_set_pos(obj, 94, 60);
            lv_obj_set_size(obj, 120, 120);
            lv_arc_set_range(obj, -100, 100);
            lv_arc_set_mode(obj, LV_ARC_MODE_SYMMETRICAL);
            lv_obj_add_event_cb(obj, event_handler_cb_main_valu_sensrgb, LV_EVENT_ALL, 0);
            lv_obj_set_style_arc_width(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, false, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xff020505), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_image_src(obj, &img_rgb, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            // VALEU_SENS_ut
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.valeu_sens_ut = obj;
            lv_obj_set_pos(obj, 116, 138);
            lv_obj_set_size(obj, 80, 26);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_FLOATING);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // back
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.back = obj;
            lv_obj_set_pos(obj, 257, 211);
            lv_obj_set_size(obj, 47, 17);
            lv_obj_add_event_cb(obj, action_lvgl, LV_EVENT_CLICKED, (void *)1);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff202020), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffd8d8d8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "BACK");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 1, 1);
            lv_obj_set_size(obj, 318, 23);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff202020), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // bluetooth
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.bluetooth = obj;
            lv_obj_set_pos(obj, 280, 6);
            lv_obj_set_size(obj, 24, 13);
            lv_led_set_color(obj, lv_color_hex(0xff000000));
            lv_obj_set_style_bg_image_src(obj, &img_bt, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 13, 1);
            lv_obj_set_size(obj, 37, 20);
            lv_image_set_src(obj, &img_battry);
            lv_image_set_scale(obj, 13);
        }
        {
            // battry valu
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.battry_valu = obj;
            lv_obj_set_pos(obj, 50, 5);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 149, 165);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffcaff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "uT");
        }
        {
            // pitch_valeu
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.pitch_valeu = obj;
            lv_obj_set_pos(obj, 10, 28);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff08ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // pitch_valeu_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.pitch_valeu_1 = obj;
            lv_obj_set_pos(obj, 221, 28);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff08ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // pitch_valeu_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.pitch_valeu_2 = obj;
            lv_obj_set_pos(obj, 124, 211);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff08ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
    {
        bool new_val = get_var_tesla_value();
        bool cur_val = lv_obj_has_flag(objects.valeu_sens_scale, LV_OBJ_FLAG_CLICKABLE);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.valeu_sens_scale;
            if (new_val) lv_obj_add_flag(objects.valeu_sens_scale, LV_OBJ_FLAG_CLICKABLE);
            else lv_obj_clear_flag(objects.valeu_sens_scale, LV_OBJ_FLAG_CLICKABLE);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_tesla_value();
        int32_t cur_val = lv_arc_get_value(objects.valu_sensrgb);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.valu_sensrgb;
            lv_arc_set_value(objects.valu_sensrgb, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_tesla_value();
        const char *cur_val = lv_label_get_text(objects.valeu_sens_ut);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.valeu_sens_ut;
            lv_label_set_text(objects.valeu_sens_ut, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = get_var_bluetooth_connected();
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.bluetooth);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.bluetooth;
            lv_led_set_brightness(objects.bluetooth, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_battery_level();
        const char *cur_val = lv_label_get_text(objects.battry_valu);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.battry_valu;
            lv_label_set_text(objects.battry_valu, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_pitch_angle();
        const char *cur_val = lv_label_get_text(objects.pitch_valeu);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.pitch_valeu;
            lv_label_set_text(objects.pitch_valeu, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_roll_angle();
        const char *cur_val = lv_label_get_text(objects.pitch_valeu_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.pitch_valeu_1;
            lv_label_set_text(objects.pitch_valeu_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = get_var_yaw_angle();
        const char *cur_val = lv_label_get_text(objects.pitch_valeu_2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.pitch_valeu_2;
            lv_label_set_text(objects.pitch_valeu_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}
