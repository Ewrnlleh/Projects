
#include "IkiliAramaAgaci.hpp"
#include <iostream>

IkiliAramaAgaci::IkiliAramaAgaci(){
	say=0;
	toplamSoy=0;
	kok=NULL;
}

int IkiliAramaAgaci::getToplamSoy(){
	return toplamSoy;
}
void IkiliAramaAgaci::setToplamSoy(int toplamSoy){
	this->toplamSoy=toplamSoy;
}
AgacDugum* IkiliAramaAgaci::getKok(){
	return kok;
}
void IkiliAramaAgaci::setKok(AgacDugum* dugum){
	kok=dugum;
}
int IkiliAramaAgaci::getKokSayi(){
	return kok->getSayi();
}

void IkiliAramaAgaci::agacaEkle(int sayi){
	
	AgacDugum* yeni= new AgacDugum();
	yeni->setSayi(sayi);
	
	if(kok==NULL){
		kok=yeni;
	}
	else{
		simdiki=kok;
		
		while(1){
			
			ana = simdiki;
			if(sayi > ana->getSayi()){
				simdiki=simdiki->getSag();
				if(simdiki==NULL){
					ana->setSag(yeni);
					return;
				}
			}
			else{
				simdiki = simdiki->getSol();
				if(simdiki==NULL){
					ana->setSol(yeni);
					return;
				}
			}
		}
	}
}

void IkiliAramaAgaci::yazdir(string isim){
	cout<<isim<<" Agac Postorder :"<<endl;
	postorder(getKok());
	cout<<endl<<isim<<" Agac Toplam Soy Sayisi : "<<toplamSoy<<endl;
}
void IkiliAramaAgaci::postorder(AgacDugum* dugum){
	if(dugum==NULL){
		return;
	}
	postorder(dugum->getSol());
	postorder(dugum->getSag());
	dugum->setSoySayisi(sayDugum(dugum));
	cout<<"<"<<dugum->getSayi()<<","<<dugum->getSoySayisi()<<"> ";
	toplamSoy += dugum->getSoySayisi();
	say=0;
	
}

int IkiliAramaAgaci::sayDugum(AgacDugum* dugum){
	if(dugum==NULL){
		return 0;
	}
	if(dugum->getSol()!=NULL){
		say = say+1;
		say = sayDugum(dugum->getSol());
	}
	if(dugum->getSag()!=NULL){
		say = say+1;
		say = sayDugum(dugum->getSag());
	}
	return say;
}

void IkiliAramaAgaci::dosyadanOku(string dosyaAdi){
		
	ifstream dosya;
	dosya.open(dosyaAdi);
	
	if(!dosya){
		cout<<"Dosya okunmasinda hata.!!"<<endl;
		cin.get();
		exit(0);
	}
	
	int sayi;
	while(dosya >> sayi)
	{
		agacaEkle(sayi);
	}
	dosya.close();
}

int IkiliAramaAgaci:: bulEnBuyuk(){
	return enBuyukDeger(getKok());
}
int IkiliAramaAgaci:: enBuyukDeger(AgacDugum* dugum){
	if(dugum->getSag()!= NULL){
		return enBuyukDeger(dugum->getSag());
	}
	return dugum->getSayi();
}

AgacDugum* IkiliAramaAgaci::dugumSil(AgacDugum* dugum,int sayi){
	
	if(dugum == NULL){
		return dugum;
	}
	else if(sayi < dugum->getSayi()){
		dugum->setSol(dugumSil(dugum->getSol(),sayi));
	}
	else if(sayi > dugum->getSayi()){
		dugum->setSag(dugumSil(dugum->getSag(),sayi));
	}
	else{
		if(dugum->getSol() == NULL && dugum->getSag() == NULL){
			delete dugum;
			dugum = NULL;
		}
		else if(dugum->getSol() == NULL){
			AgacDugum* gecici = new AgacDugum();
			gecici = dugum;
			dugum = dugum->getSag();
			delete gecici;
		}
		else if(dugum->getSag() == NULL){
			AgacDugum* gecici = new AgacDugum();
			gecici = dugum;
			dugum = dugum->getSol();
			delete gecici;
		}
		else{
		AgacDugum* gecici = new AgacDugum();
		gecici = dugum->getSol();
		while(gecici->getSag() != NULL){
			gecici = gecici->getSag();
		}
		dugum->setSayi(gecici->getSayi());
		dugum->setSol(dugumSil(dugum->getSol(), gecici->getSayi()));
		}
	}
	return dugum;
}
		
IkiliAramaAgaci::~IkiliAramaAgaci(){
	delete kok;
	delete ana;
	delete simdiki;
}
		
	

		
	


