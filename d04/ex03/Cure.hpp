/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:49:37 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 19:21:38 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria {
private:
public:
	Cure(void);
	Cure(Cure const & src);
	~Cure(void);

	Cure & operator = (Cure const & Cc);

	AMateria*		clone() const;
	using			AMateria::use;
	void			use(ICharacter& target);
};

#endif
