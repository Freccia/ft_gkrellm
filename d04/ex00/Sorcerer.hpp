/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:40:13 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/18 14:22:11 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer {
public:
	Sorcerer(std::string name, std::string title);
	~Sorcerer(void);
	std::string		introduce(void) const;
	void			polymorph(Victim const &);

private:
	Sorcerer(void); // default constructor
	std::string		_name;
	std::string		_title;
};

std::ostream		&operator << (std::ostream &, Sorcerer const &);

#endif
