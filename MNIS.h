#ifndef MNIS_H
#define MNIS_H

#include <stdio.h>

enum DATA_TYPE {IS_LABEL=2, IS_IMG=4 };

int ReverseInt(int i);
void ReadMNIST(const char *db, int NumberOfImages, double *arr, int DATA_TYPE);

#endif /* MNIS_H */

