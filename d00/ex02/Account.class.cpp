/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:03:38 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/08 15:46:53 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.class.hpp"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalDeposits = 0;
int		Account::_totalWithdrawals = 0;

Account::Account(void){
	return;
}

Account::~Account(void){
	return;
}

Account::Account( int initial_deposit ):
_accountNumber(Account::_nbAccounts),
_amount(initial_deposit),
_nbAccountsDeposits(0),
_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_Timestamp();
	std::cout << "::number: " << this->_accountNumber;
	std::cout << ";total_amount:" getAmount();
	std::cout << ";CREATED::" << std::endl;
}

void	Account::Deposit( int deposit ){
	Account::_totalDeposits;
	Account::_totalAmount += deposit;
	Account::_Timestamp();
	this->_nbDeposits++;
	std::cout << "::number: "<< this->_accountNumber;
	std::cout << ";total_amount: " << this->amount;
	this->_amount += deposit;
	std::cout << ";deposit: " << deposit << ";DEPOSIT::";
	std::cout << ";nb_deposits: "<< this->_nbDeposits;
	std::cout << ";new_total_amount: " << this->amount;
	std::cout << ";SYNC::" << std::endl;
}

bool	Account::Withdrawal( int withdrawal ){
	Account::_Timestamp();
	std::cout << "::number" << this->_accountNumber;
	std::cout << ";total_amount: " << this->amount;
	if (withdrawal > getAmount())
	{
		std::cout << "transaction refused;WITHDRAWAL::" << std::endl;
		return false;
	}
	Account::_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->amount -= withdrawal;
	std::cout << ";new_total_amount: " << this->amount;
	std::cout << ";nb_withdrawals: " << this->_nbWithdrawals;
	std::cout << ";WITHDRAWAL::" << std::endl;
	return true;
}

void	Account::_Timestamp( void ){
	std::time_t result = std::time(nullptr);
	//std::cout << "[" << result << "]" << std::endl;
	std::cout << "[" << std::asctime(std::localtime(&result)) << "]" << std::endl;
}

int		Account::getAmount( void ){
	return this->_amount;
}

int		Account::getNbAccounts( void ){
	return Account::_nbAccounts;
}

int		Account::getTotalAmount( void ){
	return Account::_totalAmount;
}

int		Account::getNbDeposits( void ){
	return Account::_totalDeposits;
}

int		Account::getNbWithdrawals( void ){
	return Account::_totalWithdrawals;
}

void	Account::Status( void ){
	Account::_Timestamp();
	std::cout << "::number: "<< this->_accountNumber;
	std::cout << ";total_amount: "<< this->_amount;
	std::cout << ";last_deposit: " << this->_lastDeposit;
	std::cout << ";last_deposit_amount: " << this->_lastDepositAmount;
	std::cout << ";last_withdrawal: " << this->_lastWithdrawal;
	std::cout << ";last_withdrawal_amount: " << this->_lastWithdrawalAmount;
	std::cout << ";nb_withdrawals: " << this->_nbWithdrawals;
	std::cout << ";STATUS::" << std::endl;
}

void	Account::AccountsInfo( void ){
	Account::_Timestamp();
	Account::getNbAccounts();
	Account::getTotalAmount();
	Account::getNbDeposits();
	Account::getNbWithdrawals();
}
