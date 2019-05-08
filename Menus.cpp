#include "Menus.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>


unsigned clientsMenu()
{
	int checker_clients, i;
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
			for (i = 0; i < 5; )
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
			//falta completar este menu
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
    
