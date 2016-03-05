/* 
 * File:   Glouton.h
 * Author: faudi_000
 *
 * Created on 3 mars 2016, 12:10
 */

#ifndef GLOUTON_H
#define	GLOUTON_H

#include <vector>

#include "Gene.h"

class Glouton{
private:
    double fitness;
    std::vector<Gene> genome;
    
public:
    Glouton();
    ~Glouton();
    double getFiness();
    void setFitness(double);
    void Run();
    void Afficher();
};



#endif	/* GLOUTON_H */

