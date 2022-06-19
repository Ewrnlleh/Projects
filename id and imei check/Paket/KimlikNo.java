/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Paket;

public class KimlikNo {
    
    private int gecersizKimlik=0;
    private int gecerliKimlik=0;
    
    public String tcUret(){
        
        int tc1,tc2,tc3,tc4,tc5,tc6,tc7,tc8,tc9,tc10,tc11;
                
        Rastgele sayi = new Rastgele();
        tc1 = sayi.rastgele(9);
        tc2 = (sayi.rastgele(10))-1;
        tc3 = (sayi.rastgele(10))-1;
        tc4 = (sayi.rastgele(10))-1;
        tc5 = (sayi.rastgele(10))-1;
        tc6 = (sayi.rastgele(10))-1;
        tc7 = (sayi.rastgele(10))-1;
        tc8 = (sayi.rastgele(10))-1;
        tc9 = (sayi.rastgele(10))-1;
        
        tc10 = (((tc1+tc3+tc5+tc7+tc9)*7)-(tc2+tc4+tc6+tc8))%10;
        
        tc11 = (tc1+tc2+tc3+tc4+tc5+tc6+tc7+tc8+tc9+tc10)%10;

        return (Integer.toString(tc1)+Integer.toString(tc2)+Integer.toString(tc3)+Integer.toString(tc4)+Integer.toString(tc5)+Integer.toString(tc6)+Integer.toString(tc7)+Integer.toString(tc8)+Integer.toString(tc9)+Integer.toString(tc10)+Integer.toString(tc11));
    } 
    
    public void tcKontrol(String girisTc){
        if (Integer.valueOf(girisTc.substring(0,1)) == 0){
            gecersizKimlik++;
        }
        else{
            int toplam = 0;
            int toplam2 = 0;
            int toplam3 = 0;
            for (int i=0; i<9; i++){
                if(i%2==0){
                    toplam = toplam + Integer.valueOf(girisTc.substring(i,i+1));
                }
                if (i%2==1){
                    toplam2 = toplam2 + Integer.valueOf(girisTc.substring(i,i+1));
                }
            }
            for (int i=0; i<10; i++){
                toplam3 = toplam3 + Integer.valueOf(girisTc.substring(i,i+1));
            }
            if(((toplam*7)- toplam2)%10 == Integer.valueOf(girisTc.substring(9,10)) && toplam3%10 == Integer.valueOf(girisTc.substring(10,11))){
                gecerliKimlik++;
            }
            else{
                gecersizKimlik++;
            }
         } 
    }
    
    public void kontrolYaz(){
        System.out.println("T.C. Kimlik Kontrol");
        System.out.println(gecerliKimlik + "  Geçerli");
        System.out.println(gecersizKimlik + "  Geçersiz");        
    }
    
}
