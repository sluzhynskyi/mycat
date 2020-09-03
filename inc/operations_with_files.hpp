#ifndef MYCAT_OPERATIONS_WITH_FILES_HPP
#define MYCAT_OPERATIONS_WITH_FILES_HPP

#include <iostream>

int writebuffer(int fd, const char *buffer, ssize_t size, int *status);

int readbuffer(int fd, char *buffer, ssize_t size, int *status);

#endif //MYCAT_OPERATIONS_WITH_FILES_HPP
