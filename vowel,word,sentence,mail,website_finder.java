
package find;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class find {


    public static void main(String[] args) throws IOException{
        
        //Dosya okuma
        File dosya = new File("icerik.txt");
        FileInputStream dosyaKayit =new FileInputStream(dosya);
        InputStreamReader giris =  new InputStreamReader(dosyaKayit,"UTF-8");//Turkce Karakter
        BufferedReader okuyucu = new BufferedReader(giris);
        
        String satir;
        
        String regexMail = "[A-Za-z0-9+_.-]+@[A-Za-z0-9_-]+\\.[A-Za-z0-9_.-]+";
        Pattern sekilMail = Pattern.compile(regexMail);
        
        //.com, .edu, .net, .org, .com.tr, .edu.tr, .net.tr, .org.tr
        String regexWeb = "(www\\.)?(\\w+)(\\.)+(com|edu|net|org|com.tr|edu.tr|net.tr|org.tr)";
        Pattern sekilWeb = Pattern.compile(regexWeb);
        
        int kelimeSayisi = 0;
        int cumleSayisi = 0;
        int sesliSayisi = 0;
        int mailSayisi = 0;
        int webSayisi= 0;
        
        char ch;
        char ch2;
        
        //satir satir okuma
        while((satir= okuyucu.readLine()) != null){
            
            // satırı charlara bölme
            for(int i=0; i<satir.length();i++)
            {
                ch= satir.charAt(i);
                
                // sesli harf kontrolu
                if(ch =='a'|| ch=='e'|| ch=='ı'|| ch=='i'|| ch=='o'|| ch=='ö'|| ch=='u'|| ch=='ü'||
                   ch =='A'|| ch=='E'|| ch=='I'|| ch=='İ'|| ch=='O'|| ch=='Ö'|| ch=='U'|| ch=='Ü')
                {
                    sesliSayisi++;
                }
                // noktaya göre cumle kontrolu
                else if (ch=='.')
                {
                    //satırın sonunda nokta olursa cumle sayma
                    if(i==(satir.length()-1)){
                        cumleSayisi++;
                    }
                    
                    // noktadan sonra bosluk gelirse cumle sayma
                    else{
                        ch2 = satir.charAt(i+1);
                        if(ch2 == ' '){
                            cumleSayisi++;
                        }
                    }
                }
                    
                // sondaki kelimeyi sayma
                if (i==(satir.length()-1)){
                    kelimeSayisi++;
                }
                // bosluga gore kelime sayma, hemen sonrasında gelen bosluklar gecersiz
                else if (ch==' '){
                    ch2 = satir.charAt(i+1);
                    if(ch2!=' '){
                        kelimeSayisi++;
                    }                    
                }
                
            }

            // satır boslukla baslıyorsa ilk boslukları saymama
            if(satir.length()>0){
                if (satir.charAt(0)==' '){
                    kelimeSayisi--;
                }
            }
           
            // kelimeleri ayırma
            String[] kelimeListesi = satir.split("\\s+"); 
               
            for (String kelime : kelimeListesi) {
                Matcher matcher = sekilMail.matcher(kelime);
                //mail olan kelimeleri bulma
                if(matcher.matches())
                {
                    mailSayisi++;
                }
                matcher = sekilWeb.matcher(kelime);
                // web sitesi olan kelimeleri bulma
                if(matcher.matches())
                {
                    webSayisi++;
                }
            }
              
        }       
        
        System.out.println("Toplam Sesli Harf Sayısı :" + sesliSayisi);
        System.out.println("Toplam Kelime Sayısı :" + kelimeSayisi);
        System.out.println("Toplam Cümle Sayısı :" + cumleSayisi);
        System.out.println("Toplam Mail Sayısı :" + mailSayisi);
        System.out.println("Toplam Web Sitesi Sayısı :" + webSayisi);
    }  
}
