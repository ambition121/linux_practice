#include    <unistd.h>
#include    <pwd.h>
#include    <sys/types.h>
#include    <stdio.h>

    int
main()
{
    uid_t id;
    struct passwd* pbuf;
    id=geteuid();   //先求出uid，在根据uid求出passwd结构体中的字段
    pbuf=getpwuid(id);
    printf("%s\n",pbuf->pw_name);
    printf("%s\n",pbuf->pw_dir);
    printf("%s\n",pbuf->pw_passwd);

    return 0;
}
