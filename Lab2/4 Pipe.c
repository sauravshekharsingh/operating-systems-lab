#include<stdio.h>
#include<unistd.h>

int main() {
   int fd[2];

    // Message to be written
   char writemessages[2][40]={"This is a message", "This is another message"};
   char readmessage[40];
   
   // Creating a pipe
   if (pipe(fd) == -1) {
      printf("Error in creating pipe\n");
      return 1;
   }
   
   // Write a message to pipe 1
   printf("Writing to pipe - Message 1 is %s\n", writemessages[0]);
   write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
   
   // Read a message from pipe 1
   read(pipefds[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message 1 is %s\n", readmessage);
   
   // Write a message to pipe 2
   printf("Writing to pipe - Message 2 is %s\n", writemessages[0]);
   write(pipefds[1], writemessages[1], sizeof(writemessages[0]));
   
   // Read a message from pipe 2
   read(pipefds[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message 2 is %s\n", readmessage);
   
   return 0;
}
