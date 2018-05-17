/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:13:46 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/16 11:54:28 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <cstdlib>
#include <iostream>
#include <ctime>

class ScavTrap {
public:
	ScavTrap();
	ScavTrap(std::string);
	ScavTrap(ScavTrap const &);
	~ScavTrap();

	/*	Operators	*/
	ScavTrap		&operator = (ScavTrap const &);

	/*	Functions	*/
	void		rangedAttack(std::string const &);
	void		meleeAttack(std::string const &);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		challengeNewcomer(std::string const &);

private:
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
