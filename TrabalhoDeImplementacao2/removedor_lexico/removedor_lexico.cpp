// Testando criar método para remover o seguinte:
// Este índice indexará o conjuntode todas as palavras contidas em todas as manpages que não caiam 
// nas seguintes categorias léxicas: artigo, conjunção, preposição e pronome (chamadas em seu conjunto 
// de conetivos).
#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> //strcpy
#include <vector>
#include <strings.h>

using namespace std;

vector<string> conectivosProibidos;
vector<string> palavras;

void criar_lista_conectivos() {

	// Artigos
	conectivosProibidos.push_back("a");
	conectivosProibidos.push_back("an");
	conectivosProibidos.push_back("the");
	conectivosProibidos.push_back("no");

	// Conjunções
	conectivosProibidos.push_back("for");
	conectivosProibidos.push_back("and");
	conectivosProibidos.push_back("nor");
	conectivosProibidos.push_back("but");
	conectivosProibidos.push_back("or");
	conectivosProibidos.push_back("yet");
	conectivosProibidos.push_back("so");

	// Preposições
	conectivosProibidos.push_back("aboard");
	conectivosProibidos.push_back("about");
	conectivosProibidos.push_back("above");
	conectivosProibidos.push_back("across");
	conectivosProibidos.push_back("after");
	conectivosProibidos.push_back("against");
	conectivosProibidos.push_back("ahead");
	conectivosProibidos.push_back("along");
	conectivosProibidos.push_back("amid");
	conectivosProibidos.push_back("amidst");
	conectivosProibidos.push_back("among");
	conectivosProibidos.push_back("around");
	conectivosProibidos.push_back("as");
	conectivosProibidos.push_back("aside");
	conectivosProibidos.push_back("at");
	conectivosProibidos.push_back("athwart");
	conectivosProibidos.push_back("atop");
	conectivosProibidos.push_back("barring");
	conectivosProibidos.push_back("because");
	conectivosProibidos.push_back("before");
	conectivosProibidos.push_back("behind");
	conectivosProibidos.push_back("below");
	conectivosProibidos.push_back("beneath");
	conectivosProibidos.push_back("beside");
	conectivosProibidos.push_back("besides");
	conectivosProibidos.push_back("between");
	conectivosProibidos.push_back("beyond");
	conectivosProibidos.push_back("but");
	conectivosProibidos.push_back("by");
	conectivosProibidos.push_back("circa");
	conectivosProibidos.push_back("concerning");
	conectivosProibidos.push_back("despite");
	conectivosProibidos.push_back("down");
	conectivosProibidos.push_back("during");
	conectivosProibidos.push_back("except");
	conectivosProibidos.push_back("excluding");
	conectivosProibidos.push_back("following");
	conectivosProibidos.push_back("for");
	conectivosProibidos.push_back("from");
	conectivosProibidos.push_back("in");
	conectivosProibidos.push_back("including");
	conectivosProibidos.push_back("inside");
	conectivosProibidos.push_back("instead");
	conectivosProibidos.push_back("into");
	conectivosProibidos.push_back("like");
	conectivosProibidos.push_back("minus");
	conectivosProibidos.push_back("near");
	conectivosProibidos.push_back("of");
	conectivosProibidos.push_back("off");
	conectivosProibidos.push_back("on");
	conectivosProibidos.push_back("onto");
	conectivosProibidos.push_back("opposite");
	conectivosProibidos.push_back("out");
	conectivosProibidos.push_back("outside");
	conectivosProibidos.push_back("over");
	conectivosProibidos.push_back("past");
	conectivosProibidos.push_back("plus");
	conectivosProibidos.push_back("prior");
	conectivosProibidos.push_back("regarding");
	conectivosProibidos.push_back("regardless");
	conectivosProibidos.push_back("save");
	conectivosProibidos.push_back("since");
	conectivosProibidos.push_back("tan");
	conectivosProibidos.push_back("through");
	conectivosProibidos.push_back("till");
	conectivosProibidos.push_back("to");
	conectivosProibidos.push_back("toward");
	conectivosProibidos.push_back("towards");
	conectivosProibidos.push_back("under");
	conectivosProibidos.push_back("underneath");
	conectivosProibidos.push_back("unlike");
	conectivosProibidos.push_back("until");
	conectivosProibidos.push_back("up");
	conectivosProibidos.push_back("upon");
	conectivosProibidos.push_back("versus");
	conectivosProibidos.push_back("via");
	conectivosProibidos.push_back("with");
	conectivosProibidos.push_back("within");
	conectivosProibidos.push_back("without");

	// Pronomes
	conectivosProibidos.push_back("I");
	conectivosProibidos.push_back("me");
	conectivosProibidos.push_back("we");
	conectivosProibidos.push_back("us");
	conectivosProibidos.push_back("you");
	conectivosProibidos.push_back("she");
	conectivosProibidos.push_back("her");
	conectivosProibidos.push_back("he");
	conectivosProibidos.push_back("him");
	conectivosProibidos.push_back("it");
	conectivosProibidos.push_back("they");
	conectivosProibidos.push_back("them");
	conectivosProibidos.push_back("what");
	conectivosProibidos.push_back("which");
	conectivosProibidos.push_back("who");
	conectivosProibidos.push_back("whom");
	conectivosProibidos.push_back("whose");
	conectivosProibidos.push_back("whichever");
	conectivosProibidos.push_back("whoever");
	conectivosProibidos.push_back("whomever");
	conectivosProibidos.push_back("this");
	conectivosProibidos.push_back("these");
	conectivosProibidos.push_back("that");
	conectivosProibidos.push_back("those");
	conectivosProibidos.push_back("anybody");
	conectivosProibidos.push_back("anyone");
	conectivosProibidos.push_back("anything");
	conectivosProibidos.push_back("each");
	conectivosProibidos.push_back("either");
	conectivosProibidos.push_back("everybody");
	conectivosProibidos.push_back("everyone");
	conectivosProibidos.push_back("everything");
	conectivosProibidos.push_back("neither");
	conectivosProibidos.push_back("nobody");
	conectivosProibidos.push_back("nothing");
	conectivosProibidos.push_back("one");
	conectivosProibidos.push_back("somebody");
	conectivosProibidos.push_back("someone");
	conectivosProibidos.push_back("something");
	conectivosProibidos.push_back("both");
	conectivosProibidos.push_back("few");
	conectivosProibidos.push_back("many");
	conectivosProibidos.push_back("several");
	conectivosProibidos.push_back("all");
	conectivosProibidos.push_back("any");
	conectivosProibidos.push_back("most");
	conectivosProibidos.push_back("none");
	conectivosProibidos.push_back("some");
	conectivosProibidos.push_back("myself");
	conectivosProibidos.push_back("ourselves");
	conectivosProibidos.push_back("yourself");
	conectivosProibidos.push_back("yourselves");
	conectivosProibidos.push_back("himself");
	conectivosProibidos.push_back("herself");
	conectivosProibidos.push_back("itself");
	conectivosProibidos.push_back("themselves");
	conectivosProibidos.push_back("my");
	conectivosProibidos.push_back("your");
	conectivosProibidos.push_back("his");
	conectivosProibidos.push_back("its");
	conectivosProibidos.push_back("is");
	conectivosProibidos.push_back("our");
	conectivosProibidos.push_back("your");
	conectivosProibidos.push_back("their");
	conectivosProibidos.push_back("mine");
	conectivosProibidos.push_back("yours");
	conectivosProibidos.push_back("his");
	conectivosProibidos.push_back("hers");
	conectivosProibidos.push_back("ours");
	conectivosProibidos.push_back("yours");
	conectivosProibidos.push_back("theirs");

}

void adicionarPalavraConectivos(string palavra){
	bool gravar = true;
	for(int i = 0; i < conectivosProibidos.size(); i++) {
		if (strcasecmp(palavra.c_str(), conectivosProibidos.at(i).c_str()) == 0) {
			gravar = false;
		}
	}
	if(gravar) {
		palavras.push_back(palavra);
	}
}

vector<string> remover_conectivos(string conteudo) {
	
	// Removendo caracteres especiais
	// TERMINAR SÁ PORRA.
	char caracteresEspeciais[] = "<>():'#;,.";
	int pos = 0, comecoDaString = 0;
	for(int i = 0; i < strlen(caracteresEspeciais); i++) {
		bool teste = true;
		while(teste) {
			pos = conteudo.find(caracteresEspeciais[i], comecoDaString);
			if(pos == -1){
				teste = false;
				break;
			}
			if (pos <= comecoDaString) {
				comecoDaString++;
				continue;
			} else {
			conteudo.replace(comecoDaString, pos-comecoDaString, " ");
				comecoDaString = pos+1;
			}
			comecoDaString = pos + 1;
		}
		// conteudo.erase(std::remove(conteudo.begin(), conteudo.end(), caracteresEspeciais[i]), 
			// conteudo.end());
	}

	// Separando em palavras
	pos = 0, comecoDaString = 0;
	while(true) {
		pos = conteudo.find(" ", comecoDaString); // \x20
		if(pos == -1) {
			string myFavoriteString = conteudo.substr(comecoDaString, conteudo.size()-comecoDaString);
			adicionarPalavraConectivos(myFavoriteString);
			break;
		}
		if (pos <= comecoDaString) {
			comecoDaString++;
			continue;
		} else {
			string myFavoriteString = conteudo.substr(comecoDaString, pos-comecoDaString);
			adicionarPalavraConectivos(myFavoriteString);
			comecoDaString = pos+1;
		}
	}

	for(int i = 0; i < palavras.size(); i++) {
		// printf("%s", palavras.at(i));
		cout << palavras.at(i) << endl;
	}

	return palavras;
}

int main() {
  const char * file = "manpages.dat";

  // Cria a lista de conectivos proibidos
  criar_lista_conectivos();

  string zoeira = "<beginning of page>"
"alias <-> alias table file of encoding names"
"/usr/lib/iconv/alias"
"This file contains the alias table of encoding names for iconv_open(3C)."
"The format of the alias table is as follows: <variant encoding name>, <canonical encoding name>"
"The string specified for the variant encoding name is case-insensitive. A line beginning with '#' is treated as a com<hy>ment."
"See attributes(5) for descriptions of the following attributes:"
"tab() box; cw(2.75i) |cw(2.75i) lw(2.75i) |lw(2.75i) ATTRIBUTE TYPEATTRIBUTE VALUE _ Interface Stabili<hy>"
"tyEvolving"
"iconv(3C), iconv_close(3C), iconv_open(3C), attributes(5)";
  remover_conectivos(zoeira);
  
  return 0;
}