#ifndef RASTGELE_H
#define RASTGELE_H

#include "stdio.h"
#include "stdlib.h"
#include <time.h>

struct RASTGELE {
	
};
typedef struct RASTGELE* Rastgele;

Rastgele RastgeleOlustur();
int rastgele(const Rastgele,int);
void RastgeleYoket(Rastgele);


#endif