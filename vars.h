#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations



// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_TESLA_VALUE = 0,
    FLOW_GLOBAL_VARIABLE_PITCH_ANGLE = 1,
    FLOW_GLOBAL_VARIABLE_ROLL_ANGLE = 2,
    FLOW_GLOBAL_VARIABLE_YAW_ANGLE = 3,
    FLOW_GLOBAL_VARIABLE_BATTERY_LEVEL = 4,
    FLOW_GLOBAL_VARIABLE_BLUETOOTH_CONNECTED = 5
};

// Native global variables

extern float get_var_tesla_value();
extern void set_var_tesla_value(float value);
extern float get_var_pitch_angle();
extern void set_var_pitch_angle(float value);
extern float get_var_roll_angle();
extern void set_var_roll_angle(float value);
extern float get_var_yaw_angle();
extern void set_var_yaw_angle(float value);
extern int32_t get_var_battery_level();
extern void set_var_battery_level(int32_t value);
extern bool get_var_bluetooth_connected();
extern void set_var_bluetooth_connected(bool value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/