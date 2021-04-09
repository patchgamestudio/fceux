#include "logger.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>>


using namespace std;

Logger::Logger() {
	char buffer[50];
	time_t now = time(0);
	tm* ltm = localtime(&now);

	int iyear = 1900 + ltm->tm_year;
	char year[4];
	sprintf(year, "%04d", iyear);

	int imonth = 1 + ltm->tm_mon;
	char month[2];
	sprintf(month, "%02d", imonth);

	int iday = ltm->tm_mday;
	char day[2];
	sprintf(day, "%02d", iday);

	int ihour = ltm->tm_hour;
	char hour[2];
	sprintf(hour, "%02d", ihour);

	int iminute = ltm->tm_min;
	char minute[2];
	sprintf(minute, "%02d", iminute);

	int isecond = ltm->tm_sec;
	char second[2];
	sprintf(second, "%02d", isecond);

	sprintf(buffer, "fceux-%s%s%s-%s%s%s.txt", year, month, day, hour, minute, second);

	logfile.open(buffer);
	//logfile.precision(16);
}

void Logger::log_info(char* text) {

	unsigned __int64 now = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	
	logfile << std::fixed << now << ": " << text << endl << flush;
	std::cout << std::fixed << now << ": " << text << endl;
}

void Logger::log_info(const char *text) {
	unsigned __int64 now = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	logfile << time << "= " << text << endl << flush;
}

void Logger::close() {
	logfile.close();
}