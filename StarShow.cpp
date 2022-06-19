


#include <iostream>

using namespace std;

int main()
{

	int satir = 11;
	// 5 kez döngüye giriyor ve 5 satýr oluþuyor.
	for (int i = 0; i < (satir-1)/2; i++)
	{	// 11 kez döngüye giriyor ve bulunduðu satýrda 11 kez cout içeriði gözüküyor.
		for (int y = 0; y < satir; y++)
		{	// y ve i deðerlerine göre ayný satýrda * veya " " görünmesini saðlýyor
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
	// 5 kez döngüye giriyor ve 5 satýr oluþuyor.
	for (int i = 0; i < (satir-1)/2; i++)
	{	// 11 kez döngüye giriyor ve bulunduðu satýrda 11 kez cout içeriði gözüküyor.
		for (int y = 0; y < satir; y++)
		{	// y ve i deðerlerine göre ayný satýrda * veya " " görünmesini saðlýyor
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