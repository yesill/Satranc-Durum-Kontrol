//
// Created by yslme on 16.02.2022.
//

#ifndef CS_TECH_ASSESSMENT_AT_H
#define CS_TECH_ASSESSMENT_AT_H

#include "Tas.h"

class At: public Tas {
public:
    At(char, Konum&);
    //Tehdit edilen karelerin konumlarini donduren fonksiyon. Aciklamasi govde icerisinde yapildi.
    std::vector<std::vector<Konum>> tehditEdilenKareler() override;
};


#endif //CS_TECH_ASSESSMENT_AT_H
