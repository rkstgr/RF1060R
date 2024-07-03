/**
 * @file
 * @anchor Eth
 * This command group contains ethernet related commands.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_ETH_H__
#define __BRP_BALTECH_API_CMDS_ETH_H__
#include "../typedefs.h"
/**
 * @anchor Eth_ErrNoResultYet
 * No result yet.
 */
#define BRP_Eth_ErrNoResultYet BRP_ERR_STATUS(0x4500, 0x01)
/**
 * @anchor Eth_ErrNotConnected
 * Port is not connected.
 */
#define BRP_Eth_ErrNotConnected BRP_ERR_STATUS(0x4500, 0x02)
/**
 * @anchor Eth_ErrDisabled
 * Detection is disabled.
 */
#define BRP_Eth_ErrDisabled BRP_ERR_STATUS(0x4500, 0x03)
/**
 * @anchor Eth_GetMacAdr
 * Retrieve the MAC address of the device.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] MAC 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Eth_GetMacAdr(brp_protocol protocol, brp_buf* MAC, brp_mempool *mempool);
/**
 * @anchor Eth_GetConnDevIP
 * Retrieve the IP address of the directly connected network device.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] IP 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Eth_GetConnDevIP(brp_protocol protocol, brp_buf* IP, brp_mempool *mempool);
/**
 * @anchor Eth_CreateRecoveryPoint
 * Create a _Recovery Point_ , backing up all relevant Ethernet- and TCP/IP-
 * settings.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Eth_CreateRecoveryPoint(brp_protocol protocol);
/**
 * @anchor Eth_DelRecoveryPoint
 * Remove a Recovery Point which was created via the
 * [Eth.CreateRecoveryPoint](@ref Eth_CreateRecoveryPoint) command.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Eth_DelRecoveryPoint(brp_protocol protocol);
/**
 * @anchor Eth_GetNetworkStatus
 * Retrieve current network status.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] PortStatus 
 * @param[out] StaticIPAdr 
 * @param[out] StaticIPNetmask 
 * @param[out] StaticIPGateway 
 * @param[out] DHCPAdr 
 * @param[out] DHCPNetmask 
 * @param[out] DHCPGateway 
 * @param[out] LinkLocalAdr 
 * @param[out] LinkLocalNetmask 
 * @param[out] LinkLocalGateway 
 * @param[out] DNSAdr 
 * @param[out] HostAdr 
 * @param[out] HostPort 
 * @param[out] AutocloseTimeout 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Eth_GetNetworkStatus(brp_protocol protocol, unsigned* PortStatus, brp_buf* StaticIPAdr, brp_buf* StaticIPNetmask, brp_buf* StaticIPGateway, brp_buf* DHCPAdr, brp_buf* DHCPNetmask, brp_buf* DHCPGateway, brp_buf* LinkLocalAdr, brp_buf* LinkLocalNetmask, brp_buf* LinkLocalGateway, brp_buf* DNSAdr, brp_buf* HostAdr, unsigned* HostPort, unsigned* AutocloseTimeout, brp_mempool *mempool);
/**
 * @anchor Eth_GetMIBCounters
 * Retrieve current MIB counters.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Port 0: device port, 1: network port
 * @param[out] MIBCounterList 
 * @param[out] MIBCounterList_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_Eth_GetMIBCounters(brp_protocol protocol, unsigned Port, unsigned** MIBCounterList, size_t* MIBCounterList_len, brp_mempool *mempool);
/**
 * @anchor Eth_GetTcpConnectionStatus
 * Retrieve the BRP over TCP connection status. Checks if there is an open TCP
 * connection.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] Status BRP over TCP connection status.
 */
brp_errcode brp_Eth_GetTcpConnectionStatus(brp_protocol protocol, brp_Eth_GetTcpConnectionStatus_Status* Status);
/**
 * @anchor Eth_OpenTcpConnection
 * Open a BRP over TCP connection to the configured host.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] ConnectionReason Connection reason bit mask that is sent to the host as soon as a connection is established.
 */
brp_errcode brp_Eth_OpenTcpConnection(brp_protocol protocol, brp_Eth_OpenTcpConnection_ConnectionReason ConnectionReason);
/**
 * @anchor Eth_CloseTcpConnection
 * Close the BRP over TCP connection.
 * 
 * @param[in] protocol used to execute the command
 */
brp_errcode brp_Eth_CloseTcpConnection(brp_protocol protocol);
#endif
/**
 * @}
 */
