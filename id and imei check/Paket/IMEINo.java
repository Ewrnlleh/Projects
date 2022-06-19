/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Paket;

public class IMEINo {
    
    private int gecersizImei=0;
    private int gecerliImei=0;
   
    public String imeiUret(){
        
        Rastgele sayi = new Rastgele();
        int imei1,imei2,imei3,imei4,imei5,imei6,imei7,imei8,imei9,imei10,imei11,imei12,imei13,imei14,imei15;
        imei1 = (sayi.rastgele(10))-1;
        imei2 = (sayi.rastgele(10))-1;
        imei3 = (sayi.rastgele(10))-1;
        imei4 = (sayi.rastgele(10))-1;
        imei5 = (sayi.rastgele(10))-1;
        imei6 = (sayi.rastgele(10))-1;
        imei7 = (sayi.rastgele(10))-1;
        imei8 = (sayi.rastgele(10))-1;
        imei9 = (sayi.rastgele(10))-1;
        imei10 = (sayi.rastgele(10))-1;
        imei11 = (sayi.rastgele(10))-1;
        imei12 = (sayi.rastgele(10))-1;
        imei13 = (sayi.rastgele(10))-1;
        imei14 = (sayi.rastgele(10))-1;
        
        int[] dizi = new int[]{ imei1,imei2,imei3,imei4,imei5,imei6,imei7,imei8,imei9,imei10,imei11,imei12,imei13,imei14 }; 
        int toplam=0;
        
        for(int i = 0; i<14 ; i++){
          if(i%2==1){
              dizi[i]=dizi[i]*2;
              if(dizi[i]>=10){
                  dizi[i] = 1 + (dizi[i]%10) ;
              }
          }
          toplam += dizi[i];
        }

        imei15 = (toplam*9)%10;
        
        return String.format("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", imei1,imei2,imei3,imei4,imei5,imei6,imei7,imei8,imei9,imei10,imei11,imei12,imei13,imei14,imei15);
    }
    
    public void imeiKontrol(String girisImei){
        int toplam = 0;
        for(int i=13; i>=0 ; i=i-1){
            String basamak = girisImei.substring(i,i+1);
            int sayi = Integer.valueOf(basamak);
            if(i%2==0){
                toplam = toplam + sayi;
            }else {
                toplam = toplam + basamaklariTopla(sayi*2);
            }
        }
        toplam = toplam * 9;
        toplam = toplam % 10;
        if (toplam != Integer.valueOf(girisImei.substring(14)) ){
            gecersizImei++;
        }
        else{
            gecerliImei++;
        }

    }
    
    public int basamaklariTopla(int sayi){
        int toplam=0;
        while(sayi > 0) {
            toplam += sayi % 10;
            sayi = sayi/10;
        }
        return toplam;
    }
    
    public void kontrolYaz(){
        System.out.println("IMEI Kontrol");
        System.out.println(gecerliImei + "  Geçerli");
        System.out.println(gecersizImei + "  Geçersiz");        
    }
    
}
