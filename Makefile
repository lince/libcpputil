CC= g++
HEADERS_DIR= /usr/local/include
LIB_DIR= /usr/local/lib
TESTS= \
		test/exceptionTest \
		test/loggerTest \
		test/socketClientTest \
		test/socketServerTest \
		test/uuidTest \
		test/enumTest \
		test/xmlBuilderTest \
		test/stringTest
		
PROGS= libcpputil.so

INCLUDES= \
			include/Functions.h \
			include/SimpleException.h \
			include/IllegalParameterException.h \
			include/InitializationException.h \
			include/NotImplementedException.h \
			include/Thread.h \
			include/Mutex.h \
			include/Enum.h
			
			
INCLUDES_LOGGER= \
			include/logger/Loggable.h \
			include/logger/LoggerDefault.h \
			include/logger/LoggerManager.h	\
			include/logger/Logger.h \
			include/logger/LoggerXmlParser.h \
			include/logger/LoggerException.h \
			include/logger/LoggerLogFile.h \
			include/logger/LoggerNetworkStream.h \
			include/logger/LoggerColor.h
			
SOURCES=	\
			src/Functions.cpp \
			src/Thread.cpp \
			src/Mutex.cpp \
			src/Enum.cpp \
			src/SimpleException.cpp \
			src/logger/Loggable.cpp \
			src/logger/LoggerDefault.cpp \
			src/logger/LoggerManager.cpp \
			src/logger/Logger.cpp \
			src/logger/LoggerXmlParser.cpp \
			src/logger/LoggerLogFile.cpp \
			src/logger/LoggerNetworkStream.cpp \
			src/logger/LoggerColor.cpp
			
LIBS= -lpthread -luuid
			
INCLUDES_TICPP= \
			ticpp/ticpp.h \
			ticpp/ticpprc.h \
			ticpp/tinystr.h \
			ticpp/tinyxml.h
					

SOURCES_TICPP=	\
			ticpp/ticpp.cpp \
			ticpp/tinystr.cpp \
			ticpp/tinyxml.cpp \
			ticpp/tinyxmlerror.cpp \
			ticpp/tinyxmlparser.cpp
			
LIBS_TICPP=

INCLUDES_NETWORK= \
			include/network/NetworkException.h \
			include/network/ServerSocketTCP.h \
			include/network/SocketTCP.h
					

SOURCES_NETWORK= \
			src/network/ServerSocketTCP.cpp \
			src/network/SocketTCP.cpp
			
LIBS_NETWORK=
			
INSTALL_HEADERS= $(INCLUDES)
INSTALL_HEADERS_LOGGER=  $(INCLUDES_LOGGER)
INSTALL_HEADERS_TICPP=  $(INCLUDES_TICPP)
INSTALL_HEADERS_NETWORK=  $(INCLUDES_NETWORK)

ALL: $(PROGS) $(TESTS)

libcpputil.so: $(INCLUDES) $(SOURCES) $(INCLUDES_LOGGER) $(INCLUDES_TICPP) $(SOURCES_TICPP) \
				$(INCLUDES_NETWORK) $(SOURCES_NETWORK)
	$(CC) -DTIXML_USE_TICPP $(SOURCES) $(SOURCES_TICPP) $(SOURCES_NETWORK) -I. -L. $(LIBS)\
		-shared -fPIC -o libcpputil.so -g
		
test/exceptionTest: test/exceptionTest.cpp libcpputil.so
	$(CC) -I. -I./include -L. -g test/exceptionTest.cpp -lcpputil -o test/exceptionTest
	
test/loggerTest: test/exceptionTest.cpp libcpputil.so
	$(CC) -I. -I./include -L. -g test/loggerTest.cpp -lcpputil -o test/loggerTest
	
test/socketClientTest: test/socketClientTest.cpp libcpputil.so
	$(CC) -I. -I./include -L. -g test/socketClientTest.cpp -lcpputil -o test/socketClientTest

test/socketServerTest: test/socketServerTest.cpp libcpputil.so
	$(CC) -I. -I./include -L. -g test/socketServerTest.cpp -lcpputil -o test/socketServerTest
	
test/uuidTest: test/uuidTest.cpp libcpputil.so
	$(CC) -I. -I./include -L. -g test/uuidTest.cpp -lcpputil -o test/uuidTest
	
test/uuidTest: test/uuidTest.cpp libcpputil.so
	$(CC) -I. -I./include -L. -g test/uuidTest.cpp -lcpputil -o test/uuidTest

test/enumTest: test/enumTest.cpp libcpputil.so
	$(CC) -I. -I./include -L. -g test/enumTest.cpp -lcpputil -o test/enumTest
	
test/xmlBuilderTest: test/xmlBuilderTest.cpp libcpputil.so
	$(CC) -I. -I./include -L. -g test/xmlBuilderTest.cpp -lcpputil -o test/xmlBuilderTest

test/stringTest: test/stringTest.cpp libcpputil.so
	$(CC) -I. -I./include -L. -g test/stringTest.cpp -lcpputil -o test/stringTest

clean:
	rm -f $(PROGS)
	rm -f $(TESTS)
	
uninstall:
	rm -rf $(HEADERS_DIR)/libcpputil
	rm -rf $(HEADERS_DIR)/ticpp
	rm -rf $(LIB_DIR)/libcpputil.so
		
install: libcpputil.so
	install -d $(HEADERS_DIR)/libcpputil
	install -d $(HEADERS_DIR)/libcpputil/logger  
	install -d $(HEADERS_DIR)/libcpputil/network  
	install -d $(HEADERS_DIR)/ticpp 
	install -t $(HEADERS_DIR)/libcpputil $(INSTALL_HEADERS)
	install -t $(HEADERS_DIR)/libcpputil/logger $(INSTALL_HEADERS_LOGGER)
	install -t $(HEADERS_DIR)/libcpputil/network $(INSTALL_HEADERS_NETWORK)
	install -t $(HEADERS_DIR)/ticpp $(INSTALL_HEADERS_TICPP)
	install -t $(LIB_DIR) libcpputil.so
