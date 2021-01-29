/*****************************************************************************
 * @file queue.c
 * @author sg-0
 * @brief 
 * @version 0.1
 * @date 2021-01-21
 * 
 * @copyright Copyright (c) 2021
 * 
 *****************************************************************************/

#include "queue.h"

Queue::Queue(){
	this->tail = 0;
	this->head = 0;
	this->current_size = 0;
}

Queue::isEmpty(){
	return (this->current_size == 0);
}

Queue::isFull(){
	return (QUEUE_MAX_SIZE <= this->current_size);
}

Queue::getSize(){
	return (this->current_size);
}

Queue::getMaxSize(){
	return (sizeof(this->elements)/sizeof(long));
}

Queue::enqueue(long element){
	if(false == this->isFull())
	{
		this->current_size++;
		this->elements[this->tail] = element;
		this->tail = (this->tail + 1) % QUEUE_MAX_SIZE;
	}
}

Queue::dequeue(){
	long return_element;

	return_element = 0;

	if(false == this->isEmpty()){
		this->current_size--;
		return_element = this->elements[this->head];
		this->head = (this->head + 1) % QUEUE_MAX_SIZE;
	}

	return return_element;
}