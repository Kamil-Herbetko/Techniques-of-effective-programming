#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic() {
	pc_root = NULL;
}

CTreeDynamic::~CTreeDynamic() {
	delete pc_root;
}

void CTreeDynamic::vPrintTree() {
	pc_root->vPrintAllBelow();
}

CNodeDynamic::~CNodeDynamic() {
	for (int ii = 0; ii < v_children.size(); ii++) {
		delete v_children[ii];
	}
}

void CNodeDynamic::vAddNewChild() {
	CNodeDynamic* pcNodeDynamic = new CNodeDynamic();
	pcNodeDynamic->pc_parent_node = this;
	v_children.push_back(pcNodeDynamic);
}

CTreeDynamic* CNodeDynamic::pcGetChild(int iChildOffset) {
	if ((0 <= iChildOffset) && (iChildOffset < v_children.size())) {
		CTreeDynamic* pcTreeDynamic = new CTreeDynamic();
		CNodeDynamic* pcRoot = pcTreeDynamic->pcGetRoot();
		pcRoot = v_children.at(iChildOffset);
		return pcTreeDynamic;
	}

	return NULL;
}

void CNodeDynamic::vPrintAllBelow() {
	vPrint();
	for (int ii = 0; ii < v_children.size(); ii++) {
		v_children.at(ii)->vPrintAllBelow();
	}
}