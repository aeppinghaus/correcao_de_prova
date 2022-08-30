/**
 *Arquivo com todas as nossas funcoes
 **/
#include <fstream>
#include <iostream>
using namespace std;

// regiao de prototipos de funcao
void split(string s);

// fim de regiao de prototipos de funcao

struct GabaritoComArray {
  string matricula;
  string notas[2][12];
};

struct GabaritoSemArray {
  string matricula;
  string q1;
  string q2;
  string q3;
  string q4;
  string q5;
  string q6;
  string q7;
  string q8;
  string q9;
  string q10;
};

void lerArquivo(string nomeArquivo) {
  string line;
  ifstream myfile(nomeArquivo);
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      cout << line << '\n';
      split(line);
    }
    myfile.close();
  } else {
    cout << "Nao consegue abrir o arquivo";
  }
}

// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
void split(string s) {
  // std::string s = "scott>=tiger>=mushroom";
  std::string delimiter = ";";

  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    std::cout << token << std::endl;
    s.erase(0, pos + delimiter.length());
  }
  std::cout << s << std::endl;
}