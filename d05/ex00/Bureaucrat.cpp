/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:04:54 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/25 10:26:18 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Frank"), _grade(150) {
	return;
}

Bureaucrat::Bureaucrat(int grade): _grade(grade) {
	if (_grade > MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (_grade < MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &Cc) {
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
		throw Bureaucrat::GradeTooLowException();
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
