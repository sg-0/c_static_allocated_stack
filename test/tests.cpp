/*****************************************************************************
 * @file Tests.cpp
 * @author sg-0
 * @brief 
 * @version 0.1
 * @date 2021-01-21
 * 
 * @copyright Copyright (c) 2021
 * 
 *****************************************************************************/

#include <gtest/gtest.h>
#include "stack.h"

Stack *myStack;

TEST(StackSetupTest, StackCreation) { 
	myStack = new Stack();
	EXPECT_FALSE(myStack == NULL);
}