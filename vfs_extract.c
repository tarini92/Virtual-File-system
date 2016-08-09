#include "vfs.h"

int extract_vfs(char* saved_name, char* n_path)
{
	FILE *fp, *f;
	f = fopen(n_path, "rb");
	if(f == NULL)
		printf("Vfs unable to open!\n");
	int i, size, flag = 0;
	struct vfs v;
	fread(&v,sizeof(v),1,f);
	printf("%d\n", v.header.v_info.num_files);

	/*
	for(i = 0;i<v.header.v_info.num_files;i++)
	{
		if(!strcmp(saved_name,v.header.vfs_files[i].fname))
		{
			size = v.header.vfs_files[i+1].offset - v.header.vfs_files[i].offset;
			flag = 1;
			break;
		}

			
	} 
	 if(!strcmp(saved_name, v.header.vfs_files[i].fname))
	{
		size = v.header.v_info.size - v.header.vfs_files[i].offset;
		flag = 1;
	} 
	*/
		
	for(i=1; i<v.header.v_info.num_files;i++)
	{
		if(!strcmp(saved_name,v.header.vfs_files[i].fname))
		{
			size = v.header.vfs_files[i].size;
			flag = 1;
			//printf("I am here!\n");
			break;
		}

	} 

	if(flag)
	{ 
	fp = fopen("ext2.txt", "w+");
	if(fp == NULL)
		printf("File unable to open!\n");
	//printf("%s\n", v.header.vfs_files[i].fname);
	printf("Extracted!\n");
	fwrite(&v.header.vfs_files[i],size, 1, fp);
	fclose(fp);
	}
	else 
		printf("File Not Found!!\n");
	
	return 0;
}

