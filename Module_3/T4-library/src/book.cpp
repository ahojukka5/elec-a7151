#include "book.hpp"

#include <ctime>
#include <iostream>

Book::Book(const std::string &name, const std::string &author,
           const std::string &isbn, bool loaned, Date due_date)
    : name_(name),
      author_(author),
      isbn_(isbn),
      loaned_(loaned),
      due_date_(due_date) {}

bool Book::operator==(const Book &rhs) {
  return (name_ == rhs.name_) && (author_ == rhs.author_) &&
         (isbn_ == rhs.isbn_);
}

const std::string &Book::GetName() const { return name_; }

const std::string &Book::GetAuthor() const { return author_; }

const std::string &Book::GetISBN() const { return isbn_; }

bool Book::GetStatus() const { return loaned_; }

const Date &Book::GetDueDate() const { return due_date_; }

bool Book::Loan() {
  if (loaned_) return false;
  loaned_ = true;
  auto now = Date::Today();
  due_date_ = {now.day, now.month + 1, now.year};
  return GetStatus();
}

void Book::Restore() {
  due_date_ = {0, 0, 0};
  loaned_ = false;
}

void Book::Print() const {
  // auto [d, m, y] = due_date_;
  std::cout << "Book: " << name_ << ", author: " << author_
            << ", ISBN: " << isbn_ << ", loaned "
            << (loaned_ ? "true" : "false") << ", due date: " << due_date_.day
            << "." << due_date_.month << "." << due_date_.year << std::endl;
}
