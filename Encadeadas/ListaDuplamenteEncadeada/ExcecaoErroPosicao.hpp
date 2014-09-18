/**
* File: ExcecaoErroPosicao.hpp
* @author: Emmanuel Podestá, Fernando Paladini.
* @since: Created on 6 de Setembro de 2014, 20:52.
* Copyright 2014 Emmanuel Podestá, Fernando Paladini.
* < Na verdade é Copyleft, MIT License \o/ >
*/
#ifndef EXCECAOERROPOSICAO_HPP_
#define EXCECAOERROPOSICAO_HPP_
#include <exception>
/** Classe ExcecaoErroPosicao.
* A classe ExcecaoErroPosicao é uma classe de Exceção disparada quando o usuário tenta acessar uma
* posição indevida ou inexistente na respectiva estrutura de dados.
*/
	class ExcecaoErroPosicao : public std::exception {
 public:
		virtual const char* mostrarMensagem() const throw() {
			return "Exceção Erro Posicao: a posição em questão não existe!";
		}
} ExcecaoErroPosicao;
#endif /* EXCECAOERROPOSICAO_HPP_ */
