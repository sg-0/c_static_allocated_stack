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
#include "queue.h"

Queue * testQueue0;
Queue * testQueue1;
Queue * testQueue2;
Queue * testQueue3;

TEST(setUp, expectUnexistingQueue){
	EXPECT_TRUE(testQueue0 == NULL);
}

TEST(setUp, expectQueueNotNull){
	testQueue0 = new Queue();
	testQueue1 = new Queue();
	testQueue2 = new Queue();
	testQueue3 = new Queue();
	EXPECT_FALSE(testQueue0 == NULL);
	EXPECT_FALSE(testQueue1 == NULL);
	EXPECT_FALSE(testQueue2 == NULL);
	EXPECT_FALSE(testQueue3 == NULL);
}

TEST(setUp, expectEmptyQueue){
	EXPECT_TRUE(testQueue0->isEmpty());
	EXPECT_FALSE(testQueue0->isFull());
	EXPECT_EQ(testQueue0->getMaxSize(), 256);
}

TEST(enqueue, expectElementsAfterenqueuees){
	for(int i = 1; i<500; i++)
		testQueue1->enqueue(i);
	testQueue0->enqueue(50);
	EXPECT_EQ(testQueue0->dequeue(), 50);
	testQueue0->enqueue(100);
	testQueue0->enqueue(200);
	testQueue0->enqueue(300);
	EXPECT_FALSE(testQueue0->isEmpty());
	EXPECT_FALSE(testQueue0->isFull());
	EXPECT_EQ(testQueue0->dequeue(), 100);
	EXPECT_EQ(testQueue0->dequeue(), 200);
}

TEST(dequeue, expectEmptyAfterDequeues){
	for(int i = 1; i<=200; i++)
		EXPECT_EQ(testQueue1->dequeue(), i);
	testQueue1->enqueue(100);
	testQueue1->enqueue(200);
	testQueue1->enqueue(300);
	EXPECT_EQ(testQueue1->getSize(), 59);
	for(int i = 201; i<=256; i++)
		EXPECT_EQ(testQueue1->dequeue(), i);
	EXPECT_EQ(testQueue0->dequeue(), 300);
	EXPECT_EQ(testQueue0->dequeue(), 0);
	EXPECT_EQ(testQueue0->dequeue(), 0);
	EXPECT_EQ(testQueue0->dequeue(), 0);
	EXPECT_TRUE(testQueue0->isEmpty());
	EXPECT_EQ(testQueue1->dequeue(), 100);
	EXPECT_EQ(testQueue1->dequeue(), 200);
	EXPECT_EQ(testQueue1->dequeue(), 300);
}

// TEST(isFull, expectFullQueue){
// 	testQueue0->enqueue(1);
// 	testQueue0->enqueue(2);
// 	testQueue0->enqueue(3);
// 	testQueue0->enqueue(4);
// 	testQueue0->enqueue(5);
// 	EXPECT_TRUE(testQueue0->isFull());
// 	testQueue0->enqueue(6);
// 	EXPECT_TRUE(testQueue0->isFull());
// 	testQueue0->enqueue(7);
// 	EXPECT_EQ(testQueue0->dequeue(), 5);
// 	EXPECT_EQ(testQueue0->dequeue(), 4);
// 	EXPECT_EQ(testQueue0->dequeue(), 3);
// 	EXPECT_EQ(testQueue0->dequeue(), 2);
// 	EXPECT_EQ(testQueue0->dequeue(), 1);
// 	EXPECT_EQ(testQueue0->dequeue(), 0);
// 	EXPECT_EQ(testQueue0->dequeue(), 0);
// }

// TEST(stackOverFlow, expectMaxStackSizeMaxLong){
// 	Stack *overFlowStack = new Stack(0XFFFFFFF);
// 	EXPECT_EQ(overFlowStack->getMaxSize(), 0XFFFFFFF);
// }