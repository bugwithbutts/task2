#include <stdio.h>
#include <assert.h>
#include "common.h"
#include <string.h>
#include "text/text.h"
#include "text/_text.h"
void fplb(text txt)
{	
    FILE* tmp = fopen("a","w");
	/*Getting cursor's info*/
	node* cur = txt -> cursor -> line;
	assert(cur!=NULL);
	int index = txt -> cursor -> position;
	/*String's prefix output*/
	for(int i = 0;i<index;i++)
        fprintf(tmp,"%c",cur->contents[i]);
    fprintf(tmp,"\n");
    fclose(tmp);
}
