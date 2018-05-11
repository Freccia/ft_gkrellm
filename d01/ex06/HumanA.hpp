/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 10:04:46 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/11 10:41:58 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CPP
# define HUMANA_CPP

#include <iostream>
#include "Weapon.hpp"

class HumanA{
public:
	HumanA(std::string, Weapon&);
	~HumanA();
	void			attack();
private:
	std::string		_name;
	Weapon&			_weapon;
};

#endif
