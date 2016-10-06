// ------------------
// StrategyPattern1.h
// ------------------

#ifndef StrategyPattern_h
#define StrategyPattern_h

#include <string> // string

using namespace std;

class Movie {
    public:
        static const int Childrens  = 0;
        static const int NewRelease = 1;
        static const int Regular    = 2;

    private:
        string _title;
        int    _price_code;
        int    _days_rented;

    public:
        Movie (string title, int price_code, int days_rented) :
                _title       (title),
                _price_code  (price_code),
                _days_rented (days_rented)
            {}

        int amount () const {
            switch (_price_code) {
                case Childrens :
                    return 2 + ((_days_rented > 3) ? (_days_rented - 3) * 2 : 0);

                case NewRelease :
                    return 3 * _days_rented;

                case Regular :
                    return 2 + ((_days_rented > 2) ? (_days_rented - 2) * 2 : 0);

                default :
                    return -1;}}};

#endif // StrategyPattern_h
