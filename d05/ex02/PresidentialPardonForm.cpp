/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:32:27 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 14:34:51 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) {
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("PresidentialPardonForm", 0, 72, 45)
{
	setTarget(target);
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &Cc):
	Form(Cc)
{
	this->setTarget(Cc.getTarget());
	return;
}

bool		PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (this->getSigned() == false) {
		std::cout << "Cannot execute: This form is not signed." << std::endl;
		return false;
	}
	if (executor.getGrade() > this->getGradeToExec()) {
		throw Form::GradeTooLowException();
	}
	std::cout << this->getTarget()
		<< " has been pardoned by Zafod Beeblebrox" << std::endl;
	return true;
}
