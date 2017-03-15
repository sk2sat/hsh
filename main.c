#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_BUF_LEN	256
#define IGNORE_NEWLINE	1


FILE *fp;

void usage(){
	printf("welcome to haribote-shell!\n");
}

int exec(char *buf, int len){
	printf("execute buf:\n\t%s\n", buf);
	system(buf);
	return 0;
}

int main(int argc, char **argv){
	int p=0, buf_len, prompt_flg=1;
	char c;
	char buf[DEFAULT_BUF_LEN];
	buf_len = DEFAULT_BUF_LEN;
	fp = stdin;
	
	usage();
	
	for(;;){
		if(fp == stdin && prompt_flg){
			fprintf(stdout, "$ ");
		}
		c = getc(fp);
		prompt_flg = 0;
		if(p<buf_len){
			buf[p] = c;
		}else{
			// 入力文字列がバッファより長かった場合
		}
		
		if(c == '\n' || c == EOF){
			prompt_flg = 1;
			int ret = exec(buf, buf_len);
			if(ret == IGNORE_NEWLINE) continue;
			memset(buf, '\0', buf_len);
			p=0;
			continue;
		}
		
		p++;
	}
}


