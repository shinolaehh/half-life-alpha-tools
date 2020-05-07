/* 
 * alpha2goldsrc.c
 * converts 0.52 maps to goldsrc-compatible maps
 */
#include <stdio.h>

#define BSP_ALPHA	0x1D
#define BSP_RETAIL	0x1E

int main(int argc, char **argv)
{
	unsigned char bspheader[0];
	const char *bspname;
	FILE *bspfile;
	
	printf("shinola's modded alpha tools\n");
	printf("---- alpha2goldsrc ----\n");
	
	if (argc < 2)
	{
		printf("usage: alpha2goldsrc <file.bsp>\n");
		return 1;
	}
	
	/* open the bspfile and the file stream */
	bspname = argv[1];
	printf("opening %s...\n", bspname);
	bspfile = fopen(bspname, "r+w");
	
	if (!bspfile)
	{
		printf("ERROR: unable to open %s!\n", bspname);
		return 1;
	}
	
	/* read the bsp header */
	printf("reading header...\n");
	
	fseek(bspfile, 0, SEEK_SET);
	fread(bspheader, sizeof(unsigned char), 1, bspfile);
	
	/* display the header and double check if we've got an alpha bsp */
	if (bspheader[0] = BSP_ALPHA)
	{
		printf("opened %s!\n\n", bspname);
	}
	else
	{
		printf("ERROR: %s has an invalid bsp version!\n", bspname);
		return 1;
	}
	
	/* write retail bsp header into the first offset */
	printf("converting %s...\n", bspname);
	
	/*
	 * TODO: the conversion code itself is incomplete.
	 * i need to find a way to properly convert it
	 */
	
	/* we've finished everything up, now time to close the stream */
	printf("%s has been converted!\n", bspname);
	fclose(bspfile);
	return 0;
}
