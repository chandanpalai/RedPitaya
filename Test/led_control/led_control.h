

/* Sample control program -- exec file */
#include <stdint.h>

#ifndef __LED_CONTROL_H
#define __LED_CONTROL_H

/** Base Housekeeping adress */
#define LED_BASE_ADDR        0x40000000
#define LED_BASE_SIZE        0x30

#define TEMP_BASE_ADDR       0x40400000
#define TEMP_BASE_SIZE       0x30

#define ADC_FULL_RANGE_CNT 0xfff


/* Base mapping function for the Housekeeping module -- This structure is a complete mirror of the FPGA memory map documented in the document linked below:
 *
 * https://github.com/RedPitaya/RedPitaya/blob/master/FPGA/release1/doc/RedPitaya_HDL_memory_map.odt?raw=true  */
typedef struct led_struct_s {
	//OxO
	uint32_t id;
	//0x4
	uint32_t dna_part1;
	//0x8
	uint32_t dna_part2;
	//0xC
	uint32_t reserved_1;
	//0x10
	uint32_t ex_cd_p;
	//0x14
	uint32_t ex_cd_n;
	//0x18
	uint32_t ex_co_p;
	//0x1C
	uint32_t ex_co_n;
	//0x20
	uint32_t ex_ci_p;
	//0x24
	uint32_t ex_ci_n;
	//0x28
	uint32_t reserved_2;
	//0x2C
	uint32_t reserved_3;
	//0x30
	uint32_t led_control;

}led_struct_t;


/* Base mapping of the AMS function */
typedef struct temp_struct_s {
	//OxO
	uint32_t xadc_aif0;
	//0x4
	uint32_t xadc_aif1;
	//0x8
	uint32_t xadc_aif2;
	//0xC
	uint32_t xadc_aif3;
	//0x10
	uint32_t xadc_aif4;
	//0x14
	uint32_t reserved_1;
	//0x18
	uint32_t reserved_2;
	//0x1C
	uint32_t reserved_3;
	//0x20
	uint32_t pwm_dac0;
	//0x24
	uint32_t pwm_dac1;
	//0x28
	uint32_t pwm_dac2;
	//0x2C
	uint32_t pwm_dac3;
	//0x30
	uint32_t temp_control;
}temp_struct_t;

/* Function init */
int control_init(int option);
int control_cleanup(void);


#endif /*  __LED_CONTROL_H */