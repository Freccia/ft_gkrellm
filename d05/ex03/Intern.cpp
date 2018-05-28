/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:29:15 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 15:45:27 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	return;
}

Intern::~Intern(void) {
	return;
}

Intern::Intern(Intern const &Cc) {
	*this = Cc;
	return;
}

Intern		&Intern::operator = (Intern const &Cc) {
	(void)Cc;
	return *this;
}

Form*		Intern::makeForm(std::string name, std::string target) {
	if (name == "presidential pardon") {
		std::cout << "Intern creates " << name << std::endl;
		return new PresidentialPardonForm(target);
	}
	else if (name == "robotomy request") {
		std::cout << "Intern creates " << name << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (name == "shrubbery creation") {
		std::cout << "Intern creates " << name << std::endl;
		return new ShrubberyCreationForm(target);
	}
	std::cout << "Cannot create unknown Form " << name << std::endl;
	return NULL;
}
