#include "gtest/gtest.h"
#include "SpaceBattleQueue.h"


TEST(SpaceBattleQueueTest, SpaceBattleQueueDefaultConstructor) {
    SpaceBattleQueue<int> sbq;
    EXPECT_EQ(sbq.size(), 0);
    EXPECT_TRUE(sbq.isEmpty());
    EXPECT_THROW(sbq.front(), int);
}

TEST(SpaceBattleQueueTest, SpaceBattleQueueCopyConstructor) {
    SpaceBattleQueue<int> sbq1;
    sbq1.enqueue(1);
    sbq1.enqueue(2);
    sbq1.enqueue(3);

    SpaceBattleQueue<int> sbq2(sbq1); // Use copy constructor

    // Check that sizes are equal
    EXPECT_EQ(sbq1.size(), sbq2.size());

    // Check that front elements are equal
    EXPECT_EQ(sbq1.front(), sbq2.front());

    // Modify original and check that copy is unaffected
    sbq1.dequeue();
    EXPECT_NE(sbq1.front(), sbq2.front());
}

// Basic smoke tests for SpaceBattleQueue public API.
// These tests assume the queue behaves like a normal FIFO queue:
// - enqueue places items at the back
// - front returns the current front element (throws int on empty)
// - dequeue removes the front element (no-op on empty)
// - size and isEmpty reflect the number of elements
// - clear empties the queue
// - copy constructor performs a deep copy

TEST(SpaceBattleQueueTest, DefaultConstruct_IsEmpty) {
    SpaceBattleQueue<int> q;
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

TEST(SpaceBattleQueueTest, FrontThrowsOnEmpty) {
    const SpaceBattleQueue<int> q;
    EXPECT_THROW(q.front(), int);
}

TEST(SpaceBattleQueueTest, EnqueueIncreasesSizeAndFrontIsFIFO) {
    SpaceBattleQueue<int> q;
    q.enqueue(10);
    EXPECT_FALSE(q.isEmpty());
    EXPECT_EQ(q.size(), 1);
    EXPECT_NO_THROW({
        EXPECT_EQ(q.front(), 10);
    });

    q.enqueue(20);
    EXPECT_EQ(q.size(), 2);
    EXPECT_EQ(q.front(), 10); // first remains 10

    q.enqueue(30);
    EXPECT_EQ(q.size(), 3);
    EXPECT_EQ(q.front(), 10);
}

TEST(SpaceBattleQueueTest, DequeueRemovesFrontAndNoThrowOnEmpty) {
    SpaceBattleQueue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQ(q.size(), 3);
    EXPECT_EQ(q.front(), 1);

    q.dequeue(); // removes 1
    EXPECT_EQ(q.size(), 2);
    EXPECT_EQ(q.front(), 2);

    q.dequeue(); // removes 2
    EXPECT_EQ(q.size(), 1);
    EXPECT_EQ(q.front(), 3);

    q.dequeue(); // removes 3 -> empty
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);

    // Dequeue on empty should not throw and should leave queue empty
    EXPECT_NO_THROW(q.dequeue());
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

TEST(SpaceBattleQueueTest, ClearEmptiesQueue) {
    SpaceBattleQueue<int> q;
    for (int i = 0; i < 5; ++i) q.enqueue(i + 100);
    EXPECT_EQ(q.size(), 5);
    q.clear();
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
    EXPECT_THROW(q.front(), int);
}

TEST(SpaceBattleQueueTest, CopyConstructorCreatesIndependentCopy) {
    SpaceBattleQueue<int> a;
    a.enqueue(7);
    a.enqueue(8);
    a.enqueue(9);

    // copy construct
    SpaceBattleQueue<int> b(a);

    // sizes should match
    EXPECT_EQ(a.size(), b.size());

    // front elements should be equal initially
    EXPECT_EQ(a.front(), b.front());

    // Mutate original: dequeue should change a but not b
    a.dequeue();
    EXPECT_EQ(a.front(), 8);
    // b should still have original front
    EXPECT_EQ(b.front(), 7);

    // Mutate copy: dequeue on b should not affect a
    b.dequeue();
    EXPECT_EQ(b.front(), 8);
    EXPECT_EQ(a.front(), 8); // both may now match again, but operations were independent
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}