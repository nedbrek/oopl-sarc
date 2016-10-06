// --------------------
// StrategyPattern3.c++
// --------------------

// https://en.wikipedia.org/wiki/Strategy_pattern

#include "gtest/gtest.h"

#include "StrategyPattern3.h"

using namespace std;

TEST(Strategy_Pattern_Fixture, test_1) {
    ChildrensMovie x("Lion King", 2);
    ASSERT_EQ(2, x.amount());}

TEST(Strategy_Pattern_Fixture, test_2) {
    ChildrensMovie x("Finding Nemo", 4);
    ASSERT_EQ(4, x.amount());}

TEST(Strategy_Pattern_Fixture, test_3) {
    NewReleaseMovie x("Jason Bourne", 2);
    ASSERT_EQ(6, x.amount());}

TEST(Strategy_Pattern_Fixture, test_4) {
    RegularMovie x("Giant", 1);
    ASSERT_EQ(2, x.amount());}

TEST(Strategy_Pattern_Fixture, test_5) {
    RegularMovie x("Shane", 3);
    ASSERT_EQ(4, x.amount());}
