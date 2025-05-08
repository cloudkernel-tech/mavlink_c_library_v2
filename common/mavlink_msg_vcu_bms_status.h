#pragma once
// MESSAGE VCU_BMS_STATUS PACKING

#define MAVLINK_MSG_ID_VCU_BMS_STATUS 344


typedef struct __mavlink_vcu_bms_status_t {
 float voltage; /*< [v] voltage*/
 float current; /*< [A] current*/
 float remained_capacity; /*< [A*h] remained_capacity*/
} mavlink_vcu_bms_status_t;

#define MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN 12
#define MAVLINK_MSG_ID_VCU_BMS_STATUS_MIN_LEN 12
#define MAVLINK_MSG_ID_344_LEN 12
#define MAVLINK_MSG_ID_344_MIN_LEN 12

#define MAVLINK_MSG_ID_VCU_BMS_STATUS_CRC 226
#define MAVLINK_MSG_ID_344_CRC 226



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VCU_BMS_STATUS { \
    344, \
    "VCU_BMS_STATUS", \
    3, \
    {  { "voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_vcu_bms_status_t, voltage) }, \
         { "current", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_vcu_bms_status_t, current) }, \
         { "remained_capacity", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vcu_bms_status_t, remained_capacity) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VCU_BMS_STATUS { \
    "VCU_BMS_STATUS", \
    3, \
    {  { "voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_vcu_bms_status_t, voltage) }, \
         { "current", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_vcu_bms_status_t, current) }, \
         { "remained_capacity", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vcu_bms_status_t, remained_capacity) }, \
         } \
}
#endif

/**
 * @brief Pack a vcu_bms_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param voltage [v] voltage
 * @param current [A] current
 * @param remained_capacity [A*h] remained_capacity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vcu_bms_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float voltage, float current, float remained_capacity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN];
    _mav_put_float(buf, 0, voltage);
    _mav_put_float(buf, 4, current);
    _mav_put_float(buf, 8, remained_capacity);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN);
#else
    mavlink_vcu_bms_status_t packet;
    packet.voltage = voltage;
    packet.current = current;
    packet.remained_capacity = remained_capacity;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VCU_BMS_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VCU_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_CRC);
}

/**
 * @brief Pack a vcu_bms_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param voltage [v] voltage
 * @param current [A] current
 * @param remained_capacity [A*h] remained_capacity
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vcu_bms_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float voltage,float current,float remained_capacity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN];
    _mav_put_float(buf, 0, voltage);
    _mav_put_float(buf, 4, current);
    _mav_put_float(buf, 8, remained_capacity);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN);
#else
    mavlink_vcu_bms_status_t packet;
    packet.voltage = voltage;
    packet.current = current;
    packet.remained_capacity = remained_capacity;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VCU_BMS_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VCU_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_CRC);
}

/**
 * @brief Encode a vcu_bms_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vcu_bms_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vcu_bms_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vcu_bms_status_t* vcu_bms_status)
{
    return mavlink_msg_vcu_bms_status_pack(system_id, component_id, msg, vcu_bms_status->voltage, vcu_bms_status->current, vcu_bms_status->remained_capacity);
}

/**
 * @brief Encode a vcu_bms_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vcu_bms_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vcu_bms_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vcu_bms_status_t* vcu_bms_status)
{
    return mavlink_msg_vcu_bms_status_pack_chan(system_id, component_id, chan, msg, vcu_bms_status->voltage, vcu_bms_status->current, vcu_bms_status->remained_capacity);
}

/**
 * @brief Send a vcu_bms_status message
 * @param chan MAVLink channel to send the message
 *
 * @param voltage [v] voltage
 * @param current [A] current
 * @param remained_capacity [A*h] remained_capacity
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vcu_bms_status_send(mavlink_channel_t chan, float voltage, float current, float remained_capacity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN];
    _mav_put_float(buf, 0, voltage);
    _mav_put_float(buf, 4, current);
    _mav_put_float(buf, 8, remained_capacity);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_BMS_STATUS, buf, MAVLINK_MSG_ID_VCU_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_CRC);
#else
    mavlink_vcu_bms_status_t packet;
    packet.voltage = voltage;
    packet.current = current;
    packet.remained_capacity = remained_capacity;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_BMS_STATUS, (const char *)&packet, MAVLINK_MSG_ID_VCU_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_CRC);
#endif
}

/**
 * @brief Send a vcu_bms_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_vcu_bms_status_send_struct(mavlink_channel_t chan, const mavlink_vcu_bms_status_t* vcu_bms_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_vcu_bms_status_send(chan, vcu_bms_status->voltage, vcu_bms_status->current, vcu_bms_status->remained_capacity);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_BMS_STATUS, (const char *)vcu_bms_status, MAVLINK_MSG_ID_VCU_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vcu_bms_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float voltage, float current, float remained_capacity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, voltage);
    _mav_put_float(buf, 4, current);
    _mav_put_float(buf, 8, remained_capacity);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_BMS_STATUS, buf, MAVLINK_MSG_ID_VCU_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_CRC);
#else
    mavlink_vcu_bms_status_t *packet = (mavlink_vcu_bms_status_t *)msgbuf;
    packet->voltage = voltage;
    packet->current = current;
    packet->remained_capacity = remained_capacity;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_BMS_STATUS, (const char *)packet, MAVLINK_MSG_ID_VCU_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN, MAVLINK_MSG_ID_VCU_BMS_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE VCU_BMS_STATUS UNPACKING


/**
 * @brief Get field voltage from vcu_bms_status message
 *
 * @return [v] voltage
 */
static inline float mavlink_msg_vcu_bms_status_get_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field current from vcu_bms_status message
 *
 * @return [A] current
 */
static inline float mavlink_msg_vcu_bms_status_get_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field remained_capacity from vcu_bms_status message
 *
 * @return [A*h] remained_capacity
 */
static inline float mavlink_msg_vcu_bms_status_get_remained_capacity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a vcu_bms_status message into a struct
 *
 * @param msg The message to decode
 * @param vcu_bms_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_vcu_bms_status_decode(const mavlink_message_t* msg, mavlink_vcu_bms_status_t* vcu_bms_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    vcu_bms_status->voltage = mavlink_msg_vcu_bms_status_get_voltage(msg);
    vcu_bms_status->current = mavlink_msg_vcu_bms_status_get_current(msg);
    vcu_bms_status->remained_capacity = mavlink_msg_vcu_bms_status_get_remained_capacity(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN? msg->len : MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN;
        memset(vcu_bms_status, 0, MAVLINK_MSG_ID_VCU_BMS_STATUS_LEN);
    memcpy(vcu_bms_status, _MAV_PAYLOAD(msg), len);
#endif
}
