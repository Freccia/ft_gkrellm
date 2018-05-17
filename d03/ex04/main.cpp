/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:08:23 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 17:06:38 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

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

void	test_ninjaTrap(void) {
	NinjaTrap	ft;
	NinjaTrap	ct("Sasuke");
	NinjaTrap	Cct(ft);
	NinjaTrap	eq;

	ClapTrap	Clap_test;
	ScavTrap	Scav_test;

	eq = ct;

	ft.meleeAttack("Sakura");
	ct.rangedAttack("Gaara");
	Cct.ninjaShoebox(Clap_test);
	eq.ninjaShoebox(Scav_test);

	for (int i=0; i < 5; i++) {
		ft.takeDamage(25);
	}

	for (int i=0; i < 2; i++) {
		ft.beRepaired(50);
	}
}

void	test_superTrap(void) {
	SuperTrap	ft;
	SuperTrap	ct("Gundam");
	SuperTrap	Cct(ft);
	SuperTrap	eq;

	ClapTrap	Clap_test;
	ScavTrap	Scav_test;

	eq = ct;

	ft.meleeAttack("Tatoori");
	ct.rangedAttack("OldBoy");
	Cct.ninjaShoebox(Clap_test);
	eq.ninjaShoebox(Scav_test);
	Cct.vaulthunter_dot_exe("Enemy one");
	eq.vaulthunter_dot_exe("Enemy two");

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
	std::cout << "---- NinjaTrap ---------------------------------" << std::endl;
	test_ninjaTrap();
	std::cout << "---- end --------------------------------------" << std::endl;
	std::cout << "---- SuperTrap ---------------------------------" << std::endl;
	test_superTrap();
	std::cout << "---- end --------------------------------------" << std::endl;

	return 0;
}
