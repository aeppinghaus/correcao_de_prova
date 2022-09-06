#include "services.h"
#include <iostream>

int main() {

  lerArquivo("resultado/resultado.csv");

  std::cout << "Hello World!\n";

  // cout << variavelGlobal[1] << endl;

  int linha = 0;
  while (linha < 2) {
    cout << variavelGlobal[linha] << endl;
    
    split(variavelGlobal[linha], linha);

    cout << "=============" << endl;
    cout << "Matricula:" << gabarito1[linha].matricula << endl;
    cout << "Nome:" << gabarito1[linha].nome << endl;
    for(int indice=0;indice<10;indice++) {
      cout << "questão "<<(indice+1)<<": " << gabarito1[linha].questao[indice] << endl;  
    }
    cout << "=============" << endl;
    linha++;
  }
}