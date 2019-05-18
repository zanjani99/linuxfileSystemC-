//
// Created by d on 12/26/18.
//

#ifndef APPROJECT3_OS_H
#define APPROJECT3_OS_H

#include <string>
#include "HardDisk.h"
#include "Directory.h"

using namespace std;

class MyOS {
protected:
    Directory root = Directory("root", nullptr);
    int HardSize=0;
    string commandLine="";
    Directory* current= &root;
    Directory*const rootprt=&root;

public:
    HardDisk hardDisk;
    MyOS(int HardSize);

    bool get_command(string command);

    bool osput(string &command) const;

    Directory *goToAdress(string &command, Directory *tempt) const;

    string getCurrentAdrees() const;

    void deletFileRight( Directory *leaf) const;

    Directory* findleaf(Directory *tempt) const;
};


#endif //APPROJECT3_OS_H
