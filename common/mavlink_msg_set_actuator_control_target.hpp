// MESSAGE SET_ACTUATOR_CONTROL_TARGET support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief SET_ACTUATOR_CONTROL_TARGET message
 *
 * Set the vehicle attitude and body angular rates.
 */
struct SET_ACTUATOR_CONTROL_TARGET : mavlink::Message {
    static constexpr msgid_t MSG_ID = 139;
    static constexpr size_t LENGTH = 44;
    static constexpr size_t MIN_LENGTH = 44;
    static constexpr uint8_t CRC_EXTRA = 241;
    static constexpr auto NAME = "SET_ACTUATOR_CONTROL_TARGET";


    uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. */
    uint8_t group_mlx; /*<  Actuator group. The "_mlx" indicates this is a multi-instance message and a MAVLink parser should use this field to difference between instances. */
    uint8_t target_system; /*<  System ID */
    uint8_t target_component; /*<  Component ID */
    std::array<float, 8> controls; /*<  Actuator controls. Normed to -1..+1 where 0 is neutral position. Throttle for single rotation direction motors is 0..1, negative range for reverse direction. Standard mapping for attitude controls (group 0): (index 0-7): roll, pitch, yaw, throttle, flaps, spoilers, airbrakes, landing gear. Load a pass-through mixer to repurpose them as generic outputs. */
    uint8_t flag_rover_mode; /*<  Boolean indicating whether the direct actuator control is in the rover mode, true will force direct actuator control, added for kerloud product */


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
        ss << "  time_usec: " << time_usec << std::endl;
        ss << "  group_mlx: " << +group_mlx << std::endl;
        ss << "  target_system: " << +target_system << std::endl;
        ss << "  target_component: " << +target_component << std::endl;
        ss << "  controls: [" << to_string(controls) << "]" << std::endl;
        ss << "  flag_rover_mode: " << +flag_rover_mode << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_usec;                     // offset: 0
        map << controls;                      // offset: 8
        map << group_mlx;                     // offset: 40
        map << target_system;                 // offset: 41
        map << target_component;              // offset: 42
        map << flag_rover_mode;               // offset: 43
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_usec;                     // offset: 0
        map >> controls;                      // offset: 8
        map >> group_mlx;                     // offset: 40
        map >> target_system;                 // offset: 41
        map >> target_component;              // offset: 42
        map >> flag_rover_mode;               // offset: 43
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
