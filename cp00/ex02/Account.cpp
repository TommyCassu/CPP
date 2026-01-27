#include "Account.hpp"
#include <ctime>
#include <iostream>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void    Account::_displayTimestamp(void)
{
    std::time_t t_time = std::time(NULL);
    std::tm* now = std::localtime(&t_time);
    char t[20];
    std::strftime(t, 20, "%Y%m%d_%H%M%S", now);
    std::cout << "[" << t << "] ";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout   << "index:"
                << _accountIndex
                << ";amount:"
                << _amount
                << ";created"
                << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout   << "index:"
                << _accountIndex
                << ";amount:"
                << _amount
                << ";closed"
                << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout   << "index:"
                << _accountIndex
                << ";p_amount:"
                << _amount
                << ";deposit:"
                << deposit
                << ";amount:"
                << _amount + deposit
                << ";nb_deposits:"
                << _nbDeposits + 1
                << std::endl;

    _amount += deposit;
    _nbDeposits++;

    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool    Account::makeWithdrawal(int withdrawal)
{
     _displayTimestamp();
    std::cout   << "index:"
                << _accountIndex
                << ";p_amount:"
                << _amount
                << ";withdrawal:";
    if (_amount - withdrawal >= 0)
    {
        std::cout   << withdrawal
                    << ";amount:"
                    << _amount - withdrawal
                    << ";nb_withdrawals:"
                    << _nbWithdrawals + 1
                    << std::endl;
        
        _amount -= withdrawal;
        _nbWithdrawals++;

        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        
    }
    else
    {
        std::cout   << "refused"
                    << std::endl;
        return (false);
    }
    return (true);    
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout   << "index:"
                << _accountIndex
                << ";amount:"
                << _amount
                << ";deposits:"
                << _nbDeposits
                << ";withdrawals:"
                << _nbWithdrawals
                << std::endl;
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout   << "accounts:"
                << _nbAccounts
                <<  ";total:"
                << _totalAmount
                <<  ";deposits:"
                << _totalNbDeposits
                <<  ";withdrawals:"
                << _totalNbWithdrawals
                << std::endl;
}

int Account::checkAmount(void) const
{
    return (_amount);
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}
