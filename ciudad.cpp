#include "ciudad.hpp"
    
ciudad::ciudad(int x, int y, int x_ini, int x_fin, int y_ini, int y_fin){
    city.resize(x);
    for(int i = 0; i < x; i++){
        city[i].resize(y);
    }
    
    for(int i = 0; i< x; i++)
        for(int j = 0; j <y; j++)
            city[i][j] = new camino();

    fin_x = x_fin;
    fin_y = y_fin;
    inicial.x = x_ini;
    inicial.y = y_ini;
    pos_x = x;
    pos_y = y;
    carro.pos_x = x_ini;
    carro.pos_y = y_ini;
    city[x_ini][y_ini] = new inicio();
    city[x_fin][y_fin] = new fin();
}

ciudad::~ciudad(){}

void ciudad::pintar_ciudad(void){
        
    cout << endl << KGRN " \xe2\x95\x94";  //╔
    for(int k = 0; k < pos_y ; k++)
        if(k != 0 || k != pos_y-1)
            cout << KGRN "\xe2\x95\x90\xe2\x95\x90";  //══
        else
            cout <<" ";
    cout << KGRN "\xe2\x95\x90\xe2\x95\x97" << endl;  //═╗

    for(int i=0; i<pos_x;i++){
          
        cout<< KGRN " \xe2\x95\x91";  //║
        for(int j=0 ; j<pos_y ; j++){
              
            if(carro.pos_x == i && carro.pos_y == j)
                cout <<RSD " "<<carro.car;
            else city[i][j]->print(cout);
        }
        cout<< KGRN " \xe2\x95\x91"<<endl;  //║
    }
    cout << KGRN " \xe2\x95\x9a";  //╚
    for(int k = 0; k < pos_y ; k++)
        cout<< KGRN "\xe2\x95\x90\xe2\x95\x90";  //══
    cout << KGRN "\xe2\x95\x90\xe2\x95\x9d" << endl;  //╝
}
  
void ciudad::manu_alea(int n){
    int x, y;
    for(int i = 0; i < n; i++){
        cout << "Introduce la posicion X del obstaculo: "<< i+1 <<": ";
        cin >> x;
        cout << "Introduce la posicion Y del obstaculo: "<< i+1 <<": ";
        cin >> y;
        city[x][y] = new obstaculo();
    }
}
  
void ciudad::aleatorio(int n){
    
    srand(time(NULL));
    while(n > 0){  
        int x, y;
        x = rand() % pos_x;
        y = rand() % pos_y;
        if(city[x][y]->que_soy() < 2){
        city[x][y] = new obstaculo();
        n--;
        }
    }
}


void ciudad::realeatorio(int n){
    
    srand(time(NULL));
    
    for(int i = 0; i< pos_x; i++)
        for(int j = 0; j <pos_y; j++)
            if(city[i][j]->que_soy() < 3 )
              city[i][j] = new camino();
    
    while(n > 0){  
        int x, y;
        x = rand() % pos_x;
        y = rand() % pos_y;
        if(city[x][y]->que_soy() < 2){
        city[x][y] = new obstaculo();
        n--;
        }
    }
    system("clear");
    pintar_ciudad();
}

void ciudad::realeatorio(int n, int x, int y){
    carro.pos_x = x;
    carro.pos_y = y;
    srand(time(NULL));
    
    for(int i = 0; i< pos_x; i++)
        for(int j = 0; j <pos_y; j++)
            if(city[i][j]->que_soy() < 3 )
              city[i][j] = new camino();
    
    while(n > 0){  
        int x, y;
        x = rand() % pos_x;
        y = rand() % pos_y;
        if(city[x][y]->que_soy() < 2){
        city[x][y] = new obstaculo();
        n--;
        }
    }
    system("clear");
    pintar_ciudad();
}



// bool ciudad::mover_carro(char mov){
//     //cout<<endl<<carro.pos_x<<" <--X  Y--> 0"<<carro.pos_y;
//     switch(mov){
//         case 'a': if( (carro.pos_y-1 >= 0 ) && (city[carro.pos_x][carro.pos_y-1]->que_soy() != 2  )){
//                   carro.pos_y--;
//                   carro.car = '<';
//                   if(city[carro.pos_x][carro.pos_y]->que_soy() != 3 && city[carro.pos_x][carro.pos_y]->que_soy() != 4 )
//                   city[carro.pos_x][carro.pos_y] = new estela('-');
//                 }
//                   break;
//         case 's': if( ((carro.pos_x+1 < pos_x) && city[carro.pos_x+1][carro.pos_y]->que_soy() != 2)){
//                   carro.pos_x++;
//                   carro.car = 'v';
//                   if((city[carro.pos_x][carro.pos_y]->que_soy() != 3 && city[carro.pos_x][carro.pos_y]->que_soy() != 4 ))
//                   city[carro.pos_x][carro.pos_y] = new estela('|');
//                 }
//                   break;
//         case 'd': if( (carro.pos_y+1 < pos_y) && (city[carro.pos_x][carro.pos_y+1]->que_soy() != 2  )){
//                   carro.pos_y++;
//                   carro.car = '>';
//                   if(city[carro.pos_x][carro.pos_y]->que_soy() != 3 && city[carro.pos_x][carro.pos_y]->que_soy() != 4 )
//                   city[carro.pos_x][carro.pos_y] = new estela('-');
//                 }
//                   break;
//         case 'w': if(((carro.pos_x-1 >= 0) && city[carro.pos_x-1][carro.pos_y]->que_soy() != 2)){
//                   carro.pos_x--;
//                   carro.car = '^';
//                   if(city[carro.pos_x][carro.pos_y]->que_soy() != 3 && city[carro.pos_x][carro.pos_y]->que_soy() != 4 )
//                   city[carro.pos_x][carro.pos_y]  = new estela('|');
//                 }
//                   break;
//         default: cout<<"\nMovimiento erroneo";
        
//     }
//     if(city[carro.pos_x][carro.pos_y]->que_soy() == 4){
//         return true;
//     }
//     else
//         return false;
//     //cout<<endl<<carro.pos_x<<" <--X  Y--> 0"<<carro.pos_y;
// }

/*void ciudad::set_obstac(){
    if(city[carro.pos_x][carro.pos_y]->que_soy() < 3){
        city[carro.pos_x][carro.pos_y] = new obstaculo();
        system("clear");
        pintar_ciudad();
    }else{
        system("clear");
        pintar_ciudad();
        cout<<"\nImposible";
    }
}*/

int ciudad::distancia_Manhattan(int x1, int x2, int y1, int y2){
    return fabs(x1 - x2) + fabs(y1 - y2);
}

int ciudad::distancia_Mahalanobis(int x1, int x2, int y1, int y2){
    int A = fabs(x1 - x2);
    int B = fabs(y1 - y2);
    if(A > B) return A;
    else return B;
}

double ciudad::distancia_euclidea(int x1, int x2, int y1, int y2){
    return sqrt((x1 - x2)^2 + (y1 - y2)^2);
}


punto ciudad::elegir_camino(int x, int y){      //dado un punto devuelve el vecino mas optimo
    vector<punto> caminos;
    punto dummy;

    if((x-1 >= 0) && ((city[x-1][y]->que_soy() == 0) || (city[x-1][y]->que_soy() == 4))){
        dummy.x = x-1;
        dummy.y = y;
        caminos.push_back(dummy);
    }
    if((y-1 >= 0) && ((city[x][y-1]->que_soy() == 0) || (city[x][y-1]->que_soy() == 4))){
        dummy.x = x;
        dummy.y = y-1;
        caminos.push_back(dummy);
    }
    if((y+1 < pos_y) && ((city[x][y+1]->que_soy() == 0) || (city[x][y+1]->que_soy() == 4))){
        dummy.x = x;
        dummy.y = y+1;
        caminos.push_back(dummy);
    }
    if((x+1 < pos_x) && ((city[x+1][y]->que_soy() == 0) || (city[x+1][y]->que_soy() == 4))){
        dummy.x = x+1;
        dummy.y = y;
        caminos.push_back(dummy);
    }
    
    double minimo = INF;
    if(caminos.empty()){
        dummy.x = -INF;
        return dummy;
    }
    
    for(int i = 0; i < caminos.size(); i++){
        double aux = distancia_Manhattan(caminos[i].x, fin_x, caminos[i].y, fin_y);
        if(aux < minimo){
            minimo = aux;
            dummy = caminos[i];
        }
    }
    return dummy;
}

bool ciudad::camino_optimo(){
    stack<punto> camino_final;
    camino_final.push(inicial);
    do{
        punto siguiente = elegir_camino(camino_final.top().x, camino_final.top().y); 
        
        if(siguiente.x == -INF){
            city[camino_final.top().x][camino_final.top().y] = new obstaculo_ficticio();
            carro.pos_x = camino_final.top().x;
            carro.pos_y = camino_final.top().y;
            usleep(200000);
            system("clear");
            pintar_ciudad();
            camino_final.pop();
        }
        else{
            city[camino_final.top().x][camino_final.top().y] = new estela();
            carro.pos_x = camino_final.top().x;
            carro.pos_y = camino_final.top().y;
            usleep(200000);
            system("clear");
            pintar_ciudad();
            camino_final.push(siguiente);
        }
        if((!camino_final.empty()) && (camino_final.top().x == fin_x && camino_final.top().y == fin_y)){
            carro.pos_x = camino_final.top().x;
            carro.pos_y = camino_final.top().y;
            usleep(200000);
            
            system("clear");
            pintar_ciudad();
            return true;
        }
            
    }while(!camino_final.empty());
    return false;
}