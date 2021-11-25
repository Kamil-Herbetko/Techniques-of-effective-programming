#pragma once
#include "CNodeStatic.h"

class CTreeStatic {
public:
	CTreeStatic();
	~CTreeStatic();

	CNodeStatic* pcGetRoot() { return(&c_root); }

	void vPrintTree();

	bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);
	bool bNodesAreInTheSameTree(CNodeStatic* pcNode1, CNodeStatic* pcNode2);
private:
	CNodeStatic c_root;
};
