#pragma once
#include <iostream>
#include <vector>

class CTreeDynamic;

class CNodeDynamic {
public:
	CNodeDynamic() { i_val = 0; pc_parent_node = NULL; i_level = 0; i_depth = 0; };
	~CNodeDynamic();

	void vSetValue(int iNewVal) { i_val = iNewVal; };
	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();
	CTreeDynamic* pcGetChild(int iChildOffset);
	void vUpdateDepthAndLevel();

	void vUpdateLevel();

	void vUpdateDepth();

	void vMoveHelper(CNodeDynamic* pcNewParent);
	void vPrintBreadthHelper(int iNum);
	CNodeDynamic* pcGetParent() { return pc_parent_node; };

	
	void vPrint() { std::cout << " " << i_val; };
	void vPrintBreadth();
	void vPrintAllBelow();
private:
	std::vector<CNodeDynamic*> v_children;
	CNodeDynamic* pc_parent_node;
	int i_val;
	int i_level;
	int i_depth;
};

class CTreeDynamic {
public:
	CTreeDynamic();
	~CTreeDynamic();

	CNodeDynamic* pcGetRoot() { return(pc_root); }
	bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode);
	bool bNodesAreInTheSameTree(CNodeDynamic* pcNode1, CNodeDynamic* pcNode2);

	void vSetRoot(CNodeDynamic* pcNewRootNode);

	void vPrintBreadth() { pc_root->vPrintBreadth(); };
	void vPrintTree();
private:
	CNodeDynamic* pc_root;
};

