#include<iostream>
#include<cstdlib>
#define MAX_SIZE 10 //testing

using namespace std;

class Spaceship
{
  private:
    string m_name;
    int m_hull;
  public:
    Spaceship(string name = "test", int hull = 10)
    {
      m_name = name;
      m_hull = hull;
    }
};

class Queue
{
  private:
    Spaceship spaceship[MAX_SIZE];
    int rear;
    int front;

  public:
    Queue();
    void enqueue(Spaceship);
    Spaceship dequeue(); //not sure about Spaceship dequeue
    int size();
    void display();
    bool isEmpty();
    bool isFull();
};



int main()
{
  Queue queue;
  int choice;
  while(1)
  {
    cout<<"\n1. Enqueue\n2. Dequeue\n3. Size\n4. Display all element\n5. Quit";
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch(choice)
    {
      case 1:
      {
        if(!queue.isFull())
        {
          cout<<"\nEnter data: ";
          Spaceship ship;
          queue.enqueue(ship); //CHECK!!!!!
        }
        else
        {
          cout<<"Queue is Full"<<endl;
        }
      }
      break;
      
      case 2:
      {
        if(!queue.isEmpty())
        {
          cout<<"The data dequeued is :"<<queue.dequeue();
        }
        else
        {
          cout<<"Queue is Empty"<<endl;
        }
      }
      break;

      case 3:
      {
        cout<<"Size of Queue is "<<queue.size();
      }
      break;

      case 4:
      {
        queue.display(); 
      }
      break;

      case 5:
      {
        exit(0);
      }
      break;
      
    }
  }
  return 0;
}

Queue::Queue()
{
  rear = -1;
  front = 0;
}

void Queue::enqueue(Spaceship ship)
{
  spaceship[++rear] = ship;
}

Spaceship Queue::dequeue() //not sure about Spaceship Queue
{
  return spaceship[front++]; //cannot convert from int??? think fixed
}

void Queue::display() //as for the printing you need to provide a: ostream& operator<<(ostream& os, const Spaceship& spaceship)
{
  if(!this->isEmpty())
  {
    for(int i=front; i<=rear; i++)
    cout<<spaceship[i]<<endl; //no match for operator<< ???
  }
  else
  {
    cout<<"Queue Error"<<endl;
  }
}


int Queue::size()
{
  return (rear - front + 1);
}

bool Queue::isEmpty()
{
  if(front>rear)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Queue::isFull()
{
  if(this->size()>=MAX_SIZE)
  {
    return true;
  }
  else
  {
    return false;
  }
}
