#ifndef LATEX_MACRO_DECL_H
#define LATEX_MACRO_DECL_H

#include "core/formula.h"
#include "core/parser.h"
#include "atom/atom.h"

namespace tex {

#ifndef macro
#define macro(name) sptr<Atom> macro_##name(TeXParser& tp, Args& args)
#endif

}

#endif //LATEX_MACRO_DECL_H
