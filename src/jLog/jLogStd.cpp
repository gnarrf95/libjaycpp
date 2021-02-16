/**
 * @file jLog.cpp
 * @author Manuel Nadji (https://github.com/gnarrf95)
 * 
 * @brief Code for functionality of jLogStd.
 * 
 * @date 2021-02-16
 * @copyright Copyright (c) 2020 by Manuel Nadji
 * 
 */

#include <jLogStd.hpp>

#include <iostream>

//----------------------------------------------------------------------------------------------------------------------
//
static const char *LOGSTRING_DEBUG = "=DBG=";
static const char *LOGSTRING_INFO = "=INF=";
static const char *LOGSTRING_WARNING = "=WRN=";
static const char *LOGSTRING_ERROR = "=ERR=";
static const char *LOGSTRING_CRITICAL = "*CRT*";
static const char *LOGSTRING_FATAL = "**FATAL**";

namespace jCPP
{
    //------------------------------------------------------------------------------------------------------------------
    //
    jLogStd::jLogStd()
    {
    }

    //------------------------------------------------------------------------------------------------------------------
    //
    jLogStd::~jLogStd()
    {
    }

    //------------------------------------------------------------------------------------------------------------------
    //
    void jLogStd::log(logType_t log_type, const char *msg)
    {
        std::cout << "[ ";

        switch(log_type)
        {
            case logType_t::DEBUG:
            {
                std::cout << LOGSTRING_DEBUG;
                break;
            }

            case logType_t::INFO:
            {
                std::cout << LOGSTRING_INFO;
                break;
            }

            case logType_t::WARNING:
            {
                std::cout << LOGSTRING_WARNING;
                break;
            }

            case logType_t::ERROR:
            {
                std::cout << LOGSTRING_ERROR;
                break;
            }

            case logType_t::CRITICAL:
            {
                std::cout << LOGSTRING_CRITICAL;
                break;
            }

            case logType_t::FATAL:
            {
                std::cout << LOGSTRING_FATAL;
                break;
            }

            default:
            {
                std::cout << LOGSTRING_DEBUG;
                break;
            }
        }

        std::cout << " ] " << msg << std::endl;
    }

    //------------------------------------------------------------------------------------------------------------------
    //
    void jLogStd::log_sc(logType_t log_type, const char *file, const char *function, const int line, const char *msg)
    {
        std::cout << "[ ";

        switch(log_type)
        {
            case logType_t::DEBUG:
            {
                std::cout << LOGSTRING_DEBUG;
                break;
            }

            case logType_t::INFO:
            {
                std::cout << LOGSTRING_INFO;
                break;
            }

            case logType_t::WARNING:
            {
                std::cout << LOGSTRING_WARNING;
                break;
            }

            case logType_t::ERROR:
            {
                std::cout << LOGSTRING_ERROR;
                break;
            }

            case logType_t::CRITICAL:
            {
                std::cout << LOGSTRING_CRITICAL;
                break;
            }

            case logType_t::FATAL:
            {
                std::cout << LOGSTRING_FATAL;
                break;
            }

            default:
            {
                std::cout << LOGSTRING_DEBUG;
                break;
            }
        }

        std::cout << " " << file << ":" << line << " " << function << "() ] " << msg << std::endl;
    }
}