#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic() {

}

CTreeDynamic::~CTreeDynamic() {

}

void CTreeDynamic::vPrintTree() {

}

CNodeDynamic::~CNodeDynamic() {
	for (int ii = 0; ii < v_children.size(); ii++) {
		delete v_children[ii];
	}
}

void CNodeDynamic::vAddNewChild() {
	CNodeDynamic* pcNodeDynamic = new CNodeDynamic();
}

CTreeDynamic* CNodeDynamic::pcGetChild(int iChildOffset) {
	return nullptr;
}

void CNodeDynamic::vPrintAllBelow() {

}