#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(){
//sender process used to write to the shared memory that they share with the
//receiver process.
	
const int SIZE=4096; //shared memory object size
const char* name="OS"; //name of shared memory object
//strings written to shared memory
const char* message_0="HELLO"; 
const char* message_1="WORLD";


int shm_fd; //shared memory file descriptor
void* ptr;//pointer to shared memory object

//create the shared memory object with shm_open() method
//shm_open parameters=> shared memory object name,flags,permission
shm_fd=shm_open(name,O_CREAT|O_RDWR,0666);

//configure the size of the shared memory object
ftruncate(shm_fd,SIZE);

//memory map the shared memory object 
//mmap() parameters=>adress,size,purpose(write,read),type of match,file,0
ptr=mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shm_fd,0);

//mmap() method allows a part of the shared memory object to be mapped to an 
//address space


//write to the shared memory object
sprintf(ptr,%s,message_0);
ptr+=strlen(message_0);
sprintf(ptr,%s,message_1);
ptr+=strlen(message_1);

return 0;

}
