#ifndef STRATEGY_PATTERN_1
#define STRATEGY_PATTERN_1
// ------------------
// StrategyPattern1.h
// ------------------
#include <string> // string
#include <algorithm>

/*
    Childrens
        $2 for the first 3 days
        $2 per day after

    NewRelease
        $3 per day

    Regular
        $2 for the first 2 days
        $2 per day after
 */
class Movie
{
public:
	 enum Type
	 {
	 	Childrens,
	 	NewRelease,
	 	Regular
	 };

	 virtual int amount() const = 0;
};

//---implementations----------------------------------------------------------
class MovieCommon
{
protected:
	MovieCommon(const std::string &name, int days)
	: name_(name)
	, days_(days)
	{
	}

	const std::string name_;
	const int days_;
};

class ChildrensMovie : public Movie, protected MovieCommon
{
public:
	ChildrensMovie(const std::string &name, int days)
	: MovieCommon(name, days)
	{
	}

	int amount() const override
	{
		return 2 + std::max(days_ - 3, 0) * 2;
	}
};

class RegularMovie : public Movie, protected MovieCommon
{
public:
	RegularMovie(const std::string &name, int days)
	: MovieCommon(name, days)
	{
	}

	int amount() const override
	{
		return 2 + std::max(days_ - 2, 0) * 2;
	}
};

class NewReleaseMovie : public Movie, protected MovieCommon
{
public:
	NewReleaseMovie(const std::string &name, int days)
	: MovieCommon(name, days)
	{
	}

	int amount() const override
	{
		return 3 * days_;
	}
};

#endif

