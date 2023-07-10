#include<iostream>
#include<csignal>   //header used to handle and manage signals

//Signal handler function for handling signals.
void signal_demonstration(int sig)
{
    std::cout<<"Signal caught........."<<(sig)<<std::endl;
    exit(0);
}
class signals_demo
{
    public:
        signals_demo(){
            std::cout<<"In constructor...."<<std::endl;
        }
        ~signals_demo(){
            std::cout<<"In destructor........"<<std::endl;
        }
};
void sigterm_handler(int sig)
{
    signals_demo *sd=new signals_demo();
    std::cout<<"SIGTERM Signal caught........."<<(sig)<<std::endl;
    delete sd;
    exit(0);
}
void sigkill_handler(int sig)
{
    signals_demo *sd=new signals_demo();
    std::cout<<"SIGKILL Signal caught........."<<(sig)<<std::endl;
    delete sd;
    exit(0);
}
int main()
{
     // Register signal handlers
     std::signal(SIGINT,signal_demonstration);   //ctrl+c
     std::signal(SIGSEGV,signal_demonstration);  //segmentation fault
     std::signal(SIGTSTP,signal_demonstration);  //ctrl+z
     std::signal(SIGTERM,sigterm_handler);  //kill -15 PID
     std::signal(SIGKILL,sigkill_handler);  //kill -9 PID  

    //These 2 lines will initiate SIGSEGV signal
    // int *ptr;
    // *ptr=10;

    /*These 2 lines will initiate SIGTERM signal.But before exiting from program object will be created,
    message printed to console and object will be destructed i.e.cleanup will be done*/
    // int p_id=getpid();
    // kill(p_id,SIGTERM);

    /*These 2 lines will initiate SIGKILL signal.Program terminates as soon as signal gets encountered
    i.e.It won't do necessary cleanup.*/
    // int p_id=getpid();
    // kill(p_id,SIGKILL);

    while(true)
    {
        std::cout<<"In side main....."<<getpid()<<std::endl;
        sleep(2);
    }
}