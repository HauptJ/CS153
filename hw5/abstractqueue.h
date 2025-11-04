/* 
 * Author: Dr. Ricardo Morales
 *   _____________
 *  /             \
 * | AbstractQueue |
 *  \_____________/
 *
 * An abstact class that defines the basic operations of a 
 * QUEUE Data Structure 
 *
 * For Homework #5, your Queue implementation should derive
 * this class.
 *
 * Version 13.1.1
 *
 */

#ifndef ABSTRACTQUEUE_H 
#define ABSTRACTQUEUE_H

template < typename T >
class AbstractQueue
{
public:

  // Purpose: clears the queue
  // Postconditions: the queue is now empty 
  // -- PURE VIRTUAL
  virtual void clear() = 0;
  
  // Purpose: enqueue an element into the queue
  // Parameters: x is the item to add to the queue
  // Postconditions: x is now the element at the end of the queue, 
  // -- PURE VIRTUAL
  virtual void enqueue(const T& x) = 0;
  
  // Purpose: dequeues 
  // Postconditions: the element formerly at the front of the queue has
  //     been removed
  // Dequeueing from an empty Queue produces no errors, queue remains empty.
  // -- PURE VIRTUAL
  virtual void dequeue() = 0;
  
  // Purpose: looks at the front of the queue
  // Returns: a reference to the element currently in front of the queue
  // Exception: if the queue is currently empty, throw SOMETHING!!
  // -- PURE VIRTUAL
  virtual const T& front() const = 0;  

  // Purpose: Checks if a queue is empty
  // Returns: 'true' if the queue is empty
  //     'false' otherwise  
  // -- PURE VIRTUAL
  virtual bool isEmpty() const = 0;
  
  // Purpose: Returns the size of a queue.
  // Returns: the number of elements in the Queue
  // -- PURE VIRTUAL
  virtual int size() const = 0;

  // ----------------

  // Purpose: Destructor
  // -- VIRTUAL
	virtual ~AbstractQueue() {};

};

#endif 
