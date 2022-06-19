#include "RastgeleKisi.h"

RastgeleKisi RastgeleKisiOlustur(){
	RastgeleKisi this;
	this = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
	return this;
	
}

char* KisiSec(const RastgeleKisi r){
	
	
}

int Yas(const RastgeleKisi r){
	
	
}

void RastgeleKisiYoket (RastgeleKisi r){
	if(r == NULL) return;
	free(r);
	r = NULL;
}