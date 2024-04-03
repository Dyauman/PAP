#ifndef SYMBOLS_H
#define SYMBOLS_H

#include <QString>
#include "drag_drop.h"


class Symbols
{
public:

    enum class Symb
    {
        rectangle,
        oval,
        diamond,
        input_symb,
        output_symb,
    };

    Symb symbol;        // Member zum Speichern des Enum-Werts



    int get_current_lineCnt();


    Symbols(Symb symb, bool selected, int symb_number);


    void set_symbol(Symb symb);

    QString set_text(Symb symb, position p);

private:
    int current_lineCnt = 0;
    int symb_number = 0;
    bool symb_selected = false;
    QString text = "";
};



#endif // SYMBOLS_H
