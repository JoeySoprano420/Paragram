# Creating a structured output with three major parts:
# 1. The Paragram EBNF Grammar
# 2. Scaffold Compiler Design (in pseudocode/C++)
# 3. Full Program Suite with REPL and runtime injection

from IPython.display import Markdown

paragram_ebnf = """
# --------------------------------------------
# PARAGRAM EBNF GRAMMAR SPECIFICATION
# --------------------------------------------

Program          ::= { Statement ";" } ;
Statement        ::= Declaration
                  | Assignment
                  | FunctionDef
                  | FunctionCall
                  | Conditional
                  | Loop
                  | Event
                  | Thread
                  | MemoryOp
                  | Directive ;

Declaration      ::= Identifier ":" Type ;
Assignment       ::= Identifier "=" Expression ;
FunctionDef      ::= "^" Identifier "(" [ ParamList ] ")" "=" Block ;
FunctionCall     ::= "!" Identifier [ "." Identifier ] [ "(" ArgList ")" ] ;
Conditional      ::= "?" Expression ">" Statement [ "|" Statement ] ;
Loop             ::= "loop" ":" Range ">" FunctionDef ;
Event            ::= "event" ":" Identifier ">" FunctionCall ;
Thread           ::= "thread" ":" "spawn" ">" FunctionCall ;
MemoryOp         ::= Identifier ":" "aloc" "[" Number "]"
                  | "%" Identifier ":" StackOp ;

Directive        ::= "use" ":" Identifier
                  | "sheet" ":" Identifier
                  | "mode" ":" Identifier ;

Expression       ::= Term { Operator Term } ;
Term             ::= Identifier | Number | String | FunctionCall ;
Operator         ::= "+" | "-" | "*" | "/" | ">" | "<" | "==" ;

Range            ::= Number ".." Number ;
Block            ::= "(" { Statement ";" } ")" ;
ParamList        ::= Identifier { "," Identifier } ;
ArgList          ::= Expression { "," Expression } ;

Type             ::= "int" | "text" | "bool" | "float" | "void" ;
StackOp          ::= "push" "." Identifier
                  | "pop" "." Identifier ;

Identifier       ::= Letter { Letter | Digit | "_" } ;
Number           ::= Digit { Digit } ;
String           ::= '"' { Character } '"' ;

Letter           ::= "A".."Z" | "a".."z" ;
Digit            ::= "0".."9" ;
Character        ::= ? any printable character ? ;
"""

scaffold_compiler = """
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

    emitter.saveTo("out.asm");
    return 0;
}
"""

repl_runtime_suite = """
# --------------------------------------------
# PARAGRAM FULL PROGRAM SUITE (REPL + Runtime)
// --------------------------------------------

import readline

class ParagramREPL:
    def __init__(self):
        self.env = {}  # Variable and function scope
        self.memory = bytearray(1024)  # Simple memory simulation
        self.pc = 0  # Instruction pointer

    def run(self):
        print("Paragram REPL. Type 'exit' to quit.")
        while True:
            try:
                line = input(">>> ")
                if line.strip() == "exit":
                    break
                self.eval_line(line)
            except Exception as e:
                print("Error:", e)

    def eval_line(self, line):
        # Simulate parsing and executing a single statement
        tokens = self.tokenize(line)
        if not tokens:
            return
        cmd = tokens[0]
        if cmd == "let" and tokens[2] == "=":
            self.env[tokens[1]] = self.eval_expr(tokens[3:])
        elif cmd.startswith("!"):
            func_name = cmd[1:]
            if func_name in self.env and callable(self.env[func_name]):
                self.env[func_name]()
        elif cmd == "print":
            print(self.eval_expr(tokens[1:]))
        elif cmd.startswith("def"):
            name = tokens[1]
            args = tokens[2].strip("()").split(",")
            body = " ".join(tokens[3:])
            self.env[name] = lambda *a: print("Simulated call to", name, "with", a)
        else:
            print("Unknown command")

    def tokenize(self, line):
        return line.replace("(", " ( ").replace(")", " ) ").split()

    def eval_expr(self, tokens):
        try:
            return int(tokens[0])
        except:
            return self.env.get(tokens[0], tokens[0])

if __name__ == "__main__":
    repl = ParagramREPL()
    repl.run()
"""

# Display in Markdown
full_output = f"""
# **PARAGRAM Language Toolkit**

## 1. EBNF Grammar

```ebnf
{paragram_ebnf}
