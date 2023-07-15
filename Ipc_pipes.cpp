#include <iostream>
#include<unistd.h>
int main() {
    int fd[2];
    int child_id;
    char buffer[1024];
    
    //check if pipe fails to create
    if(pipe(fd)==-1)
    {
        std::cout<<"Failed to create a pipe..."<<std::endl;
    }
    child_id=fork();
    
    //check if child process fail to create
    if(child_id==-1)
    {
        std::cout<<"Failed to create child process....."<<std::endl;
    }
    
    //If it is a child process process_id=0
    else if(child_id==0)
    {
        std::cout<<"Inside child process....."<<getpid()<<std::endl;
        close(fd[1]); //closing the write end of the pipe before reading from pipe
        read(fd[0],buffer,sizeof(buffer));  //reading data from pipe
        std::cout<<"Message read from pipe......"<<buffer<<std::endl;
        close(fd[0]); //closing the read end of the pipe after reading
    }
    //parent process
    else
    {
        std::cout<<"Inside parent process....."<<getpid()<<" "<<child_id<<std::endl;
        close(fd[0]);   //closing the read end of the pipe before writing from pipe
        char message[100]="Hello world";
        write(fd[1],message,sizeof(message));   //writing to the pipe
        std::cout<<"Message writen successfully......"<<std::endl;
        close(fd[1]);
    }
}
