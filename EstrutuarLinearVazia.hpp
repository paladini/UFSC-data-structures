/* 
 * File:   EstruturaLinearVazia.h
 * Author: paladini
 *
 * Created on August 23, 2014, 8:48 PM
 */

#ifndef ESTRUTURALINEARVAZIA_H
#define	ESTRUTURALINEARVAZIA_H

class EstruturaLinearVazia {
public:
    EstruturaLinearVazia();
    virtual ~EstruturaLinearVazia();

    const char *mostrarMensagem() const { return "A estrutura linear está vazia."; }
private:

};

#endif	/* ESTRUTURALINEARVAZIA_H */

