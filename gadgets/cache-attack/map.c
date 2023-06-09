#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void *map_offset(const char *file, uint64_t size, uint64_t offset) {
  int fd = open(file, O_RDONLY);
  if (fd < 0)
    return NULL;
  
  char *mapaddress = MAP_FAILED;
#ifdef HAVE_MMAP64
  mapaddress = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, offset);
#else
  mapaddress = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, ((off_t)offset));
#endif
  close(fd);
  if (mapaddress == MAP_FAILED)
    return NULL;
  return (void *)(mapaddress+(offset));
}
