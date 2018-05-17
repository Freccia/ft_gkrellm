/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:08:23 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/16 12:35:26 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void	test_fragTrap(void) {
	FragTrap	ft;
	FragTrap	ct("Claptrap");
	FragTrap	Cct(ft);
	FragTrap	eq;

	eq = ct;

	ft.meleeAttack("Tuco");
	ct.rangedAttack("Apple's CEO");
	Cct.vaulthunter_dot_exe("Mark Zuckerberg");
	eq.vaulthunter_dot_exe("Satan");

	for (int i=0; i < 5; i++) {
		ft.takeDamage(25);
	}

	for (int i=0; i < 3; i++) {
		ft.beRepaired(50);
	}
}

void	test_scavTrap(void) {
	ScavTrap	ft;
	ScavTrap	ct("Gatekeeper");
	ScavTrap	Cct(ft);
	ScavTrap	eq;

	eq = ct;

	ft.meleeAttack("Luis");
	ct.rangedAttack("Steve");
	Cct.challengeNewcomer("Cara");
	eq.challengeNewcomer("Mick");

	for (int i=0; i < 5; i++) {
		ft.takeDamage(25);
	}

	for (int i=0; i < 2; i++) {
		ft.beRepaired(50);
	}
}

int		main(void) {
	std::cout << "---- FragTrap ---------------------------------" << std::endl;
	test_fragTrap();
	std::cout << "---- end --------------------------------------" << std::endl;
	std::cout << "---- ScavTrap ---------------------------------" << std::endl;
	test_scavTrap();
	std::cout << "---- end --------------------------------------" << std::endl;

	return 0;
}
