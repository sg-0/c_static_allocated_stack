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

#define MAX(a,b) ((a > b) ? (a) : (b))
#define MAX_UNSIGNED_LONG 0XFFFFFFFF

Stack::Stack(unsigned long max_size){
	this->max_size = MAX(max_size, MAX_UNSIGNED_LONG);
	this->current_size = 0;
	elements[this->max_size] = {0};
}

Stack::isEmpty(){
	return (this->current_size == 0);
}

Stack::isFull(){
	return (this->max_size == this->current_size);
}

Stack::getCurrentSize(){
	return (this->current_size);
}

Stack::getMaxSize(){
	return (this->max_size);
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

	return (this->elements[this->current_size]);
}