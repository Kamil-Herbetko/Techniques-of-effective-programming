#pragma once
#include "CNodeStatic.h"

class CTreeStatic {
public:
	CTreeStatic();
	~CTreeStatic();

	CNodeStatic* pcGetRoot() { return(&c_root); }

	void vPrintTree();

	bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);
private:
	CNodeStatic c_root;
};

void v_tree_move_test();