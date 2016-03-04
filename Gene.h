/* 
 * File:   Gene.h
 * Author: faudi_000
 *
 * Created on 21 février 2016, 12:29
 */

#ifndef GENE_H
#define	GENE_H

#include <string>

class Gene {
protected :
    int villeIndex;
    
public:
    Gene();
    Gene(int);
    Gene(const Gene &);
    ~Gene();
    int getDistance(Gene);
    int getVilleIndex();
    void Muter();
    std::string  Afficher();
};


#endif	/* GENE_H */

