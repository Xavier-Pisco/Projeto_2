#include <iostream>
#include <string>
#include <vector>

#include <fstream>
#include <iomanip>
#include <map>

#include "defs.h"
#include "Agency.h"
#include "Menus.h"
#include "Client.h"
// #include "utils.h"
using namespace std;


bool checkIfPacketExist(const unsigned packetId)
{
	for (unsigned i = 0; i < vpackets.size(); i++)
	{
		if (vpackets[i].getId() == packetId)
		{
			return true;
		}

		else if (i == vpackets.size() - 1)
			return false;
	}
}

map<string, unsigned> mapMostVisited()
{	
	map<string, unsigned> mostVisited;

	for (int i = 0; i < vclients.size(); i++)
	{
		for (int x = 0; x < vclients[i].getPacketList().size(); x++)
		{
			if (checkIfPacketExist(vclients[i].getPacketList()[x]))
			{
				Packet packet = getPacketFromId(vclients[i].getPacketList()[x]);

				for (int a = 0; a < packet.getSites().size(); a++)
				{
					mostVisited[packet.getSites()[a]] = 0;
				}
			}

		}
	}

	for (int i = 0; i < vclients.size(); i++)
	{
		for (int x = 0; x < vclients[i].getPacketList().size(); x++)
		{
			if (checkIfPacketExist(vclients[i].getPacketList()[x]))
			{
				Packet packet = getPacketFromId(vclients[i].getPacketList()[x]);

				for (int a = 0; a < packet.getSites().size(); a++)
				{
					mostVisited[packet.getSites()[a]] += 1;
				}
			}
		}
	}

	return mostVisited;
}


vector<string> sitesFromString(string sites)
{
	vector<string> vsites;

	if (sites.find_first_of('-') == sites.npos)
		vsites.push_back(trim(sites));

	else
	{
		vsites.push_back(trim(sites.substr(0, sites.find_first_of('-') - 1)));
		sites.erase(0, sites.find_first_of('-') + 1);

		while (sites.find_first_of(',') != sites.npos)
		{
			vsites.push_back(trim(sites.substr(0, sites.find_first_of(','))));
			sites.erase(0, sites.find_first_of(',') + 1);
		}
		vsites.push_back(trim(sites));
	}
	return vsites;
}

string trim(string str)
{
	if (str[0] == ' ')
		str.erase(0, str.find_first_not_of(' '));

	str.erase(str.find_last_not_of(' ') + 1, str.npos);

	return str;
}

bool stringIsNumber(string str)
{
	int count = 0;
	for (int i = 0; i <= str.size(); i++)
	{
		if (isdigit(str[i]))
			count += 1;
	}
	if (count == str.size())
		return true;

	return false;
}

Packet getPacketFromId(const unsigned packetId)
{
	for (unsigned i = 0; i < vpackets.size(); i++)
	{
		if (vpackets[i].getId() == packetId)
		{
			return vpackets[i];
		}

		else if (i == vpackets.size() - 1)
			cout << "Pacote nao encontrado" << endl;
	}
}

Client getClientFromNIF(const unsigned clientNIF)
{
	for (unsigned i = 0; i < vclients.size(); i++)
	{
		if (vclients[i].getVATnumber() == clientNIF)
		{
			return vclients[i];
		}

		else if (i == vclients.size() - 1)
			cout << "Cliente nao encontrado." << endl;
	}
}


void openClientsFile(string filename)
{
	string input, clientContent;
	ifstream f;
	f.open(filename);

	while (getline(f, input))
	{
		if (input != "::::::::::")
		{
			clientContent += input + '\n';
		}

		else
		{
			Client client(clientContent);
			vclients.push_back(client);
			clientContent = "";
		}
	}
	Client client(clientContent);
	vclients.push_back(client);
	f.close();
	clientContent = "";
}


void openPacketsFile(string filename)
{
	string input, packetContent;
	ifstream f;
	f.open(filename);

	getline(f, input);

	while (getline(f, input))
	{
		if (input != "::::::::::")
			packetContent += input + '\n';

		else
		{
			Packet packet(packetContent);
			vpackets.push_back(packet);
			packetContent = "";
		}
	}
	Packet packet(packetContent);
	vpackets.push_back(packet);
	packetContent = "";
}



int main(){
	string AGENCY_FILE_NAME;
	cout << "Agency file: ";
	cin >> AGENCY_FILE_NAME;
	Agency agency(AGENCY_FILE_NAME);   // create the agency

	openClientsFile(agency.getClientsFilename());

	openPacketsFile(agency.getPacketsFilename());
	
	mainMenu(agency);

	

  //mainMenu(agency); // initial menu inicial with the major options of the application
  
	return 0;
}
