//
// Created by zejva on 11.02.2023.
//

#include "Osoba.h"
#include <iostream>

Osoba::Osoba()
{
    //ctor
}

Osoba::Osoba(std::string sName_in, std::string sSurname_in, float fHeight_in, int iAge_in, std::string sEdu_in)
{
    sName = sName_in;
    sSurname = sSurname_in;
    fHeight = fHeight_in;
    iAge = iAge_in;
    sEdu = sEdu_in;

}

std::string Osoba::name() const {
    return sName;
}

std::string Osoba::surname() const {
    return sSurname;
}

float Osoba::height() const {
    return fHeight;
}

int Osoba::age() const {
    return iAge;
}

std::string Osoba::edu() const {
    return sEdu;
}