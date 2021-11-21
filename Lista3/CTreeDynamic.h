#pragma once
#include <iostream>
#include <vector>

class CTreeDynamic;

class CNodeDynamic {
public:
	CNodeDynamic() { i_val = 0; pc_parent_node = NULL; };
	~CNodeDynamic();
	void vSetValue(int iNewVal) { i_val = iNewVal; };
	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();
	CTreeDynamic* pcGetChild(int iChildOffset);
	void vPrint() { std::cout << " " << i_val; };
	void vPrintAllBelow();
private:
	std::vector<CNodeDynamic*> v_children;
	CNodeDynamic* pc_parent_node;
	int i_val;
};

class CTreeDynamic {
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic* pcGetRoot() { return(pc_root); }
	void vPrintTree();
private:
	CNodeDynamic* pc_root;
};