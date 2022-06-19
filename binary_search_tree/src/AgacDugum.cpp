

#include "AgacDugum.hpp"
#include <iostream>

AgacDugum::AgacDugum(){
	sayi=0;
	soySayisi=0;
	sag=NULL;
	sol=NULL;
}

void AgacDugum::setSayi(int sayi){
	this->sayi=sayi;
}

int AgacDugum::getSayi(){
	return sayi;
}

void AgacDugum::setSag(AgacDugum* sag){
	this->sag=sag;
}

AgacDugum* AgacDugum::getSag(){
	return sag;
}

void AgacDugum::setSol(AgacDugum* sol){
	this->sol=sol;
}

AgacDugum* AgacDugum::getSol(){
	return sol;
}

void AgacDugum::setSoySayisi(int soySayisi){
	this->soySayisi=soySayisi;
}

int AgacDugum::getSoySayisi(){
	return soySayisi;
}