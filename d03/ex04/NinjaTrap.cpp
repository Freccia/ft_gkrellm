/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:55:25 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 15:19:04 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"


/*		Constructors - Desctructors		*/

NinjaTrap::NinjaTrap() :
	ClapTrap("Naruto", 1, 60, 60, 120, 120, 60, 5, 0)
{
	std::cout << "A stealthy N1NJ4-TP named " << _name
	<< " is being created !" << std::endl;
	return;
}

NinjaTrap::NinjaTrap(std::string name) :
	ClapTrap(name, 1, 60, 60, 120, 120, 60, 5, 0)
{
	std::cout << "A stealthy N1NJ4-TP named " << _name
	<< " is being created !" << std::endl;
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const &Cc) :
	ClapTrap(Cc)
{
	//*this = Cc;
	std::cout << "A stealthy N1NJ4-TP named " << _name
	<< " is being cloned !" << std::endl;
	return;
}

NinjaTrap::~NinjaTrap() {
	std::cout << "The stealthy N1NJ4-TP named " << _name
	<< " is destructed !" << std::endl;
	return;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &Cc) {
	ClapTrap::operator = (Cc);
	return *this;
}


/*		Member Functions		*/

void		NinjaTrap::ninjaShoebox(ClapTrap const &target)
{
	(void)target;
	std::cout << _name << " launches a shoebox to a ClapTrap!"  << std::endl;
}

void		NinjaTrap::ninjaShoebox(FragTrap const &target)
{
	(void)target;
	std::cout << _name << " launches a shoebox to a FragTrap!"  << std::endl;
}

void		NinjaTrap::ninjaShoebox(ScavTrap const &target)
{
	(void)target;
	std::cout << _name << " launches a shoebox to a ScavTrap!"  << std::endl;
}

void		NinjaTrap::ninjaShoebox(NinjaTrap const &target)
{
	(void)target;
	std::cout << _name << " launches a shoebox to a NinjaTrap!"  << std::endl;
}
