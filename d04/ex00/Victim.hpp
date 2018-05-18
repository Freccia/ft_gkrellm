/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:40:13 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/18 18:19:30 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim {
public:
	Victim(std::string name);
	~Victim(void);
	std::string		introduce(void) const;
	virtual void	getPolymorphed(void) const;

protected:
	Victim(void); // default constructor
	std::string		_name;
};

std::ostream		&operator << (std::ostream &, Victim const &);

#endif
