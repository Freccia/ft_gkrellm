/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:56:10 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 18:07:26 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <string>
# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
private:
	AMateria*	_inventory[4];
	int			_amount;

public:
	MateriaSource(void);
	MateriaSource(MateriaSource const & Cc);
	~MateriaSource(void);

	MateriaSource & operator = (MateriaSource const & Cc);

	void			learnMateria(AMateria*);
	AMateria*		createMateria(std::string const & type);

};

#endif
