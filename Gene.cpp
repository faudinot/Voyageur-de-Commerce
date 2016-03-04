#include "Gene.h"
#include "Environnement.h"
#include <iostream>

Gene::Gene(int _villeIndex){
    villeIndex = _villeIndex;
}

Gene::Gene(){}

Gene::~Gene(){}

Gene::Gene(const Gene &g) {
    villeIndex = g.villeIndex;
}

int Gene::getVilleIndex(){
    return villeIndex;
}

int Gene::getDistance(Gene g) {
    Environnement tmp;
    tmp.Init();
    int dist = tmp.getDistance(villeIndex, g.villeIndex);
    return dist;
}

void Gene::Muter() {
    std::cout << "Error" << std::endl;
}

std::string Gene::Afficher() {
    Environnement tmp;
    tmp.Init();
    return tmp.getVille(villeIndex);
}