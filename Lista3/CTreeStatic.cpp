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
	if ((pcNewChildNode != NULL) && (pcParentNode != NULL) && (!bNodesAreInTheSameTree(pcParentNode, pcNewChildNode))) {

		pcNewChildNode->bRecursiveMove(pcParentNode);	
		CNodeStatic* pcNewChildParent = pcNewChildNode->pcGetParent();
		if (pcNewChildParent != NULL) {
			pcNewChildParent->bRemoveChild(pcNewChildNode);
		}
		

		return true;
			

	}

	return false;
	
}

bool CTreeStatic::bNodesAreInTheSameTree(CNodeStatic* pcNode1, CNodeStatic* pcNode2) {
	CNodeStatic* pcRoot1 = pcNode1;
	CNodeStatic* pcRoot2 = pcNode2;

	while (pcRoot1->pcGetParent() != NULL) {
		pcRoot1 = pcRoot1->pcGetParent();
	}

	while (pcRoot2->pcGetParent() != NULL) {
		pcRoot2 = pcRoot2->pcGetParent();
	}

	return pcRoot1 == pcRoot2;

}
