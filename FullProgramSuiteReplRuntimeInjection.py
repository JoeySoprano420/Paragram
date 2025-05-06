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
