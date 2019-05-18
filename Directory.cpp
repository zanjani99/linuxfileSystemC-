//
// Created by d on 12/26/18.
//

#include <iostream>
#include "Directory.h"
#include "File.h"
File *Directory::newfile(const string & filename,Node *fileptr) {
    File file(filename,fileptr);
    vectorFile.push_back(file);
    cout<<"new file create";
    return &file;
}

Directory::Directory( const string &name,Node *parent)
: Node( name,parent) {}
File *Directory::findFile(const string & fileName) {
//    File* fileptr;
    for (auto &i : vectorFile) {
        if(i.getName()==fileName){
            return &i;
        }
    }
    return nullptr;
}

Directory *Directory::FindDirectoryinDir(const string &dirname){
    for (auto &i : vectorDir) {
        if(i.getName()==dirname){
            return &i;
        }
    }
    return nullptr;
}

Node *Directory::getParent() const {

    return Node::getParent();
}

const string &Directory::getName() const {
    return Node::getName();
}

Directory *Directory::getParentdir() const {
//    parentdir=parent;
    return dynamic_cast<Directory *>(parent);
}

void Directory::setParentdir(Directory *_parentdir) {
    Directory::parentdir = _parentdir;
    parent=_parentdir;
}

string Directory::getFileName() {
    string listFileName;
    for (auto &i : vectorFile) {
        listFileName+= i.getName();
        listFileName+="        ";
    }




    return listFileName;
}

string Directory::getDirName() {
    string listDirName;
    for (auto &i : vectorDir) {
        listDirName+= i.getName();
        listDirName+='\t';
    }




    return listDirName;
}

/*void Directory::deletefilesofdir(HardDisk *hardDisk) {
    for (auto &i : vectorFile) {
        hardDisk->DeleteFile(&i);
    }

}

void *Directory::deleteDir(Directory *dirptr, HardDisk *hardDisk) {
    cout<<"errre";
    Directory*temtptr=dirptr;
    while (!dirptr->vectorDir.empty()) {
        while (!temtptr->vectorDir.empty()) {
            temtptr = &temtptr->vectorDir.back();
        }
        temtptr->deletefilesofdir(hardDisk);
        temtptr = temtptr->getParentdir();
        temtptr->vectorDir.pop_back();
        temtptr= &temtptr->vectorDir.back();
    }
    return nullptr;
}*/

void Directory::makeNewDir(string nameDir,Directory* _parent) {

    vectorDir.emplace_back(nameDir, _parent);
}

void Directory::newCopyTofile(string basic_string, Directory *pDirectory) {


}

