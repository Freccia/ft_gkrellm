/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:43:12 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 13:08:21 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <iostream>

class ZombieEvent {
public:
	ZombieEvent();
	~ZombieEvent();
	void			setZombieType(std::string type);
	Zombie*			newZombie(std::string name);
	Zombie*			randomChump(void);
private:
	std::string		_zombieType;
};

#endif
