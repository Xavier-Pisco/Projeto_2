#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>


#include "Agency.h"
#include "Menus.h"
#include "Client.h"
// #include "utils.h"

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
	Agency agency(AGENCY_FILE_NAME);   // create the agency

	agency.show();

	

  //mainMenu(agency); // initial menu inicial with the major options of the application
  
	return 0;
}
