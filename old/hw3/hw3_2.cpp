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