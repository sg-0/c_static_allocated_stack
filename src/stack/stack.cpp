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

Stack::Stack(){
	stack_size = 0;
}

Stack::isEmpty(){
	return stack_size == 0;
}

Stack::push(int element){
	stack_size ++;
}

Stack::pop(){
	stack_size --;
}