#include "KimlikNo.h"
#include "Rastgele.h"

KimlikNo KimlikNoOlustur(){
	KimlikNo this;
	this = (KimlikNo)malloc(sizeof(struct KIMLIKNO));
	this->gecersizKimlik=0;
	this->gecerliKimlik=0;
	return this;
}

char* tcUret(const KimlikNo this){
	
	int tc1,tc2,tc3,tc4,tc5,tc6,tc7,tc8,tc9,tc10,tc11;
	
	Rastgele sayi = RastgeleOlustur();
	
	tc1 = rastgele(sayi,9);
	tc2 = (rastgele(sayi,10))-1;
	tc3 = (rastgele(sayi,10))-1;
	tc4 = (rastgele(sayi,10))-1;
	tc5 = (rastgele(sayi,10))-1;
	tc6 = (rastgele(sayi,10))-1;
	tc7 = (rastgele(sayi,10))-1;
	tc8 = (rastgele(sayi,10))-1;
    tc9 = (rastgele(sayi,10))-1;
	
	tc10 = (((tc1+tc3+tc5+tc7+tc9)*7)-(tc2+tc4+tc6+tc8))%10;
	
	tc11 = (tc1+tc2+tc3+tc4+tc5+tc6+tc7+tc8+tc9+tc10)%10;
	
	//long tc = tc1*10^10+tc2*10^9+tc3*10^8+tc4*10^7+tc5*10^6+tc6*10^5+tc7*10^4+tc8*10^3+tc9*10^2+tc10*10;
	
	char* tckarakter;
	
	//sprintf(tckarakter,"%d",tc);
	
	return tckarakter;
	
}
void tcKontrol(const KimlikNo k, char* girisTc){


}

void kimlikkontrolYaz(const KimlikNo k){
	
};

void KimlikNoYoket (KimlikNo k){
	if(k == NULL) return;
	free(k);
	k = NULL;
}
	