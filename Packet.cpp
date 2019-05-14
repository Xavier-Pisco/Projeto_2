#include "Packet.h"

int Packet::nextId;

Packet::Packet(vector<string> sites, Date inicio, Date fim, double precoPessoa, unsigned seatsAvailable, unsigned seatsBought){

	packetAvailable = true;
	nextId += 1;
	id = nextId;
	this->sites = sites;
	begin = inicio;
	end = fim;
	pricePerPerson = precoPessoa;
	this->seatsAvailable = seatsAvailable;
	this->seatsBought = seatsBought;
	if (seatsAvailable == seatsBought)
		packetAvailable = false;
}

Packet::Packet(string packet)
{
	int maximo, vendido;
	bool valido = true;
	packetAvailable = true;

	if (stoi(packet.substr(0, packet.find_first_of('\n'))) < 0)
		packetAvailable = false;

	id = abs(stoi(packet.substr(0, packet.find_first_of('\n'))));
	packet.erase(0, packet.find_first_of('\n') + 1);

	sites = sitesFromString(packet.substr(0, packet.find_first_of('\n')));
	packet.erase(0, packet.find_first_of('\n') + 1);

	setBeginDate(packet.substr(0, packet.find_first_of('\n')));
	packet.erase(0, packet.find_first_of('\n') + 1);

	setEndDate(packet.substr(0, packet.find_first_of('\n')));
	packet.erase(0, packet.find_first_of('\n') + 1);

	pricePerPerson = stoi(packet.substr(0, packet.find_first_of('\n')));
	packet.erase(0, packet.find_first_of('\n') + 1);

	seatsAvailable = stoi(packet.substr(0, packet.find_first_of('\n')));
	packet.erase(0, packet.find_first_of('\n') + 1);

	seatsBought = stoi(packet.substr(0, packet.find_first_of('\n')));
	packet.erase(0, packet.find_first_of('\n') + 1);

	nextId += 1;

	
}

  // metodos GET

unsigned Packet::getId() const{

	return id;
}

vector<string> Packet::getSites() const{

	return sites;
}

string Packet::getAllSites() const
{
	string content;
	for (int i = 0; i < sites.size(); i++)
	{
		if (i == 0)
			content += sites[i] + " - ";

		else if (i != sites.size() - 1)
			content += sites[i] + ", ";
		else
			content += sites[i];
	}

	return content;
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

unsigned Packet::getSeatsAvailable() const
{
	return seatsAvailable;
}

unsigned Packet::getSeatsBought() const
{
	return seatsBought;
}

string Packet::getContent() const
{
	string content;
	if (packetAvailable)
		content += to_string(id) + '\n';
	else
		content += to_string(-int(id)) + '\n';

	content += sites[0] + " - ";
	for (int i = 1; i < sites.size() - 1; i++)
		content += sites[i] + ", ";
	content += sites[sites.size() - 1] + '\n';

	content += begin.getContent() + end.getContent();
	content += to_string(pricePerPerson) + '\n';
	content += to_string(seatsAvailable) + '\n';
	content += to_string(seatsBought) + '\n';
	
	return content;
}

bool Packet::getPacketAvailable() const
{
	return packetAvailable;
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

void Packet::setSeatsAvailable(unsigned seatsAvailable)
{
	this->seatsAvailable = seatsAvailable;

	if (seatsAvailable == seatsBought)
		packetAvailable = false;
}

void Packet::setSeatsBought(unsigned seatsBought)
{
	this->seatsBought = seatsBought;

	if (seatsAvailable == seatsBought)
		packetAvailable = false;
}



void Packet::show() const
{
	if (!packetAvailable)
		cout << to_string(-int(id)) << endl;

	else
		cout << id << endl;

	if (sites.size() != 0)
	{

		cout << sites[0] << " - ";
		for (int i = 1; i < sites.size() - 1; i++)
			cout << sites[i] << ", ";
		cout << sites[sites.size() - 1] << endl;
	}

	else if (sites.size() == 0)
		cout << sites[0] << endl;
	begin.show();
	end.show();
	cout << pricePerPerson << endl << seatsAvailable << endl << seatsBought << endl;
	
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

