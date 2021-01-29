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
	testStack = new Stack(5);
	EXPECT_FALSE(testStack == NULL);
}

TEST(setUp, expectEmptyStack){
	EXPECT_TRUE(testStack->isEmpty());
	EXPECT_FALSE(testStack->isFull());
}

TEST(push, expectNotEmptyAfterPush){
	testStack->push(50);
	EXPECT_FALSE(testStack->isEmpty());
	EXPECT_FALSE(testStack->isFull());
}

TEST(push, expectElementsAfterPushes){
	testStack->push(100);
	testStack->push(200);
	testStack->push(300);
	EXPECT_EQ(testStack->pop(), 300);
	EXPECT_EQ(testStack->pop(), 200);
	EXPECT_EQ(testStack->pop(), 100);
}

TEST(pop, expectEmptyAfterPops){
	EXPECT_EQ(testStack->pop(), 50);
	EXPECT_EQ(testStack->pop(), 0);
	EXPECT_EQ(testStack->pop(), 0);
	EXPECT_EQ(testStack->pop(), 0);
	EXPECT_TRUE(testStack->isEmpty());
}

TEST(isFull, expectFullStack){
	testStack->push(1);
	testStack->push(2);
	testStack->push(3);
	testStack->push(4);
	testStack->push(5);
	EXPECT_TRUE(testStack->isFull());
	testStack->push(6);
	EXPECT_TRUE(testStack->isFull());
	testStack->push(7);
	EXPECT_EQ(testStack->pop(), 5);
	EXPECT_EQ(testStack->pop(), 4);
	EXPECT_EQ(testStack->pop(), 3);
	EXPECT_EQ(testStack->pop(), 2);
	EXPECT_EQ(testStack->pop(), 1);
	EXPECT_EQ(testStack->pop(), 0);
	EXPECT_EQ(testStack->pop(), 0);
}

// TEST(stackOverFlow, expectMaxStackSizeMaxLong){
// 	Stack *overFlowStack = new Stack(0XFFFFFFF);
// 	EXPECT_EQ(overFlowStack->getMaxSize(), 0XFFFFFFF);
// }