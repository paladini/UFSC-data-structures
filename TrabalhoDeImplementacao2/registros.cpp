/*
 * @author max
*/
#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> //strcpy

using namespace std;

struct MyRecord {
  string conteudo;
  char comando[80];
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
  //fazer um while com getline em uma string, concatenar e armazenar
  MyRecord mr;
  // ifstream infile;
  // string aux; //homenagem.
  // infile.open("/ManPages/a.out.4.txt");
  // while (!infile.eof) {
  // 	getline(infile, aux);
  // 	strcat(mr.conteudo, aux);
  // }
  // puts(mr.conteudo);
  strcpy(mr.comando, "a.out.4");
  output.write((char *) &mr, sizeof(struct MyRecord));

  output.close();
}

void le(const char * filename) {
  ifstream input(filename,
		 ios::in //abre arquivo para leitura.
		 | ios::binary //arquivo binario.
		);
  if(!input) {
    cout << " -> Erro ao abrir arquivo." << endl;
    return;
  }

  MyRecord mr;
  input.read((char *) &mr, sizeof(struct MyRecord));
  input.close();
  
  cout << "Comando: " << mr.comando << endl;
  cout << "Conteudo: " << mr.conteudo << endl;
  cout.precision(2);
  cout.setf(ios::fixed);
}

int main() {
  const char * file = "manpages.dat";

  //Cria/Abre um arquivo e insere um registro no fim
  escreve(file);

  //Abre o arquivo criado e le o registro
  le(file);
  
  return 0;
}