

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std; 

int main()
{
	int aHarfSayac = 0;
	int eHarfSayac = 0;
	int iHarfSayac = 0;
	int oHarfSayac = 0;
	int uHarfSayac = 0;
	int enBuyuk;

	char ch = 'x';

	cout << "Bir Seyler Yaz:  ";
	
	// Döngüye giriyor ve entera basana kadar çalýþýyor
	while (ch != '\r')
	{
		// Klavyeden girilen karakteri okur
		ch =_getche();
		// Eðer girilen karakter a ise aHarfSayacýný artýr
		if (ch == 'a')
			aHarfSayac++;
		if (ch == 'e')
			eHarfSayac++;
		if (ch == 'i')
			iHarfSayac++;
		if (ch == 'o')
			oHarfSayac++;
		if (ch == 'u')
			uHarfSayac++;
	}
	cout << endl;

	// aHarfSayacý diðer hepsinden büyük eþit ise enBuyuk deðerine ata
	if (aHarfSayac >= eHarfSayac && aHarfSayac >= iHarfSayac && aHarfSayac >= oHarfSayac && aHarfSayac >= uHarfSayac)
		enBuyuk = aHarfSayac;
	if (eHarfSayac > aHarfSayac && eHarfSayac >= iHarfSayac && eHarfSayac >= oHarfSayac && eHarfSayac >= uHarfSayac)
		enBuyuk = eHarfSayac;
	if (iHarfSayac > aHarfSayac && iHarfSayac > eHarfSayac && iHarfSayac >= oHarfSayac && iHarfSayac >= uHarfSayac)
		enBuyuk = iHarfSayac;
	if (oHarfSayac > aHarfSayac && oHarfSayac > eHarfSayac && oHarfSayac > iHarfSayac && oHarfSayac >= uHarfSayac)
		enBuyuk = oHarfSayac;
	if (uHarfSayac > aHarfSayac && uHarfSayac > eHarfSayac && uHarfSayac > iHarfSayac && uHarfSayac > oHarfSayac)
		enBuyuk = uHarfSayac;

	                                      // 1 den baþlayarak enBuyuk deðerine kadar ekrana sayý çýkart
	cout << "H" << "        " << "TS   "; for (int i = 1; i <= enBuyuk; i++)cout << i << "    "; cout << endl;
	                                                   // Sayacýn deðeri kadar ekrana o harfi çýkart
	cout << "a" << "        " << aHarfSayac << "    "; for (int i = 0; i < aHarfSayac; i++) cout << "a    "; cout << endl;
	cout << "e" << "        " << eHarfSayac << "    "; for (int i = 0; i < eHarfSayac; i++) cout << "e    "; cout << endl;
	cout << "i" << "        " << iHarfSayac << "    "; for (int i = 0; i < iHarfSayac; i++) cout << "i    "; cout << endl;
	cout << "o" << "        " << oHarfSayac << "    "; for (int i = 0; i < oHarfSayac; i++) cout << "o    "; cout << endl;
	cout << "u" << "        " << uHarfSayac << "    "; for (int i = 0; i < uHarfSayac; i++) cout << "u    "; cout << endl;

	system("pause");
	return 0;
}