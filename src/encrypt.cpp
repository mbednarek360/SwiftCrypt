#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>
#include "infint.h"
using namespace std;

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
    //cout << m.size() << endl;
  }
  return out;
}

//decimal to hex string
string dth(InfInt q) {
  if (q == 0) {
    return "0";
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

    string out = "";
    for (InfInt n = (cur - 1); n >= 0; n--) {
      if (r[n] < 10) {
        out += (r[n]).toString();
      } else {
        out += map[r[n]];
      }
    }
    return out;
  }
}

int main(int argc, char * argv[]) {
  system("clear");

  //read input to char vector
  cout << "Reading input file..." << endl;
  map < InfInt, char > in = {};
  InfInt n = 0;
  ifstream f;
  f.open(argv[1]);
  if (f.is_open()) {
    while (!f.eof()) {
      char c;
      f >> c; in [n] = c;
      n++;
    }
  }
  f.close(); in.erase(in .size() - 1);

  //read key to char vector
  cout << "Reading key file..." << endl;
  map < InfInt, char > ky = {};
  InfInt m = 0;
  ifstream f1;
  f1.open(argv[2]);
  if (f1.is_open()) {
    while (!f1.eof()) {
      char c;
      f1 >> c;
      ky[m] = c;
      m++;
    }
  }
  f1.close();
  ky.erase(ky.size() - 1);


  //write output to file
  ofstream file(argv[3]);
  string inMode = argv[4];
  string out;
  if (inMode == "-e") {
    cout << "Decoding input..." << endl;
    InfInt inDec = htd(in);
    cout << "Decoding key..." << endl;
    InfInt kyDec = htd(ky);
    cout << "Calculating output..." << endl;
    InfInt outDec = inDec * kyDec;
    cout << "Encoding output..." << endl;
    out = dth(outDec);

  } else if (inMode == "-d") {
    cout << "Decoding input..." << endl;
    InfInt inDec = htd(in);
    cout << "Decoding key..." << endl;
    InfInt kyDec = htd(ky);
    cout << "Calculating output..." << endl;
    InfInt outDec = inDec / kyDec;
    cout << "Encoding output..." << endl;
    out = dth(outDec);
  }
  if (out.length() % 2 == 1) {
    out = ("0" + out);
  }
  file << out;
}