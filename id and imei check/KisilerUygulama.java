/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package kisileruygulama;

import Paket.IMEINo;
import Paket.KimlikNo;
import Paket.Kisi;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class KisilerUygulama {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        
        Scanner giris=new Scanner(System.in);
        int kisiSayisi;
        int secim;  
        do
        {
           System.out.println("1-Rastgele Kişi Üret\n2-Üretilmiş Dosya Kontrol Et\n3-Çıkış");
           secim = giris.nextInt();
           switch(secim){
                case 1:
                   System.out.println("Kaç adet kişi üretilmesini istersiniz: ");
                   kisiSayisi = giris.nextInt();
                   Kisi kisi = new Kisi();
                   PrintWriter writer = new PrintWriter("Kisiler.txt", "UTF-8");
                   for(int i=0;i<kisiSayisi;i++){
                       kisi.kisiUret();
                       writer.println(kisi.kisiYaz());
                   }
                   writer.close();
                   System.out.println("Kişiler dosyaya kaydedilmiştir.");
                   break;

                case 2:
                    try {
                        FileInputStream fstream = new FileInputStream("Kisiler.txt");
                        DataInputStream in = new DataInputStream(fstream);
                        BufferedReader br = new BufferedReader(new InputStreamReader(in));
                        String satir;
                        
                        KimlikNo kimlik = new KimlikNo();
                        IMEINo imei = new IMEINo();
                        
                        Pattern pk = Pattern.compile("^1?(\\d{11})");
                        Pattern pi = Pattern.compile("1?(\\d{15})");  
                        
                        while ((satir = br.readLine()) != null) {
                            Matcher mk = pk.matcher(satir);
                            Matcher mi = pi.matcher(satir);
                            while (mk.find())
                            {    
                                kimlik.tcKontrol(mk.group());
                            }
                            while (mi.find())
                            {
                                imei.imeiKontrol(mi.group());
                            }
                        }
                        kimlik.kontrolYaz();
                        imei.kontrolYaz();

                    } catch (FileNotFoundException e) {
                        System.err.println("Hata: Dosya Bulunamadı " + e.getMessage());
                    }
                   break;
                   
                case 3:
                   System.exit(0);
                   break;
              }  
         }
         while(secim < 4);
            
    }  
}  

