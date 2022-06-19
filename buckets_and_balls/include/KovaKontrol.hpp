

#ifndef KOVAKONTROL_HPP
#define KOVAKONTROL_HPP
#include "Kova.hpp"
#include "Top.hpp"

class KovaKontrol{
	private:
		Kova* kovaAdres;
		Top* topAdres;
		int renk;
		char harf = '-';
	
	public:	
		void kovaOlustur();
		
		void setKovaAdres(Kova*);
		void setTopAdres(Top*);
		void setRenk(int);
		void setHarf(char);
		Top* getTopAdres();
		char getHarf();
			
};


#endif