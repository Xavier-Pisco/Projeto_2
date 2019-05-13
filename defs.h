#pragma once

#include <string>
#include <vector>
#include <map>


const std::string AGENCY_FILE_NAME="agency.txt";

std::vector<std::string> sitesFromString(std::string sites);

std::map<std::string, unsigned> mapMostVisited();

std::string trim(std::string str);

bool stringIsNumber(std::string str);
