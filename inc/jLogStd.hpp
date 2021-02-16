#ifndef INCLUDE_JLOGSTD_HPP
#define INCLUDE_JLOGSTD_HPP

#include <jLog.hpp>

namespace jCPP
{
    class jLogStd : public jLog
    {
        public:
            jLogStd();
            ~jLogStd();

            void log(logType_t log_type, const char *msg);
            void log_sc(logType_t log_type, const char *file, const char *function, const int line, const char *msg);
    };
}

#endif /* INCLUDE_JLOGSTD_HPP */