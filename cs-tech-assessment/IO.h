//
// Created by yslme on 17.02.2022.
//

#ifndef CS_TECH_ASSESSMENT_IO_H
#define CS_TECH_ASSESSMENT_IO_H

#include <fstream>
#include <cstring>


class IO {
public:
    static std::string* oku(const std::string& path);
    static void yaz(std::string dosya_adi, float puan_beyaz, float puan_siyah, const std::string& path);
};


#endif //CS_TECH_ASSESSMENT_IO_H
