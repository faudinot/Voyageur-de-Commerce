#include <iostream>

#include "Glouton.h"
#include "Parametres.h"
#include "Environnement.h"
#include "Individus.h"

#define DISTMAX 2000

Glouton::Glouton(){
    Run();
    std::cout << "Fitness : " << fitness << " km" << std::endl;
    std::cout << "Genome : "; Afficher();
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
    int premierIndex = indexLigne;
    int rang;
    int distance;
    int cmpt = 0;
    double distTotale = 0.0;
    
    int minDist = DISTMAX;

    // Création des villes
    env.Init();
    
    // Recup liste des villes
    std::vector<int> indexDispo = env.getVillesIndex();
        
    // Initialisation des vecteurs
    for(int i=0; i<NBVILLE; i++){
        rangColonne.push_back(i);
        rangLigne.push_back(i);
    }
    
    while(genome.size() < NBVILLE){
        std::cout << "Indice ville : " << indexLigne << std::endl;

        for(int indexColonne=0; indexColonne < rangColonne.size(); indexColonne++){
            if(rangColonne.at(indexColonne) != -1){
                distance = env.getDistance(rangLigne.at(indexLigne), rangColonne.at(indexColonne));
                std::cout << "Indice : " << indexColonne << ", min : " << minDist << ", dist : " << distance << std::endl;
        
                if(distance < minDist && distance != 0){
                    minDist = distance;
                    rang = indexColonne;
                }              
            }
        }
        if(minDist != DISTMAX){
            distTotale += minDist;
        }

        std::cout << "Distance : " << distTotale << std::endl;
        rangColonne.at(indexLigne) = -1;
        Gene gene = indexDispo.at(indexLigne);
        genome.push_back(gene);
        std::cout << "Genome : "; Afficher(); 
        indexLigne = rang;

        minDist = DISTMAX;
        std::cout << "\n";
    }
    // Retour à la ville de départ
    indexLigne = premierIndex;
    minDist = env.getDistance(indexLigne, rang);
    distTotale += minDist;

    fitness = distTotale;
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