#include "CNodeStatic.h"

//CNodeStatic::~CNodeStatic() {

//}

void CNodeStatic::vAddNewChild() {
	CNodeStatic c_child = CNodeStatic();
	c_child.pc_parent_node = this;
	v_children.push_back(c_child);

}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset) {
	if (iChildOffset < v_children.size()) {
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
	CNodeStatic c_root;
	c_root.vAddNewChild();
	c_root.vAddNewChild();
	c_root.pcGetChild(0)->vSetValue(1);
	c_root.pcGetChild(1)->vSetValue(2);
	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	c_root.vPrintAllBelow();
	std::cout << "\n";
	c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
	std::cout << "Koniec";
}
