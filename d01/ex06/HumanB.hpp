/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 10:04:46 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/11 11:01:08 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CPP
# define HUMANB_CPP

#include <iostream>
#include "Weapon.hpp"

class HumanB{
public:
	HumanB(std::string name);
	~HumanB();
	void			attack();
	void			setWeapon(Weapon&);
private:
	std::string		_name;
	Weapon*			_weapon;
};

#endif
