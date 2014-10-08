// #include <algorithm>
// #include <iostream>
// #include <vector>
 
// void merge_sort(const std::vector<int> &data) {
// 	if (listaDeEventos->retornaTamanho() <= 1) {
// 		return listaDeEventos;
// 	}

// 	int middle = listaDeEventos->retornaTamanho() / 2;
// 	std::vector<int> left(listaDeEventos->begin(), listaDeEventos->begin()+middle);
// 	std::vector<int> right(listaDeEventos->begin()+middle, listaDeEventos->end());
 
// 	left = merge_sort(left);
// 	right = merge_sort(right);
 
// 	std::vector<int> result(listaDeEventos->retornaTamanho());
// 	std::merge(left.begin(), left.end(), 
// 	           right.begin(), right.end(),
// 	           result.begin());
 
// 	return result;
// }