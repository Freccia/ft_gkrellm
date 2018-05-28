/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:00:44 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 15:10:06 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	std::string	const		_name;
	std::string				_target;
	bool					_signed;
	int			const		_minGradeToSign;
	int			const		_minGradeToExec;

public:
	Form(void);
	Form(std::string name, bool sign, int minGradeToSign, int minGradeToExec);
	Form(Form const &Cc);
	virtual ~Form(void);

	std::string				getName(void) const;
	bool					getSigned(void) const;
	int						getGradeToSign(void) const;
	int						getGradeToExec(void) const;
	bool					beSigned(Bureaucrat);

	std::string				getTarget(void) const;
	void					setTarget(std::string target);

	virtual bool			execute(Bureaucrat const &) const = 0;

	Form			&operator = (Form const &Cc);

	struct GradeTooHighException : public std::exception {
		const char * what () const throw () {
			return "GradeTooHighException";
		}
	};

	struct GradeTooLowException : public std::exception {
		const char * what () const throw () {
			return "GradeTooLowException";
		}
	};

};

std::ostream &operator << (std::ostream &out, Form const &Cc);

#endif
