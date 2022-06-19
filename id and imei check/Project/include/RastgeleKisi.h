#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H

#include "stdio.h"
#include "stdlib.h"


struct RASTGELEKISI {
	
};
typedef struct RASTGELEKISI* RastgeleKisi;

RastgeleKisi RastgeleKisiOlustur();
char* KisiSec(const RastgeleKisi);
int Yas(const RastgeleKisi);
void RastgeleKisiYoket(RastgeleKisi);


#endif