/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:54:04 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 16:41:18 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * clang++ main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp OfficeBlock.cpp
*/

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main() {
	Intern      idiotOne;
	Bureaucrat  hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat  bob = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;

	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);

	try
	{
		ob.doBureaucracy("mutant pig termination", "Pigley");
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		/* oh god, unknown error, what to do ?! */
	}
}
