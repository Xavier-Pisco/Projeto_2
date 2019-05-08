#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>

#include "Agency.h"
#include "Menus.h"
#include "Client.h"
// #include "utils.h"
using namespace std;

vector<Client> vclients;
vector<Packet> vpacket;

//void openClientsFile(string filename)
//{
//	stringstream ssClient;
//	string input;
//	ifstream f;
//	f.open(filename);
//
//	while (getline(f, input))
//	{
//		if (input == "::::::::::")
//		{
//			Client client(ssClient);
//			vclients.push_back(client);
//		}
//
//		ssClient = input + '\n';
//
//	}
//
//
//}

int main(){
	string AGENCY_FILE_NAME;
	cin >> AGENCY_FILE_NAME;
	Agency agency(AGENCY_FILE_NAME);   // create the agency

	mainMenu(agency);

	

  //mainMenu(agency); // initial menu inicial with the major options of the application
  
	return 0;
}
