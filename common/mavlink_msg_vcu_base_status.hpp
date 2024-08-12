// MESSAGE VCU_BASE_STATUS support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief VCU_BASE_STATUS message
 *
 * VCU base status from the pursuit autopilot, see pursuit_msgs/VcuBaseStatus definition
 */
struct VCU_BASE_STATUS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 342;
    static constexpr size_t LENGTH = 30;
    static constexpr size_t MIN_LENGTH = 30;
    static constexpr uint8_t CRC_EXTRA = 64;
    static constexpr auto NAME = "VCU_BASE_STATUS";


    uint8_t vcu_base_type; /*<  vcu base type */
    uint8_t gear_position; /*<  vcu gear position */
    float speed; /*< [m/s] speed */
    uint8_t steering_angle_valid; /*<  valid flag for steering angle */
    float steering_angle; /*< [rad] steering angle */
    uint8_t twist_valid; /*<  valid flag for twist */
    std::array<float, 3> vel; /*<  Linear velocities along body axies in FRD frame */
    uint8_t heading_rate_valid; /*<  valid flag for heading rate */
    float heading_rate; /*< [rad/s] heading rate */
    uint8_t operating_mode; /*<  operating mode, reserved */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  vcu_base_type: " << +vcu_base_type << std::endl;
        ss << "  gear_position: " << +gear_position << std::endl;
        ss << "  speed: " << speed << std::endl;
        ss << "  steering_angle_valid: " << +steering_angle_valid << std::endl;
        ss << "  steering_angle: " << steering_angle << std::endl;
        ss << "  twist_valid: " << +twist_valid << std::endl;
        ss << "  vel: [" << to_string(vel) << "]" << std::endl;
        ss << "  heading_rate_valid: " << +heading_rate_valid << std::endl;
        ss << "  heading_rate: " << heading_rate << std::endl;
        ss << "  operating_mode: " << +operating_mode << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << speed;                         // offset: 0
        map << steering_angle;                // offset: 4
        map << vel;                           // offset: 8
        map << heading_rate;                  // offset: 20
        map << vcu_base_type;                 // offset: 24
        map << gear_position;                 // offset: 25
        map << steering_angle_valid;          // offset: 26
        map << twist_valid;                   // offset: 27
        map << heading_rate_valid;            // offset: 28
        map << operating_mode;                // offset: 29
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> speed;                         // offset: 0
        map >> steering_angle;                // offset: 4
        map >> vel;                           // offset: 8
        map >> heading_rate;                  // offset: 20
        map >> vcu_base_type;                 // offset: 24
        map >> gear_position;                 // offset: 25
        map >> steering_angle_valid;          // offset: 26
        map >> twist_valid;                   // offset: 27
        map >> heading_rate_valid;            // offset: 28
        map >> operating_mode;                // offset: 29
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
