//
// Created by d on 12/26/18.
//

#ifndef APPROJECT3_HARD_H
#define APPROJECT3_HARD_H

//#include <debug/vector>
#include <vector>
#include "Sector.h"
#include <string>
#define KB *1024
#define MB *1024*1024
#define GB *1024*1024*1024
using namespace std;

#include <array>
class HardDisk {
protected:
    int  HardSize;
    Sector* sectorList;
//    vector<string> vecStr;
public:
    HardDisk();
   /* void defrag();*/
    void saveFile(string _strFile,File *_fileptr) const;
    void copyFile(File *first,File*second);
    string readFile(File* _fileptr);
    int GetFileSize(File* _fileptr);
    void DeleteFile(File* _fileptr) const;
    void setHardSize(int _HardSize);
};


#endif //APPROJECT3_HARD_H
