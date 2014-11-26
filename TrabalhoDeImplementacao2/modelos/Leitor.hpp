#ifndef LEITOR_HPP_
#define LEITOR_HPP_
/** Classe Leitor.
* Essa clase serve para ler arquivos do disco e transformar seu conteúdo em Registros, ou seja,
 em objetos do tipo Registro que mais tarde serão utilizados tanto na indexação secundária como
 na indexação primária.
*/
class Leitor {
 private:

    // Variável que armazena o diretório do arquivo que será lido.
 	string arquivo;
 public:
    /**Construtor Leitor
    *Construtor para um Leitor, possuindo um atributo arquivo que será necessário para a leitura
    *do mesmo.
    *@param archive Será o nome do arquivo que se quer ler.
    */
 	Leitor(string archive) {
 		arquivo = archive;
 	}
    
    /**Método ler_arquivo.
    * Lê um arquivo do disco e armazena o seu conteúdo em um objeto Registro.
    * Esse método lê um arquivo com disco com diretório fornecido como argumento e realiza duas coisas:
    *
    *   1 - Extrai o nome do comando do diretório fornecido e armazena.
    *   2 - Lê o arquivo, extrai o conteúdo e armazena.
    *
    * Esses dados são armazenados em um objeto do tipo "Registro", que logo em seguida é 
    * retornado para o método que o chamou.
    *
    * @return Registro um registro que foi criado a partir do dado lido.
    */
    Registro ler_arquivo() {
        
        // Abre o arquivo para leitura
        ifstream arquivoLido(arquivo.c_str());

        // Verifica se o arquivo está mesmo aberto.
        if (arquivoLido.is_open()) {

            // O nome do arquivo é "ManPages/nomeDoComando.txt". Pega apenas o nomeDoComando.
            int pos_barra = arquivo.find_last_of("/") + 1;
            int pos_ponto = arquivo.find_last_of(".");
            int quantidadeDeCaracteres = pos_ponto - pos_barra;
            string nomeDoComando = arquivo.substr(pos_barra, quantidadeDeCaracteres);

            // Copia todo o conteúdo do arquivo para o char "conteudo".
            char conteudo[200000];
            std::stringstream buffer;
            buffer << arquivoLido.rdbuf(); // lê o arquivo inteiro e coloca na variável buffer
            strcpy(conteudo, buffer.str().c_str());

            // Pega o nome do comando e armazena em uma variável.                
            char comando[80];
            strcpy(comando, nomeDoComando.c_str());

            // Cria um registro.
            Registro mr(comando, conteudo);

            // Fecha o arquivo.
            arquivoLido.close();

            // Retorna o registro criado.
            return mr;

        } else {
            throw "Arquivo não pode ser lido. Método ler_arquivo.";
        }
    }

};
#endif