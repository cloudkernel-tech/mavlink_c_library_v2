#pragma once
// MESSAGE AVOIDANCE_STATUS PACKING

#define MAVLINK_MSG_ID_AVOIDANCE_STATUS 341


typedef struct __mavlink_avoidance_status_t {
 uint8_t flag_obstacle_in_far_front; /*<  Boolean indicating whether an obstacle is in far front of the vehicle*/
 uint8_t flag_obstacle_far_nearby; /*<  Boolean indicating whether an obstacle is in the neighbourhood of the vehicle with a large distance*/
 uint8_t flag_obstacle_in_front; /*<  Boolean indicating whether an obstacle is at the front of the vehicle*/
 uint8_t flag_obstacle_in_rear; /*<  Boolean indicating whether an obstacle is at the back of the vehicle*/
 uint8_t flag_obstacle_nearby; /*<  Boolean indicating whether an obstacle is within a distance from the vehicle*/
 uint8_t flag_nav_local_plan_valid; /*<  Boolean indicating whether the local plan from navigation is valid for obstacle avoidance*/
 uint8_t flag_laser_scan_data_valid; /*<  Boolean indicating whether the laser scan data is valid for obstacle detection*/
} mavlink_avoidance_status_t;

#define MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN 7
#define MAVLINK_MSG_ID_AVOIDANCE_STATUS_MIN_LEN 7
#define MAVLINK_MSG_ID_341_LEN 7
#define MAVLINK_MSG_ID_341_MIN_LEN 7

#define MAVLINK_MSG_ID_AVOIDANCE_STATUS_CRC 246
#define MAVLINK_MSG_ID_341_CRC 246



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AVOIDANCE_STATUS { \
    341, \
    "AVOIDANCE_STATUS", \
    7, \
    {  { "flag_obstacle_in_far_front", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_avoidance_status_t, flag_obstacle_in_far_front) }, \
         { "flag_obstacle_far_nearby", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_avoidance_status_t, flag_obstacle_far_nearby) }, \
         { "flag_obstacle_in_front", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_avoidance_status_t, flag_obstacle_in_front) }, \
         { "flag_obstacle_in_rear", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_avoidance_status_t, flag_obstacle_in_rear) }, \
         { "flag_obstacle_nearby", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_avoidance_status_t, flag_obstacle_nearby) }, \
         { "flag_nav_local_plan_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_avoidance_status_t, flag_nav_local_plan_valid) }, \
         { "flag_laser_scan_data_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_avoidance_status_t, flag_laser_scan_data_valid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AVOIDANCE_STATUS { \
    "AVOIDANCE_STATUS", \
    7, \
    {  { "flag_obstacle_in_far_front", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_avoidance_status_t, flag_obstacle_in_far_front) }, \
         { "flag_obstacle_far_nearby", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_avoidance_status_t, flag_obstacle_far_nearby) }, \
         { "flag_obstacle_in_front", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_avoidance_status_t, flag_obstacle_in_front) }, \
         { "flag_obstacle_in_rear", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_avoidance_status_t, flag_obstacle_in_rear) }, \
         { "flag_obstacle_nearby", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_avoidance_status_t, flag_obstacle_nearby) }, \
         { "flag_nav_local_plan_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_avoidance_status_t, flag_nav_local_plan_valid) }, \
         { "flag_laser_scan_data_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_avoidance_status_t, flag_laser_scan_data_valid) }, \
         } \
}
#endif

/**
 * @brief Pack a avoidance_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param flag_obstacle_in_far_front  Boolean indicating whether an obstacle is in far front of the vehicle
 * @param flag_obstacle_far_nearby  Boolean indicating whether an obstacle is in the neighbourhood of the vehicle with a large distance
 * @param flag_obstacle_in_front  Boolean indicating whether an obstacle is at the front of the vehicle
 * @param flag_obstacle_in_rear  Boolean indicating whether an obstacle is at the back of the vehicle
 * @param flag_obstacle_nearby  Boolean indicating whether an obstacle is within a distance from the vehicle
 * @param flag_nav_local_plan_valid  Boolean indicating whether the local plan from navigation is valid for obstacle avoidance
 * @param flag_laser_scan_data_valid  Boolean indicating whether the laser scan data is valid for obstacle detection
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_avoidance_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t flag_obstacle_in_far_front, uint8_t flag_obstacle_far_nearby, uint8_t flag_obstacle_in_front, uint8_t flag_obstacle_in_rear, uint8_t flag_obstacle_nearby, uint8_t flag_nav_local_plan_valid, uint8_t flag_laser_scan_data_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, flag_obstacle_in_far_front);
    _mav_put_uint8_t(buf, 1, flag_obstacle_far_nearby);
    _mav_put_uint8_t(buf, 2, flag_obstacle_in_front);
    _mav_put_uint8_t(buf, 3, flag_obstacle_in_rear);
    _mav_put_uint8_t(buf, 4, flag_obstacle_nearby);
    _mav_put_uint8_t(buf, 5, flag_nav_local_plan_valid);
    _mav_put_uint8_t(buf, 6, flag_laser_scan_data_valid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN);
#else
    mavlink_avoidance_status_t packet;
    packet.flag_obstacle_in_far_front = flag_obstacle_in_far_front;
    packet.flag_obstacle_far_nearby = flag_obstacle_far_nearby;
    packet.flag_obstacle_in_front = flag_obstacle_in_front;
    packet.flag_obstacle_in_rear = flag_obstacle_in_rear;
    packet.flag_obstacle_nearby = flag_obstacle_nearby;
    packet.flag_nav_local_plan_valid = flag_nav_local_plan_valid;
    packet.flag_laser_scan_data_valid = flag_laser_scan_data_valid;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AVOIDANCE_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AVOIDANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_CRC);
}

/**
 * @brief Pack a avoidance_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param flag_obstacle_in_far_front  Boolean indicating whether an obstacle is in far front of the vehicle
 * @param flag_obstacle_far_nearby  Boolean indicating whether an obstacle is in the neighbourhood of the vehicle with a large distance
 * @param flag_obstacle_in_front  Boolean indicating whether an obstacle is at the front of the vehicle
 * @param flag_obstacle_in_rear  Boolean indicating whether an obstacle is at the back of the vehicle
 * @param flag_obstacle_nearby  Boolean indicating whether an obstacle is within a distance from the vehicle
 * @param flag_nav_local_plan_valid  Boolean indicating whether the local plan from navigation is valid for obstacle avoidance
 * @param flag_laser_scan_data_valid  Boolean indicating whether the laser scan data is valid for obstacle detection
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_avoidance_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t flag_obstacle_in_far_front,uint8_t flag_obstacle_far_nearby,uint8_t flag_obstacle_in_front,uint8_t flag_obstacle_in_rear,uint8_t flag_obstacle_nearby,uint8_t flag_nav_local_plan_valid,uint8_t flag_laser_scan_data_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, flag_obstacle_in_far_front);
    _mav_put_uint8_t(buf, 1, flag_obstacle_far_nearby);
    _mav_put_uint8_t(buf, 2, flag_obstacle_in_front);
    _mav_put_uint8_t(buf, 3, flag_obstacle_in_rear);
    _mav_put_uint8_t(buf, 4, flag_obstacle_nearby);
    _mav_put_uint8_t(buf, 5, flag_nav_local_plan_valid);
    _mav_put_uint8_t(buf, 6, flag_laser_scan_data_valid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN);
#else
    mavlink_avoidance_status_t packet;
    packet.flag_obstacle_in_far_front = flag_obstacle_in_far_front;
    packet.flag_obstacle_far_nearby = flag_obstacle_far_nearby;
    packet.flag_obstacle_in_front = flag_obstacle_in_front;
    packet.flag_obstacle_in_rear = flag_obstacle_in_rear;
    packet.flag_obstacle_nearby = flag_obstacle_nearby;
    packet.flag_nav_local_plan_valid = flag_nav_local_plan_valid;
    packet.flag_laser_scan_data_valid = flag_laser_scan_data_valid;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AVOIDANCE_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AVOIDANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_CRC);
}

/**
 * @brief Encode a avoidance_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param avoidance_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_avoidance_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_avoidance_status_t* avoidance_status)
{
    return mavlink_msg_avoidance_status_pack(system_id, component_id, msg, avoidance_status->flag_obstacle_in_far_front, avoidance_status->flag_obstacle_far_nearby, avoidance_status->flag_obstacle_in_front, avoidance_status->flag_obstacle_in_rear, avoidance_status->flag_obstacle_nearby, avoidance_status->flag_nav_local_plan_valid, avoidance_status->flag_laser_scan_data_valid);
}

/**
 * @brief Encode a avoidance_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param avoidance_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_avoidance_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_avoidance_status_t* avoidance_status)
{
    return mavlink_msg_avoidance_status_pack_chan(system_id, component_id, chan, msg, avoidance_status->flag_obstacle_in_far_front, avoidance_status->flag_obstacle_far_nearby, avoidance_status->flag_obstacle_in_front, avoidance_status->flag_obstacle_in_rear, avoidance_status->flag_obstacle_nearby, avoidance_status->flag_nav_local_plan_valid, avoidance_status->flag_laser_scan_data_valid);
}

/**
 * @brief Send a avoidance_status message
 * @param chan MAVLink channel to send the message
 *
 * @param flag_obstacle_in_far_front  Boolean indicating whether an obstacle is in far front of the vehicle
 * @param flag_obstacle_far_nearby  Boolean indicating whether an obstacle is in the neighbourhood of the vehicle with a large distance
 * @param flag_obstacle_in_front  Boolean indicating whether an obstacle is at the front of the vehicle
 * @param flag_obstacle_in_rear  Boolean indicating whether an obstacle is at the back of the vehicle
 * @param flag_obstacle_nearby  Boolean indicating whether an obstacle is within a distance from the vehicle
 * @param flag_nav_local_plan_valid  Boolean indicating whether the local plan from navigation is valid for obstacle avoidance
 * @param flag_laser_scan_data_valid  Boolean indicating whether the laser scan data is valid for obstacle detection
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_avoidance_status_send(mavlink_channel_t chan, uint8_t flag_obstacle_in_far_front, uint8_t flag_obstacle_far_nearby, uint8_t flag_obstacle_in_front, uint8_t flag_obstacle_in_rear, uint8_t flag_obstacle_nearby, uint8_t flag_nav_local_plan_valid, uint8_t flag_laser_scan_data_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, flag_obstacle_in_far_front);
    _mav_put_uint8_t(buf, 1, flag_obstacle_far_nearby);
    _mav_put_uint8_t(buf, 2, flag_obstacle_in_front);
    _mav_put_uint8_t(buf, 3, flag_obstacle_in_rear);
    _mav_put_uint8_t(buf, 4, flag_obstacle_nearby);
    _mav_put_uint8_t(buf, 5, flag_nav_local_plan_valid);
    _mav_put_uint8_t(buf, 6, flag_laser_scan_data_valid);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVOIDANCE_STATUS, buf, MAVLINK_MSG_ID_AVOIDANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_CRC);
#else
    mavlink_avoidance_status_t packet;
    packet.flag_obstacle_in_far_front = flag_obstacle_in_far_front;
    packet.flag_obstacle_far_nearby = flag_obstacle_far_nearby;
    packet.flag_obstacle_in_front = flag_obstacle_in_front;
    packet.flag_obstacle_in_rear = flag_obstacle_in_rear;
    packet.flag_obstacle_nearby = flag_obstacle_nearby;
    packet.flag_nav_local_plan_valid = flag_nav_local_plan_valid;
    packet.flag_laser_scan_data_valid = flag_laser_scan_data_valid;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVOIDANCE_STATUS, (const char *)&packet, MAVLINK_MSG_ID_AVOIDANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_CRC);
#endif
}

/**
 * @brief Send a avoidance_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_avoidance_status_send_struct(mavlink_channel_t chan, const mavlink_avoidance_status_t* avoidance_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_avoidance_status_send(chan, avoidance_status->flag_obstacle_in_far_front, avoidance_status->flag_obstacle_far_nearby, avoidance_status->flag_obstacle_in_front, avoidance_status->flag_obstacle_in_rear, avoidance_status->flag_obstacle_nearby, avoidance_status->flag_nav_local_plan_valid, avoidance_status->flag_laser_scan_data_valid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVOIDANCE_STATUS, (const char *)avoidance_status, MAVLINK_MSG_ID_AVOIDANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_avoidance_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t flag_obstacle_in_far_front, uint8_t flag_obstacle_far_nearby, uint8_t flag_obstacle_in_front, uint8_t flag_obstacle_in_rear, uint8_t flag_obstacle_nearby, uint8_t flag_nav_local_plan_valid, uint8_t flag_laser_scan_data_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, flag_obstacle_in_far_front);
    _mav_put_uint8_t(buf, 1, flag_obstacle_far_nearby);
    _mav_put_uint8_t(buf, 2, flag_obstacle_in_front);
    _mav_put_uint8_t(buf, 3, flag_obstacle_in_rear);
    _mav_put_uint8_t(buf, 4, flag_obstacle_nearby);
    _mav_put_uint8_t(buf, 5, flag_nav_local_plan_valid);
    _mav_put_uint8_t(buf, 6, flag_laser_scan_data_valid);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVOIDANCE_STATUS, buf, MAVLINK_MSG_ID_AVOIDANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_CRC);
#else
    mavlink_avoidance_status_t *packet = (mavlink_avoidance_status_t *)msgbuf;
    packet->flag_obstacle_in_far_front = flag_obstacle_in_far_front;
    packet->flag_obstacle_far_nearby = flag_obstacle_far_nearby;
    packet->flag_obstacle_in_front = flag_obstacle_in_front;
    packet->flag_obstacle_in_rear = flag_obstacle_in_rear;
    packet->flag_obstacle_nearby = flag_obstacle_nearby;
    packet->flag_nav_local_plan_valid = flag_nav_local_plan_valid;
    packet->flag_laser_scan_data_valid = flag_laser_scan_data_valid;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AVOIDANCE_STATUS, (const char *)packet, MAVLINK_MSG_ID_AVOIDANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN, MAVLINK_MSG_ID_AVOIDANCE_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE AVOIDANCE_STATUS UNPACKING


/**
 * @brief Get field flag_obstacle_in_far_front from avoidance_status message
 *
 * @return  Boolean indicating whether an obstacle is in far front of the vehicle
 */
static inline uint8_t mavlink_msg_avoidance_status_get_flag_obstacle_in_far_front(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field flag_obstacle_far_nearby from avoidance_status message
 *
 * @return  Boolean indicating whether an obstacle is in the neighbourhood of the vehicle with a large distance
 */
static inline uint8_t mavlink_msg_avoidance_status_get_flag_obstacle_far_nearby(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field flag_obstacle_in_front from avoidance_status message
 *
 * @return  Boolean indicating whether an obstacle is at the front of the vehicle
 */
static inline uint8_t mavlink_msg_avoidance_status_get_flag_obstacle_in_front(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field flag_obstacle_in_rear from avoidance_status message
 *
 * @return  Boolean indicating whether an obstacle is at the back of the vehicle
 */
static inline uint8_t mavlink_msg_avoidance_status_get_flag_obstacle_in_rear(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field flag_obstacle_nearby from avoidance_status message
 *
 * @return  Boolean indicating whether an obstacle is within a distance from the vehicle
 */
static inline uint8_t mavlink_msg_avoidance_status_get_flag_obstacle_nearby(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field flag_nav_local_plan_valid from avoidance_status message
 *
 * @return  Boolean indicating whether the local plan from navigation is valid for obstacle avoidance
 */
static inline uint8_t mavlink_msg_avoidance_status_get_flag_nav_local_plan_valid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field flag_laser_scan_data_valid from avoidance_status message
 *
 * @return  Boolean indicating whether the laser scan data is valid for obstacle detection
 */
static inline uint8_t mavlink_msg_avoidance_status_get_flag_laser_scan_data_valid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Decode a avoidance_status message into a struct
 *
 * @param msg The message to decode
 * @param avoidance_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_avoidance_status_decode(const mavlink_message_t* msg, mavlink_avoidance_status_t* avoidance_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    avoidance_status->flag_obstacle_in_far_front = mavlink_msg_avoidance_status_get_flag_obstacle_in_far_front(msg);
    avoidance_status->flag_obstacle_far_nearby = mavlink_msg_avoidance_status_get_flag_obstacle_far_nearby(msg);
    avoidance_status->flag_obstacle_in_front = mavlink_msg_avoidance_status_get_flag_obstacle_in_front(msg);
    avoidance_status->flag_obstacle_in_rear = mavlink_msg_avoidance_status_get_flag_obstacle_in_rear(msg);
    avoidance_status->flag_obstacle_nearby = mavlink_msg_avoidance_status_get_flag_obstacle_nearby(msg);
    avoidance_status->flag_nav_local_plan_valid = mavlink_msg_avoidance_status_get_flag_nav_local_plan_valid(msg);
    avoidance_status->flag_laser_scan_data_valid = mavlink_msg_avoidance_status_get_flag_laser_scan_data_valid(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN? msg->len : MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN;
        memset(avoidance_status, 0, MAVLINK_MSG_ID_AVOIDANCE_STATUS_LEN);
    memcpy(avoidance_status, _MAV_PAYLOAD(msg), len);
#endif
}
