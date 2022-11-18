/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:39:00 by jmabel            #+#    #+#             */
/*   Updated: 2022/11/18 19:26:11 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::getNbAccounts( void ) { return _nbAccounts; }
int	Account::getTotalAmount( void ) { return _totalAmount; }
int	Account::getNbDeposits( void ) { return _totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts <<
				";total:" << _totalAmount <<
				";deposits:" << _totalNbDeposits <<
				";withdrawals:" << _totalNbWithdrawals << std::endl;
}


Account::Account( int initial_deposit )
			:_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex <<
			";amount:" << initial_deposit <<
			";created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex <<
			";amount:" << _amount <<
			";closed" << std::endl;	
};

void	Account::makeDeposit( int deposit )
{

	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex <<
				";p_amount:" << _amount <<
				";deposit:" << deposit;
	_amount += deposit;
	std:: cout << ";amount:" << _amount <<
			";nb_deposits:" << _nbDeposits << std::endl;
	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex <<
			";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << ";withdrawal:" << withdrawal <<
				";amount:" << _amount <<
				";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
}

int	Account::checkAmount( void ) const { return _amount;}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex <<
			";amount:" << _amount <<
			";deposits:" << _nbDeposits <<
			";withdrawals:" << _nbWithdrawals << std::endl;	
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	const time_t tm = time(nullptr);
	char buffer[80];
	strftime(buffer, 80, "%Y%m%d_%H%M%S", localtime(&tm));
	std::cout << "[" << buffer << "] ";
}

Account::Account( void )
			:_amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex <<
			";amount:" << _amount <<
			";created" << std::endl;
	_nbAccounts++;
}