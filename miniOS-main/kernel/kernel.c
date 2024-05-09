#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "system.h"
void print_minios(char* str);

int main() {
    print_minios("[MiniOS SSU] Hello, World!");
    char *input;

    while(1) {
        // readline을 사용하여 입력 받기
        input = readline("커맨드를 입력하세요(종료:exit) : ");

        if (strcmp(input, "exit") == 0) {
            break;
        }

        else if (strcmp(input, "minisystem") == 0){
            minisystem();
        }
		
		else if (strcmp(input, "add") == 0) {
			char *a, *b;
			a = readline("첫 번째 값 : ");
			b = readline("두 번째 값 : ");
			
			add(a, b);
		}
		
		else if (strcmp(input, "fork") == 0) {
			Fork();
		}

        else if (strcmp(input, "ipc") == 0) {
			IPC();
		}

        else if (strcmp(input, "est_pi") == 0) {
			Est_PI();
		}

        else if (strcmp(input, "rrs") == 0) {
			RRS();
		}

        else system(input);
    }

    // 메모리 해제
    free(input);
    print_minios("[MiniOS SSU] MiniOS Shutdown........");

    return(1);
}

void print_minios(char* str) {
        printf("%s\n", str);
}
