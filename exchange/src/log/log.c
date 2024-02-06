#define _CRT_SECURE_NO_WARNINGS

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include "log.h"

static FILE *ech_log_get_level_file(enum ech_log_level level) {
  switch (level) {
  case ECH_LOG_LEVEL_INFO:
    return stdout;
  case ECH_LOG_LEVEL_WARN:
    return stdout;
  case ECH_LOG_LEVEL_ERR:
    return stderr;
  case ECH_LOG_LEVEL_DEBUG:
    return stdout;
  }
  return NULL;
}

static char *ech_log_get_level_col(enum ech_log_level level) {
  switch (level) {
  case ECH_LOG_LEVEL_INFO:
    return "";
  case ECH_LOG_LEVEL_WARN:
    return "\x1b[33m";
  case ECH_LOG_LEVEL_ERR:
    return "\x1b[31m";
  case ECH_LOG_LEVEL_DEBUG:
    return "\x1b[36m";
  }
  return NULL;
}

#ifdef _DEBUG
void ech_log(enum ech_log_level level, const char *file, int ln,
             const char *fmt, ...) {
  char timebuf[16], *col;
  time_t now;
  FILE *f;
  va_list va;

  assert(file != NULL && fmt != NULL);
  now = time(NULL);
  (void)memset(timebuf, 0, sizeof timebuf);
  (void)strftime(timebuf, sizeof timebuf, "%H:%M:%S", localtime(&now));
  f = ech_log_get_level_file(level);
  col = ech_log_get_level_col(level);
  (void)fprintf(f, "%s[exchange] %s %s:%d: ", col, timebuf, file, ln);
  va_start(va, fmt);
  (void)vfprintf(f, fmt, va);
  (void)fprintf(f, "\x1b[0m");
  va_end(va);
}

#else
void ech_log(enum ech_log_level level, const char *fmt, ...) {
  char timebuf[16], *col;
  time_t now;
  FILE *f;
  va_list va;

  now = time(NULL);
  (void)memset(timebuf, 0, sizeof timebuf);
  (void)strftime(timebuf, sizeof timebuf, "%H:%M:%S", localtime(&now));
  f = ech_log_get_level_file(level);
  col = ech_log_get_level_col(level);
  (void)fprintf(f, "%s[exchange] %s: ", col, timebuf);
  va_start(va, fmt);
  (void)vfprintf(f, fmt, va);
  (void)fprintf(f, "\x1b[0m");
  va_end(va);
}
#endif