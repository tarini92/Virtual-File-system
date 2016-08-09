#include "vfs.h"


int close_vfs(char* n_path)
{
	struct vfs v;
	FILE *fp;
	int loc;
	fp = fopen(n_path, "ab+");
	fseek(fp, 0, SEEK_SET);
	/*strcpy(v.header.v_info.vfs_name, "VFS");
	v.header.v_info.size = 10;
	v.header.v_info.num_files = 3; */
	fwrite(&v.header,sizeof(v), 1, fp);
	fclose(fp);
	v.vfs_status = VFS_CLOSE;
	return 0;
}

