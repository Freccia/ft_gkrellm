/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:20:43 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 17:21:44 by lfabbro          ###   ########.fr       */
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
#include "CentralBureaucracy.hpp"

int main() {
	CentralBureaucracy central;
	central.feedSigner(*new Bureaucrat("Stacy", 1));
	central.feedSigner(*new Bureaucrat("Stacy", 70));
	central.feedSigner(*new Bureaucrat("Stacy", 150));
	central.feedSigner(*new Bureaucrat("Stacy", 150));
	central.feedSigner(*new Bureaucrat("Stacy", 2));
	central.feedSigner(*new Bureaucrat("Stacy", 150));
	central.feedSigner(*new Bureaucrat("Stacy", 150));
	central.feedSigner(*new Bureaucrat("Stacy", 1));
	central.feedSigner(*new Bureaucrat("Stacy", 150));
	central.feedSigner(*new Bureaucrat("Stacy", 150));
	central.feedSigner(*new Bureaucrat("Stacy", 150));
	central.feedSigner(*new Bureaucrat("Stacy", 150));
	central.feedSigner(*new Bureaucrat("Stacy", 150));
	central.feedSigner(*new Bureaucrat("Stacy", 150));
	central.feedSigner(*new Bureaucrat("Stacy", 140));
	central.feedSigner(*new Bureaucrat("Stacy", 150));
	central.feedSigner(*new Bureaucrat("Stacy", 150));
	central.feedSigner(*new Bureaucrat("Stacy", 150));

	central.feedExecutor(*new Bureaucrat("Vincent", 50));
	central.feedExecutor(*new Bureaucrat("Vincent", 150));
	central.feedExecutor(*new Bureaucrat("Vincent", 33));
	central.feedExecutor(*new Bureaucrat("Vincent", 90));
	central.feedExecutor(*new Bureaucrat("Vincent", 100));
	central.feedExecutor(*new Bureaucrat("Vincent", 100));
	central.feedExecutor(*new Bureaucrat("Vincent", 1));
	central.feedExecutor(*new Bureaucrat("Vincent", 99));
	central.feedExecutor(*new Bureaucrat("Vincent", 12));
	central.feedExecutor(*new Bureaucrat("Vincent", 23));
	central.feedExecutor(*new Bureaucrat("Vincent", 4));
	central.feedExecutor(*new Bureaucrat("Vincent", 22));
	central.feedExecutor(*new Bureaucrat("Vincent", 5));
	central.feedExecutor(*new Bureaucrat("Vincent", 2));
	central.feedExecutor(*new Bureaucrat("Vincent", 10));
	central.feedExecutor(*new Bureaucrat("Vincent", 1));

	/*
	for (int i = 0; i < 16; i++) {
		int		ra = rand() % 150;
		central.feedExecutor(*new Bureaucrat("Vincent", ra));
	}
	*/

	for (int i = 0; i < OFFICE_BLOCKS_SIZE; i++) {
		central.queueUp("target");
	}
	try {
		central.doBureaucracy();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
