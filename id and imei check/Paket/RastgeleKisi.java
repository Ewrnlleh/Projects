/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Paket;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class RastgeleKisi {
    

    public String KisiSec() throws IOException{
        
        String secilenSatir;
        Rastgele sayi = new Rastgele();
        
        try (Stream<String> all_lines = Files.lines(Paths.get("random_isimler.txt"))) {
            secilenSatir = all_lines.skip((sayi.rastgele(3000))-1).findFirst().get();
        }
        return secilenSatir;
    }

    public int Yas(){     
        Rastgele sayi = new Rastgele();
        return (sayi.rastgele(101)-1);
    }
}
