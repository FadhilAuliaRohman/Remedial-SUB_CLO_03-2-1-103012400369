#include "stack.h"

void create_stack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == N_STACK - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = "";
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void emptyStack(Stack &S) {
    S.top = -1;
}

void manageAction(Stack &S_Aksi, Stack &S_Redo, infotype aksi) {
    infotype temp;

    if (aksi == "UNDO") {
        temp = pop(S_Aksi);
        if (temp != "") {
            push(S_Redo, temp);
        }

    } else if (aksi == "REDO") {
        temp = pop(S_Redo);
        if (temp != "") {
            push(S_Aksi, temp);
        }

    } else {
        push(S_Aksi, aksi);
        emptyStack(S_Redo);
    }
}

int totalDamage(Stack &S) {
    int damage = 0;
    infotype aksi;

    while (!isEmpty(S)) {
        aksi = pop(S);

        if (aksi == "ATTACK") {
            damage += 30;
        } else if (aksi == "DEFENSE") {
            damage += 5;
        }
    }
    return damage;
}
