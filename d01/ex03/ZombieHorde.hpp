/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:39:52 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 16:22:03 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include <iostream>
#include <cstdlib>
#include "Zombie.hpp"

class ZombieHorde {
public:
	ZombieHorde(int n);
	~ZombieHorde();
	void			setZombieHordeType(std::string type);
	static int		getNbHordes(void);

private:
	static int		_nbHordes;
	int				_size;
	Zombie*			_horde;
	std::string		_zombieHordeType;
	void			_randomName(Zombie* zombie);
};

#endif
