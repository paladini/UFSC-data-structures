#include <string>

class Palavra {
private:
	string palavra;
	vector<string> comandosQueContem;

public:

	Palavra(string _palavra) {
		palavra = _palavra;
	}

	void adicionarComandosQueContem(string comando) {
		if (!comandosQueContem.has(comando)) {
			comandosQueContem.push_back(comando);
		}
	}


}