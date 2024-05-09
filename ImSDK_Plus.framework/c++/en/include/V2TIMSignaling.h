// Copyright (c) 2021 Tencent. All rights reserved.

#ifndef __V2TIM_SIGNALING_H__
#define __V2TIM_SIGNALING_H__

#include "V2TIMCommon.h"
#include "V2TIMDefine.h"
#include "V2TIMMessage.h"

/////////////////////////////////////////////////////////////////////////////////
//
//                    （一）Enumeration definition
//
/////////////////////////////////////////////////////////////////////////////////

// Operation type
enum V2TIMSignalingActionType {
    // The inviter initiated the invitation
    SignalingActionType_Invite = 1,
    // The inviter canceled the invitation
    SignalingActionType_Cancel_Invite = 2,
    // The invitee accepted the invitation
    SignalingActionType_Accept_Invite = 3,
    // The invitee declined the invitation
    SignalingActionType_Reject_Invite = 4,
    // The invitation timed out
    SignalingActionType_Invite_Timeout = 5,
};

/////////////////////////////////////////////////////////////////////////////////
//
//                     Struct definition
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMSignalingInfo {
    // The identification of signaling
    V2TIMString inviteID;
    // For a group signaling, groupID is the signaling receiving group ID. Otherwise, groupID is null
    V2TIMString groupID;
    // The identification of inviter
    V2TIMString inviter;
    // The list of invitee
    V2TIMStringVector inviteeList;
    // The content of signaling
    V2TIMString data;
    // The Operation type of signaling
    V2TIMSignalingActionType actionType;
    // The timeout of signaling
    int timeout;

    V2TIMSignalingInfo();
    V2TIMSignalingInfo(const V2TIMSignalingInfo& signalingInfo);
    ~V2TIMSignalingInfo();
};

#endif /* __V2TIM_SIGNALING_H__ */
