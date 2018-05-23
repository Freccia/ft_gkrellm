/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:55:38 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 14:46:26 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

class Enemy {
protected:
	Enemy();

	int			_hp;
	std::string	_type;

public:
	Enemy(int hp, std::string const & type);
	Enemy(Enemy const &Cc);
	virtual ~Enemy();

	Enemy 	&operator = (Enemy const &Cc);

	std::string		getType() const;
	int 			getHP() const;
	virtual void 	takeDamage(int);
};

#endif
