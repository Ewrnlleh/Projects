/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Paket;

import java.io.IOException;


public class Kisi {
    
    private String kimlikNumarasi;
    private String isim;
    private String telefonNumarasi;
    private String imeiNumarasi;
    private int yas;
    
    public void kisiUret() throws IOException{
        
        RastgeleKisi kisi = new RastgeleKisi();
        isim = kisi.KisiSec();
        yas = kisi.Yas();
       
        KimlikNo kimlik = new KimlikNo();
        kimlikNumarasi = kimlik.tcUret();
        
        Telefon telefon = new Telefon();
        telefonNumarasi = telefon.telUret();
        
        IMEINo imei = new IMEINo();
        imeiNumarasi = imei.imeiUret();
    }
    
    public String kisiYaz(){    
        return(kimlikNumarasi+" "+isim+" "+yas+" "+telefonNumarasi+" ("+imeiNumarasi+")");
    }
    
}
