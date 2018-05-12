/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 09:37:14 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 11:00:05 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <ctime>

class Logger {
public:
	Logger(std::string logFile);
	~Logger();
	int				log(std::string const & dest, std::string const & msg);

	struct logDst
	{
		std::string	name;
		int			(Logger::*logMethod)(std::string str);
	};

	logDst			dst[2];

private:
	std::string		makeLogEntry(std::string msg);
	int				logToConsole(std::string msg);
	int				logToFile(std::string msg);

	std::ofstream	_logFile;
};

#endif
