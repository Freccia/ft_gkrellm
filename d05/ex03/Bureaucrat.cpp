/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:04:54 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 16:35:15 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Frank"), _grade(150) {
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade):
_name(name), _grade(grade)
{
	if (_grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &Cc):
_name(Cc.getName()), _grade(Cc.getGrade())
{
	//_name = Cc.getName();
	//_grade = Cc.getGrade();
	*this = Cc;
	return;
}

Bureaucrat::~Bureaucrat(void) {
	return;
}

/*		Function Members		*/

std::string				Bureaucrat::getName(void) const {
	return this->_name;
}

int						Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void					Bureaucrat::increaseGrade(void) {
	_grade--;
	if (_grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
}

void					Bureaucrat::decreaseGrade(void) {
	_grade++;
	if (_grade > MIN_GRADE)
		throw GradeTooLowException();
}

bool					Bureaucrat::signForm(Form &form) {
	if (form.beSigned(*this) == false) {
		std::cout << this->_name << " cannot sign " << form.getName()
			<< std::endl;
		return false;
	}
	std::cout << this->_name << " signed " << form.getName()
		<< std::endl;
	return true;
}

bool					Bureaucrat::executeForm(Form const &form) {
	if (form.execute(*this) == false) {
		std::cout << this->_name << " cannot execute " << form.getName()
			<< std::endl;
		return false;
	}
	std::cout << this->_name << " executes " << form.getName() << std::endl;
	return true;
}

/*		Operators				*/

Bureaucrat &Bureaucrat::operator = (Bureaucrat const &Cc) {
	//_name = Cc._name;
	_grade = Cc._grade;
	return *this;
}

std::ostream &operator << (std::ostream &out, Bureaucrat const &Cc) {
	out << "<" << Cc.getName() << ">, bureaucrat grade <"
		<< Cc.getGrade() << ">" << std::endl;
	return out;
}
