/**
  @file sysinfo.h

  Copyright (C) 2013 Jonathan Wilson

  @author Jonathan wilson <jfwfreo@tpgi.com.au>

  This library is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License version 2.1 as
  published by the Free Software Foundation.

  This library is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
  General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this library; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef SYSINFO_H_
#define SYSINFO_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma GCC visibility push(default)

struct system_config;

int  sysinfo_init      (struct system_config **sc_out);
void sysinfo_finish    (struct system_config *sc);
int  sysinfo_get_keys  (struct system_config *sc, char ***keys_out);
int  sysinfo_get_value (struct system_config *sc, const char *key,
                        uint8_t **val_out, unsigned long *len_out);
void sysinfo_set_trace_level(int level);
void sysinfo_set_trace_logger(void (* trace_logger)(int, const char *));
void sysinfo_set_error_logger(void (* error_logger)(const char *));
void sysinfo_trace(int level, const char *fmt, ...)
__attribute__((format(printf,2,3)));
void sysinfo_error(const char *fmt, ...)
__attribute__((format(printf,1,2)));

#pragma GCC visibility pop

#ifdef __cplusplus
};
#endif

#endif
