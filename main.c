#include <stdio.h>
#include "hidapi.h"
#include <string.h>
#include <stdint.h>

int main(int argc, char **argv)
{
  char device_handle = "name";
  int r = 0;
  printf("requesting if active\n");
  unsigned char data_request[58] = {0x1c, 0x00, 0xb0, 0x9a, 0x19, 0xb8, 0x8d, 0xaf, 0xff, 0xff, 0, 0, 0, 0, 0x08, 0, 0x01, 0x05, 0x00, 0x01, 0, 0, 0x02, 0x1f, 0, 0, 0, 0x01, 0x06, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  
  r = hid_write(device_handle, data_request, 2);
  if (r < 0) return r;
  
  unsigned char data_read[5];
   
   
	printf("hello world\n");
   
  
  
  return 0;
}

int	find_usb_devices()
{
	struct device;
	int found;
}
