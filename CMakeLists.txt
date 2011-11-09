CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(libcpputil)

SET(BUILD_SHARED_LIBS ON)
SET(CMAKE_BUILD_TYPE DEBUG)

IF(CMAKE_COMPILER_IS_GNUCXX)
	SET(CMAKE_CXX_FLAGS_DEBUG  "-g3")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

SET(CMAKE_CXX_FLAGS "-DTIXML_USE_TICPP")
SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined -fPIC")


ADD_LIBRARY(cpputil 
			src/Enum.cpp 
			src/Functions.cpp 
			src/Mutex.cpp 
			src/SimpleException.cpp 
			src/Thread.cpp 
			src/network/ServerSocketTCP.cpp 
			src/network/SocketTCP.cpp
			src/logger/Loggable.cpp
			src/logger/Logger.cpp 
			src/logger/LoggerColor.cpp 
			src/logger/LoggerDefault.cpp 
			src/logger/LoggerLogFile.cpp 
			src/logger/LoggerManager.cpp 
			src/logger/LoggerNetworkStream.cpp 
			src/logger/LoggerXmlParser.cpp
			ticpp/ticpp.cpp
			ticpp/tinystr.cpp
			ticpp/tinyxml.cpp
			ticpp/tinyxmlerror.cpp
			ticpp/tinyxmlparser.cpp)
			
SET(install_headers
			include/Functions.h
			include/SimpleException.h
			include/IllegalParameterException.h
			include/InitializationException.h
			include/NotImplementedException.h
			include/Thread.h
			include/Mutex.h
			include/Enum.h)
			
			
SET(install_headers_logger
			include/logger/Loggable.h
			include/logger/LoggerDefault.h
			include/logger/LoggerManager.h
			include/logger/Logger.h
			include/logger/LoggerXmlParser.h
			include/logger/LoggerException.h
			include/logger/LoggerLogFile.h
			include/logger/LoggerNetworkStream.h
			include/logger/LoggerColor.h)
			
SET(install_headers_ticpp
			ticpp/ticpp.h
			ticpp/ticpprc.h
			ticpp/tinystr.h
			ticpp/tinyxml.h)
			
SET(install_headers_network
			include/network/NetworkException.h
			include/network/ServerSocketTCP.h
			include/network/SocketTCP.h)
			
TARGET_LINK_LIBRARIES (cpputil pthread uuid)

LINK_DIRECTORIES (${libcpputil_BINARY_DIR})

ADD_EXECUTABLE(exceptionTest test/exceptionTest.cpp)
TARGET_LINK_LIBRARIES (exceptionTest cpputil)

ADD_EXECUTABLE(loggerTest test/loggerTest.cpp)
TARGET_LINK_LIBRARIES (loggerTest cpputil)

ADD_EXECUTABLE(LoggerServer test/LoggerServer.cpp)
TARGET_LINK_LIBRARIES (LoggerServer cpputil)

ADD_EXECUTABLE(socketClientTest test/socketClientTest.cpp)
TARGET_LINK_LIBRARIES (socketClientTest cpputil)

ADD_EXECUTABLE(socketServerTest test/socketServerTest.cpp)
TARGET_LINK_LIBRARIES (socketServerTest cpputil)

ADD_EXECUTABLE(uuidTest test/uuidTest.cpp)
TARGET_LINK_LIBRARIES (uuidTest cpputil)

ADD_EXECUTABLE(enumTest test/enumTest.cpp)
TARGET_LINK_LIBRARIES (enumTest cpputil)

ADD_EXECUTABLE(xmlBuilderTest test/xmlBuilderTest.cpp)
TARGET_LINK_LIBRARIES (xmlBuilderTest cpputil)

ADD_EXECUTABLE(stringTest test/stringTest.cpp)
TARGET_LINK_LIBRARIES (stringTest cpputil)

INSTALL (TARGETS cpputil LIBRARY DESTINATION lib)

INSTALL (FILES ${install_headers} DESTINATION include/libcpputil)

INSTALL (FILES ${install_headers_ticpp} DESTINATION include/ticpp)

INSTALL (FILES ${install_headers_logger} DESTINATION include/libcpputil/logger)

INSTALL (FILES ${install_headers_network} DESTINATION include/libcpputil/network)

# include_directories (${HELLO_SOURCE_DIR}/Hello)

