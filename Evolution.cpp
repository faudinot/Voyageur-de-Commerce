#include <iostream>

#include "Evolution.h"
#include "Parametres.h"
#include "Environnement.h"
#include "Individus.h"

// Constructeur

Evolution::Evolution() { 
    nbGenerations = 0;
    Environnement env;
    env.Init();

    Parametre param;
    for(int i=0; i < param.nbIndividus; i++) {
        Individus ind;
         
        double val = ind.Evaluer();
        ind.setFitness(val);
         
	population.push_back(ind);
    }
}

// Methode

void Evolution::Survie(std::vector<Individus> nouvelleGeneration) {
    population = nouvelleGeneration;
}

Individus Evolution::Selection() {
    Parametre param;
    int index1 = param.randomInt(param.nbIndividus);
    int index2 = param.randomInt(param.nbIndividus);
	
    if(population.at(index1).getFitness() <= population.at(index2).getFitness()) {
	return population.at(index1);
    }
    else {
        return population.at(index2);
    }
}

void Evolution::Run() {
    Parametre param;
    meilleureFitness = param.minFitness + 1;

    while(nbGenerations < param.nbMaxGenerations && meilleureFitness > param.minFitness) {
        
        Individus meilleurIndividu = population.at(0);
        std::cout << "Fitness a battre : " << meilleurIndividu.getFitness() << "km" << std::endl;
        
        // Evaluation de tous les individus
        for(int i=0; i < population.size(); i++){
            population.at(i).Evaluer();

            if(population.at(i).getFitness() < meilleurIndividu.getFitness()) {
                meilleurIndividu = population.at(i);
            }
        }
       
        // Meilleur Individu
        std::cout << "Generation : " << nbGenerations << " -> " << meilleurIndividu.getFitness() << " km" << std::endl;
        meilleurIndividu.Afficher();
        std::cout << "\n" << std::endl;
        
        meilleureFitness = meilleurIndividu.getFitness();

        // Selection et reproduction avec elitisme
        std::vector<Individus> nouvellePopulation;
        nouvellePopulation.push_back(meilleurIndividu);
        
        for(int i=0; i < param.nbIndividus - 1; i++) {
            // Crossover ou pas ?
            if(param.randomFloat(100) < param.tauxCrossover) {
                // Avec crossover, 2 parents
                Individus parent1 = Selection();
                Individus parent2 = Selection();
            
                // Reproduction
                Individus ind (parent1, parent2);
                nouvellePopulation.push_back(ind);
            }
            else {
                // Sans crossover, 1 parent
                Individus parent = Selection();
            
                // Reproduction
                Individus ind (parent);
                nouvellePopulation.push_back(ind);
            }
        }
        // Survie
        Survie(nouvellePopulation);
        
        nbGenerations++;
        std::cout << "\n";
    }
}