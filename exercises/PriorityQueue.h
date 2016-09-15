// -----------------
// PriorityQueue.c++
// -----------------

// http://www.cplusplus.com/reference/queue/priority_queue/

#include <algorithm>  // make_heap, pop_heap, push_heap
#include <functional> // less
#include <vector>     // vector

template < typename T, typename C = std::vector<T>, typename BP = std::less<T> >
class my_priority_queue {
    public:
        typedef C                                         container_type;

        typedef typename container_type::value_type       value_type;
        typedef typename container_type::size_type        size_type;

        typedef typename container_type::reference        reference;
        typedef typename container_type::const_reference  const_reference;

    private:
        container_type _c;
        BP             _p;

    public:
        explicit my_priority_queue (BP p = BP(), const container_type& c = container_type()) :
                _c (c),
                _p (p) {
            std::make_heap(_c.begin(), _c.end(), _p);}

                           my_priority_queue  (const my_priority_queue&) = default;
                           ~my_priority_queue ()                         = default;
        my_priority_queue& operator =         (const my_priority_queue&) = default;

        bool empty () const {
            return _c.empty();}

        void pop () {
            std::pop_heap(_c.begin(), _c.end(), _p);
            _c.pop_back();}

        void push (const_reference v) {
            _c.push_back(v);
            std::push_heap(_c.begin(), _c.end(), _p);}

        size_type size () const {
            return _c.size();}

        const_reference top () const {
            return _c.front();}};

