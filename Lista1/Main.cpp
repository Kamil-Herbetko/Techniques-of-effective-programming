#include "CTable.h"
#include "Funkcje_tablicowe.h"

int main() {
	v_alloc_test_add_5(10);
	
	int** piTable;
	bool bIfProperlyAllocated = b_alloc_table_2_dim(piTable, 2, 3);
	std::cout << bIfProperlyAllocated << std::endl;

	bIfProperlyAllocated = b_dealloc_table_2_dim(piTable, 2, 3);
	std::cout << bIfProperlyAllocated << std::endl;

	
	CTable cTable("Table name", 10);
	CTable* pcTable = cTable.pcClone();
	delete pcTable;

	v_mod_tab(&cTable, 15);
	std::cout << cTable.iGetTableLen() << std::endl;

	v_mod_tab(cTable, 10);
	std::cout << cTable.iGetTableLen() << std::endl;

	CTable* pcTableOfTables = new CTable[3];
	delete[] pcTableOfTables;
	
	/*
	CTable c_tab_0("table 0", 8), c_tab_1("table 1", 8);
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);

	for (int ii = 0; ii < 6; ii++){
		c_tab_0.vSetValueAt(ii, ii + 1);
	}

	for (int ii = 0; ii < 4; ii++) {
		c_tab_1.vSetValueAt(ii, ii + 51);
	}

	c_tab_0 = c_tab_1;
	c_tab_1.vSetValueAt(2, 123);
	c_tab_0.vPrint();
	c_tab_1.vPrint();

	*/
	return 0;
}