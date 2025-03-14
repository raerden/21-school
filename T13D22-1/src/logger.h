#ifndef LOGGER_H_
#define LOGGER_H_
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "log_levels.h"

FILE *log_init(char *filename);
void logcat(FILE *log_file, enum log_level level, char *message);
void log_close(FILE *log_file);

#endif