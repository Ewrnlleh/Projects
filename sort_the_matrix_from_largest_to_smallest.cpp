



#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

const int Sat�r = 5;
const int Sutun = 10;



int main()
{

	srand((unsigned)time(0));

	char matris[Sat�r][Sutun]; // 5 e 10 luk bir matris dizisi
	char Harf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int temp;

	cout << "Tekrarsiz ve Rasgele Dizi" << endl;

	for (int i = 0; i < Sat�r; i++) // 5 kez d�ng�ye girip, 5 sat�r olu�uyor
	{

		for (int j = 0; j < Sutun; j++) // 10 kez d�ng�ye girip, 10 sat�r olu�uyor
		{

			temp = Harf[rand() % 52]; // Harf dizisinin i�indeki harflerden rastgele at�yor

			for (int x = 0; x < Sat�r; x++) // Ayn� d�ng�ler olu�turularak matrisin b�t�n elemanlar� kontrol ediliyor
			{


				for (int y = 0; y < Sutun; y++)
				{

					if (temp == matris[x][y]) // e�er rastgele atad���m�z de�er matrisin herhangi bir eleman�nda varsa
					{

						temp = Harf[rand() % 52]; // tekrar yeni bir de�er atan�yor
						x = -1; // x -1 olsunki atanan yeni de�er i�in 0 dan ba�lay�p tekrardan matrisin b�t�n elemanlar� kontrol edilsin

					}
				}

			}

			matris[i][j] = temp; // en son olu�an temp de�eri matris eleman� oluyor
			cout << setw(5) << matris[i][j]; // ekrana matrisi ��kar

		}

		cout << endl;

	}

	cout << endl << "Siralanmis Dizi" << endl;
	int k, temp2;

	for (int i = 0; i < Sat�r; i++) // 5 kez d�ng�ye girip, 5 sat�r olu�uyor
	{
		for (int j = 0; j < Sutun; j++) // 10 kez d�ng�ye girip, 10 sat�r olu�uyor
		{
			k = (j + 1); // bir matrisle di�er bir matrisi kar��la�t�rmak i�in s�tunun bir fazla de�erini al�yoruz

			for (int x = i; x < Sat�r; x++) // Ayn� d�ng�leri kullanarak kar��la�t�rmak istedi�imiz matrisi olu�turuyoruz
			{
				for (int y = k; y < Sutun; y++)
				{
					if (matris[i][j] > matris[x][y]) // ilk matris di�erinden b�y�kse yerlerini de�i�tirerek s�ralama i�lemini sa�l�yoruz
					{
						temp2 = matris[i][j];
						matris[i][j] = matris[x][y];
						matris[x][y] = temp2;
					}
				}

				k = 0; // k n�n de�erini s�f�ra d���rerek bir sonraki sat�rda d�ng�n�n tekrar �al��mas�n� sa�l�yoruz
			}
		}
	}

	for (int i = 0; i < Sat�r; i++)
	{
		for (int j = 0; j < Sutun; j++)
		{
			cout << setw(5) << matris[i][j]; // s�ralad���m�z harfleri 5 e 10 matris bi�iminde ekrana ��kart�yoruz
		}

		cout << endl;
	}


	system("pause");
	return 0;




}
