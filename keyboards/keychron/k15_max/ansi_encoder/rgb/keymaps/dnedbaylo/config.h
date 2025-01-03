#pragma once

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY


#ifdef RGB_MATRIX_ENABLE
    #define ENABLE_RGB_MATRIX_SOLID_COLOR

    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
    #define RGB_MATRIX_DEFAULT_HUE 191
    #define RGB_MATRIX_DEFAULT_SAT 255
    #define RGB_MATRIX_DEFAULT_VAL 255

#endif // RGB_MATRIX_ENABLE
