// isEmpty
template <class T>
bool LinkedList<T>::isEmpty() const
{
  if(m_next = NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
  /*bool status;
  LinkedList*p = this;
  while(p -> m_next != NULL)
  {
    status = false;
    p = p -> m_data;
  }
  return status;*/
}