/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:23:15 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 19:14:42 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
private:
	Character(void);

	std::string			_name;
	AMateria			*_inventory[4];
	unsigned int		_amount;

public:
	Character(Character const & src);
	Character(std::string const & name);
	~Character(void);

	Character & operator = (Character const & rhs);

	std::string const &		getName() const;
	void					equip(AMateria* m);
	void					unequip(int idx);
	void					use(int idx, ICharacter& target);

};

#endif
