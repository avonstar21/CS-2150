#ifndef bankAccount_H
#define bankAccount_H

#include <iostream>
#include <string>
using namespace std;
class bankAccount {
public:
  //double balance;
  bankAccount();
  bankAccount(double amount);
  ~bankAccount();
  double withdraw(double amount);
  double deposit(double amount);
  double getBalance() const;

 private:
  double balance;
  
};

#endif 
