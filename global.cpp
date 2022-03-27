

#include"global.h"

char* get_string()
{
	char *ptr=NULL;
	int i=0;

	do
	{
		ptr=(char*)realloc(ptr,i+1);

		if(ptr==NULL)
			return ptr;

		ptr[i]=getchar();

	} while(ptr[i++]!='\n');

	ptr[i-1]='\0';

	return ptr;
}
