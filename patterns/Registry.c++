// ------------
// Registry.c++
// ------------

#include <memory> // shared_ptr
#include <string> // string

#include "gtest/gtest.h"

#include "Registry.h"

using namespace std;



struct A {
    virtual string f () = 0;};

using registry_type = Registry<string, shared_ptr<A>>;



struct B : A {
    static registry_type registry;

    string f () {
        return "B::f()";}};

registry_type B::registry("B", shared_ptr<A>(new B));



struct C : A {
    static registry_type registry;

    string f () {
        return "C::f()";}};

registry_type C::registry("C", shared_ptr<A>(new C));



TEST(RegistryFixture, test_1) {
    shared_ptr<A> p = registry_type::get("B");
    ASSERT_EQ("B::f()", p->f());}

TEST(RegistryFixture, test_2) {
    shared_ptr<A> p = registry_type::get("C");
    ASSERT_EQ("C::f()", p->f());}

TEST(RegistryFixture, test_3) {
    shared_ptr<A> p = registry_type::get("D");
    ASSERT_FALSE(p);}
