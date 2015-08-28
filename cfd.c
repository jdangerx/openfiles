#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main (int argc, char *argv) {
  int fd = open("f",
                O_WRONLY | O_CREAT | O_TRUNC,
                S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  printf("Writing \"write from c\\n\"...\n");
  write(fd, "write from c\n", 13);
  printf("Do you want me to run `vim +wq g` (this will change the inode) (y/n)? ");
  int doVim = getchar();
  if (doVim == 'y') {
    system("vim +wq f");
  }
  printf("Do you want me to run `vi +wq g` (this will edit in-place and not change the inode) (y/n)? ");
  getchar();
  int doVi = getchar();
  if (doVi == 'y') {
    system("vi +wq f");
  }
  printf("\nWriting \"write from c!\"...\n");
  write(fd, "write from c!", 13);
  close(fd);
  return 0;
}
