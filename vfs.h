#define MAX_LEN 30
#define MAX_FILES 30
#define VFS_OPEN 0
#define VFS_CLOSE 1
#define VFS_SAVE 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct vfs_info
{
	char vfs_name[MAX_LEN];
	int num_files;
	int size;
};

struct vfs_file_info
{
	char fname[MAX_LEN];
	int offset;
	int size;
};

struct vfs_header_info
{
	struct vfs_info v_info;
	struct vfs_file_info vfs_files[MAX_FILES];
};

struct vfs
{
	struct vfs_header_info header;
	//FILE *vfs_fp;
	int vfs_status;
};

int create_vfs(char* n_path, int size);
int open_vfs(char* n_path);
int save_vfs(char* saved_name, char* n_path, char* vfs_path);
int close_vfs(char* n_path);
int extract_vfs(char* saved_name, char* n_path);

