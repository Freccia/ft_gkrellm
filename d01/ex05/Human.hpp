/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:54:17 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 19:36:42 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>
#include "Brain.hpp"

// note: http://duramecho.com/ComputerInformation/WhyHowCppConst.html

class Human{
public:
	Human();
	~Human();
	std::string		identify(void);
	Brain const		&getBrain(void) const;

private:
	Brain const		_brain;
};

#endif
