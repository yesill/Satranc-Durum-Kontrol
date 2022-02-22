//
// Created by yslme on 16.02.2022.
//

#include "Konum.h"


Konum::Konum() {
    satir='0';
    sutun='0';
}

Konum::Konum(char sutun, char satir) {
    this->sutun = sutun;
    this->satir = satir;
}

char Konum::getSatir() const {
    return satir;
}

char Konum::getSutun() const {
    return sutun;
}

//iki konumun ayni olmasi durumunu kontrol etmek icin operator overloading
bool Konum::operator==(const Konum & konum) const {
    //iki konumun ayni olmasi icin satirlarinin ve sutunlarinin ayni olmasi gerekir.
    if(sutun == konum.getSutun() && satir == konum.getSatir()){
        return true;
    }
    else{
        return false;
    }
}
