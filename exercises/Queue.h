// -------
// Queue.h
// -------

#ifndef Queue_h
#define Queue_h

#include <deque>   // deque
#include <utility> // !=, <=, >, >=

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

template <typename T>
inline bool operator <= (const T& lhs, const T& rhs) {
    return !(rhs < lhs);}

template <typename T>
inline bool operator > (const T& lhs, const T& rhs) {
    return (rhs < lhs);}

template <typename T>
inline bool operator >= (const T& lhs, const T& rhs) {
    return !(lhs < rhs);}

} // rel_ops
} // std;
*/

using namespace std::rel_ops;

template <typename T, typename C = std::deque<T>>
class my_queue {
    public:
        using container_type  = C;

        using value_type      = typename container_type::value_type;
        using size_type       = typename container_type::size_type;

        using reference       = typename container_type::reference;
        using const_reference = typename container_type::const_reference;

    public:
        friend bool operator == (const my_queue& lhs, const my_queue& rhs) {
            return lhs._c == rhs._c;}

        friend bool operator < (const my_queue& lhs, const my_queue& rhs) {
            return lhs._c < rhs._c;}

    private:
        container_type _c;

    public:
        explicit my_queue (const container_type& c = container_type()) :
                _c (c)
            {}

                  my_queue   (const my_queue&)  = default;
                  ~my_queue  ()                 = default;
        my_queue& operator = (const my_queue&)  = default;

        reference back () {
            return _c.back();}

        const_reference back () const {
            return _c.back();}

        bool empty () const {
            return _c.empty();}

        reference front () {
            return _c.front();}

        const_reference front () const {
            return _c.front();}

        void pop () {
            _c.pop_front();}

        void push (const_reference v) {
            _c.push_back(v);}

        size_type size () const {
            return _c.size();}};

#endif // Queue_h
