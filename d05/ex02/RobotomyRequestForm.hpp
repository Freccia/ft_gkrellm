/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:51:54 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 13:56:30 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"
#include <fstream>

class RobotomyRequestForm : public Form {
private:
	RobotomyRequestForm(void);

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &Cc);
	~RobotomyRequestForm(void);

	RobotomyRequestForm		&operator = (RobotomyRequestForm const &Cc);

	virtual bool			execute(Bureaucrat const &) const = 0;
};

#endif
