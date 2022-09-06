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
    cout << "Matricula:" << gabarito2[linha].matricula << endl;
    cout << "Nome:" << gabarito2[linha].nome << endl;
    cout << "questão 1:" << gabarito2[linha].q1 << endl;
    cout << "questão 2:" << gabarito2[linha].q2 << endl;
    cout << "questão 3:" << gabarito2[linha].q3 << endl;
    cout << "questão 4:" << gabarito2[linha].q4 << endl;
    cout << "questão 5:" << gabarito2[linha].q5 << endl;
    cout << "questão 6:" << gabarito2[linha].q6 << endl;
    cout << "questão 7:" << gabarito2[linha].q7 << endl;
    cout << "questão 8:" << gabarito2[linha].q8 << endl;
    cout << "questão 9:" << gabarito2[linha].q9 << endl;
    cout << "questão 10:" << gabarito2[linha].q10 << endl;
    cout << "=============" << endl;
    linha++;
  }
}