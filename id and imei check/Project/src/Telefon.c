#include "Telefon.h"

Telefon TelefonOlustur(){
	Telefon this;
	this = (Telefon)malloc(sizeof(struct TELEFON));
	this->telNo=malloc(sizeof(char)*11);
	//this->telUret = &_telUret;
	//this->telYoket = &_TelefonYoket;
	return this;
	
}

char* _telUret(const Telefon this){
	
	Rastgele sayi = RastgeleOlustur();
	
	int tel1,tel2,tel3,tel4,tel5,tel6,tel7,tel8,tel9,tel10,tel11;
	
	tel1 = 0;
	tel2 = (rastgele(sayi,10))-1;
	tel3 = (rastgele(sayi,10))-1;
	tel4 = (rastgele(sayi,10))-1;
	tel5 = (rastgele(sayi,10))-1;
	tel6 = (rastgele(sayi,10))-1;
	tel7 = (rastgele(sayi,10))-1;
	tel8 = (rastgele(sayi,10))-1;
	tel9 = (rastgele(sayi,10))-1;
	tel10 = (rastgele(sayi,10))-1;
	tel11 = (rastgele(sayi,10))-1;
	
	char teldizi[11];
	teldizi[0]=tel1 +'0';teldizi[1]=tel2 +'0';teldizi[2]=tel3 +'0';
	teldizi[3]=tel4 +'0';teldizi[4]=tel5 +'0';teldizi[5]=tel6 +'0';
	teldizi[6]=tel7 +'0';teldizi[7]=tel8 +'0';teldizi[8]=tel9 +'0';
	teldizi[9]=tel10 +'0';teldizi[10]=tel11 +'0';
	
	for (int i=0;i<11;i++){
		this->telNo[i]=teldizi[i];
	}
	return this->telNo;
}

void TelefonYoket (Telefon t){
	if(t == NULL) return;
	free(t);
	t = NULL;
}