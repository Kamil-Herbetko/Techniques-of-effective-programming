#include "CTab.h"
#include <iostream>

CTab::CTab(const CTab& cOther)
{
	v_copy(cOther);
	std::cout << "Copy ";
}

CTab::~CTab()
{
	if (pi_tab != NULL) delete pi_tab;
	std::cout << "Destr ";
}

CTab CTab::operator=(const CTab& cOther)
{
	if (pi_tab != NULL) delete pi_tab;
	v_copy(cOther);
	std::cout << "op= ";
	return(*this);
}

CTab CTab::operator=(CTab&& cOther) noexcept{
	if (pi_tab != NULL) delete pi_tab;
	v_move(cOther);
	return(*this);
}

bool CTab::bSetSize(int iNewSize){
	if (iNewSize < 0) {
		return false;
	}

	int* piTableHelper = new int[iNewSize];
	memcpy(piTableHelper, pi_tab, std::min(iNewSize, i_size) * sizeof(int));

	i_size = iNewSize;

	delete[] pi_tab;
	pi_tab = piTableHelper;
	return true;
}

void CTab::v_copy(const CTab& cOther)
{
	pi_tab = new int[cOther.i_size];
	i_size = cOther.i_size;
	for (int ii = 0; ii < cOther.i_size; ii++)
		pi_tab[ii] = cOther.pi_tab[ii];
}

void CTab::v_move(CTab& cOther){
	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;
	cOther.pi_tab = NULL;
}

CTab::CTab(CTab&& cOther) noexcept {
	v_move(cOther);
	std::cout << "MOVE ";
}



