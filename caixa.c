#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINHA 1024
#define MAX_ARGS 64

int main(int argc, char *argv[]) {
    FILE *fluxo_entrada = stdin;

    if (argc > 1) {
        fluxo_entrada = fopen(argv[1], "r");
        if (fluxo_entrada == NULL) {
            perror("Erro ao abrir o arquivo");
            return EXIT_FAILURE;
        }
    }

    char linha[MAX_LINHA];
    char *args[MAX_ARGS];

    while (1) {
        if (fluxo_entrada == stdin) {
            printf("MeuShell> ");
            fflush(stdout);
        }

        if (fgets(linha, MAX_LINHA, fluxo_entrada) == NULL) {
            break;
        }

        linha[strcspn(linha, "\n")] = '\0';

        if (strlen(linha) == 0) continue;

        if (strcmp(linha, "exit") == 0) break;

        int i = 0;
        args[i] = strtok(linha, " \t");
        while (args[i] != NULL && i < MAX_ARGS - 1) {
            i++;
            args[i] = strtok(NULL, " \t");
        }
        args[i] = NULL;

        pid_t pid = fork();

        if (pid < 0) {
            perror("Erro no fork");
        } else if (pid == 0) {
            if (execvp(args[0], args) < 0) {
                perror("Comando não encontrado");
                exit(EXIT_FAILURE);
            }
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    if (fluxo_entrada != stdin) {
        fclose(fluxo_entrada);
    }

    return 0;
}
