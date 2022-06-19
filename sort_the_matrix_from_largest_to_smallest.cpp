



#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

const int Satýr = 5;
const int Sutun = 10;



int main()
{

	srand((unsigned)time(0));

	char matris[Satýr][Sutun]; // 5 e 10 luk bir matris dizisi
	char Harf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int temp;

	cout << "Tekrarsiz ve Rasgele Dizi" << endl;

	for (int i = 0; i < Satýr; i++) // 5 kez döngüye girip, 5 satýr oluþuyor
	{

		for (int j = 0; j < Sutun; j++) // 10 kez döngüye girip, 10 satýr oluþuyor
		{

			temp = Harf[rand() % 52]; // Harf dizisinin içindeki harflerden rastgele atýyor

			for (int x = 0; x < Satýr; x++) // Ayný döngüler oluþturularak matrisin bütün elemanlarý kontrol ediliyor
			{


				for (int y = 0; y < Sutun; y++)
				{

					if (temp == matris[x][y]) // eðer rastgele atadýðýmýz deðer matrisin herhangi bir elemanýnda varsa
					{

						temp = Harf[rand() % 52]; // tekrar yeni bir deðer atanýyor
						x = -1; // x -1 olsunki atanan yeni deðer için 0 dan baþlayýp tekrardan matrisin bütün elemanlarý kontrol edilsin

					}
				}

			}

			matris[i][j] = temp; // en son oluþan temp deðeri matris elemaný oluyor
			cout << setw(5) << matris[i][j]; // ekrana matrisi çýkar

		}

		cout << endl;

	}

	cout << endl << "Siralanmis Dizi" << endl;
	int k, temp2;

	for (int i = 0; i < Satýr; i++) // 5 kez döngüye girip, 5 satýr oluþuyor
	{
		for (int j = 0; j < Sutun; j++) // 10 kez döngüye girip, 10 satýr oluþuyor
		{
			k = (j + 1); // bir matrisle diðer bir matrisi karþýlaþtýrmak için sütunun bir fazla deðerini alýyoruz

			for (int x = i; x < Satýr; x++) // Ayný döngüleri kullanarak karþýlaþtýrmak istediðimiz matrisi oluþturuyoruz
			{
				for (int y = k; y < Sutun; y++)
				{
					if (matris[i][j] > matris[x][y]) // ilk matris diðerinden büyükse yerlerini deðiþtirerek sýralama iþlemini saðlýyoruz
					{
						temp2 = matris[i][j];
						matris[i][j] = matris[x][y];
						matris[x][y] = temp2;
					}
				}

				k = 0; // k nýn deðerini sýfýra düþürerek bir sonraki satýrda döngünün tekrar çalýþmasýný saðlýyoruz
			}
		}
	}

	for (int i = 0; i < Satýr; i++)
	{
		for (int j = 0; j < Sutun; j++)
		{
			cout << setw(5) << matris[i][j]; // sýraladýðýmýz harfleri 5 e 10 matris biçiminde ekrana çýkartýyoruz
		}

		cout << endl;
	}


	system("pause");
	return 0;




}
