/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:54:30 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 14:01:06 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(void) {
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("RobotomyRequestForm", 0, 145, 137)
{
	setTarget(target);
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &Cc):
	Form(Cc)
{
	this->setTarget(Cc.getTarget());
	return;
}

bool			RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (this->getSigned() == false) {
		std::cout << "Cannot execute: This form is not signed." << std::endl;
		return false;
	}
	if (executor.getGrade() > this->getGradeToExec()) {
		throw Form::GradeTooLowException();
	}
	std::cout << "BzzzTrrshhCshhhh Bzzz Bzzz Vrrrreeee" << std::endl;
	std::cout << this->getTarget()
		<< " has successfully robotomized 50%% of his time,"
		<< " sadly the rest of the time he is still human. " << std::endl;
	return true;
}
