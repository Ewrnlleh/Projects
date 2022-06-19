#include "Kisi.h"

Kisi KisiOlustur(){
	Kisi this;
	this = (Kisi)malloc(sizeof(struct KISI));
	this->kimlikNumarasi=malloc(sizeof(char)*11);
	this->isim=malloc(sizeof(char)*25);
	this->telefonNumarasi=malloc(sizeof(char)*11);
	this->imeiNumarasi=malloc(sizeof(char)*15);
	this->yas=0;
	this->kimlikNo = KimlikNoOlustur();
	this->telefon = TelefonOlustur();
	this->imeiNo = IMEINoOlustur();
	this->rastgeleKisi = RastgeleKisiOlustur();
	//this->KisiYoket = &_KisiYoket;
	//this->kisiUret = &_kisiUret;
	//this->kisiYaz = &_kisiYaz;
	return this;
}

void kisiUret(const Kisi k){

	//this->isim = this->rastgeleKisi->KisiSec(this->rastgeleKisi);
	//this->yas = this->rastgeleKisi->Yas(this->rastgeleKisi);

	//this->kimlikNumarasi = this->kimlikNo->KimlikNoOlustur(this->kimlikNo);

	//this->telefonNumarasi = this->telefon->TelefonOlustur(this->telefon);  

	//this->imeiNumarasi = this->imeiNo->IMEINoOlustur(this->imeiNo);
	
}

char* kisiYaz(const Kisi k){
	
	//return(kimlikNumarasi+" "+isim+" "+yas+" "+telefonNumarasi+" ("+imeiNumarasi+")");
}


void KisiYoket (Kisi k){
	if(k == NULL) return;
	free(k);
	k = NULL;
}