#ifndef ECH_LOG_H
#define ECH_LOG_H

#include <string.h>

enum ech_log_level {
  ECH_LOG_LEVEL_INFO,
  ECH_LOG_LEVEL_WARN,
  ECH_LOG_LEVEL_ERR,
  ECH_LOG_LEVEL_DEBUG
};

#ifdef _DEBUG
#define __FILENAME__                                                           \
  (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define ECH_LOG_INFO(...)                                                      \
  ech_log(ECH_LOG_LEVEL_INFO, __FILENAME__, __LINE__, __VA_ARGS__)

#define ECH_LOG_WARN(...)                                                      \
  ech_log(ECH_LOG_LEVEL_WARN, __FILENAME__, __LINE__, __VA_ARGS__)

#define ECH_LOG_ERR(...)                                                       \
  ech_log(ECH_LOG_LEVEL_ERR, __FILENAME__, __LINE__, __VA_ARGS__)

#define ECH_LOG_DEBUG(...)                                                     \
  ech_log(ECH_LOG_LEVEL_DEBUG, __FILENAME__, __LINE__, __VA_ARGS__)

void ech_log(enum ech_log_level level, const char *file, int ln,
             const char *fmt, ...);

#else
#define ECH_LOG_INFO(...) ech_log(ECH_LOG_LEVEL_INFO, __VA_ARGS__)

#define ECH_LOG_WARN(...) ech_log(ECH_LOG_LEVEL_WARN, __VA_ARGS__)

#define ECH_LOG_ERR(...) ech_log(ECH_LOG_LEVEL_ERR, __VA_ARGS__)

#define ECH_LOG_DEBUG(...)

void ech_log(enum ech_log_level level, const char *fmt, ...);

#endif

#endif