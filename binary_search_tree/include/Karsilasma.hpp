

#ifndef KARSILASMA_HPP
#define KARSILASMA_HPP

#include "IkiliAramaAgaci.hpp"

class Karsilasma{
	
	private:
		int skorBirinci=0;
		int skorIkinci=0;

	public:
		void yazdir(IkiliAramaAgaci*,IkiliAramaAgaci*,string,string);
		void oyna(string,string,string,string);

};

#endif