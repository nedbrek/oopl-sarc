// ------------------
// StrategyPattern5.h
// ------------------

#ifndef StrategyPattern_h
#define StrategyPattern_h

#include <iostream>
#include <string> // string

using namespace std;

struct Price {
    virtual int amount (int days_rented) const = 0;};

struct ChildrensPrice : Price {
    int amount (int days_rented) const {
        return 2 + ((days_rented > 3) ? (days_rented - 3) * 2 : 0);}};

struct NewReleasePrice : Price {
    int amount (int days_rented) const {
        return 3 * days_rented;}};

struct RegularPrice : Price {
    int amount (int days_rented) const {
        return 2 + ((days_rented > 2) ? (days_rented - 2) * 2 : 0);}};

class Movie {
    public:
        enum PriceCode {Childrens, NewRelease, Regular};

    private:
        string _title;
        Price* _price;
        int    _days_rented;

    protected:
        int days_rented () const {
            return _days_rented;}

    public:
        Movie (string title, PriceCode price_code, int days_rented) :
                _title       (title),
                _days_rented (days_rented) {
            switch (price_code) {
                case Childrens :
                    _price = new ChildrensPrice;
                    break;

                case NewRelease :
                    _price = new NewReleasePrice;
                    break;

                case Regular :
                    _price = new RegularPrice;
                    break;

                default :
                    assert(false);
                    _price = nullptr;}}

        int amount () const {
            assert(_price);
            return _price->amount(_days_rented);}};

#endif // StrategyPattern_h
