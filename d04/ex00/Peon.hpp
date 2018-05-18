/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:40:13 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/18 14:35:03 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim {
public:
	Peon(std::string name);
	~Peon(void);

private:
	Peon(void); // default constructor
	std::string		_name;
};

std::ostream		&operator << (std::ostream &, Peon const &);

#endif
