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
  unsigned seatsAvailable; // number of maximum seats available
  unsigned seatsBought; //number of seats already bought
  bool packetAvailable;
  static int nextId;
  
 public:
  Packet(vector<string> sites, Date begin, Date end, double pricePerPerson, unsigned seatsAvailable, unsigned seatsBought);
  Packet(string packet);

  // GET methods
  unsigned getId() const;
  vector<string> getSites() const;
  Date getBeginDate() const;
  Date getEndDate() const;
  double getPricePerPerson() const;
  unsigned getSeatsAvailable() const;
  unsigned getSeatsBought() const;
  string getContent() const;
  bool getPacketAvailable() const;

  // SET methods
  void setId(unsigned id);  // to set negatve if "deprecated"
  void setSites(vector<string> sites);
  void setSites(string sites);
  void setBeginDate(Date begin);
  void setEndDate(Date end);
  void setPricePerPerson(double pricePerPerson);
  void setSeatsAvailable(unsigned seatsAvailable);
  void setSeatsBought(unsigned seatsBought);

  // other methods
  void show() const;
  bool searchLocation(string location);
  //friend ostream& operator<<(ostream& out, const Packet & packet);
};

extern vector<Packet> vpackets;

Packet getPacketFromId(const unsigned packetId);
