


#include <iostream>
#include <iomanip>

using namespace std;

class Sifre
{
public:
	Sifre(char *alfabex, char *sifre)
	{
		alfabe = alfabex;
		sifreKelimesi = sifre;
	};

	Sifre();

	char* sifrele(char*);
	char* sifrecoz(char*);
	void sifreKelimesiAta(char*);

private:
	char* alfabe;
	char* sifreKelimesi;
};



int main()
{
	char tablo[26][26];

	char alfabe[26];
	char sifre[26];
	char sifrelenecek[26];


	char sifrelenmis[26];
	int x = 0;



	cout << "ALFABE             :";
	cin >> alfabe;
	cout << "SIFRE              :";
	cin >> sifre;
	cout << "METIN              :";
	cin >> sifrelenecek;

	{
		for (int i = 0; i < strlen(alfabe); i++)
		{
			x = i;
			for (int j = 0; j < strlen(alfabe); j++)
			{
				tablo[i][j] = alfabe[x];
				x++;
				if (alfabe[x] == alfabe[strlen(alfabe)])
					x = 0;
			}
		}
	};


	int  a = 0, i = 0, j = 0, k = 0;

	for (int y = 0; y < strlen(sifrelenecek); y++)
	{
		k = 0;
		while (sifrelenecek[y] != alfabe[k])
		{
			k++;
		}
		i = k;

		k = 0;
		while (sifre[a] != alfabe[k])
		{
			k++;

		}
		a++;
		if (sifre[a] == sifre[strlen(sifre)])
			a = 0;


		j = k;

		sifrelenmis[y] = tablo[i][j];
	}




	cout << "SIFRELENMIS METIN  :";
	for (int j = 0; j < strlen(sifrelenecek); j++)
	{
		cout << sifrelenmis[j];
	}
	cout << endl;




	cout << "DESIFRE METIN      :";
	for (int j = 0; j < strlen(sifrelenecek); j++)
	{
		cout << sifrelenecek[j];
	}
	cout << endl;


	char* yenisifrelenmis = new char[26];

	Sifre yenisifre(alfabe, sifre);
	yenisifrelenmis = yenisifre.sifrele(sifrelenecek);






	system("pause");
	return 0;


}

Sifre::Sifre()
{
}

char * Sifre::sifrele(char *a)
{
	int x = 0;
	char tablo[26][26];
	for (int i = 0; i < strlen(alfabe); i++)
	{
		x = i;
		for (int j = 0; j < strlen(alfabe); j++)
		{
			tablo[i][j] = alfabe[x];
			x++;
			if (alfabe[x] == alfabe[strlen(alfabe)])
				x = 0;
		}
	}
	int  c = 0, i = 0, j = 0, k = 0;

	for (int y = 0; y < strlen(a); y++)
	{
		k = 0;
		while (a[y] != alfabe[k])
		{
			k++;
		}
		i = k;

		k = 0;
		while (sifreKelimesi[c] != alfabe[k])
		{
			k++;

		}
		a++;
		if (sifreKelimesi[c] == sifreKelimesi[strlen(sifreKelimesi)])
			a = 0;


		j = k;

		a[y] = tablo[i][j];
	}

	return a;
}

char * Sifre::sifrecoz(char *b)
{
	return b;
}

void Sifre::sifreKelimesiAta(char *sifre)
{
	sifreKelimesi = sifre;
}
