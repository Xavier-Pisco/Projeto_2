#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <set>
#include <sstream>


const std::string AGENCY_FILE_NAME="agency.txt";

std::vector<std::string> sitesFromString(std::string sites);

std::map<std::string, unsigned> mapMostVisited();

std::string trim(std::string str);

bool stringIsNumber(std::string str);

int main();

void saveClients(std::string file);

void savePacks(std::string file);

void openPacketsFile(std::string filename);

void openClientsFile(std::string filename);
