/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:08:11 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 17:14:48 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy() :
_nInterns(0), _nSigners(0), _nExecutors(0)
{
	Intern intern;

	for (int i = 0; i < OFFICE_BLOCKS_SIZE; i++) {
		_officeBlocks[i].setIntern(intern);
	}
	return;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &rfs) {
	*this = rfs;
	return;
}

CentralBureaucracy::~CentralBureaucracy() {
	return;
}

CentralBureaucracy &CentralBureaucracy::operator = (CentralBureaucracy const &rfs) {
	for (int i = 0; i < TARGET_QUEUE_SIZE; i++) {
		_targetsqueue[i] = rfs._targetsqueue[i];
	}
	return *this;
}

bool			CentralBureaucracy::feedSigner(Bureaucrat &rfs) {
	if (_nSigners < OFFICE_BLOCKS_SIZE) {
		_officeBlocks[_nSigners].setSigner(rfs);
		_nSigners++;
		return true;
	}
	std::cout << "No more places for signing bureaucrats" << std::endl;
	return false;
}

bool			CentralBureaucracy::feedExecutor(Bureaucrat &rfs) {
	if (_nExecutors < OFFICE_BLOCKS_SIZE) {
		_officeBlocks[_nExecutors].setExecutor(rfs);
		_nExecutors++;
		return true;
	}
	std::cout << "No more places for executing bureaucrats" << std::endl;
	return false;
}

bool			CentralBureaucracy::queueUp(std::string target) {
	for (int i=0; i < TARGET_QUEUE_SIZE; i++) {
		if (_targetsqueue[i] == "") {
			_targetsqueue[i] = target;
			_nInterns++;
			return true;
		}
	}
	std::cout << "Targets queue is full." << std::endl;
	return false;
}

bool			CentralBureaucracy::doBureaucracy(void) {
	if (_nInterns == 0) {
		std::cout << "Targets queue is empty." << std::endl;
		return false;
	}

	std::string form_list[3] = {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon" };

	for (int i=0; i < OFFICE_BLOCKS_SIZE; i++) {
		for (int k=0; k < TARGET_QUEUE_SIZE; k++) {
			if (_targetsqueue[k] != "") {
				try {
					_officeBlocks[i].doBureaucracy(form_list[rand() % 3], _targetsqueue[k]);
				} catch (std::exception &e) {
					std::cout << e.what() << std::endl;
				//	return false;
				}
				std::cout << "--- OFFICE ------------------------" << std::endl;
			}
		}
	}
	return true;

}
