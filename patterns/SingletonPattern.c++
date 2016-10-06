// --------------------
// SingletonPattern.c++
// --------------------

// http://en.cppreference.com/w/cpp/container/singleton

#include "gtest/gtest.h"

#include "SingletonPattern.h"

using namespace std;
using namespace testing;

template <typename T>
struct SingletonFixture : Test {
    using singleton_type = T;};

using
    singleton_types =
    Types<
        SingletonEager,
        SingletonLazy,
        SingletonLocal>;

TYPED_TEST_CASE(SingletonFixture, singleton_types);

TYPED_TEST(SingletonFixture, test_1) {
    using singleton_type = typename TestFixture::singleton_type;
    ASSERT_EQ(&singleton_type::only(), &singleton_type::only());}

TYPED_TEST(SingletonFixture, test_2) {
    using singleton_type = typename TestFixture::singleton_type;
    ASSERT_EQ("Singleton::f()", singleton_type::only().f());}
