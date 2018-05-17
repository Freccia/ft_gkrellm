/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:13:46 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/17 15:41:58 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string);
	FragTrap(FragTrap const &);
	~FragTrap();

	/*	Operators	*/
	FragTrap	&operator = (FragTrap const &);

	void		vaulthunter_dot_exe(std::string const & target);

};

#endif
