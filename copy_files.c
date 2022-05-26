#include "copy_files.h"

void copy_file() {
	int read_fd;
	int write_fd;
	struct stat stat_buf;
	off_t offset = 0;
	
	read_fd = open("input_file.txt", O_RDONLY);
	
	fstat(read_fd, &stat_buf);
	
	write_fd = open("output_file.txt", O_WRONLY | O_CREAT, stat_buf.st_mode);
	
	sendfile(write_fd, read_fd, &offset, stat_buf.st_size);
	
	close(read_fd);
	close(write_fd);
}
