/*
 * LoggerManager.h
 *
 *  Created on: Jul 20, 2011
 *      Author: caioviel
 */

#ifndef LOGGERMANAGER_H_
#define LOGGERMANAGER_H_

#include <string>
#include <set>

#include "Logger.h"
#include "LoggerDefault.h"
#include "LoggerLogFile.h"
#include "LoggerNetworkStream.h"
#include "LoggerColor.h"

namespace cpputil {
namespace logger {

typedef int LOGGER_STYLE;

/**
 * This class manages the log options and decides which concrete logger will be used.
 */
class LoggerManager {
public:
	/**
	 * Enumeration that holds the possibles concrete loggers.
	 * - DEFAULT: LoggerDefault
	 * - LOGFILE: LoggerLogFile
	 * - NETWORKSTREAM: LoggerNetworkStream
	 * - MULTILOGGER: Allows diferent concrete loggers at the same time (Not implemented yet.)
	 * - COLOR: LoggerColor
	 */
	enum LoggerStyle {
		DEFAULT,
		LOGFILE,
		NETWORKSTREAM,
		MULTILOGGER,
		COLOR};

	/**
	 * Enumeration that holds regional options for the logger.
	 * Default is USA.
	 * - USA
	 * - BRAZIL
	 */
    enum RegionalOpt{
    	USA,
    	BRAZIL};

public:
    /**
     * Destructor
     */
    virtual ~LoggerManager();

    /**
     * This methods returns a pointer to the singleton of the LoggerManager.
     * @return A pointer to the LoggerManager unique instance.
     */
    static LoggerManager *getInstance();

    /**
     * Read the log configuration from a xml file.
     * @param filePath The name of the configuration file to be read.
     */
    void readConfigurationFile(std::string filePath);

    /**
     * Add classes to blocked-class list.
     * Classes in this list will not be able to post logger messages with LoggerLvl
     * lower than ERROR.
     * @param completeClassName Name of the class to be added.
     */
    void addBlockedClassList(std::string completeClassName);

    /**
     * Remove classes for the blocked-class list.
     * @param completeClassName The name of the class to be removed.
     * @return true, if the class was removed; false, otherwise.
     */
    bool removeBlockedClassList(std::string completeClassName);

    /**
     * Verifies if a class is in the blocked-class lsit.
     * @param completeClassName The name of the class to be checked.
     * @return true, if the class is the list; false, otherwise.
     */
    bool isBlockedClass(std::string completeClassName);

    /**
     * Returns the RegionalOpt of the logger.
     * @return An item of RegionalOpt enumeration.
     */
    RegionalOpt getRegionalOpt();

    /**
     * This method determines the RegionalOpt of the logger.
     * @param regionalOpt The RegionalOpt to be selected.
     */
    void setRegionalOpt(RegionalOpt regionalOpt);

    /**
     * This method determines the LoggerLvl of the logger.
     * @param loggerLvl The LoggerLvl to be selected.
     */
    void setLoggerLvl(Logger::LoggerLvl loggerLvl);

    /**
     * Returns the Logger::LoggerLvl of the logger.
     * @return An item of Logger::LoggerLvl enumeration.
     */
    Logger::LoggerLvl getLoggerLvl();

    void setLoggerStyle(LoggerStyle loggerStyle);
    LoggerStyle getLoggerStyle();

    std::string getIpAddress();
    std::string getLogfileName();
    unsigned short getPortNumber();
    LoggerNetworkStream::Protocol getProtocol();
    LoggerLogFile::WriteMode getWritemode();

    void setIpAddress(std::string ipAddress);
    void setLogfileName(std::string logfileName);
    void setPortNumber(unsigned short  portNumber);
    void setProtocol(LoggerNetworkStream::Protocol  protocol);
    void setWritemode(LoggerLogFile::WriteMode  writemode);

    void setLevelColor(Logger::LoggerLvl lvl, LoggerColor::Color color);
    LoggerColor::Color getLevelColor(Logger::LoggerLvl lvl);

    static RegionalOpt stringToRegionalOpt(std::string str);
    static std::string regionalOptToString(RegionalOpt regionalOpt);
    static LoggerStyle stringToLoggerStyle(std::string str);
    static std::string loggerStyleToString(LoggerStyle loggerStyle);


private:
    LoggerManager();
	Logger* CreateLoggerInstance();

private:
    static LoggerManager* _instance;
    static Logger* loggerInstance;

    Logger::LoggerLvl loggerLvl;
    std::set<std::string>* blockedClassList;
	LoggerStyle loggerStyle;
	RegionalOpt regionalOpt;

	std::string ipAddress;
	unsigned short	portNumber;
	LoggerNetworkStream::Protocol protocol;

	std::string logfileName;
	LoggerLogFile::WriteMode writemode;

	LoggerColor::Color* colors;

friend class Logger;
};

} /* namespace logger */
} /* namespace cpputil */
#endif /* LOGGERMANAGER_H_ */
