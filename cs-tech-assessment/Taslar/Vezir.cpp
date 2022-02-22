//
// Created by yslme on 16.02.2022.
//

#include "Vezir.h"

Vezir::Vezir(char renk, Konum &konum) {
    this->renk=renk;
    this->konum=&konum;
    //ilk karakter isim olarak ataniyor.
    this->isim='v';
    this->puan=9.0;
}

std::vector<std::vector<Konum>> Vezir::tehditEdilenKareler() {
    /*
     * Yataydaki, dikeydeki ve caprazlardaki Konumlar ayri ayri vektorler icerisinde depolaniyor.
     * Bu sayede Tahta::tehditDurumlariniHesaplama fonksiyonu icersindeki dongulerde,
     * yatayda, dikeyde ve/veya caprazlarda yol uzerinde bir engele rastlandiginda, o vektore
     * ait dongu sonlandiriliyor. Bu sayede engelden sonraki kareler dikkate alinmiyor.
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

    //Vezirin tehdit ettigi kareler, Konum cinsinden birer nesne olarak ilgili vektorlere ekleniyor.
    /*
     * Vezirin herhangi bir engelle karsilasmadan gidebilecegi maksimum kare sayisi 7.
     * Bu sebeple dongu 7 kez donuyor.
     */
    for (int i=1; i<=7; i++){
        //ust yol: tasin bulundugu konumdan yukari dogru tahta icerisinde kalan her kare
        if (char(satir+i) <= '8'){
            vector_ust.push_back(Konum(sutun,satir+i));
            //sol ust
            if (char(sutun-i) >= 'a'){
                vector_solust.push_back(Konum(sutun-i,satir+i));
            }
            //sag ust
            if (char(sutun+i) <= 'h'){
                vector_sagust.push_back(Konum(sutun+i,satir+i));
            }
        }
        //alt yol: tasin bulundugu konumdan asagiya dogru tahta icerisinde kalan her kare
        if (char(satir-i) >= '1'){
            vector_alt.push_back(Konum(sutun,satir-i));
            //sag alt
            if (char(sutun+i) <= 'h'){
                vector_sagalt.push_back(Konum(sutun+i,satir-i));
            }
            //sol alt
            if (char(sutun-i) >= 'a'){
                vector_solalt.push_back(Konum(sutun-i,satir-i));
            }
        }
        //caprazlar yukaridaki kosul tanimlari icerisinde ele alindigi icin bu bolumde sadece yataylar ele aliniyor.
        //sag yol: tasin bulundugu konumdan saga dogru tahta icerisinde kalan her kare
        if (char(sutun+i) <= 'h'){
            vector_sag.push_back(Konum(sutun+i,satir));
        }
        //sol yol: tasin bulundugu konumdan sola dogru tahta icerisinde kalan her kare
        if (char(sutun-i) >= 'a'){
            vector_sol.push_back(Konum(sutun-i,satir));
        }
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

