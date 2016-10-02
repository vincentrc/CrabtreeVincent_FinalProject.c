#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef __PRJ__
#define __PRJ__

#define MAXD  20


struct book {
	int ID; 
  	char Title[50];
    char Author[50];
	int SubjectCode;
	int BorrowingAge;
	char BorrowerName[50];
	struct book *nextbook;
};


#endif
