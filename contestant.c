#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define MAX_BUF 1024


int ct = 0;
int zt = 0;

void ctrlc (int sig)
{

        printf("we are live, that's attempt number %d\n", ++ct);

        if (ct >= 3)
        {
                printf("This is serious, go to commercial!\n");
                exit(0);
        }
}


void ctrlz (int sig)
{
        printf("we are live, that's attempt number %d\n", ++zt);

        if (zt >= 3)
        {
                printf("This is serious, go to commercial!\n");
                exit(0);
        }
}





int main()
{

	signal(SIGINT, ctrlc);
	signal(SIGTSTP, ctrlz);
   
   	int fd;
/*
    char *user;
    char *myfifo;
    user=getlogin();
    strcat(myfifo,"/tmp/");
    strcat(myfifo,user);
    strcat(myfifo,".fifo");
    printf("%s %s %d\n",myfifo, myfifo[4], strlen(myfifo));
*/
    	char *myfifo="/tmp/simeonr.fifo";
	char buf[MAX_BUF];
//    printf("%s %s %d\n",myfifo, myfifo[4], strlen(myfifo));


    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    	mkfifo(myfifo, 0666);

    	system("ls -al /tmp/simeonr.fifo");
//    sleep(30);

    	char arr1[80], arr2[80];
    	while (1)
    	{
        // Open FIFO for write only
        	fd = open(myfifo, O_WRONLY);

        // Take an input arr2ing from user.
        // 80 is maximum length
        	fgets(arr2, 80, stdin);
	// Write the input arr2ing on FIFO
        // and close it
        	
		write(fd, arr2, strlen(arr2)+1);
		close(fd);


        // Open FIFO for Read only
        	fd = open(myfifo, O_RDONLY);

        // Read from FIFO
        	read(fd, arr1, sizeof(arr1));


        // Print the read message
        	printf("User2: %s\n", arr1);

//        	close(fd);
		
		if (strcmp(arr1, "You just said the secret word and you have won $100!!!") == 0)
		{
			break;
		}

		else
		{
			close(fd);
		}
    	}
    	return 0;
}






