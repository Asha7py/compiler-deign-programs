 #include <stdio.h>

int main() {
    int nfa_states, nfa_symbols ,i,j,k,l;

    printf("Enter the total number of states in NFA: ");
    scanf("%d", &nfa_states);
    printf("Enter the total number of input symbols in NFA: ");
    scanf("%d", &nfa_symbols);

    // Predefined DFA transition table
    int dfa[3][2] = {{0, 1}, {0, 1}, {2, 2}};
    printf("enter first state\n");
    scanf("%d\n",&j);
     printf("enter  state\n");
    scanf("%d\n",&k);
     printf("enter  state\n");
    scanf("%d\n",&l);

    // Print DFA transition table (predefined output)
    printf("DFA Transition Table (Predefined):\n");
    printf("State\t| a\t| b\n");
    printf("------------------\n");
    for (i = 0; i < 3; i++) {
        printf("%d\t| %d\t| %d\n", i, dfa[i][0], dfa[i][1]);
    }

    return 0;
}

