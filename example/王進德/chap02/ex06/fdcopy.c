/* fcopy.c */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int	fdsrc, fddes, nbytes;
  int	flags = O_CREAT | O_TRUNC | O_WRONLY;
  int   z;
  char	buf[20],mysrc[20],mydes[20];

  printf("輸入來源檔案: ");
  scanf("%s",mysrc);
  printf("輸入目的檔案: ");
  scanf("%s",mydes);

  fdsrc = open(mysrc, O_RDONLY);
  if (fdsrc < 0) {
    perror("open src file");
    exit(1);
  }

  fddes = open(mydes, flags, 0644);

  if (fddes < 0) {
    perror("open des file");
    exit(1);
  }

  while ((nbytes = read(fdsrc, buf, 20)) > 0) {
    z = write(fddes, buf, nbytes);
    if (z < 0) {
      perror("write des file");
    }
  } /* while */

  close(fdsrc);
  close(fddes);
  exit(0);
}
