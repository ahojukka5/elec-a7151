#ifndef AALTO_ELEC_CPP_TRANSCRIPT_CLASS
#define AALTO_ELEC_CPP_TRANSCRIPT_CLASS

#include <list>
#include <string>
#include <utility>

/**
 * @brief structured type for storing transcripts
 */
struct Transcript {
  /*@{*/
  std::string name;       /**< Name of the transcript */
  std::string student_id; /**< Student ID as a std::string */
  std::list<std::pair<std::string, size_t>>
      grades; /**< List of (course, grade) pairs */
              /*@}*/
};

/* TODO: class TranscriptRegistry
 * ------------
 * Description:
 * A class for storing and interfacing with transcripts (type Transcript).
 * ------------
 * Functions:
 *
 * Add: the function returns nothing and takes a const reference to Transcript
 * as a parameter. Adds the transcript to the registry.
 *
 * RemoveById: takes takes a student id as a const reference to string as
 * parameter and returns nothing. Removes all transcripts with the given student
 * id.
 *
 * FindTranscript: takes a student id as a const reference to string as a
 * parameter and returns an iterator to the first transcript with the given
 * student id.
 *
 * FindCourseResults: takes a course name as a const reference to string as a
 * parameter and returns a list of pairs of student ids and course grades for
 * the given course from the registry.
 *
 * GetTranscripts: takes no parameters and returns a container that supports
 * begin and end functions containing all the transcripts in the registry, in
 * the order they were added.
 * ------------
 * Other:
 * As like always, any function that doesn't directly or indirectly modify the
 * object should by const.
 *
 * Hint: due to the GetTranscripts function it would be beneficial to use e.g.
 * list or vector to store the transcripts.
 */

class TranscriptRegistry {
 private:
  std::list<Transcript> m_transcripts;

 public:
  void Add(const Transcript &transcript);

  void RemoveById(const std::string &student_id);

  std::list<Transcript>::const_iterator FindTranscript(
      const std::string &student_id) const;

  std::list<std::pair<std::string, size_t>> FindCourseResults(
      const std::string &name) const;

  const std::list<Transcript> GetTranscripts() const;
};

#endif
