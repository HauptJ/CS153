// Purpose: performs a deep copy of the data from rhs into this linked list
// Parameters: rhs is linked list to be copied
// Returns: *this
// Postconditions: this list contains same data values (in the same order)
//     as are in rhs; any memory previously used by this list has been
//     deallocated.
template <typename T>
LinkedList<T>&  LinkedList<T>::operator= (const LinkedList<T>& rhs) {

  if (this != &rhs) {
    LinkedList<T>* p = this;
    int size = rhs.size();
    clear();

    const LinkedList<T>* ptr = &rhs;

    for (int i = 0; i < size; i++) {
      p->m_data = ptr->m_data;
      ptr = ptr->m_next;
      p->m_next = new LinkedList<T>;
      p = p->m_next;
    }
  }
  return *this;
}


// Purpose: copy constructor
// Parameters: cpy is the LinkedList that is to be copied
// Postconditions: this list contains same data values (in same order)
//      as in cpy.
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& cpy) {
  m_next = new LinkedList<T>();
  *this = cpy;
}



// --------
// ---- Basic Accessor Operations ---
// --------

// Purpose: accessor function for the current # data values in the list
// Returns: current size of the list
template <typename T>
int LinkedList<T>::size() const {
  int size = 0;
  LinkedList* tmp = m_next;

  // increment size while not in sentinal ptr
  while(tmp != NULL) {
    size++;
    tmp = tmp->m_next;
  }

  return size;
}

// Purpose: determines whether the list is empty
// Returns: true if list is empty; otherwise, false
template <typename T>
bool LinkedList<T>::isEmpty() const {
  if (m_next == NULL) {
    return true;
  } else {
      return false;
  }
}

// Purpose: Get a pointer to the first element node
// Returns: pointer to the first node in the list;
//     returns NULL if the list is empty
template <typename T>
LinkedList<T>* LinkedList<T>::getFirstPtr() {
  if (m_next != NULL) {
    return this;
  } else {
      std::cout << "!-- ERROR : PANIC in LINKEDLIST!!" << "list is empty" << std::endl;
      return NULL;
  }
}

// Purpose: accessor function for last element node
// Returns: pointer to the last element's node in the list;
//     returns NULL if list is empty
template <typename T>
LinkedList<T>* LinkedList<T>::getLastPtr(){
  if (m_next != NULL) {
    LinkedList* tmp = this;

    // we want the node before the sentinal so m_next 2x
    while (tmp->m_next->m_next != NULL) {
      tmp = tmp->m_next;
    }
    return tmp;

  } else {
      std::cout << "!-- ERROR : PANIC in LINKEDLIST!!" << "list is empty" << std::endl;
      return NULL;
  }
}

// Purpose: accessor function for a node in the list
// Returns: pointer to the node at the i'th position in the list;
//     returns NULL if no such element exists.
template <typename T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i) {
  if (m_next != NULL && i < size() && i >= 0) {
    LinkedList* tmp = this;

    for (int j = 0; j < i; j++) {
      tmp = tmp->m_next;
    }
    return tmp;
  } else {
      std::cout << "!-- ERROR : PANIC in LINKEDLIST!!" << "list is empty or index is out of bounds" << std::endl;
      return NULL;
  }
}

// Purpose: accessor function for the first element of the list
// Returns: a pointer to the first element of the list,
//     returns NULL if no such element exists.
template <typename T>
T* LinkedList<T>::first() {

  LinkedList* tmp = this;

  if (tmp->m_next != NULL) {
    return &tmp->m_data;
  } else {
      std::cout << "!-- ERROR : PANIC in LINKEDLIST!!" << "list is empty" << std::endl;
      return NULL;
  }
}

// Purpose: accessor function for the last element of the list
// Returns: a pointer to the last element of the list,
//     returns NULL if no such element exists.
template <typename T>
T* LinkedList<T>::last() {
  if (m_next != NULL) {
    LinkedList* tmp = this;

    // we want the node before the sentinal so m_next 2x
    while (tmp->m_next->m_next != NULL) {
      tmp = tmp->m_next;
    }
    return &tmp->m_data;

  } else {
      std::cout << "!-- ERROR : PANIC in LINKEDLIST!!" << "list is empty" << std::endl;
      return NULL;
  }
}

// Purpose: accessor function for an element of the list
// Returns: a pointer to the element at the i'th position in the list
//     returns NULL if no such element exists.
template <typename T>
T* LinkedList<T>::at(int i) {
  if (m_next != NULL && i < size() && i >= 0) {
    LinkedList* tmp = this;

    for (int j = 0; j < i; j++) {
      tmp = tmp->m_next;
    }
    return &tmp->m_data;
  } else {
      std::cout << "!-- ERROR : PANIC in LINKEDLIST!!" << "list is empty or index is out of bounds" << std::endl;
      return NULL;
  }
}
