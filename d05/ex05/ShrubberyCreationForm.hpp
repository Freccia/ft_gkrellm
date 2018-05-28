/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:57:31 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 14:53:28 by lfabbro          ###   ########.fr       */
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
	virtual ~ShrubberyCreationForm(void);

	ShrubberyCreationForm		&operator = (ShrubberyCreationForm const &Cc);

	virtual bool			execute(Bureaucrat const &) const;
};

#endif
