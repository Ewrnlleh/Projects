#ifndef TELEFON_H
#define TELEFON_H

#include "stdio.h"
#include "stdlib.h"
#include "Rastgele.h"

struct TELEFON {
	
	char * telNo;
	char (*telUret)(struct TELEFON*);
	void (*telYoket)(struct TELEFON*);
	
};
typedef struct TELEFON* Telefon;

Telefon TelefonOlustur();
char* _telUret(const Telefon);
void _TelefonYoket(Telefon);



#endif