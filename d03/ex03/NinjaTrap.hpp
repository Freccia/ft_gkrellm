/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:51:57 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 15:07:19 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {
public:
	NinjaTrap();
	NinjaTrap(std::string);
	NinjaTrap(NinjaTrap const &);
	~NinjaTrap();

	/*	Operators	*/
	NinjaTrap		&operator = (NinjaTrap const &);

	void		ninjaShoebox(std::string const &);
	void		ninjaShoebox(ClapTrap const &);
	void		ninjaShoebox(FragTrap const &);
	void		ninjaShoebox(ScavTrap const &);
	void		ninjaShoebox(NinjaTrap const &);

};

#endif
