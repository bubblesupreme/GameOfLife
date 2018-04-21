#include "BoothGene.h"

BoothGene::BoothGene(int x, int y, bool alive, bool* gene)
	:Booth(x, y, alive)
{
	this->gene = gene;
}

BoothGene::BoothGene()
{}

BoothGene::~BoothGene()
{

}

bool* BoothGene::getGene() const
{
	return gene;
}

void BoothGene::operator=(const BoothGene& rhs)
{
	shape = rhs.shape;
	alive = rhs.alive;
	gene = rhs.gene;
}