/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 23:42:57 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 00:03:17 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMonitorModule_hpp
#define IMonitorModule_hpp

#include <vector>
#include <iostream>

template <typename T> // usually std::vector<int>
class IMonitorModule {
private:
public:
	virtual ~IMonitorModule(void) {};
	virtual T getSize(void) = 0;
};

#endif
