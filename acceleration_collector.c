#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"

#include "mma8451_i2c.h"
#include "bootsel_button.h"

MMA8451Gravity gravity;

int main()
{
  stdio_init_all();
  MMA8451Status status = mma8451_init();
  if (status == kMMA8451Error)
  {
    return -1;
  }

  bool is_low = true;

  while (true)
  {   
    if (get_bootsel_button())
    {
      if(is_low)
      {
        printf("-,-,-\r\n");
        is_low = false;
      }
      mma451_read_gravity(&gravity);
      
      printf("%04.2f,%04.2f,%04.2f\r\n", gravity.x*1000, gravity.y*1000, gravity.z*1000);
    }else{
      is_low = true;
    }

    sleep_ms(40);
  }

  return 0;
}
