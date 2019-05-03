#include "Client.h"

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address){
	
	this->name = name;
	this->VATnumber = VATnumber;
	this->familySize = familySize;
	this->address = address;
	totalPurchased = 0;
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<Packet> & packets, unsigned totalPurchased){
  
	this->name = name;
	this->VATnumber = VATnumber;
	this->familySize = familySize;
	this->address = address;
	this->packets = packets;
	this->totalPurchased = totalPurchased;
}


  // GET methods

string Client::getName() const{
  
	return name;
}
  
unsigned Client::getVATnumber() const{
  
	return VATnumber;
}

unsigned short Client::getFamilySize() const{
  
	return familySize;
}

Address Client::getAddress() const{
  
	return address;
}

vector<Packet> Client::getPacketList() const{
  
	return packets;
}

unsigned Client::getTotalPurchased() const{
  
	return totalPurchased;
}
  

  // metodos SET
	  
void Client::setName(string nome){
  
	this->name = name;
}

void Client::setVATnumber(unsigned VATnumber){
  
	this->VATnumber = VATnumber;
}

void Client::setFamilySize(unsigned short familySize){
  
	this->familySize = familySize;
}

void Client::setAddress(Address address){
  
	this->address = address;
}

void Client::setPacketList(vector<Packet> & packets){
  
	this->packets = packets;
}

unsigned Client::setTotalPurchased(unsigned totalPurchased){
  
	this->totalPurchased = totalPurchased;
}
  

  // outros metodos

void Client::show() const
{
	cout << name << endl;
	cout << VATnumber << endl;
	cout << familySize << endl;
	address.show();
	for (int i = 0; i < packets.size() - 1; i++)
		cout << packets[i].getId() << " ; ";
	cout << packets[packets.size() - 1].getId() << endl;
	cout << totalPurchased << endl;
}


//ostream& operator<<(ostream& out, const Client & client){
//
//  // REQUIRES IMPLEMENTATION 
//
//}
