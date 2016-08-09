#include "vfs.h"


int save_vfs(char* saved_name, char* n_path, char* vfs_path)
{
	struct vfs v;
	FILE *fp, *f;  // FILE POINTERS
	char c, a;   
	int counter = 0, siz;
	
	f = fopen(vfs_path, "r+b");         // OPENING VFS
	
	fp = fopen(n_path, "r");    // READING EXTERNAL FILE
	
	
	fseek(fp, 0, SEEK_END);
	int s = ftell(fp);               // Size of external file
	fseek(fp, 0, SEEK_SET); 

	fread(&v, sizeof(v), 1, f);


	strcpy(v.header.vfs_files[v.header.v_info.num_files].fname, saved_name);
	
	//printf("NumOfFiles: %d FileName: %s Offset: %d\n", v.header.v_info.num_files, v.header.vfs_files[v.header.v_info.num_files].fname, v.header.vfs_files[v.header.v_info.num_files].offset);
	
	/*
	do{
		a = fgetc(fp);
		
		counter++;
	}while( a != EOF); */

	
	v.header.vfs_files[v.header.v_info.num_files].size = s;
	//siz = v.header.vfs_files[v.header.v_info.num_files].size;

	
    //printf("Offset: %d  NumOfFiles: %d\n", v.header.vfs_files[v.header.v_info.num_files].offset, v.header.v_info.num_files );

    fseek(f, 0, SEEK_END);
	fwrite(fp, siz, 1, f);
	v.header.vfs_files[v.header.v_info.num_files+1].offset = v.header.vfs_files[v.header.v_info.num_files].offset + s;
	v.header.v_info.num_files++;
	
	//printf("Offset: %d NumOfFiles: %d\n", v.header.vfs_files[v.header.v_info.num_files].offset, v.header.v_info.num_files );

	v.vfs_status = VFS_SAVE;
	rewind(f);
	fwrite(&v, sizeof(v), 1, f);
	
	
	fclose(f);
	/*FILE *f1 = fopen(vfs_path, "rb");
	struct vfs v1;
	fread(&v1, sizeof(v1), 1, f1); */

	//printf("Offset: %d NumOfFiles: %d\n", v1.header.vfs_files[v1.header.v_info.num_files].offset, v1.header.v_info.num_files );
	
	fclose(fp);
	
	return 0;
}

