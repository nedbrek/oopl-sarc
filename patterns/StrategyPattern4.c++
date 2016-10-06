// --------------------
// StrategyPattern4.c++
// --------------------

// https://en.wikipedia.org/wiki/Strategy_pattern

#include <memory> // shared_ptr

#include "gtest/gtest.h"

#include "StrategyPattern4.h"

using namespace std;

TEST(Strategy_Pattern_Fixture, test_1) {
    Movie x("Lion King", shared_ptr<Price>(new ChildrensPrice), 2);
    ASSERT_EQ(2, x.amount());}

TEST(Strategy_Pattern_Fixture, test_2) {
    Movie x("Finding Nemo", shared_ptr<Price>(new ChildrensPrice), 4);
    ASSERT_EQ(4, x.amount());}

TEST(Strategy_Pattern_Fixture, test_3) {
    Movie x("Jason Bourne", shared_ptr<Price>(new NewReleasePrice), 2);
    ASSERT_EQ(6, x.amount());}

TEST(Strategy_Pattern_Fixture, test_4) {
    Movie x("Giant", shared_ptr<Price>(new RegularPrice), 1);
    ASSERT_EQ(2, x.amount());}

TEST(Strategy_Pattern_Fixture, test_5) {
    Movie x("Shane", shared_ptr<Price>(new RegularPrice), 3);
    ASSERT_EQ(4, x.amount());}
