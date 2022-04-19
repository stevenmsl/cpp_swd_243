#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cinttypes>
using namespace std;

namespace sol243
{
    struct Node
    {
        int val;
        Node *left;
        Node *right;
        Node(int initVal) : val(initVal), left(nullptr), right(nullptr){};
    };
}
#endif