/**
 * @file jLog.hpp
 * @author Manuel Nadji (https://github.com/gnarrf95)
 * 
 * @brief This is a logger system, that can call customized implementations.
 * 
 * Derived logger classes can be used as a global instance with the
 * @c #init_GlobalLogger() , @c #get_GlobalLogger() and
 * @c #destroy_GlobalLogger() functions.
 * 
 * This global instance can then be used with the macros at the
 * end of the file. These macros also automatically insert the
 * source code information.
 * 
 * @date 2021-02-16
 * @copyright Copyright (c) 2020 by Manuel Nadji
 * 
 */

#ifndef INCLUDE_JLOG_HPP
#define INCLUDE_JLOG_HPP

namespace jCPP
{
    /**
     * @brief Abstract logger class with global functions.
     * 
     */
    class jLog
    {
        public:
            /**
             * @brief Reference values for the different types of log messages.
             * 
             */
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
            /**
             * @brief Destroy the jLog object.
             * 
             * Needs to be there for the global functions to work properly.
             * 
             */
            virtual ~jLog();

            /**
             * @brief Simple log message.
             * 
             * @param log_type  Type of message.
             * @param msg       Message to be displayed.
             */
            virtual void log(logType_t log_type, const char *msg) = 0;

            /**
             * @brief Log message with source code information.
             * 
             * @param log_type  Type of message.
             * @param file      File in which log was called.
             * @param function  Function in which log was called.
             * @param line      Line number on which log was called.
             * @param msg       Message to be displayed.
             */
            virtual void log_sc(logType_t log_type, const char *file, const char *function, const int line, const char *msg) = 0;

        private:
            /**
             * @brief Global instance of derived logger.
             * 
             */
            static jLog *global_instance;

        public:
            /**
             * @brief Initialize global instance with derived class.
             * 
             * @param logger_instance   Instance to use.
             * 
             * @return                  Instance that is used.
             */
            static jLog *init_GlobalLogger(jLog *logger_instance);

            /**
             * @brief Get the GlobalLogger object.
             * 
             * @return                  Instance in global variable.
             * @return                  @c NULL if no instance available.
             */
            static jLog *get_GlobalLogger();

            /**
             * @brief Deletes current global instance.
             * 
             */
            static void destroy_GlobalLogger();

            /**
             * @brief Simple log with global instance.
             * 
             * @see #log()
             */
            static void log_Global(logType_t log_type, const char *fmt, ...);

            /**
             * @brief Complex log with global instance.
             * 
             * @see #log_sc()
             */
            static void log_Global_sc(logType_t log_type, const char *file, const char *function, const int line, const char *fmt, ...);
    };
}

/**
 * @brief Special log macros that use the global instance.
 * 
 * These should be used directly in the code.
 * These automatically fill in the source code information.
 * 
 */
#define JLOG_DEBUG(fmt, ...) jLog::log_Global_sc(jLog::logType_t::DEBUG, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define JLOG_INFO(fmt, ...) jLog::log_Global_sc(jLog::logType_t::INFO, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define JLOG_WARN(fmt, ...) jLog::log_Global_sc(jLog::logType_t::WARNING, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define JLOG_ERROR(fmt, ...) jLog::log_Global_sc(jLog::logType_t::ERROR, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define JLOG_CRIT(fmt, ...) jLog::log_Global_sc(jLog::logType_t::CRITICAL, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define JLOG_FATAL(fmt, ...) jLog::log_Global_sc(jLog::logType_t::FATAL, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)

#endif /* INCLUDE_JLOG_HPP */