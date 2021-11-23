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
	if (pcNewChildNode != NULL) {
		bool bCopySuccessful = pcNewChildNode->bRecursiveMove(pcParentNode);

			if (bCopySuccessful) {
				CNodeStatic* pcNewChildParent = pcNewChildNode->pcGetParent();
				if (pcNewChildParent == NULL) {
					delete pcNewChildNode;
				}
				else {
					pcNewChildParent->bRemoveChild(pcNewChildNode);
				}

				return true;
			}

	}

	return false;
	
}
