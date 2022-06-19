

#ifndef KOVA_HPP
#define KOVA_HPP


class Kova{
	private:
		Kova* kovaAdres;
		int kovaRenk;	
		
	public:		
		void setKovaRenk(int);
		int getKovaRenk();
		void setKovaAdres(Kova*);
		Kova* getKovaAdres();		
};

#endif