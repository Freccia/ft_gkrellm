/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:08:48 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/11 12:38:32 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() {
	actions[0].name = "meleeAttack";
	actions[0].func = &Human::meleeAttack;
	actions[1].name = "rangedAttack";
	actions[1].func = &Human::rangedAttack;
	actions[2].name = "intimidatingShout";
	actions[2].func = &Human::intimidatingShout;
	return;
}

Human::~Human() {
	return;
}

void		Human::meleeAttack(std::string const & target) {
	std::cout << "Melee Attack to " << target << std::endl;
}

void		Human::rangedAttack(std::string const & target) {
	std::cout << "Ranged Attack to " << target << std::endl;
}

void		Human::intimidatingShout(std::string const & target) {
	std::cout << "Intimidatig shout to " << target << std::endl;
}

void		Human::action(std::string const & action_name,
			std::string const & target)
{
	for (int i=0; i < 3; i++) {
		if (action_name == actions[i].name) {
			(this->*actions[i].func)(target);
			return;
		}
	}
	std::cout << "Invalid action." << std::endl;
}
