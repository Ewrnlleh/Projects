#ifndef KIMLIKNO_H
#define KIMLIKNO_H

#include "stdio.h"
#include "stdlib.h"

struct KIMLIKNO{
	
	int gecersizKimlik;
	int gecerliKimlik;
};
typedef struct KIMLIKNO* KimlikNo;

KimlikNo KimlikNoOlustur();
char* tcUret(const KimlikNo);
void tcKontrol(const KimlikNo,char*);
void kimlikkontrolYaz(const KimlikNo);
void KimlikNoYoket(KimlikNo);

#endif