#include "Address.h"


using namespace std;


Address::Address()
{
	this->street = "";
	this->doorNumber = 0;
	this->floor = "-";
	this->postalCode = "";
	this->location = "";
}

Address::Address(string address)
{
	street = trim(address.substr(0, address.find_first_of('/')));
	address.erase(0, address.find_first_of('/') + 1);

	doorNumber = stoi(address.substr(0, address.find_first_of('/')));
	address.erase(0, address.find_first_of('/') + 1);

	floor = trim(address.substr(0, address.find_first_of('/')));
	address.erase(0, address.find_first_of('/') + 1);

	postalCode = trim(address.substr(0, address.find_first_of('/')));
	address.erase(0, address.find_first_of('/') + 1);

	location = trim(address.substr(0, address.find_first_of('/')));
	address.erase(0, address.find_first_of('/') + 1);
}

Address::Address(string street, unsigned short doorNumber, string floor, string postalCode, string location)
{
	this->street = street;
	this->doorNumber = doorNumber;
	this->floor = floor;
	this->postalCode = postalCode;
	this->location = location;
}

// metodos GET
string Address::getStreet() const {

	return street;
}

unsigned short Address::getDoorNumber() const {

	return doorNumber;
}

string Address::getFloor() const {

	return floor;
}

string Address::getPostalCode() const {

	return postalCode;
}

string Address::getLocation() const {

	return location;
}

string Address::getContent() const
{
	return (street + "/ " + to_string(doorNumber) + " /" + floor + "/" + postalCode + "/" + location);
}


// metodos SET
void Address::setStreet(string street) {

	this->street = street;
}

void Address::setDoorNumber(unsigned short doorNumber) {

	this->doorNumber = doorNumber;
}

void Address::setFloor(string floor) {

	this->floor = floor;
}

void Address::setPostalCode(string postalCode) {

	this->postalCode = postalCode;
}

void Address::setLocation(string  location) {

	this->location = location;
}

void Address::show() const
{
	cout << street << "/ " << doorNumber << " /" << floor << '/' << postalCode << '/' << location << endl;
}



// discplyes an address in a nice format
//ostream& operator<<(ostream & out, const Address & address) {
//
//	// REQUIRES IMPLEMENTATION
//
//}

bool postalCodeChecker(string postalCode)
{
	if (postalCode.find_first_of('-') == postalCode.npos)
		return false;
	if (postalCode.length() != 8)
		return false;
	if (stoi(postalCode.substr(0,4)) > 999 && stoi(postalCode.substr(0, 4)) < 10000)
	{
		if (stoi(postalCode.substr(5, 3)) > 99 && stoi(postalCode.substr(5, 3)) < 1000)
			return true;
	}
	return false;
}