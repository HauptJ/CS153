/*
 * ---- Big 3 Member Functions ---*/

// Purpose: Destructor
// Postconditions: current size and maximum size set to 0,
//                 data deallocated and set to NULL
template <typename T>
ArrayList<T>::~ArrayList() {
  //std::cout << "~ArrayList() DESTRUCTOR" << std::endl;
  m_size = 0;
  m_max = 0;
  delete[] m_data;
  m_data = NULL;
}

/*
 * ---- Big 3 Member Functions ---*/

// Purpose: Operator=, performs a deep copy of 'rhs' into 'this' ArrayList
// Parameters: rhs, ArrayList to be copied
// Returns: *this
// Postconditions: rhs == this
template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs) {
  //std::cout << "operator=(const ArrayList<T>& rhs)" << std::endl;
  // if rhs != this delete this
  if(this != &rhs) {
    m_size = rhs.m_size;
    m_max = rhs.m_max;
    m_errobj = rhs.m_errobj;

    delete[] m_data;
    m_data = new T[rhs.m_max];
  }

  // set m_data(this) to rhs so rhs == this
  for(int i = 0; i < rhs.m_size; i++) {
    m_data[i] = rhs.m_data[i];
  }

  return *this;
}

// Purpose: Copy Constructor
// Parameters: cpy = ArrayList to be copied
// Postconditions: current size, maximum size, and elements same as cpy
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy) {
  //std::cout << "ArrayList(const ArrayList<T>& cpy) COPY CONSTRUCTOR" << std::endl;
  m_data = NULL;
  *this = cpy;
}


/*
 * ----- Basic Accessor Operations ----- */

 // Purpose: Accessor function for the number of elements in the list
 // Returns: number of elements in the list
template <typename T>
int ArrayList<T>::size() const {
  //std::cout << "size()" << std::endl;
  return m_size;
}

// Purpose: Accessor function for the first element of the list
// Returns: a copy of the first element in the list
template <typename T>
const T& ArrayList<T>::first() const {
  //std::cout << "first() const" << std::endl;
  if(m_size <= 0) {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!" << std::endl;
    std::cout << "list is empty" << std::endl;
    return m_errobj;
  } else {
    return m_data[0];
  }
}

// Purpose: return a read-and-write reference to the element at
// the specified position
// Parameters: i is 0-based index into the ArrayList
// Returns: the element at position i in the ArrayList
template <typename T>
T& ArrayList<T>::operator[](int i) {
  //std::cout << "operator[](int i)" << std::endl;
  if (i > m_size || i < 0) {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!" << std::endl;
    std::cout << "index is out of range" << std::endl;
    return m_errobj;
  } else {
    return m_data[i];
  }
}

// Purpose: return a read-only reference to the element at
// the specified position
// Parameters: i is 0-based index into the ArrayList
// Returns: the element at position i in the ArrayList
template <typename T>
const T& ArrayList<T>::operator[](int i) const {
  //std::cout << "operator[](int i) const" << std::endl;
  if (i > m_size || i < 0) {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!" << std::endl;
    std::cout << "index is out of range" << std::endl;
    return m_errobj;
  } else {
    return m_data[i];
  }
}

// Purpose: finds an element in the ArrayList
// Parameters: x is value to be found in the ArrayList
// Returns: the position of the first occurrance of x in the list,
//          or -1  if x is not found.
template <typename T>
int ArrayList<T>::find(const T& x) {
  //std::cout << "find(const T& x)" << std::endl;
  for (int i = 0; i < m_size; i++) {
    if (m_data[i] == x) {
      return i;
    }
  }
  return -1; // x is not found
}

/*
 * ----- Basic Mutator Operations ----- */

// Purpose: Clears the ArrayList
// Postconditions: current size and maximum size set to 0,
//                 elements are deallocated and data is set to NULL
template <typename T>
void ArrayList<T>::clear() {
   //std::cout << "clear()" << std::endl;
   m_size = 0;
   m_max = 0;
   delete[] m_data;
   m_data = NULL;
 }

 // Purpose: puts the value x at the end of an ArrayList
 // Parameters: x is value to be added to ArrayList
 // Postconditions: current size is incremented by 1
 //     If max size is reached, a new array of size max*2 is allocated
 //     and data is copied to it.
template <typename T>
void ArrayList<T>::insert_back(const T& x) {
  //std::cout << "insert_back(const T& x)" << std::endl;
  T* tmp;

  if (m_size == 0) { // check if the array exists
    m_data = new T[2];
    m_max = 2;
  }
  // if max size has been reached
  else if (m_size >= m_max) {
    tmp = new T[m_max * 2];
    for (int i = 0; i < m_size; i++) {
      tmp[i] = m_data[i];
    }
    delete[] m_data;
    m_data = tmp;
    m_max *= 2;
  }

  // insert at end of the ArrayList
  m_data[m_size] = x;
  m_size++;
}

// Purpose: puts the value x at the position i in the  ArrayList
// Parameters: x is value to be added to ArrayList
//             i is the position to insert x at
// Postconditions: current size is incremented by 1
//     If max size is reached, a new array of size max*2 is allocated
//     and data is copied to it.
template <typename T>
void ArrayList<T>::insert(const T& x, int i) {
  //std::cout << "insert(const T& x, int i)" << std::endl;
  T* tmp;

  if (i >= 0 && i < m_size) {
    if (m_size >= m_max) { // If max size is reached, a new array of size max*2 is allocated
      tmp = new T[m_max * 2];
      for(int j = 0; j < m_size; j++) {
        tmp[j] = m_data[j];
      }
      delete[] m_data;
      m_data = tmp;
      m_max *= 2;
    }
    for (int j = i; j < m_size; j++) { // move everything after i back one
      m_data[j+1] = m_data[j];
    }
    m_data[i] = x;
    m_size++;
  } else {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!" << std::endl;
    std::cout << "index is out of bounds" << std::endl;
  }
}

// Purpose: Removes the element at index i in the array
// Parameters: i, the index of the element to remove
// Postconditions: if the size of the list is greater than 0
//     size is decremented by one.
//     if the size of the list less than 1/4 the max size, a new array
//     of size max/2 is allocated, and data is copied to it.
template <typename T>
void ArrayList<T>::remove(int i) {
  //std::cout << "remove(int i) " << std::endl;
  T* tmp;

  if (i >= 0 && i < m_size) {
    if (m_size > 0) {
      m_size--;
    }
    for (int j = i; j < m_size; j++) {
      m_data[j] = m_data[j-1];
    }
    if (m_size < 1/4 * m_max) {
      tmp = new T[m_max / 2];
      for (int j = 0; j < m_size; j++) {
        tmp[j] = m_data[j];
      }
    }
  } else {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!" << std::endl;
    std::cout << "index is out of bounds" << std::endl;
  }
}

/*
 * ----- Complex Mutator Operations ----- */

 // Purpose: swaps two elements of the array
 // Parameters: i, k, two positions on the Arraylist
 // Postconditions: the elements at positions i and k swap positions
 template <typename T>
 void ArrayList<T>::swap(int i, int k) {
   //std::cout << "swap(int i, int k) " << std::endl;
   T tmp;

   if (i >= 0 && i < m_size && k >= 0 && k < m_size) {
     tmp = m_data[i];
     m_data[i] = m_data[k];
     m_data[k] = tmp;
   } else {
     std::cout << "!-- ERROR : PANIC in ARRAYLIST!!" << std::endl;
     std::cout << "index is out of bounds" << std::endl;
   }
 }

 // Purpose: appends two lists
 // Parameters: alist, a list to append to the end of 'this' list
 // Postconditions: current size is incremented by size of alist
 //     the elements of alist are appended to the elements of 'this'
 template <typename T>
 void ArrayList<T>::append(const ArrayList<T>& alist) {
   //std::cout << "append(const ArrayList<T>& alist)" << std::endl;
   for (int i = 0; i < alist.size(); i++) {
     insert_back(alist[i]);
   }
 }

 // Purpose: removes duplicates from an Arraylist
 // Postconditions: all duplicate elements are removed from the list.
 template <typename T>
 void ArrayList<T>::purge() {
   //std::cout << "purge()" << std::endl;
   for (int i = 0; i < m_size; i++) {
     for (int j = 0; j < m_size; j++) {
       if (m_data[i] == m_data[j]) {
         remove(j);
       }
     }
   }
 }
