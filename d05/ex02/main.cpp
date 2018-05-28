/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:20:43 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 15:14:13 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * clang++ main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
*/

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	int i = 0;

	while (i < 201)
	{
		try {
			Bureaucrat Francis("Francis", i);
			std::cout << Francis;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		i += 50;
	}

	std::cout << "-------" << std::endl;
	Bureaucrat George("George", 148);
	i = 0;
	while (i < 5) {
		try {
			George.decreaseGrade();
			std::cout << George;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		i++;
	}

	std::cout << "-------" << std::endl;
	Bureaucrat Jimmy("Jimmy", 4);
	i = 0;
	while (i < 5) {
		try {
			Jimmy.increaseGrade();
			std::cout << Jimmy;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		i++;
	}

	std::cout << "-------" << std::endl;
	ShrubberyCreationForm tree("tree");
	Bureaucrat Charly("Charly", 137);
	tree.execute(Charly);
	std::cout << "-------" << std::endl;
	Bureaucrat Carlos("Carlos", 143);
	i = 3;
	while (i > 0) {
		std::cout << Carlos;
		try {
			Carlos.signForm(tree);
			tree.execute(Carlos);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		Carlos.increaseGrade();
		i--;
	}
	tree.execute(Charly);
	RobotomyRequestForm		robo("Robo");
	srand(time_t());
	robo.beSigned(Jimmy);
	robo.execute(Jimmy);
	robo.execute(Jimmy);
	robo.execute(Jimmy);
	robo.execute(Jimmy);
	robo.execute(Jimmy);

	PresidentialPardonForm Leo("Leo");
	Bureaucrat Lucy("Lucy", 6);
	Leo.execute(Carlos);
	Lucy.signForm(Leo);
	std::cout << "-------" << std::endl;
	std::cout << Lucy;
	try {
		Leo.execute(Lucy);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Lucy.increaseGrade();
	Lucy.executeForm(Leo);
}
