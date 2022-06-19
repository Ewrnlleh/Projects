#include "IMEINo.h"

IMEINo IMEINoOlustur(){
	IMEINo this;
	this = (IMEINo)malloc(sizeof(struct IMEINO));
	this->gecersizImei=0;
	this->gecerliImei=0;
	this->imeiNoUret = &imeiUret;
	this->imeiNoKontrol = &imeiKontrol;
	this->imeiNoKontrolYaz = &imeikontrolYaz;
	this->imeibasamaklariTopla = &basamaklariTopla;
	this->imeiNoYoket = &IMEINoYoket;
	return this;
}

char* imeiUret(const IMEINo this){
	
}



void imeiKontrol(const IMEINo this, char* girisTc){


}

void imeikontrolYaz(const IMEINo this){
	printf("IMEI Kontrol");
	printf("%d  Geçerli",this->gecerliImei);
	printf("%d  Geçersiz",this->gecersizImei);
	
};

int basamaklariTopla(const IMEINo this, int* sayi){
	/*int toplam=0;
	while(sayi > 0) {
		toplam += sayi % 10;
		sayi = sayi/10;
	}
	return toplam;*/
	
}

void IMEINoYoket (IMEINo this){
	if(this == NULL) return;
	free(this);
	this = NULL;
}