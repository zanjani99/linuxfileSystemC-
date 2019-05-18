//
// Created by d on 12/26/18.
//

#ifndef APPROJECT3_NODE_H
#define APPROJECT3_NODE_H

#include <string>

using namespace std;
class Node {
protected:
    Node* parent;
    string name;
public:
    Node(const string &name,Node *parent );

    Node();

    virtual Node *getParent() const;

    void setParent(Node *_parent);

    virtual const string &getName() const;

    void setName(const string &_name);
};


#endif //APPROJECT3_NODE_H
