#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic() {
	pc_root = new CNodeDynamic();
}

CTreeDynamic::~CTreeDynamic() {
	delete pc_root;
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode)
{
	if ((pcParentNode != NULL) && (pcNewChildNode != NULL) && (!bNodesAreInTheSameTree(pcParentNode, pcNewChildNode))) {
		pcNewChildNode->vMoveHelper(pcParentNode);
		return true;
	}

	return false;
}

bool CTreeDynamic::bNodesAreInTheSameTree(CNodeDynamic* pcNode1, CNodeDynamic* pcNode2) {
	CNodeDynamic* pcRoot1 = pcNode1;
	CNodeDynamic* pcRoot2 = pcNode2;

	while (pcRoot1->pcGetParent() != NULL) {
		pcRoot1 = pcRoot1->pcGetParent();
	}

	while (pcRoot2->pcGetParent() != NULL) {
		pcRoot2 = pcRoot2->pcGetParent();
	}

	return pcRoot1 == pcRoot2;

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
	pcNodeDynamic->i_level = i_level + 1;


	CNodeDynamic* pcRoot = this;
	
	while (pcRoot->pc_parent_node != NULL) {
		pcRoot = pcRoot->pc_parent_node;
	}

	if (pcRoot->i_depth < i_level + 1) {
		pcRoot->i_depth = i_level + 1;
	}

	pcNodeDynamic->i_depth = i_depth;
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

void CNodeDynamic::vUpdateDepthAndLevel() {
	CNodeDynamic* pcRoot = this;

	while (pcRoot->pc_parent_node != NULL) {
		pcRoot->pc_parent_node;
	}
	pcRoot->i_level = 0;
	pcRoot->vUpdateLevel();
	pcRoot->vUpdateDepth();

}

void CNodeDynamic::vUpdateDepth() {
	i_depth = i_level;
	for (int ii = 0; ii < v_children.size(); ii++) {
		v_children.at(ii)-> vUpdateDepth();
	}
	
	for (int ii = 0; ii < v_children.size(); ii++)	{
		if (v_children.at(ii)->i_level > i_depth) {
			i_depth = v_children.at(ii)->i_level;
		}
	}
}

void CNodeDynamic::vUpdateLevel() {
	for (int ii = 0; ii < v_children.size(); ii++)
	{
		v_children.at(ii)->i_level = i_level + 1;
		v_children.at(ii)->vUpdateLevel();
	}
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

			vCurrentParentChildren->back()->vUpdateDepthAndLevel();
	}
	
	pcNewParent->iGetChildrenNumber();

	pc_parent_node = pcNewParent;
	
}

void CNodeDynamic::vPrintBreadthHelper(int iNum) {
	if (i_level == iNum) {
		vPrint();
	}
	else {
		for (int ii = 0; ii < v_children.size(); ii++) {
			v_children.at(ii)->vPrintBreadthHelper(iNum);
		}
	}
}


void CNodeDynamic::vPrintBreadth() {
	for (int ii = 0; ii <= i_depth; ii++) {
		vPrintBreadthHelper(ii);
		std::cout << "\n";
	}
}

void CNodeDynamic::vPrintAllBelow() {
	vPrint();
	for (int ii = 0; ii < v_children.size(); ii++) {
		v_children.at(ii)->vPrintAllBelow();
	}
}
