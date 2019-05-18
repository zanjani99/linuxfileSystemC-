#include <iostream>
#include <MyOS.h>
#include <fstream>
/*
#define KB *1024
#define MB *1024*1024
#define GB *1024*1024*1024*/
using namespace std;
int main() {
    /*ofstream myFile;
    myFile.open("ya.txt");
        myFile<<"123132";
        myFile.close();*/
    int hardsize=0;
    cout << "D E L L:/ $ enter size of hard";
    cin>>hardsize;
    MyOS os(hardsize);
    string command;
//    cout<<"D E L L:/ $ ";
//    cin>>command;
    while (command!="EXIT") {
//        cout<<"in while";
        cout<<"D E L L:/ $ ";
        cin >> command;
        os.get_command(command);
        cout<<endl;
    }

    return 0;
}