/**
 *Arquivo com todas as nossas funcoes
 **/
#include <fstream>
#include <iostream>
using namespace std;

string variavelGlobal[2];

// regiao de prototipos de funcao
// separa a string a partir de um caracter
void split(string s, int linha);

// fim de regiao de prototipos de funcao

struct GabaritoComArray {
  string matricula;
  string nome;
  string notas[2][12];
};
GabaritoComArray gabarito1[2];

struct GabaritoSemArray {
  string matricula;
  string nome;
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
GabaritoSemArray gabarito2[2];

void lerArquivo(string nomeArquivo) {
  string line;
  int contador = 0;
  ifstream myfile(nomeArquivo);
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      // cout << line << '\n';
      variavelGlobal[contador] = line;
      // split(line);
      contador++;
    } // fim while
    myfile.close();
  } else {
    cout << "Nao conseguiu abrir o arquivo";
  }
}

// string *lerArquivoCOMPONTEIRO(string nomeArquivo) {
//   string line;
//   string *resultado = new string[2];
//   int contador = 0;
//   ifstream myfile(nomeArquivo);
//   if (myfile.is_open()) {
//     while (getline(myfile, line)) {
//       // cout << line << '\n';
//       resultado[contador] = line;
//       // split(line);
//       contador++;
//     } // fim while
//     myfile.close();
//   } else {
//     cout << "Nao conseguiu abrir o arquivo";
//   }
//   return resultado;
// }

// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
void split(string s, int linha) {
  // std::string s = "scott>=tiger>=mushroom";
  std::string delimiter = ",";
  int coluna = 0;
  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    // cout << "contador" << contador << endl;
    // std::cout << token << std::endl;

    switch (coluna) {
    case 0:
      gabarito2[linha].matricula = token;
      break;
    case 1:
      gabarito2[linha].nome = token;
      break;
    case 2:
      gabarito2[linha].q1 = token;
      break;
    case 3:
      gabarito2[linha].q2 = token;
      break;
    case 4:
      gabarito2[linha].q3 = token;
      break;
    case 5:
      gabarito2[linha].q4 = token;
      break;
    case 6:
      gabarito2[linha].q5 = token;
      break;
    case 7:
      gabarito2[linha].q6 = token;
      break;
    case 8:
      gabarito2[linha].q7 = token;
      break;
    case 9:
      gabarito2[linha].q8 = token;
      break;
    case 10:
      gabarito2[linha].q9 = token;
      break;
    }
    s.erase(0, pos + delimiter.length());
    coluna++;
  }
  gabarito2[linha].q10 = s;
  // std::cout << s << std::endl;
}