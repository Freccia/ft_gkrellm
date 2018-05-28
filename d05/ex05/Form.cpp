/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:07:39 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 15:07:20 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :
	_name("F_AAA_0000"),
	_signed(false),
	_minGradeToSign(130),
	_minGradeToExec(130)
{
	return;
}

Form::Form(Form const &Cc) :
	_name(Cc._name),
	_signed(Cc._signed),
	_minGradeToSign(Cc._minGradeToSign),
	_minGradeToExec(Cc._minGradeToExec)
{
	return;
}

Form::Form(std::string name, bool sign, int minGradeToSign, int minGradeToExec):
	_name(name),
	_signed(sign),
	_minGradeToSign(minGradeToSign),
	_minGradeToExec(minGradeToExec)
{
	if (this->_minGradeToSign < MAX_GRADE || this->_minGradeToExec < MAX_GRADE)
		throw Form::GradeTooHighException();
	if (this->_minGradeToSign > MIN_GRADE || this->_minGradeToExec > MIN_GRADE)
		throw Form::GradeTooLowException();
	return;
}

Form::~Form(void) {
	return;
}

Form			&Form::operator = (Form const &Cc) {
	this->_signed = Cc.getSigned();
	return *this;
}

std::string			Form::getName(void) const {
	return this->_name;
}

bool				Form::getSigned(void) const {
	return this->_signed;
}

int					Form::getGradeToSign(void) const {
	return this->_minGradeToSign;
}

int					Form::getGradeToExec(void) const {
	return this->_minGradeToExec;
}

bool				Form::beSigned(Bureaucrat b) {
	if (b.getGrade() > this->_minGradeToSign) {
		throw Form::GradeTooLowException();
		/*
		std::cout << b.getName() << " cannot sign " << this->_name
			<< ", minimum grade to sign <" << this->getGradeToExec()
			<< std::endl;
			*/
		//return false;
	}
	this->_signed = true;
	std::cout << b.getName() << " signs " << this->_name << std::endl;
	return true;
}

std::string				Form::getTarget(void) const {
	return this->_target;
}

void					Form::setTarget(std::string target) {
	this->_target = target;
}

/*
void				Form::execute(Bureaucrat const &b) const {
	if (b.getGrade() > this->_minGradeToExec) {
		std::cout << b.getName() << " cannot exec " << this->_name
			<< ", minimum grade to exec <" << this->getGradeToExec()
			<< std::endl;
	}
}
*/

std::ostream		&operator << (std::ostream &out, Form const &Cc) {
	out << "<" << Cc.getName() << ">, signed <" << Cc.getSigned()
		<< ">, minimum grade to sign <" << Cc.getGradeToSign()
		<< ">, minimum grade to execute <" << Cc.getGradeToExec()
		<< ">" ; //<< std::endl;
	return out;
}
