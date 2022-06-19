

#include "KovaKontrol.hpp"
#include <windows.h>
#include <iostream>

using namespace std;
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

void KovaKontrol::setKovaAdres(Kova* kadres)
		{
			kovaAdres=kadres;
		}
		
void KovaKontrol::setTopAdres(Top* tadres)
		{
			topAdres=tadres;
		}
		
void KovaKontrol::setRenk(int color)
		{
			renk=color;
		}
		
void KovaKontrol::setHarf(char letter)
		{
			harf=letter;
		}

Top* KovaKontrol::getTopAdres()
		{
			return topAdres;
		}
		
char KovaKontrol::getHarf()
		{
			return harf;
		}
		
void KovaKontrol::kovaOlustur(){

	SetConsoleTextAttribute(color, renk%15+1);
	cout<<"  .|.  "<<endl;
	cout<<" .   . "<<endl;
	cout<<".     ."<<endl;
	cout<<"#     #"<<endl;
	cout<<"#  "<<harf<<"  #"<<endl;
	cout<<"#     #"<<endl;
	cout<<"#######"<<endl;
	cout<<"Kova adresi:"<<kovaAdres<<endl;
	if(harf=='-'){
		cout<<"Topun adresi: NULL"<<endl;
	}
	else
		cout<<"Topun adresi:"<<topAdres<<endl;
	SetConsoleTextAttribute(color, 7);


}