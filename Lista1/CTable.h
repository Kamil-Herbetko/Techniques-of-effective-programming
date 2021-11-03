#pragma once
#include <iostream>
#define DEFAULT_NAME "Table"
#define DEFAULT_SIZE 10
#define COPY_STRING "_copy"

class CTable {
public:
    CTable();
    CTable(CTable& pcOther);
    CTable(std::string sName, int iTableLen);
    //~CTable();

    std::string sGetName();
    int iGetTableLen();
    int* piGetTable();
    void vPrint();

    void vSetName(std::string sName);
    bool bSetNewSize(int iTableLen);
    void vSetValueAt(int iOffset, int iNewVal);
    CTable* pcClone();

    void operator=(CTable& pcOther);
    CTable operator+(CTable& pcOther);

private:
    std::string s_name;
    int i_TableLen;
    int* pi_Table;

};

void v_mod_tab(CTable* pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);

