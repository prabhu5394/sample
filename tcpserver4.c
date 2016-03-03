#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

 #define ARRAYSIZE(x)  (sizeof(x)/sizeof(*(x)))

#define MAXLINE 40 /*max text line length*/
#define SERV_PORT 3000 /*port*/
#define LISTENQ 8 /*maximum number of client connections*/

void fun(char*, int);
int isEqual(char[],char[]);

void  parse(char *, char **);
void  execute(char **);

int main (int argc, char **argv)
{
 int listenfd, connfd, n,ID=0,setvalue=0;
 pid_t childpid;
 socklen_t clilen;
 char buf[MAXLINE];

char app1[]="youtube";
char app2[]="browser";
char app3[]="skype";

 int i;


 struct sockaddr_in cliaddr, servaddr;

 //Create a socket for the soclet
 //If sockfd<0 there was an error in the creation of the socket
 if ((listenfd = socket (AF_INET, SOCK_STREAM, 0)) <0) {
  perror("Problem in creating the socket");
  exit(2);
 }


 //preparation of the socket address
 servaddr.sin_family = AF_INET;
 servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
 servaddr.sin_port = htons(SERV_PORT);

 //bind the socket
 bind (listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

 //listen to the socket by creating a connection queue, then wait for clients
 listen (listenfd, LISTENQ);

 printf("%s\n","Server running...waiting for connections.");

 for ( ; ; ) {

  clilen = sizeof(cliaddr);
  //accept a connection
  connfd = accept (listenfd, (struct sockaddr *) &cliaddr, &clilen);

  printf("%s\n","Received request...");

  if ( (childpid = fork ()) == 0 ) {//if it’s 0, it’s child process

  printf ("%s\n","Child created for dealing with client requests");

  //close listening socket
  close (listenfd);
    
 memset(buf,'\0',40);//clearing buf value

  while ( (n = recv(connfd, buf, MAXLINE,0)) > 0)  

{

printf("%s","Service Requsted from the client:");
   puts(buf);
//printf("length:%d",strlen(buf));


    if (isEqual(buf,app1))
       {
        ID=1;
        printf("the ID value %d",ID);
      }
    else if(isEqual(buf,app2))
         {
         ID=2;
         printf("the ID value %d",ID);
        } 
    else if(isEqual(buf,app3))
       {
          ID=3;
          printf("the ID value %d",ID);
        } 
 setvalue=0;
//printf("the ID value %d",ID);

 switch (ID )
 {
  case 1: setvalue=2;  //default high value
           break;
  case 2: setvalue=1;  //default low value
         break;
   case 3: setvalue=2; //  default high value
           break;
   default: setvalue=1;
           break;
   }
         memset(buf,'\0',40);
        printf(" setvalue %d\n",setvalue);
         if (setvalue==1)
  {    //buf="no_service";
  strcpy(buf,"No_service");
    send(connfd, buf, 10, 0);
}
     // ---------------------- no need to provide extra bandwidth
         if (setvalue== 2)
        {
                 //buf="yes_servicce";
               strcpy(buf,"Yes_service");
              send(connfd, buf, 11, 0);
          }
                   memset(buf,0,40);
             while ( (n = recv(connfd, buf, MAXLINE,0)) > 0)  

                 fun(buf,connfd);// function call
        

  if (n < 0)
   printf("%s\n", "Read error");
  exit(0);
 }
 //close socket of the server
 close(connfd);
  return 0;
 exit(1);
}
}

}

//function to check the requested application
 
int isEqual(char str1[],char str2[]){

int i;
int length=0;

length=strlen(str1)-1;

if(length==strlen(str2)){
	for(i=0;i<length;i++){
		if(str1[i]!=str2[i]){
		return 0;
		}
}
	}
else{
return 0;
}
return 1;
}


//function to check for the authorized user 
void fun(char* buf, int connfd)
  {
//   char line
char  *line="ovs-vsctl -- set Port s1-eth1 qos=@newqos -- --id=@newqos create QoS type=linux-htb other-config:max-rate=1000000000 \ queues=0=@q0 -- --id=@q0 create Queue other-config:min-rate=8000000 other-config:max-rate=80000000";
                /* the input line                 */
     char  *argv[64];              /* the command line argument      */
   const char filename[] = "file1.csv";
char buf1[100];
int n=16, x=0;
   /*
   * Open the file.
    */
   FILE *file = fopen(filename, "r");
   if ( file )
   {
      int array[20][20];
   int len, result=0;     
int m,array1[10][10];
     size_t i, j, k;
       char buffer[BUFSIZ], *ptr;
     /*
      * Read each line from the file.
       */
       for ( i = 0; fgets(buffer, sizeof buffer, file); ++i )
      {
       /*
        * Parse the comma-separated values from each line into 'array'.
        */
       for ( j = 0, ptr = buffer; j < ARRAYSIZE(*array); ++j, ++ptr )
        {
         array[i][j] = (int)strtol(ptr, &ptr, 10);
         }
         }
      fclose(file);
       /*
       * Print the data in 'array'.
      */
 printf("User ID from client is:%s ",buf);

      for ( j = 0; j < i; ++j ){ 
        len = strlen(buf);
     // printf("\n length %d",len);
       for(m=0; m<len; m++){

       result = result * 10 + ( buf[m] - '0' );

         
          }
           // printf(" result %d\n", result);
          for ( k = 0; k < ARRAYSIZE(*array) ; ++k )
       {

             if (result==array[j][k])
               {
                  x=1;             
                   break;
                 } 
             //  printf("\n hai1 \n");
             //else 
               // printf("\n hai2 ");
              //y=0;
          }
      
      memset(buf1,0,16);// making the buf1 empty
      if(x==1)
         {  printf("\nRequsted Service will be provided to the requsted user");
            strcpy(buf1,"service_granted");        
            send(connfd, buf1, n, 0);

              // void  main(void)

     
     
     while (1) {                   /* repeat until done ....         */
          printf("Shell -> ");     /*   display a prompt             */
          //gets(line);              /*   read in the command line     */
        //  printf("\n %s",line);
          parse(line, argv);       /*   parse the line               */
          if (strcmp(argv[0], "exit") == 0)  /* is it an "exit"?     */
               exit(0);            /*   exit if it is                */
          execute(argv);           /* otherwise, execute the command */
     }
        
       }
        else
            {
		  printf("\nRequsted Service will not be provided to the requsted user"); 
              strcpy(buf1,"service_denied");        
            send(connfd, buf1, n, 0);
         } 
          putchar('\n');
      }
     }
     else /* fopen() returned NULL */
     {
       perror(filename);
     }
     
}


        

void  parse(char *line, char **argv)
{
     while (*line != '\0') {       /* if not the end of line ....... */ 
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';     /* replace white spaces with 0    */
          *argv++ = line;          /* save the argument position     */
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;             /* skip the argument until ...    */
     }
     *argv = '\0';                 /* mark the end of argument list  */
}

     
void  execute(char **argv)
{
     pid_t  pid;
     int    status;
     
     if ((pid = fork()) < 0) {     /* fork a child process           */
          printf("*** ERROR: forking child process failed\n");
          exit(1);
     }
     else if (pid == 0) {          /* for the child process:         */
          if (execvp(*argv, argv) < 0) {     /* execute the command  */
               printf("*** ERROR: exec failed\n");
               exit(1);
          }
     }
     else {                                  /* for the parent:      */
          while (wait(&status) != pid)       /* wait for completion  */
               ;
     }
}
 
