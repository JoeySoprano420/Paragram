// --------------------------------------------
// PARAGRAM COMPILER SCAFFOLD (C++ Style Pseudo)
// --------------------------------------------

class Token {
    enum Type { IDENT, NUMBER, STRING, SYMBOL, KEYWORD };
    Type type;
    std::string value;
};

class Lexer {
public:
    std::vector<Token> tokenize(const std::string& code);
};
enum Type { IDENT, NUMBER, STRING, SYMBOL, KEYWORD, OPERATOR };


class ASTNode {
public:
    virtual void compile(NASMEmitter& out) = 0;
};

class Parser {
    std::vector<Token> tokens;
    int pos;
public:
    ASTNode* parseProgram();
    ASTNode* parseStatement();
    ASTNode* parseExpression();
};
ASTNode* parseOperator();


class NASMEmitter {
public:
    void emit(const std::string& line);
    void emitFunction(const std::string& name, std::vector<ASTNode*> body);
    void emitAssignment(const std::string& var, const std::string& val);
};

int main(int argc, char** argv) {
    std::string code = loadFile(argv[1]);
    Lexer lexer;
    auto tokens = lexer.tokenize(code);

    Parser parser(tokens);
    auto program = parser.parseProgram();

    NASMEmitter emitter;
    program->compile(emitter);
    void NASMEmitter::emitAssignment(const std::string& var, const std::string& val) {
    emit("mov " + var + ", " + val);
    emit("add " + var + ", 1"); // Example optimization
}


    emitter.saveTo("out.asm");
    return 0;
}

