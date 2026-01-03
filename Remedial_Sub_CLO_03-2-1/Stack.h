#ifndef STACK_H
#define STACK_H

#include <string>

const int N_STACK = 2025;

typedef std::string infotype;

typedef struct {
    infotype info[N_STACK];
    int top;
} Stack;

void create_stack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void emptyStack(Stack &S);

void manageAction(Stack &S_Aksi, Stack &S_Redo, infotype aksi);
int totalDamage(Stack &S);

#endif
