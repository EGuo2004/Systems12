#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
  struct dirent *data;
  struct stat space;
  DIR *d;
  unsigned int n;
  n = 0;
  d = opendir("./");
  printf("Statistics for directory: ./\n");

  data = readdir(d);
  while(data) {
    stat(data->d_name, &space);
    n += space.st_size;
    data = readdir(d);
  }
  printf("Total Directory Size: %d\n", n);

  rewinddir(d);
  data = readdir(d);

  printf("Directories: \n");
  while(data) {
    stat(data->d_name, &space);
    if(data->d_type == DT_DIR) {
      printf("%s \n", data->d_name);
    }
    data = readdir(d);
  }

  rewinddir(d);
  data = readdir(d);

  printf("Regular Files: \n");
  while(data) {
    stat(data->d_name, &space);
    if(data->d_type != DT_DIR) {
      printf("%s \n", data->d_name);
    }
    data = readdir(d);
  }

  return 0;
}
