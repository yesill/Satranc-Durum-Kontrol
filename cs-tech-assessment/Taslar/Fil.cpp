//
// Created by yslme on 16.02.2022.
//

#include "Fil.h"

#include <iostream>


Fil::Fil(char renk, Konum &konum) {
    this->renk=renk;
    this->konum=&konum;
    //ilk karakter isim olarak ataniyor.
    this->isim='f';
    this->puan=3.0;
}

std::vector<std::vector<Konum>> Fil::tehditEdilenKareler() {
    /*
     * Yataydaki, dikeydeki ve caprazlardaki Konumlar ayri ayri vektorler icerisinde depolaniyor.
     * Bu sayede Tahta::tehditDurumlariniHesaplama fonksiyonu icersindeki dongulerde,
     * yatayda, dikeyde ve/veya caprazlarda yol uzerinde bir engele rastlandiginda, o vektore
     * ait dongu sonlandiriliyor. Bu sayede engelden sonraki kareler dikkate alinmiyor.
     */
    std::vector<std::vector<Konum>> vector_return;
    std::vector<Konum> vector_solust;
    std::vector<Konum> vector_sagust;
    std::vector<Konum> vector_sagalt;
    std::vector<Konum> vector_solalt;

    char sutun = konum->getSutun();
    char satir = konum->getSatir();

    //Filin tehdit ettigi kareler, Konum cinsinden birer nesne olarak ilgili vektorlere ekleniyor.
    /*
     * Filin herhangi bir engelle karsilasmadan gidebilecegi maksimum kare sayisi 7.
     * Bu sebeple dongu 7 kez donuyor.
     */
    for (int i=1; i<=7; i++){
        //sol ust capraz: tasin bulundugu konumdan sol uste dogru tahta icerisinde kalan her kare
        if (char(sutun-i) >= 'a' && char(satir+i) <= '8'){
            vector_solust.push_back(Konum(sutun-i,satir+i));
        }
        //sag ust capraz: tasin bulundugu konumdan sag uste dogru tahta icerisinde kalan her kare
        if (char(sutun+i) <= 'h' && char(satir+i) <= '8'){
            vector_sagust.push_back(Konum(sutun+i,satir+i));
        }
        //sag alt capraz: tasin bulundugu konumdan sag alta dogru tahta icerisinde kalan her kare
        if (char(sutun+i) <= 'h' && char(satir-i) >= '1'){
            vector_sagalt.push_back(Konum(sutun+i,satir-i));
        }
        //sol alt capraz: tasin bulundugu konumdan sol alta dogru tahta icerisinde kalan her kare
        if (char(sutun-i) >= 'a' && char(satir-i) >= '1'){
            vector_solalt.push_back(Konum(sutun-i,satir-i));
        }
    }
    //yonlere ait vektorler ana vektore ekleniyor
    vector_return.push_back(vector_solust);
    vector_return.push_back(vector_sagust);
    vector_return.push_back(vector_sagalt);
    vector_return.push_back(vector_solalt);
    return vector_return;
}