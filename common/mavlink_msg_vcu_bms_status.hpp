// MESSAGE VCU_BMS_STATUS support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief VCU_BMS_STATUS message
 *
 * VCU bms status from the pursuit autopilot, see pursuit_msgs/VcuBmsStatus definition
 */
struct VCU_BMS_STATUS : mavlink::Message {
    static constexpr msgid_t MSG_ID = 344;
    static constexpr size_t LENGTH = 24;
    static constexpr size_t MIN_LENGTH = 24;
    static constexpr uint8_t CRC_EXTRA = 118;
    static constexpr auto NAME = "VCU_BMS_STATUS";


    float voltage; /*< [v] voltage */
    float current; /*< [A] current */
    float remained_capacity; /*< [A*h] remained_capacity */
    float remained_percentage; /*<  remained_percentage */
    float max_temperature; /*< [Celsius] max_temperature */
    float min_temperature; /*< [Celsius] min_temperature */


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
        ss << "  voltage: " << voltage << std::endl;
        ss << "  current: " << current << std::endl;
        ss << "  remained_capacity: " << remained_capacity << std::endl;
        ss << "  remained_percentage: " << remained_percentage << std::endl;
        ss << "  max_temperature: " << max_temperature << std::endl;
        ss << "  min_temperature: " << min_temperature << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << voltage;                       // offset: 0
        map << current;                       // offset: 4
        map << remained_capacity;             // offset: 8
        map << remained_percentage;           // offset: 12
        map << max_temperature;               // offset: 16
        map << min_temperature;               // offset: 20
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> voltage;                       // offset: 0
        map >> current;                       // offset: 4
        map >> remained_capacity;             // offset: 8
        map >> remained_percentage;           // offset: 12
        map >> max_temperature;               // offset: 16
        map >> min_temperature;               // offset: 20
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
