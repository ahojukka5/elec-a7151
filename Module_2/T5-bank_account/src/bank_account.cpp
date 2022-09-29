#include "bank_account.hpp"

#include <iostream>

BankAccount::BankAccount(const std::string &owner,
                         const std::string &account_number, double balance)
    : owner_(owner), account_number_(account_number), balance_(balance){};

std::string BankAccount::GetOwner() const { return owner_; }

std::string BankAccount::GetNumber() const { return account_number_; }

double BankAccount::GetBalance() const { return balance_; }

void BankAccount::Deposit(double amount) { balance_ += amount; }

bool BankAccount::Withdraw(double amount) {
  bool has_money = amount <= balance_;
  if (has_money) balance_ -= amount;
  return has_money;
}

void BankAccount::Print() const {
  std::cout << "Account num: " << account_number_ << ", owned by: " << owner_
            << ", balance: " << balance_ << " eur." << std::endl;
}

bool Transfer(BankAccount &source_account, BankAccount &target_account,
              double amount) {
  bool has_money = amount <= source_account.GetBalance();
  if (has_money) {
    source_account.Withdraw(amount);
    target_account.Deposit(amount);
  }
  return has_money;
}
