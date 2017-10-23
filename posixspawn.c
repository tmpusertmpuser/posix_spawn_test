#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<spawn.h>

#define MAXLOOP 10000

int main(void){
	int i;
	pid_t pid;
	posix_spawn_file_actions_t actions;
	posix_spawnattr_t attrs;
	char *args[]={"./test",NULL};
	

	posix_spawn_file_actions_init(&actions);
	posix_spawnattr_init(&attrs);

	for(i=0;i<MAXLOOP;i++){
		//pid =fork();
		//if(pid == 0){
			posix_spawn(&pid,"./test",&actions,&attrs,args,NULL);
			//printf("chile process\n");
			//return 0;
		//}
		//if(pid > 0){
			//printf("wait start\n");
			//pid_t r = waitpid(pid, &status, 0); //子プロセスのプロセスIDを指定して、終了を待つ	
			//printf("wait end\n");
		//}
	}
	return 0;
}
