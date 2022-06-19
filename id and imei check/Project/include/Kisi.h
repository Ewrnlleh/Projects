#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "stdlib.h"
#include "RastgeleKisi.h"
#include "KimlikNo.h"
#include "Telefon.h"
#include "IMEINo.h"

struct KISI{
	char* kimlikNumarasi;
    char* isim;
    char* telefonNumarasi;
	char* imeiNumarasi;
	int yas;
	KimlikNo kimlikNo;
	Telefon telefon;
	IMEINo imeiNo;
	RastgeleKisi rastgeleKisi;
	void (*KisiYoket)(struct KISI*);
	void (*kisiUret)(struct KISI*);
	char* (*kisiYaz)(struct KISI*);
};
typedef struct KISI* Kisi;

Kisi KisiOlustur();
char* _kisiYaz(const Kisi);
void _kisiUret(const Kisi);
void _KisiYoket(Kisi);


#endif