/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:20:43 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/25 12:59:06 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
 * clang++ -Wall -Wextra -Werror main.cpp  Bureaucrat.cpp
*/

int			main(void)
{
	Bureaucrat		zero;
	Bureaucrat		hero(zero);
	Bureaucrat		pero("Kcrat", 10);

	std::cout << zero << std::endl;
	std::cout << hero << std::endl;
	std::cout << pero << std::endl;

	for (int i=0; i < 150 + 1; i++) {
		zero.increaseGrade();
	}

	/*
	for (int i=0; i < 10; i++) {
		hero.decreaseGrade();
	}
	*/

	return 0;
}
