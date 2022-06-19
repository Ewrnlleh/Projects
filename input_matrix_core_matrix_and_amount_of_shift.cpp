
#include <iostream>
#include <iomanip>

using namespace std;

struct Islem
{
	int giris[5][5] = { 3,2,5,1,4,
						6,2,1,0,7,
						3,0,0,2,0,
						1,1,3,2,2,
						0,3,1,0,0 };

	int cikis[100][100];
	int cekirdek[5][5];
	int girisBoyutHesapla();
};


int Islem::girisBoyutHesapla()
{
	int x;
	// giris matrisinin boyutunu elemanlarýn bellekte kapladýklarý yere göre bulma
	x = sqrt(sizeof(giris) / sizeof(giris[0][0]));
	return x;
}

int main()
{

	int cekirdek_boyut, giris_boyut, cikis_boyut;
	int kayma_miktari;
	Islem deger;


	giris_boyut = deger.girisBoyutHesapla();
	

	cout << "cekirdek boyutunu giriniz:";
	cin >> cekirdek_boyut;
	cout << endl << "kayma miktarini giriniz:";
	cin >> kayma_miktari;
	

	// giris matrisinin boyutu cekirdeðin boyutundan küçükse cekirdekteki bütün elemanlar çarpma iþleminde kullanýlamýyor.
	// kayma miktarý cekirdeðin boyutundan büyük olursa giris matrisindeki bazý elemanlar atlanmýþ oluyor.
	// giris matrisinin cekirdekten farký kayma miktarýna kalansýz bölünemezse çýkýþ matrisi oluþmuyor.
	if (giris_boyut < cekirdek_boyut || cekirdek_boyut < kayma_miktari || (giris_boyut - cekirdek_boyut) % kayma_miktari != 0)
	{
		cout << endl << "bu islem yapilamaz...";
	}

	else
	{
		//çekirdek matrisini kullanýcýdan alma döngüsü
		for (int x = 0; x < cekirdek_boyut; x++)
		{
			for (int y = 0; y < cekirdek_boyut; y++)
			{
				cout << endl << "cekirdek" << "["<<x<<"]"<< "["<<y<<"]=";
				cin >> deger.cekirdek[x][y];
			}
		}
		
		cikis_boyut = ((giris_boyut - cekirdek_boyut) / kayma_miktari) + 1;

		int i=0, j=0;

		// çýkýs matrisini oluþturma
		for (int k = 0; k < cikis_boyut; k++)
		{
			for (int l = 0; l < cikis_boyut; l++)
			{

				// her bir matris elemanýndan diðerine geçiþte deðer 0'dan baþlýyor.
				deger.cikis[k][l] = 0;

				// Döngüden önce hangi satýrda bulunuyorsa o satýr sayýsý ile kayma miktarýný çarparak giriþ matrisindeki konumunu buluyoruz.
				i = (k * kayma_miktari);

				for (int x = 0; x < cekirdek_boyut; x++)
				{

					// Hangi sütunda bulunuyorsa o sütun sayýsý ile kayma miktarýný çarparak sütunlar artmýþ bir þekilde çarpým gerçekleþiyor.
					j = (l * kayma_miktari);

					for (int y = 0; y < cekirdek_boyut; y++)
					{
						deger.cikis[k][l] += (deger.cekirdek[x][y]) * (deger.giris[i][j]);
						j++;
					}

					i++;

				}
			}
		}
		cout << endl;

		// çýkýþ matrisini gösterme
		for (int k = 0; k < cikis_boyut; k++)
		{
			for (int l = 0; l < cikis_boyut; l++)
			{
				cout << setw(5) << deger.cikis[k][l];
			}
			cout << endl;
		}
	}
	
	system("pause");
	return 0;

}		




