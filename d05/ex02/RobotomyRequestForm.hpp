/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:51:54 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 14:45:55 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form {
private:
	RobotomyRequestForm(void);

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &Cc);
	virtual ~RobotomyRequestForm(void);

	RobotomyRequestForm		&operator = (RobotomyRequestForm const &Cc);

	virtual bool			execute(Bureaucrat const &) const;
};

#endif
