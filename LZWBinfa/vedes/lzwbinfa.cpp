//külön csomópont és lzwbinfa header
#include <fstream>
#include "binfa.cpp"


int
main (int argc, char *argv[])
{
   if (argc != 4)
    {
        usage ();
        return -1;
    }

    char *inFile = *++argv;

    if (*((*++argv) + 1) != 'o')
    {
        usage ();
        return -2;
    }
    std::fstream beFile (inFile, std::ios_base::in);

    if (!beFile)
    {
        std::cout << inFile << " nem letezik..." << std::endl;
        usage ();
        return -3;
    }
    std::fstream kiFile (*++argv, std::ios_base::out);

    unsigned char b;		// ide olvassik majd a bejövő fájl bájtjait
    LZWBinFa binFa;		// s nyomjuk majd be az LZW fa objektumunkba

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
                binFa.insert('1');
            else
                binFa.insert('0');
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
