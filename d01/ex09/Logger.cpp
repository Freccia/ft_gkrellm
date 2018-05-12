/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 09:50:55 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 11:04:14 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string logFile) {
	if (logFile.empty() == false)
		_logFile.open(logFile.c_str());
	dst[0].name = "logToConsole";
	dst[0].logMethod = &Logger::logToConsole;
	dst[1].name = "logToFile";
	dst[1].logMethod = &Logger::logToFile;
	return;
}

Logger::~Logger(void){
	_logFile.close();
	return;
}

int				Logger::log(std::string const & dest, std::string const & msg) {
	for (int i=0; i < 2; i++) {
		if (dst[i].name == dest) {
			(this->*dst[i].logMethod)(msg);
			return 0;
		}
	}
	logToConsole("Invalid log method");
	return 1;
}

std::string		Logger::makeLogEntry(std::string msg) {
	std::time_t		t = std::time(0);
	std::tm			tm = *std::localtime(&t);
	std::ostringstream time;
	std::string		strTime;

	time << std::put_time(&tm, "[%Y/%m/%d %H:%M:%S]: ");
	strTime = time.str();
	return strTime.append(msg);
}

int				Logger::logToConsole(std::string msg) {
	std::cout << makeLogEntry(msg) << std::endl;
	return 0;
}

int				Logger::logToFile(std::string msg) {
	if (_logFile.is_open() == false) {
		logToConsole("logfile closed, logging to console");
		logToConsole(msg);
		return 1;
	}
	_logFile << makeLogEntry(msg) << std::endl;
	return 0;
}
