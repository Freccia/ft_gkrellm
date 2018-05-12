/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:27:02 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/11 12:29:20 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

/*
 * Available actions:
 *		meleeAttack
 *		rangedAttack
 *		intimidatingShout
*/

int		main(void)
{
	Human	h;

	h.action("intimidatingShout", "wild lion");
	h.action("meleeAttack", "Kraken");
	h.action("rangedAttack", "beasts");
	return 0;
}
