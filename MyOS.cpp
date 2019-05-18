//
// Created by d on 12/26/18.
//

#include <fstream>
#include <iostream>
#include "MyOS.h"
#include "HardDisk.h"



MyOS::MyOS(int _HardSize) : HardSize(_HardSize) {
    hardDisk.setHardSize(HardSize);
}

bool MyOS::get_command(string command) {
    string commandLine=command.substr(0,command.find(' '));
    command=command.substr(command.find(' ')+1);
    if(commandLine=="put"){
        return osput(command);


    }else if(commandLine=="get") {
        ifstream newfile("newText.txt");
        //call read file method form hard
        string str=hardDisk.readFile(current->findFile(command));
        newfile>> str;
//        return  true;
    }

   /* else if(commandLine=="defrag"){
        hardDisk.defrage();
    }
*/

    else if(commandLine=="pwd"){
        string adress = getCurrentAdrees();
        cout<<'\n'<<adress;

    }

    else if(commandLine=="ls"){
        Directory* tempt=current;
        tempt = goToAdress(command,tempt);
        if(tempt!= nullptr){

            cout<<endl<<tempt->getDirName();
            cout<<endl<<tempt->getFileName();

        } else{
            cout<<"size: "<<hardDisk.GetFileSize(current->findFile(command))<<'\t';
            cout<<"name: "<<current->findFile(command)->getName();

        }


    } else if (commandLine=="cd"){
        current=goToAdress(command,current);
    }
    else if (commandLine=="rm"){
        Directory* tempt=current;
        tempt=goToAdress(command,tempt);
        if(tempt->getParent()== nullptr){
            cout<<"you cant delete root";
        } else{
            while(!tempt->vectorDir.empty()) {
                Directory* leaf=findleaf(current);
                deletFileRight(leaf);
//                leaf->deleteDir();
            }



        }

    }

    else if(commandLine=="mkdir") {
        if(command==""){
            cout<<"enter a name of dir ";
            return false;
        } else{
            Directory* temt=current;
            temt=goToAdress(command,temt);
            current->newfile(command, current);
            cout<<endl<<"Dir made";
        }
    }


    else if(commandLine=="mv"){
        string fistAdress=command.substr(0,command.find(' '));
        string secondAdress=command.substr(command.find(' ')+1);
        Directory* f=current;
        f=goToAdress(fistAdress,f);
        Directory* d=current;
        d=goToAdress(secondAdress,f);
        if(fistAdress.empty() && secondAdress.empty()){
            f->setParentdir(d);
        } else if(secondAdress.empty()){
            f->findFile(fistAdress)->setParent(d);
        } else{
            File* firstFile=f->findFile(fistAdress);
            File* secondFile=f->findFile(secondAdress);
            hardDisk.copyFile(firstFile,secondFile);
            hardDisk.DeleteFile(firstFile);
        }



    }
    else if(commandLine=="cp"){
        string fistAdress=command.substr(0,command.find(' '));
        string secondAdress=command.substr(command.find(' ')+1);
        Directory* f=current;
        f=goToAdress(fistAdress,f);
        Directory* d=current;
        d=goToAdress(secondAdress,f);
        if(secondAdress.empty()){
            File* newF=f->newfile(fistAdress,d);
            File* firstFile=f->findFile(secondAdress);
            hardDisk.copyFile(firstFile,newF);
            //
        } else{
//            f->newCopyTofile(command,f);
                File* firstFile=f->findFile(fistAdress);
                File* secondFile=f->findFile(secondAdress);
                hardDisk.copyFile(firstFile,secondFile);
        }
    } else{
        cout<<"";
        return false;
    }
    return true;
}

Directory* MyOS::findleaf(Directory *tempt) const {
    Directory * t=tempt;
    while (t!= nullptr){
                    t=&t->vectorDir.back();
                }
    return tempt;
}

void MyOS::deletFileRight( Directory *leaf) const {
    for (int i = leaf->vectorFile.size(); i > 0  ; --i) {
                    hardDisk.DeleteFile(&leaf->vectorFile[i]);
                    leaf->vectorFile.pop_back();
                }
}

string MyOS::getCurrentAdrees() const {
    Node *temp = current;
    string adress;
    while (temp!= nullptr) {
            adress = "/" + temp->getName() + adress;
            temp = temp->getParent();
        }
    return adress;
}

Directory *MyOS::goToAdress(string &command, Directory *tempt) const {

    while (command.find('/') != std::string::npos) {
            string commandLine=command.substr(0,command.find('/'));
            command=command.substr(command.find('/')+1);
            if (commandLine == "..") {
//                tempt=tempt->getParent();
                tempt = tempt->getParentdir();
            } else if (commandLine.empty()) {
                tempt =rootprt;
            } else {
                tempt = tempt->FindDirectoryinDir(commandLine);
            }

        }
    return tempt;
}

bool MyOS::osput(string &command) const {
//    string filename=command.substr(command.find(' '));
//    command=command.substr(command.find(' '));
    string filename="ya";

//    if(command.empty()){
        command="ya.txt";
//    }
    string fileAdressUbuntu=command;

    ifstream myFile;
    myFile.open(fileAdressUbuntu);
    string total;
    while (!myFile.eof()){
            string s;
            getline(myFile,s);
            s+='\n';
            total+=s;
        }
    myFile.close();
    cout<<"file write";
//    cout<<"os error1 put";
    File *f=current->newfile(filename,current);

//    f=current->newfile(filename,f);
    hardDisk.saveFile(total,f);
//change this two line
//new file return ponter tofile
cout<<" put done";
    return true;

}
