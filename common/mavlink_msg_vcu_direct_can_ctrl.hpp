// MESSAGE VCU_DIRECT_CAN_CTRL support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief VCU_DIRECT_CAN_CTRL message
 *
 * Direct CAN control message that will be parsed to the VCU base, see pursuit_msgs/VcuDirectCanCtrl definition
 */
struct VCU_DIRECT_CAN_CTRL : mavlink::Message {
    static constexpr msgid_t MSG_ID = 345;
    static constexpr size_t LENGTH = 12;
    static constexpr size_t MIN_LENGTH = 12;
    static constexpr uint8_t CRC_EXTRA = 117;
    static constexpr auto NAME = "VCU_DIRECT_CAN_CTRL";


    uint32_t msg_id; /*<  message ID */
    std::array<uint8_t, 8> msg_body; /*<  message body */


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
        ss << "  msg_id: " << msg_id << std::endl;
        ss << "  msg_body: [" << to_string(msg_body) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << msg_id;                        // offset: 0
        map << msg_body;                      // offset: 4
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> msg_id;                        // offset: 0
        map >> msg_body;                      // offset: 4
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
