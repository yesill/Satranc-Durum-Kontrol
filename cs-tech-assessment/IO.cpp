//
// Created by yslme on 17.02.2022.
//

#include "IO.h"
#include <iostream>

std::string* IO::oku(const std::string& path) {
    //dosyadan okuma
    std::string* satirlar = new std::string[16];
    std::string satir;
    std::ifstream dosya_in(path);
    int i=0;
    if(dosya_in.is_open()){
        while(getline(dosya_in,satir)){
            satirlar[i] = satir;
            i++;
        }
        dosya_in.close();
    }

    return satirlar;
}

void IO::yaz(std::string dosya_adi, float puan_beyaz, float puan_siyah, const std::string& path) {
    //dosyaya yazma
    std::ofstream dosya_out;
    dosya_out.open(path, std::ios::app);
    if(dosya_out.is_open()){
        dosya_out << dosya_adi << "\tSiyah: " << puan_siyah << "\tBeyaz: " << puan_beyaz << "\n";
        dosya_out.close();
    }
}
