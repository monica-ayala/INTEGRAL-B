#include "Central.h"

central::central(){}
central::central(string _name, int _CP){
  name = _name;
  CP = _CP;
}
string central::getName(){
  return name;
}
void central::setName(string _name){
  name = _name;
}
int central::getCP(){
  return CP;
}
void central::setCP(int _CP){
  CP = _CP;
}