


#include <iostream>

using namespace std;

int main()
{

	int satir = 11;
	// 5 kez d�ng�ye giriyor ve 5 sat�r olu�uyor.
	for (int i = 0; i < (satir-1)/2; i++)
	{	// 11 kez d�ng�ye giriyor ve bulundu�u sat�rda 11 kez cout i�eri�i g�z�k�yor.
		for (int y = 0; y < satir; y++)
		{	// y ve i de�erlerine g�re ayn� sat�rda * veya " " g�r�nmesini sa�l�yor
			if (y-i > (satir-1)/2 || y+i < (satir-1)/2)
				cout << "* ";
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}

	cout << endl;
	// 5 kez d�ng�ye giriyor ve 5 sat�r olu�uyor.
	for (int i = 0; i < (satir-1)/2; i++)
	{	// 11 kez d�ng�ye giriyor ve bulundu�u sat�rda 11 kez cout i�eri�i g�z�k�yor.
		for (int y = 0; y < satir; y++)
		{	// y ve i de�erlerine g�re ayn� sat�rda * veya " " g�r�nmesini sa�l�yor
			if (y+i > satir-2 || y-i < 1)
				cout << "* ";
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;

}