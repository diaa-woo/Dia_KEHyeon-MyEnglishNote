#include<stdio.h>

int main() {
	FILE* fp;
	fp = fopen("EnglishVocabulary.txt","r+");
	char buffer[100] = {0,};
	
	while(feof(fp)==0) {
		fgets(buffer, 100, fp);
		printf("%s",buffer);
	}
	
	fclose(fp);
}
