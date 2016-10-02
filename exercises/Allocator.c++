// -------------
// Allocator.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/allocator

#include <algorithm> // count
#include <memory>    // allocator, ==, !=

#include "gtest/gtest.h"

#include "Allocator.h" // My_Allocator
#include "Memory.h"    // my_destroy, my_uninitialized_fill

using namespace std;
using namespace testing;

template <typename T>
struct AllocatorFixture : Test {
    using allocator_type   = T;
    using value_type       = typename T::value_type;
    using size_type        = typename T::size_type;
    using pointer          = typename T::pointer;
    using other            = typename T::template rebind<double>::other;
    using other_value_type = typename T::template rebind<double>::other::value_type;
    using other_size_type  = typename T::template rebind<double>::other::size_type;
    using other_pointer    = typename T::template rebind<double>::other::pointer;};

using
    allocator_types =
    Types<
           allocator<int>,
        my_allocator<int>>;

TYPED_TEST_CASE(AllocatorFixture, allocator_types);

TYPED_TEST(AllocatorFixture, test_1) {
    using allocator_type = typename TestFixture::allocator_type;
    using value_type     = typename TestFixture::value_type;
    using size_type      = typename TestFixture::size_type;
    using pointer        = typename TestFixture::pointer;

          allocator_type x;
    const size_type      s = 1;
    const pointer        p = x.allocate(s);
    const value_type     v = 2;
    x.construct(p, v);
    assert(*p == v);
    x.destroy(p);
    x.deallocate(p, s);}

TYPED_TEST(AllocatorFixture, test_2) {
    using allocator_type = typename TestFixture::allocator_type;
    using value_type     = typename TestFixture::value_type;
    using size_type      = typename TestFixture::size_type;
    using pointer        = typename TestFixture::pointer;

          allocator_type x;
    const size_type      s = 10;
    const pointer        b = x.allocate(s);
    const pointer        e = b + s;
    const value_type     v = 2;
    my_uninitialized_fill(x, b, e, v);
    assert(std::count(b, e, v) == s);
    my_destroy(x, b, e);
    x.deallocate(b, s);}

TYPED_TEST(AllocatorFixture, test_3) {
    using other            = typename TestFixture::other;
    using other_value_type = typename TestFixture::other_value_type;
    using other_size_type  = typename TestFixture::other_size_type;
    using other_pointer    = typename TestFixture::other_pointer;

          other            x;
    const other_size_type  s = 1;
    const other_pointer    p = x.allocate(s);
    const other_value_type v = 2;
    x.construct(p, v);
    assert(*p == v);
    x.destroy(p);
    x.deallocate(p, s);}

TYPED_TEST(AllocatorFixture, test_4) {
    using allocator_type = typename TestFixture::allocator_type;

    allocator_type x;
    allocator_type y;
    ASSERT_EQ(x, y);}
