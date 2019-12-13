#include <iostream>
#include "csomopont.h"

class LZWBinFa
{
public:
    LZWBinFa ();
    ~LZWBinFa ();
    
    void operator<< (char b);
    void kiir (void);
    int getMelyseg (void);
    double getAtlag (void);
    double getSzoras (void);
    void usage(void);
    void kiir (std::ostream & os);

    friend std::ostream & operator<< (std::ostream & os, LZWBinFa & bf);

private:
    Csomopont *fa;
    int melyseg, atlagosszeg, atlagdb;
    double szorasosszeg;

    LZWBinFa (const LZWBinFa &);
    LZWBinFa & operator= (const LZWBinFa &);
    void kiir (Csomopont * elem, std::ostream & os);
    void szabadit (Csomopont * elem);

protected:
    Csomopont gyoker;
    int maxMelyseg;
    double atlag, szoras;

    void rmelyseg (Csomopont * elem);
    void ratlag (Csomopont * elem);
    void rszoras (Csomopont * elem);

};