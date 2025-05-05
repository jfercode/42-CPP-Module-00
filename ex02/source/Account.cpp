/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 < jaferna2@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:47:34 by jaferna2          #+#    #+#             */
/*   Updated: 2025/05/05 17:09:26 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << initial_deposit
			  << ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;	
}

int		Account::getNbAccounts( void )
{
	// std::cout << "getNbAccounts" << std::endl;
	return (_nbAccounts);
}

int 	Account::getTotalAmount( void )
{
	// std::cout << "getTotalAmount" << std::endl;
	return (_totalAmount);
}

int 	Account::getNbDeposits( void )
{
	// std::cout << "getNbDeposits" << std::endl;
	return (_totalNbDeposits);
}

int 	Account::getNbWithdrawals( void )
{
	// std::cout << "getNbWithdrawals" << std::endl;
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";amount:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_amount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout << ";refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals
				  << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	// std::cout << "checkAmount" << std::endl;
	return (_totalAmount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

void 	Account::_displayTimestamp( void )
{
	std::time_t t;
	std::tm *tm;

	t = std::time(NULL);
	tm = std::localtime(&t);
	std::cout << "["
			  << std::setfill('0') << std::setw(4) << tm->tm_year + 1900
			  << std::setw(2) << tm->tm_mon + 1
			  << std::setw(2) << tm->tm_mday << "_"
			  << std::setw(2) << tm->tm_hour
			  << std::setw(2) << tm->tm_min
			  << std::setw(2) << tm->tm_sec
			  << "] ";
}
