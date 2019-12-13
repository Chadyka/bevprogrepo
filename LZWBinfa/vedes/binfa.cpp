#include <iostream>
#include <cmath>
#include "binfa.h"
class LZWBinFa;


LZWBinFa() : fa(&gyoker)
{
}
~LZWBinFa()
{
    szabadit(gyoker.egyesGyermek());
    szabadit(gyoker.nullasGyermek());
}

void insert(char b)
{
    if (b == '0')
    {
        if (!fa->nullasGyermek())
        {
            Csomopont *uj = new Csomopont('0');
            fa->ujNullasGyermek(uj);
            fa = &gyoker;
        }
        else
        {
            fa = fa->nullasGyermek();
        }
    }
    else
    {
        if (!fa->egyesGyermek())
        {
            Csomopont *uj = new Csomopont('1');
            fa->ujEgyesGyermek(uj);
            fa = &gyoker;
        }
        else
        {
            fa = fa->egyesGyermek();
        }
    }
}

void kiir(void)
{
    melyseg = 0;
    kiir(&gyoker, std::cout);
}

void kiir(std::ostream &os)
{
    melyseg = 0;
    kiir(&gyoker, os);
}

void kiir(Csomopont *elem, std::ostream &os)
{
    if (elem != NULL)
    {
        ++melyseg;
        kiir(elem->egyesGyermek(), os);
        for (int i = 0; i < melyseg; ++i)
            os << "---";
        os << elem->getBetu() << "(" << melyseg - 1 << ")" << std::endl;
        kiir(elem->nullasGyermek(), os);
        --melyseg;
    }
}
void LZWBinFa::szabadit(Csomopont *elem)
{
    if (elem != NULL)
    {
        szabadit(elem->egyesGyermek());
        szabadit(elem->nullasGyermek());
        delete elem;
    }
}

int LZWBinFa::getMelyseg(void)
{
    melyseg = maxMelyseg = 0;
    rmelyseg(&gyoker);
    return maxMelyseg - 1;
}

double
getAtlag(void)
{
    melyseg = atlagosszeg = atlagdb = 0;
    ratlag(&gyoker);
    atlag = ((double)atlagosszeg) / atlagdb;
    return atlag;
}

double
LZWBinFa::getSzoras(void)
{
    atlag = getAtlag();
    szorasosszeg = 0.0;
    melyseg = atlagdb = 0;

    rszoras(&gyoker);

    if (atlagdb - 1 > 0)
        szoras = std::sqrt(szorasosszeg / (atlagdb - 1));
    else
        szoras = std::sqrt(szorasosszeg);

    return szoras;
}

void LZWBinFa::rmelyseg(Csomopont *elem)
{
    if (elem != NULL)
    {
        ++melyseg;
        if (melyseg > maxMelyseg)
            maxMelyseg = melyseg;
        rmelyseg(elem->egyesGyermek());
        rmelyseg(elem->nullasGyermek());
        --melyseg;
    }
}

void LZWBinFa::ratlag(Csomopont *elem)
{
    if (elem != NULL)
    {
        ++melyseg;
        ratlag(elem->egyesGyermek());
        ratlag(elem->nullasGyermek());
        --melyseg;
        if (elem->egyesGyermek() == NULL && elem->nullasGyermek() == NULL)
        {
            ++atlagdb;
            atlagosszeg += melyseg;
        }
    }
}

void LZWBinFa::rszoras(Csomopont *elem)
{
    if (elem != NULL)
    {
        ++melyseg;
        rszoras(elem->egyesGyermek());
        rszoras(elem->nullasGyermek());
        --melyseg;
        if (elem->egyesGyermek() == NULL && elem->nullasGyermek() == NULL)
        {
            ++atlagdb;
            szorasosszeg += ((melyseg - atlag) * (melyseg - atlag));
        }
    }
}

void usage(void)
{
    std::cout << "Usage: lzwtree in_file -o out_file" << std::endl;
}