#pragma once
#include <iostream>
#define DEFAULT_NAME "Table"
#define DEFAULT_SIZE 10
#define COPY_STRING "_copy"
#define PP_ADDED_VALUE 48

class CTable {
public:
    CTable();
    CTable(const CTable& pcOther);
    CTable(std::string sName, int iTableLen);
    ~CTable();
    CTable(CTable&& pcOther) noexcept;

    std::string sGetName();
    int iGetTableLen();
    int* piGetTable();
    void vPrint();

    void vSetName(std::string sName);
    bool bSetNewSize(int iTableLen);
    void vSetValueAt(int iOffset, int iNewVal);
    CTable* pcClone();

    CTable operator=(CTable cOther);
    CTable operator+(CTable& cOther);
    CTable operator++(int);
    friend void swap(CTable& cFirst, CTable& cSecond) noexcept;

private:
    std::string s_name;
    int i_TableLen;
    int* pi_Table;
};

void v_mod_tab(CTable* pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);

