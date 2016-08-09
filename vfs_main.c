#include "vfs.h"

int main()
{
	create_vfs("/home/akanksha/Desktop/vfs.bin", 8192);
	printf("Created\n");

	open_vfs("/home/akanksha/Desktop/vfs.bin");
	printf("Opened\n");

	save_vfs("A.txt","e.txt","/home/akanksha/Desktop/vfs.bin");
	printf("Saved\n");

	save_vfs("B.txt","e.txt","/home/akanksha/Desktop/vfs.bin");
	printf("Saved\n");

	save_vfs("C.txt","e.txt","/home/akanksha/Desktop/vfs.bin");
	printf("Saved\n");

	extract_vfs("C.txt","/home/akanksha/Desktop/vfs.bin");
	//sprintf("Extracted\n");

	close_vfs("/home/akanksha/Desktop/vfs.bin");
	printf("Closed\n");
	
	/*
	printf("Virtual File System\nEnter choice:\n 1: Create\n2 : Open\n3 : Save\n4 : Extract\n 5 : Close\n0 : Quit\n");
	scanf("%d", &i);
	while( i !=  0)
	{
		switch(i)
		{
			case 1: 
			create_vfs("/home/akanksha/Desktop/vfs.bin", 8192);
			printf("Created\n");
			break;

			case 2: 
			open_vfs("/home/akanksha/Desktop/vfs.bin");
			printf("Opened\n");
			break;

			case 3:
			save_vfs("A.txt","e.txt","/home/akanksha/Desktop/vfs.bin");
			printf("Saved\n");
			break;

			case 4: 
			extract_vfs("A.txt","/home/akanksha/Desktop/vfs.bin");
			printf("Extracted\n");
			break;

			case 5: 
			close_vfs("/home/akanksha/Desktop/vfs.bin");
			printf("Closed\n");
			break;

			default:
			printf("Make a choice again!!\n");
			
			break;



		}
		scanf("%d", &i);
	}
	*/

	

}
