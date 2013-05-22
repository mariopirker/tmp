#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>

int main(int argc, char *argv[]){

        FILE *passwd;

        /* opens the log and syslogtest + pid of the process will be as header of every line */
        openlog("syslogtest",LOG_PID,LOG_LOCAL0);

        /* LOG_DEBUG is the severiy, the rest is pretty the same as with printf */
        syslog(LOG_DEBUG, "start of %s with %d arguments\n", argv[0], argc);
        if((passwd=fopen("test.txt","r"))!=NULL){
                syslog(LOG_INFO,"Open of file test.txt succeeded");
        }
        else{
                syslog(LOG_ERR,"Opening the file failed: %m");
                return EXIT_FAILURE;
        }

        closelog();
        return(EXIT_SUCCESS);

}
