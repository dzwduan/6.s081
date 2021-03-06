

#include "kernel/types.h"
#include "user/user.h"

//notion: a pair of pipes
//这里要实现全双工管道

int
main()
{
  int pid;
  int p[2];
  char buf ='a';
  
  // create a pipe, with two FDs in fds[0], fds[1].
  // pipe0 : read ; pip01 : write
  // read : fd->buf wriet : buf->fd
  pipe(p);
  pid = fork();
  //child
  if (pid == 0) {
    read(p[0],&buf,1);
    printf("%d: received ping\n", getpid());
    close(p[0]);
    write(p[1],&buf,1);
    close(p[1]);
    exit(0);
  }
  else {
    write(p[1],&buf,1);
    close(p[1]);
    wait((int*)0);
    read(p[0],&buf,1);
    printf("%d: received pong\n", getpid());
    close(p[0]);
    exit(0);
  }

  exit(0);
}
