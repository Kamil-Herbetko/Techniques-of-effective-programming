#pragma once

void v_alloc_test_add_5(int iSize);

bool b_alloc_table_2_dim(int**& piTable, int iSizeX, int iSizeY);

bool b_dealloc_table_2_dim(int**& piTable, int iSizeX, int iSizeY);

bool b_alloc_table_3_dim(char***& pcLetters, int iSizeX, int iSizeY, int iSizeZ);
