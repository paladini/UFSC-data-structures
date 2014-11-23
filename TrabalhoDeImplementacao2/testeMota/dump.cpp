
/*
 * @author max
 */

#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> // strcpy
#include <cstdlib> // strcpy

using namespace std;

struct MyRecord {
  char nome[80];
  double salario;
  int teste;
};

void escreve(const char * filename) {
  ofstream output(filename,
		  //ios::out //abre arquivo para escrita.
		  ios::app //abre arquivo para escrita, adicionando ao fim do arquivo (append).
		  | ios::binary //arquivo binario.
		 );
  if (!output) {
    cout << " -> Erro ao abrir arquivo." << endl;
    return;
  }

  MyRecord *mr = new MyRecord[2];
  strcpy(mr[0].nome, "Fernando");
  mr[0].salario = 1100;
  mr[0].teste = 101;

  strcpy(mr[1].nome, "Jean");
  mr[1].salario = 5000;
  mr[1].teste = 102;

  output.write((char *) mr, sizeof(struct MyRecord)*2);

  output.close();
}

void le(const char * filename, int pos) {
  ifstream input(filename,
		 ios::in //abre arquivo para leitura.
		 | ios::binary //arquivo binario.
		);
  if(!input) {
    cout << " -> Erro ao abrir arquivo." << endl;
    return;
  }

  MyRecord mr;
  input.seekg(sizeof(struct MyRecord)*pos, input.beg);
  input.read((char *) &mr, sizeof(struct MyRecord));
  input.close();
  
  cout << "Nome: " << mr.nome << endl;
  cout.precision(2);
  cout.setf(ios::fixed);
  cout << "Salario: " << mr.salario << endl;
  cout << "Teste: " << mr.teste << endl;
}

int main(int argc, char **argv) {
  const char * file = "arquivo_test.txt";

  //Cria/Abre um arquivo e insere um registro no fim
  escreve(file);

  //Abre o arquivo criado e le o registro
  le(file, atoi(argv[1]));
  
  return 0;
}
