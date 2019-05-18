//
// Created by d on 12/26/18.
//

#include "Sector.h"

Sector::Sector() {
//    emtysector= true;
}

void Sector::fullSector(string _str,File* _fileptr ) {
//    emtysector= false;
    fileptr=_fileptr;
    for (int i = 0; i <SECTORSIZE ; ++i) {
        if(_str[i] != 0){
            sectorChar[i]=_str[i];
        } else{
            sectorChar[i]=0;
        }
    }
}

void Sector::deleteSector() {
//    emtysector= true;
    fileptr= nullptr;
}

string Sector::readSector() {
    string vectorsrt;
    for (char i : sectorChar) {
        vectorsrt+= i;
    }
    return vectorsrt;

}

Sector Sector::operator=(const Sector &obj) {
    for (int i = 0; i <SECTORSIZE ; ++i) {
        sectorChar[i]=obj.sectorChar[i];
    }
    return Sector();
}
