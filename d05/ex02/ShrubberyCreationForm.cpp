/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:15:37 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 14:34:54 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) {
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("ShrubberyCreationForm", 0, 145, 137)
{
	setTarget(target);
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &Cc):
	Form(Cc)
{
	this->setTarget(Cc.getTarget());
	return;
}

bool			ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->getSigned() == false) {
		std::cout << "Cannot execute: This form is not signed." << std::endl;
		return false;
	}
	if (executor.getGrade() > this->getGradeToExec()) {
		throw Form::GradeTooLowException();
	}
	std::string		filename = this->getTarget() + "_shrubbery";
	std::ofstream	out(filename);
	out << "       ^       " << std::endl;
	out << "     <   >     " << std::endl;
	out << "    <     >    " << std::endl;
	out << "   <       >   " << std::endl;
	out << "  <  O    O >  " << std::endl;
	out << " <           > " << std::endl;
	out << "<       >     >" << std::endl;
	out << " <    _      > " << std::endl;
	out << "  <_________>  " << std::endl;
	out << "       ||      " << std::endl;
	out.close();
	std::cout << executor.getName() << " executes " << getName() << std::endl;
	return true;
}
