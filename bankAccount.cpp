#include "bankAccount.h"
#include <iostream>
#include  <string>

using namespace std;
bankAccount::bankAccount(){
  balance = 0.00;
  
}

bankAccount::bankAccount(double amount){
  balance = amount;
}

bankAccount::~bankAccount(){

}

double bankAccount::withdraw(double amount){
  if(balance - amount >= 0){
    balance = balance - amount;
    return balance;
  }
  else{
    return balance;
  }
}

double bankAccount::deposit(double amount){
  balance = balance + amount;
  return balance;
}

double bankAccount::getBalance() const{
  return balance;
}
