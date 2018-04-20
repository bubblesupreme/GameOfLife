#ifndef BOOTHGENE_H
#define BOOTHGENE_H

#include "Booth.h"

class BoothGene: public Booth
{
public:
	BoothGene(int x, int y, bool alive, bool* gene);
	BoothGene();
	~BoothGene();
	bool* getGene() const;
	void operator=(const BoothGene& rhs);
private:
	bool* gene;
};

#endif