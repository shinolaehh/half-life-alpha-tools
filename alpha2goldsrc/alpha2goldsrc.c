/* 
 * alpha2goldsrc.c
 * converts 0.52 maps to goldsrc-compatible maps
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	unsigned char alphaheader;
	unsigned char retailheader;
	
	char *filename;
	FILE *filestream;
	
	printf("shinola's modded alpha tools\n");
	printf("---- alpha2goldsrc ----\n");
	
	if (argc < 2)
	{
		printf("usage: alpha2goldsrc <file.bsp>\n");
		return 1;
	}
	
	filename = argv[1];
	
	/* check if there isn't a .bsp extension so it can be appended */
	if ((strrchr(filename, '.')) == NULL)
	{
		/* if it doesn't end in '.bsp' */
		if(strcmp(filename, ".bsp") == 1)
		{
			strcat(filename, ".bsp");
		}
	}
	
	/* open the bsp file and the file stream */
	printf("opening %s...\n", filename);
	filestream = fopen(filename, "r+");
	
	if (!filestream)
	{
		printf("ERROR: unable to open %s!\n", filename);
		return 1;
	}
	
	/* read the bsp header */
	printf("reading header...\n");
	
	fseek(filestream, 0, SEEK_SET);
	fread(&alphaheader, sizeof(unsigned char), 1, filestream);
	
	/* display the header and double check if we've got an alpha bsp */
	if (alphaheader == 0x1D) /* 0x1D = alpha bsp */
	{
		printf("opened %s!\n\n", filename);
	}
	else
	{
		printf("ERROR: %s has an invalid bsp version!\n", filename);
		return 1;
	}
	
	/* write retail bsp header into the first offset */
	printf("converting %s...\n", filename);
	
	retailheader = 0x1E;
	fseek(filestream, 0, SEEK_SET);
	fwrite(&retailheader, sizeof(unsigned char), 1, filestream);
	
	/* we've finished everything up, now time to close the stream */
	printf("%s has been converted!\n", filename);
	fclose(filestream);
	return 0;
}
