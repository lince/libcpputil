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

    /**
     * This method determines the Logger::LoggerStyle  that will be used by the logger
     * @param loggerStyle The Logger::LoggerStyle to be used.
     */
    void setLoggerStyle(LoggerStyle loggerStyle);

    /**
     * Returns the Logger::LoggerStyle currently used by the logger
     * @return An item of Logger::LoggerStyle enumeration.
     */
    LoggerStyle getLoggerStyle();

    /**
     * Returns the ip address of the logger server for witch the LoggerNetworkStream send log messages.
     * @return A string with the ip address.
     */
    std::string getIpAddress();

    /**
     * Returns the name of the file used by the LoggerLogFile.
     * @return A string with the file name.
     */
    std::string getLogfileName();

    /**
     * Returns the port number of the logger server for witch the LoggerNetworkStream send log messages.
     * @return A integer with the port number.
     */
    unsigned short getPortNumber();

    /**
     * Returns the port network protocol used by the LoggerNetworkStream to communicate with the logger server.
     * @return An item of LoggerNetworkStream::Protocol enumeration.
     */
    LoggerNetworkStream::Protocol getProtocol();

    /**
     * Returns the write mode by which the LoggerLogFile will open the log file.
     * @return An item of LoggerLogFile::WriteMode enumeration.
     */
    LoggerLogFile::WriteMode getWritemode();

    /**
     * This method determines the ip address of the server for which the LoggerNetworkStream will send log messages.
     * @param ipAddress The IPv4 Address of the log server.
     */
    void setIpAddress(std::string ipAddress);

    /**
     * This method determines the port number of the server for which the LoggerNetworkStream will send log messages.
     * @param portNumber The port number of the Logger-Server.
     */
    void setPortNumber(unsigned short  portNumber);

    /**
     * This method determines the Network protocol by which the LoggerNetworkStream will communicate with the log server
     * @param protocol An item of the LoggerNetworkStream::Protocol representing the protocol to be used.
     */
    void setProtocol(LoggerNetworkStream::Protocol  protocol);

    /**
     * This method determines the name of the log file to be opened by the LoggerLogFile.
     * @param logfileName The name of the file to be opened.
     */
    void setLogfileName(std::string logfileName);

    /**
     * This method determines the write mode by which the log file will be opened by the LoggerLogFile.
     * @param writemode An item of the LoggerLogFile::WriteMode representing the write mode to be used.
     */
    void setWritemode(LoggerLogFile::WriteMode  writemode);

    /**
     * This method allow to set the color used by LoggerColor for log messages of one Logger::LoggerLvl.
     * @param lvl The Logger::LoggerLvl which will be setted the color.
     * @param color In item of Logger::Color enumeration representing the color which will be setted.
     */
    void setLevelColor(Logger::LoggerLvl lvl, LoggerColor::Color color);

    /**
     * Returns the color associated with a Logger::LoggerLvl.
     * @param lvl The Logger::LoggerLvl desired.
     * @return In item of Logger::Color enumeration representing the color associated.
     */
    LoggerColor::Color getLevelColor(Logger::LoggerLvl lvl);

    /**
     * This method converts strings to itens of the enumeration RegionalOpt
     * @param The string to be converted.
     * @return An item of Regionalpt.
     * @throw LoggerException If the string is invalid.
     */
    static RegionalOpt stringToRegionalOpt(std::string str);

    /**
     * This method converts itens of RegionalOpt enumeration into correspondents strings.
     * @param regionalOpt The item of RegionalOpt enumeration to be converted.
     * @return The string correspondents.
     */
    static std::string regionalOptToString(RegionalOpt regionalOpt);

    /**
     * This method converts strings to itens of the enumeration LoggerStyle
     * @param The string to be converted.
     * @return An item of LoggerStyle.
     * @throw LoggerException If the string is invalid.
     */
    static LoggerStyle stringToLoggerStyle(std::string str);

    /**
     * This method converts itens of LoggerStyle enumeration into correspondents strings.
     * @param loggerStyle The item of LoggerStyle enumeration to be converted.
     * @return The string correspondents.
     */
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
