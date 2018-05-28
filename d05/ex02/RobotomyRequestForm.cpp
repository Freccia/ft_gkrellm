/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:54:30 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 15:23:54 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) {
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("RobotomyRequestForm", 0, 72, 45)
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

RobotomyRequestForm &RobotomyRequestForm::operator = (RobotomyRequestForm const &rfs) {
	(void)rfs;
	return *this;
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
		<< " sadly the rest of the time he's still a slow human. " << std::endl;
	return true;
}
