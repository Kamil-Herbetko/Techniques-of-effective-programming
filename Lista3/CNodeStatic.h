#pragma once
#include <iostream>
#include <vector>

class CNodeStatic {
public:
	CNodeStatic() { i_val = 0; pc_parent_node = NULL; };
	//~CNodeStatic();

	void vSetValue(int iNewVal) { i_val = iNewVal; };

	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();
	CNodeStatic* pcGetChild(int iChildOffset);

	void vPrint() { std::cout << " " << i_val; };
	void vPrintAllBelow();
	void vPrintUp();

	bool bRecursiveMove(CNodeStatic* pcDestinationParent);

private:
	std::vector<CNodeStatic> v_children;
	CNodeStatic* pc_parent_node;
	int i_val;
};

void v_tree_test();