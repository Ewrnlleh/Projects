
#include "IkiYonluBagliListe.hpp"
#include <iostream>
using namespace std;


IkiYonluBagliListe::IkiYonluBagliListe()
{
	kazanc = 0;
	head = NULL;
}


void IkiYonluBagliListe::dugumEkle(Dugum* n, string k)
{
	int solSayim = 0;
	if (head == NULL)
	{
		head = n;
		head->setKelime(k);

	}
	else
	{
		ptr = head;
		while (ptr->getIleri() != NULL)
		{
			ptr = ptr->getIleri();
		}
		ptr->setIleri(n);
		n->setGeri(ptr);


		ptr = n;
		n->setKelime(k);
		
		while (ptr->getGeri() != NULL)
		{
			ptr = ptr->getGeri();
			solSayim++;
			if (n->getKelime()== ptr->getKelime())
			{
				n->setKelime("");
				n->setRakam(solSayim);
				kazanc += (k.size() - to_string(solSayim).length());
				break;
			}
		}
	}
}
void IkiYonluBagliListe::yazdir()
{
	if (head == NULL)
	{
		cout<<"Dosyada herhangi bir icerik bulunamadi!";
	}

	else
	{

		ptr = head;

		cout << ptr->getGeri() << "<-";
		while (ptr != NULL)
		{
			cout << ":" << ptr->getKelime() << " - " << ptr->getRakam() << ":";
			ptr = ptr->getIleri();
			if(ptr!=NULL)
			{
				cout<< "<->";
			}
		}

		cout << "->" << ptr << endl;
		cout << "Toplam Kazanc : " << kazanc << " Byte";
	}

}


IkiYonluBagliListe::~IkiYonluBagliListe() {
	delete head;
	delete ptr;
}