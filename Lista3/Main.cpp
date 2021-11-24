#include "CTreeStatic.h"
#include "CTreeDynamic.h"

int main() {
	//v_tree_test();
	//v_tree_move_test();

	CNodeDynamic cRoot;
	cRoot.vAddNewChild();
	cRoot.vAddNewChild();
	cRoot.pcGetChild(0)->pcGetRoot()->vSetValue(1);
	cRoot.pcGetChild(1)->pcGetRoot()->vSetValue(2);
	cRoot.pcGetChild(0)->pcGetRoot()->vAddNewChild();
	cRoot.pcGetChild(0)->pcGetRoot()->vAddNewChild();
	cRoot.pcGetChild(0)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(11);
	cRoot.pcGetChild(0)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(12);
	cRoot.pcGetChild(1)->pcGetRoot()->vAddNewChild();
	cRoot.pcGetChild(1)->pcGetRoot()->vAddNewChild();
	cRoot.pcGetChild(1)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(21);
	cRoot.pcGetChild(1)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(22);

	cRoot.vPrintAllBelow();
	std::cout << "\n";

	CNodeDynamic cRoot2;
	cRoot2.vAddNewChild();
	cRoot2.vAddNewChild();
	cRoot2.pcGetChild(0)->pcGetRoot()->vSetValue(5);
	cRoot2.pcGetChild(1)->pcGetRoot()->vSetValue(6);
	cRoot2.pcGetChild(0)->pcGetRoot()->vAddNewChild();
	cRoot2.pcGetChild(0)->pcGetRoot()->vAddNewChild();
	cRoot2.pcGetChild(0)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(51);
	cRoot2.pcGetChild(0)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(52);
	cRoot2.pcGetChild(1)->pcGetRoot()->vAddNewChild();
	cRoot2.pcGetChild(1)->pcGetRoot()->vAddNewChild();
	cRoot2.pcGetChild(1)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(61);
	cRoot2.pcGetChild(1)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(62);

	cRoot2.vPrintAllBelow();
	std::cout << "\n";

	CTreeDynamic cTree;
	cTree.bMoveSubtree(cRoot.pcGetChild(0)->pcGetRoot()->pcGetChild(1)->pcGetRoot(), cRoot2.pcGetChild(0)->pcGetRoot());

	cRoot.vPrintAllBelow();
	std::cout << "\n";

	cRoot2.vPrintAllBelow();
	std::cout << "\n";

	return 0;
}