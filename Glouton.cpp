#include <iostream>

#include "Glouton.h"
#include "Parametres.h"
#include "Environnement.h"
#include "Individus.h"

Glouton::Glouton(){
    Run();
    std::cout << "Genome : "; Afficher();
    std::cout << "Fitness : " << fitness << " km" << std::endl;
}

Glouton::~Glouton(){}

double Glouton::getFiness(){
    return fitness;
}

void Glouton::setFitness(double fit){
    fitness = fit;
}

void Glouton::Run() {
    Environnement env;
    Parametre param;
    std::vector<int> rangColonne;
    std::vector<int> rangLigne;
    int indexLigne = param.randomInt(NBVILLE);
    int rang;
    double distTotale = 0.0;
    
    int minDist = 2000;

    
    // Création des villes
    env.Init();
    
    // Recup liste des villes
    std::vector<int> indexDispo = env.getVillesIndex();
        
    for(int i=0; i<NBVILLE; i++){
        rangColonne.push_back(i);
        rangLigne.push_back(i);
    }
    

    int arret = 0;
    while(arret < NBVILLE){
        std::cout << "Indice ville : " << indexLigne << std::endl;
        
        for(int indexColonne=0; indexColonne < rangColonne.size(); indexColonne++){
            if(rangColonne.at(indexColonne) != -1){
                int dist = env.getDistance(rangLigne.at(indexLigne), rangColonne.at(indexColonne));
                std::cout << "Indice : " << indexColonne << ", min : " << minDist << ", dist : " << dist << std::endl;
        
                if(dist < minDist && dist != 0){
                    minDist = dist;
                    distTotale += dist;
                    rang = indexColonne;
                }
            }
        }
        std::cout << "Rang suivant : " << rang << std::endl;
        rangColonne.at(indexLigne) = -1;
        Gene gene = indexDispo.at(indexLigne);
        genome.push_back(gene);
        std::cout << "Genome : "; Afficher(); 
        indexLigne = rang;
        minDist = 2000;
        arret++;
        std::cout << "\n";
    }
    
    fitness += distTotale;
}

void Glouton::Afficher(){
    std::vector<std::string> villes;
    for(int i=0; i < genome.size(); i++){
        villes.push_back(genome.at(i).Afficher());
    }
    for(int i=0; i < villes.size(); i++){
        std::cout << villes.at(i) << "\t";
    }
    std::cout << "\n";
}