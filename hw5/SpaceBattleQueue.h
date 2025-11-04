#ifndef SPACEBATTLEQUEUE_H
#define SPACEBATTLEQUEUE_H

#include "abstractqueue.h"


const unsigned int INIT_MAX_SIZE = 10;

template<class T>
class SpaceBattleQueue : public AbstractQueue<T> {
public:
	SpaceBattleQueue() {
		m_size = 0;
		m_max_size = MAX_SIZE;
		m_data = new T[MAX_SIZE];
	}
	SpaceBattleQueue(const SpaceBattleQueue<T>& cpy);
	void clear();
	void enqueue(const T& x);
	void dequeue();
	const T& front() const throw(int);
	bool isEmpty() const;
	int size() const;
	~SpaceBattleQueue();




private:
	T *m_data;
	unsigned int m_size;
	unsigned int m_max_size;
	void expand();
	void shrink();


};

#include "SpaceBattleQueue.hpp"

#endif