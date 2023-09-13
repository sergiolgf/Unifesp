buffer* allocate_buffer(FILE *arq){
	buffer *q;
	q = (buffer*)malloc(sizeof(buffer));
	q->buff = (char*)malloc(256*sizeof(char));
	q->atual = 0;
	return q;
}

char* allocate_char(){
	char *c;
	c = (char*)malloc(sizeof(char));
	return c;
}

char get_next_char(buffer *b){
	
	char c;
	
	c = b->buff[b->atual];
	b->atual++;
	
	return c;
}

void deallocate(void *b){
	free(b);
}
