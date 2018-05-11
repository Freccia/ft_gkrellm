/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 09:55:44 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/11 10:58:44 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
public:
	Weapon(std::string);
	~Weapon();
	std::string const &	getType() const;
	void				setType(std::string);
private:
	std::string			type;
};

#endif
