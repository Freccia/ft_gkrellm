/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:55:11 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 13:51:57 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon
{
protected:
	AWeapon();

	std::string	_name;
	int			_damage;
	int			_apcost;

public:
	AWeapon(std::string const & name, int damage, int apcost);
	AWeapon(AWeapon const &Cc);
	virtual ~AWeapon();

	std::string 	getName() const;
	int 			getAPCost() const;
	int 			getDamage() const;
	virtual void 	attack() const = 0;

	AWeapon 	&operator=(AWeapon const &Cc);
};


#endif
