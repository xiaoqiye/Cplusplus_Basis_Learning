#pragma once
#ifndef __SINGLETON__
#define __SINGLETON__

//Problem: �̲߳���ȫ�����ʺ϶��̻߳���
//Solution: �ڴ���ʱ��������ʹ��Local static����
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
