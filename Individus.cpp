#include "Individus.h"
#include "Environnement.h"
#include "Parametres.h"
#include "Gene.h"

#include <algorithm>
#include <iostream>
#include <typeinfo>

Individus::Individus() {
  //  std::cout << "Individus::Individus()" << std::endl;
    Environnement tmp1;
    tmp1.Init();
    Parametre tmp2;
    
    // Recup liste des villes
    std::vector<int> indexDispo = tmp1.getVillesIndex();
    /*
    for(int y=0; y<indexDispo.size(); y++){
        std::cout << indexDispo.at(y) << "\t";
    }
    std::cout << "\n";
   */
    while(!indexDispo.empty()){
        int index = tmp2.randomInt(indexDispo.size());
        Gene tmp3(indexDispo.at(index));
        genome.push_back(tmp3);
        indexDispo.erase(indexDispo.begin() + index);
        /*
        std::cout << "Index : " << index << std::endl;
        std::cout << "Size : " << indexDispo.size() << std::endl;
        std::cout << "Genome size : " << genome.size() << std::endl;
        
        for(int y=0; y<indexDispo.size(); y++){
            std::cout << indexDispo.at(y) << "\t";
        }
         
        std::cout << "\n";
        std::cout << "\n"; 
         */  
    }
   // std::cout << "Fin Individuds::Individus()" << std::endl << std::endl;
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
        genome.push_back((Gene)parent1.genome.at(i));	// Voir Gene
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

void Individus::Muter(){
    Parametre tmp1;

    if(tmp1.randomFloat(100) < tmp1.tauxMutation){ 
       // std::cout << "Mutation" << std::endl;
        // Permutation
        int index1 = tmp1.randomInt(genome.size());
        int index2 = tmp1.randomInt(genome.size());
        
      //  Gene g1 = (Gene)genome.at(index1);
       // Gene g2 = (Gene)genome.at(index2);
        
     //   std::cout << "g1 : " << genome.at(index1).Afficher() << ", g2 : " << genome.at(index2).Afficher() << std::endl;
        
       /* tmp = (Gene)genome.at(index1);
        (Gene)genome.at(index1) = (Gene)genome.at(index2);
        (Gene)genome.at(index2) = tmp;*/
        
        std::iter_swap(genome.begin()+index1, genome.begin()+index2);
        
       // std::cout << "g1 : " << genome.at(index1).Afficher() << ", g2 : " << genome.at(index2).Afficher() << std::endl;
    }
}

double Individus::getFitness() {
    return fitness;
}

void Individus::setFitness(double val) {
    fitness = val;
}

double Individus::Evaluer(){
  //  std::cout << "Individus::Evaluer()" << std::endl;
    Gene ancienGene;
    int kmTotal = 0;
  //  Gene ancienGene = NULL;
    for(int i=0; i < genome.size()-1; i++){
        kmTotal += ((Gene)genome.at(i)).getDistance(genome.at(i+1));
        ancienGene = (Gene)genome.at(i+1);
    }
    // Distance pour revenir au depart
    kmTotal += ancienGene.getDistance(genome.at(0));

    //   std::cout << "km : " << kmTotal << std::endl;
       
    fitness = kmTotal;
    
    //   std::cout << "Fin Individus::Evaluer" << std::endl;

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