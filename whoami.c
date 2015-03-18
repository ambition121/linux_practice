#include    <unistd.h>
#include    <pwd.h>
#include    <sys/types.h>
#include    <stdio.h>

int
main()
{
	uid_t id;
	struct passwd* pbuf;
	id=geteuid();
	pbuf=getpwuid(id);
	printf("%s\n",pbuf->pw_name);
		return 0;
}
