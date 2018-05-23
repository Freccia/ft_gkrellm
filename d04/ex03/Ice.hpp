/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:06:11 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 19:21:14 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria {
private:

public:
	Ice(void);
	//Ice(std::string const & type);
	Ice(Ice const & Cc);
	~Ice(void);

	Ice &operator = (Ice const & Cc);

	AMateria *			clone() const;
	using		AMateria::use;
	void				use(ICharacter& target);
};

#endif
