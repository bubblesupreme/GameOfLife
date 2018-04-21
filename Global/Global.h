#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>
#include "StateEnum.h"
#include "../Additional/Resources.h"
#include "../Additional/LevelBlanks.h"
#include "../User.h"

typedef  std::pair<int, int> Position;
typedef  std::pair<int, int> Size;
//State state = MODIFYING;
extern const int sizeBooth;
extern const Size sizeGrid;
extern const Size sizeGridLevel;
extern const float bandWidth;
extern Resources* resources;
extern const LevelBlanks levelBlanks;
extern User user;
extern std::string fileName;
extern sf::Sound sound;
//static const float bandReturn = 40.0;
#endif