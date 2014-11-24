/*
* @author max
*/

#include <iostream> //cout
#include <fstream> //fstream
#include "NoAVL.cpp"
#include <string>
#include <vector>
#include <sys/stat.h>

using namespace std;

struct MyRecord {
  string nome;
  double salario;
  int teste;
};

void escreve(const char * filename) {
  ofstream output(filename,
      ios::out //abre arquivo para escrita.
      // ios::app //abre arquivo para escrita, adicionando ao fim do arquivo (append).
      | ios::binary //arquivo binario.
     );
  if (!output) {
    cout << " -> Erro ao abrir arquivo." << endl;
    return;
  }

  NoAVL<int> *inteiro = new NoAVL<int>(10);
  inteiro->inserir(5, inteiro);
  inteiro->inserir(5, inteiro);
  inteiro->inserir(15, inteiro);
  inteiro->inserir(14, inteiro);
  inteiro->inserir(16, inteiro);
  inteiro->inserir(6, inteiro);
  inteiro->inserir(13, inteiro);

  inteiro->preOrdem(inteiro);
  vector<NoAVL<int>*> dump = inteiro->getElementos();

  int *dumpInt = new int[dump.size()];
  cout << "Há "<< dump.size() << " itens no vetor\n";
  for(int i=0;  i < dump.size(); i++) {
    dumpInt[i] = *(dump[i]->getDado());
  }

  output.write((char *) dumpInt, sizeof(int)*dump.size());

  output.close();
}

void le(const char * filename) {
  ifstream input(filename,
     ios::in //abre arquivo para leitura.
     | ios::binary //arquivo binario.
    );

  struct stat result;
  int rStat = stat(filename, &result);
  if(!input || rStat == -1) {
    cout << " -> Erro ao abrir arquivo." << endl;
    return;
  }
  int fileSize = result.st_size;
  cout <<  "O arquivo tem " << fileSize << " bytes" << endl;

  
  int size = fileSize/sizeof(int);
  int *dump = new int[size];
  cout << "Há " << size << " itens no vetor" << endl;
  input.read((char *) dump, fileSize);

  NoAVL<int> *inteiro = new NoAVL<int>(dump[0]);

  for(int i=1; i<size; i++) {
    cout << "dump[" << i << "] = " << dump[i] << endl;
    inteiro->inserir(dump[i], inteiro);
  }

  inteiro->preOrdem(inteiro);
  vector<NoAVL<int>*> dumpV = inteiro->getElementos();

  int *dumpInt = new int[dumpV.size()];
  cout << "Há "<< dumpV.size() << " itens no vetor\n";
  for(int i=0;  i < dumpV.size(); i++) {
    cout << "dumpV[" << i << "] = " << *(dumpV[i]->getDado()) << endl;
  }

  input.close();
}

int main(int argc, char **argv) {
  const char * file = "arquivo_test.txt";

  //Cria/Abre um arquivo e insere um registro no fim
  escreve(file);

  //Abre o arquivo criado e le o registro
  le(file);
  
  return 0;
}
