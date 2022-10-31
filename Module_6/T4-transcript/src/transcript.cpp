#include "transcript.hpp"

#include <algorithm>

void TranscriptRegistry::Add(const Transcript &transcript) {
  return m_transcripts.push_back(transcript);
}

void TranscriptRegistry::RemoveById(const std::string &student_id) {
  m_transcripts.erase(std::remove_if(
      m_transcripts.begin(), m_transcripts.end(),
      [&](const auto &t) { return t.student_id == student_id; }));
}

std::list<Transcript>::const_iterator TranscriptRegistry::FindTranscript(
    const std::string &student_id) const {
  return std::find_if(
      m_transcripts.begin(), m_transcripts.end(),
      [&](const auto &t) { return t.student_id == student_id; });
}

std::list<std::pair<std::string, size_t>> TranscriptRegistry::FindCourseResults(
    const std::string &name) const {
  std::list<std::pair<std::string, size_t>> results;
  for (const auto &t : m_transcripts)
    for (const auto [course, grade] : t.grades)
      if (course == name) results.push_back({t.student_id, grade});
  return results;
}

const std::list<Transcript> TranscriptRegistry::GetTranscripts() const {
  return m_transcripts;
}
