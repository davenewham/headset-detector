#include <stdio.h>
#include "hidapi.h"
#include <string.h>
#include <stdint.h>
#include <unistd.h>

int is_device_connected(hid_device *device_handle);
int find_usb_devices();

int main(int argc, char **argv) {

    while (1) {
        //TODO: Investigate threads
        sleep(10);
        char device_handle = "name";
        if (is_device_connected(device_handle) == 1){
            printf("Arctis 7 headset connected");
            //set default device to headset
        }
        else{
            printf("Could not find headset");
            //set other default output
        }
    }
    return 0;
}

int is_device_connected(hid_device *device_handle) {
    int r = 0;
    int connected = 0;

    // thanks to the reverse engineering from https://github.com/Sapd/HeadsetControl
    // send request for battery status
    unsigned char data_request[2] = {0x06, 0x18};
    r = hid_write(device_handle, data_request, 2);

    // read the result
    unsigned char data_read[8];
    r = hid_read(device_handle, data_read, 8);
    if (r < 0) return 0;
    int bat = data_read[2];
    if (bat > 0) return 1;
}


int find_usb_devices() {
    struct device;
    int found;
}
