

#ifndef AGACDUGUM_HPP
#define AGACDUGUM_HPP


class AgacDugum{

private:
	int sayi;
	int soySayisi;
	AgacDugum* sag;
	AgacDugum* sol;
	
public:
	AgacDugum();
	void setSayi(int);
	int getSayi();
	void setSag(AgacDugum*);
	AgacDugum* getSag();
	void setSol(AgacDugum*);
	AgacDugum* getSol();
	void setSoySayisi(int);
	int getSoySayisi();


};

#endif