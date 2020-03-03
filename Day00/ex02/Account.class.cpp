/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accounts.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:56:07 by spoole            #+#    #+#             */
/*   Updated: 2020/01/13 20:56:08 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <string>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    int test = _nbAccounts;
    return (test);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int     Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int     Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void    Account::_displayTimestamp(void)
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%Y%m%d_%H%M%S",timeinfo);
    std::string str(buffer);
    std::cout << "[" << str << "]";;
}

Account::Account(int init_deposit)
{
    _accountIndex = getNbAccounts();
    _amount = init_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += init_deposit;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << init_deposit << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void    Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawls:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    int p_amnt = _amount;
    _amount += deposit;
    _nbDeposits++;

    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << p_amnt << ";deposit:" << deposit << ";amount:" << checkAmount() << ";nb_debosits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    int p_amnt = _amount;
    if (withdrawal > _amount)
    {
        std::cout << " index:" << _accountIndex << ";p_amount:" << p_amnt << ";withdrawals:refused" << std::endl; 
        return (false);
    }
    else
    {
        _amount -= withdrawal;
        _nbWithdrawals++;

        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << " index:" << _accountIndex << ";p_amount:" << p_amnt << ";withdrawals:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount" << checkAmount() << ";deposits:" << _nbDeposits << ";withdrawls:" << _nbWithdrawals << std::endl;
}
