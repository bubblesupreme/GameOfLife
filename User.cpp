#include "User.h"



User::User()
{
	name = "no name";
	level = 1;
}

User::User(const std::string& name)
	:name(name)
{
	level = 0;
}

User::User(const std::string& name, int level)
	:name(name), level(level)
{}

bool User::operator==(User rhs)
{
	if (name == rhs.getName() && level == rhs.getLevel())
	{
		return true;
	}
	return false;
}

bool User::operator!=(User rhs)
{
	if (*this == rhs)
	{
		return false;
	}
	return true;
}

User::~User()
{
}

void User::setLevel(int level)
{
	this->level = level;
}

void User::addLevel()
{
	level++;
}

int User::getLevel()
{
	return level;
}

std::string& User::getName()
{
	return name;
}