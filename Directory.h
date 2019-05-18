//
// Created by d on 12/26/18.
//

#ifndef APPROJECT3_DIRECTORY_H
#define APPROJECT3_DIRECTORY_H


#include <vector>

#include "Node.h"
#include "File.h"

using namespace std;
class File;
class Directory: public Node {
public:
//    void deletefilesofdir(HardDisk *hardDisk);
    Directory( const string &name,Node *parent) ;

    File * newfile(const string &filename,Node * fileptr);
    File* findFile(const string &fileName);
    Directory* FindDirectoryinDir(const string &dirname);
    Node *getParent() const override;
    const string &getName() const override;
    Directory *getParentdir() const;
    string getFileName();
    string getDirName();
//    viod* deleteDir(Directory *dirptr, HardDisk *hardDisk);
    void makeNewDir(string nameDir,Directory* _parent);

    void setParentdir(Directory *parentdir);

    void newCopyTofile(string basic_string, Directory *pDirectory);

    vector<Directory> vectorDir;
    vector<File>vectorFile;
protected:
    Directory* parentdir;
};


#endif //APPROJECT3_DIRECTORY_H
