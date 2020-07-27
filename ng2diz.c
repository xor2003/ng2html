#include <stdio.h>
/* For make FILE_ID.DIZ from .NG database */

void main( int argc, char *argv[] ) {
	FILE *fo, *fi;
	int ch;

	if (argc < 2 )
		puts( "Usage: NG2DIZ <name>.NG");
	else {
             for(int i=1; i< argc; i++){
		fo = fopen( argv[i], "rb" );
		fi = fopen( "FILE_ID.DIZ", "ab" );

		fputs(argv[i], fi);
			fputc( ' ', fi);
		fseek( fo, 8, SEEK_SET );

		while ( (ch = fgetc( fo ) ) != 0 ) {
			fputc( ch, fi);
		}
			fputc( '\r', fi);
			fputc( '\n', fi);
		fclose(fi);
		fclose(fo);
               }
	}
}
