/*****************************************************************************
 * @file stack.c
 * @author sg-0
 * @brief 
 * @version 0.1
 * @date 2021-01-21
 * 
 * @copyright Copyright (c) 2021
 * 
 *****************************************************************************/

#include "stack.h"

Stack::Stack(unsigned long max_size){
	this->max_size = max_size;
	this->current_size = 0;
	elements[max_size] = {0};
}

Stack::isEmpty(){
	return (this->current_size == 0);
}

Stack::isFull(){
	return (this->max_size == this->current_size);
}

Stack::push(long element){
	if(this->isFull())
		this->current_size--;
	else
		this->elements[this->current_size] = element;

	this->current_size++;
}

Stack::pop(){
	if(this->isEmpty())
		this->elements[this->current_size] = 0;
	else
		this->current_size--;

	return this->elements[this->current_size];;
}