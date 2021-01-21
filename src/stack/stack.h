/*****************************************************************************
 * @file stack.h
 * @author sg-0
 * @brief 
 * @version 0.1
 * @date 2021-01-21
 * 
 * @copyright Copyright (c) 2021
 * 
 *****************************************************************************/

class Stack{
	public:
		Stack(unsigned long max_size);
		isEmpty();
		isFull();
		push(long element);
		pop();
	private:
		unsigned long max_size;
		unsigned long current_size;
		long elements[];
};