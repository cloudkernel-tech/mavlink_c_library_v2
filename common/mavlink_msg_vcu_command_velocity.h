#pragma once
// MESSAGE VCU_COMMAND_VELOCITY PACKING

#define MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY 343


typedef struct __mavlink_vcu_command_velocity_t {
 float linear_vel[3]; /*<  Linear velocities along body axies in FRD frame*/
 float angular_vel[3]; /*<  Angular velocities along body axies in FRD frame*/
 uint8_t flag_nav_src; /*<  Boolean indicating the command is from the online navigation module*/
} mavlink_vcu_command_velocity_t;

#define MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN 25
#define MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_MIN_LEN 25
#define MAVLINK_MSG_ID_343_LEN 25
#define MAVLINK_MSG_ID_343_MIN_LEN 25

#define MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_CRC 130
#define MAVLINK_MSG_ID_343_CRC 130

#define MAVLINK_MSG_VCU_COMMAND_VELOCITY_FIELD_LINEAR_VEL_LEN 3
#define MAVLINK_MSG_VCU_COMMAND_VELOCITY_FIELD_ANGULAR_VEL_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VCU_COMMAND_VELOCITY { \
    343, \
    "VCU_COMMAND_VELOCITY", \
    3, \
    {  { "linear_vel", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_vcu_command_velocity_t, linear_vel) }, \
         { "angular_vel", NULL, MAVLINK_TYPE_FLOAT, 3, 12, offsetof(mavlink_vcu_command_velocity_t, angular_vel) }, \
         { "flag_nav_src", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_vcu_command_velocity_t, flag_nav_src) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VCU_COMMAND_VELOCITY { \
    "VCU_COMMAND_VELOCITY", \
    3, \
    {  { "linear_vel", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_vcu_command_velocity_t, linear_vel) }, \
         { "angular_vel", NULL, MAVLINK_TYPE_FLOAT, 3, 12, offsetof(mavlink_vcu_command_velocity_t, angular_vel) }, \
         { "flag_nav_src", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_vcu_command_velocity_t, flag_nav_src) }, \
         } \
}
#endif

/**
 * @brief Pack a vcu_command_velocity message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param linear_vel  Linear velocities along body axies in FRD frame
 * @param angular_vel  Angular velocities along body axies in FRD frame
 * @param flag_nav_src  Boolean indicating the command is from the online navigation module
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vcu_command_velocity_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const float *linear_vel, const float *angular_vel, uint8_t flag_nav_src)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN];
    _mav_put_uint8_t(buf, 24, flag_nav_src);
    _mav_put_float_array(buf, 0, linear_vel, 3);
    _mav_put_float_array(buf, 12, angular_vel, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN);
#else
    mavlink_vcu_command_velocity_t packet;
    packet.flag_nav_src = flag_nav_src;
    mav_array_memcpy(packet.linear_vel, linear_vel, sizeof(float)*3);
    mav_array_memcpy(packet.angular_vel, angular_vel, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_CRC);
}

/**
 * @brief Pack a vcu_command_velocity message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param linear_vel  Linear velocities along body axies in FRD frame
 * @param angular_vel  Angular velocities along body axies in FRD frame
 * @param flag_nav_src  Boolean indicating the command is from the online navigation module
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vcu_command_velocity_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const float *linear_vel,const float *angular_vel,uint8_t flag_nav_src)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN];
    _mav_put_uint8_t(buf, 24, flag_nav_src);
    _mav_put_float_array(buf, 0, linear_vel, 3);
    _mav_put_float_array(buf, 12, angular_vel, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN);
#else
    mavlink_vcu_command_velocity_t packet;
    packet.flag_nav_src = flag_nav_src;
    mav_array_memcpy(packet.linear_vel, linear_vel, sizeof(float)*3);
    mav_array_memcpy(packet.angular_vel, angular_vel, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_CRC);
}

/**
 * @brief Encode a vcu_command_velocity struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vcu_command_velocity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vcu_command_velocity_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vcu_command_velocity_t* vcu_command_velocity)
{
    return mavlink_msg_vcu_command_velocity_pack(system_id, component_id, msg, vcu_command_velocity->linear_vel, vcu_command_velocity->angular_vel, vcu_command_velocity->flag_nav_src);
}

/**
 * @brief Encode a vcu_command_velocity struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vcu_command_velocity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vcu_command_velocity_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vcu_command_velocity_t* vcu_command_velocity)
{
    return mavlink_msg_vcu_command_velocity_pack_chan(system_id, component_id, chan, msg, vcu_command_velocity->linear_vel, vcu_command_velocity->angular_vel, vcu_command_velocity->flag_nav_src);
}

/**
 * @brief Send a vcu_command_velocity message
 * @param chan MAVLink channel to send the message
 *
 * @param linear_vel  Linear velocities along body axies in FRD frame
 * @param angular_vel  Angular velocities along body axies in FRD frame
 * @param flag_nav_src  Boolean indicating the command is from the online navigation module
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vcu_command_velocity_send(mavlink_channel_t chan, const float *linear_vel, const float *angular_vel, uint8_t flag_nav_src)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN];
    _mav_put_uint8_t(buf, 24, flag_nav_src);
    _mav_put_float_array(buf, 0, linear_vel, 3);
    _mav_put_float_array(buf, 12, angular_vel, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY, buf, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_CRC);
#else
    mavlink_vcu_command_velocity_t packet;
    packet.flag_nav_src = flag_nav_src;
    mav_array_memcpy(packet.linear_vel, linear_vel, sizeof(float)*3);
    mav_array_memcpy(packet.angular_vel, angular_vel, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY, (const char *)&packet, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_CRC);
#endif
}

/**
 * @brief Send a vcu_command_velocity message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_vcu_command_velocity_send_struct(mavlink_channel_t chan, const mavlink_vcu_command_velocity_t* vcu_command_velocity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_vcu_command_velocity_send(chan, vcu_command_velocity->linear_vel, vcu_command_velocity->angular_vel, vcu_command_velocity->flag_nav_src);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY, (const char *)vcu_command_velocity, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_CRC);
#endif
}

#if MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vcu_command_velocity_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const float *linear_vel, const float *angular_vel, uint8_t flag_nav_src)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 24, flag_nav_src);
    _mav_put_float_array(buf, 0, linear_vel, 3);
    _mav_put_float_array(buf, 12, angular_vel, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY, buf, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_CRC);
#else
    mavlink_vcu_command_velocity_t *packet = (mavlink_vcu_command_velocity_t *)msgbuf;
    packet->flag_nav_src = flag_nav_src;
    mav_array_memcpy(packet->linear_vel, linear_vel, sizeof(float)*3);
    mav_array_memcpy(packet->angular_vel, angular_vel, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY, (const char *)packet, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_CRC);
#endif
}
#endif

#endif

// MESSAGE VCU_COMMAND_VELOCITY UNPACKING


/**
 * @brief Get field linear_vel from vcu_command_velocity message
 *
 * @return  Linear velocities along body axies in FRD frame
 */
static inline uint16_t mavlink_msg_vcu_command_velocity_get_linear_vel(const mavlink_message_t* msg, float *linear_vel)
{
    return _MAV_RETURN_float_array(msg, linear_vel, 3,  0);
}

/**
 * @brief Get field angular_vel from vcu_command_velocity message
 *
 * @return  Angular velocities along body axies in FRD frame
 */
static inline uint16_t mavlink_msg_vcu_command_velocity_get_angular_vel(const mavlink_message_t* msg, float *angular_vel)
{
    return _MAV_RETURN_float_array(msg, angular_vel, 3,  12);
}

/**
 * @brief Get field flag_nav_src from vcu_command_velocity message
 *
 * @return  Boolean indicating the command is from the online navigation module
 */
static inline uint8_t mavlink_msg_vcu_command_velocity_get_flag_nav_src(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Decode a vcu_command_velocity message into a struct
 *
 * @param msg The message to decode
 * @param vcu_command_velocity C-struct to decode the message contents into
 */
static inline void mavlink_msg_vcu_command_velocity_decode(const mavlink_message_t* msg, mavlink_vcu_command_velocity_t* vcu_command_velocity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_vcu_command_velocity_get_linear_vel(msg, vcu_command_velocity->linear_vel);
    mavlink_msg_vcu_command_velocity_get_angular_vel(msg, vcu_command_velocity->angular_vel);
    vcu_command_velocity->flag_nav_src = mavlink_msg_vcu_command_velocity_get_flag_nav_src(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN? msg->len : MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN;
        memset(vcu_command_velocity, 0, MAVLINK_MSG_ID_VCU_COMMAND_VELOCITY_LEN);
    memcpy(vcu_command_velocity, _MAV_PAYLOAD(msg), len);
#endif
}
