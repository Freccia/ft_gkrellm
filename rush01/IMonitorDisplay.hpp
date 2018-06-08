/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 00:15:15 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 00:16:59 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMonitorDisplay_hpp
#define IMonitorDisplay_hpp

//template <typename T> // usually std::vector<int>
class IMonitorDisplay {
private:
public:
	virtual ~IMonitorDisplay(void) {};
	virtual void display(void);
};

#endif
