/*
 * mydevices.c
 *
 *  Created on: 25 oct. 2022
 *      Author: jacobo.gonzalez
 */

#include <stdio.h>
#include <stdint.h>
#include <file.h>
#include <errno.h>
#include <stdarg.h>
#include "utils/uartstdio.h"
#include "mydevices/mydevices.h"


#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

int Init_Device(void){

    FILE *fid;
       int ret_val;

       ret_val = add_device("uart", _SSA,
                            MYDEVICE_open,
                            MYDEVICE_close,
                            MYDEVICE_read,
                            MYDEVICE_write,
                            MYDEVICE_lseek,
                            MYDEVICE_unlink,
                            MYDEVICE_rename);

       fid = fopen("uart", "w");
       freopen("uart:", "w", stdout);     // redirect stdout to uart
       setvbuf(stdout, NULL, _IONBF, 0);  // turn off buffering for stdout
       //printf("Hello world over UART!\r\n");

       return ret_val;
}

int MYDEVICE_open(const char *path, unsigned flags, int fno){

    return 0;
}


int MYDEVICE_close(int fno){

    return 0;
}


int MYDEVICE_read(int fno, char *buffer, unsigned count){

    int rx=0;

    rx = UARTgets((char *) buffer, count);

    if(rx>0)
        return rx;
    else
        return -1;

}


int MYDEVICE_write(int fno, const char *buffer, unsigned count){

    int tx=0;

        tx = UARTwrite(buffer,(uint32_t) count);

       if (tx == count)
         return count;
       else
         return -1;
}



off_t MYDEVICE_lseek(int fno, off_t offset, int origin){

    return 0;
}


int MYDEVICE_unlink(const char *path){

    return 0;
}


int MYDEVICE_rename(const char *old_name, char *new_name){

    return 0;
}
