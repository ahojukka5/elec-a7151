#include "customer.hpp"

#include <algorithm>
#include <iostream>

using std::string;
using std::vector;

Customer::Customer(const string &name, const string &id)
    : m_name(name), m_id(id) {}

const string &Customer::GetName() const { return m_name; }

const string &Customer::GetID() const { return m_id; }

int Customer::GetLoanAmount() const { return m_books.size(); }

const vector<Book> &Customer::GetLoans() const { return m_books; }

bool Customer::LoanBook(Book &book) {
  auto status = book.Loan();
  m_books.push_back(book);  // creates copy
  return status;
}

void Customer::ReturnBook(Book &book) {
  auto book_it = std::remove(m_books.begin(), m_books.end(), book);
  m_books.erase(book_it, m_books.end());
  book.Restore();
}

void Customer::Print() const {
  std::cout << "Customer: " << m_name << ", " << m_id << ", has "
            << GetLoanAmount() << " books on loan:" << std::endl;
  for (auto book : GetLoans()) {
    std::cout << "- ";
    book.Print();
  }
}
