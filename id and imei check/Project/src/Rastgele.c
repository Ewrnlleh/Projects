#include "Rastgele.h"

Rastgele RastgeleOlustur(){
	Rastgele this;
	this = (Rastgele)malloc(sizeof(struct RASTGELE));
	return this;
}

int rastgele (const Rastgele r, int limit){
	
	static long a = 2;//((time(0))
    a = (a * 125) % 2796203;
    return ((a % limit) + 1);
}

void RastgeleYoket (Rastgele r){
	if(r == NULL) return;
	free(r);
	r = NULL;
}