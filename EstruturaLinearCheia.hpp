/* 
 * File:   EstruturaLinearCheia.h
 * Author: paladini
 *
 * Created on August 23, 2014, 9:05 PM
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

