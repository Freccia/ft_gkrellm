/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:45:45 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 13:47:35 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
private:
public:
	PowerFist();
	PowerFist(PowerFist const &Cc);
	virtual ~PowerFist();

	PowerFist 	&operator = (PowerFist const &Cc);
	virtual void 	attack() const;
};


#endif
