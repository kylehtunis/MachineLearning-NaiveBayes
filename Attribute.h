#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <iostream>

using namespace std;

class Attribute {
private:
	friend ostream& operator<<(ostream& os, const Attribute &attribute);
protected:
	string name;
public:
	virtual void print(ostream &os = cout) const;
	Attribute();
	Attribute(string n);
	virtual string getName() const;
	virtual int getSize();
	void setName(string);
};
#endif // !ATTRIBUTE_H
