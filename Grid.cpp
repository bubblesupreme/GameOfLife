#include "Grid.h"
#include<iostream>

Grid::Grid(int widht, int height)
{
	this->width = widht;
	this->height = height;
	boothes = new BoothGene*[widht];
	for (int i = 0; i < widht; i++)
	{
		boothes[i] = new BoothGene[height];
	}
}

Grid::~Grid()
{}

void Grid::setBoothAt(const bool alive, int x, int y)
{
	boothes[x][y].setAlive(alive);
}

bool Grid::isboolAliveAt(int x, int y) const
{
	return boothes[x][y].isAlive();
}

void Grid::draw(sf::RenderWindow &window) const
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			boothes[x][y].choiceColor();
			boothes[x][y].draw(window);
		}
	}
}

void Grid::draw(sf::RenderWindow &window, Grid* nextGrid)
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			boothes[x][y].choiceColor(nextGrid->boothes[x][y]);
			boothes[x][y].draw(window);
		}
	}
}

Grid::Grid(const Grid &grid)
	:Grid(grid.width, grid.height)
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			boothes[x][y] = grid.boothes[x][y];
		}
	}
}

const bool Grid::operator==(const Grid& rhs) const
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (boothes[x][y].isAlive() != rhs.boothes[x][y].isAlive())
			{
				return false;
			}
		}
	}
	return true;
}

const int Grid::aliveCount() const
{
	int count = 0;
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (boothes[x][y].isAlive())
			{
				count++;
			}
		}
	}
	return count;
}

void Grid::clear()
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {

			boothes[x][y].setAlive(false);
		}
	}
}

const Size Grid::getSize() const
{
	return Size(width, height);
}