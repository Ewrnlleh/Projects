#ifndef IMEINO_H
#define IMEINO_H

#include "stdio.h"
#include "stdlib.h"

struct IMEINO{
	
	int gecersizImei;
	int gecerliImei;
	
	char* (*imeiNoUret)(struct IMEINO*);
	void (*imeiNoKontrol)(struct IMEINO*, char*);
	void (*imeiNoKontrolYaz)(struct IMEINO*);
	int (*imeibasamaklariTopla)(struct IMEINO*, int*);
	void (*imeiNoYoket)(struct IMEINO*);
};
typedef struct IMEINO* IMEINo;

IMEINo IMEINoOlustur();
char* imeiUret(const IMEINo);
void imeiKontrol(const IMEINo,char*);
void imeikontrolYaz(const IMEINo);
int basamaklariTopla(const IMEINo,int*);
void IMEINoYoket(IMEINo);



#endif