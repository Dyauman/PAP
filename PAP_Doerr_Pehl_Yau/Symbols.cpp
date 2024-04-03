#include "Symbols.h"

Symbols::Symbols(Symb symb, bool selected, int symb_number) : symbol(symb), symb_selected(selected), symb_number(symb_number) {}


int Symbols::get_current_lineCnt()
{
    return current_lineCnt;
}

void Symbols::set_symbol(Symbols::Symb symb)
{
    switch (symb)
    {
    case Symbols::Symb::rectangle:
        break;

    case Symbols::Symb::diamond:
        break;

    case Symbols::Symb::oval:
        break;

    case Symbols::Symb::input_symb:
        break;

    case Symbols::Symb::output_symb:
        break;

    default:
        break;
    }
}
