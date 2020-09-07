#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static int display_info(const char *fpath, const struct stat *sb,
             int tflag, struct FTW *ftwbuf)
{
     if(tflag==FTW_SL || tflag==FTW_SLN) return 0; // symbolic link (soft link)
     if (tflag==FTW_D) printf( "D " ); // directory.
     else if(tflag == FTW_DNR) printf( "DNR " ); // fpath is a directory which can't be read.
     else if(tflag == FTW_DP) printf( "DP " );
     else if(tflag == FTW_F) printf( "F " ); // regular file
     else if(tflag == FTW_NS) printf( "NS " );
     else { return 0; }
     printf( "%ld %s\n", sb->st_ino, &fpath[ftwbuf->base]); // printing inode number and file`s name 
    return 0;          
}

int main(int argc, char *argv[])
{
    char* name=argv[1];
    // The nftw() function shall recursively descend the directory hierarchy rooted in path.
    nftw(name,display_info,20,FTW_PHYS); 
    exit(EXIT_SUCCESS);
}
