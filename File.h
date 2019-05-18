//
// Created by d on 12/26/18.
//

#ifndef APPROJECT3_FILE_H
#define APPROJECT3_FILE_H

#include <string>
//#include "Node.h"
#include "Directory.h"
#include "Sector.h"

using  namespace std;
class File: public Node{
protected:
//    int size;
public:
    File( const string &name,Node *parent);

    File();
//    File(const string &name);
//
////    const string &getName() const;
//
//    string name;
};


#endif //APPROJECT3_FILE_H
