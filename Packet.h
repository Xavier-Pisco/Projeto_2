#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "defs.h"
#include "Date.h"

using namespace std;

class Packet{
 private:
  unsigned id; // packet unique identifier
  vector<string> sites; // touristic sites to visit
  Date begin;  // begin date
  Date end;  // end date
  double pricePerPerson; // price per person
  unsigned maxPersons; // number of persons still available in the packet (updated whenever the packet is sold to a new client)
  static int nextId;
  
 public:
  Packet(vector<string> sites, Date begin, Date end, double pricePerPerson, unsigned maxPersons);
  Packet(string packet);

  // GET methods
  unsigned getId() const;
  vector<string> getSites() const;
  Date getBeginDate() const;
  Date getEndDate() const;
  double getPricePerPerson() const;
  unsigned getMaxPersons() const;
  string getContent() const;

  // SET methods
  void setId(unsigned id);  // to set negatve if "deprecated"
  void setSites(vector<string> sites);
  void setSites(string sites);
  void setBeginDate(Date begin);
  void setEndDate(Date end);
  void setPricePerPerson(double pricePerPerson);
  void setMaxPersons(unsigned maxPersons);
  void setMaxPersons(unsigned total, unsigned reserved);

  // other methods
  void show() const;
  //friend ostream& operator<<(ostream& out, const Packet & packet);
};

extern vector<Packet> vpackets;

Packet getPacketFromId(const unsigned packetId);
