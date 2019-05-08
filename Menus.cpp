#include "Menus.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

unsigned mainMenu(Agency agency){

	int checker;
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
		return 0;
	}
  
  return 0;
}
    
