

#include "Dugum.hpp"
#include <string>


Dugum::Dugum()
{
	kelime = "";
	rakam = 0;
	ileri = NULL;
	geri = NULL;

}

void Dugum::setKelime(string kelime) {
	this->kelime = kelime;
}

string Dugum::getKelime() {
	return kelime;
}

void Dugum::setRakam(int rakam) {
	this->rakam = rakam;
}

int Dugum::getRakam() {
	return rakam;
}

void Dugum::setIleri(Dugum* ilr) {
	ileri = ilr;
}

Dugum* Dugum::getIleri() {
	return ileri;
}

void Dugum::setGeri(Dugum* gr) {
	geri = gr;
}

Dugum* Dugum::getGeri() {
	return geri;
}



