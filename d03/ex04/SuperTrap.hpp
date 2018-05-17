/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:20:32 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 17:32:17 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {
public:
	SuperTrap();
	SuperTrap(std::string);
	SuperTrap(SuperTrap const &);
	~SuperTrap();

	/*	Operators	*/
	SuperTrap		&operator = (SuperTrap const &);

	using FragTrap::_hitPoints;
	using FragTrap::rangedAttack;
	using NinjaTrap::meleeAttack;

};

#endif
