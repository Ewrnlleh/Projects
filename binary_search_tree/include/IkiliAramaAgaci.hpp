

#ifndef IKILIARAMAAGACI_HPP
#define IKILIARAMAAGACI_HPP

#include <string>
#include "AgacDugum.hpp"
#include <fstream>

using namespace std;

class IkiliAramaAgaci{
	private:
		int say;
		int toplamSoy;
		AgacDugum* kok = new AgacDugum();
		AgacDugum* ana = new AgacDugum();
		AgacDugum* simdiki = new AgacDugum();
		int enBuyukDeger(AgacDugum*);
		void postorder(AgacDugum*);
		int sayDugum(AgacDugum*);
		
	public:
		IkiliAramaAgaci();

		void dosyadanOku(string);
		void yazdir(string);
	
		void agacaEkle(int);
		AgacDugum* dugumSil(AgacDugum*,int);
		int bulEnBuyuk();
		
		AgacDugum* getKok();
		void setKok(AgacDugum*);
		int getKokSayi();
		int getToplamSoy();
		void setToplamSoy(int);
		
		~IkiliAramaAgaci();
};


#endif