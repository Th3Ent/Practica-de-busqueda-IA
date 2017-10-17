#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <stack>
#include <cmath>

#define KBLU "\x1B[34m"
#define KWHT "\x1B[37m"
#define KRED "\x1B[31m"
#define RSD "\x1B[0m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KCYN "\x1B[36m"
#define KSRED "\x1B[91m"
#define INF 9999

using namespace std;

typedef struct{
    int x;
    int y;
}punto;

class camino{
    
    public:
    
        char escr;
        
        camino();
        
      virtual int que_soy();
        
      virtual  ostream& print(ostream& os);
};

class obstaculo: public camino{
    
    public:
    
    obstaculo();
    
    ostream& print(ostream& os);
    
    int que_soy();

};

class inicio: public camino{
    
    public:
    
    inicio();
    
    ostream& print(ostream& os);
    
    int que_soy();
};

class fin: public camino{
    
    public:
    
    fin();
    
    ostream& print(ostream& os);
    
    int que_soy();
};


class estela: public camino{
    
    public:
    
    estela();
    
    ostream& print(ostream& os);
    
    int que_soy();
};

class obstaculo_ficticio: public camino{    //Cuando desde ese punto no hay solucion
    
    public:
    
    obstaculo_ficticio();
    
    ostream& print(ostream& os);
    
    int que_soy();
};