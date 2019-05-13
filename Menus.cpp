#include "Menus.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

void changeClient(int i)
{
	int menuChecker, NIF, familySize, doorNumber;
	string name, street, postalCode, location, floor;
	bool checkNIF = true;

	while (true)
	{
		cout << endl << "1. Alterar o nome" << endl;
		cout << "2. Alterar o NIF" << endl;
		cout << "3. Alterar o número de pessoas no agregado familiar" << endl;
		cout << "4. Alterar a morada" << endl;
		cout << "0. Voltar atrás" << endl;

		cin >> menuChecker;

		if (menuChecker == 1)
		{
			cout << "Nome do cliente: ";
			getline(cin, name);
			vclients[i].setName(name);
		}

		else if (menuChecker == 2)
		{
			while (checkNIF)
			{
				cout << "NIF: ";
				cin >> NIF;
				while (cin.fail())
				{
					cin >> NIF;
				}

				for (int i = 0; i < vclients.size(); i++)
				{
					if (vclients[i].getVATnumber() == NIF)
					{
						cout << "NIF ja existe. " << endl;
						break;
					}

					else if (i == vclients.size() - 1)
						checkNIF = false;
				}


			}

			vclients[i].setVATnumber(NIF);
		}

		else if (menuChecker == 3)
		{
			cout << "Numero de pessoas no agragado familiar: ";
			cin >> familySize;

			while (cin.fail())
			{
				cout << "Numero invalido. Insira novamente: ";
				cin >> familySize;
			}

			vclients[i].setFamilySize(familySize);
		}

		else if (menuChecker == 4)
		{
			cout << "Rua: ";
			getline(cin, street);
			while (cin.fail())
			{
				getline(cin, street);
			}

			cout << "Numero da porta: ";
			cin >> doorNumber;
			while (cin.fail())
			{
				cin >> doorNumber;
			}

			cout << "Andar: ";
			cin >> floor;

			cout << "Codigo postal(xxxx-yyy): ";
			getline(cin, postalCode);
			while (!postalCodeChecker(postalCode))
			{
				cout << "Codigo postal invalido. Insira novamente(xxxx-yyy): ";
				getline(cin, postalCode);
			}

			cout << "Localidade: ";
			getline(cin, location);

			Address address(street, doorNumber, floor, postalCode, location);
		}

		else if (menuChecker == 0)
			break;

		else
			cout << "Codigo invalido." << endl;
	}
}

void clientsMenu()
{
	int checker_clients, i = 0;
	string street, floor, postalCode, location, name;
	unsigned short doorNumber, familySize;
	unsigned VATnumber;
	bool checkNIF = true;

	while (true)
	{
		cout << "1. Dados de todos os clientes" << endl;
		cout << "2. Dados de um cliente" << endl;
		cout << "3. Adicionar clientes" << endl;
		cout << "4. Remover clientes" << endl;
		cout << "5. Alterar clientes" << endl;
		cout << "6. Comprar pacote" << endl;
		cout << "0. Voltar" << endl;
		cin >> checker_clients;
		
		if (checker_clients == 1)
		{
			i = 0;
			while (i < vclients.size())
			{
				vclients[i].show();
				if (i < (vclients.size() - 1))
				{
					cout << "::::::::::" << endl;
				}
				i++;
			}
		}

		else if (checker_clients == 2)
		{
			unsigned NIF;
			cout << "NIF do cliente: ";
			cin >> NIF;

			getClientFromNIF(NIF).show();
		}


		else if (checker_clients == 3)
		{
			cout << "Nome: ";
			cin.ignore(1000, '\n');
			getline(cin, name);

			while (checkNIF)
			{
				cout << "NIF: ";
				cin >> VATnumber;
				while (cin.fail() || (VATnumber < 100000000 || VATnumber > 999999999))
				{
					cout << "Dados invalidos" << endl;
					cout << "NIF: ";
					cin.clear();
					cin.ignore(1000000000, '\n');
					cin >> VATnumber;
				}

				for (int i = 0; i < vclients.size(); i++)
				{
					if (vclients[i].getVATnumber() == VATnumber)
					{
						cout << "NIF ja existe. " << endl;
						break;
					}

					else if (i == vclients.size() - 1)
						checkNIF = false;
				}


			}

			
			cout << "Numero de agregado familiar: ";
			cin >> familySize;
			while (cin.fail() || familySize < 0)
			{
				cout << "Dados invalidos" << endl << "Numero de agregado familiar: ";
				cin.clear();
				cin.ignore(10000000, '\n');
				cin >> familySize;
			}
			
			cout << "Rua: ";
			cin.ignore(1000, '\n');
			getline(cin, street);
			while (cin.fail())
			{
				getline(cin, street);
			}
			
			cout << "Numero da porta: ";
			cin >> doorNumber;
			while (cin.fail() || doorNumber < 0)
			{
				cout << "Dados invalidos" << endl << "Numero da porta: ";
				cin.clear();
				cin.ignore(10000000, '\n');
				cin >> doorNumber;
			}
			
			cout << "Andar: ";
			cin >> floor;
			
			cout << "Codigo postal(xxxx-yyy): ";
			cin.ignore(1000000, '\n');
			getline(cin, postalCode);
			while (!postalCodeChecker(postalCode))
			{
				cout << "Dados invalidos" << endl << "Codigo postal(xxxx-yyy): ";
				cin.clear();
				getline(cin, postalCode);
			}

			cout << "Localidade: ";
			getline(cin, location);

			Address address(street, doorNumber, floor, postalCode, location);
			Client client(name, VATnumber, familySize, address);

			vclients.push_back(client);

		}

		else if (checker_clients == 4)
		{
			unsigned NIF;
			cout << "NIF do cliente: ";
			cin >> NIF;
			
			for (unsigned i = 0; i < vclients.size(); i++)
			{
				if (vclients[i].getVATnumber() == NIF)
				{
					vclients.erase(vclients.begin() + i);
					cout << "Cliente apagado" << endl;
					break;
				}
				else if (i == vclients.size() - 1)
					cout << "Dados invalidos" << endl;
			}
		}

		else if (checker_clients == 5)
		{
			unsigned NIF;
			cout << "NIF do cliente: ";
			cin >> NIF;

			for (unsigned i = 0; i < vclients.size(); i++)
			{
				if (vclients[i].getVATnumber() == NIF)
				{
					changeClient(i);
					break;
				}
				else if (i == vclients.size() - 1)
					cout << "Cliente nao encontrado." << endl;
			}
		}

		else if (checker_clients == 6)
		{
			unsigned NIF;
			cout << "NIF do cliente: ";
			cin >> NIF;

			while (cin.fail())
			{
				cin >> NIF;
			}

			for (unsigned i = 0; i < vclients.size(); i++)
			{
				if (vclients[i].getVATnumber() == NIF)
				{

					unsigned packet;
					cout << "Numero do pacote: ";
					cin >> packet;

					while (cin.fail())
					{
						cin >> packet;
					}

					vclients[i].buyPacket(packet);
				}
				else if (i == vclients.size() - 1)
					cout << "Cliente nao encontrado." << endl;
			}

		}

		else if (checker_clients == 0)
			break;

		else 
		cout << "Codigo invalido." << endl;
	}

}

void packetsMenu()
{
	int menuChecker;
	vector<Packet> orderedPackets;

	while (true)
	{
		cout << endl << "1. Ordenar por data" << endl;
		cout << "2. Entre duas datas" << endl;
		cout << "3. Procurar por local turistico" << endl;
		cout << "4. Ver dados de 1 pacote" << endl;
		cout << "5. Adicionar um pacote" << endl;
		cout << "0. Voltar atras" << endl;

		cin >> menuChecker;

		if (menuChecker == 1)
		{
			for (unsigned i = 0; i < vpackets.size(); i++)
			{
				if (orderedPackets.size() == 0)
					orderedPackets.push_back(vpackets[i]);

				else
				{
					for (unsigned x = 0; x < orderedPackets.size(); x++)
					{
						if (vpackets[i].getBeginDate().isBefore(orderedPackets[x].getBeginDate()))
						{
							orderedPackets.insert(orderedPackets.begin() + x, vpackets[i]);
							break;
						}

						else if (x == orderedPackets.size() - 1)
						{
							orderedPackets.push_back(vpackets[i]);
							break;
						}
					}
				}
			}

			for (unsigned i = 0; i < orderedPackets.size(); i++)
			{
				orderedPackets[i].show();

				if (i < orderedPackets.size() - 1)
					cout << "::::::::::" << endl;
			}
		}

		else if (menuChecker == 2)
		{
			vector<Packet> showPackets;
			string date;
			cout << "Insira data inicial(AAAA/MM/DD): ";
			cin >> date;
			Date begin(date);

			cout << "Insira data final(AAAA/MM/DD): ";
			cin >> date;
			Date end(date);

			for (unsigned i = 0; i < vpackets.size(); i++)
			{
				if (vpackets[i].getBeginDate().isAfter(begin) && vpackets[i].getEndDate().isBefore(end))
					showPackets.push_back(vpackets[i]);
			}

			if (showPackets.size() == 0)
				cout << "Nenhum pacote encontrado." << endl;

			for (unsigned i = 0; i < showPackets.size(); i++)
			{
				showPackets[i].show();

				if (i < showPackets.size() - 1)
					cout << "::::::::::" << endl;
			}
		}

		else if (menuChecker == 3)
		{
			string location;
			int counter = 0;

			cin.ignore(1000, '\n');

			cout << "Local turistico: ";
			getline(cin, location);

			for (unsigned i = 0; i < vpackets.size(); i++)
			{
				if (vpackets[i].searchLocation(location))
				{
					vpackets[i].show();
					counter++;
				}
			}

			if (counter == 0)
				cout << "Nenhum pacote tem este local turistico." << endl;
		}

		else if (menuChecker == 4)
		{
			int packetId;

			cout << "Id do pacote: ";
			cin >> packetId;

			while (cin.fail())
			{
				cout << "Id invalido. Insira novamente: ";
				cin >> packetId;
			}

			for (unsigned i = 0; i < vpackets.size(); i++)
			{
				if (vpackets[i].getId() == packetId)
				{
					vpackets[i].show();	
					break;
				}

				else if (i == vpackets.size() - 1)
					cout << "Pacote nao encontrado." << endl;
			}
		}

		else if (menuChecker == 5)
		{
			string sites, sbegin, send;
			unsigned pricePerPerson, seatsAvailable, seatsBought;

			cout << "Locais de destino: ";
			cin.ignore(1000, '\n');
			getline(cin, sites);

			cout << "Data de inicio (AAAA/MM/DD): ";
			getline(cin, sbegin);
			Date begin(sbegin);

			cout << "Data de fim (AAAA/MM/DD): ";
			getline(cin, send);
			Date end(send);

			cout << "Preco por pessoa: ";
			cin >> pricePerPerson;

			cout << "Numero de lugares total: ";
			cin >> seatsAvailable;

			cout << "Numero de lugares vendidos: ";
			cin >> seatsBought;

			vector<string> vsites = sitesFromString(sites);

			Packet packet(vsites, begin, end, pricePerPerson, seatsAvailable, seatsBought);
			vpackets.push_back(packet);
		}

		else if (menuChecker == 0)
		break;

		else
		cout << "Codigo nao aceite." << endl;
	}
}

void mainMenu(Agency agency)
{

	int checker;
	while (true)
	{
		cout << "1. Dados da Agencia" << endl;
		cout << "2. Clientes" << endl;
		cout << "3. Pacotes" << endl;
		cout << "0. Sair" << endl;
		cin >> checker;
		if (checker == 1)
		{
			agency.show();
		}
		else if (checker == 2)
		{
			clientsMenu();
		}
		else if (checker == 3)
		{
			packetsMenu();
		}
		else if (checker == 0)
		{
			break;
		}
		else
			cout << "Dados invalidos" << endl;
	}
}
    
