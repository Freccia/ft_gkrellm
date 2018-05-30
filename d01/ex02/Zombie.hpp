/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:42:31 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/29 11:10:51 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
public:
	Zombie();
	~Zombie();
	void			announce();
	std::string		getZombieName(void);
	void			setZombieName(std::string name);
	std::string		getZombieType(void);
	void			setZombieType(std::string type);
private:
	std::string		_type;
	std::string		_name;
};

#endif
