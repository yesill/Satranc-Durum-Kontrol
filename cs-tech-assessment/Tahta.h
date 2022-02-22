//
// Created by yslme on 16.02.2022.
//

#ifndef CS_TECH_ASSESSMENT_TAHTA_H
#define CS_TECH_ASSESSMENT_TAHTA_H

#include <vector>
#include "Konum.h"
#include "Taslar/Tas.h"


class Tahta {
private:
    //okunacak ve yazilacak dosyalarin dosya yollari
    std::string path_oku, path_yaz;
    //tahtadaki her bir kare, Konum nesnesi olarak
    Konum* konumlar;
    //Beyaz ve siyah taslari tutan vektorler
    std::vector<Tas*> taslar_beyaz;
    std::vector<Tas*> taslar_siyah;
    //puanlar
    float puan_beyazlar=0, puan_siyahlar=0;
    //bu fonksiyonlarin aciklamalari govdeleri icerisinde yapilmistir.
    void konumlarOlustur();
    void taslarOlustur();
    void tehditDurumlariniHesaplama();
    void genelPuanHesaplama();
public:
    //okunacak ve yazilacak dosyalarin dosya yollarini alan constructor
    Tahta(const std::string& path_oku, const std::string& path_yaz);
    //sonuclari ekrana basan ve cikti dosyasina yazan fonksiyon
    void sonuclariBastir() const;
};


#endif //CS_TECH_ASSESSMENT_TAHTA_H
