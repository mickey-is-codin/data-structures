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
#define log_bred(fmt, ...) printf("%s", BRED); printf(fmt, ##__VA_ARGS__); printf("\n%s", RESET);
#define log_green(fmt, ...) printf("%s", GREEN); printf(fmt, ##__VA_ARGS__); printf("\n%s", RESET);
#define log_bgreen(fmt, ...) printf("%s", BGREEN); printf(fmt, ##__VA_ARGS__); printf("\n%s", RESET);
#define log_yell(fmt, ...) printf("%s", YELLOW); printf(fmt, ##__VA_ARGS__); printf("\n%s", RESET);
#define log_byell(fmt, ...) printf("%s", BYELLOW); printf(fmt, ##__VA_ARGS__); printf("\n%s", RESET);
#define log_blue(fmt, ...) printf("%s", BLUE); printf(fmt, ##__VA_ARGS__); printf("\n%s", RESET);
#define log_bblue(fmt, ...) printf("%s", BBLUE); printf(fmt, ##__VA_ARGS__); printf("\n%s", RESET);
#define log_mag(fmt, ...) printf("%s", MAGENTA); printf(fmt, ##__VA_ARGS__); printf("\n%s", RESET);
#define log_bmag(fmt, ...) printf("%s", BMAGENTA); printf(fmt, ##__VA_ARGS__); printf("\n%s", RESET);
#define log_cyan(fmt, ...) printf("%s", CYAN); printf(fmt, ##__VA_ARGS__); printf("\n%s", RESET);
#define log_bcyan(fmt, ...) printf("%s", BCYAN); printf(fmt, ##__VA_ARGS__); printf("\n%s", RESET);


#endif
