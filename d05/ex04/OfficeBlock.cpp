/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:50:19 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 16:22:20 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) {
	return;
}

OfficeBlock::~OfficeBlock(void) {
	return;
}

OfficeBlock::OfficeBlock(
Intern &intern,
Bureaucrat &signing,
Bureaucrat &executor)
{
	*(this->_intern) = intern;
	*(this->_signing) = signing;
	*(this->_executor) = executor;
	return;
}

void OfficeBlock::setIntern(Intern &intern) {
	this->_intern = &intern;
}

void OfficeBlock::setSigning(Bureaucrat &signing) {
	this->_signing = &signing;
}

void OfficeBlock::setExecutor(Bureaucrat &executor) {
	this->_executor = &executor;
}

void OfficeBlock::doBureaucracy(std::string name, std::string target) {
	if (!_intern) {
		throw OfficeBlock::MissingInternException();
		return;
	} else if (!_signing || !_executor) {
		throw OfficeBlock::MissingBureaucratException();
		return;
	}

	Form *newForm = _intern->makeForm(name, target);

	if (!newForm) {
		throw OfficeBlock::UnknownFormException();
		return;
	}

	if (_signing->getGrade() > newForm->getGradeToSign()) {
		throw OfficeBlock::GradeTooLowToSignException();
		return;
	}

	_signing->signForm(*newForm);

	if (_executor->getGrade() > newForm->getGradeToExec()) {
		throw OfficeBlock::GradeTooLowToExecException();
		return;
	}

	_executor->executeForm(*newForm);
	std::cout << "Bureaucracy wins again." << std::endl;

}
