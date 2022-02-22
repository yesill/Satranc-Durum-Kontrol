//
// Created by yslme on 16.02.2022.
//
#include <iostream>
#include <vector>

#include "Tahta.h"
#include "IO.h"
#include "Taslar/Piyon.h"
#include "Taslar/Fil.h"
#include "Taslar/At.h"
#include "Taslar/Kale.h"
#include "Taslar/Vezir.h"
#include "Taslar/Sah.h"

#define KARE_ADEDI 64

Tahta::Tahta(const std::string& path_oku, const std::string& path_yaz) {
    //okunacak dosyanin yolu
    this->path_oku = path_oku;
    //yazilacak dosyanin yolu
    this->path_yaz = path_yaz;

    //assagidaki methodlarin aciklamalari methodlarin govdeleri icerisinde bulunmaktadir.

    //tahtadaki her bir karenin konumu olusturuluyor.
    konumlarOlustur();

    //girdi olarak verilen taslari konumlarla eslestiriyoruz.
    taslarOlustur();

    //tehdit durumlarini hesaplama
    tehditDurumlariniHesaplama();

    //genel paunlarin hesabi
    genelPuanHesaplama();
}

void Tahta::konumlarOlustur() {
    /*
     * Tahtadaki her bir karenin konumu, konum turunden bir nesne olarak olusturuluyor.
     * Tahtadaki taslar konumlara yerlestirileceginde ayni indisler kullanilarak taslarin
     * konum atamalari kolayca yapilabiliyor.
     */
    konumlar = new Konum[KARE_ADEDI];
    int k=0;
    for(char c2='8'; c2>='1';c2--){
        for(char c1='a'; c1<='h';c1++){
            konumlar[k] = Konum(c1,c2);
            k++;
        }
    }
}

void Tahta::taslarOlustur() {
    //IO sinifi ile okunan txt girdileri satirlar halinde aliniyor.
    std::string* satirlar = IO::oku(path_oku);

    /*
     * input olarak alinan tahtadaki taslarin ve konumlarinin yerlestirilmesi.
     * IO sinifi dosya yolu verilen txt'den satirlari okuyarak geri gonderiyor.
     * Bu sebeple ilk dongu satir. Ikinci dongu sutun.
     */
    //donguler icerisinde kullanilacak sayac
    int konum_sayac=0;
    for (int sat=0; sat<8; sat++){
        /*
         * txt icerisinde verilen tahta sablonunda bir satirda bosluklar dahil toplam 23 karakter bulunmakta.
         * ornek satir: kb -- fb sb -- -- ab --
         * Ikinci dongu icerisinde sutun iteratoru, substring alinirken bosluk karakterini atlayip
         * bir sonraki tasa gecmesini saglamak amaciyla 3 ile carpiliyor.
         * kb -- fb sb -- -- ab --
         * -^ substring 2 karakter olarak aliniyor.
         * kb -- fb sb -- -- ab --
         * --^ 3 karakter atlanarak(sutun_sayac * 3) bosluktan sonraki karaktere geciliyor.
         */
        for (int sut=0; sut<8; sut++, konum_sayac++){
            //vb -> tas_turu: v=vezir, tas_rengi: b=beyaz
            char tas_turu = satirlar[sat].substr(sut*3,2)[0];   //"vb"[0] -> v
            char tas_rengi = satirlar[sat].substr(sut*3,2)[1];  //"vb"[1] -> b

            //oncelikle taslar renklerine gore ayriliyor.
            if (tas_rengi == 'b'){
                switch (tas_turu) {
                    /*
                     * Taslar olusturulurken, mimari geregi tasin bulundugu kare Konum sinifindan
                     * bir obje ile belirtilmelidir. Konum objesi, sutunu ve satiri iki farkli ozellik
                     * olarak char turunden almaktadir. "konumlarOlustur" methodunun icerisinde hazirlanan
                     * konumlar dizisine gerekli indisler verilirek konumlar kolayca taslara atanabiliyor.
                     */
                    //tas turu piyon ise
                    case 'p':{
                        taslar_beyaz.push_back(new Piyon(tas_rengi, konumlar[konum_sayac]));
                        break;
                    }
                    //tas turu at ise
                    case 'a':{
                        taslar_beyaz.push_back(new At(tas_rengi, konumlar[konum_sayac]));
                        break;
                    }
                    //tas turu fil ise
                    case 'f':{
                        taslar_beyaz.push_back(new Fil(tas_rengi, konumlar[konum_sayac]));
                        break;
                    }
                    //tas turu kale ise
                    case 'k':{
                        taslar_beyaz.push_back(new Kale(tas_rengi, konumlar[konum_sayac]));
                        break;
                    }
                    //tas turu vezir ise
                    case 'v':{
                        taslar_beyaz.push_back(new Vezir(tas_rengi, konumlar[konum_sayac]));
                        break;
                    }
                    //tas turu sah ise
                    case 's':{
                        taslar_beyaz.push_back(new Sah(tas_rengi, konumlar[konum_sayac]));
                        break;
                    }
                }
            }
            else if (tas_rengi == 's'){
                switch (tas_turu) {
                    //tas turu piyon ise
                    case 'p':{
                        taslar_siyah.push_back(new Piyon(tas_rengi, konumlar[konum_sayac]));
                        break;
                    }
                    //tas turu at ise
                    case 'a':{
                        taslar_siyah.push_back(new At(tas_rengi, konumlar[konum_sayac]));
                        break;
                    }
                    //tas turu fil ise
                    case 'f':{
                        taslar_siyah.push_back(new Fil(tas_rengi, konumlar[konum_sayac]));
                        break;
                    }
                    //tas turu kale ise
                    case 'k':{
                        taslar_siyah.push_back(new Kale(tas_rengi, konumlar[konum_sayac]));
                        break;
                    }
                    //tas turu vezir ise
                    case 'v':{
                        taslar_siyah.push_back(new Vezir(tas_rengi, konumlar[konum_sayac]));
                        break;
                    }
                    //tas turu sah ise
                    case 's':{
                        taslar_siyah.push_back(new Sah(tas_rengi, konumlar[konum_sayac]));
                        break;
                    }
                }
            }
            else{
                /*
                 * Tas rengi siyah veya beyaz degil ise girdi formatina gore '-' olabilir.
                 * tas renginin '-' olmasi tahtadaki o konumun bos oldugu anlamina gelir.
                 * Bu durumda herhangi bir islem yapilmasina gerek yoktur.
                 */
                continue;
            }
        }
    }
}

void Tahta::tehditDurumlariniHesaplama() {
    /*
     * - Beyaz taslar vektoru icerisinde for dongusu ile gezilir.
     * - i. tasin tehdit ettigi kareler "tehditEdilenKareler" methodu ile alinir.
     * - Tehdit edilen bu kareler icerisinde bir for dongusu ile gezilir.
     * - Bir dongu daha olusturulur bu dongude siyah taslar icerisinde gezilir.
     * - i. siyah tas, beyaz tas tarafindan tehdit edilen bir karede ise,
     * bu tasin "tehdit_altinda" ozelligine "true" degeri atanir.
     * - "tehdit_altinda = true" olan taslarin "getPuan" methodlari yarim puan returnler.
     * - Bu sayede ayni tasin birden fazla tas tarafindan tehdit edilmesi puani tekrar tekrar ikiye bolmez.
     * - Bu islemler diger renk icinde tekrarlanir.
     * - Her iki rengin taslarinin paunlari alinir ve iki farkli genel puan hesaplanir.
     */

    //Beyaz taslarin tehdit ettigi karelerin hesabi
    for(int sayac1=0; sayac1<taslar_beyaz.size(); sayac1++){
        std::vector<std::vector<Konum>> vector_ana = taslar_beyaz[sayac1]->tehditEdilenKareler();

        for (int sayac2=0; sayac2<vector_ana.size(); sayac2++) {
            //vector icerisinde vector yapisi burada ic vektorlerine ayriliyor.
            std::vector<Konum> temp = vector_ana[sayac2];

            /*
             * mevcut tasin yatayda, dikeyde ve/veya caprazlarda yolu uzerinde,
             * kendi renginden bir tas var ise, o tasin konumuna gelindiginde dongu
             * "stop=true" atanarak kesilir. Engel olan tastan sonraki kareler kontrol edilmez.
             * Rakip renkten bir tas var ise, o tasin konumuna gelindiginde tasin "tehdit_durumu=true"
             * ve "stop=true" atanir. Engel olan tas rakip renkten oldugu icin tehdit ediliyor olarak
             * isaretlenir ve sonraki kareler kontrol edilmez.
             */
            bool stop = false;
            for (int sayac3 = 0; sayac3 < temp.size() && !stop; sayac3++) {

                //beyaz tas engeli var mi?
                for (int sayac4 = 0; sayac4 < taslar_beyaz.size(); sayac4++) {
                    if (temp[sayac3] == taslar_beyaz[sayac4]->getKonum()) {
                        stop = true;
                        break;
                    }
                }
                //siyah tas tehdidi var mi?
                for (int sayac4 = 0; sayac4 < taslar_siyah.size(); sayac4++) {
                    if (temp[sayac3] == taslar_siyah[sayac4]->getKonum()) {
                        taslar_siyah[sayac4]->setTehditAltinda(true);
                        stop = true;
                        break;
                    }
                }
            }
        }
    }

    //siyah taslarin tehdit ettigi karelerin hesabi
    for(int sayac1=0; sayac1<taslar_siyah.size(); sayac1++){
        std::vector<std::vector<Konum>> vector_ana = taslar_siyah[sayac1]->tehditEdilenKareler();

        for (int sayac2=0; sayac2<vector_ana.size(); sayac2++) {
            std::vector<Konum> temp = vector_ana[sayac2];

            bool stop = false;
            for (int sayac3 = 0; sayac3 < temp.size() && !stop; sayac3++) {

                //siyah tas engeli var mi?
                for (int sayac4 = 0; sayac4 < taslar_siyah.size(); sayac4++) {
                    if (temp[sayac3] == taslar_siyah[sayac4]->getKonum()) {
                        stop = true;
                        break;
                    }
                }
                //beyaz tas tehdidi var mi?
                for (int sayac4 = 0; sayac4 < taslar_beyaz.size(); sayac4++) {
                    if (temp[sayac3] == taslar_beyaz[sayac4]->getKonum()) {
                        taslar_beyaz[sayac4]->setTehditAltinda(true);
                        stop = true;
                        break;
                    }
                }
            }
        }
    }

}

void Tahta::genelPuanHesaplama() {
    /*
     * "tehditDurumlariniHesaplama" fonksiyonunda "tehdit_durumu=true" atanan taslar,
     * "getPuan" fonksiyonu cagirildiginda orjinal puanlarinin yarisini returnlerler.
     */
    for (int i=0; i<taslar_beyaz.size(); i++){
        puan_beyazlar += taslar_beyaz[i]->getPuan();
    }
    for (int i=0; i<taslar_siyah.size(); i++){
        puan_siyahlar += taslar_siyah[i]->getPuan();
    }
}

void Tahta::sonuclariBastir() const {
    /*
     * Tahta uzerindeki taslarin butun ozellikleri ekrana basilir.
     * Istenen formatta dosya yolu verilen txt dosyasina yazilir.
     */
    std::cout << "Beyaz Taslar" << std::endl;

    for (int i=0; i<taslar_beyaz.size(); i++){
        std::cout << taslar_beyaz[i]->getIsim() << taslar_beyaz[i]->getRenk() << ", ";
        std::cout << taslar_beyaz[i]->getKonum().getSutun() << taslar_beyaz[i]->getKonum().getSatir() << ", ";
        std::cout << (taslar_beyaz[i]->getTehditAltinda() ? "tehdit(+)": "tehdit(-)") << ", ";
        std::cout << taslar_beyaz[i]->getPuan() << std::endl;
    }
    //------------------------------------------------------------------------------------------------
    std::cout << std::endl;
    std::cout << "Siyah Taslar" << std::endl;
    for (int i=0; i<taslar_siyah.size(); i++){
        std::cout << taslar_siyah[i]->getIsim() << taslar_siyah[i]->getRenk() << ", ";
        std::cout << taslar_siyah[i]->getKonum().getSutun() << taslar_siyah[i]->getKonum().getSatir() << ", ";
        std::cout << (taslar_siyah[i]->getTehditAltinda() ? "tehdit(+)": "tehdit(-)") << ", ";
        std::cout << taslar_siyah[i]->getPuan() << std::endl;
    }

    std::cout << std::endl;
    std::cout << path_oku.substr(path_oku.length()-10) << "\t";
    std::cout << "Beyaz:" << puan_beyazlar << "\t";
    std::cout << "Siyah:" << puan_siyahlar << std::endl;
    //------------------------------------------------------------------------------------------------
    //dosyaya yazma
    std::string dosya_adi = path_oku.substr(path_oku.length()-10);
    IO::yaz(dosya_adi, puan_beyazlar, puan_siyahlar, path_yaz);
}

