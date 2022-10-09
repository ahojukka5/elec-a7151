#ifndef AALTO_ELEC_CPP_AVIARY_CLASS
#define AALTO_ELEC_CPP_AVIARY_CLASS

#include <iostream>

#include "bird.hpp"

/**
 * \brief Class for storing different birds and interacting with them.
 *
 * If somebody tries to copy an instance of this class, the compilation must
 * fail i.e. disallow copying
 */
class Aviary {
 public:
  Aviary() {}

  Aviary(const Aviary&) = delete;

  /**
   * \brief method Add adds the given bird to the aviary.
   *
   * If the pointer is NULL, std::logic_error is thrown. When a bird is added
   * to the aviary, it's ownership is transferred. When the aviary is
   * destroyed, all the birds are destroyed too.
   *
   * \param bird A pointer to a bird object.
   * \return nothing
   */
  void Add(Bird* bird);

  /**
   * \brief method SpeakAll calls the Speak method with the given
   * parameter on all birds in the aviary.
   *
   * Does not modify the object, thus it should be const.
   *
   * \param os A reference to the desired ostream.
   * \return nothing
   */
  void SpeakAll(std::ostream& os) const;

  /**
   * \brief method Size returns the number of birds in the aviary.
   *
   * Method takes no arguments and does not modify the object, thus it should
   * be const.
   *
   * \return How many birds there are in the aviary.
   */
  size_t Size() const;

  /**
   * \brief non-const version of the indexing operator [].
   *
   * If the index is out of bounds, std::out_of_range is thrown.
   *
   * \param idx desired index as an size_t integer value.
   * \return A pointer to the bird (Bird*) at the index given as an argument
   */
  Bird* operator[](size_t idx);

  /**
   * \brief const version of the indexing operator [].
   *
   * If the index is out of bounds, std::out_of_range is thrown.
   *
   * \param idx desired index as an size_t integer value.
   * \return A pointer to the bird (const Bird*) at the index given as an
   * argument
   */
  const Bird* operator[](size_t idx) const;

  /**
   * \brief destructor. Takes no parameters.
   *
   * \return nothing
   */
  ~Aviary();

 private:
  std::vector<Bird*> m_birds;
};

#endif
