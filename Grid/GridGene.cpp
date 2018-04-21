#include "GridGene.h"
#include <set>

GridGene::~GridGene()
{
}


void GridGene::update()
{
	bool boothesToDie[40][30];
	bool boothesToGetLive[40][30];

	for (int x = 0; x < 40; x++) {
		for (int y = 0; y < 30; y++) {
			boothesToDie[x][y] = false;
			boothesToGetLive[x][y] = false;
		}
	}
	int boothNeighbours[40][30];

	for (int x = 0; x < 40; x++) {
		for (int y = 0; y < 30; y++) {

			int neighbours = 0;

			if ((x == 0) && (y == 0)) {
				neighbours = (boothes[x + 1][y].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x + 1][y + 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x][y + 1].isAlive()) ? neighbours + 1 : neighbours;
			}

			else if ((x == width - 1) && (y == 0)) {
				neighbours = (boothes[x - 1][y].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x - 1][y + 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x][y + 1].isAlive()) ? neighbours + 1 : neighbours;
			}

			else if ((x == 0) && (y == height - 1)) {
				neighbours = (boothes[x + 1][y].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x + 1][y - 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x][y - 1].isAlive()) ? neighbours + 1 : neighbours;
			}

			else if ((x == width - 1) && (y == height - 1)) {
				neighbours = (boothes[x - 1][y].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x - 1][y - 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x][y - 1].isAlive()) ? neighbours + 1 : neighbours;
			}

			else if (x == 0) {
				neighbours = (boothes[x + 1][y - 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x + 1][y].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x + 1][y + 1].isAlive()) ? neighbours + 1 : neighbours;

				neighbours = (boothes[x][y - 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x][y + 1].isAlive()) ? neighbours + 1 : neighbours;
			}

			else if (x == width - 1) {
				neighbours = (boothes[x - 1][y - 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x - 1][y].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x - 1][y + 1].isAlive()) ? neighbours + 1 : neighbours;

				neighbours = (boothes[x][y - 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x][y + 1].isAlive()) ? neighbours + 1 : neighbours;
			}

			else if (y == 0)
			{
				neighbours = (boothes[x - 1][y + 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x][y + 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x + 1][y + 1].isAlive()) ? neighbours + 1 : neighbours;

				neighbours = (boothes[x - 1][y].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x + 1][y].isAlive()) ? neighbours + 1 : neighbours;
			}

			else if (y == height - 1) {
				neighbours = (boothes[x - 1][y - 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x][y - 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x + 1][y - 1].isAlive()) ? neighbours + 1 : neighbours;

				neighbours = (boothes[x - 1][y].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x + 1][y].isAlive()) ? neighbours + 1 : neighbours;
			}

			else {
				neighbours = (boothes[x - 1][y - 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x - 1][y].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x - 1][y + 1].isAlive()) ? neighbours + 1 : neighbours;

				neighbours = (boothes[x][y - 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x][y + 1].isAlive()) ? neighbours + 1 : neighbours;

				neighbours = (boothes[x + 1][y - 1].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x + 1][y].isAlive()) ? neighbours + 1 : neighbours;
				neighbours = (boothes[x + 1][y + 1].isAlive()) ? neighbours + 1 : neighbours;
			}

			boothNeighbours[x][y] = neighbours;
		}
	}

	//GridGene oldGrid(*this);

	for (int x = 0; x < 40; x++) {
		for (int y = 0; y < 30; y++) {
			std::set<int> geneSet;
			for (int i = 0; i < 9; i++){
				if (boothes[x][y].getGene()[i] == true) {
					geneSet.insert(i + 1);
				}
			}
			if ((x == 0) && (y == 0)) {

				if (geneSet.find(boothNeighbours[x + 1][y]) != geneSet.end() 
					&& boothes[x + 1][y].isAlive() ==false) {

					boothes[x + 1][y] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x + 1][y + 1]) != geneSet.end()
					&& boothes[x + 1][y + 1].isAlive()== false) {

					boothes[x + 1][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x][y + 1]) != geneSet.end()
					&& boothes[x][y + 1].isAlive()== false) {

					boothes[x][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}

			}

			else if ((x == width - 1) && (y == 0)) {

				if (geneSet.find(boothNeighbours[x - 1][y]) != geneSet.end()
					&& boothes[x - 1][y].isAlive() ==false) {

					boothes[x - 1][y] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x - 1][y + 1]) != geneSet.end()
					&& boothes[x - 1][y + 1].isAlive() ==false) {

					boothes[x - 1][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x][y + 1]) != geneSet.end()
					&& boothes[x][y + 1].isAlive() ==false) {

					boothes[x][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
			}

			else if ((x == 0) && (y == height - 1)) {

				if (geneSet.find(boothNeighbours[x + 1][y]) != geneSet.end()
					&& boothes[x + 1][y].isAlive() ==false) {

					boothes[x + 1][y] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x + 1][y - 1]) != geneSet.end()
					&& boothes[x + 1][y - 1].isAlive()==false) {

					boothes[x + 1][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x][y - 1]) != geneSet.end()
					&& boothes[x][y - 1].isAlive() ==false) {

					boothes[x][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
			}

			else if ((x == width - 1) && (y == height - 1)) {

				if (geneSet.find(boothNeighbours[x - 1][y]) != geneSet.end()
					&& boothes[x - 1][y].isAlive()==false) {

					boothes[x - 1][y] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x - 1][y - 1]) != geneSet.end()
					&& boothes[x - 1][y - 1].isAlive()==false) {

					boothes[x - 1][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x][y - 1]) != geneSet.end()
					&& boothes[x][y - 1].isAlive()==false==false) {

					boothes[x][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
			}

			else if (x == 0) {

				if (geneSet.find(boothNeighbours[x + 1][y - 1]) != geneSet.end()
					&& boothes[x + 1][y - 1].isAlive()==false) {

					boothes[x + 1][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x + 1][y]) != geneSet.end()
					&& boothes[x + 1][y].isAlive()==false) {

					boothes[x + 1][y] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x + 1][y + 1]) != geneSet.end()
					&& boothes[x + 1][y + 1].isAlive()==false) {

					boothes[x + 1][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}


				else if (geneSet.find(boothNeighbours[x][y - 1]) != geneSet.end()
					&& boothes[x][y - 1].isAlive()==false) {

					boothes[x][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x][y + 1]) != geneSet.end()
					&& boothes[x][y + 1].isAlive()==false) {

					boothes[x][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
			}

			else if (x == width - 1) {

				if (geneSet.find(boothNeighbours[x - 1][y - 1]) != geneSet.end()
					&& boothes[x - 1][y - 1].isAlive()==false) {

					boothes[x - 1][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x + 1][y]) != geneSet.end()
					&& boothes[x - 1][y].isAlive()==false) {

					boothes[x - 1][y] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x - 1][y + 1]) != geneSet.end()
					&& boothes[x - 1][y + 1].isAlive()==false) {

					boothes[x - 1][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}


				else if (geneSet.find(boothNeighbours[x][y - 1]) != geneSet.end()
					&& boothes[x][y - 1].isAlive()==false) {

					boothes[x][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x][y + 1]) != geneSet.end()
					&& boothes[x][y + 1].isAlive()==false) {

					boothes[x][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
			}

			else if (y == 0)
			{

				if (geneSet.find(boothNeighbours[x - 1][y + 1]) != geneSet.end()
					&& !boothes[x - 1][y + 1].isAlive()==false) {

					boothes[x - 1][y+ 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x][y + 1]) != geneSet.end()
					&& !boothes[x][y + 1].isAlive()==false) {

					boothes[x][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x + 1][y + 1]) != geneSet.end()
					&& !boothes[x + 1][y + 1].isAlive()==false) {

					boothes[x + 1][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}


				else if (geneSet.find(boothNeighbours[x - 1][y]) != geneSet.end()
					&& boothes[x - 1][y].isAlive()==false) {

					boothes[x - 1][y] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x + 1][y]) != geneSet.end()
					&& boothes[x + 1][y].isAlive()==false==false) {

					boothes[x + 1][y] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
			}

			else if (y == height - 1) {

				if (geneSet.find(boothNeighbours[x - 1][y - 1]) != geneSet.end()
					&& boothes[x - 1][y - 1].isAlive()==false) {

					boothes[x - 1][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x][y - 1]) != geneSet.end()
					&& boothes[x][y - 1].isAlive()==false) {

					boothes[x][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x + 1][y - 1]) != geneSet.end()
					&& boothes[x + 1][y - 1].isAlive()==false) {

					boothes[x + 1][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}


				else if (geneSet.find(boothNeighbours[x - 1][y]) != geneSet.end()
					&& boothes[x - 1][y].isAlive()==false) {

					boothes[x - 1][y] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x + 1][y]) != geneSet.end()
					&& boothes[x + 1][y].isAlive()==false) {

					boothes[x + 1][y] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
			}

			else {
				if (geneSet.find(boothNeighbours[x - 1][y - 1]) != geneSet.end()
					&& boothes[x - 1][y - 1].isAlive()==false) {

					boothes[x - 1][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x][y - 1]) != geneSet.end()
					&& boothes[x][y - 1].isAlive()==false) {

					boothes[x][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x + 1][y - 1]) != geneSet.end()
					&& !boothes[x + 1][y - 1].isAlive()==false) {

					boothes[x + 1][y - 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}


				else if (geneSet.find(boothNeighbours[x - 1][y]) != geneSet.end()
					&& boothes[x - 1][y].isAlive()==false) {

					boothes[x - 1][y] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x + 1][y]) != geneSet.end()
					&& boothes[x + 1][y].isAlive()==false) {

					boothes[x + 1][y] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}


				else if (geneSet.find(boothNeighbours[x - 1][y + 1]) != geneSet.end()
					&& boothes[x - 1][y + 1].isAlive()==false) {

					boothes[x - 1][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x][y + 1]) != geneSet.end()
					&& boothes[x][y + 1].isAlive()==false) {

					boothes[x][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
				else if (geneSet.find(boothNeighbours[x + 1][y + 1]) != geneSet.end()
					&& boothes[x + 1][y + 1].isAlive()==false) {

					boothes[x + 1][y + 1] = boothes[x][y];
					boothes[x][y].setAlive(false);
				}
			}
		}
	}


	for (int x = 0; x < 40; x++) {
		for (int y = 0; y < 30; y++) {

			int * neighbours = new int;
			*neighbours = 0;

			if ((x == 0) && (y == 0)) {
				*neighbours = (boothes[x + 1][y].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x + 1][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;
			}

			else if ((x == width - 1) && (y == 0)) {
				*neighbours = (boothes[x - 1][y].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x - 1][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;
			}

			else if ((x == 0) && (y == height - 1)) {
				*neighbours = (boothes[x + 1][y].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x + 1][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
			}

			else if ((x == width - 1) && (y == height - 1)) {
				*neighbours = (boothes[x - 1][y].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x - 1][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
			}

			else if (x == 0) {
				*neighbours = (boothes[x + 1][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x + 1][y].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x + 1][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;

				*neighbours = (boothes[x][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;
			}

			else if (x == width - 1) {
				*neighbours = (boothes[x - 1][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x - 1][y].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x - 1][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;

				*neighbours = (boothes[x][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;
			}

			else if (y == 0)
			{
				*neighbours = (boothes[x - 1][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x + 1][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;

				*neighbours = (boothes[x - 1][y].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x + 1][y].isAlive()) ? *neighbours + 1 : *neighbours;
			}

			else if (y == height - 1) {
				*neighbours = (boothes[x - 1][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x + 1][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;

				*neighbours = (boothes[x - 1][y].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x + 1][y].isAlive()) ? *neighbours + 1 : *neighbours;
			}

			else {
				*neighbours = (boothes[x - 1][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x - 1][y].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x - 1][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;

				*neighbours = (boothes[x][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;

				*neighbours = (boothes[x + 1][y - 1].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x + 1][y].isAlive()) ? *neighbours + 1 : *neighbours;
				*neighbours = (boothes[x + 1][y + 1].isAlive()) ? *neighbours + 1 : *neighbours;
			}

			if (boothes[x][y].isAlive()) {
				if ((*neighbours != 2) && (*neighbours != 3)) {
					boothesToDie[x][y] = true;
				}
			}

			else {
				if (*neighbours == 3) {
					boothesToGetLive[x][y] = true;
				}
			}

			delete neighbours;
		}
	}


	for (int x = 0; x < 40; x++) {
		for (int y = 0; y < 30; y++) {
			if (boothesToDie[x][y]) {
				boothes[x][y].setAlive(false);
			}
			if (boothesToGetLive[x][y]) {
				boothes[x][y].setAlive(true);
			}
		}
	}
	if (aliveCount() == 0)
	{
		throw std::exception("Died!\n0 cells is alive");
	}
}


GridGene::GridGene(int widht, int height)
	:Grid(widht, height)
{
	for (int x = 0; x < widht; x++) {
		for (int y = 0; y < height ; y++) {
			bool* gene = new bool[9];
			for (int i = 0; i < 9; i++)
			{
				gene[i] = rand() % 2;
			}
			boothes[x][y] = BoothGene(x * 20, y * 20, false,gene);
		}
	}
}

GridGene::GridGene(const GridGene &grid)
	:Grid(grid)
{}


