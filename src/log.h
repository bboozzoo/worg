#ifndef __LOG_H__
#define __LOG_H__
#include <stdint.h>
#include <iostream>

extern uint32_t log_level;
#define LOG(lvl, x) \
    do { \
        if (lvl <= log_level) \
            std::cerr << __FILE__ << ":" << __LINE__ << ": " << x << std::endl; \
    } while (0)

#endif /* __LOG_H__ */
