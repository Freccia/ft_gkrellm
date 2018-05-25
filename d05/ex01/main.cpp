/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:20:43 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/25 13:36:57 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
 * clang++ -Wall -Wextra -Werror main.cpp  Bureaucrat.cpp
*/

int			main(void)
{
	Bureaucrat		zero;
	Bureaucrat		hero(zero);
	Bureaucrat		pero("Kcrat", 10);
	Form			formA;
	Form			formB("F_BAA_0001", false, 100, 20);

	std::cout << pero << std::endl;

	std::cout << formA << std::endl;
	std::cout << formB << std::endl;

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
