/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 09:48:31 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 15:03:30 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

# define MIN_GRADE	150
# define MAX_GRADE	1

class Form;

class Bureaucrat {
private:
	std::string const	_name;
	int					_grade;

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &);
	~Bureaucrat(void);

	Bureaucrat &operator = (Bureaucrat const &Cc);

	std::string			getName(void) const;
	int					getGrade(void) const;
	void				increaseGrade(void);
	void				decreaseGrade(void);

	bool				signForm(Form &form);


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

std::ostream &operator << (std::ostream &out, Bureaucrat const &Cc);

#endif
