/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LBlock;

import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class Program {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
Scanner in = new Scanner(System.in);
        LBlock lblock=null;
        Random rand =null;
        int sec=0;
        
        do{
            System.out.println("1. 16 Bitlik Karakter ?ifreleme Yap ");
            System.out.println("3. Cikis");
            System.out.print("Se?iminizi Yap?n?z=>");
            sec = in.nextInt();
            switch(sec)
            {
                case 1:
                    System.out.print("16 bitlik ?ifrelenecek hexa-decimal veriyi giriniz..:");
                    String input = new Scanner(System.in).nextLine();
                    int inputBits[] = new int[64];

                    for(int i=0 ; i < 16 ; i++) {//i=0
                        String s = Integer.toBinaryString(Integer.parseInt(input.charAt(i) + "", 16));
                        while(s.length() < 4) {
                                s = "0" + s;
                        }
                        for(int j=0 ; j < 4 ; j++) {
                                inputBits[(4*i)+j] = Integer.parseInt(s.charAt(j) + "");
                        }
                    }
                    System.out.println("Girmi? oldu?unuz verinin B?NARY kar??l???..:");
                    for(int j=0 ; j < 64 ; j++) {
                            System.out.print(inputBits[j]);
                    }
                    System.out.println("\n ?imdi anahtar?n?z? üretiyorum ...\n.............");
                   
                    
                    int anahtar[] = new int[64];
                    anahtar = RandomDeger.nAdetRandomBitGetir(64);
                    System.out.println("??te üretti?im anahtar ..:");
                    for (int i = 0; i < 64; i++) {
                        System.out.print(anahtar[i]);
                    }                         
                    
                    int x[][]= new int[34][32];
                    System.out.println("\n?ifreleme Ba?l?yor");
                    
                    LBlock.fiestelNetwork(inputBits, anahtar);
                break;
            }
        }while(sec != 3);
    }
}
