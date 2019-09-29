#include <iostream>

#include <string>
using namespace std;

const int maxqueue = 7;

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

struct queuetype
{
	string name[maxqueue];
	int front;

	int back;
};

void createqueue(queuetype &queue);
bool fullqueue(queuetype queue);

bool emptyqueue(queuetype queue);
void enqueue(queuetype &queue, string &newelement);

void dequeue(queuetype &queue, string &nameout);

int main()
{

	queuetype shipinqueue;
	string newelement, nameout;
	char quest;

	createqueue(shipinqueue);

	cout << "Do you want to enter data (Y/N)? ";
	cin >> quest; 

	while ((quest=='y' || quest=='Y') && (!(fullqueue(shipinqueue))))
	{

		cout << "Entering ship name: ";
		Spaceship ship;

		enqueue(shipinqueue, newelement);

		if(!(fullqueue(shipinqueue)))
		{
			cout << "Do you want to enter data (Y/N)? ";
			cin >> quest; 
		}
	}

	while(!(emptyqueue(shipinqueue)))
	{
		dequeue(shipinqueue, nameout);

		cout << nameout << endl;
	}


	cin.get();

	cin.ignore();
	//system("pause");
}

void createqueue(queuetype &queue)
{

	queue.front = maxqueue - 1;
	queue.back = maxqueue - 1;
}

bool fullqueue(queuetype queue)
{
	if(queue.front == (queue.back +1) % maxqueue ) return 1;

	else return 0;

}

void enqueue(queuetype &queue, string &newelement)
{

	queue.back = (queue.back + 1) % maxqueue;

	queue.name[queue.back] = newelement;
}

bool emptyqueue(queuetype queue)
{

	if(queue.front == queue.back) return 1;

	else return 0;
}

void dequeue(queuetype &queue, string &nameout)
{

	queue.front = (queue.front +1) % maxqueue;

	nameout = queue.name[queue.front];
}

