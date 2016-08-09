#include "vfs.h"

int open_vfs(char* n_path)
{
	FILE *fd ;
	struct vfs v;
	fd = fopen(n_path, "rb");
	fread(&v, sizeof(v), 1, fd);
	//printf("%s %d", v.header.vfs_files[0].fname, v.header.vfs_files[0].offset);
	v.vfs_status = VFS_OPEN;
	//v.vfs_fp = NULL;
	return 0;
}


