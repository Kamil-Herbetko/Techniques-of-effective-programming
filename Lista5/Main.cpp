#include "CMySmartPointer.h"
#include "CTab.h"


int main() {
	CTab* c_Tab_0 = new CTab();
	CTab* c_Tab_1 = new CTab();

	CMySmartPointer<CTab> p1 = CMySmartPointer<CTab>(c_Tab_0);
	p1.pcGetCounter()->vPrintPointers();
	std::cout << std::endl;
	CMySmartPointer<CTab> p2 = CMySmartPointer<CTab>(p1);
	CMySmartPointer<CTab> p3 = CMySmartPointer<CTab>(c_Tab_1);

	p1.pcGetCounter()->vPrintPointers();
	std::cout << std::endl;

	p3.pcGetCounter()->vPrintPointers();
	std::cout << std::endl;

	p2 = p3;

	p1.pcGetCounter()->vPrintPointers();
	std::cout << std::endl;

	p3.pcGetCounter()->vPrintPointers();
	std::cout << std::endl;

	return 0;
}