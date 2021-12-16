#include "CTreeDynamic.h"

//int main() {
//	v_tree_test();
//	
//	CNodeStatic cRootStatic;
//	cRootStatic.vAddNewChild();
//	cRootStatic.vAddNewChild();
//	cRootStatic.pcGetChild(0)->vSetValue(1);
//	cRootStatic.pcGetChild(1)->vSetValue(2);
//	cRootStatic.pcGetChild(0)->vAddNewChild();
//	cRootStatic.pcGetChild(0)->vAddNewChild();
//	cRootStatic.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
//	cRootStatic.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
//	cRootStatic.pcGetChild(1)->vAddNewChild();
//	cRootStatic.pcGetChild(1)->vAddNewChild();
//	cRootStatic.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
//	cRootStatic.pcGetChild(1)->pcGetChild(1)->vSetValue(22);
//
//	cRootStatic.vPrintAllBelow();
//	std::cout << "\n";
//
//	CNodeStatic cRoot2Static;
//	cRoot2Static.vSetValue(4);
//	cRoot2Static.vAddNewChild();
//	cRoot2Static.vAddNewChild();
//	cRoot2Static.pcGetChild(0)->vSetValue(5);
//	cRoot2Static.pcGetChild(1)->vSetValue(6);
//	cRoot2Static.pcGetChild(0)->vAddNewChild();
//	cRoot2Static.pcGetChild(0)->vAddNewChild();
//	cRoot2Static.pcGetChild(0)->pcGetChild(0)->vSetValue(51);
//	cRoot2Static.pcGetChild(0)->pcGetChild(1)->vSetValue(52);
//	cRoot2Static.pcGetChild(1)->vAddNewChild();
//	cRoot2Static.pcGetChild(1)->vAddNewChild();
//	cRoot2Static.pcGetChild(1)->pcGetChild(0)->vSetValue(61);
//	cRoot2Static.pcGetChild(1)->pcGetChild(1)->vSetValue(62);
//		  
//	cRoot2Static.vPrintAllBelow();
//	std::cout << "\n";
//
//	CTreeStatic cTreeStatic;
//	cTreeStatic.bMoveSubtree(cRootStatic.pcGetChild(0)->pcGetChild(1), cRoot2Static.pcGetChild(1));
//
//	cRootStatic.vPrintAllBelow();
//	std::cout << "\n";
//	cRoot2Static.vPrintAllBelow();
//
//	std::cout << "\n";
//	cRootStatic.pcGetChild(0)->pcGetChild(1)->pcGetChild(0)->pcGetChild(0)->vPrintUp();
//	std::cout << "\n";
//	cRoot2Static.vPrintUp();
//
//	std::cout << "\n";
//	
//	CNodeDynamic<int> cRoot;
//	cRoot.vSetValue(0);
//	cRoot.vAddNewChild();
//	cRoot.vAddNewChild();
//	cRoot.pcGetChild(0)->pcGetRoot()->vSetValue(1);
//	cRoot.pcGetChild(1)->pcGetRoot()->vSetValue(2);
//	cRoot.pcGetChild(0)->pcGetRoot()->vAddNewChild();
//	cRoot.pcGetChild(0)->pcGetRoot()->vAddNewChild();
//	cRoot.pcGetChild(0)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(11);
//	cRoot.pcGetChild(0)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(12);
//	cRoot.pcGetChild(1)->pcGetRoot()->vAddNewChild();
//	cRoot.pcGetChild(1)->pcGetRoot()->vAddNewChild();
//	cRoot.pcGetChild(1)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(21);
//	cRoot.pcGetChild(1)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(22);
//
//	cRoot.vPrintAllBelow();
//	std::cout << "\n";
//
//	CNodeDynamic<int> cRoot2;
//	cRoot2.vSetValue(50);
//	cRoot2.vAddNewChild();
//	cRoot2.vAddNewChild();
//	cRoot2.pcGetChild(0)->pcGetRoot()->vSetValue(5);
//	cRoot2.pcGetChild(1)->pcGetRoot()->vSetValue(6);
//	cRoot2.pcGetChild(0)->pcGetRoot()->vAddNewChild();
//	cRoot2.pcGetChild(0)->pcGetRoot()->vAddNewChild();
//	cRoot2.pcGetChild(0)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(51);
//	cRoot2.pcGetChild(0)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(52);
//	cRoot2.pcGetChild(1)->pcGetRoot()->vAddNewChild();
//	cRoot2.pcGetChild(1)->pcGetRoot()->vAddNewChild();
//	cRoot2.pcGetChild(1)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(61);
//	cRoot2.pcGetChild(1)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(62);
//
//	
//	cRoot.vPrintBreadth();
//	
//	cRoot2.vPrintAllBelow();
//	std::cout << "\n";
//
//	bMoveSubtree(cRoot.pcGetChild(0)->pcGetRoot()->pcGetChild(1)->pcGetRoot(), cRoot2.pcGetChild(0)->pcGetRoot());
//
//	cRoot.vPrintAllBelow();
//	std::cout << "\n";
//
//	cRoot2.vPrintAllBelow();
//	std::cout << "\n";
//
//	cRoot.vPrintBreadth();
//	cRoot2.vPrintBreadth();
//
//	std::cout << "\n";
//
//	CNodeDynamic<double>* cRoot3 = new CNodeDynamic<double>;
//	cRoot3->vSetValue(1.0);
//	cRoot3->vAddNewChild();
//	cRoot3->vAddNewChild();
//	cRoot3->pcGetChild(0)->pcGetRoot()->vSetValue(5.1);
//	cRoot3->pcGetChild(1)->pcGetRoot()->vSetValue(6.2);
//	cRoot3->pcGetChild(0)->pcGetRoot()->vAddNewChild();
//	cRoot3->pcGetChild(0)->pcGetRoot()->vAddNewChild();
//	cRoot3->pcGetChild(0)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(51.1);
//	cRoot3->pcGetChild(0)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(52.2);
//	cRoot3->pcGetChild(1)->pcGetRoot()->vAddNewChild();
//	cRoot3->pcGetChild(1)->pcGetRoot()->vAddNewChild();
//	cRoot3->pcGetChild(1)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(61.1);
//	cRoot3->pcGetChild(1)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(62.2);
//		  
//	cRoot3->vPrintAllBelow();
//	std::cout << "\n";
//
//	CTreeDynamic<double> cTree1;
//	cTree1.vSetRoot(cRoot3);
//	std::cout << *(cTree1.tSum()) << std::endl;
//
//	CNodeDynamic<int>* cRoot4 = new CNodeDynamic<int>;
//	cRoot4->vSetValue(50);
//	cRoot4->vAddNewChild();
//	cRoot4->vAddNewChild();
//	cRoot4->pcGetChild(0)->pcGetRoot()->vSetValue(5);
//	cRoot4->pcGetChild(1)->pcGetRoot()->vSetValue(6);
//	cRoot4->pcGetChild(0)->pcGetRoot()->vAddNewChild();
//	cRoot4->pcGetChild(0)->pcGetRoot()->vAddNewChild();
//	cRoot4->pcGetChild(0)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(51);
//	cRoot4->pcGetChild(0)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(52);
//	cRoot4->pcGetChild(1)->pcGetRoot()->vAddNewChild();
//	cRoot4->pcGetChild(1)->pcGetRoot()->vAddNewChild();
//	cRoot4->pcGetChild(1)->pcGetRoot()->pcGetChild(0)->pcGetRoot()->vSetValue(61);
//	cRoot4->pcGetChild(1)->pcGetRoot()->pcGetChild(1)->pcGetRoot()->vSetValue(62);
//
//	cRoot4->vPrintAllBelow();
//	std::cout << "\n";
//
//	CTreeDynamic<int> cTree2;
//	cTree2.vSetRoot(cRoot4);
//	std::cout << *(cTree2.tSum()) << std::endl;
//
//	
//	return 0;
//}