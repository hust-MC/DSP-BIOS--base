#ifndef DRV_I2C_H
#define DRV_I2C_H

#define ADT75_TEMP    		0  	/* get or set temperature value */
#define ADT75_CONFIG         		1
#define ADT75_T_HYST         		2
#define ADT75_T_OS           		3
#define ADT75_ONESHOT        		4


// Error Messages
#define I2C_ERROR               0xFFFF
#define I2C_ARB_LOST_ERROR      0x0001
#define I2C_NACK_ERROR          0x0002
#define I2C_BUS_BUSY_ERROR      0x1000
#define I2C_STP_NOT_READY_ERROR 0x5555
#define I2C_NO_FLAGS            0xAAAA
#define I2C_SUCCESS             0x0000

extern float I2C_getTemp();
extern void I2C_init();


#endif

