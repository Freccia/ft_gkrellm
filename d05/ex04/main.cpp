/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:20:43 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 16:39:40 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * clang++ main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp OfficeBlock.cpp
*/

/*    !!! Subject MAIN is in test.cpp    */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main() {
/*
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

	std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
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

	std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
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

	std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	ShrubberyCreationForm tree("tree");
	Bureaucrat Charly("Charly", 137);
	tree.execute(Charly);
	std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
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
	std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << Lucy;
	try {
		Leo.execute(Lucy);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Lucy.increaseGrade();
	Lucy.executeForm(Leo);

	std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	Intern		intern;

	Form		*G5 = intern.makeForm("shrubbery creation", "lol_tree");
	G5->beSigned(Jimmy);
	G5->beSigned(Charly);

	Form		*Z9 = intern.makeForm("robotomy request", "botoromiZe mE");
	try {
		Z9->beSigned(George);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Z9->execute(Lucy);

	Form		*H76 = intern.makeForm("presidential pardon", "forgive me Sir");
	H76->beSigned(Lucy);
	try {
		H76->execute(Carlos);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Form		*lulz = intern.makeForm("lulz", "lulZZ");
	lulz = NULL;
*/

	OfficeBlock		block;
	Intern			*Fred = new Intern();
	Bureaucrat		Francois("Francois", 50);
	Bureaucrat		Paul("Paul", 100);

	std::cout << "-------------------------------------" << std::endl;
	block.setIntern(*Fred);
	try {
		block.doBureaucracy("robotomy request", "torobo");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------------" << std::endl;
	block.setSigner(Francois);
	try {
		block.doBureaucracy("shrubberry creation", "free");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------------" << std::endl;
	delete Fred;
	Fred = NULL;
	block.setExecutor(Paul);
	try {
		block.doBureaucracy("robotomy request", "boroto");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------------" << std::endl;
	Intern			randomStagist;
	block.setIntern(randomStagist);
	try {
		block.doBureaucracy("robotomy request", "toboro");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------------" << std::endl;
	Bureaucrat		Lucio("Lucio", 10);
	block.setExecutor(Lucio);
	try {
		block.doBureaucracy("presidential pardon", "I'm sorry mate!");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------------" << std::endl;
	try {
		block.doBureaucracy("LULz", "LULZ");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
