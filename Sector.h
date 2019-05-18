//
// Created by d on 12/26/18.
//

#ifndef APPROJECT3_SECTOR_H
#define APPROJECT3_SECTOR_H

#include <string>
#include "File.h"

using  namespace std;
enum {SECTORSIZE=64};
class File;
class Sector {
public:

    File* fileptr;
    void fullSector(string _str,File* _fileptr);
    Sector operator=(const Sector& obj);
    void deleteSector();
    string readSector();
    Sector();
protected:
    char sectorChar[SECTORSIZE];

    //bool emtySector;


};


#endif //APPROJECT3_SECTOR_H
