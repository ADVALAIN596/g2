/*
 * report.h - TinyG status report and other reporting functions
 * This file is part of the TinyG3 project
 *
 * Copyright (c) 2010 - 2013 Alden S. Hart Jr.
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

#ifndef REPORT_H_ONCE
#define REPORT_H_ONCE

#include "config.h"

#ifdef __cplusplus
extern "C"{
#endif

const char_t *get_status_message(uint8_t status);
void rpt_print_message(char_t *msg);
void rpt_exception(uint8_t status, int16_t value);
void rpt_print_loading_configs_message(void);
void rpt_print_initializing_message(void);
void rpt_print_system_ready_message(void);

void rpt_init_status_report(void);
stat_t rpt_set_status_report(cmdObj_t *cmd);
void rpt_decr_status_report(void);
void rpt_request_status_report(uint8_t request_type);
void rpt_status_report_rtc_callback(void);
stat_t rpt_status_report_callback(void);
void rpt_run_text_status_report(void);
void rpt_populate_unfiltered_status_report(void);
uint8_t rpt_populate_filtered_status_report(void);

void rpt_request_queue_report(void);
stat_t rpt_queue_report_callback(void);

// If you are looking for the defaults for the status report see config.h

/* unit test setup */
//#define __UNIT_TEST_REPORT	// uncomment to enable report unit tests
#ifdef __UNIT_TEST_REPORT
void sr_unit_tests(void);
#define	REPORT_UNITS sr_unit_tests();
#else
#define	REPORT_UNITS
#endif // __UNIT_TEST_REPORT

#ifdef __cplusplus
}
#endif

#endif // End of include guard: REPORT_H_ONCE

