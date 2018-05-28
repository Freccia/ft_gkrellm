/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:49:39 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 16:17:40 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class OfficeBlock {
private:
	OfficeBlock(OfficeBlock const &);
	OfficeBlock		operator = (OfficeBlock const &);

	Intern		*_intern;
	Bureaucrat	*_signing;
	Bureaucrat	*_executor;

public:
	OfficeBlock(void);
	OfficeBlock(Intern &intern, Bureaucrat &signing, Bureaucrat &executor);
	~OfficeBlock(void);

	void setIntern(Intern &intern);
	void setSigning(Bureaucrat &signing);
	void setExecutor(Bureaucrat &executor);
	void doBureaucracy(std::string name, std::string target);


	struct MissingInternException : public std::exception {
		const char * what () const throw () {
			return "NoInternException";
		}
	};

	struct MissingBureaucratException : public std::exception {
		const char * what () const throw () {
			return "MissingBureaucratException";
		}
	};

	struct GradeTooLowToSignException : public std::exception {
		const char * what () const throw () {
			return "GradeTooLowToSignException";
		}
	};

	struct GradeTooLowToExecException : public std::exception {
		const char * what () const throw () {
			return "GradeTooLowToExecException";
		}
	};

	struct UnknownFormException : public std::exception {
		const char * what () const throw () {
			return "UnknownFormException";
		}
	};

};

#endif
