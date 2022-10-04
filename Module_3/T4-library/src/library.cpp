#include "library.hpp"

#include <algorithm>
#include <iostream>

#include "book.hpp"
#include "customer.hpp"

using std::string;
using std::vector;

Library::Library(const string &name) : m_name(name) {}

const string &Library::GetName() const { return m_name; }

vector<Book> &Library::GetBooks() { return m_books; }

vector<Customer> &Library::GetCustomers() { return m_customers; }

const static Book empty_book{"", "", ""};

const Book Library::FindBookByName(const string &name) {
  for (const auto &book : GetBooks()) {
    if (book.GetName() == name) return book;
  }
  return empty_book;
}

template <typename C>
const vector<Book> Library::FindBooksBy(C condition) {
  vector<Book> books = GetBooks(), result;
  copy_if(begin(books), end(books), back_inserter(result), condition);
  return result;
}

const vector<Book> Library::FindBooksByAuthor(const string &author) {
  auto condition = [author](auto &b) { return b.GetAuthor() == author; };
  return FindBooksBy(condition);
}

const std::vector<Book> Library::FindAllLoanedBooks() {
  return FindBooksBy([](auto &b) { return b.GetStatus(); });
}

const static Customer empty_customer{"", ""};

const Customer Library::FindCustomer(const string &id) {
  for (const auto &customer : GetCustomers()) {
    if (customer.GetID() == id) return customer;
  }
  return empty_customer;
}
