/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2009 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Kirill Maximov (kir@rus.net)                                 |
   +----------------------------------------------------------------------+
*/

/* $Id: quot_print.h,v 1.13.2.1.2.1.2.3 2008/12/31 11:15:45 sebastian Exp $ */

#ifndef QUOT_PRINT_H
#define QUOT_PRINT_H

PHPAPI unsigned char *php_quot_print_decode(const unsigned char *str, size_t length, size_t *ret_length, int replace_us_by_ws);
PHPAPI unsigned char *php_quot_print_encode(const unsigned char *str, size_t length, size_t *ret_length);

PHP_FUNCTION(quoted_printable_decode);
PHP_FUNCTION(quoted_printable_encode);

#endif /* QUOT_PRINT_H */
