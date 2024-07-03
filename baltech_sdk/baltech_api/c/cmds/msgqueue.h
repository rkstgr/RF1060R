/**
 * @file
 * @anchor MsgQueue
 * The _MsgQueue_ command group allows to exchange arbitrary data messages
 * between multiple BRP hosts.
 * 
 * The message exchange is based on a queue that can be accessed by the different
 * BRP hosts. Every host can put a message into the queue (Send command) or can
 * retrieve a message from it (Receive command).
 * 
 * Only one single message can reside in the queue. If a host wants to put a
 * message into a non-empty queue it can only overwrite the queue content if it
 * originates from the host itself. Otherwise a MSGQ_COLLISION_ERR is returned in
 * order to avoid data loss. In this case the message has to be picked up with
 * the Receive command first, which clears the queue. Then a new message can be
 * sent.
 * 
 * The maximum allowed size of a message can be retrieved with GetMsgSize
 * command. A Send/SendReceive command that exceeds this size returns the status
 * code MSGQ_BUFOVERFLOW_ERR.
 * 
 * There are 3 commands for the message handling:
 * 
 *   1. Receive: Retrieve a message from the queue 
 *   2. Send: Put a message into the queue 
 *   3. SendReceive: Put a message into the queue and wait for reception of a new message (combines Send and Receive) 
 * 
 * A basic data exchange with alternated sent messages (A => B => A => B => A =>
 * B ....) could be implemented like this:
 * 
 * ` A: Receive B: Receive A: Wait until there is a message to be sent:
 * SendReceive(Msg1) B: Receive returns with Msg1;Answer with Msg2:
 * SendReceive(Msg2) A: SendReceive returns with Msg2; Answer with Msg3:
 * SendReceive(Msg3) ... `
 * 
 * A larger data transfer from A to B consisting of multiples messages without B
 * having to send a response every time could be implemented this way:
 * 
 * ` A: Receive B: Receive A: Wait until there is a message to be sent:
 * Send(Msg1) B: Receive returns Msg1; Receive next part: Receive A: Send returns
 * after B picked up the data; Send next part: Send(Msg2) B: Receive returns
 * Msg2; Receive next part: Receive ... `
 * 
 * Every Send call of A returns as soon as B has picked up the data, so A can
 * directly proceed with the next Send.
 */
/**
 * @file
 * @defgroup baltech_api Baltech API
 * @{
 */
#ifndef __BRP_BALTECH_API_CMDS_MSGQUEUE_H__
#define __BRP_BALTECH_API_CMDS_MSGQUEUE_H__
#include "../typedefs.h"
/**
 * @anchor MsgQueue_ErrMsgqRecvTimeout
 * Timeout: no message received within the specified time interval
 */
#define BRP_MsgQueue_ErrMsgqRecvTimeout BRP_ERR_STATUS(0xA600, 0x01)
/**
 * @anchor MsgQueue_ErrMsgqNotackedTimeout
 * Timeout: the message was not picked up within the specified time interval
 */
#define BRP_MsgQueue_ErrMsgqNotackedTimeout BRP_ERR_STATUS(0xA600, 0x02)
/**
 * @anchor MsgQueue_ErrMsgqCollision
 * Collision: there is already a message in the queue - pick up this data first
 */
#define BRP_MsgQueue_ErrMsgqCollision BRP_ERR_STATUS(0xA600, 0x03)
/**
 * @anchor MsgQueue_ErrMsgqBufoverflow
 * Buffer Overflow: the message is too large and can not be processed
 */
#define BRP_MsgQueue_ErrMsgqBufoverflow BRP_ERR_STATUS(0xA600, 0x04)
/**
 * @anchor MsgQueue_GetMsgSize
 * Retrieve the maximum message size the reader supports. If a message exceeds
 * this value the commands Send and SendReceive return the status code
 * MSGQ_BUFOVERFLOW_ERR.
 * 
 * @param[in] protocol used to execute the command
 * @param[out] BufferSize Maximum message size
 */
brp_errcode brp_MsgQueue_GetMsgSize(brp_protocol protocol, unsigned* BufferSize);
/**
 * @anchor MsgQueue_Receive
 * Wait for a message and return its content. If no message is received within
 * Timeout ms MSGQ_RECV_TIMEOUT_ERR is returned. If a previously sent message has
 * not been picked up by another host within Timeout ms MSGQ_NOTACKED_TIMEOUT_ERR
 * is returned.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] Timeout Max. time (in ms) to wait for a message.
 * @param[out] RecvMsg Received Message.
 * @param[out] RecvMsg_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_MsgQueue_Receive(brp_protocol protocol, unsigned Timeout, brp_buf* RecvMsg, size_t* RecvMsg_len, brp_mempool *mempool);
/**
 * @anchor MsgQueue_Send
 * Put a message into the Message Queue and wait a maximum time of Timeout ms
 * until the message has been picked up. If the queue already contains a message
 * that originates from another host MSGQ_COLLISION_ERR is returned; the message
 * must be removed from the queue first with the Receive command. If the message
 * is not picked up from another host within Timeout ms MSGQ_NOTACKED_TIMEOUT_ERR
 * is returned.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SendMsg Message to send.
 * @param[in] SendMsg_len 
 * @param[in] Timeout Max. time (in ms) to wait for message pickup.
 */
brp_errcode brp_MsgQueue_Send(brp_protocol protocol, brp_buf SendMsg, size_t SendMsg_len, unsigned Timeout);
/**
 * @anchor MsgQueue_SendReceive
 * This command combines Send and Receive to a single command. It sends a message
 * and then waits for the reception of a new message.
 * 
 * @param[in] protocol used to execute the command
 * @param[in] SendMsg Message to send.
 * @param[in] SendMsg_len 
 * @param[in] Timeout Max. time (in ms) to wait for reception of a response message.
 * @param[out] RecvMsg Received message.
 * @param[out] RecvMsg_len 
 * @param[in] mempool is used to store response data. Maybe NULL to use an internal mempool, in this case the data is only available until another command uses the internal mempool
 */
brp_errcode brp_MsgQueue_SendReceive(brp_protocol protocol, brp_buf SendMsg, size_t SendMsg_len, unsigned Timeout, brp_buf* RecvMsg, size_t* RecvMsg_len, brp_mempool *mempool);
#endif
/**
 * @}
 */
