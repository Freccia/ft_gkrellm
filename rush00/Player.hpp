/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:10:09 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/30 18:02:25 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

struct s_position {
	int		x;
	int		y;
};

class Player {
private:
	unsigned int		_lifes;
	std::string			_shape;
	s_position			_pos;

public:
	Player(void);
	~Player(void);
	Player(Player const &Cc);

	Player				&operator = (Player const &Cc);

	unsigned int		getLifes(void) const;
	std::string			getShape(void) const;
	int					getShapeSize(void) const;
	int					getPosX(void) const;
	int					getPosY(void) const;
	
	bool				setLifes(int lifes);
	bool				setShape(std::string shape);
	bool				setPosition(int x, int y);
};

#endif
