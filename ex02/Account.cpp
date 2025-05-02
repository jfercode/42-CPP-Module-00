/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 < jaferna2@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:47:34 by jaferna2          #+#    #+#             */
/*   Updated: 2025/05/02 13:43:19 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

Account::Account( int initial_deposit )
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount;" << _amount
			  << "closed" << std::endl;	
}

int		Account::getNbAccounts( void )
{
	std::cout << "getNbAccounts" << std::endl;
	return (_nbAccounts);
}

int 	Account::getTotalAmount( void )
{
	std::cout << "getTotalAmount" << std::endl;
	return (_totalAmount);
}

int 	Account::getNbDeposits( void )
{
	std::cout << "getNbDeposits" << std::endl;
	return (_totalNbDeposits);
}

int 	Account::getNbWithdrawals( void )
{
	std::cout << "getNbWithdrawals" << std::endl;
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	// TO DO 
}

void	Account::makeDeposit( int deposit )
{
	// TO DO 
}

bool	Account::makeWithdrawal( int withdrawal )
{
	// TO DO
}

int		Account::checkAmount( void ) const
{
	std::cout << "checkAmount" << std::endl;
	return (_totalAmount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _totalAmount
			  << ";deposits" << _nbDeposits
			  << ";withdrawals" << _nbWithdrawals
			  << std::endl;
}

void 	Account::_displayTimestamp( void )
{
	std::time_t t;
	std::tm *tm;

	t = std::time(nullptr);
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
