// -----------------
// StrategyPattern.h
// -----------------

#ifndef StrategyPattern_h
#define StrategyPattern_h

#include <string> // string

using namespace std;

struct FlyingInterface {
    virtual ~FlyingInterface () {}
    virtual string fly () = 0;};

struct QuackingInterface {
    virtual ~QuackingInterface () {}
    virtual string quack () = 0;};

struct DuckInterface {
    virtual ~DuckInterface () {}
    virtual string swim () = 0;};



struct DecoyDuck : QuackingInterface, DuckInterface {
    string quack () {
        return "decoy ducks can quack";}

    string swim () final {
        return "decoy ducks can swim";}};

struct MallardDuck : FlyingInterface, QuackingInterface, DuckInterface {
    string fly () {
        return "mallard ducks can fly";}

    string quack () {
        return "mallard ducks can quack";}

    string swim () final {
        return "mallard ducks can swim";}};

struct ModelDuck : DuckInterface {
    string swim () final {
        return "model ducks can swim";}};

struct RubberDuck : QuackingInterface, DuckInterface {
    string quack () {
        return "rubber ducks can quack";}

    string swim () final {
        return "rubber ducks can swim";}};

#endif // StrategyPattern_h