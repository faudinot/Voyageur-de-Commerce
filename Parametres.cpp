#include "Parametres.h"
#include <stdlib.h>
#include <time.h>

int Parametre::nbIndividus = 500;
int Parametre::nbGenes = 10;
    
    // Critere d'arret
int Parametre::nbMaxGenerations = 500;
double Parametre::minFitness = 2579;
    
    // Taux des opérateurs
double Parametre::tauxMutation = 0.05;
double Parametre::tauxAjoutGene = 0.0;
double Parametre::tauxSupprGene = 0.0;
double Parametre::tauxCrossover = 0.10;

// Generateur aleatoire
int Parametre::randomInt(int max=10) {
    int valeur = rand() % max;
    return valeur;
}

float Parametre::randomFloat(int max=100) {
    float valeur = rand() % max;
    valeur /= 100;
    return valeur;
}
