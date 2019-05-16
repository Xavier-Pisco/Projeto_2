#include "Client.h"


	//Construtores

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address){
	
	this->name = name;
	this->VATnumber = VATnumber;
	this->familySize = familySize;
	this->address = address;
	vector<int> packets(0);
	setPacketList(packets);
	totalPurchased = 0;
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<int> packets, unsigned totalPurchased){
  
	this->name = name;
	this->VATnumber = VATnumber;
	this->familySize = familySize;
	this->address = address;
	this->packets = packets;
	this->totalPurchased = totalPurchased;
}

Client::Client(string client)
{
	name = trim(client.substr(0, client.find_first_of('\n')));
	client.erase(0, client.find_first_of('\n') + 1);

	VATnumber = stoi(client.substr(0, client.find_first_of('\n')));
	client.erase(0, client.find_first_of('\n') + 1);

	familySize = stoi(client.substr(0, client.find_first_of('\n')));
	client.erase(0, client.find_first_of('\n') + 1);

	setAddress(client.substr(0, client.find_first_of('\n')));
	client.erase(0, client.find_first_of('\n') + 1);

	setPacketList(client.substr(0, client.find_first_of('\n')));
	client.erase(0, client.find_first_of('\n') + 1);

	totalPurchased = stoi(client.substr(0, client.find_first_of('\n')));
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

vector<int> Client::getPacketList() const{
  
	return packets;
}

unsigned Client::getTotalPurchased() const{
  
	return totalPurchased;
}

string Client::getPacketsIds() const
{
	if (packets.size() == 0)
		return "\n";

	string content;
	for (int i = 0; i < packets.size() - 1; i++)
		content += packets[i] + " ; ";
	content += packets[packets.size() - 1];
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

void Client::setPacketList(vector<int> packets){
  
	this->packets = packets;
}

void Client::setPacketList(string packets)
{
	while (packets.find_first_of(';') != packets.npos)
	{
		this->packets.push_back(stoi(packets.substr(0, packets.find_first_of(';') - 1)));
		packets.erase(0, packets.find_first_of(';') + 2);
	}
	this->packets.push_back(stoi(packets.substr(0, packets.npos)));
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

		if (packets.size() == 0)
			cout << "\n";

		else
		{
			for (int i = 0; i < packets.size() - 1; i++)
				cout << packets[i] << " ; ";
			cout << packets[packets.size() - 1] << endl;
		}
		cout << totalPurchased << endl;
}

void Client::buyPacket(int packetId)
{
	Packet packet = getPacketFromId(packetId);

	if (checkIfPacketExist(packetId))
	{

		if (packets.size() == 0)
		{
			for (unsigned i = 0; i < vpackets.size(); i++)
			{
				if (vpackets[i].getId() == packetId)
				{
					if (packet.getPacketAvailable())
					{
						this->totalPurchased += int(round(this->familySize * packet.getPricePerPerson()));
						this->packets.push_back(packetId);
						for (int x = 0; x < vpackets.size(); x++)
						{
							if (packetId == vpackets[x].getId())
								vpackets[x].setSeatsBought(vpackets[x].getSeatsBought() + familySize);
						}					cout << "Compra efetuada" << endl;
					}
					else
						cout << "Pacote nao tem mais lugares disponiveis" << endl;

					break;

				}

				else if (i == vpackets.size() - 1)
					cout << "Pacote nao encontrado" << endl;
			}
		}
		else
		{
			for (unsigned i = 0; i < packets.size(); i++)
			{
				if (packets[i] == packetId)
				{
					cout << "Ja comprou lugar neste pacote" << endl;
					break;
				}

				else if (i == packets.size() - 1)
				{
					for (unsigned i = 0; i < vpackets.size(); i++)
					{
						if (vpackets[i].getId() == packetId)
						{
							if (packet.getPacketAvailable())
							{
								this->totalPurchased += int(round(this->familySize * packet.getPricePerPerson()));
								this->packets.push_back(packetId);
								for (int x = 0; x < vpackets.size(); x++)
								{
									if (packetId == vpackets[x].getId())
										vpackets[x].setSeatsBought(vpackets[x].getSeatsBought() + familySize);
								}
								cout << "Compra efetuada" << endl;
							}
							else
								cout << "Pacote nao tem mais lugares disponiveis" << endl;

							break;

						}

						else if (i == vpackets.size() - 1)
							cout << "Pacote nao encontrado" << endl;
					}
					break;
				}
			}
		}
	}
}

vector<Client> vclients;

//ostream& operator<<(ostream& out, const Client & client){
//
//  // REQUIRES IMPLEMENTATION 
//
//}

