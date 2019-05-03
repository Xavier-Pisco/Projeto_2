#include "Address.h"
#include <string>
#include <iostream>

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
	street = address.substr(0, address.find_first_of('/'));
	address.erase(0, address.find_first_of('/') + 1);

	doorNumber = stoi(address.substr(0, address.find_first_of('/')));
	address.erase(0, address.find_first_of('/') + 1);

	floor = address.substr(0, address.find_first_of('/'));
	address.erase(0, address.find_first_of('/') + 1);

	postalCode = address.substr(0, address.find_first_of('/'));
	address.erase(0, address.find_first_of('/') + 1);

	location = address.substr(0, address.find_first_of('/'));
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
	setVectorLocations();
}

void Address::show()
{
	cout << street << '/' << doorNumber << '/' << floor << '/' << postalCode << '/' << location << endl;
}

void Address::setVectorLocations()
{
	string s = location;
	v_locations.push_back(s.substr(0, s.find_first_of('-')));
	s.erase(0, s.find_first_of('-') + 1);
	while (s.find_first_of(',') != s.npos)
	{
		v_locations.push_back(s.substr(0, s.find_first_of(',')));
		s.erase(0, s.find_first_of(',') + 1);
	}
	v_locations.push_back(s);

	for (unsigned i = 0; i < v_locations.size(); i++)
	{
		if (v_locations[i][0] == ' ')
			v_locations[i].erase(0, v_locations[i].find_first_not_of(' '));

		v_locations[i].erase(v_locations[i].find_last_not_of(' ') + 1, v_locations[i].npos);
	}
}


bool Address::searchLocation(string location)
{
	if (location[0] == ' ')
		location.erase(0, location.find_first_not_of(' '));

	location.erase(location.find_last_not_of(' ') + 1, location.npos);

	for (unsigned i = 0; i < v_locations.size(); i++)
	{
		if (v_locations[i] == location)
			return true;
	}
	return false;
}



// discplyes an address in a nice format
//ostream& operator<<(ostream & out, const Address & address) {
//
//	// REQUIRES IMPLEMENTATION
//
//}