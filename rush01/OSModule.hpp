/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:32:15 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 17:40:39 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSModule_hpp
#define OSModule_hpp

#include "MonitorModule.hpp"

#define OSMOD_X 62
#define OSMOD_Y 10

#define MAXHOSTNAME 256

class OSModule: public MonitorModule {
private:
	/**/
	OSModule(void);
	OSModule(OSModule const &Cc);
	OSModule &operator=(OSModule const &Cc);
	/**/
	std::string		_hostname;
	std::string		_username;
	std::string		_sysname;
	std::string		_nodename;
	std::string		_release;
	std::string		_version;
	std::string		_machine;

public:
	//OSModule(int width, int height, int x, int y);
	OSModule(int posx, int posy);
	~OSModule(void);

	/**/
	void		display(void);
};

#endif
