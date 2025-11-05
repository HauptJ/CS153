template <class T>
SpaceBattleQueue<T>::SpaceBattleQueue(const SpaceBattleQueue<T>& cpy) {
	m_size = cpy.m_size;
	m_max_size = cpy.m_max_size;
	m_data = new T[m_max_size];
	for (unsigned int i = 0; i < m_size; i++) {
		m_data[i] = cpy.m_data[i];
	}
}

// Purpose: Checks if a queue is empty
// Returns: 'true' if the queue is empty
//     'false' otherwise 

// Purpose: clears the queue
// Postconditions: the queue is now empty 
template <class T>
void SpaceBattleQueue<T>::clear() {
  while (!isEmpty()) {
	dequeue();
  }
}

// Purpose: enqueue an element into the queue
// Parameters: x is the item to add to the queue
// Postconditions: x is now the element at the end of the queue, 
template <class T>
void SpaceBattleQueue<T>::enqueue(const T& x) {
	if (m_size >= m_max_size) {
		m_max_size = m_max_size * 2;
		T* new_data = new T[m_max_size];
		for (unsigned int i = 0; i < m_size; i++) {
			new_data[i] = m_data[i];
		}
		delete[] m_data;
		m_data = new_data;
	}
	m_data[m_size] = x;
	m_size++;
}


// Purpose: dequeues 
// Postconditions: the element formerly at the front of the queue has
//     been removed
// Dequeueing from an empty Queue produces no errors, queue remains empty.
template <class T>
void SpaceBattleQueue<T>::dequeue() {
	// Default implementation using only pure virtual functions
  if (!this->isEmpty()) {
	for (int i = 0; i < m_size - 1; i++) {
	  m_data[i] = m_data[i + 1];
	}
	m_size--;
  }
}


// Purpose: looks at the front of the queue
// Returns: a reference to the element currently in front of the queue
// Exception: if the queue is currently empty, throw SOMETHING!!
template <class T>
const T& SpaceBattleQueue<T>::front() const throw(int) {
  // Default implementation using only pure virtual functions
  if (this->isEmpty()) {
    throw -1;
  }
  else {
    return m_data[0];
  }
}

// Purpose: Checks if a queue is empty
// Returns: 'true' if the queue is empty
//     'false' otherwise 
template <typename T>
bool SpaceBattleQueue<T>::isEmpty() const {
  return (size() == 0);
}

// Purpose: Returns the size of a queue.
// Returns: the number of elements in the Queue
template <typename T>
int SpaceBattleQueue<T>::size() const {
	return m_size;
}

// Purpose: Destructor
template <class T>
SpaceBattleQueue<T>::~SpaceBattleQueue() {
  delete[] m_data;
}