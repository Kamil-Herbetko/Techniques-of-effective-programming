#pragma once
#include <vector>
#include <iostream>

template <typename T> class CMySmartPointer;

template <typename T> class CRefCounter {
public:
	CRefCounter() { i_count = 0;}
	int iAdd() { return(++i_count); }
	int iDec() { return(--i_count); }
	int iGet() { return(i_count); }

	void vPrintPointers();
	void vAddPointer(CMySmartPointer<T>* pcNewSmartPointer);
	void vRemovePointer(CMySmartPointer<T>* pcSmartPointerToRemove);
	std::vector<CMySmartPointer<T>*>* vecGetSmartPointers() { return &vec_CSmartPointers; }

private:
	int i_count;
	std::vector<CMySmartPointer<T>*> vec_CSmartPointers;
};

template <typename T>
void CRefCounter<T>::vPrintPointers() {
	for (int ii = 0; ii < vec_CSmartPointers.size(); ii++) {
		std::cout << vec_CSmartPointers.at(ii) << std::endl;
	}
}

template <typename T>
void CRefCounter<T>::vAddPointer(CMySmartPointer<T>* pcNewSmartPointer) {
	vec_CSmartPointers.push_back(pcNewSmartPointer);
}

template <typename T>
void CRefCounter<T>::vRemovePointer(CMySmartPointer<T>* pcNewSmartPointer) {
	for (int ii = 0; ii < vec_CSmartPointers.size(); ii++) {
		if (vec_CSmartPointers.at(ii) == pcNewSmartPointer) {
			vec_CSmartPointers.erase(vec_CSmartPointers.begin() + ii);
		}
	}
}


template <typename T> class CMySmartPointer {
public:
	CMySmartPointer(T* pcPointer);
	CMySmartPointer(const CMySmartPointer& pcOther);
	~CMySmartPointer();
	
	CRefCounter<T>* pcGetCounter() { return pc_counter; }
	void operator=(const const CMySmartPointer<T>& pcOther);
	T& operator*() { return(*pc_pointer); }
	T* operator->() { return(pc_pointer); }
private:
	CRefCounter<T>* pc_counter;
	T* pc_pointer;
};

template <typename T>
CMySmartPointer<T>::~CMySmartPointer() {
	pc_counter->vRemovePointer(this);

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
	pc_counter->vAddPointer(this);
}

template <typename T>
CMySmartPointer<T>::CMySmartPointer(T* pcPointer) {
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter<T>();
	pc_counter->iAdd();
	pc_counter->vAddPointer(this);
}

template <typename T>
void CMySmartPointer<T>::operator=(const CMySmartPointer<T>& pcOther) {
	pc_counter->vRemovePointer(this);

	if (pc_counter->iDec() == 0)
	{
		delete pc_pointer;
		delete pc_counter;
	}

	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
	pc_counter->vAddPointer(this);
}