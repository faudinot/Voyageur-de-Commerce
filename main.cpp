/* 
 * File:   main.cpp
 * Author: faudi_000
 *
 * Created on 20 février 2016, 14:29
 */

#include <cstdlib>
#include <time.h>
#include <iostream>

#include "Parametres.h"
#include "Environnement.h"
#include "Evolution.h"

using namespace std;

void testRandom();
void testVille();
void testIndex();

/*
 *      RandomFloat max=100 ? 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    /*
    testVille();
    testRandom();
    testIndex();
    */
    std::cout << "Algorithme Genetique : Probleme du Voyageur de Commerce \n" << std::endl;

    Evolution system;
    
    system.Run();
    
    
    return 0;
}

void testVille(){
    Environnement a;
    a.Init();
    
    cout << "Test Ville :" << endl;
    
    for(int i=0; i < NBVILLE ; i++){
        string t = a.getVille(i);
        cout << t << " \t";
    }
    cout << endl;
    
    for(int y=0; y < NBVILLE; y++){
        for(int z=0; z < NBVILLE; z++){
                int  b = a.getDistance(y, z);
                cout << b << "\t";
        }
        cout << endl;
    }
}

void testIndex(){
    Environnement a;
    a.Init();
    cout << "Test Index :" << endl;
    std::vector<int> test = a.getVillesIndex();
    cout << test.at(2) << endl;
}

void testRandom(){
    Parametre b;
    
    cout << "Test RandomInt et RandomFloat :" << endl;
    
    for(int f=0; f < 10; f++){
        int val = b.randomInt(10);
        cout << val << "\t";
    }
    
    cout << endl;
    
    for(int l=0; l < 10; l++) {
        float val = b.randomFloat(100);
        cout << val << "\t";
    }
    cout << endl;
}
