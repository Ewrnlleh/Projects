

#include "Karsilasma.hpp"
#include <iostream>
#include <conio.h>

using namespace std;

void Karsilasma::yazdir(IkiliAramaAgaci* birinci, IkiliAramaAgaci* ikinci,string isimBir,string isimIki){
	cout<<"----------------------------------------------------------"<<endl;
	birinci->yazdir(isimBir);
	cout<<"--------------------\n\n";
	ikinci->yazdir(isimIki);
	cout<<endl;
}

void Karsilasma::oyna(string isimBir, string isimIki, string dosyaAdiBir, string dosyaAdiIki){
	
	IkiliAramaAgaci* birinci = new IkiliAramaAgaci();
	IkiliAramaAgaci* ikinci = new IkiliAramaAgaci();
	
	birinci->dosyadanOku(dosyaAdiBir);
	ikinci->dosyadanOku(dosyaAdiIki);
	
	while(skorBirinci !=5 && skorIkinci !=5 ){
		yazdir(birinci,ikinci,isimBir,isimIki);
		
		if(birinci->getToplamSoy() < ikinci->getToplamSoy()){
			birinci->agacaEkle(ikinci->bulEnBuyuk());
			ikinci->setKok(ikinci->dugumSil(ikinci->getKok(),ikinci->bulEnBuyuk()));
			ikinci->agacaEkle(birinci->getKokSayi());
			birinci->setKok(birinci->dugumSil(birinci->getKok(),birinci->getKokSayi()));
			skorBirinci += 1;
			cout<<"--TEBRIKLER TURU KAZANDINIZ--\n\n";
		}
		else if(ikinci->getToplamSoy() < birinci->getToplamSoy()){
			ikinci->agacaEkle(birinci->bulEnBuyuk());
			birinci->setKok(birinci->dugumSil(birinci->getKok(),birinci->bulEnBuyuk()));
			birinci->agacaEkle(ikinci->getKokSayi());
			ikinci->setKok(ikinci->dugumSil(ikinci->getKok(),ikinci->getKokSayi()));
			skorIkinci += 1;
			cout<<"--MAALESEF BU TURU KAZANAMADINIZ--\n\n";
		}
		else{
			ikinci->agacaEkle(birinci->getKokSayi());
			birinci->setKok(birinci->dugumSil(birinci->getKok(),birinci->getKokSayi()));
			birinci->agacaEkle(ikinci->getKokSayi());
			ikinci->setKok(ikinci->dugumSil(ikinci->getKok(),ikinci->getKokSayi()));
			cout<<"--BERABERE--\n\n";
		}
		cout<<"SKOR\n";
		cout<<isimBir<<" : "<<skorBirinci<<endl;
		cout<<isimIki<<" : "<<skorIkinci<<endl<<endl<<endl;
		birinci->setToplamSoy(0);
		ikinci->setToplamSoy(0);
		_getch();
	}
	
	delete birinci;
	delete ikinci;
}