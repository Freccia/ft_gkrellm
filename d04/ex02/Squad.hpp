/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:39:50 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 15:04:54 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad {
private:
	typedef struct		s_list {
		ISpaceMarine	*unit;
		s_list			*next;
	}					t_list;

	int		_units;
	t_list	*_marines;

public:
	Squad();
	Squad(Squad const &Cc);
	virtual ~Squad();

	Squad &operator = (Squad const &Cc);

	virtual int getCount() const;
	virtual ISpaceMarine* getUnit(int) const;
	virtual int push(ISpaceMarine*);
};

#endif
