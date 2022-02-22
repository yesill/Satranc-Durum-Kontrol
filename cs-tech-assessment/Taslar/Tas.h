//
// Created by yslme on 16.02.2022.
//

#ifndef CS_TECH_ASSESSMENT_TAS_H
#define CS_TECH_ASSESSMENT_TAS_H

#include "../Konum.h"
#include <vector>


class Tas {
protected:
    //taslarin temel ozellikleri
    char isim;
    char renk;
    float puan;
    //halihazirda var olan konumu referans olarak constructor icerisinde alacagiz
    Konum *konum;
    //baska renkten bir tas tarafindan tehdit edilme durumu
    bool tehdit_altinda = false;
public:
    //temel ozelliklere ait get fonksiyonlari
    char getIsim() const;
    char getRenk() const;
    float getPuan() const;
    Konum getKonum() const;
    bool getTehditAltinda() const;
    //tehdit durumunu guncelleyen fonksiyon
    void setTehditAltinda(bool);
    /*
     * Tas adinda bir tas olamayacagi icin tas sinifi soyut sinif olarak tasarlandi.
     * her tas cesidinin tehdit edebilecegi karelerin hesaplari farkli oldugu icin
     * bu sanal fonksiyon her bir tas turu icerisinde override ediliyor.
     */
    virtual std::vector<std::vector<Konum>> tehditEdilenKareler() = 0;
};


#endif //CS_TECH_ASSESSMENT_TAS_H
