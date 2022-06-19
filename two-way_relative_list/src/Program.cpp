



#include <fstream>
#include <iostream>
#include <string>

#include "IkiYonluBagliListe.hpp"


using namespace std;

int main()
{
	
	IkiYonluBagliListe* obj= new IkiYonluBagliListe();


	fstream dosya;
	string kelime;
	
	string dosyaIsim = "icerik.txt";
	
	dosya.open(dosyaIsim.c_str());
	
	while (dosya >> kelime)
		
		{
			Dugum* nesne = new Dugum();
			
			obj->dugumEkle(nesne,kelime);
		
		}
		
		obj->yazdir();

	delete obj;
	
	cin.get();

}

