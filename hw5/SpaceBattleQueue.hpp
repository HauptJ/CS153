#include "SpaceBattleQueue.h"

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
  // Default implementation using only pure virtual functions
  SpaceBattleQueue<T> tempQueue;
  // Step 1: Dequeue all elements into a temporary queue
  while (!this->isEmpty()) {
	tempQueue.enqueue(this->front());
	this->dequeue();
  }
  // Step 2: Enqueue the new element into the original queue
  this->enqueue(x);
  // Step 3: Enqueue back all elements from the temporary queue
  while (!tempQueue.isEmpty()) {
	this->enqueue(tempQueue.front());
	tempQueue.dequeue();
  }
}


// Purpose: dequeues 
// Postconditions: the element formerly at the front of the queue has
//     been removed
// Dequeueing from an empty Queue produces no errors, queue remains empty.
template <class T>
void SpaceBattleQueue<T>::dequeue() {
  // Default implementation using only pure virtual functions
  if (!this->isEmpty()) {
	this->front(); // Access front to ensure it's valid
	SpaceBattleQueue<T> tempQueue;
	// Step 1: Dequeue all elements except the front into a temporary queue
	this->dequeue(); // Remove the front element
	while (!this->isEmpty()) {
	  tempQueue.enqueue(this->front());
	  this->dequeue();
	}
	// Step 2: Enqueue back all elements from the temporary queue
	while (!tempQueue.isEmpty()) {
	  this->enqueue(tempQueue.front());
	  tempQueue.dequeue();
	}
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
  int count = 0;
  AbstractQueue<T> tempQueue;
  while (!this->isEmpty()) {
	tempQueue.enqueue(this->front());
	this->dequeue();
	count++;
  }
  while (!tempQueue.isEmpty()) {
	this->enqueue(tempQueue.front());
	tempQueue.dequeue();
  }
  return count;
}

template <class T>
void SpaceBattleQueue<T>::expand() {
  // Implementation of expand function
  m_max_size = m_max_size +1;
  T* new_data = new T[m_max_size];
  for (unsigned int i = 0; i < m_size; i++) {
	new_data[i] = m_data[i];
  }
  delete[] m_data;
  m_data = new_data;
}

template <class T>
void SpaceBattleQueue<T>::shrink() {
  // Implementation of shrink function
  m_max_size = m_max_size -1;
  T* new_data = new T[m_max_size];
  for (unsigned int i = 0; i < m_size; i++) {
	  new_data[i] = m_data[i];
  }
  delete[] m_data;
  m_data = new_data;
}