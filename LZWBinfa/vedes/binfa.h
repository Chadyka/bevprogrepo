#include <iostream>
#include "csomopont.h"
class Csomopont;
extern Csomopont *fa;
extern int melyseg;
extern Csomopont gyoker;

class LZWBinFa
{
public:
    LZWBinFa();
    ~LZWBinFa();

    void insert(char b);

    void kiir(void);

    int getMelyseg(void);
    double getAtlag(void);
    double getSzoras(void);

    friend std::ostream &operator<<(std::ostream &os, LZWBinFa &bf)
    {
        bf.kiir(os);
        return os;
    }
    void kiir(std::ostream &os);

    

private:
    int atlagosszeg, atlagdb;
    double szorasosszeg;
    LZWBinFa(const LZWBinFa &);
    LZWBinFa &operator=(const LZWBinFa &);

    void kiir(Csomopont *elem, std::ostream &os);
    void szabadit(Csomopont *elem);

protected:
    int maxMelyseg;
    double atlag, szoras;

    void rmelyseg(Csomopont *elem);
    void ratlag(Csomopont *elem);
    void rszoras(Csomopont *elem);
};

void usage(void);