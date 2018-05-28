/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:20:43 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/25 18:29:35 by lfabbro          ###   ########.fr       */
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
	Bureaucrat		hero("Kcrat", 20);
	Form			formA;
	Form			formB("F_BAA_0001", false, 100, 20);

//	std::cout << hero << std::endl;

	std::cout << formA << std::endl;
	std::cout << formB << std::endl;

	formA.beSigned(zero);
	formB.beSigned(hero);

	Form			exceptionalForm("NastyNasty", true, 200, -1);

	/*
	for (int i=0; i < 150 + 1; i++) {
		zero.increaseGrade();
	}
	*/

	/*
	for (int i=0; i < 10; i++) {
		hero.decreaseGrade();
	}
	*/

	return 0;
}
