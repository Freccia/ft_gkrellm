/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:57:31 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 13:42:39 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form {
private:
	ShrubberyCreationForm(void);

public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &Cc);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm		&operator = (ShrubberyCreationForm const &Cc);

	virtual bool			execute(Bureaucrat const &) const = 0;
};

#endif
