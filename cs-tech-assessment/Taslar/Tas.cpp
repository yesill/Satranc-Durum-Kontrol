//
// Created by yslme on 16.02.2022.
//

#include "Tas.h"

char Tas::getIsim() const {
    return isim;
}

char Tas::getRenk() const {
    return renk;
}

float Tas::getPuan() const {
    //tas tehdit altinda ise puaninin yarisi returnlenir.
    return (tehdit_altinda ? puan/2 : puan);
}

Konum Tas::getKonum() const {
    return *konum;
}

void Tas::setTehditAltinda(bool tehdit_durumu) {
    tehdit_altinda = tehdit_durumu;
}

bool Tas::getTehditAltinda() const{
    return tehdit_altinda;
}

