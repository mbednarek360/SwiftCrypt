#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include "infint.h"
using namespace std;

//print charectar vector (for debugging)
void printVector(map < InfInt, char > m) {
  for (InfInt i = 0; i < m.size(); i++) {
    cout << m[i];
  }
  cout << endl;
}

//return 16^n
InfInt raise(InfInt p) {
  InfInt out = 16;
  if (p == 0) {
    return 1;
  }
  for (InfInt i = 0; i < (p - 1); i++) {
    out *= 16;
  }
  return out;
}

//hex vector to decimal
InfInt htd(map < InfInt, char > m) {
  map < char, int > map = {};
  map['a'] = 10;
  map['b'] = 11;
  map['c'] = 12;
  map['d'] = 13;
  map['e'] = 14;
  map['f'] = 15;
  InfInt out = 0;
  for (InfInt i = (m.size()); i > 0; i--) {
    InfInt t;
    if (m[i - 1] - '0' < 10) {
      t = (m[i - 1] - '0');
    } else {
      t = map[(m[i - 1])];
    }
    out += (t * raise(static_cast < InfInt > (m.size()) - i));
  }
  return out;
}

//decimal to char vector
map < InfInt, char > dth(InfInt q) {
  map < InfInt, char > out = {};
  map < InfInt, char > nil = {};
  nil[0] = '0';
  nil[1] = '0';
  if (q == 0) {
    return nil;
  } else {
    map < InfInt, InfInt > r = {};
    InfInt cur = 0;

    while (q > 0) {
      r[cur] = q % 16;
      q = q / 16;
      cur++;
    }

    map < InfInt, char > map = {};
    map[10] = 'a';
    map[11] = 'b';
    map[12] = 'c';
    map[13] = 'd';
    map[14] = 'e';
    map[15] = 'f';

    InfInt m = 0;
    for (InfInt n = (cur - 1); n >= 0; n--) {
      if (r[n] < 10) {
        out[m] = r[n].toString().at(0);

      } else {
        out[m] = map[r[n]];
      }
      m++;
    }
    return out;
  }
}

int main(int argc, char * argv[]) {
  system("clear");
  string inMode = argv[3];
  string oFName = argv[1];

  //read key to char vector
  cout << "Reading key file..." << endl;
  map < InfInt, char > ky = {};
  InfInt m = 0;
  ifstream f1;
  f1.open(argv[2], ios::binary);
  if (f1.is_open()) {
    while (!f1.eof()) {
      stringstream s;
      int it;
      it = f1.get();
      s << hex << it;
      string s1 = s.str();
      if (s1.length() < 2) {
        s1 = ('0' + s1);
      }
      ky[m] = s1[0];
      ky[(m+1)] = s1[1];
      m+=2;
    }
  }
  f1.close();
  for (int i = 0; i < 2; i++) {
    ky.erase(ky.size() - 1);
  }

if (inMode == "-e") {

  //rename file
  oFName = (oFName + ".sc");
  rename(argv[1], oFName.c_str());

  //write key to input file
  cout << "Writing key to input file..." << endl;
  ofstream keyV;
  keyV.open(oFName, ios::binary | ios::app);
  for (InfInt i = 0; i < ky.size(); i+=2) {
    stringstream t;
    t << ky[i];
    t << ky[(i+1)];
    int t1;
    t >> hex >> t1;
    keyV.write((char *)&t1, 1);
  }
  keyV.close();
} else if (inMode == "-d") {

  //revert file name
  oFName = oFName.substr(0, oFName.size()-3);
  rename(argv[1], oFName.c_str());
}

  //read input to char vector
  cout << "Reading input file..." << endl;
  map < InfInt, char > in = {};
  InfInt n = 0;
  ifstream f;
  f.open(oFName, ios::binary);
  if (f.is_open()) {
    while (!f.eof()) {
      stringstream s;
      int it;
      it = f.get();
      s << hex << it;
      string s1 = s.str();
      if (s1.length() < 2) {
        s1 = ('0' + s1);
      }
      in[n] = s1[0];
      in[(n+1)] = s1[1];
      n+=2;
    }
  }
  f.close();
 for (int i = 0; i < 2; i++) {
    in.erase(in.size() - 1);
  }

  //calculate output
  cout << "Calculating output..." << endl;
  map < InfInt, char > out = {};
  if (inMode == "-e") {
    out = dth(htd(in) * htd(ky));

  } else if (inMode == "-d") {
    out = dth(htd(in) / htd(ky));

    //build verification vector
    cout << "Verifying key..." << endl;
    map < InfInt, char > ver = {};
    InfInt n = 0;
    for (InfInt i = (out.size() - ky.size()); i < out.size(); i++) {
      ver[n] = out[i];
      n++;
    }

    //remove verification vector from output
    map < InfInt, char > tmp = {};
    for (InfInt i = 0; i < (out.size() - ky.size()); i++) {
      tmp[i] = out[i];
    }
    out = tmp;

    //verify key
    if (ky != ver) {
      system("clear");
      cout << "Error verifying key. Make sure you have the correct key and try again." << endl;
      return 1;
    }

  }

  //write output to file
  cout << "Writing output file..." << endl;
  ofstream outF;
  outF.open(oFName, ios::binary);
  for (InfInt i = 0; i < out.size(); i+=2) {
    stringstream t;
    t << out[i];
    t << out[(i+1)];
    int t1;
    t >> hex >> t1;
    outF.write((char *)&t1, 1);
  }
  outF.close();
}