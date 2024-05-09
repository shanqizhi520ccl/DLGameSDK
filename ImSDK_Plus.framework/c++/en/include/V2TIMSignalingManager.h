// Copyright (c) 2021 Tencent. All rights reserved.

/////////////////////////////////////////////////////////////////////
//
//                     Signaling
//
/////////////////////////////////////////////////////////////////////

#ifndef __V2TIM_SIGNALING_MANAGER_H__
#define __V2TIM_SIGNALING_MANAGER_H__

#include "V2TIMCallback.h"
#include "V2TIMDefine.h"
#include "V2TIMListener.h"
#include "V2TIMSignaling.h"


class TIM_API V2TIMSignalingManager {
public:
    virtual ~V2TIMSignalingManager() {}

    /**
     *  Add the signaling listener
     */
    virtual void AddSignalingListener(V2TIMSignalingListener* listener) = 0;

    /**
     * Remove the signaling listener
     */
    virtual void RemoveSignalingListener(V2TIMSignalingListener* listener) = 0;

    /**
     * Invite someone
     *
     * @param invitee Invitee's user ID
     * @param data Custom data
     * @param onlineUserOnly Whether the message can be received only by online users. If this field is set to true, the message can be received only by online users, and the Invite operation does not produce historical messages (nor do subsequent Cancel, Accept, Reject, and Timeout operations of this invite operation). The invite operation does not produce historical messages (nor do subsequent cancel, accept, reject, and timeout operations of this invite operation).
     * @param offlinePushInfo Offline push information, where the desc field is required. The information specified by desc will be displayed by default during push.
     * @param timeout Timeout duration, in seconds. If it is set to 0, the SDK does not perform timeout detection nor trigger the OnInvitationTimeout callback.
     * @return inviteID Invitation ID. If the invitation fails, empty string is returned.
     */
    virtual V2TIMString Invite(const V2TIMString& invitee, const V2TIMString& data,
                               bool onlineUserOnly,
                               const V2TIMOfflinePushInfo& offlinePushInfo, int timeout,
                               V2TIMCallback* callback) = 0;

    /**
     * Invite certain users in the group
     *
     * @param groupID   ID of the inviter's group
     * @param inviteeList List of invitees. Invitees specified by inviteeList must be in the group specified by groupID. Otherwise, the invitation fails.
     * @param onlineUserOnly Whether the message can be received only by online users. If this field is set to true, the message can be received only by online users, and the Invite operation does not produce historical messages (nor do subsequent Cancel, Accept, Reject, and Timeout operations of this invite operation). The invite operation does not produce historical messages (nor do subsequent cancel, accept, reject, and timeout operations of this invite operation).。
     * @param timeout Timeout duration, in seconds. If it is set to 0, the SDK does not perform timeout detection nor trigger the OnInvitationTimeout callback.
     * @return inviteID Invitation ID. If the invitation fails, empty string is returned.
     *
     * @note
     * Currently, Group invitation does not support offline push. If you need offline push, you can send custom offline push messages to invitees separately
     * For more descriptions, see TRTCAVCallImpl -> sendOnlineMessageWithOfflinePushInfo API
     */
    virtual V2TIMString InviteInGroup(const V2TIMString& groupID,
                                      const V2TIMStringVector& inviteeList, const V2TIMString& data,
                                      bool onlineUserOnly, int timeout,
                                      V2TIMCallback* callback) = 0;

    /**
     * The inviter canceled the invitation
     *
     * @param inviteID Invitation ID
     *
     * @note If all invitees have processed the current invitation (including timeout), the current invitation cannot be cancelled.
     */
    virtual void Cancel(const V2TIMString& inviteID, const V2TIMString& data,
                        V2TIMCallback* callback) = 0;

    /**
     * The invitee accepts the invitation
     *
     * @note Users cannot accept only invitations that are not targeted at themselves. When receiving the OnReceiveNewInvitation callback, check whether the current user is specified in inviteeList. If no, the current user cannot Accept the invitation.。
     */
    virtual void Accept(const V2TIMString& inviteID, const V2TIMString& data,
                        V2TIMCallback* callback) = 0;

    /**
     * The invitee rejects the invitation
     *
     * @note Users cannot reject only invitations that are not targeted at themselves. When receiving the OnReceiveNewInvitation callback, check whether the current user is specified in inviteeList. If no, the current user cannot Reject the invitation.
     */
    virtual void Reject(const V2TIMString& inviteID, const V2TIMString& data,
                        V2TIMCallback* callback) = 0;

    /**
     * Get the signaling information
     *
     *  If onlineUserOnly is set to false in the invite operation, a custom message is generated for each signaling operation (including the Invite, Cancel, Accept, Reject, and Timeout operations). The message will be delivered to users via V2TIMAdvancedMsgListener -> OnRecvNewMessage and can be pulled by users via historical message pulling. If you want to customize the display text based on the signaling information, call the following API to get the signaling information.
     * @param msg Message object
     * @return V2TIMSignalingInfo Signaling information. If the V2TIMSignalingInfo::inviteID value is empty string, msg is not a signaling message.
     */
    virtual V2TIMSignalingInfo GetSignalingInfo(const V2TIMMessage& msg) = 0;

    /**
     *  Add invitation signaling
     *
     *  It is mainly used for inviter to send group invitation when the invitees are offline, and sync the signaling info to SDK after the invitees are online, so as to use the signaling function normally.
     *
     *  When the invitee clicks the offline push message notification and starts the App:
     *  1. If the inviter sends 1v1 signaling while the invitee is offline, SDK can automatically sync the invitation signaling. If the invitation does not timed out, onReceiveNewInvitation will be called.
     *
     *  2. If the inviter sends group signaling while the invitee is offline, different SDK behaviors are as follows:
     *  - versions lower than 6.7:
     *  SDK cannot automatically sync the invitation signaling. If the invitee needs to deal with the invitation, the inviter can send an extra C2C offline push message carrying V2TIMSignalingInfo object to each invitee while sending the invitation. When the invitee receives the offline push message, he could invoke addInvitedSignaling to sync the V2TIMSignalingInfo to SDK.
     *  - versions equal or higher than 6.7:
     *  SDK can automatically sync messages for the last 30 seconds. If it contains invitation signaling that does not timed out, onReceiveNewInvitation will be called. You no longer need to call this API to sync the invitation signaling info.
     *
     *  @note If the added signaling information already exists, the callback throws the ERR_SDK_SIGNALING_ALREADY_EXISTS error code.
     */
    virtual void AddInvitedSignaling(const V2TIMSignalingInfo& info, V2TIMCallback* callback) = 0;

    /**
     *  Modify the invitaion (supported only in 6.7 and later versions)
     *
     *  @note Only supports modifying the custom field data of the invitation. Invitation that can only be received by online users cannot be modified.
     */
    virtual void ModifyInvitation(const V2TIMString& inviteID, const V2TIMString& data,
                                  V2TIMCallback* callback) = 0;
};

#endif  // __V2TIM_SIGNALING_MANAGER_H__
