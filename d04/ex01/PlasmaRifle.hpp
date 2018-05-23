/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:43:19 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 13:47:16 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
private:
public:
	PlasmaRifle();
	PlasmaRifle(PlasmaRifle const &Cc);
	virtual ~PlasmaRifle();

	PlasmaRifle 	&operator = (PlasmaRifle const &Cc);
	virtual void 	attack() const;
};


#endif
