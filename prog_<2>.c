#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedence(char op) { if(op=='+'||op=='-') return 1; if(op=='*'||op=='/') return 2; return 0; }
int isOp(char c) { return c=='+'||c=='-'||c=='*'||c=='/'; }

void scanExpr(const char *in, char *out) {
    char st[200]; int top=-1, j=0;
    for (int i=0; in[i]; ++i) {
        char c = in[i];
        if (isspace(c)) continue;
        if (isalnum(c)) out[j++]=c;
        else if (c=='(') st[++top]=c;
        else if (c==')') {
            while (top>=0 && st[top]!='(') out[j++]=st[top--];
            if (top>=0) --top;
        } else if (isOp(c)) {
            while (top>=0 && st[top]!='(' && precedence(st[top])>=precedence(c)) out[j++]=st[top--];
            st[++top]=c;
        }
    }
    while (top>=0) out[j++]=st[top--];
    out[j]='\0';
}

int evalPost(const char *post) {
    int st[200], top=-1;
    for (int i=0; post[i]; ++i) {
        char c=post[i];
        if (isdigit(c)) st[++top]=c-'0';
        else {
            int b=st[top--], a=st[top--], r=0;
            if (c=='+') r=a+b; else if (c=='-') r=a-b;
            else if (c=='*') r=a*b; else if (c=='/') r=a/b;
            st[++top]=r;
        }
    }
    return top>=0?st[top]:0;
}

int main() {
    char expr[] = "3+(2*4)-5";
    char postfix[200];
    scanExpr(expr, postfix);
    printf("Infix: %s\nPostfix: %s\nEvaluation: %d\n", expr, postfix, evalPost(postfix));
    /* Example: input with multi-digit/evaluated values would need tokenization; for assignment single-digit example is shown */
    return 0;
}
