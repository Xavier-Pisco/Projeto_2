#pragma once

#include "defs.h"
#include "Packet.h"
#include "Address.h"

using namespace std;

class Client{
 private:
  string name; // name of the client
  unsigned VATnumber; // VAT number of client
  unsigned short familySize;  // number of family members
  Address address; // client's address
  vector<int> packets; // vector to store client's packets bought
  unsigned  totalPurchased; // total value spent by the client

 public:
  Client(string name, unsigned VATnumber, unsigned short familySize, Address address);  // for a new client
  Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<int> packets, unsigned totalPurchased);  // client read from file
  Client(string client);

  // GET methods
  
  string getName() const;
  unsigned getVATnumber() const;
  unsigned short getFamilySize() const;
  Address getAddress() const;
  vector<int> getPacketList() const;
  unsigned getTotalPurchased() const;
  string getContent() const;
  string getPacketsIds() const;

  
  // SET methods
  
  void setName(string name);
  void setVATnumber(unsigned VATnumber);
  void setFamilySize(unsigned short familySize);
  void setAddress(Address address);
  void setPacketList(vector<int> packets);
  void setPacketList(string packets);
  void setTotalPurchased(unsigned totalPurchased);
  
  // other methods
  void show() const;
  void buyPacket(int packetId);

  //friend ostream& operator<<(ostream& out, const Client & client);
};

extern vector<Client> vclients;

Client getClientFromNIF(const unsigned clientNIF);

bool checkIfClientExist(const unsigned NIF);