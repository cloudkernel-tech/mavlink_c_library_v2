// MESSAGE VCU_COMMAND_VELOCITY support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief VCU_COMMAND_VELOCITY message
 *
 * VCU command velocity from/to the pursuit autopilot
 */
struct VCU_COMMAND_VELOCITY : mavlink::Message {
    static constexpr msgid_t MSG_ID = 343;
    static constexpr size_t LENGTH = 25;
    static constexpr size_t MIN_LENGTH = 25;
    static constexpr uint8_t CRC_EXTRA = 130;
    static constexpr auto NAME = "VCU_COMMAND_VELOCITY";


    std::array<float, 3> linear_vel; /*<  Linear velocities along body axies in FRD frame */
    std::array<float, 3> angular_vel; /*<  Angular velocities along body axies in FRD frame */
    uint8_t flag_nav_src; /*<  Boolean indicating the command is from the online navigation module */


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
        ss << "  linear_vel: [" << to_string(linear_vel) << "]" << std::endl;
        ss << "  angular_vel: [" << to_string(angular_vel) << "]" << std::endl;
        ss << "  flag_nav_src: " << +flag_nav_src << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << linear_vel;                    // offset: 0
        map << angular_vel;                   // offset: 12
        map << flag_nav_src;                  // offset: 24
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> linear_vel;                    // offset: 0
        map >> angular_vel;                   // offset: 12
        map >> flag_nav_src;                  // offset: 24
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
