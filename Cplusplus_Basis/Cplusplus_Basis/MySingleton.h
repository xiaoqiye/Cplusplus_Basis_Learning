#pragma once
#ifndef __SINGLETON__
#define __SINGLETON__

//Problem: 线程不安全，不适合多线程环境
//Solution: 在创建时加锁或者使用Local static对象
class CSingleton
{
public:
	~CSingleton();
	static CSingleton* getInstance();

private:
	CSingleton();
	static CSingleton* m_Singleton;

	int* m_Data = nullptr;
	float m_Count = 1.0f;
};

CSingleton* CSingleton::m_Singleton = nullptr;

CSingleton::CSingleton()
{
	m_Data = new int(1);
	m_Count = 2.0f;
}

CSingleton::~CSingleton()
{
	if (m_Singleton != nullptr)
	{
		delete m_Singleton;
	}
}

CSingleton* CSingleton::getInstance()
{
	if (m_Singleton != nullptr)
		return m_Singleton;

	m_Singleton = new CSingleton();
	return m_Singleton;
}

#endif // !__SINGLETON__
