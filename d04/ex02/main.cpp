/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:36:05 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 15:44:13 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

int main()
{
	ISpaceMarine*		bob = new TacticalMarine;
	ISpaceMarine*		jim = new AssaultTerminator;
	TacticalMarine*		fred = new TacticalMarine;
	ISpaceMarine*		clone = new TacticalMarine (*fred);
	ISquad*			vlc = new Squad;
	Squad*			vlc2 = new Squad;
	Squad*			vlc3 = new Squad (*vlc2);

	vlc->push(bob);
	vlc->push(jim);
	vlc->push(fred);
	vlc->push(clone);
	vlc3->push(bob);

	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
/*
	delete vlc3; // this will segfault (with `delete vlc`)
	delete vlc2;
	delete bob;
	delete jim;
	delete fred;
	delete clone;
*/
	return 0;
}
