
#include <iostream>
#include <Windows.h>

using namespace std;

const int yatay = 20;
const int dikey = 80;
const char gemiKarakter = 219;
const char mermiKarakter = 219;
const char dusmanKarakter = 219;
char sahne[yatay][dikey];
char tuslar[256];


enum YON
{
	YON_YUKARI = 1,
	YON_ASAGI = 2,
	YON_SAG = 4,
	YON_SOL = 16,
	YON_DUR = 256,
};

struct Eleman
{
	int x;
	int y;

	YON yon;
	char karakter;
};

Eleman gemiGövdesi[5];
Eleman mermi;
Eleman dusman[9];


void koordinatxy(int x,int y) // koordinat vermek için gerekli.
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void sahneCiz() // Oyun alanýný çizer.
{
	for (int x = 0; x < yatay; x++)
	{
		for (int y = 0; y < dikey; y++)
		{
			cout << sahne[x][y];
		}
		cout << endl;
	}

	cout << endl <<" Tuslar:  A=Yukari   D=Asagi   K=Ates";
}
void sinirOlustur() // Oyun alanýnýn çerçevesini oluþturur.
{

	for (int y = 0; y < yatay; y++)
	{
		sahne[y][0] = 219;
		sahne[y][dikey - 1] = 219;
	}

	for (int x = 0; x < dikey; x++)
	{
		sahne[0][x] = 219;
		sahne[yatay - 1][x] = 219;
	}


}
void sahneTemizle() // Sahnedeki karakterlerin hepsini siler.
{
	for (int x = 0; x < yatay; x++)
	{
		for (int y = 0; y < dikey; y++)
		{
			sahne[x][y] = ' ';
		}
	}
}
void kursoruGizle()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void klavyeOku(char tuslar[])
{
	for (int x = 0; x < 256; x++)
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
}
void klavyeKontrol() // Klavyeden basýlan tuþa göre oyunda kontrolu saðlar.
{
	klavyeOku(tuslar);

	if (tuslar['A'] != 0)
	{
		for (int i = 0; i < 5; i++)
		{
			gemiGövdesi[i].yon = YON_YUKARI;
		}
	}
	if (tuslar['D'] != 0)
	{
		for (int i = 0; i < 5; i++)
		{
			gemiGövdesi[i].yon = YON_ASAGI;
		}
	}
	if (tuslar['K'] != 0)
	{
		mermi.yon = YON_SAG;
	}




}


void gemiOlustur() // Geminin prototipini oluþturur.
{
	gemiGövdesi[0].x = 8;
	gemiGövdesi[0].y = 4;

	gemiGövdesi[1].x = 8;
	gemiGövdesi[1].y = 2;

	gemiGövdesi[2].x = 10;
	gemiGövdesi[2].y = 4;

	gemiGövdesi[3].x = 12;
	gemiGövdesi[3].y = 2;

	gemiGövdesi[4].x = 12;
	gemiGövdesi[4].y = 4;

	for (int i = 0; i < 5; i++)
	{
		gemiGövdesi[i].karakter = gemiKarakter;
	}
}
void gemiSahnede() // Geminin oyun alanýnda gösterilmesini saðlar.
{
	for (int i = 0; i < 5; i++)
	{
		int x = gemiGövdesi[i].x;
		int y = gemiGövdesi[i].y;
		sahne[x][y] = gemiGövdesi[i].karakter;
	}
}
void gemiHareket() // Geminin yukarý ve aþaðý kontrolünü saðlar.
{
	for (int i = 0; i < 5; i++)
	{
		switch(gemiGövdesi[i].yon)
		{
		case YON_YUKARI:
			gemiGövdesi[i].x++;
			break;
		case YON_ASAGI:
			gemiGövdesi[i].x--;
			break;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		gemiGövdesi[i].yon = YON_DUR;
	}


}

void mermiOlustur() // Mermi prototipini oluþturur.
{
	switch(mermi.yon)
	case YON_SAG:
	{
		mermi.x = gemiGövdesi[2].x;
		mermi.y = gemiGövdesi[2].y;
		mermi.karakter = mermiKarakter;

		break;
	}

	mermi.yon = YON_DUR;

	

}
void mermiSahnede() // Merminin oyun alanýnda gösterilmesini saðlar.
{
	int x = mermi.x;
	int y = mermi.y;
	sahne[x][y] = mermi.karakter;

}
void mermiHareket() // Merminin oyunda saða doðru ilerlemesini saðlar.
{
	mermi.y++;
	
}	

void dusmanOlustur() // Düþman gemisinin prototipini oluþturur.
{
	int a = rand() % 15;

	for (int i = 0; i < 3; i++)
	{
		dusman[i].x = 2+a;
		dusman[i].y = dikey - i;
	}
	for (int i = 3; i < 6; i++)
	{
		dusman[i].x = 3+a;
		dusman[i].y = dikey - i;
	}
	for (int i = 6; i < 9; i++)
	{
		dusman[i].x = 4+a;
		dusman[i].y = dikey - i;
	}
	for (int i = 0; i < 9; i++)
	{
		if (i == 4)
			dusman[i].karakter = ' ';
		else
			dusman[i].karakter = dusmanKarakter;
	}
		
}
void dusmanSahnede() // Düþman gemisinin oyun alanýnda gösterilmesini saðlar.
{
	
	for (int i = 0; i < 9; i++)
	{
		int x = dusman[i].x;
		int y = dusman[i].y;
		sahne[x][y] = dusman[i].karakter;
	}
	if (dusman[0].y == 0)
	{
		dusmanOlustur();
	}
}
void dusmanHareket() // Düþman gemisinin sola doðru ilerlemesini saðlar.
{
	for (int i = 0; i < 9; i++)
	{
		dusman[i].y--;
	}
	for (int i = 0; i < 9; i++)
	{
		if (dusman[i].x == mermi.x && dusman[i].y == mermi.y)
		{
			for (int i = 0; i < 9; i++)
			{
				dusman[i].karakter = ' ';
				mermi.karakter = ' ';
			}
		}
	}
}



int main()
{
	
	kursoruGizle();

	gemiOlustur();
	dusmanOlustur();
	

	while (true)
	{

		sahneTemizle();

		sinirOlustur();
		klavyeKontrol();
		
		
		mermiOlustur();


		gemiHareket();
		gemiSahnede();

		mermiHareket();
		mermiSahnede();
		
		dusmanHareket();
		dusmanSahnede();


		koordinatxy(0, 0);
		sahneCiz();


		Sleep(50);


	}





	
}