/* @file: linkedlist.h
 * Definition of templated class LinkedList
 * Implementation of List A.D.T.
 * @C - Omicron Persei 8 Grand Emperor Lrrr
 * 
 * Version 3.14
 */

/* __________________
  /                  \
  | LinkedList Class |
  \__________________/
   
    Purpose: Implements a List ADT using a dynamically allocated 
        linked list to store the elements of the list.

    Design: This linked list implementation is designed to have a "sentinel"
        node at the end of the list. The data element of the sentinel node
        is left undefined.
        This is a POINTER HAPPY design...   :-)

    Error Handling: Whenever a function is given invalid parameter values 
        the message "!-- ERROR : PANIC in LINKEDLIST!!" and maybe an explanation
        is displayed. The list should remains unchanged. 
        If the function returns a value this value is undefined unless 
        otherwise specified by the function description.
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <class T>
class LinkedList
{
public:
  T m_data;                  // Data to be stored
  LinkedList<T>* m_next;     // Pointer to the next element in the list

    // Purpose: Default constructor
    // Postconditions: next pointer set to NULL
    // -INLINE-
  LinkedList() : m_next(NULL) {}

    // Purpose: Auxiliaty constructor, construct from parameters
    //     useful when inserting elements
    // Postconditions: data and next pointer set to parameters
    // -INLINE-
  LinkedList(const T& x, LinkedList<T>* p) 
             : m_data(x), m_next(p) {}


    // --------
    // ---- Big 3 Member Functions ---
    // --------

    // Purpose: Destructor
    // IMPORTANT:: FOr didactic purposes, the destructor is left empty.
    // YOU are expected to implement function clear() to de-allocate the list
  ~LinkedList() {}

    // Purpose: performs a deep copy of the data from rhs into this linked list
    // Parameters: rhs is linked list to be copied
    // Returns: *this
    // Postconditions: this list contains same data values (in the same order)
    //     as are in rhs; any memory previously used by this list has been
    //     deallocated.
  LinkedList<T>&  operator= (const LinkedList<T>& rhs);

    // Purpose: copy constructor
    // Parameters: cpy is the LinkedList that is to be copied
    // Postconditions: this list contains same data values (in same order) 
    //      as in cpy.
  LinkedList(const LinkedList<T>& cpy);
  
  

    // --------
    // ---- Basic Accessor Operations ---
    // --------

    // Purpose: accessor function for the current # data values in the list
    // Returns: current size of the list
  int size() const;
    
    // Purpose: determines whether the list is empty
    // Returns: true if list is empty; otherwise, false
  bool isEmpty() const;

    // Purpose: Get a pointer to the first element node
    // Returns: pointer to the first node in the list; 
    //     returns NULL if the list is empty
  LinkedList<T>* getFirstPtr();

    // Purpose: accessor function for last element node
    // Returns: pointer to the last element's node in the list; 
    //     returns NULL if list is empty
  LinkedList<T>* getLastPtr();

    // Purpose: accessor function for a node in the list
    // Returns: pointer to the node at the i'th position in the list; 
    //     returns NULL if no such element exists.
  LinkedList<T>* getAtPtr(int i);

    // Purpose: accessor function for the first element of the list
    // Returns: a pointer to the first element of the list,
    //     returns NULL if no such element exists.
  T* first();
  
    // Purpose: accessor function for the last element of the list
    // Returns: a pointer to the last element of the list,
    //     returns NULL if no such element exists.
  T* last(); 

    // Purpose: accessor function for an element of the list
    // Returns: a pointer to the element at the i'th position in the list
    //     returns NULL if no such element exists.
  T* at(int i);



    // --------
    // ---- Basic Mutator Operations ---
    // --------

    // Purpose: effectively "empties" the list
    // Postconditions: all dynamically allocated memory for nodes deallocated
  void clear();

    // Purpose: puts the data x in the front of the list 
    // Parameters: x is data value to inserted
    // Postconditions: x is the first element of the list
  void insert_front(const T& x);

    // Purpose: puts the data value x in the list at position i
    // Parameters: x is data value to inserted
    //     i position to insert x at.
    // Postconditions: x is the ith element of the list
  void insert(const T& x, int i);

    // Purpose: puts the data value x in the position pointed by pos
    // Parameters: x is data value to inserted
    //     pos pointer to the position to insert x at.
    // Preconditions: pos is a pointer in this list.
    // Postconditions: x is inserted at the position pointed by pos
  void insert(const T& x, LinkedList<T>* pos);

    // Purpose: removes the element at position i
    // Parameters: i position of element to remove.
    // Postconditions: the ith element of the list is removed
  void remove(int i);

    // Purpose: removed the element in the position pointed by pos
    // Parameters: pos pointer to the position to remove.
    // Preconditions: pos is a pointer in this list.
    // Postconditions: position pointed by pos is removed from the list
  void remove(LinkedList<T>* pos);



    // --------
    // ---- Complex Operations ---
    // --------

    // Purpose: determines whether this list is identical to rhs list in
    // terms of data values and their order in the list
    // Parameters: rhs is list to be compared to this list
    // Returns: true if lists are identical; otherwise, false
  bool operator== (const LinkedList<T>& rhs) const;

    // Purpose: determines whether x is in the list
    // Parameters: x is data value to be found
    // Returns: a pointer to the position of x in the list; 
    //     otherwise, NULL
  LinkedList<T>* find(const T& x);
    
    // Purpose: removes all duplicates from the lost
    // Postconditions: every element in the list occurs only once in the list
  void purge();

    // Purpose: appends two lists
    // Parameters: xlist, a list to append to the end of 'this' list
    // Postconditions: elements of alist are appended to 'this' list 
  void append(const LinkedList<T>& xlist);
        
}; // of class LinkedList



// ---------------  Utility Function for Printing
// Purpose: prints a LinkedList
template <typename T>                 
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& xlist)
{
  out << "[ ";
  const LinkedList<T>* p = &xlist;
  while ( p->m_next != NULL ){
    out << p->m_data << ", ";
    p = p->m_next;
  } 
  out << "]"; 
  
  return out;
}


#include "linkedlist.hpp"

#endif
