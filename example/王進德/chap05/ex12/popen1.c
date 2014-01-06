/* popen1.c */
#include <stdio.h>

int main()
{
  FILE 	*fp;
  char 	buf[501];
  int	ch;
  memset(buf, '\0', sizeof(buf));

  printf("讀取管道...\n");

  fp=popen("ls -l","r");
  if (fp!=NULL) {
    ch=fread(buf,sizeof(char),500,fp);
        if (ch > 0) {
	printf("\n檔案列表如下:\n");
	printf("%s\n",buf);
        }
    pclose(fp);
  }
  else {
    printf("無法執行 popen.\n");
    return 1;
  }
  
  printf("\n寫入二進位檔案...\n");

  fp=fopen("test.bin","wb");
  if (fp == NULL) {
    printf("無法開啟檔案.\n");
    return 1;
  }
  fwrite(buf,sizeof(char),500,fp);
  fclose(fp);

  printf("\n讀取二進位檔案.\n");
  
  memset(buf, '\0', sizeof(buf));
  fp=fopen("test.bin","rb");
  if (fp == NULL) {
    printf("無法開啟檔案.\n");
    return 1;
  }
  fread(buf,sizeof(char),500,fp);
  fclose(fp);

  printf("\n寫入管道...\n\n");

  fp=popen("grep popen","w");
  fwrite(buf,sizeof(char),500,fp);
  pclose(fp);  
  
  return 0;
}

