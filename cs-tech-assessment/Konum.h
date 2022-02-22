//
// Created by yslme on 16.02.2022.
//

#ifndef CS_TECH_ASSESSMENT_KONUM_H
#define CS_TECH_ASSESSMENT_KONUM_H


class Konum {
private:
    //satir ve sutun birer karakter cinsinden depolaniyor. orn: 'e','4'
    char sutun;
    char satir;
public:
    //dizilerin baslatilabilmesi icin gerekli olan parametresiz constructor fonksiyonu
    Konum();
    //satir ve sutunu parametre olarak alan constructor fonksiyonu
    Konum(char,char);
    //teml ozelliklerin get fonksiyonlar
    char getSatir() const;
    char getSutun() const;
    //iki konumun ayni olmasi durumunu kontrol etmek icin operator overloading
    bool operator==(const Konum&) const;
};


#endif //CS_TECH_ASSESSMENT_KONUM_H
