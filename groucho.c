#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>

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




int main( int argc, char *argv[] )
{

	signal(SIGINT, ctrlc);
	signal(SIGTSTP, ctrlz);

    	int fd1;
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
//    printf("%s %s %d\n",myfifo, myfifo[4], strlen(myfifo));


    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    	mkfifo(myfifo, 0666);

    	system("ls -al /tmp/simeonr.fifo");
	sleep(3);
	printf("Today's secret word is %s, say the word and win 100 bucks\n", argv[1]);

    	char str1[80], str2[80];

//	char str1 = tolower(str01);

    	while (1)
    	{
        // First open in read only and read
        	fd1 = open(myfifo,O_RDONLY);
        	read(fd1, str1, 80);
		
//		char *newstr[80] = tolower(str1);

                char *search = argv[1];
                char *ptr = strstr(str1, search);

//		char newstr;
/*
		int i = 0;

		while (*ptr ==  '\0')
		{
			char toLower = ("%s\n", tolower(&(ptr)));
			printf("%c\n", toLower);
			break;
		}

*/
/*
		printf("%s\n", search);


		for (char *x = strstr(str1, search); *x; x++)
		{
			*x = tolower(search);
			printf("%s\n", search);
		}
*/		

                if (ptr != NULL)
                {
//                      printf("Hooray for Captain Spaulding the African Explorer...did someone call me Schnorer...hooray, hooray, hooray!!!\n You just said the secret word and you have won $100!!!\n");
//                	write(fd1, str2, strlen(str2)+1);
//                	close(fd1);
                	fd1 = open(myfifo,O_WRONLY);
//			fgets(str2, 80, stdin);
			write(fd1, "You just said the secret word and you have won $100!!!", sizeof("You just said the secret word and you have won $100!!!"));
			printf("User 1: %s\n", str1);
			printf("THE SECRET WORD WAS PRINTED\n");
			close(fd1);
                        break;
                }
                else
                {

//                      while (ptr != NULL);
			
		
			printf("They didn't get the word lol\n");
			close(fd1);
			fd1 = open(myfifo,O_WRONLY);
//	                fgets(str2, 80, stdin);
       	        	write(fd1, "NO", sizeof("NO"));
//			printf("NO\n");
               		close(fd1);
//			fd1 = open(myfifo,O_WRONLY);
//	                fgets(str2, 80, stdin);
//        	        write(fd1, str2, strlen(str2)+1);
//                	close(fd1);

//			fd1 = open(myfifo,O_RDONLY); 
//			read(fd1, str1, 80);
//			}while (ptr = NULL);

		
                
		}


        // Print the read string and close
	        printf("User1: %s\n", str1);
        	close(fd1);
	
/*
	 // Now open in write mode and write
        // string taken from user.
	        fd1 = open(myfifo,O_WRONLY);
        	fgets(str2, 80, stdin);
        	write(fd1, str2, strlen(str2)+1);
        	close(fd1);
*/
    	}
    	return 0;
}

