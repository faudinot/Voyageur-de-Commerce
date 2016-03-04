/* 
 * File:   Parametres.h
 * Author: faudi_000
 *
 * Created on 20 février 2016, 14:29
 */

#ifndef PARAMETRES_H
#define	PARAMETRES_H

#include <time.h>

class Parametre{
public:
    // Parametre sur la population
    static int nbIndividus;
    static int nbGenes;
    
    // Critere d'arret
    static int nbMaxGenerations;
    static double minFitness;
    
    // Taux des opérateurs
    static double tauxMutation;
    static double tauxAjoutGene;
    static double tauxSupprGene;
    static double tauxCrossover;
    
    int randomInt(int);
    float randomFloat(int);
    
};

#endif	/* PARAMETRES_H */

