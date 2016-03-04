/* 
 * File:   Evolution.h
 * Author: faudi_000
 *
 * Created on 23 février 2016, 14:08
 */

#ifndef EVOLUTION_H
#define	EVOLUTION_H

#include <vector>
#include "Individus.h"

class Evolution {
private :
    std::vector<Individus> population;
    int nbGenerations;
    double meilleureFitness;
		
public :
    Evolution();
    Individus Selection();
    void Survie(std::vector<Individus>);
    void Run();
};


#endif	/* EVOLUTION_H */

