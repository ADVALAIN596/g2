/*
 * text_parser.h - text parser and text mode support for tinyg2
 * Part of TinyG project
 *
 * Copyright (c) 2013 Alden S. Hart Jr.
 * Copyright (c) 2013 Robert Giseburt
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

#ifndef _TEXT_PARSER_H_
#define _TEXT_PARSER_H_

#ifdef __cplusplus
extern "C"{
#endif

/*
 * Global Scope Functions
 */

stat_t text_parser(uint8_t *str);
void text_response(const uint8_t status, const uint8_t *buf);
void text_print_inline_pairs(cmdObj_t *cmd);
void text_print_inline_values(cmdObj_t *cmd);
void text_print_multiline_formatted(cmdObj_t *cmd);

/* unit test setup */

//#define __UNIT_TEST_TEXT				// uncomment to enable TEXT unit tests
#ifdef __UNIT_TEST_TEXT
void text_unit_tests(void);
#define	TEXT_UNITS text_unit_tests();
#else
#define	TEXT_UNITS
#endif // __UNIT_TEST_TEXT

#ifdef __cplusplus
}
#endif

#endif // _TEXT_PARSER_H_
