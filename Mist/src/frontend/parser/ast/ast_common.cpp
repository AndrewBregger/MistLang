
#include "ast_common.hpp"

namespace mist {
    Pos::Pos() = default;
    Pos::Pos(u32 line, u32 column, u32 span, u64 fileId) : line(line), column(column),
        span(span), fileId(fileId) {}

    Pos Pos::operator+ (const Pos& p) {
        Pos pos = *this;
        pos.span += p.span;
        return pos;
    }
}

namespace ast {
    Ident::Ident(mist::String* value,
        const mist::Pos& pos) : value(value), pos(pos) { }
    
    WhereElement::WhereElement(Ident* parameter, TypeSpec* type,
        mist::Pos pos) : parameter(parameter), type(type), pos(pos) { }

    WhereClause::WhereClause(const std::vector<WhereElement*>& elems,
        mist::Pos pos) : elements(elems), pos(pos) { }
}