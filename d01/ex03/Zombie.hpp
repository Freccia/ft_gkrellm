/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:42:31 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 15:14:20 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
public:
	Zombie();
	~Zombie();
	void			announce();
	std::string		getName(void);
	void			setName(std::string name);
	std::string		getType(void);
	void			setType(std::string type);
private:
	std::string		_type;
	std::string		_name;
};

#endif
