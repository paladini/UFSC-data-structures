/** Classe Registro.
* Essa classe armazenará os dados das manpages para realizar a indexação por chave primária.
* 
*/
class Registro {
 public:
	char conteudo[100000];
	char comando[80];
	/**Construtor padrão.
	*Este é o contrutor padrão da classe Registro.
	*/
	Registro() { }
	/**Cnstrutor da classe Registro.
	*Construirá um registro com um campo de comando e um de conteúdo.
	*/
	Registro(char _comando[80], char _conteudo[100000]){
		strcpy(comando, _comando);
		strcpy(conteudo, _conteudo);
	}
	/**Método retornarConteudo.
	*Retornará o conteúdo presente em um registro.
	*/
	char* retornarConteudo() {
		return conteudo;
	}
	/**Método retornarComando.
	*Retornará o comando presente em um registro.
	*/
	char* retornarComando() {
		return comando;
	}
	/**Método definirComando.
	*Definirá um novo comando para o registro.
	*@param novoNome Será o novo comando do registro.
	*/
	void definirComando(char* novoNome) {
		strcpy(comando, novoNome);
	}
	/**Método definirConteudo.
	*Definirá um novo conteúdo para o registro.
	*@param novoConteudo Será o novo conteúdo a ser inserido
	*no registro.
	*/
	void definirConteudo(char* novoConteudo) {
		strcpy(conteudo, novoConteudo);
	}
	/**Sobreescrita de operator.
	*Será responsável por fazer a comparação pelo comando do registro.
	*/
	bool operator<(const Registro& rhs) const {
		return comando < rhs.comando;
	}
};