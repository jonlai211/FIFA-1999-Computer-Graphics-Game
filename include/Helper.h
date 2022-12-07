//
// Created by jonathan on 12/7/22.
//

#ifndef CPT205_HELPER_H
#define CPT205_HELPER_H

#include <cstring>

#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif // !M_PI


#define _FILE strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__
#define PRINTFUNCTION(format, ...)      fprintf(stderr, format, __VA_ARGS__)

#define LOG_FMT             "[%-5s] %s:%03d | "
#define LOG_ARGS(LOG_TAG)   LOG_TAG, _FILE, __LINE__

#define NEWLINE     "\n"
#define ERROR_TAG   "ERROR"
#define INFO_TAG    "INFO"
#define DEBUG_TAG   "DEBUG"

#ifdef _WIN32
#define LOGD(message, ...)     PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(DEBUG_TAG), __VA_ARGS__)
#define LOGI(message, ...)     PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(INFO_TAG), __VA_ARGS__)
#define LOGE(message, ...)     PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(ERROR_TAG), __VA_ARGS__)
#else
#define LOGD(message, args...)     PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(DEBUG_TAG), ## args)
#define LOGI(message, args...)     PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(INFO_TAG), ## args)
#define LOGE(message, args...)     PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(ERROR_TAG), ## args)
#endif

// Constants and Initial Values
#define INIT_WINDOW_WIDTH   1280
#define INIT_WINDOW_HEIGHT  720
#define INIT_WINDOW_X       ((glutGet(GLUT_SCREEN_WIDTH) >> 1) - (INIT_WINDOW_WIDTH >> 1))
#define INIT_WINDOW_Y       ((glutGet(GLUT_SCREEN_HEIGHT) >> 1)  - (INIT_WINDOW_WIDTH >> 1))
#define WINDOW_TITLE        "FIFA-1999"

// Handy operations
#define toRGB(a) (a / 255.0)

enum LightingMode {
    DAY_MODE,
    NIGHT_MODE
};

#endif //CPT205_HELPER_H
