#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic() {
	pc_root = new CNodeDynamic();
}

CTreeDynamic::~CTreeDynamic() {
	delete pc_root;
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode)
{
	if ((pcParentNode != NULL) && (pcNewChildNode != NULL)) {
		pcNewChildNode->vMoveHelper(pcParentNode);
		return true;
	}

	return false;
}

void CTreeDynamic::vSetRoot(CNodeDynamic* pcNewRootNode) {
	pc_root = pcNewRootNode;
}

void CTreeDynamic::vPrintTree() {
	pc_root->vPrintAllBelow();
}

CNodeDynamic::~CNodeDynamic() {
	for (int ii = 0; ii < v_children.size(); ii++) {
		delete v_children[ii];
	}
}

void CNodeDynamic::vAddNewChild() {
	CNodeDynamic* pcNodeDynamic = new CNodeDynamic();
	pcNodeDynamic->pc_parent_node = this;
	v_children.push_back(pcNodeDynamic);
}

CTreeDynamic* CNodeDynamic::pcGetChild(int iChildOffset) {
	if ((0 <= iChildOffset) && (iChildOffset < v_children.size())) {
		CTreeDynamic* pcTreeDynamic = new CTreeDynamic();
		pcTreeDynamic->vSetRoot(v_children.at(iChildOffset));
		return pcTreeDynamic;
	}

	return NULL;
}

void CNodeDynamic::vMoveHelper(CNodeDynamic* pcNewParent) {
	(pcNewParent->v_children).push_back(this);
	if (pc_parent_node != NULL) {
		std::vector<CNodeDynamic*>* vCurrentParentChildren = &(pc_parent_node->v_children);

			for (int ii = 0; ii < vCurrentParentChildren->size(); ii++) {
				if (vCurrentParentChildren->at(ii) == this) {
					vCurrentParentChildren->erase(vCurrentParentChildren->begin() + ii);
				}
			}
	}

	pc_parent_node = pcNewParent;
	
}

void CNodeDynamic::vPrintAllBelow() {
	vPrint();
	for (int ii = 0; ii < v_children.size(); ii++) {
		v_children.at(ii)->vPrintAllBelow();
	}
}
