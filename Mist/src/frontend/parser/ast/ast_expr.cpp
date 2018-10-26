#include "ast_expr.hpp"
#include "ast_decl.hpp"

namespace ast {
	ExprKind Expr::kind() { return k; }
	
	Type* Expr::type() { return t; }
	
	mist::Pos Expr::pos() { return p; }

	Expr::Expr(ExprKind k, mist::Pos p) : k(k), p(p) {}

	ValueExpr::ValueExpr(Ident* name) : Expr(Value, name->pos), name(name) {}
	
	TupleExpr::TupleExpr(const std::vector<Expr*>& values, mist::Pos pos) : Expr(Tuple, pos), values(values) {

	}
	
	IntegerConstExpr::IntegerConstExpr(i64 val, ConstantType cty, mist::Pos pos) : Expr(IntegerConst, pos),
		value(val), cty(cty) {}
	
	FloatConstExpr::FloatConstExpr(f64 val, ConstantType cty, mist::Pos pos) : Expr(FloatConst, pos),
		value(val), cty(cty) {	}
	
	StringConstExpr::StringConstExpr(const std::string& val, mist::Pos pos) : Expr(StringConst, pos), value(value) {
	}
	
	BooleanConstExpr::BooleanConstExpr(bool val, mist::Pos pos) : Expr(BooleanConst, pos), value(val) {
	}
	
	CharConstExpr::CharConstExpr(char val, mist::Pos pos) : Expr(CharConst, pos), value(val) {
	}
	
	BinaryExpr::BinaryExpr(BinaryOp op, Expr* lhs, Expr* rhs, mist::Pos pos) : Expr(Binary, pos),
		op(op), lhs(lhs), rhs(rhs) {}
	
	UnaryExpr::UnaryExpr(UnaryOp op, Expr* expr, mist::Pos pos) : Expr(Unary, pos), op(op), expr(expr) {
	}
	
	IfExpr::IfExpr(Expr* cond, Expr* body, mist::Pos pos) : Expr(If, pos), cond(cond), body(body) {
	}
	
	WhileExpr::WhileExpr(Expr* cond, Expr* body, mist::Pos pos) : Expr(While, pos), cond(cond), body(body) {
	}
	
	LoopExpr::LoopExpr(Expr* body, mist::Pos pos) : Expr(Loop, pos), body(body) {
	}
	
	ForExpr::ForExpr(Expr* index, Expr* expr, Expr* body, mist::Pos pos) : Expr(For, pos), index(index), expr(expr), body(body) {
	}
	
	MatchArm::MatchArm(Expr* name, Ident* value, Expr* body) : name(name), value(value), body(body) {
	}
	
	MatchExpr::MatchExpr(Expr* cond, const std::vector<MatchArm*>& arms, mist::Pos pos) : Expr(Match, pos), cond(cond), arms(arms) {
	}
	
	DeclExpr::DeclExpr(Decl* decl) : Expr(ExprKind::DeclDecl, decl->pos), decl(decl) {
	}
	
	ParenthesisExpr::ParenthesisExpr(Expr* operand) : Expr(Parenthesis, operand->pos()), operand(operand) {
	}
	
	SelectorExpr::SelectorExpr(Expr* operand, TypeSpec* element, mist::Pos pos) : Expr(Selector, pos), operand(operand), element(element) {
	}
	
	BreakExpr::BreakExpr(mist::Pos pos) : Expr(Break, pos) {
	}
	
	ContinueExpr::ContinueExpr(mist::Pos pos) : Expr(Continue, pos) {
	}
	
	ReturnExpr::ReturnExpr(const std::vector<Expr*> returns, mist::Pos pos) : Expr(Return, pos), returns(returns) {
	}
	
	CastExpr::CastExpr(Expr* expr, TypeSpec* ty, mist::Pos pos) : Expr(Cast, pos), expr(expr), ty(ty) {
	}
	
	RangeExpr::RangeExpr(Expr* low, Expr* high, Expr* count, mist::Pos pos) : Expr(Range, pos), low(low), high(high), count(count) {
	}
	
	SliceExpr::SliceExpr(Expr* low, Expr* high, mist::Pos pos) : Expr(Slice, pos), low(low), high(high) {
	}
	
	TupleIndexExpr::TupleIndexExpr(Expr* operand, i32 index, mist::Pos pos) : Expr(TupleIndex, pos), operand(operand), index(index) {
	}
	
	AssignmentExpr::AssignmentExpr(AssignmentOp op, const std::vector<Expr*> lvalues, Expr* expr, mist::Pos pos) : Expr(Assignment, pos), op(op), lvalues(lvalues), expr(expr) {
	}
	
	BlockExpr::BlockExpr(const std::vector<Expr*> elements, mist::Pos pos) : Expr(Block, pos), elements(elements) {
	}
}