#include "quadratic.h"
#include "Central.h"
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "graph.h"
#include <map>

vector <central*> vectorCentral;
ofstream outdata; 
map<int, int> centrales;
map<int, int>::iterator itr;

void start();
bool menu();
void LoadCentral(ifstream &file);
int maxMedia(const char* file);
void addAdress();
unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}
Quadratic <string, int> quad_hash(10, "empty" , myHash);

int main() {
  central prueba("prueba",12);
  ifstream file2("Info.txt");
  LoadCentral(file2);
  for(int i=0;i < 6;i++){
    quad_hash.put(vectorCentral[i]->getName(), 11+i);
    centrales.insert(pair<int, int>(i, vectorCentral[i]->getCP())); }
  LoadCentral(file2);
  while (true){
    bool stop;
    stop=menu();
    if (stop == true){
      break;
    }
  }
}

void LoadCentral(ifstream &file){
  for(int i=0;i<=maxMedia("Info.txt");i++){
    int ID;
    string name;
    file >> name;
    file >> ID;
    vectorCentral.push_back(new central(name, ID)); 
  }
}

bool menu(){
  Graph g;
  g.loadGraphList("Centrals.txt", 7, 7);
  g.loadGraphMat("Centrals.txt", 7, 7);

  cout << endl << "------------MENU------------------"<<endl<<endl;
  cout<<"1. Lista de centrales de autobus [nombre]"<<endl;
  cout<<"2. Lista de centrales de autobus [código postal]"<<endl;
  cout<<"3. Calcular ruta"<<endl;
  cout<<"4. Ver matriz de adjacencia"<<endl;
  cout<<"5. Ver lista de IDs de las centrales"<<endl;
  cout<<"6. Salir"<<endl;
  
  int op;
  cin >> op;
  switch (op){
    case 1:
      for(int i=0;i<6;i++){
        cout<<i<<"- "<<vectorCentral[i]->getName()<<endl;
      }
      break;
    case 2:
      for (itr = centrales.begin(); itr != centrales.end(); ++itr) {
          cout << '\t' << itr->first<< '\t' << itr->second << '\n';
      }
      break;
    case 3:
      int inicio, pfinal;
      cout<<"¿En qué nodo te encuentras?"<<endl;
      cin>>inicio;
      cout<<"¿A dónde quieres ir?"<<endl;
      cin>>pfinal;
      cout<<endl<<g.BFS(inicio,pfinal)<<endl;
      
      outdata.open("rutas.txt"); 
      if( !outdata ) { 
          cerr << "Error: file could not be opened" << endl;
          exit(1);
      }
      outdata << g.BFS(inicio,pfinal) << endl;
      outdata.close();
      break;
    case 4:
      cout<<g.printAdjMat();
      break;
    case 5:
      cout<<quad_hash.toString().c_str();
      break;
    case 6:
      return true;
      break; 
  }
  return false;
}


int maxMedia(const char* file){
  ifstream inFile(file);
  int c = std::count(istreambuf_iterator<char>(inFile),istreambuf_iterator<char>(), '\n');
  return c;
}


/* 
**************CASO DE PRUEBA 1:*************** 
Output:
    ------------MENU------------------

    1. Lista de centrales de autobus [nombre]
    2. Lista de centrales de autobus [código postal]
    3. Calcular ruta
    4. Ver matriz de adjacencia
    5. Ver lista de IDs de las centrales
    6. Salir
Input: 1
Output:
    0- Celaya
    1- CDMX
    2- Queretaro
    3- Guanajuato
    4- Puebla
    5- Hidalgo

**************CASO DE PRUEBA 2:*************** 
Output:
    ------------MENU------------------

    1. Lista de centrales de autobus [nombre]
    2. Lista de centrales de autobus [código postal]
    3. Calcular ruta
    4. Ver matriz de adjacencia
    5. Ver lista de IDs de las centrales
    6. Salir
Input: 2
Output:
    0   38000
    1   810
    2   76000
    3   36010
    4   72000
    5   78557

**************CASO DE PRUEBA 3:*************** 
Output:
    ------------MENU------------------

    1. Lista de centrales de autobus [nombre]
    2. Lista de centrales de autobus [código postal]
    3. Calcular ruta
    4. Ver matriz de adjacencia
    5. Ver lista de IDs de las centrales
    6. Salir
Input: 3
Output: ¿En qué nodo te encuentras?
Input: 1
Output: ¿A dónde quieres ir?
Input: 3
Output:
    recorrió: 1 0 2 3 camino a tomar: 1 3

**************CASO DE PRUEBA 4:*************** 
Output:
    ------------MENU------------------

    1. Lista de centrales de autobus [nombre]
    2. Lista de centrales de autobus [código postal]
    3. Calcular ruta
    4. Ver matriz de adjacencia
    5. Ver lista de IDs de las centrales
    6. Salir
Input: 4
Output:
    Matriz de Adjacencia

        0 1 2 3 4 5 6 
        — — — — — — — 
    0 | 0 1 0 0 1 0 0 
    1 | 1 0 1 1 0 0 0 
    2 | 0 1 0 0 0 0 0 
    3 | 0 1 0 0 0 0 1 
    4 | 1 0 0 0 0 1 0 
    5 | 0 0 0 0 1 0 0 
    6 | 0 0 0 1 0 0 0 
**************CASO DE PRUEBA 5:*************** 
Output:
    ------------MENU------------------

    1. Lista de centrales de autobus [nombre]
    2. Lista de centrales de autobus [código postal]
    3. Calcular ruta
    4. Ver matriz de adjacencia
    5. Ver lista de IDs de las centrales
    6. Salir
Input: 5
Output:
    (0 CDMX : 12) 
    (1 Celaya : 11) 
    (2 Queretaro : 13) 
    (5 Puebla : 15) 
    (6 Hidalgo : 16) 
    (9 Guanajuato : 14) 

*/