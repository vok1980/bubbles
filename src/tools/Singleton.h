
#pragma once



template<class T>
class Singleton
{
public:
	static T& instance(void)
	{
		static T obj;
		return obj;
	}

protected:
	Singleton(){};
	virtual ~Singleton(){};

private:
	Singleton(const Singleton<T>&);
	const Singleton<T>& operator=(const Singleton<T>&);
};