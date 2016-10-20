#ifndef SINGLETON_PATTERN_H
#define SINGLETON_PATTERN_H

class SingletonEager
{
public:
	static
	SingletonEager* only()
	{
		return self_;
	}

	std::string f() const { return "Singleton::f()"; }

private:
	SingletonEager() {}

	static
	SingletonEager *self_;
};

SingletonEager* SingletonEager::self_ = new SingletonEager();

class SingletonLazy
{
public:
	static
	SingletonLazy* only()
	{
		if (!self_)
			self_ = new SingletonLazy();

		return self_;
	}

	std::string f() const { return "Singleton::f()"; }

private:
	SingletonLazy() {}

	static
	SingletonLazy *self_;
};

SingletonLazy* SingletonLazy::self_ = nullptr;

class SingletonLocal
{
public:
	static
	SingletonLocal* only()
	{
		static
		SingletonLocal *self = new SingletonLocal();

		return self;
	}

	std::string f() const { return "Singleton::f()"; }

private:
	SingletonLocal() {}
};

#endif

