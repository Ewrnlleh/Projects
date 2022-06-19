/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LBlock;

import java.util.Random;


public class RandomDeger extends Random{
    
    public static int[] nAdetRandomBitGetir(int n){
        String bits = ""; 
        int anahtar[] = new int[64];
        Random r = new Random();  
        for(int i=0; i<64; i++){ 
            int x = 0; 
            if(r.nextBoolean()==true)x=1;
            bits += x; 
        }
        for(int i=0 ; i < 16 ; i++) {
            String s = Integer.toBinaryString(Integer.parseInt(bits.charAt(i) + "", 16));
            while(s.length() < 4) {
                    s = "0" + s;
            }
            for(int j=0 ; j < 4  ; j++) {
                    anahtar[(4*i)+j] = Integer.parseInt(s.charAt(j) + "");
            }
        }
        return anahtar;
    }


}