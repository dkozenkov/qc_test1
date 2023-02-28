#ifndef LOG_H
#define LOG_H

#include "msg_const.h"

void print_hex(char *caption, UINT8 *m, int length);

void print_bool(char *msg, BOOLEAN value);

#define LOG_INFO(a...)      log_formatted('I', a)
#define LOG_ERROR(a...)     log_formatted('E', a)
#define LOG_WARN(a...)      log_formatted('W', a)
#define LOG_DEBUG(a...)     log_formatted('D', a)

INT32 log_formatted(char type, const CHAR *fmt, ... );

#endif
