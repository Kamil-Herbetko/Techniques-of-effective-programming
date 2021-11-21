#include "CTreeStatic.h"

CTreeStatic::CTreeStatic() {
	c_root = CNodeStatic();
}

CTreeStatic::~CTreeStatic() {

}

void CTreeStatic::vPrintTree() {
	c_root.vPrintAllBelow();
}
