#pragma once
#include "CNodeStatic.h"

class CTreeStatic {
public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic* pcGetRoot() { return(&c_root); }
	void vPrintTree();
private:
	CNodeStatic c_root;
};