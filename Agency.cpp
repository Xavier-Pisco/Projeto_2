#include "Agency.h"
#include <fstream>
#include <string>
#include <iostream>

Agency::Agency(string fileName){

	int counter = 0;
	string line_agency;
	ifstream agency_file;
	agency_file.open(fileName);
	while (getline(agency_file, line_agency))
	{
		if (counter == 0)
		{
			name = line_agency;
		}
		if (counter == 1)
		{
			VATnumber = stoi(line_agency);
		}
		if (counter == 2)
		{
			URL = line_agency;
		}
		if (counter == 3)
		{
			this->setAddress(line_agency);
		}
		if (counter == 4)
		{
			clients_file_name = line_agency;
		}
		if (counter == 5)
		{
			packs_file_name = line_agency;
		}
		counter++;
	}
}

  // metodos GET
string Agency::getName() const{

  return name;
}

unsigned Agency::getVATnumber() const{

	return VATnumber;
}

Address Agency::getAddress() const{

	return address;
}

string Agency::getURL() const{

	return URL;
}

vector<Client> Agency::getClients() const{

	return clients;
}

vector<Packet> Agency::getPackets() const{

	return packets;
}

string Agency::getContent() const
{
	return (name + '\n' + to_string(VATnumber) + '\n' + address.getContent() + '\n' + URL + '\n' + clients_file_name + '\n' + packs_file_name + '\n');
}

string Agency::getClientsFilename() const
{
	return clients_file_name;
}

string Agency::getPacketsFilename() const
{
	return packets_file_name;
}

  
  // SET Methods

void Agency::setName(string name){

	this->name = name;
}

void Agency::setVATnumber(unsigned VATnumber){

	this->VATnumber = VATnumber;
}

void Agency::setAddress(Address address){

	this->address = address;
}
void Agency::setURL(string url){

	  this->URL = url;

}
void Agency::setClients(vector<Client> & clients){

	  this->clients = clients;

  }
void Agency::setPackets(vector<Packet> & packets){

	  this->packets = packets;

}

/*********************************
 * Mostrar Loja*/
  void Agency::show() const
  {
	  cout << name << endl << VATnumber << endl << URL << endl;
	  address.show();
	  cout << clients_file_name << endl << packs_file_name << endl;
  }
  

// mostra o conteudo de uma agencia
//ostream& operator<<(ostream& out, const Agency & agency){
//
//  // A IMPLEMENTATION REQUIRED 
//}
