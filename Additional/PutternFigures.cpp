#include "PatternFigures.h"

PutternFigures::PutternFigures()
{
	stable.push_back(figure("Block",*block,sizeof(block)/sizeof(block[0]),sizeof(block[0])));
	stable.push_back(figure("Bi block",*biBlock, sizeof(biBlock) / sizeof(biBlock[0]), sizeof(biBlock[0])));
	stable.push_back(figure("Hive", *hive, sizeof(hive) / sizeof(hive[0]), sizeof(hive[0])));
	stable.push_back(figure("Honey\n farm", *honeyFarm, sizeof(honeyFarm) / sizeof(honeyFarm[0]), sizeof(honeyFarm[0])));
	stable.push_back(figure("Loaf", *loaf, sizeof(loaf) / sizeof(loaf[0]), sizeof(loaf[0])));
	stable.push_back(figure("Bi loaf", *biLoaf, sizeof(biLoaf) / sizeof(biLoaf[0]), sizeof(biLoaf[0])));
	stable.push_back(figure("Bakery", *bakery, sizeof(bakery) / sizeof(bakery[0]), sizeof(bakery[0])));
	stable.push_back(figure("Tub",*tub, sizeof(tub) / sizeof(tub[0]), sizeof(tub[0])));
	stable.push_back(figure("Barge",*barge, sizeof(barge) / sizeof(barge[0]), sizeof(barge[0])));
	stable.push_back(figure("Boat",*boat, sizeof(boat) / sizeof(boat[0]), sizeof(boat[0])));
	stable.push_back(figure("Boat\n long",*boatLong, sizeof(boatLong) / sizeof(boatLong[0]), sizeof(boatLong[0])));
	stable.push_back(figure("Ship",*ship, sizeof(ship) / sizeof(ship[0]), sizeof(ship[0])));
	stable.push_back(figure("Ship long",*shipLong, sizeof(shipLong) / sizeof(shipLong[0]), sizeof(shipLong[0])));
	stable.push_back(figure("Boat Tie",*boatTie, sizeof(boatTie) / sizeof(boatTie[0]), sizeof(boatTie[0])));
	stable.push_back(figure("Canoe",*canoe, sizeof(canoe) / sizeof(canoe[0]), sizeof(canoe[0])));
	stable.push_back(figure("Flattop",*flattop, sizeof(flattop) / sizeof(flattop[0]), sizeof(flattop[0])));
	stable.push_back(figure("Integral",*integral, sizeof(integral) / sizeof(integral[0]), sizeof(integral[0])));
	stable.push_back(figure("Mango",*mango, sizeof(mango) / sizeof(mango[0]), sizeof(mango[0])));
	stable.push_back(figure("Pond",*pond, sizeof(pond) / sizeof(pond[0]), sizeof(pond[0])));
	stable.push_back(figure("Snake",*snake, sizeof(snake) / sizeof(snake[0]), sizeof(snake[0])));

	centenarians.push_back(figure("R-penta-\nnimo",*Rpentanimo, sizeof(Rpentanimo) / sizeof(Rpentanimo[0]), sizeof(Rpentanimo[0])));
	centenarians.push_back(figure("Corn",*corn, sizeof(corn) / sizeof(corn[0]), sizeof(corn[0])));
	centenarians.push_back(figure("Bunnies",*bunnies, sizeof(bunnies) / sizeof(bunnies[0]), sizeof(bunnies[0])));

	oscillators2.push_back(figure("Blinker",*blinker, sizeof(blinker) / sizeof(blinker[0]), sizeof(blinker[0])));
	oscillators2.push_back(figure("Toad",*toad, sizeof(toad) / sizeof(toad[0]), sizeof(toad[0])));
	oscillators2.push_back(figure("Clock",*clock, sizeof(clock) / sizeof(clock[0]), sizeof(clock[0])));
	oscillators2.push_back(figure("Beacon",*beacon, sizeof(beacon) / sizeof(beacon[0]), sizeof(beacon[0])));
	oscillators2.push_back(figure("Bipole",*bipole, sizeof(bipole) / sizeof(bipole[0]), sizeof(bipole[0])));
	oscillators2.push_back(figure("Ring A",*ringA, sizeof(ringA) / sizeof(ringA[0]), sizeof(ringA[0])));
	oscillators2.push_back(figure("Phonix",*phoenix, sizeof(phoenix) / sizeof(phoenix[0]), sizeof(phoenix[0])));
	oscillators2.push_back(figure("Leaf",*leaf, sizeof(leaf) / sizeof(leaf[0]), sizeof(leaf[0])));
	oscillators2.push_back(figure("Z",*z, sizeof(z) / sizeof(z[0]), sizeof(z[0])));
	oscillators2.push_back(figure("Arrow",*arrow, sizeof(arrow) / sizeof(arrow[0]), sizeof(arrow[0])));
	oscillators2.push_back(figure("Quad",*quad, sizeof(quad) / sizeof(quad[0]), sizeof(quad[0])));
	oscillators2.push_back(figure("Snake2",*snake2, sizeof(snake2) / sizeof(snake2[0]), sizeof(snake2[0])));
	oscillators2.push_back(figure("Glasses",*glasses, sizeof(glasses) / sizeof(glasses[0]), sizeof(glasses[0])));
	oscillators2.push_back(figure("Negentropy",*negentropy, sizeof(negentropy) / sizeof(negentropy[0]), sizeof(negentropy[0])));
	oscillators2.push_back(figure("Revolver",*revolver, sizeof(revolver) / sizeof(revolver[0]), sizeof(revolver[0])));

	oscillators345.push_back(figure("Prepulsar",*prepulsar, sizeof(prepulsar) / sizeof(prepulsar[0]), sizeof(prepulsar[0])));
	oscillators345.push_back(figure("Jam",*jam, sizeof(jam) / sizeof(jam[0]), sizeof(jam[0])));
	oscillators345.push_back(figure("Caterer",*caterer, sizeof(caterer) / sizeof(caterer[0]), sizeof(caterer[0])));
	oscillators345.push_back(figure("Jack",*jack, sizeof(jack) / sizeof(jack[0]), sizeof(jack[0])));
	oscillators345.push_back(figure("Snake\n pirt3",*snakePirt3, sizeof(snakePirt3) / sizeof(snakePirt3[0]), sizeof(snakePirt3[0])));
	oscillators345.push_back(figure("Maltese\n Cross",*MalteseCross, sizeof(MalteseCross) / sizeof(MalteseCross[0]), sizeof(MalteseCross[0])));
	oscillators345.push_back(figure("Monogram",*monogram, sizeof(monogram) / sizeof(monogram[0]), sizeof(monogram[0])));
	oscillators345.push_back(figure("Pinwheel",*pinwheel, sizeof(pinwheel) / sizeof(pinwheel[0]), sizeof(pinwheel[0])));
	oscillators345.push_back(figure("Keys",*keys, sizeof(keys) / sizeof(keys[0]), sizeof(keys[0])));
	oscillators345.push_back(figure("Star",*star, sizeof(star) / sizeof(star[0]), sizeof(star[0])));
	oscillators345.push_back(figure("Glider",*glider, sizeof(glider) / sizeof(glider[0]), sizeof(glider[0])));

	oscillators678.push_back(figure("A for all",*aForAll, sizeof(aForAll) / sizeof(aForAll[0]), sizeof(aForAll[0])));
	oscillators678.push_back(figure("Smiley",*smiley, sizeof(smiley) / sizeof(smiley[0]), sizeof(smiley[0])));
	oscillators678.push_back(figure("Roteightor",*roteightor, sizeof(roteightor) / sizeof(roteightor[0]), sizeof(roteightor[0])));
	oscillators678.push_back(figure("Quilt\n square",*quiltSquare, sizeof(quiltSquare) / sizeof(quiltSquare[0]), sizeof(quiltSquare[0])));
	oscillators678.push_back(figure("Figure8",*figure8, sizeof(figure8) / sizeof(figure8[0]), sizeof(figure8[0])));
	oscillators678.push_back(figure("Cauldron",*cauldron, sizeof(cauldron) / sizeof(cauldron[0]), sizeof(cauldron[0])));

	oscillatorsLong.push_back(figure("Champagne\n glass (22)",*champagneGlass22, sizeof(champagneGlass22) / sizeof(champagneGlass22[0]), sizeof(champagneGlass22[0])));
	oscillatorsLong.push_back(figure("Toadsu-\ncker (60)",*toadsucker60, sizeof(toadsucker60) / sizeof(toadsucker60[0]), sizeof(toadsucker60[0])));
	oscillatorsLong.push_back(figure("Gourmet\n (per.32)",*gourmet32, sizeof(gourmet32) / sizeof(gourmet32[0]), sizeof(gourmet32[0])));
	oscillatorsLong.push_back(figure("Eurika",*eurika, sizeof(eurika) / sizeof(eurika[0]), sizeof(eurika[0])));
	oscillatorsLong.push_back(figure("Queen\n shuttle",*queenShuttle, sizeof(queenShuttle) / sizeof(queenShuttle[0]), sizeof(queenShuttle[0])));
	oscillatorsLong.push_back(figure("Snacker",*snacker, sizeof(snacker) / sizeof(snacker[0]), sizeof(snacker[0])));

	spaceships.push_back(figure("Light",*light, sizeof(light) / sizeof(light[0]), sizeof(light[0])));
	spaceships.push_back(figure("Heavy",*heavy, sizeof(heavy) / sizeof(heavy[0]), sizeof(heavy[0])));
	spaceships.push_back(figure("Brain",*brain, sizeof(brain) / sizeof(brain[0]), sizeof(brain[0])));
	spaceships.push_back(figure("Canada\n goose",*canadaGoose, sizeof(canadaGoose) / sizeof(canadaGoose[0]), sizeof(canadaGoose[0])));
	spaceships.push_back(figure("Coe ship",*coeShip, sizeof(coeShip) / sizeof(coeShip[0]), sizeof(coeShip[0])));
	spaceships.push_back(figure("Dart",*dart, sizeof(dart) / sizeof(dart[0]), sizeof(dart[0])));
	spaceships.push_back(figure("Flotilla",*flotilla, sizeof(flotilla) / sizeof(flotilla[0]), sizeof(flotilla[0])));
	spaceships.push_back(figure("Sidecar",*sidecar, sizeof(sidecar) / sizeof(sidecar[0]), sizeof(sidecar[0])));
	spaceships.push_back(figure("Turtle",*turtle, sizeof(turtle) / sizeof(turtle[0]), sizeof(turtle[0])));
	spaceships.push_back(figure("Pushalong",*pushalong, sizeof(pushalong) / sizeof(pushalong[0]), sizeof(pushalong[0])));

	reflectors.push_back(figure("Fishhook",*fishhook, sizeof(fishhook) / sizeof(fishhook[0]), sizeof(fishhook[0])));
	reflectors.push_back(figure("Reaction",*reaction, sizeof(reaction) / sizeof(reaction[0]), sizeof(reaction[0])));
	reflectors.push_back(figure("Eightas",*eightas, sizeof(eightas) / sizeof(eightas[0]), sizeof(eightas[0])));
	reflectors.push_back(figure("Pipsquirter",*pipsquirter2, sizeof(pipsquirter2) / sizeof(pipsquirter2[0]), sizeof(pipsquirter2[0])));

	eaters.push_back(figure("Eater",*eater, sizeof(eater) / sizeof(eater[0]), sizeof(eater[0])));
	eaters.push_back(figure("Eater2",*eater2, sizeof(eater2) / sizeof(eater2[0]), sizeof(eater2[0])));
	eaters.push_back(figure("Eater3",*eater3, sizeof(eater3) / sizeof(eater3[0]), sizeof(eater3[0])));
	eaters.push_back(figure("Eater4",*eater4, sizeof(eater4) / sizeof(eater4[0]), sizeof(eater4[0])));
	eaters.push_back(figure("Eater5",*eater5, sizeof(eater5) / sizeof(eater5[0]), sizeof(eater5[0])));
	eaters.push_back(figure("Centry\n eater",*centryEater, sizeof(centryEater) / sizeof(centryEater[0]), sizeof(centryEater[0])));
	eaters.push_back(figure("Eater\n block",*eaterBlock, sizeof(eaterBlock) / sizeof(eaterBlock[0]), sizeof(eaterBlock[0])));

}


const std::vector<figure>& PutternFigures::getStable()
{
	return stable;
}

const std::vector<figure>& PutternFigures::getCentenarians()
{
	return centenarians;
}

const std::vector<figure>& PutternFigures::getOscillators2()
{
	return oscillators2;
}

const std::vector<figure>& PutternFigures::getOscillators345()
{
	return oscillators345;
}

const std::vector<figure>& PutternFigures::getOscillators678()
{
	return oscillators678;
}

const std::vector<figure>& PutternFigures::getOscillatorsLong()
{
	return oscillatorsLong;
}

const std::vector<figure>& PutternFigures::getSpaceships()
{
	return spaceships;
}

const std::vector<figure>& PutternFigures::getReflectors()
{
	return reflectors;
}

const std::vector<figure>& PutternFigures::getEaters()
{
	return eaters;
}

PutternFigures::~PutternFigures()
{}