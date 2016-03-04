/* 
 * File:   Individus.h
 * Author: faudi_000
 *
 * Created on 21 février 2016, 12:34
 */

#ifndef INDIVIDUS_H
#define	INDIVIDUS_H

#include <vector>
#include "Gene.h"

class Individus {
private :
    double fitness;
    std::vector<Gene> genome;
    
public:
    Individus();
    Individus(const Individus &);
    Individus(Individus, Individus);
    ~Individus();
    double getFitness();
    void setFitness(double);

    void Muter();
    double Evaluer();
    void Afficher();
};


#endif	/* INDIVIDUS_H */

