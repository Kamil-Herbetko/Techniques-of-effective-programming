#include "CTreeStatic.h"

CTreeStatic::CTreeStatic() {
	c_root = CNodeStatic();
}

CTreeStatic::~CTreeStatic() {

}

void CTreeStatic::vPrintTree() {
	c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode) {
	if ((pcNewChildNode != NULL) && (pcParentNode != NULL)) {

		pcNewChildNode->bRecursiveMove(pcParentNode);	
		CNodeStatic* pcNewChildParent = pcNewChildNode->pcGetParent();
		if (pcNewChildParent == NULL) {
			delete pcNewChildNode;
		}

		else {
			pcNewChildParent->bRemoveChild(pcNewChildNode);
		}

		return true;
			

	}

	return false;
	
}

void v_tree_move_test() {
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

	CNodeStatic cRoot2;
	cRoot2.vSetValue(4);
	cRoot2.vAddNewChild();
	cRoot2.vAddNewChild();
	cRoot2.pcGetChild(0)->vSetValue(5);
	cRoot2.pcGetChild(1)->vSetValue(6);
	cRoot2.pcGetChild(0)->vAddNewChild();
	cRoot2.pcGetChild(0)->vAddNewChild();
	cRoot2.pcGetChild(0)->pcGetChild(0)->vSetValue(51);
	cRoot2.pcGetChild(0)->pcGetChild(1)->vSetValue(52);
	cRoot2.pcGetChild(1)->vAddNewChild();
	cRoot2.pcGetChild(1)->vAddNewChild();
	cRoot2.pcGetChild(1)->pcGetChild(0)->vSetValue(61);
	cRoot2.pcGetChild(1)->pcGetChild(1)->vSetValue(62);

	cRoot2.vPrintAllBelow();
	std::cout << "\n";

	CTreeStatic cTree;
	cTree.bMoveSubtree(cRoot.pcGetChild(0)->pcGetChild(1), cRoot2.pcGetChild(1));

	cRoot.vPrintAllBelow();
	std::cout << "\n";
	cRoot2.vPrintAllBelow();
}
