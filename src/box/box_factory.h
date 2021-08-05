#ifndef LATEX_BOX_FACTORY_H
#define LATEX_BOX_FACTORY_H

#include "atom/atom.h"

namespace tex {

class SymbolAtom;

/** Create a horizontal delimiter with given symbol and size */
sptr<Box> createHDelim(const sptr<SymbolAtom>& sym, Env& env, int size);

/** Create a vertical delimiter with given symbol and size */
sptr<Box> createVDelim(const sptr<SymbolAtom>& sym, Env& env, int size);

/** Create a horizontal delimiter with given symbol and width */
sptr<Box> createHDelim(const std::string& sym, Env& env, float width, bool round = false);

/** Create a vertical delimiter with given symbol and height */
sptr<Box> createVDelim(const std::string& sym, Env& env, float height, bool round = false);

}

#endif //LATEX_BOX_FACTORY_H
