#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

int main(){

    FILE *fp;
    fp = fopen("./child.txt", "w+");

    pid_t pid = fork();

    //TODO: child proc. e görev ver, bittikten sonra kill yap
    //parent
    if(pid>0){
        wait(NULL); //child larin islemi tamamlamasini bekle
        kill(pid, SIGKILL); 

    }
    //child
    else if(pid == 0){
        fprintf(fp, "child process doing something cool");
        fclose(fp);
    }
    //fail
    else{
        fclose(fp);
        return -1;
    }

    return 0;
}
