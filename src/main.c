#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "unpack/frames.h"
int main(int argc, char** argv)
{

	FILE *fp_start = fopen("../res/test.mp3","r");
	int fd = fileno(fp_start);


	struct stat meta;
	fstat(fd, &meta);

	physical_header_metadata *p = malloc(sizeof(physical_header_metadata));

	char *mp3_stream = mmap(0, meta.st_size, PROT_READ, MAP_SHARED, fd, 0);

	for(int i = 0; i<100;i++)
	{
		printf("B: %c\n",mp3_stream[i]);
	}



	return EXIT_SUCCESS;
}
