

#ifndef IKIYONLUBAGLILISTE_HPP
#define IKIYONLUBAGLILISTE_HPP

#include "Dugum.hpp"

class IkiYonluBagliListe {
private:
	int kazanc;
	Dugum* head = new Dugum();
	Dugum* ptr = new Dugum();
	
public:
	IkiYonluBagliListe();
	void dugumEkle(Dugum*, string);
	void yazdir();
	~IkiYonluBagliListe();
};


#endif
