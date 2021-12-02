#ifndef CENTRAL_H
#define CENTRAL_H

#include <iostream>
using namespace std;

class central{
  protected:
    string name;
    int CP;
  public:
    central();
    central(string _name,int _CP);
    string getName();
    void setName(string name);
    int getCP();
    void setCP(int CP);
};

#endif

