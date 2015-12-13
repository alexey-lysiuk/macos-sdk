/*
 *  if_wlt.h
 *  IOFamily
 *
 *  Created by Pete on 3/3/05.
 *  Copyright 2005 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef IF_WLT_H
#define IF_WLT_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <net/kpi_interface.h>

typedef int (*monitor_callback)( int , void * );
typedef int (*wlt_output_callback)( void *, mbuf_t );

errno_t create_wlt_if( ifnet_t parent , 
					   ifnet_t * wlt_ifn, 
					   u_int32_t dlt, 
					   u_int32_t header_len, 
					   monitor_callback callback, 
					   wlt_output_callback output_callback, 
					   void * context );

void destroy_wlt_if( ifnet_t ifn );
errno_t	wlt_input( ifnet_t ifn, mbuf_t m );

#ifdef  __cplusplus
}
#endif

#endif

