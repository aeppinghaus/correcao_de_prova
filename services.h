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
#define totalQuestoes 10
#define totalLinha 2

struct GabaritoComArray {
  string matricula;
  string nome;
  string questao[totalQuestoes];
};

GabaritoComArray gabarito1[totalLinha];

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
GabaritoSemArray gabarito2[totalLinha];

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
  int contador=0;
  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    // cout << "contador" << contador << endl;
    // std::cout << token << std::endl;
    
    switch (coluna) {
    case 0:
      gabarito1[linha].matricula = token;
      break;
    case 1:
      gabarito1[linha].nome = token;
      break;
    default:
      gabarito1[linha].questao[coluna-2] = token; 
      break;
    }
    /*
    coluna=     0   1     2 3 4 5 6 7 8 9 10 11
               1000,andre,b,c,e,f,a,e,d,b, c, a
              questao     0,1,2,3,4,5,6,7, 8, 9

      */
    s.erase(0, pos + delimiter.length());
    coluna++;
  }//fim while
  gabarito1[linha].questao[9] = s;
  // std::cout << s << std::endl;
}