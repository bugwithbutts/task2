/**
 * s.c -- функция для перемещения курсора в заданную позицию
 * 
 * Copyright (c) 2021, Anisimov Nikita
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include "_text.h"

void s(text txt) 
{		
	node *current = txt->cursor->line;//node with cursor
	assert(current!=NULL);
	node *nw = (void*)malloc(sizeof(node));//new node
	/*Adding node to the list*/
    	nw->previous = current;    
	nw->next = current->next;
	current->next = nw;
    	/*Dividing the string*/
	int poz = txt->cursor->position;
    	int cur = 0;
    	for(int i = poz;current->contents[i]!='\0';i++)    
    		nw->contents[cur++] = current->contents[i];
	nw->contents[cur]='\0';    
    	current->contents[poz]='\0';    	
}
