#pragma once
#include <fstream>

class Logger {
private:
	std::ofstream logfile;
public:
	Logger();
	void log_info(char* text);
	void log_info(const char* text);
	void close();
};