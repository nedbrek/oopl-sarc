// ------------------
// StrategyPattern3.h
// ------------------

#ifndef StrategyPattern_h
#define StrategyPattern_h

#include <string> // string

using namespace std;

class Movie {
    private:
        string _title;
        int    _days_rented;

    protected:
        int days_rented () const {
            return _days_rented;}

    public:
        Movie (string title, int days_rented) :
                _title       (title),
                _days_rented (days_rented)
            {}

        virtual int amount () const = 0;};

struct ChildrensMovie : Movie {
    ChildrensMovie (string title, int days_rented) :
            Movie (title, days_rented)
        {}

    int amount () const {
        return 2 + ((days_rented() > 3) ? (days_rented() - 3) * 2 : 0);}};

struct NewReleaseMovie : Movie {
    NewReleaseMovie (string title, int days_rented) :
            Movie (title, days_rented)
        {}

    int amount () const {
        return 3 * days_rented();}};

struct RegularMovie : Movie {
    RegularMovie (string title, int days_rented) :
            Movie (title, days_rented)
        {}

    int amount () const {
        return 2 + ((days_rented() > 2) ? (days_rented() - 2) * 2 : 0);}};

#endif // StrategyPattern_h
