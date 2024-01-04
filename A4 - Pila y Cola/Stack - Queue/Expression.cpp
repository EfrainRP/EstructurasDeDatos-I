#include "Expression.h"
using namespace std;

int Expression::getPrecedence(const char& operators)const {
    switch (operators) {
        case '+':
        case '-':
            return 1;

        case '/':
        case '*':
            return 2;

        case '^':
            return 3;

        case '(':
            return 4;

        case ')':
            return 5;

        default:
            return 0;
        }
    }

int Expression::comparePrecedence(Stack<char> stackOp, char operatorOfString)const {
    char stackSymbol;
    int i(0), opPos(0);

    while(!stackOp.isEmpty()) {
        i++;
        stackSymbol = stackOp.pop();

        if(getPrecedence(stackSymbol) == 4) { //Si el operador de la pila operador es (
            break;
            }
        if(getPrecedence(operatorOfString) <= getPrecedence(stackSymbol)) { //Si encuentra de mayor o igual presedencia
            opPos = i;
            }
        }
    if(opPos != 0) {
        return opPos;
        }
    else {
        return -1;
        }
    }

Expression::Expression() {}
Expression::Expression(Stack<char>& s):myStack(&s) {}

void Expression::getInfix(Queue<char>& q) {
    while(!q.isEmpty()) {
        myStack->push(q.dequeue());
        }
    }

Queue<char> Expression::convertPosfix() {
    Queue<char> queueConvert;
    Stack<char> stackOperator;
    int operatorPos(0);

    while(!myStack->isEmpty()) {

        if(getPrecedence(myStack->getTop()) == 0) {//Si un operando
            queueConvert.enqueue(myStack->pop());

            }
        else {//Si NO es un operando

            if(stackOperator.isEmpty()) { //Si la pila del operador esta vacia
                stackOperator.push(myStack->pop());
                }
            else {
                if(getPrecedence(myStack->getTop()) == 5) { //Si el operador es un )
                    while(getPrecedence(stackOperator.getTop()) != 4) {
                        queueConvert.enqueue(stackOperator.pop());
                        }

                    stackOperator.pop();//Se elimina el )
                    myStack->pop();


                    }
                else if(getPrecedence(myStack->getTop()) == 4) {//Si es(, se apila
                    stackOperator.push(myStack->pop());

                    }
                else if((operatorPos = comparePrecedence(stackOperator, myStack->getTop())) != -1) { //Si es un operador mayor o igual precedencia
                    while(operatorPos > 0) {
                        queueConvert.enqueue(stackOperator.pop());
                        operatorPos--;
                        }
                    stackOperator.push(myStack->pop());//Se apila el operador comparada
                    }
                else {
                    stackOperator.push(myStack->pop());//Se apila el operador
                    }
                }
            }
        }

    while(!stackOperator.isEmpty()) {//Vacia los operadores de la pila
        queueConvert.enqueue(stackOperator.pop());
        }

    return queueConvert;
    }

