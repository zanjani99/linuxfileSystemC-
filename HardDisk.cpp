//
// Created by d on 12/26/18.
//
#include <vector>
#include <iostream>
#include "HardDisk.h"

HardDisk::HardDisk(){
//    sectorList=new Sector[HardSize/SECTORSIZE];
}

void HardDisk::setHardSize(int _HardSize) {
    HardDisk::HardSize = _HardSize;
    sectorList=new Sector[HardSize/SECTORSIZE];
}

void HardDisk::saveFile(string _strFile,File *_fileptr) const {
    //get string of txt file from os and send it to emty vector
    string strTemp;
    int j=0;
    int k =0;
    int i=0;
    Sector sector;
    while (!_strFile.empty()) {

        strTemp = _strFile.substr(0, SECTORSIZE);
        _strFile = _strFile.substr(SECTORSIZE + 1);
//        vecStr.push_back("ttt");
////       vecStriii.insert(vecStriii.end(),strTemp);
//        cout<<"savefile/while1";

        while (k <HardSize) {
            if(sectorList[k].fileptr== nullptr){
                sectorList[k].fullSector(strTemp,_fileptr);
                break;
            }
            k++;
            cout<<" savefile/while2";
        }
        if(k>HardSize){
            throw " memory is full";
            break;
        }
        cout<<" /hardDisk/savefile/for";
    }
   /* if(k>HardSize){
        throw " memory is full";
            break;
    }


    for (int u = 0; u <vecStr.size() ; ++u) {

        while (k <HardSize) {
            if(sectorList[k].fileptr== nullptr){
               sectorList[k].fullSector(vecStr[u],_fileptr);
                break;
            }
            k++;
            cout<<" savefile/while2";
        }*/


    }


//find file withname in the string

string HardDisk::readFile(File *_fileptr) {
    //read sector related to file and return the string of them
    string filestr;
    for (int i = 0; i <HardSize ; ++i) {
        if(sectorList[i].fileptr==_fileptr){
            filestr+=sectorList[i].readSector();
        }
    }
    return filestr;
}

int HardDisk::GetFileSize(File *_fileptr) {
    int size=0;
    for (int i = 0; i <HardSize ; ++i) {
        if(sectorList[i].fileptr==_fileptr){
            size+=SECTORSIZE;
        }
    }
    return size;
}

void HardDisk::DeleteFile(File *_fileptr) const {

    for (int i = 0; i <HardSize ; ++i) {
        if(sectorList[i].fileptr==_fileptr){
            sectorList[i].fileptr= nullptr;
        }
    }

}

void HardDisk::copyFile(File *first, File *second) {
    DeleteFile(second);
    for (int i = 0; i <HardSize ; ++i) {
        if(sectorList[i].fileptr==first){
            for (int j = 0; j <HardSize ; ++j) {
                if(sectorList[j].fileptr== nullptr){
                    sectorList[j]=sectorList[i];
                }
            }
        }


    }
}

/*
void HardDisk::defrag() {
//search
// you shold have strong copy constructor for swap in vector
//and change the type of sector list to vector
//http://www.cplusplus.com/reference/vector/vector/swap/
//see there
// or write good swap for array
//  or use std::array and use array::swap
//see http://www.cplusplus.com/reference/array/array/swap/
//you must shift all element
// between two same to right and move the same along:))
}
*/

