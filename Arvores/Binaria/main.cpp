#include "Arvore.hpp"
#include <iostream>
int main(int argc, char **argv) {
	NoBinario<int>* a = new NoBinario<int>(100);
	// NoBinario<int>* b = new NoBinario<int>(50);
	// NoBinario<int>* c = new NoBinario<int>(150);
	NoBinario<int>* novo = a->inserir(50, a);
	NoBinario<int>* novo1 = a->inserir(150, a);
	a->posOrdem(a);
	NoBinario<int>* aux;
	aux = a->getElementos();
	std::cout << *aux[0].getDado() << std::endl;
	std::cout << *aux[1].getDado() << std::endl;
	std::cout << *aux[2].getDado() << std::endl;
}