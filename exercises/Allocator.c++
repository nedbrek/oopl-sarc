// -------------
// Allocator.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/allocator

#include <algorithm> // count
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <memory>    // allocator, ==, !=
#include <new>       // new

#include "Allocator.h" // My_Allocator
#include "Memory.h"    // my_destroy, my_uninitialized_fill

template <typename A, typename U>
void allocators (typename A::const_reference v, const U& w) {
    using size_type = typename A::size_type;
    using pointer_A = typename A::pointer;

    {
    A z;
    const pointer_A p = z.allocate(1);
    z.construct(p, v);
    assert(*p == v);
    z.destroy(p);
    z.deallocate(p, 1);
    }

    {
    A z;
    const size_type s = 10;
          pointer_A b = z.allocate(s);
          pointer_A e = b + s;
    my_uninitialized_fill(z, b, e, v);
    assert(std::count(b, e, v) == s);
    my_destroy(z, b, e);
    z.deallocate(b, s);
    }

    {
    using B         = typename A::template rebind<U>::other;
    using pointer_B = typename A::template rebind<U>::other::pointer;
    B z;
    const pointer_B p = z.allocate(1);
    z.construct(p, w);
    assert(*p == w);
    z.destroy(p);
    z.deallocate(p, 1);
    }

    {
    A x;
    A y;
    assert(x == y);
    assert(!(x != y));
    }}

int main () {
    using namespace std;
    cout << "Allocator.c++" << endl;

    allocators<My_Allocator<int>, double>(2, 3.45);
    allocators<   allocator<int>, double>(2, 3.45);

    cout << "Done." << endl;
    return 0;}
