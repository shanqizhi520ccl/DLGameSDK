// Copyright (c) 2021 Tencent. All rights reserved.

/////////////////////////////////////////////////////////////////////////////////
//
//                          Definition of global listener for IMSDK
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef __V2TIM_LISTENER_H__
#define __V2TIM_LISTENER_H__

#include "V2TIMCommon.h"
#include "V2TIMConversation.h"
#include "V2TIMFriendship.h"
#include "V2TIMGroup.h"
#include "V2TIMMessage.h"

/////////////////////////////////////////////////////////////////////////////////
//
//                 Definition of V2TIMSDKListener
//
/////////////////////////////////////////////////////////////////////////////////

class TIM_API V2TIMSDKListener {
public:
    V2TIMSDKListener();

    virtual ~V2TIMSDKListener();

    /**
     * The SDK is connecting to the CVM instance
     */
    virtual void OnConnecting() {}

    /**
     * The SDK is successfully connected to the CVM instance
     */
    virtual void OnConnectSuccess() {}

    /**
     * The SDK failed to connect to the CVM instance
     */
    virtual void OnConnectFailed(int error_code, const V2TIMString &error_message) {}

    /**
     * The current user is kicked offline: the SDK notifies the user on the UI, and the user can choose to call the login() function of V2TIMManager to log in again.
     */
    virtual void OnKickedOffline() {}

    /**
     * The ticket expires when the user is online: the user needs to generate a new userSig and call the login() function of V2TIMManager to log in again.
     */
    virtual void OnUserSigExpired() {}

    /**
     * The profile of the current user was updated
     *
     */
    virtual void OnSelfInfoUpdated(const V2TIMUserFullInfo &info) {}

    /**
     * User status changed notification
     *
     * @note You will receive this callback in the following cases：
     * 1. The status (including status and custom status) changed of the subscribed user.
     * 2. The status (including status and custom status) changed of the friends. (Need to turn on the switch on console).
     * 3. The custom status changed of yourself.
     */
    virtual void OnUserStatusChanged(const V2TIMUserStatusVector &userStatusList) {}
};

/////////////////////////////////////////////////////////////////////////////////
//
//              Definition of V2TIMSimpleMsgListener
//
/////////////////////////////////////////////////////////////////////////////////

class TIM_API V2TIMSimpleMsgListener {
public:
    V2TIMSimpleMsgListener();

    virtual ~V2TIMSimpleMsgListener();

    /**
     * Received a one-to-one text message
     */
    virtual void OnRecvC2CTextMessage(const V2TIMString &msgID, const V2TIMUserFullInfo &sender,
                                      const V2TIMString &text) {}

    /**
     * Received a one-to-one custom (signaling) message
     */
    virtual void OnRecvC2CCustomMessage(const V2TIMString &msgID, const V2TIMUserFullInfo &sender,
                                        const V2TIMBuffer &customData) {}

    /**
     * Received a group text message
     */
    virtual void OnRecvGroupTextMessage(const V2TIMString &msgID, const V2TIMString &groupID,
                                        const V2TIMGroupMemberFullInfo &sender,
                                        const V2TIMString &text) {}

    /**
     * Received a group custom (signaling) message
     */
    virtual void OnRecvGroupCustomMessage(const V2TIMString &msgID, const V2TIMString &groupID,
                                          const V2TIMGroupMemberFullInfo &sender,
                                          const V2TIMBuffer &customData) {}
};

DEFINE_POINT_VECTOR(V2TIMSimpleMsgListener)
typedef TXPV2TIMSimpleMsgListenerVector V2TIMSimpleMsgListenerVector;

/////////////////////////////////////////////////////////////////////////////////
//
//                    Definition of V2TIMAdvancedMsgListener
//
/////////////////////////////////////////////////////////////////////////////////

class TIM_API V2TIMAdvancedMsgListener {
public:
    V2TIMAdvancedMsgListener();

    virtual ~V2TIMAdvancedMsgListener();

    /**
     * Received a new message
     *
     * @param message Message
     */
    virtual void OnRecvNewMessage(const V2TIMMessage &message) {}

    /**
     * C2C peer user conversation read notification（If the peer user calls the MarkC2CMessageAsRead interface, you will receive the callback, and the callback will only carry the peer userID and peer read timestamp information）
     *
     * @param receiptList Read receipt list
     */
    virtual void OnRecvC2CReadReceipt(const V2TIMMessageReceiptVector &receiptList) {}

    /**
     * Notification of message read receipt
     *
     * @param receiptList Read receipt list
     */
    virtual void OnRecvMessageReadReceipts(const V2TIMMessageReceiptVector &receiptList) {}

    /**
     * Received a message recall notification
     *
     * @param messageID Unique ID of a message
     */
    virtual void OnRecvMessageRevoked(const V2TIMString &messageID) {}

    /**
     * Message content modified
     */
    virtual void OnRecvMessageModified(const V2TIMMessage &message) {}

    /**
     * Message extension changed
     */
    virtual void OnRecvMessageExtensionsChanged(const V2TIMString &msgID,
                                                const V2TIMMessageExtensionVector &extensions) {}

    /**
     * Message extension deleted
     */
    virtual void OnRecvMessageExtensionsDeleted(const V2TIMString &msgID,
                                                const V2TIMStringVector &extensionKeys) {}
};

/////////////////////////////////////////////////////////////////////////////////
//
//                      Definition of V2TIMGroupListener
//
/////////////////////////////////////////////////////////////////////////////////

class TIM_API V2TIMGroupListener {
public:
    V2TIMGroupListener();

    virtual ~V2TIMGroupListener();

    /**
     * New members join the group (all members of the group can receive it, and the Meeting group does not have this callback by default. To configure callback for them, please submit a ticket)
     *
     * @param groupID    Group ID
     * @param memberList Members who join the group
     */
    virtual void OnMemberEnter(const V2TIMString &groupID,
                               const V2TIMGroupMemberInfoVector &memberList) {}

    /**
     * A member leaves the group (all members of the group can receive it, and the Meeting group does not have this callback by default. To configure callback for them, please submit a ticket)
     *
     * @param groupID Group ID
     * @param member  Members who leave the group
     */
    virtual void OnMemberLeave(const V2TIMString &groupID, const V2TIMGroupMemberInfo &member) {}

    /**
     * Users are added to a group by others (received by all members of the group)
     *
     * @param groupID    Group ID
     * @param opUser     Handler
     * @param memberList Members who are added to the group
     */
    virtual void OnMemberInvited(const V2TIMString &groupID, const V2TIMGroupMemberInfo &opUser,
                                 const V2TIMGroupMemberInfoVector &memberList) {}

    /**
     * Users are removed from a group by others (received by all members of the group)
     *
     * @param groupID    Group ID
     * @param opUser     Handler
     * @param memberList Members who are removed from the group
     */
    virtual void OnMemberKicked(const V2TIMString &groupID, const V2TIMGroupMemberInfo &opUser,
                                const V2TIMGroupMemberInfoVector &memberList) {}

    /**
     * Group member information modified (received by all members)
     * Meeting group And AVChatRoom group do not have this callback by default. If you need a callback, please go to the [Console](https://console.cloud.tencent.com/im) (Feature Configuration -> Group configuration -> Group system notification configuration -> Notification of group member profile Change) to actively configure.
     *
     * @param groupID Group ID
     * @param v2TIMGroupMemberChangeInfoList  Group member information modified
     */
    virtual void OnMemberInfoChanged(
        const V2TIMString &groupID,
        const V2TIMGroupMemberChangeInfoVector &v2TIMGroupMemberChangeInfoList) {}

    /**
     * Group created (used for multi-device synchronization)
     *
     * @param groupID Group ID
     */
    virtual void OnGroupCreated(const V2TIMString &groupID) {}

    /**
     * Group deleted (received by all members)
     *
     * @param groupID Group ID
     * @param opUser   Handler
     */
    virtual void OnGroupDismissed(const V2TIMString &groupID, const V2TIMGroupMemberInfo &opUser) {}

    /**
     * Group repossessed (received by all members)
     *
     * @param groupID Group ID
     * @param opUser  Handler
     */
    virtual void OnGroupRecycled(const V2TIMString &groupID, const V2TIMGroupMemberInfo &opUser) {}

    /**
     * Group information modified (received by all members)
     *
     * @param changeInfos Group information modified
     */
    virtual void OnGroupInfoChanged(const V2TIMString &groupID,
                                    const V2TIMGroupChangeInfoVector &changeInfos) {}

    /**
     * Received group attribute update（received by all members）
     *
     * @param groupID           Group ID
     * @param groupAttributeMap All attributes of the group
     */
    virtual void OnGroupAttributeChanged(const V2TIMString &groupID,
                                         const V2TIMGroupAttributeMap &groupAttributeMap) {}

    /**
     * Group counter update notification (received by all members).
     *
     * @param groupID  Group ID
     * @param key The key of counter
     * @param newValue The newest value of counter which have been modified
     */
    virtual void OnGroupCounterChanged(const V2TIMString &groupID,
                                       const V2TIMString &key, int64_t newValue) {}

    /**
     * New group joining request (received only by the group owner and admin)
     *
     * @param groupID  Group ID
     * @param member   Applicant
     * @param opReason Request reason
     */
    virtual void OnReceiveJoinApplication(const V2TIMString &groupID,
                                          const V2TIMGroupMemberInfo &member,
                                          const V2TIMString &opReason) {}

    /**
     * Group joining request handled by group owner or admin (received only by the applicant)
     *
     * @param groupID     Group ID
     * @param opUser      Handler
     * @param isAgreeJoin Whether to agree to join the group
     * @param opReason    Handling reason
     */
    virtual void OnApplicationProcessed(const V2TIMString &groupID,
                                        const V2TIMGroupMemberInfo &opUser, bool isAgreeJoin,
                                        const V2TIMString &opReason) {}

    /**
     * Specify the admin identity
     *
     * @param groupID    Group ID
     * @param opUser     Handler
     * @param memberList Group members handled
     */
    virtual void OnGrantAdministrator(const V2TIMString &groupID,
                                      const V2TIMGroupMemberInfo &opUser,
                                      const V2TIMGroupMemberInfoVector &memberList) {}

    /**
     * Cancel the admin identity
     *
     * @param groupID    Group ID
     * @param opUser     Handler
     * @param memberList Group members handled
     */
    virtual void OnRevokeAdministrator(const V2TIMString &groupID,
                                       const V2TIMGroupMemberInfo &opUser,
                                       const V2TIMGroupMemberInfoVector &memberList) {}

    /**
     * Quit a group (mainly used for multi-device synchronization, not supported by audio-video groups)
     *
     * @param groupID Group ID
     */
    virtual void OnQuitFromGroup(const V2TIMString &groupID) {}

    /**
     * Received a custom system message delivered via the RESTful API
     *
     * @param groupID    Group ID
     * @param customData  Custom data
     */
    virtual void OnReceiveRESTCustomData(const V2TIMString &groupID,
                                         const V2TIMBuffer &customData) {}

    /**
     * Topic created
     * @param GroupID group id of Community
     * @param TopicID topic id in Community
     */
    virtual void OnTopicCreated(const V2TIMString &groupID, const V2TIMString &topicID) {}

    /**
     * Topic deleted
     * @param GroupID group id of Community
     * @param TopicIDList topic id list in Community
     */
    virtual void OnTopicDeleted(const V2TIMString &groupID, const V2TIMStringVector &topicIDList) {}

    /**
     * Topic information modified (received by all members)
     * @param groupID Group id of Community
     * @param topicInfo Topic information modified
     */
    virtual void OnTopicChanged(const V2TIMString &groupID, const V2TIMTopicInfo &topicInfo) {}
};

/////////////////////////////////////////////////////////////////////////////////
//
//                  Definition of V2TIMLogListener
//
/////////////////////////////////////////////////////////////////////////////////

class TIM_API V2TIMLogListener {
public:
    V2TIMLogListener();

    virtual ~V2TIMLogListener();

    /**
     * 14.1 Log callback
     *
     * @param logLevel Log Level, see V2TIMLogLevel
     * @param logContent Log content
     */
    virtual void OnLog(V2TIMLogLevel logLevel, const V2TIMString &logContent) {}
};

/////////////////////////////////////////////////////////////////////////////////
//
//                      Definition of V2TIMConversationListener
//
/////////////////////////////////////////////////////////////////////////////////

class TIM_API V2TIMConversationListener {
public:
    V2TIMConversationListener();

    virtual ~V2TIMConversationListener();

    /**
     * When server conversation synchronization starts, the SDK automatically synchronizes server conversations after a successful login or network reconnection. You can monitor such an event and display the event progress on the UI.
    */
    virtual void OnSyncServerStart() {}

    /**
     * When server conversation synchronization is completed, if there are conversation changes, the SDK notifies users of the changes via onNewConversation or onConversationChanged callback.
    */
    virtual void OnSyncServerFinish() {}

    /**
     * Server conversation synchronization failed
    */
    virtual void OnSyncServerFailed() {}

    /**
     * If there is a new conversation (such as receiving a one-to-one chat message from a new colleague or being added to a new group), use "lastMessage -> timestamp" to sort the conversation list again.
    */
    virtual void OnNewConversation(const V2TIMConversationVector &conversationList) {}

    /**
     * If the key information of some conversations changes (for example, the unread count changes, or the last message is updated), use "lastMessage -> timestamp" to sort the conversation list again.
    */
    virtual void OnConversationChanged(const V2TIMConversationVector &conversationList) {}

    /**
     * Notify the changes of the total unread message count of all conversations (supported by 5.3.425 and later versions)
     * @note
     *  - After you call GetTotalUnreadMessageCount to obtain the total number of unread messages for all conversations, the newest value will be notified to you through this callback when unread message count of any conversation changed.
     *  - The total unread message count excludes the unread message count of Do-Not-Disturb conversations (conversations whose message receiving option is V2TIM_NOT_RECEIVE_MESSAGE or V2TIM_RECEIVE_NOT_NOTIFY_MESSAGE).
    */
    virtual void OnTotalUnreadMessageCountChanged(uint64_t totalUnreadCount) {}

    /**
     * Notify the changes of the total unread message count of conversations by filter (supported by 7.0 and later versions)
     * @note
     *  - You can call SubscribeUnreadMessageCountByFilter to listen the changes of total unread message count for conversations by filter, then the SDK will notify you with the latest value through this callback.
     *  - When you subscribe changing notification for total unread message count with multiple conversation filters, you can distinguish which types of conversations's unread messages count has changed by judging the three fields of conversationType, markType, and conversationGroup specified in  the filter parameter.
     *  - The total unread message count excludes the unread message count of Do-Not-Disturb conversations (conversations whose message receiving option is V2TIM_NOT_RECEIVE_MESSAGE or V2TIM_RECEIVE_NOT_NOTIFY_MESSAGE).
     */
    virtual void OnUnreadMessageCountChangedByFilter(const V2TIMConversationListFilter &filter, uint64_t totalUnreadCount) {}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //        Conversation group notification（supported only in 6.5 and later versions）
    //
    /////////////////////////////////////////////////////////////////////////////////
    /**
     * Conversation group has been created.
     */
    virtual void OnConversationGroupCreated(const V2TIMString &groupName,
                                            const V2TIMConversationVector &conversationList) {}

    /**
     * Conversation group has been deleted.
     */
    virtual void OnConversationGroupDeleted(const V2TIMString &groupName) {}

    /**
     * Conversation group name has been chaned.
     */
    virtual void OnConversationGroupNameChanged(const V2TIMString &oldName, const V2TIMString &newName) {}

    /**
     * New conversations have been added to this conversation group.
     */
    virtual void OnConversationsAddedToGroup(const V2TIMString &groupName,
                                             const V2TIMConversationVector &conversationList) {}

    /**
     * Conversations have been deleted from this conversation group.
     */
    virtual void OnConversationsDeletedFromGroup(const V2TIMString &groupName,
                                                 const V2TIMConversationVector &conversationList) {}
};

/////////////////////////////////////////////////////////////////////////////////
//
//                      Definition of V2TIMFriendshipListener
//
/////////////////////////////////////////////////////////////////////////////////

class TIM_API V2TIMFriendshipListener {
public:
    V2TIMFriendshipListener();

    virtual ~V2TIMFriendshipListener();

    /**
     *  New friend request notification. You will receive this callback in the following cases:
     *  1. You send a friend request to others.
     *  2. You receive a friend request from others.
     */
    virtual void OnFriendApplicationListAdded(const V2TIMFriendApplicationVector &applicationList) {}

    /**
     *  Friend request deletion notification. You will receive this callback in the following cases:
     *  1. You call deleteFriendApplication to proactively delete a friend request.
     *  2. You call refuseFriendApplication to reject a friend request.
     *  3. You call acceptFriendApplication to accept a friend request and the acceptance type is V2TIM_FRIEND_ACCEPT_AGREE.
     *  4. Your friend request is rejected by others.
     */
    virtual void OnFriendApplicationListDeleted(const V2TIMStringVector &userIDList) {}

    /**
     *  Friend request read notification. When you call setFriendApplicationRead to set the friend request list as read, you will receive this callback (mainly used for multi-device synchronization).
     */
    virtual void OnFriendApplicationListRead() {}

    /**
     *  New friend notification
     */
    virtual void OnFriendListAdded(const V2TIMFriendInfoVector &userIDList) {}

    /**
     *  Friend deletion notification. You will receive this callback in the following cases:
     *  1. You delete a friend (received for one-way or two-way friend deletion).
     *  2. You are deleted by a friend (received for two-way friend deletion).
     */
    virtual void OnFriendListDeleted(const V2TIMStringVector &userIDList) {}

    /**
     *  New blocklist notification
     */
    virtual void OnBlackListAdded(const V2TIMFriendInfoVector &infoList) {}

    /**
     *  Blocklist deletion notification
     */
    virtual void OnBlackListDeleted(const V2TIMStringVector &userIDList) {}

    /**
     *  Friend profile update notification
     */
    virtual void OnFriendInfoChanged(const V2TIMFriendInfoVector &infoList) {}
};

/////////////////////////////////////////////////////////////////////////////////
//
//                      Definition of V2TIMSignalingListener
//
/////////////////////////////////////////////////////////////////////////////////

class TIM_API V2TIMSignalingListener {
public:
    V2TIMSignalingListener();

    virtual ~V2TIMSignalingListener();

    /**
     * Received an invitation
     */
    virtual void OnReceiveNewInvitation(const V2TIMString &inviteID, const V2TIMString &inviter,
                                        const V2TIMString &groupID, const V2TIMStringVector &inviteeList,
                                        const V2TIMString &data) {}

    /**
     * The invitee accepted the invitation
     */
    virtual void OnInviteeAccepted(const V2TIMString &inviteID, const V2TIMString &invitee,
                                   const V2TIMString &data) {}

    /**
     * The invitee declined the invitation
     */
    virtual void OnInviteeRejected(const V2TIMString &inviteID, const V2TIMString &invitee,
                                   const V2TIMString &data) {}

    /**
     * he invitation was canceled
     */
    virtual void OnInvitationCancelled(const V2TIMString &inviteID, const V2TIMString &inviter,
                                       const V2TIMString &data) {}

    /**
     * The invitation timed out
     */
    virtual void OnInvitationTimeout(const V2TIMString &inviteID,
                                     const V2TIMStringVector &inviteeList) {}

    /**
     * The invitation was modified (supported only in 6.7 and later versions)
     */
    virtual void OnInvitationModified(const V2TIMString &inviteID, const V2TIMString &data) {}
};

#endif /* __V2TIM_LISTENER_H__ */
