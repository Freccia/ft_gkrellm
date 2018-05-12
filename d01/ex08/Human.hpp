/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:06:21 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/11 12:31:36 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <iostream>

class Human {
private:
	void		meleeAttack(std::string const & target);
	void		rangedAttack(std::string const & target);
	void		intimidatingShout(std::string const & target);

	struct		actionFunc {
		std::string		name;
		void			(Human::*func)(std::string const & target);
	};
	actionFunc	actions[3];

public:
	Human();
	~Human();
	void		action(std::string const & action_name, std::string const & target);
};

#endif
