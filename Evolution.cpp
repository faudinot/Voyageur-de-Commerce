#include "Evolution.h"
#include "Parametres.h"
#include "Environnement.h"
#include "Individus.h"

#include <iostream>
#include <vector>

Evolution::Evolution() { 
   // std::cout << "Evolution::Evolution()" << std::endl;
    nbGenerations = 0;
    Environnement env;
    env.Init();

    Parametre param;
    for(int i=0; i < param.nbIndividus; i++) {
        Individus ind;
         
        //std::cout << "fitness : " << ind.getFitness() << std::endl;
        double val = ind.Evaluer();
        ind.setFitness(val);
         
	population.push_back(ind);
    }
    /*
    for(int i=0; i < population.size(); i++){
        population.at(i).Afficher();
    }
    */
   // std::cout << "Fin Evolution::Evolution()" << std::endl << std::endl;;
}

void Evolution::Survie(std::vector<Individus> nouvelleGeneration) {
    /*
    for(int i=0; i < population.size(); i++){
        delete population.at(i);
    }
     */
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
  //  std::cout << "Evolution::Run()" << std::endl;
    Parametre param;
    meilleureFitness = param.minFitness + 1;

  //  std::cout << "nbGenerations : " << nbGenerations << ", nbMax : " << param.nbMaxGenerations << std::endl;
 //   std::cout << "meilleureFitness : " << meilleureFitness << ", paramFitness : " << param.minFitness << std::endl;

    while(nbGenerations < param.nbMaxGenerations && meilleureFitness > param.minFitness) {
        
        Individus meilleurIndividu = population.at(0);
        std::cout << "Fitness a battre : " << meilleurIndividu.getFitness() << "km" << std::endl;
        
        // Evaluation de tous les individus
        for(int i=0; i < population.size(); i++){
            population.at(i).Evaluer(); // Redondance avec le constructeur ??? Voir avec les nouvelles générations

            if(population.at(i).getFitness() < meilleurIndividu.getFitness()) {
                meilleurIndividu = population.at(i);
            }
        }
       
        // Meilleur Individu
        std::cout << "Generation : " << nbGenerations << " -> " << meilleurIndividu.getFitness() << " km" << std::endl;
        meilleurIndividu.Afficher();
        std::cout << "\n" << std::endl;
        
        // Stoppé le 25/02/2016 17:54
        // Voir génération successive 
        // Voir constructeur de recopie Individus
        // Voir crossover
        // Probleme const Individus &ind
        
        meilleureFitness = meilleurIndividu.getFitness();

        // Selection et reproduction avec elitisme
        std::vector<Individus> nouvellePopulation;
        nouvellePopulation.push_back(meilleurIndividu);
        
        for(int i=0; i < param.nbIndividus - 1; i++) {
            // Crossover ou pas ?
            if(param.randomFloat(100) < param.tauxCrossover) {
                // std::cout << "AVEC Crossover" << std::endl;
                // Avec crossover, 2 parents
                Individus parent1 = Selection();
                Individus parent2 = Selection();
            
                // Reproduction
                Individus ind (parent1, parent2);
                // std::cout << "New Individu : ";
                // ind.Muter();
                nouvellePopulation.push_back(ind);
            }
            else {
                // std::cout << "SANS crossover" << std::endl;
                // Sans crossover, 1 parent
                Individus parent = Selection();
            
                // Reproduction
                Individus ind (parent);
                //  std::cout << "Old Ind : ";ind.Afficher();
                // ind.Muter();
                //     std::cout << "New Ind : ";ind.Afficher();
                nouvellePopulation.push_back(ind);
                //     std::cout << "\n";
            }
        }
    
        // Survie
        Survie(nouvellePopulation);
    
        // Nouvelle Population
        /*
        for(int y=0; y < nouvellePopulation.size(); y++){
            nouvellePopulation.at(y).Afficher();
        }
        std::cout << "\n" << std::endl;
         */
        
        nbGenerations++;
        std::cout << "\n";
    }
}