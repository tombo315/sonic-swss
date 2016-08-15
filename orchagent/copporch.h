#ifndef SWSS_COPPORCH_H
#define SWSS_COPPORCH_H

#include <map>
#include "orch.h"

const std::string copp_trap_id_list                = "trap_ids";
const std::string copp_queue_field                 = "queue";
// policer fields
const std::string copp_policer_meter_type_field    = "meter_type";
const std::string copp_policer_mode_field          = "mode";
const std::string copp_policer_color_field         = "color";
const std::string copp_policer_cbs_field           = "cbs";
const std::string copp_policer_cir_field           = "cir";
const std::string copp_policer_pbs_field           = "pbs";
const std::string copp_policer_pir_field           = "pir";
const std::string copp_trap_action_field           = "trap_action";
const std::string copp_policer_action_green_field  = "green_action";
const std::string copp_policer_action_red_field    = "red_action";
const std::string copp_policer_action_yellow_field = "yellow_action";

class CoppOrch : public Orch
{
public:
    CoppOrch(DBConnector *db, string tableName);
protected:
    virtual void doTask(Consumer& consumer);
    task_process_status processCoppRule(Consumer& consumer);
    bool isValidList(vector<string> &trap_id_list, vector<string> &all_items) const;
    void getTrapIdList(vector<string> &trap_id_name_list, vector<sai_hostif_trap_id_t> &trap_id_list) const;
    bool applyTrapIds(sai_object_id_t trap_group, vector<string> &trap_id_name_list, std::vector<sai_attribute_t> &trap_id_attribs);
    bool removePolicer(string trap_group_name);
    sai_object_id_t getPolicer(string trap_group_name);
    bool createPolicer(string trap_group, std::vector<sai_attribute_t> &policer_attribs);
    object_map m_trap_group_map;
    std::map<sai_object_id_t, sai_object_id_t> m_trap_group_policer_map;
};
#endif /* SWSS_COPPORCH_H */

