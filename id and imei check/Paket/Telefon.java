/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Paket;


public class Telefon {
    
    public String telUret(){
        
        Rastgele sayi = new Rastgele();
        int tel1,tel2,tel3,tel4,tel5,tel6,tel7,tel8,tel9,tel10,tel11;
        
        tel1 = 0;
        tel2 = (sayi.rastgele(10))-1;
        tel3 = (sayi.rastgele(10))-1;
        tel4 = (sayi.rastgele(10))-1;
        tel5 = (sayi.rastgele(10))-1;
        tel6 = (sayi.rastgele(10))-1;
        tel7 = (sayi.rastgele(10))-1;
        tel8 = (sayi.rastgele(10))-1;
        tel9 = (sayi.rastgele(10))-1;
        tel10 = (sayi.rastgele(10))-1;
        tel11 = (sayi.rastgele(10))-1;
        
        return String.format("%s%s%s%s%s%s%s%s%s%s%s", tel1,tel2,tel3,tel4,tel5,tel6,tel7,tel8,tel9,tel10,tel11);
        
    }   
}
