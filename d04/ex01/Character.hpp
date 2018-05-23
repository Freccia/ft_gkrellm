/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:15:45 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 14:47:11 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {
private:
	Character();

	std::string	_name;
	int			_ap;
	AWeapon		*_weapon;

public:
	Character(std::string const &name);
	Character(Character const &Cc);
	~Character();

	Character &operator = (Character const &Cc);

	void 			recoverAP();
	void 			equip(AWeapon *);
	void 			attack(Enemy*);
	std::string		getName() const;
	int				getAP() const;
	std::string		getWeaponName() const;
	AWeapon			*getWeapon() const;
};

std::ostream 	&operator << (std::ostream &o, Character const &Cc);

#endif
