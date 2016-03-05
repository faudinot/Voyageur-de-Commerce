#include <algorithm>
#include <iostream>
#include <typeinfo>

#include "Individus.h"
#include "Environnement.h"
#include "Parametres.h"
#include "Gene.h"

// Constructeurs & Destructeur

Individus::Individus() {
    Environnement tmp1;
    tmp1.Init();
    Parametre tmp2;
    
    // Recup liste des villes
    std::vector<int> indexDispo = tmp1.getVillesIndex();

    while(!indexDispo.empty()){
        int index = tmp2.randomInt(indexDispo.size());
        Gene tmp3(indexDispo.at(index));
        genome.push_back(tmp3);
        indexDispo.erase(indexDispo.begin() + index);
    }
}

Individus::Individus(const Individus &ind){
	fitness = ind.fitness;
	genome = ind.genome;	
        Muter();
}

Individus::Individus(Individus parent1, Individus parent2){
    Parametre tmp;
    // Crossover
    int coupure = tmp.randomInt(parent1.genome.size());
    for(int i=0; i < coupure; i++){
        genome.push_back((Gene)parent1.genome.at(i));
    }
   
    // Complete le genome
    for(int y=0; y < parent2.genome.size(); y++){
        int cmpt = 0;
        for(int z=0; z < genome.size(); z++){
            if(parent2.genome.at(y).getVilleIndex() == genome.at(z).getVilleIndex()){
                cmpt++;
            }            
        }
        if(cmpt == 0){
            genome.push_back((Gene)parent2.genome.at(y));
        }
        else{
            cmpt = 0;
        }
    }
    Muter();
}

Individus::~Individus(){}


// Getter & Setter

double Individus::getFitness() {
    return fitness;
}

void Individus::setFitness(double val) {
    fitness = val;
}


// Methodes

void Individus::Muter(){
    Parametre tmp1;

    if(tmp1.randomFloat(100) < tmp1.tauxMutation){ 
        int index1 = tmp1.randomInt(genome.size());
        int index2 = tmp1.randomInt(genome.size());
        // Permutation
        std::iter_swap(genome.begin()+index1, genome.begin()+index2);
    }
}

double Individus::Evaluer(){
    Gene ancienGene;
    int kmTotal = 0;

    for(int i=0; i < genome.size()-1; i++){
        kmTotal += ((Gene)genome.at(i)).getDistance(genome.at(i+1));
        ancienGene = (Gene)genome.at(i+1);
    }
    // Distance pour revenir au depart
    kmTotal += ancienGene.getDistance(genome.at(0));
       
    fitness = kmTotal;

    return fitness;
}

void Individus::Afficher(){
    std::vector<std::string> villes;
    for(int i=0; i < genome.size(); i++){
        villes.push_back(genome.at(i).Afficher());
    }
    for(int i=0; i < villes.size(); i++){
        std::cout << villes.at(i) << "\t";
    }
    std::cout << "\n";
}