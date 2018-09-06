#include <stdio.h>




struct member_BlackPink
{
	char name[20];
	int birthday;
	double height;
	char bloodtype;
public:
	member_BlackPink(/*char gname[20], int gbirthday, double gheight, char gbloodtype) : name(gname), birthday(gbirthday), height(gheight), bloodtype(gbloodtype*/) {}
	~member_BlackPink() {}
	char* getName() { return name; }
	int getBirthday() { return height; }
	double getHeight() { return height; }
	char getBloodType() { return bloodtype; }
	void setName(char gname[20]) { /*this->name = gname;*/ for (int i = 0; i < 20; i++) this->name[i] = gname[i]; }
	void setBirthday(int gbirthday) { this->birthday = gbirthday; }
	void setHeight(double gheight) { this->height = gheight; }
	void setBloodtype(char gbloodtype) { this->bloodtype = gbloodtype; }
};

int main()
{
	member_BlackPink member[3];

	member[0].setName("hello");	member[0].setBirthday(9999999); member[0].setHeight(1.5); member[0].setBloodtype('A');
	
	


	return 0;
}