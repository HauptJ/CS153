#include<iostream>
#include<cstdlib>
#define MAX_SIZE 10

using namespace std;

class Queue
{
  private:
    Spaceship spaceship[MAX_SIZE];
    int rear;
    int front;

  public:
    Queue();
    void enqueue(Spaceship);
    int dequeue();
    int size();
    void display();
    bool isEmpty();
    bool isFull();
};

class Spaceship;
{
  string name;
  int hull;
};