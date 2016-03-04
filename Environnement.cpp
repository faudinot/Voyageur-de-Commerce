#include <iostream>
#include <cstdlib>
#include <vector>

#include "Environnement.h"

Environnement::Environnement(){}

void Environnement::Init(){
    villes.push_back("Paris");
    villes.push_back("Lyon");
    villes.push_back("Marseille");
    villes.push_back("Nantes");
    villes.push_back("Bordeaux");
    villes.push_back("Toulouse");
    villes.push_back("Lille");
    villes.push_back("Rouen");
    villes.push_back("Rennes");
    villes.push_back("Brest");
    villes.push_back("Tours");
    villes.push_back("Montpellier");
    villes.push_back("Toulon");
    villes.push_back("Nice");
    villes.push_back("Clermont-Ferrand");
    villes.push_back("Dijon");
    villes.push_back("Strasbourg");
    villes.push_back("Reims");
}

Environnement::~Environnement(){};

std::string Environnement::getVille(int villeIndex){
    return villes.at(villeIndex);
}

int Environnement::getDistance(int ville1, int ville2){
    return distances[ville1][ville2];
}

std::vector<int> Environnement::getVillesIndex(){
    int nbVilles = villes.size();
    std::vector<int> villesIndex;
    for(int i=0; i < nbVilles; i++){
        villesIndex.push_back(i);
    }
    return villesIndex;
}