//
// Created by yslme on 16.02.2022.
//

#ifndef CS_TECH_ASSESSMENT_FIL_H
#define CS_TECH_ASSESSMENT_FIL_H

#include "Tas.h"

class Fil : public Tas {
public:
    Fil(char,Konum&);
    //Tehdit edilen karelerin konumlarini donduren fonksiyon. Aciklamasi govde icerisinde yapildi.
    std::vector<std::vector<Konum>> tehditEdilenKareler() override;
};


#endif //CS_TECH_ASSESSMENT_FIL_H
