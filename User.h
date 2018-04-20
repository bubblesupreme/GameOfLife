#ifndef USER_H
#define USER_H

#include <string>

class User
{
public:
	User();
	User(const std::string& name);
	User(const std::string& name, int level);
	~User();
	void setLevel(int level);
	void addLevel();
	int getLevel();
	std::string& getName();
	bool operator==(User rhs);
	bool operator!=(User rhs);
private:
	std::string name;
	int level;
};

#endif