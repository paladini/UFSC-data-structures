/* 
 * File:   EstruturaLinearCheia.h
 * @author: Emmanuel Podestá, Fernando Paladini.
 * @since: Created on August 23, 2014, 9:05 PM
 * Copyright 2014 Emmanuel Podestá, Fernando Paladini.
 * < Na verdade é Copyleft, MIT License \o/ >
 */

#ifndef ESTRUTURALINEARCHEIA_H
#define	ESTRUTURALINEARCHEIA_H

class EstruturaLinearCheia {
 public:
    EstruturaLinearCheia();
    virtual ~EstruturaLinearCheia();
    const char *mostrarMensagem() const {
        return "A estrutura linear está cheia.";
    }
 private:
};

#endif	/* ESTRUTURALINEARCHEIA_H */

