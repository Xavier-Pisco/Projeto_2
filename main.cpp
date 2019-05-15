#include "defs.h"
#include "Agency.h"
#include "Menus.h"
#include "Client.h"
using namespace std;

bool(checkIfDateIsPossible(string date))
{
	int count = 0;
	for (int i = 0; i < date.size(); i++)
	{
		if (date[i] == '/')
			count += 1;
	}

	if (count != 2)
		return false;

	Date data(date);

	if (data.isValid())
		return true;

	return false;
}

bool checkIfPacketExist(const unsigned packetId)
{
	for (unsigned i = 0; i < vpackets.size(); i++)
	{
		if (vpackets[i].getId() == packetId)
		{
			return true;
		}
	}
	return false;
}

bool checkIfClientExist(const unsigned NIF)
{
	for (unsigned i = 0; i < vclients.size(); i++)
	{
		if (vclients[i].getVATnumber() == NIF)
		{
			return true;
		}
	}

	return false;
}

map<string, unsigned> mapMostVisited()
{	
	map<string, unsigned> mostVisited;

	for (unsigned i = 0; i < vpackets.size(); i++)
	{
		mostVisited[vpackets[i].getAllSites()] += vpackets[i].getSeatsBought();
	}

	/*for (int i = 0; i < vclients.size(); i++)
	{
		for (int x = 0; x < vclients[i].getPacketList().size(); x++)
		{
			if (checkIfPacketExist(vclients[i].getPacketList()[x]))
			{
				Packet packet = getPacketFromId(vclients[i].getPacketList()[x]);

				mostVisited[packet.getAllSites()] = 0;
				
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

				mostVisited[packet.getAllSites()] += 1;

			}
		}
	}*/

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
			cout << "Cliente nao encontrado" << endl;
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
	int agency_line_checker = 0;
	ifstream agency_file_name;
	string AGENCY_FILE_NAME, checking_agency = "", line_agency_file;
	cout << "Nome do ficheiro da agencia: ";
	cin >> AGENCY_FILE_NAME;
	agency_file_name.open(AGENCY_FILE_NAME);
	while (getline(agency_file_name, line_agency_file))
	{
		if (agency_line_checker == 4)
		{
			checking_agency = line_agency_file;
		}
		agency_line_checker++;
	}
	while (checking_agency == "")
	{
		agency_line_checker = 0;
		agency_file_name.close();
		cout << "Ficheiro nao encontrado" << endl << endl << "Nome do ficheiro da agencia: ";
		cin >> AGENCY_FILE_NAME;
		agency_file_name.open(AGENCY_FILE_NAME);
		while (getline(agency_file_name, line_agency_file))
		{
			if (agency_line_checker == 4)
			{
				checking_agency = line_agency_file;
			}
			agency_line_checker++;
		}
	}
	agency_file_name.close();
	cout << endl << setfill('*') << setw(30) << "" << endl << endl;
	Agency agency(AGENCY_FILE_NAME);   // create the agency

	openClientsFile(agency.getClientsFilename());

	openPacketsFile(agency.getPacketsFilename());
	
	mainMenu(agency);

	

  //mainMenu(agency); // initial menu inicial with the major options of the application
  
	return 0;
}
