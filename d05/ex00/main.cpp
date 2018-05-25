/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:20:43 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/25 10:24:59 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.cpp"

int			main(void)
{
	Bureaucrat		zero;
	Bureaucrat		hero(zero);
	Bureaucrat		pero(10);

	for (int i=0; i < MAX_GRADE + 1; i++) {
		zero.increaseGrade();
	}

	for (int i=0; i < 10; i++) {
		hero.decreaseGrade();
	}

	return 0;
}
