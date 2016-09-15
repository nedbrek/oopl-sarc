// -----------------
// PriorityQueue.c++
// -----------------

// http://en.cppreference.com/w/cpp/container/priority_queue

#include <cassert> // assert
#include <list>    // list
#include <queue> // priority_queue
#include <vector>  // vector

#include "gtest/gtest.h"

#include "PriorityQueue.h"

using namespace std;

using testing::Test;
using testing::Types;

template <typename T>
struct PriorityQueue_Fixture : Test {
    using priority_queue_type = T;};

using
    priority_queue_types =
    Types<
           priority_queue<int>,
           priority_queue<int, list<int>>,
        my_priority_queue<int>,
        my_priority_queue<int, list<int>>>;

TYPED_TEST_CASE(PriorityQueue_Fixture, priority_queue_types);

TYPED_TEST(PriorityQueue_Fixture, test_1) {
    using priority_queue_type = typename TestFixture::priority_queue_type;

    priority_queue_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(0, x.size());

    x.push(2);
    x.push(3);
    x.push(4);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(3, x.size());
    ASSERT_EQ(2, x.front());
    ASSERT_EQ(4, x.back());

    x.pop();
    ASSERT_EQ(2, x.size());
    ASSERT_EQ(3, x.front());
    ASSERT_EQ(4, x.back());

    x.front() = 4;
    ASSERT_EQ(4, x.front());

    x.back() = 5;
    ASSERT_EQ(5, x.back());}

TYPED_TEST(PriorityQueue_Fixture, test_2) {
    using priority_queue_type = typename TestFixture::priority_queue_type;

    priority_queue_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    x.front() = 1;
    ASSERT_EQ(1, x.front());

    const priority_queue_type& r = x;
//  r.front() = 1;            // error: member function 'push' not viable: 'this' argument has type 'const priority_queue_type'
    ASSERT_EQ(1, r.front());

    x.back() = 5;
    ASSERT_EQ(5, x.back());

    const priority_queue_type& s = x;
//  s.back() = 6;            // error: member function 'push' not viable: 'this' argument has type 'const priority_queue_type'
    ASSERT_EQ(5, s.back());}

TYPED_TEST(PriorityQueue_Fixture, test_3) {
    using priority_queue_type = typename TestFixture::priority_queue_type;

    priority_queue_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    priority_queue_type y = x;
    ASSERT_EQ(x, y);

    y.pop();
    ASSERT_EQ(3, x.size());
    ASSERT_EQ(2, x.front());
    ASSERT_EQ(4, x.back());
    ASSERT_EQ(2, y.size());
    ASSERT_EQ(3, y.front());
    ASSERT_EQ(4, y.back());}

TYPED_TEST(PriorityQueue_Fixture, test_4) {
    using priority_queue_type = typename TestFixture::priority_queue_type;

    priority_queue_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    priority_queue_type y;
    y.push(5);
    y.push(6);

    y = x;
    ASSERT_EQ(x, y);

    y.pop();
    ASSERT_EQ(3, x.size());
    ASSERT_EQ(2, x.front());
    ASSERT_EQ(4, x.back());
    ASSERT_EQ(2, y.size());
    ASSERT_EQ(3, y.front());
    ASSERT_EQ(4, y.back());}

TYPED_TEST(PriorityQueue_Fixture, test_5) {
    using priority_queue_type = typename TestFixture::priority_queue_type;

    priority_queue_type x;
    x.push(2);
    x.push(3);
    x.push(4);

    priority_queue_type y;
    y.push(2);
    y.push(3);
    y.push(4);

    ASSERT_FALSE(x != y);
    ASSERT_FALSE(x <  y);
    ASSERT_FALSE(x >  y);
    ASSERT_TRUE (x <= y);
    ASSERT_TRUE (x >= y);}
