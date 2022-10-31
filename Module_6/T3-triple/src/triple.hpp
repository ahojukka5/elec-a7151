#pragma once

/**
 * @brief: The template class Triple is a container class, which holds three
 * values. All of the values can be of different type. All of the values should
 * be private.
 *
 * The constructor of the class takes three const references to values as a
 * parameter. The parameters are in order, in other words, after construction
 * the first parameter should be accessible through the public member function
 * First, the second parameter through the public member function Second, and
 * the third through the public member function Third.
 *
 * The default empty constructor should also work.
 *
 * The Triple class should also support the copy constructor, and assignment
 * operations.
 *
 * Public member functions:
 * ------------------------
 * The Triple class has three public member functions, which are used to
 * access the stored elements. All three should work with const instances
 * of Triple.
 *
 * Function: First
 * The function takes no parameters.
 * The function returns a const reference to the first value of the triple.
 *
 * Function: Second
 * The function takes no parameters.
 * The function returns a const reference to the second value of the triple.
 *
 * Function: Third
 * The function takes no parameters.
 * The function returns a const reference to the third value of the triple.
 */
template <typename TA, typename TB, typename TC>
class Triple {
 private:
  TA m_A;
  TB m_B;
  TC m_C;

 public:
  Triple() = default;

  Triple(const TA& A, const TB& B, const TC& C) : m_A(A), m_B(B), m_C(C) {}

  /*
  Triple(const Triple<TA, TB, TC>& T) {
    m_A = T.First();
    m_B = T.Second();
    m_C = T.Third();
  }

  Triple<TA, TB, TC>& operator=(const Triple<TA, TB, TC>& T) {
    m_A = T.First();
    m_B = T.Second();
    m_C = T.Third();
    return *this;
  }
  */

  const TA& First() const { return m_A; }

  const TB& Second() const { return m_B; }

  const TC& Third() const { return m_C; }
};

/* Non-member functions:
 * ---------------------
 * Function: IsHomogenous
 * The function is a non-member function that takes a Triple as a parameter.
 * The function returns a boolean value indicating whether the triple is
 * homogenous or not. A triple is homogenous if all of its three values are of
 * the same type.
 * Hint: specialisation can help you here.
 */
template <typename T>
bool IsHomogenous(const Triple<T, T, T>&) {
  return true;
}
template <typename A, typename B, typename C>
bool IsHomogenous(const Triple<A, B, C>&) {
  return false;
}

/* Operator overloads:
 * -------------------
 * The triple class should support the following operators:
 *
 * Assignment operator, =
 * The default functionality should do here.
 *
 * Equality operator, ==
 * You can assume that all the values in the triple can be compared by the
 * == -operator. Two triples are equal if the corresponding values in both
 * of the triples are equal.
 *
 * Inequality operator, !=
 * You can assume that all the values in the triple can be compared by the
 * != -operator. Two triples are inequal if even one corresponding value in
 * the triples is different.
 *
 * The output stream operator, <<
 * You can assume that all the values in the triple support the << -operator.
 * The triple should be printed to the output stream in the following format:
[<first value>, <second value>, <third value>]
 * Note that there is NO new line at the end of the output.
 */

template <typename TA, typename TB, typename TC>
bool operator==(const Triple<TA, TB, TC>& T1, const Triple<TA, TB, TC>& T2) {
  return (T1.First() == T2.First() && T1.Second() == T2.Second() &&
          T1.Third() == T2.Third());
}

template <typename TA, typename TB, typename TC>
bool operator!=(const Triple<TA, TB, TC>& T1, const Triple<TA, TB, TC>& T2) {
  return !(T1 == T2);
}

template <typename TA, typename TB, typename TC>
std::ostream& operator<<(std::ostream& os, const Triple<TA, TB, TC>& T) {
  os << "[" << T.First() << ", " << T.Second() << ", " << T.Third() << "]";
  return os;
}
