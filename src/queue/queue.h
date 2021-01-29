/*****************************************************************************
 * @file queue.h
 * @author sg-0
 * @brief 
 * @version 0.1
 * @date 2021-01-21
 * 
 * @copyright Copyright (c) 2021
 * 
 *****************************************************************************/

#define QUEUE_MAX_SIZE 256u

class Queue{
	public:
		Queue();
		isEmpty();
		isFull();
		getSize();
		getMaxSize();
		enqueue(long element);
		dequeue();
	private:
		unsigned long current_size;
		unsigned long head;
		unsigned long tail;
		long elements[QUEUE_MAX_SIZE];
};