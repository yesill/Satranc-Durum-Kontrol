//
// Created by yslme on 16.02.2022.
//

#include "Piyon.h"

Piyon::Piyon(char renk, Konum &konum) {
    this->renk=renk;
    this->konum=&konum;
    //ilk karakter isim olarak ataniyor.
    this->isim='p';
    this->puan=1.0;
}

std::vector<std::vector<Konum>> Piyon::tehditEdilenKareler() {
    /*
     * Piyonun tehdit ettigi her kare, "Tahta::tehditDurumlariniHesaplama" icerisinde kullanilabilmesi icin
     * ayri ayri vektorlere kaydediliyor.
     */
    std::vector<std::vector<Konum>> vector_return;
    std::vector<Konum> vector_capraz_sol;
    std::vector<Konum> vector_capraz_sag;

    char sutun = konum->getSutun();
    char satir = konum->getSatir();

    //Piyonun tehdit ettigi kareler, Konum cinsinden birer nesne olarak ilgili vektorlere ekleniyor.
    //tas tahtanin en ustunde ise
    if (char(satir+1) <= '8'){
        //piyon beyaz ise bir satir yukariyi tehdit eder, siyah ise bir satir asagiyi
        satir = (renk=='b' ? char(satir+1) : char(satir-1));
    }
    //tas tahtanin en altinda ise
    if (char(satir-1) >= '1'){
        //piyon beyaz ise bir satir yukariyi tehdit eder, siyah ise bir satir asagiyi
        satir = (renk=='b' ? char(satir+1) : char(satir-1));
    }
    //tas, tahtasnin en solunda ise
    if(char(sutun-1) >= 'a'){
        vector_capraz_sol.push_back(Konum(char(sutun-1),satir));
    }
    //tas, tahtanin en saginda ise
    if(char(sutun+1) <= 'h'){
        vector_capraz_sag.push_back(Konum(char(sutun+1),satir));
    }
    //yonlere ait vektorler ana vektore ekleniyor
    vector_return.push_back(vector_capraz_sol);
    vector_return.push_back(vector_capraz_sag);
    return vector_return;
}
