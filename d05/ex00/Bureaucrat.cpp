/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:04:54 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/25 12:56:50 by lfabbro          ###   ########.fr       */
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
