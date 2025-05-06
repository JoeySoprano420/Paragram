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
enum Type { IDENT, NUMBER, STRING, SYMBOL, KEYWORD, OPERATOR, FLOW, MEMORY };


class Parser {
    std::vector<Token> tokens;
    int pos;
public:
    ASTNode* parseProgram();
    ASTNode* parseStatement();
if (token.type == SYMBOL && token.value == "?") {
    return parseConditionalFlow();
}

    ASTNode* parseExpression();
};
ASTNode* parseOperator();
if (token.type == SYMBOL && token.value == "?") {
    return parseConditionalFlow();
}
ASTNode* parseConditionalFlow();
ASTNode* parseParallelExecution();


class NASMEmitter {
public:
    void emit(const std::string& line);
    void emitFunction(const std::string& name, std::vector<ASTNode*> body);
    void emitAssignment(const std::string& var, const std::string& val);
};
void NASMEmitter::emitAssignment(const std::string& var, const std::string& val) {
    emit("mov " + var + ", " + val);
    emit("add " + var + ", 1"); // Example optimization
}


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


if (token.type == SYMBOL && token.value == "?") {
    return parseConditionalFlow();
}
std::vector<std::thread> workers;
for (auto& node : ASTNodes) {
    workers.emplace_back([&]() { node->compile(NASMEmitterInstance); });
}
for (auto& worker : workers) {
    worker.join();
}
std::priority_queue<ExecutionBlock> taskQueue;
while (!taskQueue.empty()) {
    auto task = taskQueue.top();
    taskQueue.pop();
    std::thread worker([&]() { executeBlock(task); });
    worker.detach();
}
void NASMEmitter::emitFunction(const std::string& name, std::vector<ASTNode*> body) {
    std::vector<std::thread> workers;
    for (ASTNode* node : body) {
        workers.emplace_back([&]() { node->compile(*this); });
    }
    for (auto& worker : workers) {
        worker.join();  // Ensure all nodes are compiled before proceeding.
    }
}

class ExecutionScheduler {
public:
    std::priority_queue<ExecutionBlock> taskQueue;

    void scheduleTask(ExecutionBlock task) {
        taskQueue.push(task);
    }

    void executeTasks() {
        while (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();
            std::thread worker([&]() { executeBlock(task); });
            worker.detach();  // Run asynchronously.
        }
    }
};
ExecutionScheduler scheduler;
scheduler.scheduleTask(program->compile(NASMEmitterInstance));
scheduler.executeTasks();
class ExecutionScheduler {
public:
    std::priority_queue<ExecutionBlock, std::vector<ExecutionBlock>, ComparePriority> taskQueue;

    void scheduleTask(ExecutionBlock task) {
        taskQueue.push(task);
    }

    void executeTasks() {
        while (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();
            std::thread worker([&]() { executeBlock(task); });
            worker.detach();  // Run asynchronously.
        }
    }
};
class ExecutionBlock {
public:
    int priority;  // Higher value = higher priority
    std::function<void()> execute;

    bool operator<(const ExecutionBlock& other) const {
        return priority < other.priority;  // Lower priority tasks run later
    }
};
if (token.type == SYMBOL && token.value == ">") {
    ExecutionBlock task = { priority: calculatePriority(token), execute: parseExecutionBlock(token) };
    scheduler.scheduleTask(task);
}

// --------------------------------------------
// PARAGRAM COMPILER SCAFFOLD (Expanded C++ Style)
// --------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <queue>
#include <functional>
#include <unordered_map>

// --------------------------------------------
// TOKEN SYSTEM
// --------------------------------------------

enum class TokenType {
    IDENT, NUMBER, STRING, SYMBOL, KEYWORD, OPERATOR, FLOW, MEMORY
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    std::vector<Token> tokenize(const std::string& code);
};

// --------------------------------------------
// AST SYSTEM
// --------------------------------------------

class NASMEmitter;  // Forward declaration

class ASTNode {
public:
    virtual void compile(NASMEmitter& out) = 0;
    virtual ~ASTNode() = default;
};

class Parser {
    std::vector<Token> tokens;
    size_t pos = 0;

public:
    Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {}

    ASTNode* parseProgram();
    ASTNode* parseStatement();
    ASTNode* parseExpression();
    ASTNode* parseOperator();
    ASTNode* parseConditionalFlow();
    ASTNode* parseParallelExecution();
};

// --------------------------------------------
// NASM EMITTER
// --------------------------------------------

class NASMEmitter {
    std::ofstream outFile;

public:
    void emit(const std::string& line) {
        outFile << line << "\n";
    }

    void emitFunction(const std::string& name, const std::vector<ASTNode*>& body) {
        std::vector<std::thread> workers;
        for (ASTNode* node : body) {
            workers.emplace_back([this, node]() {
                node->compile(*this);
            });
        }
        for (auto& worker : workers) {
            worker.join();
        }
    }

    void emitAssignment(const std::string& var, const std::string& val) {
        emit("mov " + var + ", " + val);
        emit("add " + var + ", 1"); // Optimization example
    }

    void open(const std::string& filename) {
        outFile.open(filename);
    }

    void saveTo(const std::string& filename) {
        outFile.close();
    }
};

// --------------------------------------------
// EXECUTION SCHEDULER
// --------------------------------------------

class ExecutionBlock {
public:
    int priority;
    std::function<void()> execute;

    bool operator<(const ExecutionBlock& other) const {
        return priority < other.priority;
    }
};

struct ComparePriority {
    bool operator()(const ExecutionBlock& a, const ExecutionBlock& b) const {
        return a.priority < b.priority;
    }
};

class ExecutionScheduler {
    std::priority_queue<ExecutionBlock, std::vector<ExecutionBlock>, ComparePriority> taskQueue;

public:
    void scheduleTask(const ExecutionBlock& task) {
        taskQueue.push(task);
    }

    void executeTasks() {
        while (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();
            std::thread worker([task]() { task.execute(); });
            worker.detach();
        }
    }
};

// --------------------------------------------
// MAIN FUNCTION
// --------------------------------------------

std::string loadFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: parac <file.para>" << std::endl;
        return 1;
    }

    std::string code = loadFile(argv[1]);
    Lexer lexer;
    auto tokens = lexer.tokenize(code);

    Parser parser(tokens);
    ASTNode* program = parser.parseProgram();

    NASMEmitter emitter;
    emitter.open("out.asm");
    program->compile(emitter);
    emitter.saveTo("out.asm");

    ExecutionScheduler scheduler;
    scheduler.scheduleTask({10, [&]() { program->compile(emitter); }});
    scheduler.executeTasks();

    return 0;
}




class ExecutionBlock {
public:
    int priority;
    std::vector<ExecutionBlock*> dependencies;  // Track dependencies
    std::function<void()> execute;

    bool operator<(const ExecutionBlock& other) const {
        return priority < other.priority;
    }

    bool readyToExecute() const {
        return std::all_of(dependencies.begin(), dependencies.end(),
                           [](const ExecutionBlock* dep) { return dep == nullptr; });
    }
};
class ExecutionScheduler {
    std::priority_queue<ExecutionBlock, std::vector<ExecutionBlock>, ComparePriority> taskQueue;
    std::unordered_map<std::string, ExecutionBlock*> taskMap;  // Track execution states

public:
    void scheduleTask(const ExecutionBlock& task) {
        taskMap[task.execute.target_type().name()] = new ExecutionBlock(task);
        taskQueue.push(task);
    }

    void executeTasks() {
        while (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();

            if (task.readyToExecute()) {
                std::thread worker([task]() { task.execute(); });
                worker.detach();
            } else {
                // Re-queue task until dependencies resolve
                taskQueue.push(task);
            }
        }
    }
};
if (token.type == SYMBOL && token.value == ">") {
    ExecutionBlock* task = new ExecutionBlock({priority: calculatePriority(token), execute: parseExecutionBlock(token)});
    scheduler.scheduleTask(*task);
}
class ExecutionBlock {
public:
    int priority;
    std::vector<ExecutionBlock*> dependencies;
    std::function<void()> execute;

    bool operator<(const ExecutionBlock& other) const {
        return calculatePriority() < other.calculatePriority();
    }

    int calculatePriority() const {
        int basePriority = priority;
        int dependencyWeight = dependencies.size() * 5;  // More dependencies = higher priority
        int resourceWeight = checkSystemLoad();  // Adjust based on CPU/memory usage
        return basePriority + dependencyWeight - resourceWeight;
    }

    bool readyToExecute() const {
        return std::all_of(dependencies.begin(), dependencies.end(),
                           [](const ExecutionBlock* dep) { return dep == nullptr; });
    }
};
class ExecutionScheduler {
    std::priority_queue<ExecutionBlock, std::vector<ExecutionBlock>, ComparePriority> taskQueue;
    std::unordered_map<std::string, ExecutionBlock*> taskMap;

public:
    void scheduleTask(ExecutionBlock& task) {
        task.priority = task.calculatePriority();  // Dynamically adjust priority
        taskMap[task.execute.target_type().name()] = &task;
        taskQueue.push(task);
    }

    void executeTasks() {
        while (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();

            if (task.readyToExecute()) {
                std::thread worker([task]() { task.execute(); });
                worker.detach();
            } else {
                task.priority += 2;  // Increase priority for re-queued tasks
                taskQueue.push(task);
            }
        }
    }
};
#include <sys/sysinfo.h>

int checkSystemLoad() {
    struct sysinfo info;
    sysinfo(&info);
    int cpuLoad = (info.loads[0] / 65536.0) * 100;  // Convert load average to percentage
    int memoryUsage = ((info.totalram - info.freeram) / (double)info.totalram) * 100;
    return cpuLoad + memoryUsage;  // Higher value = more system load
}
class ExecutionScheduler {
    std::priority_queue<ExecutionBlock, std::vector<ExecutionBlock>, ComparePriority> taskQueue;
    std::unordered_map<std::string, ExecutionBlock*> taskMap;

public:
    void scheduleTask(ExecutionBlock& task) {
        int systemLoad = checkSystemLoad();
        task.priority = task.calculatePriority() - (systemLoad / 10);  // Reduce priority if system load is high
        taskMap[task.execute.target_type().name()] = &task;
        taskQueue.push(task);
    }

    void executeTasks() {
        while (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();

            if (task.readyToExecute()) {
                std::thread worker([task]() { task.execute(); });
                worker.detach();
            } else {
                task.priority += 2;  // Increase priority for re-queued tasks
                taskQueue.push(task);
            }
        }
    }
};
if (token.type == SYMBOL && token.value == ">") {
    ExecutionBlock* task = new ExecutionBlock({priority: calculatePriority(token), execute: parseExecutionBlock(token)});
    scheduler.scheduleTask(*task);
}

#include <sys/sysinfo.h>

int checkSystemLoad() {
    struct sysinfo info;
    sysinfo(&info);
    int cpuLoad = (info.loads[0] / 65536.0) * 100;  // Convert load average to percentage
    int memoryUsage = ((info.totalram - info.freeram) / (double)info.totalram) * 100;
    return cpuLoad + memoryUsage;  // Higher value = more system load
}
class ExecutionScheduler {
    std::priority_queue<ExecutionBlock, std::vector<ExecutionBlock>, ComparePriority> taskQueue;
    std::unordered_map<std::string, ExecutionBlock*> taskMap;

public:
    void scheduleTask(ExecutionBlock& task) {
        int systemLoad = checkSystemLoad();
        task.priority = task.calculatePriority() - (systemLoad / 10);  // Reduce priority if system load is high
        taskMap[task.execute.target_type().name()] = &task;
        taskQueue.push(task);
    }

    void executeTasks() {
        while (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();

            if (task.readyToExecute()) {
                std::thread worker([task]() { task.execute(); });
                worker.detach();
            } else {
                task.priority += 2;  // Increase priority for re-queued tasks
                taskQueue.push(task);
            }
        }
    }
};
if (token.type == SYMBOL && token.value == ">") {
    ExecutionBlock* task = new ExecutionBlock({priority: calculatePriority(token), execute: parseExecutionBlock(token)});
    scheduler.scheduleTask(*task);
}
#include <sys/sysinfo.h>

int checkSystemLoad() {
    struct sysinfo info;
    sysinfo(&info);
    int cpuLoad = (info.loads[0] / 65536.0) * 100;  // Convert load average to percentage
    int memoryUsage = ((info.totalram - info.freeram) / (double)info.totalram) * 100;
    return cpuLoad + memoryUsage;  // Higher value = more system load
}
class ExecutionScheduler {
    std::priority_queue<ExecutionBlock, std::vector<ExecutionBlock>, ComparePriority> taskQueue;
    std::unordered_map<std::string, ExecutionBlock*> taskMap;

public:
    void scheduleTask(ExecutionBlock& task) {
        int systemLoad = checkSystemLoad();
        task.priority = task.calculatePriority() - (systemLoad / 10);  // Reduce priority if system load is high
        taskMap[task.execute.target_type().name()] = &task;
        taskQueue.push(task);
    }

    void executeTasks() {
        while (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();

            if (task.readyToExecute()) {
                std::thread worker([task]() { task.execute(); });
                worker.detach();
            } else {
                task.priority += 2;  // Increase priority for re-queued tasks
                taskQueue.push(task);
            }
        }
    }
};
if (token.type == SYMBOL && token.value == ">") {
    ExecutionBlock* task = new ExecutionBlock({priority: calculatePriority(token), execute: parseExecutionBlock(token)});
    scheduler.scheduleTask(*task);
}

// --------------------------------------------
// PARAGRAM COMPILER SCAFFOLD (Extended C++ Style)
// --------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <queue>
#include <functional>
#include <unordered_map>
#include <sstream>
#include <mutex>
#include <optional>
#include <variant>

// --------------------------------------------
// TOKEN SYSTEM
// --------------------------------------------

enum class TokenType {
    IDENT, NUMBER, STRING, SYMBOL, KEYWORD, OPERATOR, FLOW, MEMORY, WHITESPACE, COMMENT
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
};

class Lexer {
    std::string source;
    size_t index = 0;
    int line = 1;
    int column = 0;

public:
    std::vector<Token> tokenize(const std::string& code);
    Token nextToken();
    bool isSymbol(char c);
    bool isOperator(char c);
    bool isKeyword(const std::string& str);
};

// --------------------------------------------
// AST SYSTEM
// --------------------------------------------

class NASMEmitter;  // Forward declaration

class ASTNode {
public:
    virtual void compile(NASMEmitter& out) = 0;
    virtual std::string debug() const = 0;
    virtual ~ASTNode() = default;
};

class ASTAssignment : public ASTNode {
    std::string var;
    std::string value;
public:
    ASTAssignment(std::string v, std::string val) : var(std::move(v)), value(std::move(val)) {}
    void compile(NASMEmitter& out) override;
    std::string debug() const override { return "Assignment(" + var + " = " + value + ")"; }
};

class ASTFunction : public ASTNode {
    std::string name;
    std::vector<std::string> params;
    std::vector<ASTNode*> body;
public:
    ASTFunction(std::string n, std::vector<std::string> p, std::vector<ASTNode*> b)
        : name(std::move(n)), params(std::move(p)), body(std::move(b)) {}
    void compile(NASMEmitter& out) override;
    std::string debug() const override { return "Function(" + name + ")"; }
};

class Parser {
    std::vector<Token> tokens;
    size_t pos = 0;

public:
    Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {}

    ASTNode* parseProgram();
    ASTNode* parseStatement();
    ASTNode* parseExpression();
    ASTNode* parseAssignment();
    ASTNode* parseFunction();
    ASTNode* parseConditionalFlow();
    ASTNode* parseParallelExecution();
    ASTNode* parseRawASM();
};

// --------------------------------------------
// NASM EMITTER
// --------------------------------------------

class NASMEmitter {
    std::ofstream outFile;
    std::mutex emitMutex;

public:
    void emit(const std::string& line) {
        std::lock_guard<std::mutex> lock(emitMutex);
        outFile << line << "\n";
    }

    void emitFunction(const std::string& name, const std::vector<ASTNode*>& body) {
        std::vector<std::thread> workers;
        for (ASTNode* node : body) {
            workers.emplace_back([this, node]() {
                node->compile(*this);
            });
        }
        for (auto& worker : workers) {
            worker.join();
        }
    }

    void emitAssignment(const std::string& var, const std::string& val) {
        emit("mov " + var + ", " + val);
        emit("add " + var + ", 1"); // Optimization example
    }

    void open(const std::string& filename) {
        outFile.open(filename);
    }

    void saveTo(const std::string& filename) {
        outFile.close();
    }
};

// --------------------------------------------
// EXECUTION SCHEDULER
// --------------------------------------------

class ExecutionBlock {
public:
    int priority;
    std::function<void()> execute;

    bool operator<(const ExecutionBlock& other) const {
        return priority < other.priority;
    }
};

struct ComparePriority {
    bool operator()(const ExecutionBlock& a, const ExecutionBlock& b) const {
        return a.priority < b.priority;
    }
};

class ExecutionScheduler {
    std::priority_queue<ExecutionBlock, std::vector<ExecutionBlock>, ComparePriority> taskQueue;

public:
    void scheduleTask(const ExecutionBlock& task) {
        taskQueue.push(task);
    }

    void executeTasks() {
        while (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();
            std::thread worker([task]() { task.execute(); });
            worker.detach();
        }
    }
};

// --------------------------------------------
// MAIN FUNCTION
// --------------------------------------------

std::string loadFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: parac <file.para>" << std::endl;
        return 1;
    }

    std::string code = loadFile(argv[1]);
    Lexer lexer;
    auto tokens = lexer.tokenize(code);

    Parser parser(tokens);
    ASTNode* program = parser.parseProgram();

    NASMEmitter emitter;
    emitter.open("out.asm");
    program->compile(emitter);
    emitter.saveTo("out.asm");

    ExecutionScheduler scheduler;
    scheduler.scheduleTask({10, [&]() { program->compile(emitter); }});
    scheduler.executeTasks();

    return 0;
}

// --------------------------------------------
// PARAGRAM COMPILER SCAFFOLD (Extended C++ Style + Plugin + Error Handling)
// --------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <queue>
#include <functional>
#include <unordered_map>
#include <sstream>
#include <mutex>
#include <optional>
#include <variant>
#include <map>
#include <stdexcept>

// --------------------------------------------
// ERROR REPORTING MODULE
// --------------------------------------------

class ErrorReporter {
public:
    static void report(const std::string& message, int line = -1, int column = -1) {
        std::cerr << "[Error] " << message;
        if (line >= 0 && column >= 0) {
            std::cerr << " (Line: " << line << ", Column: " << column << ")";
        }
        std::cerr << std::endl;
    }
};

// --------------------------------------------
// TOKEN SYSTEM
// --------------------------------------------

enum class TokenType {
    IDENT, NUMBER, STRING, SYMBOL, KEYWORD, OPERATOR, FLOW, MEMORY, WHITESPACE, COMMENT
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
};

class Lexer {
    std::string source;
    size_t index = 0;
    int line = 1;
    int column = 0;

public:
    std::vector<Token> tokenize(const std::string& code);
    Token nextToken();
    bool isSymbol(char c);
    bool isOperator(char c);
    bool isKeyword(const std::string& str);
};

// --------------------------------------------
// AST SYSTEM
// --------------------------------------------

class NASMEmitter;  // Forward declaration

class ASTNode {
public:
    virtual void compile(NASMEmitter& out) = 0;
    virtual std::string debug() const = 0;
    virtual ~ASTNode() = default;
};

class ASTAssignment : public ASTNode {
    std::string var;
    std::string value;
public:
    ASTAssignment(std::string v, std::string val) : var(std::move(v)), value(std::move(val)) {}
    void compile(NASMEmitter& out) override;
    std::string debug() const override { return "Assignment(" + var + " = " + value + ")"; }
};

class ASTFunction : public ASTNode {
    std::string name;
    std::vector<std::string> params;
    std::vector<ASTNode*> body;
public:
    ASTFunction(std::string n, std::vector<std::string> p, std::vector<ASTNode*> b)
        : name(std::move(n)), params(std::move(p)), body(std::move(b)) {}
    void compile(NASMEmitter& out) override;
    std::string debug() const override { return "Function(" + name + ")"; }
};

class Parser {
    std::vector<Token> tokens;
    size_t pos = 0;

public:
    Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {}

    ASTNode* parseProgram();
    ASTNode* parseStatement();
    ASTNode* parseExpression();
    ASTNode* parseAssignment();
    ASTNode* parseFunction();
    ASTNode* parseConditionalFlow();
    ASTNode* parseParallelExecution();
    ASTNode* parseRawASM();
};

// --------------------------------------------
// NASM EMITTER
// --------------------------------------------

class NASMEmitter {
    std::ofstream outFile;
    std::mutex emitMutex;

public:
    void emit(const std::string& line) {
        std::lock_guard<std::mutex> lock(emitMutex);
        outFile << line << "\n";
    }

    void emitFunction(const std::string& name, const std::vector<ASTNode*>& body) {
        std::vector<std::thread> workers;
        for (ASTNode* node : body) {
            workers.emplace_back([this, node]() {
                node->compile(*this);
            });
        }
        for (auto& worker : workers) {
            worker.join();
        }
    }

    void emitAssignment(const std::string& var, const std::string& val) {
        emit("mov " + var + ", " + val);
        emit("add " + var + ", 1");
    }

    void open(const std::string& filename) {
        outFile.open(filename);
    }

    void saveTo(const std::string& filename) {
        outFile.close();
    }
};

// --------------------------------------------
// PLUGIN ARCHITECTURE
// --------------------------------------------

using PluginFunction = std::function<void(NASMEmitter&, const std::vector<std::string>&)>;

class PluginManager {
    std::unordered_map<std::string, PluginFunction> plugins;

public:
    void registerPlugin(const std::string& name, PluginFunction func) {
        plugins[name] = func;
    }

    bool hasPlugin(const std::string& name) const {
        return plugins.find(name) != plugins.end();
    }

    void invokePlugin(const std::string& name, NASMEmitter& emitter, const std::vector<std::string>& args) const {
        auto it = plugins.find(name);
        if (it != plugins.end()) {
            it->second(emitter, args);
        } else {
            ErrorReporter::report("Plugin not found: " + name);
        }
    }
};

// --------------------------------------------
// EXECUTION SCHEDULER
// --------------------------------------------

class ExecutionBlock {
public:
    int priority;
    std::function<void()> execute;

    bool operator<(const ExecutionBlock& other) const {
        return priority < other.priority;
    }
};

struct ComparePriority {
    bool operator()(const ExecutionBlock& a, const ExecutionBlock& b) const {
        return a.priority < b.priority;
    }
};

class ExecutionScheduler {
    std::priority_queue<ExecutionBlock, std::vector<ExecutionBlock>, ComparePriority> taskQueue;

public:
    void scheduleTask(const ExecutionBlock& task) {
        taskQueue.push(task);
    }

    void executeTasks() {
        while (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();
            std::thread worker([task]() { task.execute(); });
            worker.detach();
        }
    }
};

// --------------------------------------------
// MAIN FUNCTION
// --------------------------------------------

std::string loadFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char** argv) {
    if (argc < 2) {
        ErrorReporter::report("Usage: parac <file.para>");
        return 1;
    }

    std::string code = loadFile(argv[1]);
    Lexer lexer;
    std::vector<Token> tokens;

    try {
        tokens = lexer.tokenize(code);
    } catch (const std::exception& e) {
        ErrorReporter::report("Lexer error: " + std::string(e.what()));
        return 1;
    }

    Parser parser(tokens);
    ASTNode* program = nullptr;

    try {
        program = parser.parseProgram();
    } catch (const std::exception& e) {
        ErrorReporter::report("Parser error: " + std::string(e.what()));
        return 1;
    }

    NASMEmitter emitter;
    emitter.open("out.asm");
    program->compile(emitter);
    emitter.saveTo("out.asm");

    ExecutionScheduler scheduler;
    scheduler.scheduleTask({10, [&]() { program->compile(emitter); }});
    scheduler.executeTasks();

    return 0;
}


// --------------------------------------------
// PARAGRAM COMPILER SCAFFOLD (Extended C++ Style + Plugin + Error Handling + Dynamic Loader)
// --------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <queue>
#include <functional>
#include <unordered_map>
#include <sstream>
#include <mutex>
#include <optional>
#include <variant>
#include <map>
#include <stdexcept>
#include <filesystem>

namespace fs = std::filesystem;

// --------------------------------------------
// ERROR REPORTING MODULE
// --------------------------------------------

class ErrorReporter {
public:
    static void report(const std::string& message, int line = -1, int column = -1) {
        std::cerr << "[Error] " << message;
        if (line >= 0 && column >= 0) {
            std::cerr << " (Line: " << line << ", Column: " << column << ")";
        }
        std::cerr << std::endl;
    }
};

// --------------------------------------------
// TOKEN SYSTEM
// --------------------------------------------

enum class TokenType {
    IDENT, NUMBER, STRING, SYMBOL, KEYWORD, OPERATOR, FLOW, MEMORY, WHITESPACE, COMMENT
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
};

class Lexer {
    std::string source;
    size_t index = 0;
    int line = 1;
    int column = 0;

public:
    std::vector<Token> tokenize(const std::string& code);
    Token nextToken();
    bool isSymbol(char c);
    bool isOperator(char c);
    bool isKeyword(const std::string& str);
};

// --------------------------------------------
// AST SYSTEM
// --------------------------------------------

class NASMEmitter;  // Forward declaration

class ASTNode {
public:
    virtual void compile(NASMEmitter& out) = 0;
    virtual std::string debug() const = 0;
    virtual ~ASTNode() = default;
};

class ASTMacro : public ASTNode {
    std::string macroName;
    std::vector<std::string> args;
public:
    ASTMacro(std::string name, std::vector<std::string> arguments) : macroName(std::move(name)), args(std::move(arguments)) {}
    void compile(NASMEmitter& out) override;
    std::string debug() const override { return "Macro(" + macroName + ")"; }
};

class ASTAssignment : public ASTNode {
    std::string var;
    std::string value;
public:
    ASTAssignment(std::string v, std::string val) : var(std::move(v)), value(std::move(val)) {}
    void compile(NASMEmitter& out) override;
    std::string debug() const override { return "Assignment(" + var + " = " + value + ")"; }
};

class ASTFunction : public ASTNode {
    std::string name;
    std::vector<std::string> params;
    std::vector<ASTNode*> body;
public:
    ASTFunction(std::string n, std::vector<std::string> p, std::vector<ASTNode*> b)
        : name(std::move(n)), params(std::move(p)), body(std::move(b)) {}
    void compile(NASMEmitter& out) override;
    std::string debug() const override { return "Function(" + name + ")"; }
};

class Parser {
    std::vector<Token> tokens;
    size_t pos = 0;

public:
    Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {}

    ASTNode* parseProgram();
    ASTNode* parseStatement();
    ASTNode* parseExpression();
    ASTNode* parseAssignment();
    ASTNode* parseFunction();
    ASTNode* parseConditionalFlow();
    ASTNode* parseParallelExecution();
    ASTNode* parseRawASM();
};

// --------------------------------------------
// NASM EMITTER
// --------------------------------------------

class NASMEmitter {
    std::ofstream outFile;
    std::mutex emitMutex;

public:
    void emit(const std::string& line) {
        std::lock_guard<std::mutex> lock(emitMutex);
        outFile << line << "\n";
    }

    void emitFunction(const std::string& name, const std::vector<ASTNode*>& body) {
        std::vector<std::thread> workers;
        for (ASTNode* node : body) {
            workers.emplace_back([this, node]() {
                node->compile(*this);
            });
        }
        for (auto& worker : workers) {
            worker.join();
        }
    }

    void emitAssignment(const std::string& var, const std::string& val) {
        emit("mov " + var + ", " + val);
        emit("add " + var + ", 1");
    }

    void open(const std::string& filename) {
        outFile.open(filename);
    }

    void saveTo(const std::string& filename) {
        outFile.close();
    }
};

// --------------------------------------------
// PLUGIN ARCHITECTURE + DYNAMIC LOADER
// --------------------------------------------

using PluginFunction = std::function<void(NASMEmitter&, const std::vector<std::string>&)>;

class PluginManager {
    std::unordered_map<std::string, PluginFunction> plugins;

public:
    void registerPlugin(const std::string& name, PluginFunction func) {
        plugins[name] = func;
    }

    bool hasPlugin(const std::string& name) const {
        return plugins.find(name) != plugins.end();
    }

    void invokePlugin(const std::string& name, NASMEmitter& emitter, const std::vector<std::string>& args) const {
        auto it = plugins.find(name);
        if (it != plugins.end()) {
            it->second(emitter, args);
        } else {
            ErrorReporter::report("Plugin not found: " + name);
        }
    }

    void loadFromSheets(const std::string& directory) {
        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.path().extension() == ".sheet") {
                std::ifstream sheet(entry.path());
                if (sheet) {
                    std::stringstream buffer;
                    buffer << sheet.rdbuf();
                    std::string sheetContent = buffer.str();
                    // Example registration: in real case, parse and bind macros
                    registerPlugin(entry.path().stem().string(), [sheetContent](NASMEmitter& emitter, const std::vector<std::string>& args) {
                        emitter.emit("; Plugin Macro Expansion: " + sheetContent);
                    });
                }
            }
        }
    }
};

// --------------------------------------------
// EXECUTION SCHEDULER
// --------------------------------------------

class ExecutionBlock {
public:
    int priority;
    std::function<void()> execute;

    bool operator<(const ExecutionBlock& other) const {
        return priority < other.priority;
    }
};

struct ComparePriority {
    bool operator()(const ExecutionBlock& a, const ExecutionBlock& b) const {
        return a.priority < b.priority;
    }
};

class ExecutionScheduler {
    std::priority_queue<ExecutionBlock, std::vector<ExecutionBlock>, ComparePriority> taskQueue;

public:
    void scheduleTask(const ExecutionBlock& task) {
        taskQueue.push(task);
    }

    void executeTasks() {
        while (!taskQueue.empty()) {
            auto task = taskQueue.top();
            taskQueue.pop();
            std::thread worker([task]() { task.execute(); });
            worker.detach();
        }
    }
};

// --------------------------------------------
// MAIN FUNCTION
// --------------------------------------------

std::string loadFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char** argv) {
    if (argc < 2) {
        ErrorReporter::report("Usage: parac <file.para>");
        return 1;
    }

    std::string code = loadFile(argv[1]);
    Lexer lexer;
    std::vector<Token> tokens;

    try {
        tokens = lexer.tokenize(code);
    } catch (const std::exception& e) {
        ErrorReporter::report("Lexer error: " + std::string(e.what()));
        return 1;
    }

    Parser parser(tokens);
    ASTNode* program = nullptr;

    try {
        program = parser.parseProgram();
    } catch (const std::exception& e) {
        ErrorReporter::report("Parser error: " + std::string(e.what()));
        return 1;
    }

    NASMEmitter emitter;
    emitter.open("out.asm");
    program->compile(emitter);
    emitter.saveTo("out.asm");

    PluginManager pluginManager;
    pluginManager.loadFromSheets("./sheets");

    ExecutionScheduler scheduler;
    scheduler.scheduleTask({10, [&]() { program->compile(emitter); }});
    scheduler.executeTasks();

    return 0;
}


class MacroPreprocessor {
    PluginManager& plugins;

public:
    MacroPreprocessor(PluginManager& p) : plugins(p) {}

    ASTNode* expand(const std::string& macroName, const std::vector<std::string>& args) {
        return new ASTMacro(macroName, args); // Simplified - inject full AST expansion here
    }

    bool isMacro(const std::string& name) {
        return plugins.hasPlugin(name);
    }

    void apply(ASTNode* node, NASMEmitter& emitter) {
        if (auto macro = dynamic_cast<ASTMacro*>(node)) {
            plugins.invokePlugin(macro->debug(), emitter, macro->args); // direct macro expand
        } else {
            node->compile(emitter);
        }
    }
};
// --------------------------------------------
// PARAGRAM COMPILER SCAFFOLD (Extended + Plugins + YAML + Macro DSL)
// --------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <queue>
#include <functional>
#include <unordered_map>
#include <sstream>
#include <mutex>
#include <optional>
#include <variant>
#include <map>
#include <stdexcept>
#include <filesystem>
#include <yaml-cpp/yaml.h> // Requires yaml-cpp

namespace fs = std::filesystem;

// -----------------------------
// MACRO DEFINITION STRUCTURE
// -----------------------------

struct MacroDefinition {
    std::vector<std::string> args;
    std::vector<std::string> body;
};

// -----------------------------
// EXTENDED PLUGIN MANAGER
// -----------------------------

class PluginManager {
    std::unordered_map<std::string, MacroDefinition> macros;

public:
    void registerMacro(const std::string& name, const MacroDefinition& macro) {
        macros[name] = macro;
    }

    bool hasMacro(const std::string& name) const {
        return macros.find(name) != macros.end();
    }

    void expandMacro(const std::string& name, NASMEmitter& emitter, const std::vector<std::string>& args) const {
        auto it = macros.find(name);
        if (it != macros.end()) {
            const MacroDefinition& def = it->second;
            for (const auto& line : def.body) {
                std::string expanded = line;
                for (size_t i = 0; i < def.args.size(); ++i) {
                    size_t pos = expanded.find(def.args[i]);
                    if (pos != std::string::npos && i < args.size()) {
                        expanded.replace(pos, def.args[i].length(), args[i]);
                    }
                }
                emitter.emit("; [Macro:" + name + "] " + expanded);
            }
        } else {
            ErrorReporter::report("Macro not found: " + name);
        }
    }

    void loadFromSheets(const std::string& directory) {
        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.path().extension() == ".sheet") {
                try {
                    YAML::Node doc = YAML::LoadFile(entry.path().string());
                    std::string name = doc["name"].as<std::string>();
                    std::vector<std::string> args = doc["args"].as<std::vector<std::string>>();
                    std::vector<std::string> body = doc["body"].as<std::vector<std::string>>();
                    registerMacro(name, {args, body});
                } catch (const std::exception& e) {
                    ErrorReporter::report("Failed to load sheet: " + std::string(e.what()));
                }
            }
        }
    }
};

// -----------------------------
// MACRO PREPROCESSOR
// -----------------------------

class MacroPreprocessor {
    PluginManager& plugins;
public:
    MacroPreprocessor(PluginManager& pm) : plugins(pm) {}

    bool isMacro(const std::string& name) const {
        return plugins.hasMacro(name);
    }

    void apply(ASTMacro* node, NASMEmitter& emitter) {
        plugins.expandMacro(node->debug(), emitter, node->args);
    }
};
// --------------------------------------------
// PARAGRAM COMPILER SCAFFOLD (Extended + Plugins + YAML + Macro DSL + Recursive + Trace)
// --------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <queue>
#include <functional>
#include <unordered_map>
#include <sstream>
#include <mutex>
#include <optional>
#include <variant>
#include <map>
#include <stdexcept>
#include <filesystem>
#include <yaml-cpp/yaml.h> // Requires yaml-cpp

namespace fs = std::filesystem;

// -----------------------------
// MACRO DEFINITION STRUCTURE
// -----------------------------

struct MacroDefinition {
    std::vector<std::string> args;
    std::vector<std::string> body;
};

// -----------------------------
// EXTENDED PLUGIN MANAGER
// -----------------------------

class PluginManager {
    std::unordered_map<std::string, MacroDefinition> macros;
    mutable std::ofstream traceFile;

public:
    PluginManager() {
        traceFile.open("macro.trace", std::ios::out);
    }

    void registerMacro(const std::string& name, const MacroDefinition& macro) {
        macros[name] = macro;
    }

    bool hasMacro(const std::string& name) const {
        return macros.find(name) != macros.end();
    }

    void expandMacroRecursive(const std::string& name, NASMEmitter& emitter, const std::vector<std::string>& args, int depth = 0) const {
        auto it = macros.find(name);
        if (it != macros.end()) {
            const MacroDefinition& def = it->second;
            for (const auto& line : def.body) {
                std::string expanded = line;
                for (size_t i = 0; i < def.args.size(); ++i) {
                    size_t pos = expanded.find(def.args[i]);
                    if (pos != std::string::npos && i < args.size()) {
                        expanded.replace(pos, def.args[i].length(), args[i]);
                    }
                }
                traceFile << std::string(depth * 2, ' ') << "[Macro:" << name << "] " << expanded << "\n";
                emitter.emit("; [Macro:" + name + "] " + expanded);

                std::istringstream iss(expanded);
                std::string firstToken;
                iss >> firstToken;
                if (hasMacro(firstToken)) {
                    std::vector<std::string> nestedArgs;
                    std::string arg;
                    while (iss >> arg) nestedArgs.push_back(arg);
                    expandMacroRecursive(firstToken, emitter, nestedArgs, depth + 1);
                }
            }
        } else {
            ErrorReporter::report("Macro not found: " + name);
        }
    }

    void expandMacro(const std::string& name, NASMEmitter& emitter, const std::vector<std::string>& args) const {
        expandMacroRecursive(name, emitter, args);
    }

    void loadFromSheets(const std::string& directory) {
        for (const auto& entry : fs::directory_iterator(directory)) {
            if (entry.path().extension() == ".sheet") {
                try {
                    YAML::Node doc = YAML::LoadFile(entry.path().string());
                    std::string name = doc["name"].as<std::string>();
                    std::vector<std::string> args = doc["args"].as<std::vector<std::string>>();
                    std::vector<std::string> body = doc["body"].as<std::vector<std::string>>();
                    registerMacro(name, {args, body});
                } catch (const std::exception& e) {
                    ErrorReporter::report("Failed to load YAML sheet: " + std::string(e.what()));
                }
            }
            else if (entry.path().extension() == ".para.sheet") {
                std::ifstream raw(entry.path());
                if (raw) {
                    std::string line;
                    std::string macroName;
                    std::vector<std::string> args, body;
                    while (std::getline(raw, line)) {
                        if (line.rfind("macro:", 0) == 0) {
                            size_t nameStart = 6;
                            size_t parenOpen = line.find('(', nameStart);
                            size_t parenClose = line.find(')', parenOpen);
                            macroName = line.substr(nameStart, parenOpen - nameStart);
                            std::istringstream argStream(line.substr(parenOpen + 1, parenClose - parenOpen - 1));
                            std::string arg;
                            while (std::getline(argStream, arg, ',')) {
                                args.push_back(arg);
                            }
                        } else if (!line.empty() && line != "{" && line != "}") {
                            body.push_back(line);
                        }
                    }
                    if (!macroName.empty()) {
                        registerMacro(macroName, {args, body});
                    }
                }
            }
        }
    }
};

// -----------------------------
// MACRO PREPROCESSOR
// -----------------------------

class MacroPreprocessor {
    PluginManager& plugins;
public:
    MacroPreprocessor(PluginManager& pm) : plugins(pm) {}

    bool isMacro(const std::string& name) const {
        return plugins.hasMacro(name);
    }

    void apply(ASTMacro* node, NASMEmitter& emitter) {
        plugins.expandMacro(node->debug(), emitter, node->args);
    }
};
