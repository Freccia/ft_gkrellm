/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:03:38 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/09 11:21:32 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.class.hpp"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account(void){
	return;
}

Account::~Account(void){
	return;
}

Account::Account( int initial_deposit ):
	_accountIndex(Account::_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index: " << this->_accountIndex;
	std::cout << ";amount:" << checkAmount();
	std::cout << ";created" << std::endl;
}

void	Account::makeDeposit( int deposit ){
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	this->_nbDeposits++;
	std::cout << "index:"<< this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:"<< this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > checkAmount())
	{
		std::cout << "refused;" << std::endl;
		return false;
	}
	Account::_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return true;
}

void	Account::_displayTimestamp( void ){
	std::time_t		t = std::time(0);
	std::tm			tm = *std::localtime(&t);
	char			buf[64];
	//std::cout << std::put_time(&tm, "[%Y%m%d_%H%M%S] ");
	if (strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", &tm) > 0)
		std::cout << buf;
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

int		Account::getNbAccounts( void ){
	return Account::_nbAccounts;
}

int		Account::getTotalAmount( void ){
	return Account::_totalAmount;
}

int		Account::getNbDeposits( void ){
	return Account::_totalNbDeposits;
}

int		Account::getNbWithdrawals( void ){
	return Account::_totalNbWithdrawals;
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex;
	std::cout << ";amount:"<< this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}
