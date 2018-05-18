/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:40:13 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/18 18:19:16 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class Peon : virtual public Victim {
public:
	Peon(std::string name);
	~Peon(void);
	virtual void	getPolymorphed(void) const;

private:
	Peon(void); // default constructor
	std::string		_name;
};

std::ostream		&operator << (std::ostream &, Peon const &);

#endif
