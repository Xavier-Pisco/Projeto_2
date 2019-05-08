#include <iostream>
#include <string>
#include <vector>

#include <fstream>
#include <iomanip>

#include "defs.h"
#include "Agency.h"
#include "Menus.h"
#include "Client.h"
// #include "utils.h"
using namespace std;

Packet getPacketFromId(const unsigned packetId)
{
	for (unsigned i = 0; i < vpackets.size(); i++)
	{
		if (vpackets[i].getId() == packetId)
		{
			return vpackets[i];
		}

		else if (i == vpackets.size() - 1)
			cout << "Pacote não encontrado." << endl;
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
	cout << "agency file: ";
	cin >> AGENCY_FILE_NAME;
	Agency agency(AGENCY_FILE_NAME);   // create the agency

	openClientsFile(agency.getClientsFilename());

	openPacketsFile(agency.getPacketsFilename());
	
	mainMenu(agency);

	

  //mainMenu(agency); // initial menu inicial with the major options of the application
  
	return 0;
}
