/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SysModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:55:45 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 20:50:35 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SysModule_hpp
#define SysModule_hpp

#include "MonitorModule.hpp"
#include <QFrame>
#include <QBoxLayout>
#include <QRect>

#define SYSMOD_X 60
#define SYSMOD_Y 7

class SysModule: public MonitorModule {
private:
	/**/
	SysModule(void);
	SysModule(SysModule const &Cc);
	SysModule &operator=(SysModule const &Cc);
	/**/
	std::string		_cpubrand;
	std::string		_cpuvendor;
	std::string		_cpufeatures;
	std::string		_cpucores;
	std::string		_cpuclock;

    void _init();

public:
	//SysModule(int width, int height, int x, int y);
	SysModule(int posx, int posy);
    SysModule(QFrame *fr);
	~SysModule(void);

	/**/
	void		display(void);
    void displayQT(void);
};

#endif
