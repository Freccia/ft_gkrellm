/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:30:09 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 14:53:20 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm: public Form {
private:
	PresidentialPardonForm(void);

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &Cc);
	virtual ~PresidentialPardonForm(void);

	PresidentialPardonForm		&operator = (PresidentialPardonForm const &Cc);

	virtual bool			execute(Bureaucrat const &) const;
};

#endif
