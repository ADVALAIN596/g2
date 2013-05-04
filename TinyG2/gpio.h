/*
 * gpio.h - general purpose IO bits - including limit switches, inputs, outputs
 * Part of TinyG project
 *
 * Copyright (c) 2013 Alden S. Hart Jr.
 *
 * This file ("the software") is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2 as published by the
 * Free Software Foundation. You should have received a copy of the GNU General Public
 * License, version 2 along with the software.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, you may use this file as part of a software library without
 * restriction. Specifically, if other files instantiate templates or use macros or
 * inline functions from this file, or you compile this file and link it with  other
 * files to produce an executable, this file does not by itself cause the resulting
 * executable to be covered by the GNU General Public License. This exception does not
 * however invalidate any other reasons why the executable file might be covered by the
 * GNU General Public License.
 *
 * THE SOFTWARE IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL, BUT WITHOUT ANY
 * WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef GPIO_H_ONCE
#define GPIO_H_ONCE
/*
#ifdef __cplusplus
extern "C"{
#endif
*/

// macros for finding the index into the switch table give the axis number
#define MIN_SWITCH(axis) (axis*2)
#define MAX_SWITCH(axis) (axis*2+1)

/*
 * Global Scope Definitions, Functions and Data
 */

enum swNums {	 			// indexes into switch arrays
	SW_MIN_X = 0,
	SW_MAX_X,
	SW_MIN_Y,
	SW_MAX_Y,
	SW_MIN_Z, 
	SW_MAX_Z,
	SW_MIN_A,
	SW_MAX_A,
	NUM_SWITCHES 			// must be last one. Used for array sizing and for loops
};
#define SW_OFFSET SW_MAX_X	// offset between MIN and MAX switches
#define NUM_SWITCH_PAIRS (NUM_SWITCHES/2)

#define SW_DISABLED -1
#define SW_OPEN 	 0
#define SW_CLOSED	 1

// switch mode settings
#define SW_HOMING 0x01
#define SW_LIMIT 0x02

#define SW_MODE_DISABLED 		0			// disabled for all operations
#define SW_MODE_HOMING 			SW_HOMING	// enable switch for homing only
#define SW_MODE_LIMIT 			SW_LIMIT		// enable switch for limits only
#define SW_MODE_HOMING_LIMIT   (SW_HOMING | SW_LIMIT)	// homing and limits
#define SW_MODE_MAX_VALUE 		SW_MODE_HOMING_LIMIT

enum swType {
	SW_TYPE_NORMALLY_OPEN = 0,
	SW_TYPE_NORMALLY_CLOSED
};

enum swState {						// state machine for managing debouncing and lockout
	SW_IDLE = 0,
	SW_DEGLITCHING,
	SW_LOCKOUT
};

typedef struct swStruct {							// switch state
	uint8_t switch_type;					// 0=NO, 1=NC - applies to all switches
	uint8_t limit_flag;						// 1=limit switch thrown - do a lockout
	uint8_t sw_num_thrown;					// number of switch that was just thrown
	volatile uint8_t mode[NUM_SWITCHES];	// 0=disabled, 1=homing, 2=homing+limit, 3=limit
	volatile uint8_t state[NUM_SWITCHES];	// see switch processing functions for explanation
	volatile int8_t count[NUM_SWITCHES];	// deglitching and lockout counter
} switches_t;
extern switches_t sw;

// Note 1: The term "thrown" is used because switches could be normally-open 
//		   or normally-closed. "Thrown" means activated or hit.

void gpio_init(void);
void gpio_rtc_callback(void);
uint8_t gpio_get_switch_mode(uint8_t sw_num);
uint8_t gpio_get_limit_thrown(void);
uint8_t gpio_get_sw_thrown(void);
void gpio_reset_switches(void);
uint8_t gpio_read_switch(uint8_t sw_num);

void gpio_led_on(uint8_t led);
void gpio_led_off(uint8_t led);
void gpio_led_toggle(uint8_t led);
uint8_t gpio_read_bit(uint8_t b);
void gpio_set_bit_on(uint8_t b);
void gpio_set_bit_off(uint8_t b);
void sw_show_switch(void);

/* unit test setup */

//#define __UNIT_TEST_GPIO				// uncomment to enable GPIO unit tests
#ifdef __UNIT_TEST_GPIO
void gpio_unit_tests(void);
#define	GPIO_UNITS gpio_unit_tests();
#else
#define	GPIO_UNITS
#endif // __UNIT_TEST_GPIO
/*
#ifdef __cplusplus
}
#endif
*/
#endif // End of include guard: GPIO_H_ONCE
