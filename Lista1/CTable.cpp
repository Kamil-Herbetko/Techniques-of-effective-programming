#include "CTable.h"

CTable::CTable(CTable& pcOther) {
    s_name = pcOther.s_name + COPY_STRING;
    i_TableLen = pcOther.i_TableLen;
    pi_Table = new int[i_TableLen];
    memcpy(pi_Table, pcOther.pi_Table, i_TableLen * sizeof(int));
    std::cout << "kopiuj: " << s_name << std::endl;
}

CTable::CTable() {
    s_name = DEFAULT_NAME;
    std::cout << "bezp: " << s_name << std::endl;
    i_TableLen = DEFAULT_SIZE;
    pi_Table = new int[i_TableLen];
}

void CTable::vSetName(std::string sName) {
    s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen < 0) {
        return false;
    }

    int* piTableHelper = new int[iTableLen];
    memcpy(piTableHelper, pi_Table, std::min(iTableLen, i_TableLen) * sizeof(int));

    i_TableLen = iTableLen;

    delete[] pi_Table;
    *pi_Table = *piTableHelper;
    return true;
}

void CTable::vSetValueAt(int iOffset, int iNewVal) {
    if (iOffset < i_TableLen) {
        pi_Table[iOffset] = iNewVal;
    }
}

void CTable::vPrint() {
    for (int ii = 0; ii < i_TableLen; ii++) {
        std::cout << pi_Table[ii] << " ";
    }

    std::cout << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) {
    s_name = sName;
    std::cout << "parametr: " << s_name << std::endl;
    i_TableLen = iTableLen;
    pi_Table = new int[i_TableLen];
}

CTable* CTable::pcClone() {
    CTable* pc_Clone = new CTable(*this);;
    return pc_Clone;
}

/*
CTable::~CTable() {
    delete[] pi_Table;
    std::cout << "usuwam: " << s_name << std::endl;
}
*/

std::string CTable::sGetName() {
    return s_name;
}

int CTable::iGetTableLen() {
    return i_TableLen;
}

int* CTable::piGetTable() {
    return pi_Table;
}

void CTable::operator=(CTable& pcOther) {
    pi_Table = pcOther.pi_Table;
    i_TableLen = pcOther.i_TableLen;
}



int* CTable::operator+(CTable& pcOther) {
    int* piConcatTable = new int [i_TableLen + pcOther.i_TableLen];
    memcpy(piConcatTable, pi_Table, i_TableLen * sizeof(int));
    memcpy(piConcatTable + i_TableLen, pcOther.pi_Table, pcOther.i_TableLen * sizeof(int));
    return piConcatTable;
}

void v_mod_tab(CTable* pcTab, int iNewSize) {
    (*pcTab).bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize) {
    cTab.bSetNewSize(iNewSize);
}