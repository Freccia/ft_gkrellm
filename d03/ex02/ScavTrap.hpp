/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:13:46 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 11:59:03 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string);
	ScavTrap(ScavTrap const &);
	~ScavTrap();

	/*	Operators	*/
	ScavTrap		&operator = (ScavTrap const &);

	void		challengeNewcomer(std::string const &);

};

#endif
