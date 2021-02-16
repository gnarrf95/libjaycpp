#include <jLog.hpp>

#include <cstdio>
#include <cstring>
#include <cstdarg>

namespace jCPP
{
    jLog *jLog::global_instance = nullptr;

    jLog::~jLog()
    {
    }

    jLog *jLog::init_GlobalLogger(jLog *logger_instance)
    {
        if(jLog::global_instance)
        {
            delete jLog::global_instance;
        }

        jLog::global_instance = logger_instance;
        return logger_instance;
    }

    jLog *jLog::get_GlobalLogger()
    {
        return jLog::global_instance;
    }

    void jLog::destroy_GlobalLogger()
    {
        if(jLog::global_instance)
        {
            delete jLog::global_instance;
            jLog::global_instance = nullptr;
        }
    }

    void jLog::log_Global(logType_t log_type, const char *fmt, ...)
    {
        if(jLog::global_instance == nullptr)
        {
            return;
        }

        va_list args;
        char buffer[2048];

        va_start(args, fmt);
        vsnprintf(buffer, sizeof(buffer), fmt, args);
        va_end(args);

        jLog::global_instance->log(log_type, buffer);
    }

    void jLog::log_Global_sc(logType_t log_type, const char *file, const char *function, const int line, const char *fmt, ...)
    {
        if(jLog::global_instance == nullptr)
        {
            return;
        }

        va_list args;
        char buffer[2048];

        va_start(args, fmt);
        vsnprintf(buffer, sizeof(buffer), fmt, args);
        va_end(args);

        jLog::global_instance->log_sc(log_type, file, function, line, buffer);
    }
}