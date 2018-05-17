/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:13:46 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/14 17:18:17 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <cstdlib>
#include <iostream>
#include <ctime>

class FragTrap {
public:
	FragTrap();
	FragTrap(std::string);
	FragTrap(FragTrap const &);
	~FragTrap();

	/*	Operators	*/
	FragTrap		&operator = (FragTrap const &);

	/*	Functions	*/
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		vaulthunter_dot_exe(std::string const & target);

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
