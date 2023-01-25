/*
 * mydevices.h
 *
 *  Created on: 25 oct. 2022
 *      Author: jacobo.gonzalez
 */

#ifndef MYDEVICES_MYDEVICES_H_
#define MYDEVICES_MYDEVICES_H_

#include <file.h>
#include <stdio.h>

int Init_Device(void);

int MYDEVICE_open(const char *path, unsigned flags, int fno);
int MYDEVICE_close(int fno);
int MYDEVICE_read(int fno, char *buffer, unsigned count);
int MYDEVICE_write(int fno, const char *buffer, unsigned count);
off_t MYDEVICE_lseek(int fno, off_t offset, int origin);
int MYDEVICE_unlink(const char *path);
int MYDEVICE_rename(const char *old_name, char *new_name);




#endif /* MYDEVICES_MYDEVICES_H_ */
