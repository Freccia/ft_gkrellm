/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:58:20 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 14:00:02 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPREMUTANT_HPP
# define SUPREMUTANT_HPP

#include <iostream>
#include "Enemy.hpp"

class SuperMutant : public Enemy {
public:
	SuperMutant();
	SuperMutant(SuperMutant const &Cc);
	~SuperMutant();

	SuperMutant 	&operator = (SuperMutant const &Cc);

	virtual	void	takeDamage(int p);
};

#endif
