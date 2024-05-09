#pragma once
#ifndef SINGLETON_H_
#define SINGLETON_H_

template<class T>
class Singleton
{
public:
	static T& getInstance(void) {
		static T instance;
		return instance;
	}

protected:
	Singleton() = default;
	virtual ~Singleton() = default;
private:
	Singleton(const Singleton& other) {}
	Singleton& operator=(const Singleton& other) {}
};

#endif // SINGLETON_H_