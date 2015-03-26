#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 

int main(int ac , char * av[]) { 

	int rt; 
	if(ac != 2){ 
		exit(2);   
		}else{ 

			if((rt = unlink(av[1])) !=  0){ 
			fprintf(stderr,"error."); 
				exit(3); 
				} 

			} 
									   
			return 0; 

}
