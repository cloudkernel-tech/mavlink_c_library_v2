// MESSAGE AVOIDANCE_STATUS support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief AVOIDANCE_STATUS message
 *
 * Avoidance status used for pursuit AGV navigation in 2024
 */
struct AVOIDANCE_STATUS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 341;
    static constexpr size_t LENGTH = 8;
    static constexpr size_t MIN_LENGTH = 8;
    static constexpr uint8_t CRC_EXTRA = 145;
    static constexpr auto NAME = "AVOIDANCE_STATUS";


    uint8_t flag_obstacle_in_far_front; /*<  Boolean indicating whether an obstacle is in far front of the vehicle */
    uint8_t flag_obstacle_far_nearby; /*<  Boolean indicating whether an obstacle is in the neighbourhood of the vehicle with a large distance */
    uint8_t flag_obstacle_in_front; /*<  Boolean indicating whether an obstacle is at the front of the vehicle */
    uint8_t flag_obstacle_in_rear; /*<  Boolean indicating whether an obstacle is at the back of the vehicle */
    uint8_t flag_obstacle_nearby; /*<  Boolean indicating whether an obstacle is within a distance from the vehicle */
    uint8_t flag_nav_task_active; /*<  Boolean indicating whether the navigation task is active onboard */
    uint8_t flag_nav_local_plan_valid; /*<  Boolean indicating whether the local plan from navigation is valid for obstacle avoidance */
    uint8_t flag_laser_scan_data_valid; /*<  Boolean indicating whether the laser scan data is valid for obstacle detection */


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
        ss << "  flag_obstacle_in_far_front: " << +flag_obstacle_in_far_front << std::endl;
        ss << "  flag_obstacle_far_nearby: " << +flag_obstacle_far_nearby << std::endl;
        ss << "  flag_obstacle_in_front: " << +flag_obstacle_in_front << std::endl;
        ss << "  flag_obstacle_in_rear: " << +flag_obstacle_in_rear << std::endl;
        ss << "  flag_obstacle_nearby: " << +flag_obstacle_nearby << std::endl;
        ss << "  flag_nav_task_active: " << +flag_nav_task_active << std::endl;
        ss << "  flag_nav_local_plan_valid: " << +flag_nav_local_plan_valid << std::endl;
        ss << "  flag_laser_scan_data_valid: " << +flag_laser_scan_data_valid << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << flag_obstacle_in_far_front;    // offset: 0
        map << flag_obstacle_far_nearby;      // offset: 1
        map << flag_obstacle_in_front;        // offset: 2
        map << flag_obstacle_in_rear;         // offset: 3
        map << flag_obstacle_nearby;          // offset: 4
        map << flag_nav_task_active;          // offset: 5
        map << flag_nav_local_plan_valid;     // offset: 6
        map << flag_laser_scan_data_valid;    // offset: 7
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> flag_obstacle_in_far_front;    // offset: 0
        map >> flag_obstacle_far_nearby;      // offset: 1
        map >> flag_obstacle_in_front;        // offset: 2
        map >> flag_obstacle_in_rear;         // offset: 3
        map >> flag_obstacle_nearby;          // offset: 4
        map >> flag_nav_task_active;          // offset: 5
        map >> flag_nav_local_plan_valid;     // offset: 6
        map >> flag_laser_scan_data_valid;    // offset: 7
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
