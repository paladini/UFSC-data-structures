/*
 * @author max
*/
#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> //strcpy
#include <dirent.h>
#include <sys/stat.h>
#include <cstdlib>
#include "registro.cpp"
using namespace std;


void escreve(const char * filename) {
    ofstream output(filename,
      ios::out //abre arquivo para escrita.
      //ios::app //abre arquivo para escrita, adicionando ao fim do arquivo (append).
      | ios::binary //arquivo binario.
     );

    // Erro ao abrir o arquivo.
    if (!output) {
        cout << " -> Erro ao abrir arquivo." << endl;
        return;
    }

    //
    DIR *dir;
    int i = 0;
    struct dirent *ent;

    string path = "/home/paladini/UFSC-estruturaDeDados-2014-02/TrabalhoDeImplementacao2/ManPages/";
    if ((dir = opendir (path.c_str())) != NULL) {
        int cont = 0;
        while ((ent = readdir (dir)) != NULL) {

            // Pega o nome de arquivo atual
            char *filename = (char*) ent->d_name;

            // Verifica se o nome do arquivo é diferente de "." (pasta ./)
            if(filename[0] == '.') {
                continue;
            }
            cont++;
            
            char *caminho = new char[path.size()+1000];
            strcpy(caminho, path.c_str());
            strcat(caminho, filename);
            Registro mr;
            char *extension = strstr(filename, ".txt");
            strncpy(extension, "", 4);
            strcpy(mr.comando, filename);
            std::ifstream ifs(caminho);

            struct stat propriedades;

            if (stat(caminho, &propriedades) == -1) {
                break;
            }

            char* content = new char[propriedades.st_size];

            ifs.read(content, propriedades.st_size);
            strcpy(mr.conteudo, content);
            output.write((char *) &mr, sizeof(Registro));
            delete [] content;
        }
        printf("Readed %d files\n", cont);
        output.close();
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        throw -1;
    }
}

void le(const char * filename, int pos) {
    ifstream input(filename,
       ios::in //abre arquivo para leitura.
       | ios::binary //arquivo binario.
      );

    // Erro ao abrir o arquivo
    if(!input) {
      cout << " -> Erro ao abrir arquivo." << endl;
      return;
    }

    Registro mr;
    input.seekg(sizeof(Registro)*pos, input.beg);
    input.read((char *) &mr, sizeof(Registro));
    input.close();

    cout << "Comando: " << mr.comando << endl;
    cout << "Conteudo: " << mr.conteudo << endl;
}

int main(int argc, char **argv) {
    const char * file = "manpages.dat";

    //Cria/Abre um arquivo e insere um registro no fim
    escreve(file);

    //Abre o arquivo criado e le o registro
    le(file, atoi(argv[1]));

    return 0;
}