// ------------------
// StrategyPattern4.h
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
        string            _title;
        shared_ptr<Price> _price;
        int               _days_rented;

    protected:
        int days_rented () const {
            return _days_rented;}

    public:
        Movie (string title, shared_ptr<Price> price, int days_rented) :
                _title       (title),
                _price       (price),
                _days_rented (days_rented) {
            assert(_price);}

        int amount () const {
            assert(_price);
            return _price->amount(_days_rented);}};

#endif // StrategyPattern_h
