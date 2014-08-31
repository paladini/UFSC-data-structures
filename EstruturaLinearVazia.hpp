/* 
 * File:   EstruturaLinearVazia.h
 * @author: Emmanuel Podestá, Fernando Paladini.
 * @since: Created on August 23, 2014, 8:48 PM
 * Copyright 2014 Emmanuel Podestá, Fernando Paladini.
 * < Na verdade é Copyleft, MIT License \o/ >
 */

#ifndef ESTRUTURALINEARVAZIA_H
#define	ESTRUTURALINEARVAZIA_H

class EstruturaLinearVazia {
 public:
    EstruturaLinearVazia();
    virtual ~EstruturaLinearVazia();
    const char *mostrarMensagem() const {
        return "A estrutura linear está vazia.";
    }
 private:
};

#endif	/* ESTRUTURALINEARVAZIA_H */

