1 #include<stdio.h>
  2 #include<string.h>
  3 #include<stdlib.h>
  4 #include<fcntl.h>
  5 
  6 main(int ac , char *av[])
  7 {
  8     int fd;
  9     char buf[BUFSIZ];
 10     if(ac != 2){
 11 
 12         fprintf(stderr,"usage:write0 ttyname\n");
 13         exit(1);
 14         }
 15     fd = open(av[1],O_WRONLY);
 16     if(fd = -1){
 17         perror(av[1]);
 18         exit(1);
 19         }
 20 
 21     while(fgets(buf,BUFSIZ,stdin) != NULL)
 22         if(write(fd,buf,strlen(buf)) == -1)
 23             break;
 24             close(fd);
 25     }
~                                                                                                                        
~               
