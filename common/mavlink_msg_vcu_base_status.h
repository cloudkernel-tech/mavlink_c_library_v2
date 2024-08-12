#pragma once
// MESSAGE VCU_BASE_STATUS PACKING

#define MAVLINK_MSG_ID_VCU_BASE_STATUS 342


typedef struct __mavlink_vcu_base_status_t {
 float speed; /*< [m/s] speed*/
 float steering_angle; /*< [rad] steering angle*/
 float vel[3]; /*<  Linear velocities along body axies in FRD frame*/
 float heading_rate; /*< [rad/s] heading rate*/
 uint8_t vcu_base_type; /*<  vcu base type*/
 uint8_t gear_position; /*<  vcu gear position*/
 uint8_t steering_angle_valid; /*<  valid flag for steering angle*/
 uint8_t twist_valid; /*<  valid flag for twist*/
 uint8_t heading_rate_valid; /*<  valid flag for heading rate*/
 uint8_t operating_mode; /*<  operating mode, reserved*/
} mavlink_vcu_base_status_t;

#define MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN 30
#define MAVLINK_MSG_ID_VCU_BASE_STATUS_MIN_LEN 30
#define MAVLINK_MSG_ID_342_LEN 30
#define MAVLINK_MSG_ID_342_MIN_LEN 30

#define MAVLINK_MSG_ID_VCU_BASE_STATUS_CRC 64
#define MAVLINK_MSG_ID_342_CRC 64

#define MAVLINK_MSG_VCU_BASE_STATUS_FIELD_VEL_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VCU_BASE_STATUS { \
    342, \
    "VCU_BASE_STATUS", \
    10, \
    {  { "vcu_base_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_vcu_base_status_t, vcu_base_type) }, \
         { "gear_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_vcu_base_status_t, gear_position) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_vcu_base_status_t, speed) }, \
         { "steering_angle_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_vcu_base_status_t, steering_angle_valid) }, \
         { "steering_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_vcu_base_status_t, steering_angle) }, \
         { "twist_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_vcu_base_status_t, twist_valid) }, \
         { "vel", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_vcu_base_status_t, vel) }, \
         { "heading_rate_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_vcu_base_status_t, heading_rate_valid) }, \
         { "heading_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_vcu_base_status_t, heading_rate) }, \
         { "operating_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_vcu_base_status_t, operating_mode) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VCU_BASE_STATUS { \
    "VCU_BASE_STATUS", \
    10, \
    {  { "vcu_base_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_vcu_base_status_t, vcu_base_type) }, \
         { "gear_position", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_vcu_base_status_t, gear_position) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_vcu_base_status_t, speed) }, \
         { "steering_angle_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_vcu_base_status_t, steering_angle_valid) }, \
         { "steering_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_vcu_base_status_t, steering_angle) }, \
         { "twist_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_vcu_base_status_t, twist_valid) }, \
         { "vel", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_vcu_base_status_t, vel) }, \
         { "heading_rate_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_vcu_base_status_t, heading_rate_valid) }, \
         { "heading_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_vcu_base_status_t, heading_rate) }, \
         { "operating_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_vcu_base_status_t, operating_mode) }, \
         } \
}
#endif

/**
 * @brief Pack a vcu_base_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vcu_base_type  vcu base type
 * @param gear_position  vcu gear position
 * @param speed [m/s] speed
 * @param steering_angle_valid  valid flag for steering angle
 * @param steering_angle [rad] steering angle
 * @param twist_valid  valid flag for twist
 * @param vel  Linear velocities along body axies in FRD frame
 * @param heading_rate_valid  valid flag for heading rate
 * @param heading_rate [rad/s] heading rate
 * @param operating_mode  operating mode, reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vcu_base_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vcu_base_type, uint8_t gear_position, float speed, uint8_t steering_angle_valid, float steering_angle, uint8_t twist_valid, const float *vel, uint8_t heading_rate_valid, float heading_rate, uint8_t operating_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN];
    _mav_put_float(buf, 0, speed);
    _mav_put_float(buf, 4, steering_angle);
    _mav_put_float(buf, 20, heading_rate);
    _mav_put_uint8_t(buf, 24, vcu_base_type);
    _mav_put_uint8_t(buf, 25, gear_position);
    _mav_put_uint8_t(buf, 26, steering_angle_valid);
    _mav_put_uint8_t(buf, 27, twist_valid);
    _mav_put_uint8_t(buf, 28, heading_rate_valid);
    _mav_put_uint8_t(buf, 29, operating_mode);
    _mav_put_float_array(buf, 8, vel, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN);
#else
    mavlink_vcu_base_status_t packet;
    packet.speed = speed;
    packet.steering_angle = steering_angle;
    packet.heading_rate = heading_rate;
    packet.vcu_base_type = vcu_base_type;
    packet.gear_position = gear_position;
    packet.steering_angle_valid = steering_angle_valid;
    packet.twist_valid = twist_valid;
    packet.heading_rate_valid = heading_rate_valid;
    packet.operating_mode = operating_mode;
    mav_array_memcpy(packet.vel, vel, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VCU_BASE_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VCU_BASE_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_CRC);
}

/**
 * @brief Pack a vcu_base_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vcu_base_type  vcu base type
 * @param gear_position  vcu gear position
 * @param speed [m/s] speed
 * @param steering_angle_valid  valid flag for steering angle
 * @param steering_angle [rad] steering angle
 * @param twist_valid  valid flag for twist
 * @param vel  Linear velocities along body axies in FRD frame
 * @param heading_rate_valid  valid flag for heading rate
 * @param heading_rate [rad/s] heading rate
 * @param operating_mode  operating mode, reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vcu_base_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vcu_base_type,uint8_t gear_position,float speed,uint8_t steering_angle_valid,float steering_angle,uint8_t twist_valid,const float *vel,uint8_t heading_rate_valid,float heading_rate,uint8_t operating_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN];
    _mav_put_float(buf, 0, speed);
    _mav_put_float(buf, 4, steering_angle);
    _mav_put_float(buf, 20, heading_rate);
    _mav_put_uint8_t(buf, 24, vcu_base_type);
    _mav_put_uint8_t(buf, 25, gear_position);
    _mav_put_uint8_t(buf, 26, steering_angle_valid);
    _mav_put_uint8_t(buf, 27, twist_valid);
    _mav_put_uint8_t(buf, 28, heading_rate_valid);
    _mav_put_uint8_t(buf, 29, operating_mode);
    _mav_put_float_array(buf, 8, vel, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN);
#else
    mavlink_vcu_base_status_t packet;
    packet.speed = speed;
    packet.steering_angle = steering_angle;
    packet.heading_rate = heading_rate;
    packet.vcu_base_type = vcu_base_type;
    packet.gear_position = gear_position;
    packet.steering_angle_valid = steering_angle_valid;
    packet.twist_valid = twist_valid;
    packet.heading_rate_valid = heading_rate_valid;
    packet.operating_mode = operating_mode;
    mav_array_memcpy(packet.vel, vel, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VCU_BASE_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VCU_BASE_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_CRC);
}

/**
 * @brief Encode a vcu_base_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vcu_base_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vcu_base_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vcu_base_status_t* vcu_base_status)
{
    return mavlink_msg_vcu_base_status_pack(system_id, component_id, msg, vcu_base_status->vcu_base_type, vcu_base_status->gear_position, vcu_base_status->speed, vcu_base_status->steering_angle_valid, vcu_base_status->steering_angle, vcu_base_status->twist_valid, vcu_base_status->vel, vcu_base_status->heading_rate_valid, vcu_base_status->heading_rate, vcu_base_status->operating_mode);
}

/**
 * @brief Encode a vcu_base_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vcu_base_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vcu_base_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vcu_base_status_t* vcu_base_status)
{
    return mavlink_msg_vcu_base_status_pack_chan(system_id, component_id, chan, msg, vcu_base_status->vcu_base_type, vcu_base_status->gear_position, vcu_base_status->speed, vcu_base_status->steering_angle_valid, vcu_base_status->steering_angle, vcu_base_status->twist_valid, vcu_base_status->vel, vcu_base_status->heading_rate_valid, vcu_base_status->heading_rate, vcu_base_status->operating_mode);
}

/**
 * @brief Send a vcu_base_status message
 * @param chan MAVLink channel to send the message
 *
 * @param vcu_base_type  vcu base type
 * @param gear_position  vcu gear position
 * @param speed [m/s] speed
 * @param steering_angle_valid  valid flag for steering angle
 * @param steering_angle [rad] steering angle
 * @param twist_valid  valid flag for twist
 * @param vel  Linear velocities along body axies in FRD frame
 * @param heading_rate_valid  valid flag for heading rate
 * @param heading_rate [rad/s] heading rate
 * @param operating_mode  operating mode, reserved
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vcu_base_status_send(mavlink_channel_t chan, uint8_t vcu_base_type, uint8_t gear_position, float speed, uint8_t steering_angle_valid, float steering_angle, uint8_t twist_valid, const float *vel, uint8_t heading_rate_valid, float heading_rate, uint8_t operating_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN];
    _mav_put_float(buf, 0, speed);
    _mav_put_float(buf, 4, steering_angle);
    _mav_put_float(buf, 20, heading_rate);
    _mav_put_uint8_t(buf, 24, vcu_base_type);
    _mav_put_uint8_t(buf, 25, gear_position);
    _mav_put_uint8_t(buf, 26, steering_angle_valid);
    _mav_put_uint8_t(buf, 27, twist_valid);
    _mav_put_uint8_t(buf, 28, heading_rate_valid);
    _mav_put_uint8_t(buf, 29, operating_mode);
    _mav_put_float_array(buf, 8, vel, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_BASE_STATUS, buf, MAVLINK_MSG_ID_VCU_BASE_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_CRC);
#else
    mavlink_vcu_base_status_t packet;
    packet.speed = speed;
    packet.steering_angle = steering_angle;
    packet.heading_rate = heading_rate;
    packet.vcu_base_type = vcu_base_type;
    packet.gear_position = gear_position;
    packet.steering_angle_valid = steering_angle_valid;
    packet.twist_valid = twist_valid;
    packet.heading_rate_valid = heading_rate_valid;
    packet.operating_mode = operating_mode;
    mav_array_memcpy(packet.vel, vel, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_BASE_STATUS, (const char *)&packet, MAVLINK_MSG_ID_VCU_BASE_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_CRC);
#endif
}

/**
 * @brief Send a vcu_base_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_vcu_base_status_send_struct(mavlink_channel_t chan, const mavlink_vcu_base_status_t* vcu_base_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_vcu_base_status_send(chan, vcu_base_status->vcu_base_type, vcu_base_status->gear_position, vcu_base_status->speed, vcu_base_status->steering_angle_valid, vcu_base_status->steering_angle, vcu_base_status->twist_valid, vcu_base_status->vel, vcu_base_status->heading_rate_valid, vcu_base_status->heading_rate, vcu_base_status->operating_mode);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_BASE_STATUS, (const char *)vcu_base_status, MAVLINK_MSG_ID_VCU_BASE_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vcu_base_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t vcu_base_type, uint8_t gear_position, float speed, uint8_t steering_angle_valid, float steering_angle, uint8_t twist_valid, const float *vel, uint8_t heading_rate_valid, float heading_rate, uint8_t operating_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, speed);
    _mav_put_float(buf, 4, steering_angle);
    _mav_put_float(buf, 20, heading_rate);
    _mav_put_uint8_t(buf, 24, vcu_base_type);
    _mav_put_uint8_t(buf, 25, gear_position);
    _mav_put_uint8_t(buf, 26, steering_angle_valid);
    _mav_put_uint8_t(buf, 27, twist_valid);
    _mav_put_uint8_t(buf, 28, heading_rate_valid);
    _mav_put_uint8_t(buf, 29, operating_mode);
    _mav_put_float_array(buf, 8, vel, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_BASE_STATUS, buf, MAVLINK_MSG_ID_VCU_BASE_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_CRC);
#else
    mavlink_vcu_base_status_t *packet = (mavlink_vcu_base_status_t *)msgbuf;
    packet->speed = speed;
    packet->steering_angle = steering_angle;
    packet->heading_rate = heading_rate;
    packet->vcu_base_type = vcu_base_type;
    packet->gear_position = gear_position;
    packet->steering_angle_valid = steering_angle_valid;
    packet->twist_valid = twist_valid;
    packet->heading_rate_valid = heading_rate_valid;
    packet->operating_mode = operating_mode;
    mav_array_memcpy(packet->vel, vel, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_BASE_STATUS, (const char *)packet, MAVLINK_MSG_ID_VCU_BASE_STATUS_MIN_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN, MAVLINK_MSG_ID_VCU_BASE_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE VCU_BASE_STATUS UNPACKING


/**
 * @brief Get field vcu_base_type from vcu_base_status message
 *
 * @return  vcu base type
 */
static inline uint8_t mavlink_msg_vcu_base_status_get_vcu_base_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field gear_position from vcu_base_status message
 *
 * @return  vcu gear position
 */
static inline uint8_t mavlink_msg_vcu_base_status_get_gear_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field speed from vcu_base_status message
 *
 * @return [m/s] speed
 */
static inline float mavlink_msg_vcu_base_status_get_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field steering_angle_valid from vcu_base_status message
 *
 * @return  valid flag for steering angle
 */
static inline uint8_t mavlink_msg_vcu_base_status_get_steering_angle_valid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  26);
}

/**
 * @brief Get field steering_angle from vcu_base_status message
 *
 * @return [rad] steering angle
 */
static inline float mavlink_msg_vcu_base_status_get_steering_angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field twist_valid from vcu_base_status message
 *
 * @return  valid flag for twist
 */
static inline uint8_t mavlink_msg_vcu_base_status_get_twist_valid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  27);
}

/**
 * @brief Get field vel from vcu_base_status message
 *
 * @return  Linear velocities along body axies in FRD frame
 */
static inline uint16_t mavlink_msg_vcu_base_status_get_vel(const mavlink_message_t* msg, float *vel)
{
    return _MAV_RETURN_float_array(msg, vel, 3,  8);
}

/**
 * @brief Get field heading_rate_valid from vcu_base_status message
 *
 * @return  valid flag for heading rate
 */
static inline uint8_t mavlink_msg_vcu_base_status_get_heading_rate_valid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field heading_rate from vcu_base_status message
 *
 * @return [rad/s] heading rate
 */
static inline float mavlink_msg_vcu_base_status_get_heading_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field operating_mode from vcu_base_status message
 *
 * @return  operating mode, reserved
 */
static inline uint8_t mavlink_msg_vcu_base_status_get_operating_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  29);
}

/**
 * @brief Decode a vcu_base_status message into a struct
 *
 * @param msg The message to decode
 * @param vcu_base_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_vcu_base_status_decode(const mavlink_message_t* msg, mavlink_vcu_base_status_t* vcu_base_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    vcu_base_status->speed = mavlink_msg_vcu_base_status_get_speed(msg);
    vcu_base_status->steering_angle = mavlink_msg_vcu_base_status_get_steering_angle(msg);
    mavlink_msg_vcu_base_status_get_vel(msg, vcu_base_status->vel);
    vcu_base_status->heading_rate = mavlink_msg_vcu_base_status_get_heading_rate(msg);
    vcu_base_status->vcu_base_type = mavlink_msg_vcu_base_status_get_vcu_base_type(msg);
    vcu_base_status->gear_position = mavlink_msg_vcu_base_status_get_gear_position(msg);
    vcu_base_status->steering_angle_valid = mavlink_msg_vcu_base_status_get_steering_angle_valid(msg);
    vcu_base_status->twist_valid = mavlink_msg_vcu_base_status_get_twist_valid(msg);
    vcu_base_status->heading_rate_valid = mavlink_msg_vcu_base_status_get_heading_rate_valid(msg);
    vcu_base_status->operating_mode = mavlink_msg_vcu_base_status_get_operating_mode(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN? msg->len : MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN;
        memset(vcu_base_status, 0, MAVLINK_MSG_ID_VCU_BASE_STATUS_LEN);
    memcpy(vcu_base_status, _MAV_PAYLOAD(msg), len);
#endif
}
