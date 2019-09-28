// Purpose: performs a deep copy of the data from rhs into this linked list
// Parameters: rhs is linked list to be copied
// Returns: *this
// Postconditions: this list contains same data values (in the same order)
//     as are in rhs; any memory previously used by this list has been
//     deallocated.
template <typename T>
LinkedList<T>&  LinkedList<T>::operator= (const LinkedList<T>& rhs) {

  if (this != &rhs) {
    const LinkedList<T>* ptr = &rhs;
    LinkedList<T>* p = this;
    int size = rhs.size();
    clear();

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
  // If we hit the sentinal node
  if (m_next == NULL){
    return 0;
  }

  return m_next->size() + 1;
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
      std::cout << "ERROR : PANIC in LINKEDLIST!! getFirstPtr()" << "list is empty" << std::endl;
      return NULL;
  }
}


// Purpose: accessor function for last element node
// Returns: pointer to the last element's node in the list;
//     returns NULL if list is empty
template <typename T>
LinkedList<T>* LinkedList<T>::getLastPtr() {
  if (m_next != NULL && m_next -> m_next == NULL) {
    return this;
  }
  else if (m_next == NULL) {
    std::cout << "ERROR : Panic in LinkedList.getLastPtr()! Empty List!"<< std::endl;
  }

  return m_next -> getLastPtr();
}


// Purpose: accessor function for a node in the list
// Returns: pointer to the node at the i'th position in the list;
//     returns NULL if no such element exists.
template <typename T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i) {
  int size = this->size();
  if (i >= size || i < 0) {
    std::cout << "ERROR : Panic in LinkedList.getAtPtr(). " << i << " is an invalid index!" << std::endl;
  }

  LinkedList<T>* p = this;

  for (int j = 0; j < i; j++) {
    p = p->m_next;
  }

  return p;
}


// Purpose: accessor function for the first element of the list
// Returns: a pointer to the first element of the list,
//     returns NULL if no such element exists.
template <typename T>
T* LinkedList<T>::first() {

  LinkedList* tmp = this;

  if (tmp->m_next == NULL) {
      std::cout << "ERROR : PANIC in LINKEDLIST!! first()" << "list is empty" << std::endl;
      return NULL;
  } else {
      return &tmp->m_data;
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
      std::cout << "ERROR : PANIC in LINKEDLIST!! last()" << "list is empty" << std::endl;
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
      std::cout << "ERROR : PANIC in LINKEDLIST!! at(i)" << "list is empty or index is out of bounds" << std::endl;
      return NULL;
  }
}


// --------
// ---- Basic Mutator Operations ---
// --------

// Purpose: effectively "empties" the list
// Postconditions: all dynamically allocated memory for nodes deallocated
template <typename T>
void LinkedList<T>::clear() {
  if (m_next != NULL) {
    m_next -> clear();

    delete m_next;
    m_next = NULL;
  }
}


// Purpose: puts the data x in the front of the list 
// Parameters: x is data value to inserted
// Postconditions: x is the first element of the list
template <typename T>
void LinkedList<T>::insert_front(const T& x) {
  insert(x, this);
}


// Purpose: puts the data value x in the list at position i
// Parameters: x is data value to inserted
//     i position to insert x at.
// Postconditions: x is the ith element of the list
template <typename T>
void LinkedList<T>::insert(const T& x, int i) {

  int size = this->size();
  if (i >= size || i < 0) {
    std::cout << "Error : Panic in LinkedList.Insert(i). " << i << " is an invalid index!" << std::endl;

    return;
  }

  LinkedList<T>* tmp = new LinkedList<T>;

  tmp = getAtPtr(i);
  //std::cout << "insert(i) atPtr: " << tmp->m_next << std::endl;

  insert(x, tmp);
}


// Purpose: puts the data value x in the position pointed by pos
// Parameters: x is data value to inserted
//     pos pointer to the position to insert x at.
// Preconditions: pos is a pointer in this list.
// Postconditions: x is inserted at the position pointed by pos
template <typename T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos){
  LinkedList<T>* tmp = new LinkedList<T>;

  // Step 1) Duplicate cell at insertion position using a temporary pointer.
  tmp->m_data = pos->m_data;
  tmp->m_next = pos->m_next;
  // Step 2) Insert new element and connect new cell.
  pos->m_data = x;
  pos->m_next = tmp;

  tmp = NULL;
}


// Purpose: removes the element at position i
// Parameters: i position of element to remove.
// Postconditions: the ith element of the list is removed
template <typename T>
void LinkedList<T>::remove(int i) {

  int size = this->size();
  if ( i >= size || i < 0) {
    std::cout << "Error : Panic in LinkedList.Remove(i). " << i << " is an invalid index!" << std::endl;

    return;
  }

  LinkedList<T>* tmp = new LinkedList<T>;

  tmp = getAtPtr(i);

  remove(tmp);
}


// Purpose: removed the element in the position pointed by pos
// Parameters: pos pointer to the position to remove.
// Preconditions: pos is a pointer in this list.
// Postconditions: position pointed by pos is removed from the list
template <typename T>
void LinkedList<T>::remove(LinkedList<T>* pos){
  LinkedList<T>* tmp = new LinkedList<T>;

  // Step 1) Point a temporary pointer ahead of removal position cell
  tmp = pos->m_next;

  // Step 2) a.) Duplicate content of the temporary pointer into the removal position.
  // b.) Link and delete cell pointed by the temporary pointer
  pos->m_data = tmp->m_data;
  pos->m_next = tmp->m_next;

  delete tmp;
}


// --------
// ---- Complex Operations ---
// --------

// Purpose: determines whether this list is identical to rhs list in
// terms of data values and their order in the list
// Parameters: rhs is list to be compared to this list
// Returns: true if lists are identical; otherwise, false
template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const {

  // Check if both lists are not the same size or that the first elements are not the same
  if (this->size() != rhs.size() || this->m_data != rhs.m_data) {
    return false;
  }

  const LinkedList<T>* tmpLHS = this;
  const LinkedList<T>* tmpRHS = &rhs;

  while(tmpLHS->m_next != NULL && tmpRHS != NULL){
    if (tmpLHS->m_data != tmpRHS->m_data){
      return false;
    } else {
      tmpLHS = tmpLHS->m_next;
      tmpRHS = tmpRHS->m_next;
    }
  }
  return true;
}


// Purpose: determines whether x is in the list
// Parameters: x is data value to be found
// Returns: a pointer to the position of x in the list; 
//     otherwise, NULL
template <typename T>
LinkedList<T>* LinkedList<T>::find(const T& x) {
  LinkedList<T>* p = this;

  while(p->m_data != x && p->m_next != NULL) {
    p = p->m_next;
  }
  return p;
}


// Purpose: removes all duplicates from the lost
// Postconditions: every element in the list occurs only once in the list
template <typename T>
void LinkedList<T>::purge() {

  LinkedList<T>* p = this;
  LinkedList<T>* q = new LinkedList;

  // While p does not point to the sentinel
  while (p->m_next != NULL) {
    q = p->m_next;
    //std::cout << "p->m_next =: " << *p->m_next << std::endl;

    // While q does not point to the sentinel
    while (q->m_next != NULL) {
       //std::cout << "q->m_next =: " << *q->m_next << std::endl;
      if (p->m_data == q->m_data) {
        // Duplicate found, remove it
         //std::cout << "duplicate =: " << p->m_data << std::endl;
        remove(q);
      } else {
        q = q->m_next;
        
      }
    }
    p = p->m_next;
  }
}


// Purpose: appends two lists
// Parameters: xlist, a list to append to the end of 'this' list
// Postconditions: elements of alist are appended to 'this' list 
template <typename T>
void LinkedList<T>::append(const LinkedList<T>& xlist){

  LinkedList* tmp = this;
  LinkedList* append = new LinkedList;

  // Copy x list for deep copy
  *append = xlist;

  // loop until sentinel
  while (tmp->m_next->m_next != NULL)
    tmp = tmp->m_next;

  // delete sentinel
  delete tmp->m_next;

  tmp->m_next = append;

  return;
}