/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:30:40 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 12:46:35 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

class Pony
{
public:
	void			setStrenght(size_t strenght);
	void			setStamina(int stamina);
	void			setSpeed(float speed);
	void			ponyPunch(void);
	void			ponyRun(void);
	Pony(std::string name, size_t strenght, int stamina, float speed);
	~Pony();
private:
	std::string		_name;
	size_t			_strenght;
	int				_stamina;
	float			_speed;
};

void	ponyOnTheHeap(std::string name, size_t strenght,
						int stamina, float speed);
void	ponyOnTheStack(std::string name, size_t strenght,
						int stamina, float speed);

#endif
