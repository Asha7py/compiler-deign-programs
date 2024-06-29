#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

struct Instruction {
    char op; // operator (+, -, *, /, etc.)
    char arg1; // argument 1
    char arg2; // argument 2
    char result; // result variable
};

void generate3AddressCode(char* expr) {
    stack<char> opStack; // stack to store operators
    stack<char> argStack; // stack to store arguments
    vector<Instruction> code; // vector to store generated 3-address code
    char temp = 't'; // temporary variable

    int n = strlen(expr);
    for (int i = 0; i < n; i++) {
        if (expr[i] == ' ') continue; // skip spaces

        if (isdigit(expr[i]) || isalpha(expr[i])) {
            argStack.push(expr[i]); // push operand onto stack
        } else {
            // assume it's an operator
            while (!opStack.empty() && ((opStack.top() == '*' || opStack.top() == '/') || 
                   ((opStack.top() == '+' || opStack.top() == '-') && (expr[i] == '+' || expr[i] == '-')))) {
                char op = opStack.top();
                opStack.pop();
                char arg2 = argStack.top();
                argStack.pop();
                char arg1 = argStack.top();
                argStack.pop();
                Instruction instr;
                instr.op = op;
                instr.arg1 = arg1;
                instr.arg2 = arg2;
                instr.result = temp++;
                code.push_back(instr);
                argStack.push(instr.result); // push result onto stack
            }
            opStack.push(expr[i]); // push current operator onto stack
        }
    }

    // process remaining operators in the stack
    while (!opStack.empty()) {
        char op = opStack.top();
        opStack.pop();
        char arg2 = argStack.top();
        argStack.pop();
        char arg1 = argStack.top();
        argStack.pop();
        Instruction instr;
        instr.op = op;
        instr.arg1 = arg1;
        instr.arg2 = arg2;
        instr.result = temp++;
        code.push_back(instr);
        argStack.push(instr.result); // push result onto stack
    }

    // print generated 3-address code
    for (int i = 0; i < code.size(); i++) {
        Instruction instr = code[i];
        cout << instr.result << " = " << instr.arg1 << " " << instr.op << " " << instr.arg2 << endl;
    }
}

int main() {
    char expr[100];
    cout << "Enter an expression: ";
    cin.getline(expr, 100);
    generate3AddressCode(expr);
    return 0;
}

