
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
	// giris matrisinin boyutunu elemanlar�n bellekte kaplad�klar� yere g�re bulma
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
	

	// giris matrisinin boyutu cekirde�in boyutundan k���kse cekirdekteki b�t�n elemanlar �arpma i�leminde kullan�lam�yor.
	// kayma miktar� cekirde�in boyutundan b�y�k olursa giris matrisindeki baz� elemanlar atlanm�� oluyor.
	// giris matrisinin cekirdekten fark� kayma miktar�na kalans�z b�l�nemezse ��k�� matrisi olu�muyor.
	if (giris_boyut < cekirdek_boyut || cekirdek_boyut < kayma_miktari || (giris_boyut - cekirdek_boyut) % kayma_miktari != 0)
	{
		cout << endl << "bu islem yapilamaz...";
	}

	else
	{
		//�ekirdek matrisini kullan�c�dan alma d�ng�s�
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

		// ��k�s matrisini olu�turma
		for (int k = 0; k < cikis_boyut; k++)
		{
			for (int l = 0; l < cikis_boyut; l++)
			{

				// her bir matris eleman�ndan di�erine ge�i�te de�er 0'dan ba�l�yor.
				deger.cikis[k][l] = 0;

				// D�ng�den �nce hangi sat�rda bulunuyorsa o sat�r say�s� ile kayma miktar�n� �arparak giri� matrisindeki konumunu buluyoruz.
				i = (k * kayma_miktari);

				for (int x = 0; x < cekirdek_boyut; x++)
				{

					// Hangi s�tunda bulunuyorsa o s�tun say�s� ile kayma miktar�n� �arparak s�tunlar artm�� bir �ekilde �arp�m ger�ekle�iyor.
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

		// ��k�� matrisini g�sterme
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




