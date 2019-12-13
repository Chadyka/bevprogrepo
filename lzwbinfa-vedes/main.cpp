#include <fstream>
#include "LZWBinFa.h"

int
main (int argc, char *argv[])
{
    LZWBinFa binFa;		// s nyomjuk majd be az LZW fa objektumunkba
    if (argc != 4)
    {
        binFa.usage ();
        return -1;
    }

    char *inFile = *++argv;

    if (*((*++argv) + 1) != 'o')
    {
        binFa.usage ();
        return -2;
    }

    std::fstream beFile (inFile, std::ios_base::in);

    if (!beFile)
    {
        std::cout << inFile << " nem letezik..." << std::endl;
        binFa.usage ();
        return -3;
    }

    std::fstream kiFile (*++argv, std::ios_base::out);

    unsigned char b;		// ide olvassik majd a bejövő fájl bájtjait

    while (beFile.read ((char *) &b, sizeof (unsigned char)))
        if (b == 0x0a)
            break;

    bool kommentben = false;

    while (beFile.read ((char *) &b, sizeof (unsigned char)))
    {

        if (b == 0x3e)
        {			// > karakter
            kommentben = true;
            continue;
        }

        if (b == 0x0a)
        {			// újsor
            kommentben = false;
            continue;
        }

        if (kommentben)
            continue;

        if (b == 0x4e)		// N betű
            continue;

        for (int i = 0; i < 8; ++i)
        {
            if (b & 0x80)
                binFa << '1';
            else
                binFa << '0';
            b <<= 1;
        }

    }

    kiFile << binFa;		// ehhez kell a globális operator<< túlterhelése, lásd fentebb

    kiFile << "depth = " << binFa.getMelyseg () << std::endl;
    kiFile << "mean = " << binFa.getAtlag () << std::endl;
    kiFile << "var = " << binFa.getSzoras () << std::endl;

    kiFile.close ();
    beFile.close ();

    return 0;
}
