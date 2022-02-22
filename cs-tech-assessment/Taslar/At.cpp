//
// Created by yslme on 16.02.2022.
//

#include "At.h"

#include <iostream>

At::At(char renk, Konum &konum) {
    this->renk=renk;
    this->konum=&konum;
    //ilk karakter isim olarak ataniyor.
    this->isim='a';
    this->puan=3.0;
}

std::vector<std::vector<Konum>> At::tehditEdilenKareler() {
    /*
     * Atin hamlelerini isimlendirmek icin saat yonu kullanildi
     * --  --  --  --  --  --  --
     * --  --  11  --  01  --  --
     * --  10  --  --  --  02  --
     * --  --  --  ab  --  --  --
     * --  08  --  --  --  04  --
     * --  --  07  --  05  --  --
     * --  --  --  --  --  --  --
     * at, saat yonleri 12, 3, 6 ve 9 haric tehdit edebiliyor.
     * Atin tehdit ettigi her kare, "Tahta::tehditDurumlariniHesaplama" icerisinde kullanilabilmesi icin
     * ayri ayri vektorlere kaydediliyor.
     */
    std::vector<std::vector<Konum>> vector_return;
    std::vector<Konum> vector_saat_yonu_01;
    std::vector<Konum> vector_saat_yonu_02;
    std::vector<Konum> vector_saat_yonu_04;
    std::vector<Konum> vector_saat_yonu_05;
    std::vector<Konum> vector_saat_yonu_07;
    std::vector<Konum> vector_saat_yonu_08;
    std::vector<Konum> vector_saat_yonu_10;
    std::vector<Konum> vector_saat_yonu_11;

    char sutun = konum->getSutun();
    char satir = konum->getSatir();

    //Filin tehdit ettigi kareler, Konum cinsinden birer nesne olarak ilgili vektorlere ekleniyor.
    //saat 01 yonu;
    if (char(sutun+1) <= 'h' && char(satir+2) <= '8'){
        vector_saat_yonu_01.push_back(Konum(sutun+1,satir+2));
    }
    //saat 02 yonu;
    if (char(sutun+2) <= 'h' && char(satir+1) <= '8'){
        vector_saat_yonu_02.push_back(Konum(sutun+2,satir+1));
    }
    //saat 04 yonu;
    if (char(sutun+2) <= 'h' && char(satir-1) >= '1'){
        vector_saat_yonu_04.push_back(Konum(sutun+2,satir-1));
    }
    //saat 05 yonu;
    if (char(sutun+1) <= 'h' && char(satir-2) >= '1'){
        vector_saat_yonu_05.push_back(Konum(sutun+1,satir-2));
    }
    //saat 07 yonu;
    if (char(sutun-1) >= 'a' && char(satir-2) >= '1'){
        vector_saat_yonu_07.push_back(Konum(sutun-1,satir-2));
    }
    //saat 08 yonu;
    if (char(sutun-2) >= 'a' && char(satir-1) >= '1'){
        vector_saat_yonu_08.push_back(Konum(sutun-2,satir-1));
    }
    //saat 10 yonu;
    if (char(sutun-2) >= 'a' && char(satir+1) <= '8'){
        vector_saat_yonu_10.push_back(Konum(sutun-2,satir+1));
    }
    //saat 11 yonu;
    if (char(sutun-1) >= 'a' && char(satir+2) <= '8'){
        vector_saat_yonu_11.push_back(Konum(sutun-1,satir+2));
    }
    //yonlere ait vektorler ana vektore ekleniyor
    vector_return.push_back(vector_saat_yonu_01);
    vector_return.push_back(vector_saat_yonu_02);
    vector_return.push_back(vector_saat_yonu_04);
    vector_return.push_back(vector_saat_yonu_05);
    vector_return.push_back(vector_saat_yonu_07);
    vector_return.push_back(vector_saat_yonu_08);
    vector_return.push_back(vector_saat_yonu_10);
    vector_return.push_back(vector_saat_yonu_11);
    return vector_return;
}
