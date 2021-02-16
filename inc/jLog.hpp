#ifndef INCLUDE_JLOG_HPP
#define INCLUDE_JLOG_HPP

namespace jCPP
{
    class jLog
    {
        public:
            typedef enum
            {
                DEBUG,
                INFO,
                WARNING,
                ERROR,
                CRITICAL,
                FATAL
            } logType_t;

        public:
            virtual ~jLog();

            virtual void log(logType_t log_type, const char *msg) = 0;
            virtual void log_sc(logType_t log_type, const char *file, const char *function, const int line, const char *msg) = 0;

        private:
            static jLog *global_instance;

        public:
            static jLog *init_GlobalLogger(jLog *logger_instance);
            static jLog *get_GlobalLogger();
            static void destroy_GlobalLogger();

            static void log_Global(logType_t log_type, const char *fmt, ...);
            static void log_Global_sc(logType_t log_type, const char *file, const char *function, const int line, const char *fmt, ...);
    };
}

#define JLOG_DEBUG(fmt, ...) jLog::log_Global_sc(jLog::logType_t::DEBUG, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define JLOG_INFO(fmt, ...) jLog::log_Global_sc(jLog::logType_t::INFO, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define JLOG_WARN(fmt, ...) jLog::log_Global_sc(jLog::logType_t::WARNING, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define JLOG_ERROR(fmt, ...) jLog::log_Global_sc(jLog::logType_t::ERROR, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define JLOG_CRIT(fmt, ...) jLog::log_Global_sc(jLog::logType_t::CRITICAL, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define JLOG_FATAL(fmt, ...) jLog::log_Global_sc(jLog::logType_t::FATAL, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)

#endif /* INCLUDE_JLOG_HPP */