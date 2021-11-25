#include "CNodeStatic.h"

//CNodeStatic::~CNodeStatic() {

//}

void CNodeStatic::vAddNewChild() {
	CNodeStatic c_child = CNodeStatic();
	c_child.pc_parent_node = this;
	v_children.push_back(c_child);

}

void CNodeStatic::bRecursiveMove(CNodeStatic* pcDestinationParent) {
	
	pcDestinationParent->vAddNewChild();
	std::vector<CNodeStatic>* vChildren = &(pcDestinationParent->v_children);
	CNodeStatic* cNewNode = &(vChildren->back());
	cNewNode->i_val = i_val;

	for (int ii = 0; ii < v_children.size(); ii++) {
		(v_children.at(ii)).bRecursiveMove(cNewNode);
	}

}

bool CNodeStatic::bRemoveChild(CNodeStatic* node) {
	for (int ii = 0; ii < v_children.size(); ii++) {
		if (&v_children.at(ii) == node) {
			v_children.erase(v_children.begin() + ii);
			return true;
		}
	}

	return false;
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset) {
	if ((0 <= iChildOffset) && (iChildOffset < v_children.size())) {
		return &v_children.at(iChildOffset);
	}

	return NULL;
}

void CNodeStatic::vPrintAllBelow() {
	vPrint();

	for (int ii = 0; ii < v_children.size(); ii++) {
		v_children.at(ii).vPrintAllBelow();
	}
}

void CNodeStatic::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL) {
		pc_parent_node -> vPrintUp();
	}
}

void v_tree_test()
{
	CNodeStatic cRoot;
	cRoot.vAddNewChild();
	cRoot.vAddNewChild();
	cRoot.pcGetChild(0)->vSetValue(1);
	cRoot.pcGetChild(1)->vSetValue(2);
	cRoot.pcGetChild(0)->vAddNewChild();
	cRoot.pcGetChild(0)->vAddNewChild();
	cRoot.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	cRoot.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	cRoot.pcGetChild(1)->vAddNewChild();
	cRoot.pcGetChild(1)->vAddNewChild();
	cRoot.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	cRoot.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	cRoot.vPrintAllBelow();
	std::cout << "\n";
	cRoot.pcGetChild(0)->pcGetChild(1)->vPrintUp();

}


