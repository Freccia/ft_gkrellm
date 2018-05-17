/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:43:40 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 12:24:24 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name, int level, int hitPoints, int maxHitPoints,
		int energyPoints, int maxEnergyPoints, int meleeAttack,
		int rangedAttack, int armorReduction);
	ClapTrap(ClapTrap const &);
	~ClapTrap();

	/*	Functions	*/
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	/*	Operators	*/
	ClapTrap	&operator = (ClapTrap const &);

protected:
	/*	Properties	*/
	std::string		_name;
	int				_level;
	int				_hitPoints;
	int				_maxHitPoints;
	int				_energyPoints;
	int				_maxEnergyPoints;
	int				_meleeAttackDamage;
	int				_rangedAttackDamage;
	int				_armorReduction;

};

#endif
