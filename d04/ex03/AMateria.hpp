/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:31:29 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 19:23:42 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
private:
	unsigned int	xp_;
	std::string		_type;

public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(AMateria const & Cc);
	virtual ~AMateria(void);

	AMateria &operator = (AMateria const &Cc);

	std::string const &	getType() const; //Returns the materia type
	unsigned int		getXP() const; //Returns the Materia s XP
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

	void				setXP(unsigned int xp);
};

#endif
