#pragma once

class CRefCounter
{
public:
	CRefCounter() { i_count = 0; }
	int iAdd() { return(++i_count); }
	int iDec() { return(--i_count); };
	int iGet() { return(i_count); }
private:
	int i_count;
};


template <typename T> class CMySmartPointer {
public:
	CMySmartPointer(T* pcPointer);
	CMySmartPointer(const CMySmartPointer& pcOther);
	~CMySmartPointer();
	
	void operator=(const const CMySmartPointer<T>& pcOther);
	T& operator*() { return(*pc_pointer); }
	T* operator->() { return(pc_pointer); }
private:
	CRefCounter* pc_counter;
	T* pc_pointer;
};

template <typename T>
CMySmartPointer<T>::~CMySmartPointer() {
	if (pc_counter->iDec() == 0)
	{
		delete pc_pointer;
		delete pc_counter;
	}
}

template <typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer<T>& pcOther) {
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::CMySmartPointer(T* pcPointer) {
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter();
	pc_counter->iAdd();
}

template <typename T>
void CMySmartPointer<T>::operator=(const CMySmartPointer<T>& pcOther) {
	if (pc_counter->iDec() == 0)
	{
		delete pc_pointer;
		delete pc_counter;
	}

	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}