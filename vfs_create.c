#include "vfs.h"

int create_vfs(char* n_path, int size){
	struct vfs v;
	FILE* fd;
	v.header.v_info.num_files = 0;
	fd = fopen(n_path,"wb+");
	
	strcpy(v.header.v_info.vfs_name, n_path);
	v.header.v_info.size = size;
	
	//printf("NumOfFIles: %d ", v.header.v_info.num_files);
	v.header.vfs_files[++v.header.v_info.num_files].offset = sizeof(v); 

	//printf("NumOfFIles: %d  Offset: %d\n", v.header.v_info.num_files,v.header.vfs_files[v.header.v_info.num_files].offset);
	
	fwrite(&v,sizeof(v), 1, fd);
	
	fclose(fd);
	return 0;
}


