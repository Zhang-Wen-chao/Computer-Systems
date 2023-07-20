#include <iostream>

class AbstractLogger {
public:
   static const int INFO = 1;
   static const int DEBUG = 2;
   static const int ERROR = 3;

protected:
   int level;
   AbstractLogger* nextLogger;

public:
   void setNextLogger(AbstractLogger* nextLogger) {
      this->nextLogger = nextLogger;
   }

   void logMessage(int level, const std::string& message) {
      if (this->level <= level) {
         write(message);
      }
      if (nextLogger != nullptr) {
         nextLogger->logMessage(level, message);
      }
   }

protected:
   virtual void write(const std::string& message) = 0;
};

class ConsoleLogger : public AbstractLogger {
public:
   ConsoleLogger(int level) {
      this->level = level;
   }

protected:
   void write(const std::string& message) override {
      std::cout << "Standard Console::Logger: " << message << std::endl;
   }
};

class ErrorLogger : public AbstractLogger {
public:
   ErrorLogger(int level) {
      this->level = level;
   }

protected:
   void write(const std::string& message) override {
      std::cout << "Error Console::Logger: " << message << std::endl;
   }
};

class FileLogger : public AbstractLogger {
public:
   FileLogger(int level) {
      this->level = level;
   }

protected:
   void write(const std::string& message) override {
      std::cout << "File::Logger: " << message << std::endl;
   }
};

int main() {
   AbstractLogger* loggerChain = new ErrorLogger(AbstractLogger::ERROR);
   AbstractLogger* fileLogger = new FileLogger(AbstractLogger::DEBUG);
   AbstractLogger* consoleLogger = new ConsoleLogger(AbstractLogger::INFO);

   loggerChain->setNextLogger(fileLogger);
   fileLogger->setNextLogger(consoleLogger);

   loggerChain->logMessage(AbstractLogger::INFO, "This is an information.");
   loggerChain->logMessage(AbstractLogger::DEBUG, "This is a debug level information.");
   loggerChain->logMessage(AbstractLogger::ERROR, "This is an error information.");

   delete loggerChain;
   delete fileLogger;
   delete consoleLogger;

   return 0;
}