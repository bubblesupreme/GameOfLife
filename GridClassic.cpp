#include "GridClassic.h"


GridClassic::GridClassic(int widht, int height)
	:Grid(widht, height)
{
	bool* gene = new bool[9];
	for (int i = 0; i < 9; i++)
	{
		gene[i] = false;
	}
	for (int x = 0; x < widht; x++) {
		for (int y = 0; y < height; y++) {
			boothes[x][y] = BoothGene(x * sizeBooth, y * sizeBooth, false, gene);
		}
	}
}

GridClassic::GridClassic(const Grid &grid)
	:Grid(grid)
{}

GridClassic::~GridClassic()
{
}

void GridClassic::update()
{
	bool boothesToDie[40][30];
	bool boothesToGetLive[40][30];

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			boothesToDie[x][y] = false;
			boothesToGetLive[x][y] = false;
		}
	}

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {

			if (x == 39)
			{
				x = 39;
			}
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


	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
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


