#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>
int main(int argv, char[] arg) {
	pid_t pid = fork();
	printf("Novo Processo Criado!\n");
	return 0;
}