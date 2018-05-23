/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:49:27 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/23 15:43:47 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include <iostream>

Squad::Squad() : _units(0), _marines(NULL) {
	return;
}

Squad::Squad(Squad const &Cc) {
	this->_units = Cc._units;

	t_list **dst = &this->_marines;
	t_list *tmp = Cc._marines;

	while (tmp) {
		*dst = new t_list;
		(*dst)->unit = tmp->unit->clone();
		dst = &(*dst)->next;
		tmp = tmp->next;
	}

	*dst = NULL;
	return;
}
	
Squad::~Squad() {
	t_list	*tmp;

	while (this->_marines)
	{
		tmp = _marines->next;
		if (this->_marines->unit) {
			delete this->_marines->unit;
			this->_marines->unit = NULL;
		}
		delete this->_marines;
		this->_marines = NULL;
		this->_marines = tmp;
	}
	return;
}

Squad &Squad::operator = (Squad const &Cc) {
	this->_units = Cc._units;

	t_list **dst = &this->_marines;
	t_list *tmp = Cc._marines;

	while (tmp) {
		if (*dst) {
			if ((*dst)->unit)
				delete (*dst)->unit;
		} else {
			*dst = new t_list;
		}
		(*dst)->unit = tmp->unit->clone();
		dst = &(*dst)->next;
		tmp = tmp->next;
	}
	if (*dst) {
		tmp = *dst;
		t_list *tmpNext;
		while (tmp) {
			if (tmp->unit)
				delete tmp->unit;
			tmpNext = tmp->next;
			delete tmp;
			tmp = tmpNext;
		}
		*dst = NULL;
	}
	return *this;
}

int 	Squad::push(ISpaceMarine *marine) {
	t_list **tmp = &(this->_marines);

	while (*tmp) {
		tmp = &(*tmp)->next;
	}
	*tmp = new t_list;
	(*tmp)->unit = marine;
	(*tmp)->next = NULL;
	this->_units++;
	return this->_units;
}

int 		Squad::getCount() const {
	return this->_units;
}

ISpaceMarine *Squad::getUnit(int n) const {
	t_list *tmp = this->_marines;
	int i = 0;

	while (tmp) {
		if (i == n)
			return tmp->unit;
		tmp = tmp->next;
		i++;
	}
	return NULL;
}

