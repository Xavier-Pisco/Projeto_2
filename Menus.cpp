#include "Menus.h"
#include <algorithm>

void changeClient(int i)
{
	int menuChecker, NIF, familySize, doorNumber;
	string name, street, postalCode, location, floor;
	bool checkNIF = true;

	while (true)
	{
		cout << "[1] Alterar o nome" << endl;
		cout << "[2] Alterar o NIF" << endl;
		cout << "[3] Alterar o número de pessoas no agregado familiar" << endl;
		cout << "[4] Alterar a morada" << endl;
		cout << "[0] Voltar atrás" << endl;

		cin >> menuChecker;

		if (cin.fail())
		{
			cout << "Dados invalidos" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		else if (menuChecker == 1)
		{
			cout << "Nome do cliente: ";
			cin.ignore(1000, '\n');
			getline(cin, name);
			vclients[i].setName(name);
		}

		else if (menuChecker == 2)
		{
			while (checkNIF)
			{
				cout << "NIF: ";
				cin >> NIF;
				while (cin.fail() || NIF < 100000000 || NIF > 999999999)
				{
					cout << "Dados invalidos" << endl << "NIF: ";
					cin.clear();
					cin.ignore(1000000, '\n');
					cin >> NIF;
				}

				for (int x = 0; x < vclients.size(); x++)
				{
					if (vclients[x].getVATnumber() == NIF)
					{
						cout << "NIF ja existente " << endl;
						break;
					}

					else if (x == vclients.size() - 1)
						checkNIF = false;
				}


			}

			vclients[i].setVATnumber(NIF);
			checkNIF = true;
		}

		else if (menuChecker == 3)
		{
			cout << "Numero de pessoas no agregado familiar: ";
			cin >> familySize;

			while (cin.fail())
			{
				cout << "Dados invalidos" << endl << "Numero de pessoas no agregado familiar: ";
				cin.clear();
				cin.ignore(100000000, '\n');
				cin >> familySize;
			}

			vclients[i].setFamilySize(familySize);
		}

		else if (menuChecker == 4)
		{
			cout << "Rua: ";
			cin.ignore(1000, '\n');
			getline(cin, street);
			while (cin.fail())
			{
				getline(cin, street);
			}

			cout << "Numero da porta: ";
			cin >> doorNumber;
			while (cin.fail())
			{
				cout << "Dados invalidos" << endl << "Numero da porta: ";
				cin.clear();
				cin.ignore(10000000, '\n');
				cin >> doorNumber;
			}

			cout << "Andar: ";
			cin >> floor;

			cout << "Codigo postal(xxxx-yyy): ";
			getline(cin, postalCode);
			while (!postalCodeChecker(postalCode))
			{
				cout << "Dados invalidos" << endl << "Codigo postal(xxxx-yyy): ";
				getline(cin, postalCode);
			}

			cout << "Localidade: ";
			getline(cin, location);

			Address address(street, doorNumber, floor, postalCode, location);
			vclients[i].setAddress(address);
		}

		else if (menuChecker == 0)
			break;

		else
			cout << "Dados invalidos" << endl;
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
		cout << "[1] Dados de todos os clientes" << endl;
		cout << "[2] Dados de um cliente" << endl;
		cout << "[3] Adicionar clientes" << endl;
		cout << "[4] Remover clientes" << endl;
		cout << "[5] Alterar clientes" << endl;
		cout << "[6] Comprar pacote" << endl;
		cout << "[7] Ver locais recomendados para um cliente" << endl;
		cout << "[0] Voltar" << endl;
		cin >> checker_clients;

		if (cin.fail())
		{
			cout << "Dados invalidos" << endl << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		
		else if (checker_clients == 1)
		{
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
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
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
		}

		else if (checker_clients == 2)
		{
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
			unsigned NIF;
			cout << "NIF do cliente: ";
			cin >> NIF;

			while (cin.fail())
			{
				cout << "Dados invalidos \n" << endl << "NIF do cliente: ";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> NIF;
			}

			if (checkIfClientExist(NIF))
			{
				getClientFromNIF(NIF).show();
			}
			else
			{
				cout << "Cliente nao encontrado" << endl;
			}
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
			
		}

		else if (checker_clients == 3)
		{
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
			cout << "Nome: ";
			cin.ignore(1000, '\n');
			getline(cin, name);

			while (checkNIF)
			{
				cout << "NIF: ";
				cin >> VATnumber;
				while (cin.fail() || (VATnumber < 100000000 || VATnumber > 999999999))
				{
					cout << "Dados invalidos" << endl << endl;
					cout << "NIF: ";
					cin.clear();
					cin.ignore(1000000000, '\n');
					cin >> VATnumber;
				}

				for (int i = 0; i < vclients.size(); i++)
				{
					if (vclients[i].getVATnumber() == VATnumber)
					{
						cout << "NIF ja existente " << endl << endl;
						break;
					}

					else if (i == vclients.size() - 1)
						checkNIF = false;
				}


			}
			cin.clear();
			cin.ignore(1000000, '\n');

			
			cout << "Numero de agregado familiar: ";
			cin >> familySize;
			while (cin.fail() || familySize < 0)
			{
				cout << "Dados invalidos" << endl << endl << "Numero de agregado familiar: ";
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
				cout << "Dados invalidos" << endl << endl << "Numero da porta: ";
				cin.clear();
				cin.ignore(10000000, '\n');
				cin >> doorNumber;
			}
			cin.clear();
			cin.ignore(10000, '\n');
			
			cout << "Andar: ";
			cin >> floor;
			
			cout << "Codigo postal(xxxx-yyy): ";
			cin.ignore(1000000, '\n');
			getline(cin, postalCode);
			while (!postalCodeChecker(postalCode))
			{
				cout << "Dados invalidos" << endl << endl << "Codigo postal(xxxx-yyy): ";
				cin.clear();
				getline(cin, postalCode);
			}

			cout << "Localidade: ";
			getline(cin, location);

			Address address(street, doorNumber, floor, postalCode, location);
			Client client(name, VATnumber, familySize, address);

			vclients.push_back(client);
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;

		}

		else if (checker_clients == 4)
		{
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
			unsigned NIF;
			cout << "NIF do cliente: ";
			cin >> NIF;

			while (cin.fail())
			{
				cout << "Dados invalidos \n" << endl << "NIF do cliente: ";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> NIF;
			}
			
			for (unsigned i = 0; i < vclients.size(); i++)
			{
				if (vclients[i].getVATnumber() == NIF)
				{
					vclients.erase(vclients.begin() + i);
					cout << "Cliente apagado" << endl;
					break;
				}
				else if (i == vclients.size() - 1)
					cout << "Cliente inexistente" << endl;
			}
			cin.clear();
			cin.ignore(1000000, '\n');
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
		}

		else if (checker_clients == 5)
		{
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
			unsigned NIF;
			cout << "NIF do cliente: ";
			cin >> NIF;

			while (cin.fail())
			{
				cout << "Dados invalidos \n" << endl << "NIF do cliente: ";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> NIF;
			}

			for (unsigned i = 0; i < vclients.size(); i++)
			{
				if (vclients[i].getVATnumber() == NIF)
				{
					cout << endl << setfill('*') << setw(30) << "" << endl << endl;
					cin.clear();
					cin.ignore(100000, '\n');
					changeClient(i);

					break;
				}
				else if (i == vclients.size() - 1)
					cout << "Cliente inexistente" << endl;
			}
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
		
		}

		else if (checker_clients == 6)
		{
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
			unsigned NIF;
			cout << "NIF do cliente: ";
			cin >> NIF;

			while (cin.fail() || NIF < 10000000 || NIF > 999999999)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Dados invalidos" << endl << endl << "NIF do cliente: ";
				cin >> NIF;
			}

			for (unsigned i = 0; i < vclients.size(); i++)
			{
				if (vclients[i].getVATnumber() == NIF)
				{

					cin.clear();
					cin.ignore(10000, '\n');
					unsigned packet;
					cout << "Numero do pacote: ";
					cin >> packet;

					while (cin.fail())
					{
						cin >> packet;
					}

					vclients[i].buyPacket(packet);
					break;
				}
				else if (i == vclients.size() - 1)
					cout << "Cliente nao encontrado" << endl;
			}
			cin.clear();
			cin.ignore(100000, '\n');
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;

		}

		else if (checker_clients == 7)
		{
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
			unsigned NIF;
			cout << "NIF do cliente: ";
			cin >> NIF;

			while (cin.fail())
			{
				cout << "Dados invalidos \n" << endl << "NIF do cliente: ";
				cin.clear();
				cin.ignore(10000, '\n');
				cin >> NIF;
			}

			cin.clear();
			cin.ignore(10000, '\n');
			unsigned numero;
			cout << "Numero maximo de recomendacoes: ";
			cin >> numero;

			while (cin.fail())
			{
				cout << "Dados invalidos \n" << endl << "Numero maximo de recomendacoes: ";
				cin.clear();
				cin.ignore(100000, '\n');
				cin >> numero;
			}
			cin.clear();
			cin.ignore(100000, '\n');

			vector<int> packets = getClientFromNIF(NIF).getPacketList();

			map<string, unsigned> mostVisited = mapMostVisited(); // map com <local, nº lugares comprados>

			// função para ordenar o pair pelo numero de lugares comprados
			auto cmp = [](const auto & p1, const auto & p2)
			{
				if (p1.second >= p2.second)
					return p2.second < p1.second;

				return p1.first < p2.first;
			};

			// cria um set de pairs igual ao map
			set < pair<string, unsigned>, decltype(cmp)> s(mostVisited.begin(), mostVisited.end(), cmp);

			// elimina do set os locais que o cliente já visitou
			for (int i = 0; i < packets.size(); i++) //corre todos os pacotes
			{
				if (checkIfPacketExist(packets[i]))
				{
					Packet packet = getPacketFromId(packets[i]);

					for (auto i = s.begin(); i != s.end(); i++) //corre todos os pairs do set
					{
						if (packet.getAllSites() == i->first) //verifica se o local do par é o mesmo do pacote
						{
							s.erase(i);
							break;
						}
					}
				}
			}
			unsigned count = 0;

			// Dá print a N destinos que estão no set
			for (auto x = s.begin(); x != s.end(); x++) //corre todos os pairs do set
			{
				if (count < numero)
				{
					for (int i = 0; i < vpackets.size(); i++) //corre todos os pacotes
					{
						if (vpackets[i].getAllSites() == x->first) //verifica se o local do par é o mesmo do pacote
						{
							if (x->second > 1)
							{
								cout << "O pacote " << vpackets[i].getId() << ", com destino a \"" << x->first << "\" ja foi visitado por " << x->second << " clientes" << endl;
								count += 1;
							}
							else
							{
								cout << "O pacote " << vpackets[i].getId() << ", com destino a \"" << x->first << "\" ja foi visitado por " << x->second << " cliente" << endl;
								count += 1;
							}
						}
					}
				}
			}
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
		}

		else if (checker_clients == 0)
			break;

		else 
		cout << "Dados invalidos" << endl << endl;
	}

}

void changePacket(int i)
{
	unsigned menuChecker, pricePerPerson, seatsAvailable, seatsBought;
	string sites, sbegin, send;

	while (true)
	{
		cout << "[1] Alterar o destino" << endl;
		cout << "[2] Alterar a data de inicio" << endl;
		cout << "[3] Alterar a data de fim" << endl;
		cout << "[4] Alterar o preco por pessoa" << endl;
		cout << "[5] Alterar o numero de lugares total" << endl;
		cout << "[6] Alterar o numero de lugares vendidos" << endl;
		cout << "[0] Voltar" << endl;

		cin >> menuChecker;

		if (cin.fail())
		{
			cout << "Insira um numero" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		else if (menuChecker == 1)
		{
			cout << "Ecreva o destino: ";
			cin.ignore(1000, '\n');
			getline(cin, sites);

			vpackets[i].setSites(sitesFromString(sites));
		}

		else if (menuChecker == 2)
		{
			cout << "Escreva a data de inicio: ";
			cin.ignore(1000, '\n');
			getline(cin, sbegin);

			while (!checkIfDateIsPossible(sbegin))
			{
				cout << "Data invalida.\nInsira data inicial(AAAA/MM/DD): ";
				getline(cin, sbegin);
			}

			Date begin(sbegin);

			if (begin.isAfter(vpackets[i].getEndDate()))
				cout << "Data inicial nao pode ser posterior a data final" << endl;

			else
			{
				vpackets[i].setBeginDate(begin);
			}
		}

		else if (menuChecker == 3)
		{
			cout << "Escreva a data de fim: ";
			cin.ignore(1000, '\n');
			getline(cin, send);

			while (!checkIfDateIsPossible(send))
			{
				cout << "Data invalida.\nInsira data inicial(AAAA/MM/DD): ";
				getline(cin, send);
			}

			Date end(send);

			if (end.isBefore(vpackets[i].getBeginDate()))
				cout << "Data final nao pode anteceder a data inicial" << endl;

			else
			{
				vpackets[i].setBeginDate(end);
			}
		}

		else if (menuChecker == 4)
		{
			cout << "Escreva o preco por pessoa: ";
			cin >> pricePerPerson;

			while (cin.fail())
			{
				cout << "Dados invalidos" << "Insira o preco por pessoa novamente: ";
				cin.clear();
				cin >> pricePerPerson;
			}

			vpackets[i].setPricePerPerson(pricePerPerson);
		}

		else if (menuChecker == 5)
		{
			cout << "Escreva o numero de lugares total: ";
			cin >> seatsAvailable;

			while (cin.fail())
			{
				cout << "Dados invalidos" << endl << "Insira o numero de lugares total novamente: ";
				cin.clear();
				cin >> seatsAvailable;
			}

			while (seatsAvailable < vpackets[i].getSeatsBought())
			{
				cout << "Numeros de lugares total nao pode ser menor que o numero de lugares vendidos" << endl;
				cout << "Insira o numero de lugares total novamente: ";
				cin >> seatsAvailable;
			}

			vpackets[i].setSeatsAvailable(seatsAvailable);
		}

		else if (menuChecker == 6)
		{
			cout << "Escreva o numero de lugares vendidos: ";
			cin >> seatsBought;

			while (cin.fail())
			{
				cout << "Dados invalidos" << "Insira o numero de lugares vendidos novamente: ";
				cin.clear();
				cin >> seatsBought;
			}

			while (seatsBought < vpackets[i].getSeatsAvailable())
			{
				cout << "Numeros de lugares vendido nao pode ser maior que o numero de lugares total" << endl;
				cout << "Insira o numero de lugares vendido novamente: ";
				cin >> seatsBought;
			}

			vpackets[i].setSeatsBought(seatsBought);
		}

		else if (menuChecker == 0)
			break;

		else
			cout << "Dados invalidos";

	}

}

void packetsMenu()
{
	int menuChecker;
	vector<Packet> orderedPackets;

	while (true)
	{
		cout << "1. Ordenar por data" << endl;
		cout << "2. Entre duas datas" << endl;
		cout << "3. Procurar por local turistico" << endl;
		cout << "4. Ver dados de um pacote" << endl;
		cout << "5. Adicionar um pacote" << endl;
		cout << "6. Remover um pacote" << endl;
		cout << "7. Alterar um pacote" << endl;
		cout << "8. Ver pacotes com locais mais visitados" << endl;
		cout << "0. Voltar atras" << endl;

		cin >> menuChecker;

		if (cin.fail())
		{
			cout << "Insira um numero" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		else if (menuChecker == 1)
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
			cin.ignore(1000, '\n');
			getline(cin, date);

			while (!checkIfDateIsPossible(date))
			{
				cout << "Data invalida.\nInsira data inicial(AAAA/MM/DD): ";
				getline(cin, date);
			}

			Date begin(date);

			cout << "Insira data final(AAAA/MM/DD): ";
			getline(cin, date);

			while (!checkIfDateIsPossible(date))
			{
				cout << "Data invalida.\nInsira data inicial(AAAA/MM/DD): ";
				getline(cin, date);
			}

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
			location = trim(location);
			location[0] = toupper(location[0]);
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
				cin.clear();
				cin.ignore(1000, '\n');
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
					cout << "Pacote nao encontrado" << endl;
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

			while (!checkIfDateIsPossible(sbegin))
			{
				cout << "Data invalida.\nInsira data inicial(AAAA/MM/DD): ";
				getline(cin, sbegin);
			}

			Date begin(sbegin);

			cout << "Data de fim (AAAA/MM/DD): ";
			getline(cin, send);

			while (!checkIfDateIsPossible(send))
			{
				cout << "Data invalida.\nInsira data inicial(AAAA/MM/DD): ";
				getline(cin, send);
			}

			Date end(send);

			while (end.isBefore(begin))
			{
				cout << "Data final nao pode anteceder a data inicial" << endl;
				cout << "Data de fim (AAAA/MM/DD): ";
				getline(cin, send);
				Date end(send);
			}

			cout << "Preco por pessoa: ";
			cin >> pricePerPerson;

			cout << "Numero de lugares total: ";
			cin >> seatsAvailable;

			cout << "Numero de lugares vendidos: ";
			cin >> seatsBought;

			while (seatsAvailable < seatsBought)
			{
				cout << "Numero de lugares vendidos nao pode ser menor que o numero de lugares total" << endl;
				cout << "Numero de lugares vendidos: ";
				cin >> seatsBought;
			}

			vector<string> vsites = sitesFromString(sites);

			Packet packet(vsites, begin, end, pricePerPerson, seatsAvailable, seatsBought);
			vpackets.push_back(packet);
		}

		else if (menuChecker == 6)
		{
			unsigned Id;
			cout << "Id do pacote: ";
			cin >> Id;

			for (unsigned i = 0; i < vpackets.size(); i++)
			{
				if (vpackets[i].getId() == Id)
				{
					vpackets.erase(vpackets.begin() + i);
					break;
				}
				else if (i == vpackets.size() - 1)
					cout << "Pacote nao encontrado" << endl;
			}
		}

		else if (menuChecker == 7)
		{
			unsigned Id;
			cout << "Id do pacote: ";
			cin >> Id;

			for (unsigned i = 0; i < vpackets.size(); i++)
			{
				if (vpackets[i].getId() == Id)
				{
					changePacket(i);
					break;
				}
				else if (i == vpackets.size() - 1)
					cout << "Pacote nao encontrado" << endl;
			}
		}

		else if (menuChecker == 8)
		{

			map<string, unsigned> mostVisited = mapMostVisited();

			

			// função para ordenar os pairs do set pelo numero de lugares comprados
			auto cmp = [](const auto &p1, const auto &p2)
			{
				if (p1.second >= p2.second)
					return p2.second < p1.second;

				return p1.first < p2.first;
			};

			// cria um set de pairs igual ao map
			set < pair<string, unsigned>, decltype(cmp)> s(mostVisited.begin(), mostVisited.end(), cmp);

			// corre todos os pairs do set e dá print do numero de lugares comprados - lugares do pacote
			for (auto i = s.begin(); i != s.end(); i++)
			{
				cout << i->second << " - " << i->first << endl;
			}

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

		if (cin.fail())
		{
			cout << "Dados invalidos" << endl << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (checker == 1)
		{
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
			agency.show();
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
		}
		else if (checker == 2)
		{
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
			clientsMenu();
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
		}
		else if (checker == 3)
		{
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
			packetsMenu();
			cout << endl << setfill('*') << setw(30) << "" << endl << endl;
		}
		else if (checker == 0)
		{
			break;
		}
		else
			cout << "Dados invalidos" << endl << endl;
	}
}
   
