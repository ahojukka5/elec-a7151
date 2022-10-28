#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS

/*
    Implement a class RestrictedPtr that holds a pointer of any type with at
   least the following members:
        - default constructor (takes no parameters)
        - constructor with a raw pointer parameter
        - copy constructor
        - destructor
        - copy assignment operator
        - function GetData that takes no parameters and returns the data the raw
   pointer refers to. The data returned should be such that modifying it
   modifies the data the pointer refers to.
        - function GetPointer that takes no parameters and returns the raw
   pointer
        - function GetRefCount that takes no parameters and returns an int with
   the reference count

    At any time the objects should keep track of how many references there are
   to a pointer and not allow more than 3 references. If the reference count
   drops to 0, the referenced pointer's memory should be released. If the
   reference count is already 3 when copying, the copier should set it's pointer
   to nullptr and reference count to 1. NOTE: GetPointer, GetData and
   GetRefCount are needed for the tests to run
*/

template <class T>
class RestrictedPtr {
 private:
  T* m_ptr = nullptr;
  int* m_cnt = nullptr;

  void incref() { (*m_cnt)++; }

  void decref() {
    if ((*m_cnt) > 0) (*m_cnt)--;
  }

 public:
  // constructor for a case when no parameters are given
  RestrictedPtr() {}

  // constructor for case when a raw pointer is given as a parameter
  RestrictedPtr(T* ptr) : m_ptr(ptr), m_cnt(new int(1)) {}

  // copy constructor
  RestrictedPtr(RestrictedPtr<T>& lhs) {
    if (lhs.GetRefCount() < 3) {
      m_ptr = lhs.GetPointer();
      m_cnt = lhs.m_cnt;
      incref();
    } else {
      m_ptr = nullptr;
      m_cnt = new int(1);
    }
  }

  // destructor
  ~RestrictedPtr() {
    decref();
    if (GetRefCount() == 0) {
      delete m_ptr;
      delete m_cnt;
      m_ptr = nullptr;
      m_cnt = nullptr;
    }
  }

  // copy assignment
  RestrictedPtr& operator=(RestrictedPtr& lhs) {
    if (lhs.GetRefCount() < 3) {
      m_ptr = lhs.GetPointer();
      m_cnt = lhs.m_cnt;
      incref();
    } else {
      m_ptr = nullptr;
      m_cnt = new int(1);
    }
    return *this;
  }

  T& GetData() { return *m_ptr; }

  T* GetPointer() { return m_ptr; }

  int GetRefCount() { return *m_cnt; }
};

#endif
