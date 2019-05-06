#include "Packet.h"

int Packet::nextId;

Packet::Packet(vector<string> sites, Date inicio, Date fim, double precoPessoa, unsigned maxPessoas){

	nextId += 1;
	id = nextId;
	this->sites = sites;
	begin = inicio;
	end = fim;
	pricePerPerson = precoPessoa;
	maxPersons = maxPessoas;
}

  // metodos GET

unsigned Packet::getId() const{

	return id;
}

vector<string> Packet::getSites() const{

	return sites;
}

Date Packet::getBeginDate() const {

	return begin;
}

Date Packet::getEndDate() const{

	return end;
}

double Packet::getPricePerPerson() const{

	return pricePerPerson;
}

unsigned Packet::getMaxPersons() const{

	return maxPersons;
}

string Packet::getContent() const
{
	string content;
	content += to_string(id) + '\n' + sites[0] + " - ";
	for (int i = 1; i < sites.size() - 1; i++)
		content += sites[i] + ", ";
	content += sites[sites.size() - 1] + '\n';
	content += begin.getContent() + end.getContent();
	content += to_string(pricePerPerson) + '\n';
	return content;
}

  // metodos SET

void Packet::setId(unsigned id){

	this->id = id;
}

void Packet::setSites(vector<string> sites){

	this->sites = sites;
}

void Packet::setBeginDate(Date begin){

	this->begin = begin;
}

void Packet::setEndDate(Date end){

	this->end = end;
}

void Packet::setPricePerPerson(double pricePerPerson){

	this->pricePerPerson = pricePerPerson;
}

void Packet::setMaxPersons(unsigned maxPersons){

	this->maxPersons = maxPersons;
}

void Packet::setMaxPersons(unsigned total, unsigned reserved)
{
	maxPersons = total - reserved;
}


void Packet::show() const
{
	cout << id << endl << sites[0] << " - ";
	for (int i = 1; i < sites.size() - 1; i++)
		cout << sites[i] << ", ";
	cout << sites[sites.size() - 1] << endl;
	begin.show();
	end.show();
	cout << pricePerPerson << endl << maxPersons << endl;
	
}



// shows a packet content 
//ostream& operator<<(ostream& out, const Packet & packet){
//
//  // REQUIRES IMPLEMENTATION
//}



	//Funções de Packets mas não da classe

Packet getPacketFromId(const unsigned packetId, vector<Packet> vPackets)
{
	for (unsigned i = 0; i < vPackets.size(); i++)
	{
		if (vPackets[i].getId() == packetId)
		{
			return vPackets[i];
		}

		else if (i == vPackets.size() - 1)
			cout << "Pacote não encontrado." << endl;
	}
}