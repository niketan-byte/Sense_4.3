/* Copyright (c) 2010, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _MSM_RMNET_H_
#define _MSM_RMNET_H_

#define RMNET_MODE_NONE     (0x00)
#define RMNET_MODE_LLP_ETH  (0x01)
#define RMNET_MODE_LLP_IP   (0x02)
#define RMNET_MODE_QOS      (0x04)
#define RMNET_MODE_MASK     (RMNET_MODE_LLP_ETH | \
			     RMNET_MODE_LLP_IP  | \
			     RMNET_MODE_QOS)

#define RMNET_IS_MODE_QOS(mode)  \
	((mode & RMNET_MODE_QOS) == RMNET_MODE_QOS)
#define RMNET_IS_MODE_IP(mode)   \
	((mode & RMNET_MODE_LLP_IP) == RMNET_MODE_LLP_IP)

enum rmnet_ioctl_cmds_e {
	RMNET_IOCTL_SET_LLP_ETHERNET = 0x000089F1, 
	RMNET_IOCTL_SET_LLP_IP       = 0x000089F2, 
	RMNET_IOCTL_GET_LLP          = 0x000089F3, 
	RMNET_IOCTL_SET_QOS_ENABLE   = 0x000089F4, 
	RMNET_IOCTL_SET_QOS_DISABLE  = 0x000089F5, 
	RMNET_IOCTL_GET_QOS          = 0x000089F6, 
	RMNET_IOCTL_GET_OPMODE       = 0x000089F7, 
	RMNET_IOCTL_OPEN             = 0x000089F8, 
	RMNET_IOCTL_CLOSE            = 0x000089F9, 
	RMNET_IOCTL_MAX
};

#define QMI_QOS_HDR_S  __attribute((__packed__)) qmi_qos_hdr_s
struct QMI_QOS_HDR_S {
	unsigned char    version;
	unsigned char    flags;
	unsigned long    flow_id;
};

#endif 
