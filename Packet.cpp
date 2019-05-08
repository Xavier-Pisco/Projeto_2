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

Packet::Packet(string packet)
{
	int maximo, vendido;
	bool valido = true;

	if (stoi(packet.substr(0, packet.find_first_of('\n'))) < 0)
		valido = false;

	id = abs(stoi(packet.substr(0, packet.find_first_of('\n'))));
	packet.erase(0, packet.find_first_of('\n') + 1);

	setSites(packet.substr(0, packet.find_first_of('\n')));
	packet.erase(0, packet.find_first_of('\n') + 1);

	setBeginDate(packet.substr(0, packet.find_first_of('\n')));
	packet.erase(0, packet.find_first_of('\n') + 1);

	setEndDate(packet.substr(0, packet.find_first_of('\n')));
	packet.erase(0, packet.find_first_of('\n') + 1);

	pricePerPerson = stoi(packet.substr(0, packet.find_first_of('\n')));
	packet.erase(0, packet.find_first_of('\n') + 1);

	maximo = stoi(packet.substr(0, packet.find_first_of('\n')));
	packet.erase(0, packet.find_first_of('\n') + 1);

	vendido = stoi(packet.substr(0, packet.find_first_of('\n')));
	packet.erase(0, packet.find_first_of('\n') + 1);

	maxPersons = maximo - vendido;

	if (!valido)
		maxPersons = 0;

	nextId += 1;

	
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

void Packet::setSites(string sites)
{
	this->sites.push_back(sites.substr(0, sites.find_first_of('-') - 1));
	sites.erase(0, sites.find_first_of('-') + 2);

	while (sites.find_first_of(',') != sites.npos)
	{
		this->sites.push_back(sites.substr(0, sites.find_first_of('-') - 1));
		sites.erase(0, sites.find_first_of('-') + 2);
	}
	this->sites.push_back(sites);
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
	if (maxPersons == 0)
		cout << to_string(-int(id)) << endl;

	else
		cout << id << endl;
		
	cout << sites[0] << " - ";
	for (int i = 1; i < sites.size() - 1; i++)
		cout << sites[i] << ", ";
	cout << sites[sites.size() - 1] << endl;
	begin.show();
	end.show();
	cout << pricePerPerson << endl << maxPersons << endl;
	
}

bool Packet::searchLocation(string location)
{
	if (location[0] == ' ')
		location.erase(0, location.find_first_not_of(' '));

	location.erase(location.find_last_not_of(' ') + 1, location.npos);

	for (unsigned i = 0; i < sites.size(); i++)
	{
		if (sites[i] == location)
			return true;
	}
	return false;
}


vector<Packet> vpackets;



// shows a packet content 
//ostream& operator<<(ostream& out, const Packet & packet){
//
//  // REQUIRES IMPLEMENTATION
//}



	//Funções de Packets mas não da classe
