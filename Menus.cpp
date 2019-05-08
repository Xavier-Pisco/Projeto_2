#include "Menus.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>


unsigned clientsMenu()
{
	int checker_clients, i = 0, xxxx, yyy;
	string street, floor, postalCode, location, name;
	unsigned short doorNumber, familySize;
	unsigned VATnumber;
	bool isCorrect = false;
	while (true)
	{
		cout << "1. Dados de todos os clientes" << endl;
		cout << "2. Adicionar clientes" << endl;
		cout << "3. Remover clientes" << endl;
		cout << "4. Alterar clientes" << endl;
		cout << "0. Voltar" << endl;
		cin >> checker_clients;
		if (checker_clients == 1)
		{
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
			cout << "Nome: ";
			getline(cin, name);
			cout << "NIF: ";
			cin >> VATnumber;
			while (cin.fail())
			{
				cin >> VATnumber;
			}
			cout << "Numero de agregado familiar: ";
			cin >> familySize;
			while (cin.fail())
			{
				cin >> familySize;
			}
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
			while (isCorrect == false)
			{
				getline(cin, postalCode);
				if (postalCode.find('-') == npos)
				{
					isCorrect = false;
					/////////////////////////////////////////////////////////
				}

			}

		}
	}
}

unsigned mainMenu(Agency agency){

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
			//falta completar este menu
		}
		else if (checker == 0)
		{
			break;
		}
	}
  
  return 0;
}
    
