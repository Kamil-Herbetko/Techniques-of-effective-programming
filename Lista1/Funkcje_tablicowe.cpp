#include <iostream>
#include "Funkcje_tablicowe.h"

void v_alloc_test_add_5(int iSize) {
	if (iSize > 0) {
		const int iAdd = 5;
		int* piTable = new int[iSize];

		for (int ii = 0; ii < iSize; ii++) {
			piTable[ii] = ii + iAdd;
		}

		for (int ii = 0; ii < iSize; ii++) {
			std::cout << piTable[ii] << " ";
		}

		std::cout << '\n';

		delete[] piTable;
	}
}

bool b_alloc_table_2_dim(int**& piTable, int iSizeX, int iSizeY) {
	if ((iSizeX <= 0) || (iSizeY <= 0)) {
		return false;
	}
	else {
		piTable = new int* [iSizeX];

		for (int ii = 0; ii < iSizeX; ii++) {
			piTable[ii] = new int[iSizeY];
		}

		return true;
	}
}

bool b_dealloc_table_2_dim(int**& piTable, int iSizeX, int iSizeY) {
	if ((iSizeX <= 0) || (iSizeY <= 0)) {
		return false;
	}
	else {
		for (int ii = 0; ii < iSizeX; ii++) {
			delete[] piTable[ii];
		}

		delete[] piTable;

		return true;
	}
}

bool b_alloc_table_3_dim(char***& pcLetters, int iSizeX, int iSizeY, int iSizeZ) {
	if ((iSizeX <= 0) || (iSizeY <= 0) || (iSizeZ <= 0)) {
		return false;
	}
	else {
		pcLetters = new char** [iSizeX];

		for (int ii = 0; ii < iSizeX; ii++) {
			pcLetters[ii] = new char* [iSizeY];

			for (int ij = 0; ij < iSizeY; ij++) {
				pcLetters[ii][ij] = new char[iSizeZ];
			}
		}
		
		return true;
	}
}