/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:08:23 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/14 17:27:11 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int		main(void) {
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

	return 0;
}
