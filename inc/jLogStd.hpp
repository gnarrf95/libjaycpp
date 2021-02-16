/**
 * @file jLogStd.hpp
 * @author Manuel Nadji (https://github.com/gnarrf95)
 * 
 * @brief An implementation of jLog, that uses iostream for output.
 * 
 * Logs directly to the terminal output.
 * 
 * @date 2021-02-16
 * @copyright Copyright (c) 2020 by Manuel Nadji
 * 
 */

#ifndef INCLUDE_JLOGSTD_HPP
#define INCLUDE_JLOGSTD_HPP

#include <jLog.hpp>

namespace jCPP
{
    /**
     * @brief Derived class of jLog.
     * 
     */
    class jLogStd : public jLog
    {
        public:

            /**
             * @brief Construct a new jLogStd object.
             * 
             */
            jLogStd();

            /**
             * @brief Destroy the jLogStd object.
             * 
             */
            ~jLogStd();

            /**
             * @brief Log simple message to output.
             * 
             * @param log_type  Type of log message.
             * @param msg       Message to display.
             */
            void log(logType_t log_type, const char *msg);

            /**
             * @brief Log message with source code information to output.
             * 
             * @param log_type  Type of message.
             * @param file      File in which log was called.
             * @param function  Function in which log was called.
             * @param line      Line number on which log was called.
             * @param msg       Message to display.
             */
            void log_sc(logType_t log_type, const char *file, const char *function, const int line, const char *msg);
    };
}

#endif /* INCLUDE_JLOGSTD_HPP */