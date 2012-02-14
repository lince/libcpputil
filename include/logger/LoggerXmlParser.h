/*
 * LoggerXmlParser.h
 *
 *  Created on: Jul 20, 2011
 *      Author: caioviel
 */

#ifndef LOGGERXMLPARSER_H_
#define LOGGERXMLPARSER_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <set>

#include "../../ticpp/ticpp.h"
using namespace ticpp;

#include "LoggerException.h"
#include "LoggerManager.h"

namespace cpputil {
namespace logger {

/**
 * A parser capable of read the logger configuration files.
 */
class LoggerXmlParser {
public:
	/**
	 * Constructor.
	 * @param The xml file name to be parsed.
	 */
	LoggerXmlParser(std::string xmlFileName);

	/**
	 * Destructor;
	 */
	virtual ~LoggerXmlParser();

	/**
	 * Do the parse of the xml document to retrieve the log options.
	 * If some error was detected during the parsing process, the options will be
	 * reseted to default options.
	 * @throw LoggerException When errors are detected in the xml document.
	 */
	void parseDocument();


	/**
	 * Returns a set with the name of blocked class of parsed the xml document.
	 * The default value is a empty set.
	 * @return A set with the name of classes.
	 */
	std::set<std::string>* getBlockedClasses();

	/**
	 * Returns the name of the log file of the parsed xml document.
	 * The default value is "logfile.log".
	 * @return String with the file name.
	 */
	std::string getFileName();

	/**
	 * Returns the log-server's ip address of the parsed xml document.
	 * The default value is "127.0.0.1".
	 * @return String with the file name.
	 */
	std::string getIpAddress();

	/**
	 * Returns the LoggerManager::LoggerStyle of the parsed xml document.
	 * The default value is LoggerManager::DEFAULT.
	 * @return In item of Logger::Manager::LoggerStyle enumeration.
	 */
    LoggerManager::LoggerStyle getLoggerStyle();

	/**
	 * Returns the log-server's port number of the parsed xml document.
	 * The default value is 5004
	 * @return Integer with the port number.
	 */
    unsigned short getPortNumber();

	/**
	 * Returns the RegionalOpt::LoggerStyle of the parsed xml document.
	 * The default value is LoggerManager::USA.
	 * @return In item of Logger::Manager::RegionalOpt enumeration.
	 */
    LoggerManager::RegionalOpt getRegional();

	/**
	 * Returns LoggerNetworkStream::Protocol of the parsed xml document.
	 * The default value is LoggerNetworkStream::TCP
	 * @return In item of LoggerNetworkStream::Protocol enumeration.
	 */
    LoggerNetworkStream::Protocol getProtocol();

	/**
	 * Returns LoggerLogFile::WriteMode of the parsed xml document.
	 * The default value is LoggerLogFile::OVERWRITE_FILE
	 * @return In item of LoggerLogFile::WriteMode enumeration.
	 */
    LoggerLogFile::WriteMode getWritemode();

	/**
	 * Returns Logger::LoggerLvl of the parsed xml document.
	 * The default value is Logger::INFO
	 * @return In item of Logger::LoggerLvl enumeration.
	 */
    Logger::LoggerLvl getLoggerLvl();

	/**
	 * Returns An array of LoggerColor::Color of the parsed xml document.
	 * @return Array with the Logger::Color associated with the log messages.
	 */
    LoggerColor::Color* getColors();

private:
    void parseBlockedClasses(Element* blockedClasses);
    void parseNetworkStream(Element* style);
    void parseLogFile(Element* style);
    void parseDefault(Element* style);
    void parseColor(Element* style);

private:
    std::string xmlFileName;
    std::set<std::string>* blockedClasses;
	LoggerManager::RegionalOpt regionalOpt;
	LoggerManager::LoggerStyle loggerStyle;
	Logger::LoggerLvl loggerLvl;

	std::string ipAddress;
	unsigned short	portNumber;
	LoggerNetworkStream::Protocol protocol;

	std::string logfileName;
	LoggerLogFile::WriteMode writemode;

	LoggerColor::Color* colors;

	void resetDefault();
};

} /* namespace logger */
} /* namespace cpputil */
#endif /* LOGGERXMLPARSER_H_ */
