#include<stdio.h>
#include<stdlib.h>
main(int ac , char *av[])
{
    
    
    }



void dostat( char *filename )
{
    struct stat info;

    if ( stat(filename, &info) == -1 )	    /* cannot stat   */
	perror( filename );	    /* say why	 */
    else		    /* else show info	 */
	show_file_info( filename, &info );
}

void show_file_info( char *filename, struct stat *info_p )
    /*
     * display the info about 'filename'.  The info is stored in struct at *info_p
     */
{
    char	*uid_to_name(), *ctime(), *gid_to_name(), *filemode();
    void    mode_to_letters();
    char    modestr[11];

    mode_to_letters( info_p->st_mode, modestr );

    printf( "%s"    , modestr );
    printf( "%4d "  , (int) info_p->st_nlink);  
    printf( "%-8s " , uid_to_name(info_p->st_uid) );
    printf( "%-8s " , gid_to_name(info_p->st_gid) );
    printf( "%8ld " , (long)info_p->st_size);
    printf( "%.12s ", 4+ctime(&info_p->st_mtime));
    printf( "%s\n"  , filename );

}
