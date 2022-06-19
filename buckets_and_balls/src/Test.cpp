

#include <iostream>
#include "Kova.hpp"
#include "Top.hpp"
#include "KovaKontrol.hpp"
#include "time.h"


using namespace std;


int main()
{
	
	int kovaSayisi;
	cout<<"Kova Sayisi:";
	cin>>kovaSayisi;
	system("CLS");
	srand (time(NULL));
	
	Kova *kovalar = new Kova[kovaSayisi];
	Top *toplar = new Top[kovaSayisi];
	KovaKontrol *kontrol = new KovaKontrol[kovaSayisi];

	for (int i=0;i<kovaSayisi;i++)
	{
		kovalar[i].setKovaRenk(i);
		kovalar[i].setKovaAdres(&kovalar[i]);
		
		kontrol[i].setRenk(kovalar[i].getKovaRenk());
		kontrol[i].setKovaAdres(kovalar[i].getKovaAdres());
		cout<<i+1<<". Kova"<<endl;
		kontrol[i].kovaOlustur();	
	}
	
	bool topYerlesme = true;
	int secenek=0;
	KovaKontrol *temp = new KovaKontrol();
	Top *adresTop = new Top();
	char harfTop;
	
	do{
		cout<<"[1] Toplari Yerlestir"<<endl;
		cout<<"[2] Toplari Yoket"<<endl;
		cout<<"[3] Kova Degistir"<<endl;
		cout<<"[4] Top Degistir"<<endl;
		cout<<"[5] Kovalari Tersten Yerlestir"<<endl;
		cout<<"[6] Toplari Tersten Yerlestir"<<endl;
		cout<<"[7] Cikis"<<endl;
		cout<<"Secim:";
		cin>>secenek;

		char harf = 'A'+rand()%26;
		int y=0;

		switch(secenek){
			case 1:
				system("CLS");			
				if(topYerlesme)
				{
					for (int i=0;i<kovaSayisi;i++)
					{
						toplar[i].setTopHarf((harf+(y%26)));
						toplar[i].setTopAdres(&toplar[i]);
						
						kontrol[i].setHarf(toplar[i].getTopHarf());
						kontrol[i].setTopAdres(toplar[i].getTopAdres());
						cout<<i+1<<". Kova"<<endl;
						kontrol[i].kovaOlustur();

						if(harf+(y%26)=='Z')
						{
							harf='A';
							y=-1;
						}
						y++;
					}
					topYerlesme=false;					
				}
				else
					cout<<"Zaten kovalarda top var.\n\n";
			break;
			
			case 2:
				system("CLS");
				if(topYerlesme==false)
				{
					for (int i=0;i<kovaSayisi;i++)
					{	
						kontrol[i].setHarf('-');
						cout<<i+1<<". Kova"<<endl;
						kontrol[i].kovaOlustur();
					}
					cout<<"Toplar yok edildi.\n\n";
					
					topYerlesme=true;
				}
				else
					cout<<"Once top yerlestirin.\n\n";
			break;
			
			case 3:
				system("CLS");
				int a,b;
				cout<<"Hangi Kova :";
				cin>>a;
				cout<<"Hangi Kova ile :";
				cin>>b;
				
				if(a>0 && a<=kovaSayisi && b>0 && b<=kovaSayisi)
				{
					cout<<"///////////////////////////////////once/////////////////////////"<<endl;
					for (int i=0;i<kovaSayisi;i++)
					{
						cout<<i+1<<". Kova"<<endl;
						kontrol[i].kovaOlustur();
					}
					cout<<"///////////////////////////////////sonra/////////////////////////"<<endl;

					*temp=kontrol[a-1];
					kontrol[a-1]=kontrol[b-1];
					kontrol[b-1]=*temp;
					
					for (int i=0;i<kovaSayisi;i++)
					{
						cout<<i+1<<". Kova"<<endl;
						kontrol[i].kovaOlustur();
					}
				}
				else
					cout<<"Gecersiz giris yaptiniz!!\n\n";
			break;
			
			case 4:
				system("CLS");
				if(topYerlesme==false)
				{
					int c,d;
					cout<<"Hangi Top :";
					cin>>c;
					cout<<"Hangi Top ile :";
					cin>>d;
					
					if(c>0 && c<=kovaSayisi && d>0 && d<=kovaSayisi)
					{
						cout<<"///////////////////////////////////once/////////////////////////"<<endl;
						for (int i=0;i<kovaSayisi;i++)
						{
							cout<<i+1<<". Kova"<<endl;
							kontrol[i].kovaOlustur();	
						}
						cout<<"///////////////////////////////////sonra/////////////////////////"<<endl;
						
						adresTop=kontrol[c-1].getTopAdres();
						kontrol[c-1].setTopAdres(kontrol[d-1].getTopAdres());
						kontrol[d-1].setTopAdres(adresTop);
						
						harfTop=kontrol[c-1].getHarf();
						kontrol[c-1].setHarf(kontrol[d-1].getHarf());
						kontrol[d-1].setHarf(harfTop);

						for (int i=0;i<kovaSayisi;i++)
						{
							cout<<i+1<<". Kova"<<endl;
							kontrol[i].kovaOlustur();	
						}
					}
					else
						cout<<"Gecersiz giris yaptiniz!!\n\n";
				}
				else
					cout<<"Once top yerlestirin.\n\n";
			break;
			
			case 5:
				system("CLS");
				cout<<"///////////////////////////////////once/////////////////////////"<<endl;
				for (int i=0;i<kovaSayisi;i++)
				{
					cout<<i+1<<". Kova"<<endl;
					kontrol[i].kovaOlustur();	
				}
				cout<<"///////////////////////////////////sonra/////////////////////////"<<endl;
				for (int i=0;i<(kovaSayisi/2);i++)
				{
						*temp=kontrol[i];
					kontrol[i]=kontrol[kovaSayisi-1-i];
					kontrol[kovaSayisi-1-i]=*temp;
				}
				for (int i=0;i<kovaSayisi;i++)
				{
					cout<<i+1<<". Kova"<<endl;
					kontrol[i].kovaOlustur();	
				}
			break;
			
			case 6:
				system("CLS");
				if(topYerlesme==false)
				{
					cout<<"///////////////////////////////////once/////////////////////////"<<endl;
					for (int i=0;i<kovaSayisi;i++)
					{
						
						cout<<i+1<<". Kova"<<endl;
						kontrol[i].kovaOlustur();	
					}
					cout<<"///////////////////////////////////sonra/////////////////////////"<<endl;
					
					for (int i=0;i<(kovaSayisi/2);i++)
					{
						adresTop=kontrol[i].getTopAdres();
						kontrol[i].setTopAdres(kontrol[kovaSayisi-1-i].getTopAdres());
						kontrol[kovaSayisi-1-i].setTopAdres(adresTop);
						
						harfTop=kontrol[i].getHarf();
						kontrol[i].setHarf(kontrol[kovaSayisi-1-i].getHarf());
						kontrol[kovaSayisi-1-i].setHarf(harfTop);
					}
					
					for (int i=0;i<kovaSayisi;i++)
					{	
						cout<<i+1<<". Kova"<<endl;
						kontrol[i].kovaOlustur();
					}
				}
				else
					cout<<"Once top yerlestirin.\n\n";
					
			break;
			
			case 7:
			break;
			
			default:
				system("CLS");
				cout<<"Lutfen Gecerli bir deger giriniz!!\n\n";
				cin.clear();
				cin.ignore();	
			break;
					
		}
		
		
	}while(secenek!=7);
	
	delete temp;
	delete adresTop;
	
	delete kovalar;
	delete toplar;
	delete kontrol;
			
			
}