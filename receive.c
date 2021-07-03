#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(){
//the receive process used for the read the strings that the sending process 
//writes to the shared memory. 

const int SIZE=4096; //shared memory object size
const char* name="OS"; //shared memory object name
int shm_fd; //shared memory file descriptor
void* ptr; //pointer to shared memory object 

//open the shared memory object 
shm_fd=shm_open(name,O_RDONLY,0666);

//memory map the shared memory object 
ptr=mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);
//read from the shared memory object
printf("%s",(char*)ptr);

//remove the shared memory object with shm_unlink() method
shm_unlink(name);

}
