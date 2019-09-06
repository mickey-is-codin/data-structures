#ifndef __CLOG_H__
#define __CLOG_H__

#define RED "\033[0;31m"
#define BRED "\033[1;31m"
#define GREEN "\033[0;32m"
#define BGREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define BYELLOW "\033[01;33m"
#define BLUE "\033[0;34m"
#define BBLUE "\033[1;34m"
#define MAGENTA "\033[0;35m"
#define BMAGENTA "\033[1;35m"
#define CYAN "\033[0;36m"
#define BCYAN "\033[1;36m"
#define RESET "\033[0m"

#define log_red(fmt, ...) printf("%s", RED); printf(fmt, ##__VA_ARGS__); printf("\n%s", RESET);

#endif
