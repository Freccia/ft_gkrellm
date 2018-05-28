/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:45:34 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/28 17:15:19 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_HPP
#define CENTRALBUREAUCRACY_HPP

#include <iostream>
#include "Intern.hpp"
#include "OfficeBlock.hpp"

#define OFFICE_BLOCKS_SIZE		20
#define TARGET_QUEUE_SIZE		60

class CentralBureaucracy {
private:
	OfficeBlock		_officeBlocks[OFFICE_BLOCKS_SIZE];
	std::string		_targetsqueue[TARGET_QUEUE_SIZE];
	unsigned int	_nInterns;
	unsigned int	_nSigners;
	unsigned int	_nExecutors;

public:
	CentralBureaucracy(void);
	~CentralBureaucracy(void);
	CentralBureaucracy(CentralBureaucracy const &Cc);

	bool		feedSigner(Bureaucrat &signer);
	bool		feedExecutor(Bureaucrat &signer);
	bool		doBureaucracy(void);
	bool		queueUp(std::string target);

	CentralBureaucracy &operator = (CentralBureaucracy const &Cc);
};

#endif
