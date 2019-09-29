    // Purpose: performs a deep copy of the data from rhs into this linked list
    // Parameters: rhs is linked list to be copied
    // Returns: *this
    // Postconditions: this list contains same data values (in the same order)
    //     as are in rhs; any memory previously used by this list has been
    //     deallocated.
  LinkedList<T>&  operator= (const LinkedList<T>& rhs);


template <class T>
LinkedList<T>::LinkedList & operator= (const LinkedList<T>& rhs)
{
  if(this != rhs)
  {
    LinkedList *p;
    LinkedList *q;
    while(p -> m_next != NULL)
    {
      p -> m_next = q -> rhs.m_next;
    }
  }
  return *this;
}