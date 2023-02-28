#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "log.h"
#include <pthread.h>
#include "windows.h"

#define LOG_BUFFER_SIZE 1024
static CHAR log_buffer[LOG_BUFFER_SIZE] = { 0 };
static BOOLEAN init = FALSE;
static pthread_mutex_t mutex;

static char *TimeNow(char *TimeString) {
  SYSTEMTIME st;
  GetSystemTime(&st);
  sprintf(TimeString, "%.2d:%.2d:%.2d.%.3d",
    st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
  return TimeString;
}

static void get_mutex(void) {
    if (!init) {
        if (pthread_mutex_init(&mutex, NULL) != 0) printf("Can't init l_mutex");
        init = TRUE;
    }
    pthread_mutex_lock(&mutex);
}

static void put_mutex(void) {
    pthread_mutex_unlock(&mutex);
}

void print_hex(char *caption, UINT8 *m, int length) {
    get_mutex();
    char timeString[14];
    if (caption != NULL) printf("%s %s [%i]: ", TimeNow(timeString), caption, length);
    if (m == NULL) printf("Massive is empty!\r\n");
    else {
        for (int i = 0; i < length; i++) {
            printf("%2.2X ", m[i]);
        }
    }
    printf("\r\n");
    put_mutex();
}

void print_bool(char *msg, BOOLEAN value) {
    get_mutex();
    printf("%s: %s\r\n", msg, value == TRUE ? "true" : "false");
    put_mutex();
}

INT32 log_formatted(char type, const CHAR *fmt, ... ) {
    get_mutex();
    va_list arg;
    INT32   offset = 0;
    memset(log_buffer, 0, LOG_BUFFER_SIZE);
    int size;
    va_start(arg, fmt);
    size = vsnprintf(log_buffer + offset, LOG_BUFFER_SIZE - offset, fmt, arg);
    va_end(arg);
    size++;
    char timeString[14];
    printf("%s %c: %s\r\n", TimeNow(timeString), type, log_buffer);
    put_mutex();
    return size;
}
