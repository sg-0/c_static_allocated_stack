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

Stack *testStack;

TEST(setUp, expectUnexistingStack){
	EXPECT_TRUE(testStack == NULL);
}

TEST(setUp, expectStackNotNull){
	testStack = new Stack();
	EXPECT_FALSE(testStack == NULL);
}

TEST(setUp, expectEmptyStack){
	EXPECT_TRUE(testStack->isEmpty());
}

TEST(push, expectNotEmptyAfterPush){
	testStack->push(100);
	EXPECT_FALSE(testStack->isEmpty());
}

TEST(pop, expectEmptyAfterPop){
	testStack->pop();
	EXPECT_TRUE(testStack->isEmpty());
}