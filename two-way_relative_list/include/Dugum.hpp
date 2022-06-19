

#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <string>
using namespace std;

class Dugum {
private:
	string kelime;
	int rakam;
	Dugum* ileri;
	Dugum* geri;

public:
	Dugum();

	void setKelime(string);
	string getKelime();
	void setRakam(int);
	int getRakam();
	void setIleri(Dugum*);
	Dugum* getIleri();
	void setGeri(Dugum*);
	Dugum* getGeri();

};
#endif