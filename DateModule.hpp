/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:42:53 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 20:46:22 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DateModule_hpp
#define DateModule_hpp

#include "MonitorModule.hpp"
#include <QFrame>
#include <QBoxLayout>
#include <QRect>

#define DATEMOD_X 28
#define DATEMOD_Y 3

class DateModule: public MonitorModule {
private:
	DateModule(void);
	DateModule(DateModule const &Cc);
	DateModule &operator=(DateModule const &Cc);

	std::string		_date;

public:
	DateModule(int posx, int posy);
    DateModule(QFrame *);
	~DateModule(void);

	/**/
	void			display(void);
	void			update(void);
    void displayQT(void);

};

#endif
