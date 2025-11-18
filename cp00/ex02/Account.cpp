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
    std::cout << "[" << t << "]" << std::endl;
}

Account::Account(int initial_deposit)
{
    

}
