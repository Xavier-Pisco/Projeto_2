#include "Client.h"
#include "Packet.h"
#include <sstream>

	//Construtores

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

Client::Client(stringstream ssClient)
{
	string input;
	getline(ssClient, name);
	getline(ssClient, input);
	VATnumber = stoi(input);
	getline(ssClient, input);
	familySize = stoi(input);
	getline(ssClient, input);
	this->setAddress(input);
	getline(ssClient, input);
	this->setPacketList(input);
	getline(ssClient, input);
	totalPurchased = stoi(input);
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

string Client::getPacketsIds() const
{
	string content;
	for (int i = 0; i < packets.size() - 1; i++)
		content += packets[i].getId() + " ; ";
	content += packets[packets.size() - 1].getId();
	return content;
}

string Client::getContent() const
{
	string content;
	content += name + '\n';
	content += to_string(VATnumber) + '\n';
	content += to_string(familySize) + '\n';
	content += address.getContent() + '\n';
	content += getPacketsIds() + '\n';
	content += to_string(totalPurchased) + '\n';
	return content;
}
  

  // metodos SET
	  
void Client::setName(string name){
  
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

void Client::setPacketList(string packets)
{
	while (packets.find_first_of(';') != packets.npos)
	{
		this->packets.push_back(getPacketFromId(stoi(packets.substr(0, packets.find_first_of(';') - 1))));
		packets.erase(0, packets.find_first_of(';') + 2);
	}
	this->packets.push_back(getPacketFromId(stoi(packets.substr(0, packets.npos))));
}

void Client::setTotalPurchased(unsigned totalPurchased){
  
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

void Client::buyPacket(int packetId, vector<Packet> vpackets)
{
	Packet packet = getPackFromId(packetId, vpackets);
	packets.push_back(packet);

	for (unsigned i = 0; i < packets.size(); i++)
	{
		if (packets[i].getId() == packetId)
			cout << "Já comprou lugar neste pacote." << endl;
	}

	for (unsigned i = 0; i < vpackets.size(); i++)
	{
		if (packet.getId() == packetId)
		{
			if (packet.getMaxPersons())
			{
				this->totalPurchased += this->familySize * packet.getPricePerPerson();
				packets.push_back(packet);
				packet.setMaxPersons(packet.getMaxPersons() - 1);
			}
			else
				cout << "Pacote não tem mais lugares disponiveis." << endl;
		}
	}



}

//ostream& operator<<(ostream& out, const Client & client){
//
//  // REQUIRES IMPLEMENTATION 
//
//}

