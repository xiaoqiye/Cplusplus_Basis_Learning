#pragma once
#ifndef __SHARED_PTR_
#define __SHARED_PTR_

template <typename T>
class CSharedPtr
{
public:
	CSharedPtr(T* vPtr);
	CSharedPtr(const CSharedPtr<T>& vSharedPtr);
	~CSharedPtr();

	T* operator->();
	T& operator*();
	CSharedPtr<T>& operator=(const CSharedPtr<T>& vSharedPtr);

	int getRefCount() const;

private:
	int* m_RefCount;
	T* m_Ptr;
};

template <typename T>
CSharedPtr<T>::CSharedPtr(T* vPtr) :m_RefCount(new int(1)), m_Ptr(vPtr)
{}

template <typename T>
CSharedPtr<T>::CSharedPtr(const CSharedPtr<T>& vSharedPtr) : m_RefCount(&(++vSharedPtr.m_RefCount), m_Ptr(vSharedPtr.m_Ptr))
{}

template <typename T>
CSharedPtr<T>::~CSharedPtr()
{
	if (-- * m_RefCount == 0)
	{
		delete m_Ptr;
		delete m_RefCount;
	}
}

template <typename T>
T* CSharedPtr<T>::operator->()
{
	return m_Ptr;
}

template <typename T>
T& CSharedPtr<T>::operator*()
{
	return *T;
}

template <typename T>
CSharedPtr<T>& CSharedPtr<T>::operator=(const CSharedPtr<T>& vSharedPtr)
{
	++* vSharedPtr.m_RefCount;
	if (this->m_Ptr != nullptr && -- * this->m_RefCount == 0)
	{
		delete this->m_Ptr;
		delete this->m_RefCount;
	}
	this->m_Ptr = vSharedPtr.m_Ptr;
	this->m_RefCount = vSharedPtr.m_RefCount;
	return *this;
}

template <typename T>
int CSharedPtr<T>::getRefCount() const
{
	return *m_RefCount;
}

#endif