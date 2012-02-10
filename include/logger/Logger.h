/*
 * Logger.h
 *
 *  Created on: Jul 19, 2011
 *      Author: caioviel
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <map>

#include "Loggable.h"
#include "LoggerException.h"

namespace cpputil {
namespace logger {

class LoggerManager;

/**
 * This class is a generic-logger, base for all other loggers classes.
 * Logger works as a singletron, registering all the instances that wishes
 * to emit log-messages.
 * It can control the messages by level or by the list of blocked-classes.
 */

class Logger {
public:
	/**
	 * Enumeration that holds the possible Logger Levels.
	 * - TRACE: The lowest level. Used to keep the tracing of the method calls.
	 * - DEBUG: Used to debug purposes.
	 * - INFO: Used to print usefull information.
	 * - WARNING: Used to allert about some possible problem.
	 * - ERROR: Used to inform a error.
	 * - FATAL: The highest level. Used to inform non-retrievable errors.
	 */
	enum LoggerLvl {
		TRACE=0,
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		FATAL,
	};

	/**
	 * This method returns a pointer to the singletron instance of logger.
	 */
	static Logger* getInstance();

	/**
	 * This method converts LoggerLvl itens into strings with their names.
	 * @param loggerLvl The item to be converted.
	 * @return A string with the name of the item.
	 */
	static std::string loggerLvlToString(LoggerLvl loggerLvl);

	/**
	 * This method converts strings into LoggerLvl itens.
	 * @param str The string to be converted.
	 * @return A LoggerLvl item
	 * @throw LoggerException When trying to convert an invalid string.
	 */
	static LoggerLvl stringToLoggerLvl(std::string str);

public:
	/**
	 * Destructir
	 */
	virtual ~Logger();

	/**
	 * Register a loggable instance with its name in the logger.
	 * @param loggable The instance to be registered.
	 * @param completeClassName The name of the instance.
	 * @throw LoggerException If trying to register the same instance twice.
	 */
	void registerClass(Loggable* loggable, std::string completeClassName);

	/**
	 * Remove a loggable instance for the logger's register.
	 * @param loggable The instance to be remove.
	 * @throw LoggerException If the instance ins't registered.
	 */
	void unregisterClass(Loggable* loggable);

	/**
	 * This method assembles the log messages.
	 * It will verify if the message need to be emited checking the LoggerLvl and the
	 * list of blocked-classes.
	 * @param str The raw message.
	 * @param lvl The LoggerLvl of the message.
	 * @param _this The instance that posts the message. If not informed, it will assume NULL value.
	 */
	virtual void message(std::string str, LoggerLvl lvl=INFO, Loggable* _this=NULL);

	/**
	 * This method emits TRACE level log messges.
	 * @param str The raw message
	 * @param _this The instance that posts the message. If not informed, it will assume NULL value.
	 */
	virtual void traceMessage(std::string str, Loggable* _this=NULL);

	/**
	 * This method emits DEBUG level log messges.
	 * @param str The raw message
	 * @param _this The instance that posts the message. If not informed, it will assume NULL value.
	 */
	virtual void debugMessage(std::string str, Loggable* _this=NULL);

	/**
	 * This method emits INFO level log messges.
	 * @param str The raw message
	 * @param _this The instance that posts the message. If not informed, it will assume NULL value.
	 */
	virtual void infoMessage(std::string str, Loggable* _this=NULL);

	/**
	 * This method emits WARNING level log messges.
	 * @param str The raw message
	 * @param _this The instance that posts the message. If not informed, it will assume NULL value.
	 */
	virtual void warningMessage(std::string str, Loggable* _this=NULL);

	/**
	 * This method emits ERROR level log messges.
	 * @param str The raw message
	 * @param _this The instance that posts the message. If not informed, it will assume NULL value.
	 */
	virtual void errorMessage(std::string str, Loggable* _this=NULL);

	/**
	 * This method emits FATAL level log messges.
	 * @param str The raw message
	 * @param _this The instance that posts the message. If not informed, it will assume NULL value.
	 */
	virtual void fatalMessage(std::string str, Loggable* _this=NULL);

protected:
	/**
	 * Protected Constructor.
	 * It will be used be the concrete Loggers classes only.
	 * @param loggerLvl The lowest loggerLvl that will be reported.
	 */
	Logger(LoggerLvl loggerLvl);

	/**
	 * Returns a string with a well-formated timestamp of the current time.
	 * @return A string of a timestamp.
	 */
	virtual std::string getTimeInfo();

	/**
	 * This method is internaly used to pass the log messages to concrete loggers.
	 * @param completeMessage The log message already assembled.
	 * @param lvl The LoggerLvl of the log message.
	 */
	virtual void internalMessage(std::string completeMessage, LoggerLvl lvl) = 0;

protected:
	LoggerLvl loggerLvl;
	LoggerManager* logManager;
	std::map<Loggable*, std::string>* loggableMap;

private:
	static Logger *_instance;

#define TRACE(OBJLogger, str) OBJLogger->traceMessage(str, this);
#define DEBUG(OBJLogger, str) OBJLogger->debugMessage(str, this);
#define INFO(OBJLogger, str) OBJLogger->infoMessage(str, this);
#define WARNING(OBJLogger, str) OBJLogger->warningMessage(str, this);
#define ERROR(OBJLogger, str) OBJLogger->errorMessage(str, this);
#define FATAL(OBJLogger, str) OBJLogger->fatalMessage(str, this);
#define REGISTER(OBJLogger, str) OBJLogger->registerClass(this, str);
#define UNREGISTER(OBJLogger) OBJLogger->unregisterClass(this);

friend class LoggerManager;

};

} /* namespace logger */
} /* namespace cpputil */
#endif /* LOGGER_H_ */
