#pragma once
#include <iostream>
#include <vector>

template<typename T> class CTreeDynamic;

template<typename T> class CNodeDynamic {
public:
	CNodeDynamic() { pt_val = new T; pc_parent_node = NULL; i_level = 0; i_depth = 0; };
	~CNodeDynamic();

	void vSetValue(T tNewVal) {*pt_val = tNewVal; };
	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();
	CTreeDynamic<T>* pcGetChild(int iChildOffset);
	void vUpdateDepthAndLevel();

	void vUpdateLevel();

	void vUpdateDepth();

	void vMoveHelper(CNodeDynamic<T>* pcNewParent);
	void vPrintBreadthHelper(int iNum);
	CNodeDynamic<T>* pcGetParent() { return pc_parent_node; };

	
	void vPrint() { std::cout << " " << *pt_val; };
	void vPrintBreadth();
	void vPrintAllBelow();
private:
	std::vector<CNodeDynamic<T>*> v_children;
	CNodeDynamic<T>* pc_parent_node;
	T* pt_val;
	int i_level;
	int i_depth;
};

template<typename T> class CTreeDynamic {
public:
	CTreeDynamic();
	~CTreeDynamic();

	CNodeDynamic<T>* pcGetRoot() { return(pc_root); }
	bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode);
	bool bNodesAreInTheSameTree(CNodeDynamic<T>* pcNode1, CNodeDynamic<T>* pcNode2);

	void vSetRoot(CNodeDynamic<T>* pcNewRootNode);

	void vPrintBreadth() { pc_root->vPrintBreadth(); };
	void vPrintTree();
private:
	CNodeDynamic<T>* pc_root;
};

template <typename T>
CTreeDynamic<T>::CTreeDynamic() {
	pc_root = new CNodeDynamic<T>();
}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic() {
	delete pc_root;
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode)
{
	if ((pcParentNode != NULL) && (pcNewChildNode != NULL) && (!bNodesAreInTheSameTree(pcParentNode, pcNewChildNode))) {
		pcNewChildNode->vMoveHelper(pcParentNode);
		return true;
	}

	return false;
}

template <typename T>
bool CTreeDynamic<T>::bNodesAreInTheSameTree(CNodeDynamic<T>* pcNode1, CNodeDynamic<T>* pcNode2) {
	CNodeDynamic<T>* pcRoot1 = pcNode1;
	CNodeDynamic<T>* pcRoot2 = pcNode2;

	while (pcRoot1->pcGetParent() != NULL) {
		pcRoot1 = pcRoot1->pcGetParent();
	}

	while (pcRoot2->pcGetParent() != NULL) {
		pcRoot2 = pcRoot2->pcGetParent();
	}

	return pcRoot1 == pcRoot2;

}

template <typename T>
void CTreeDynamic<T>::vSetRoot(CNodeDynamic<T>* pcNewRootNode) {
	pc_root = pcNewRootNode;
}

template <typename T>
void CTreeDynamic<T>::vPrintTree() {
	pc_root->vPrintAllBelow();
}

template <typename T>
CNodeDynamic<T>::~CNodeDynamic() {
	for (int ii = 0; ii < v_children.size(); ii++) {
		delete v_children[ii];
	}
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild() {
	CNodeDynamic<T>* pcNodeDynamic = new CNodeDynamic();
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

template <typename T>
CTreeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset) {
	if ((0 <= iChildOffset) && (iChildOffset < v_children.size())) {
		CTreeDynamic<T>* pcTreeDynamic;
		pcTreeDynamic = new CTreeDynamic<T>();
		pcTreeDynamic->vSetRoot(v_children.at(iChildOffset));
		return pcTreeDynamic;
	}

	return NULL;
}

template <typename T>
void CNodeDynamic<T>::vUpdateDepthAndLevel() {
	CNodeDynamic<T>* pcRoot = this;

	while (pcRoot->pc_parent_node != NULL) {
		pcRoot = pcRoot->pc_parent_node;
	}
	pcRoot->i_level = 0;
	pcRoot->vUpdateLevel();
	pcRoot->vUpdateDepth();

}

template <typename T>
void CNodeDynamic<T>::vUpdateDepth() {
	i_depth = i_level;
	for (int ii = 0; ii < v_children.size(); ii++) {
		v_children.at(ii)->vUpdateDepth();
	}

	for (int ii = 0; ii < v_children.size(); ii++) {
		if (v_children.at(ii)->i_depth > i_depth) {
			i_depth = v_children.at(ii)->i_depth;
		}
	}
}

template <typename T>
void CNodeDynamic<T>::vUpdateLevel() {
	for (int ii = 0; ii < v_children.size(); ii++)
	{
		v_children.at(ii)->i_level = i_level + 1;
		v_children.at(ii)->vUpdateLevel();
	}
}

template <typename T>
void CNodeDynamic<T>::vMoveHelper(CNodeDynamic<T>* pcNewParent) {
	(pcNewParent->v_children).push_back(this);
	if (pc_parent_node != NULL) {
		std::vector<CNodeDynamic<T>*>* vCurrentParentChildren = &(pc_parent_node->v_children);

		for (int ii = 0; ii < vCurrentParentChildren->size(); ii++) {
			if (vCurrentParentChildren->at(ii) == this) {
				vCurrentParentChildren->erase(vCurrentParentChildren->begin() + ii);
			}
		}

		vCurrentParentChildren->back()->vUpdateDepthAndLevel();
	}

	pc_parent_node = pcNewParent;
	vUpdateDepthAndLevel();

}

template <typename T>
void CNodeDynamic<T>::vPrintBreadthHelper(int iNum) {
	if (i_level == iNum) {
		vPrint();
	}
	else {
		for (int ii = 0; ii < v_children.size(); ii++) {
			v_children.at(ii)->vPrintBreadthHelper(iNum);
		}
	}
}

template <typename T>
void CNodeDynamic<T>::vPrintBreadth() {
	for (int ii = 0; ii <= i_depth; ii++) {
		vPrintBreadthHelper(ii);
		std::cout << "\n";
	}
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
	vPrint();
	for (int ii = 0; ii < v_children.size(); ii++) {
		v_children.at(ii)->vPrintAllBelow();
	}
}