//
// Created by yslme on 16.02.2022.
//

#include "Sah.h"

Sah::Sah(char renk, Konum &konum){
    this->renk=renk;
    this->konum=&konum;
    //ilk karakter isim olarak ataniyor.
    this->isim='s';
    this->puan=100.0;
}

std::vector<std::vector<Konum>> Sah::tehditEdilenKareler() {
    /*
     * Sahin tehdit ettigi her kare, "Tahta::tehditDurumlariniHesaplama" icerisinde kullanilabilmesi icin
     * ayri ayri vektorlere kaydediliyor.
     */
    std::vector<std::vector<Konum>> vector_return;
    std::vector<Konum> vector_ust;
    std::vector<Konum> vector_alt;
    std::vector<Konum> vector_sag;
    std::vector<Konum> vector_sol;
    std::vector<Konum> vector_solust;
    std::vector<Konum> vector_sagust;
    std::vector<Konum> vector_sagalt;
    std::vector<Konum> vector_solalt;

    char sutun = konum->getSutun();
    char satir = konum->getSatir();

    //sahin tehdit ettigi kareler, Konum cinsinden birer nesne olarak ilgili vektorlere ekleniyor.
    //ust
    if (char(satir+1) <= '8'){
        vector_ust.push_back(Konum(sutun,satir+1));
        //sol ust
        if (char(sutun-1) >= 'a'){
            vector_solust.push_back(Konum(sutun-1,satir+1));
        }
        //sag ust
        if (char(sutun+1) <= 'h'){
            vector_sagust.push_back(Konum(sutun+1,satir+1));
        }
    }
    //alt
    if (char(satir-1) >= '1'){
        vector_alt.push_back(Konum(sutun,satir-1));
        //sag alt
        if (char(sutun+1) <= 'h'){
            vector_sagalt.push_back(Konum(sutun+1,satir-1));
        }
        //sol alt
        if (char(sutun-1) >= 'a'){
            vector_solalt.push_back(Konum(sutun-1,satir-1));
        }
    }
    //sag
    if (char(sutun+1) <= 'h'){
        vector_sag.push_back(Konum(sutun+1,satir));
    }
    //sol
    if (char(sutun-1) >= 'a'){
        vector_sol.push_back(Konum(sutun-1,satir));
    }
    //yonlere ait vektorler ana vektore ekleniyor
    vector_return.push_back(vector_ust);
    vector_return.push_back(vector_alt);
    vector_return.push_back(vector_sag);
    vector_return.push_back(vector_sol);
    vector_return.push_back(vector_solust);
    vector_return.push_back(vector_sagust);
    vector_return.push_back(vector_sagalt);
    vector_return.push_back(vector_solalt);
    return vector_return;
}
