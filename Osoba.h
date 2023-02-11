//
// Created by zejva on 11.02.2023.
//

#ifndef UDAJE_OSOBA_H
#define UDAJE_OSOBA_H
#include <iostream>
#include <vector>

using namespace std;

class Osoba {

    public:
    Osoba();
        Osoba(string sName_in, string sSurname_in, float fHeight_in, int iAge_in, string sEdu_in);
        string name() const;
        string surname() const;
        float height() const;
        int age() const;
        string edu() const;

    protected:
        string sName, sSurname, sEdu;
        float fHeight;
        int iAge;

};


#endif //UDAJE_OSOBA_H
