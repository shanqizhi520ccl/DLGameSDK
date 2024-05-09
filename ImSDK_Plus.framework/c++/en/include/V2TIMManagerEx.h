// Copyright (c) 2021 Tencent. All rights reserved.

/////////////////////////////////////////////////////////////////////////////////
//
//       Core class of the IM SDK, implementing features such as IM SDK initialization and login, message sending and receiving, and group creation and quitting
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef __V2TIM_MANAGER_H__
#define __V2TIM_MANAGER_H__

#include "V2TIMCallback.h"
#include "V2TIMCommon.h"
#include "V2TIMFriendship.h"
#include "V2TIMGroup.h"
#include "V2TIMListener.h"
#include "V2TIMMessage.h"

class V2TIMMessageManager;
class V2TIMGroupManager;
class V2TIMConversationManager;
class V2TIMFriendshipManager;
class V2TIMOfflinePushManager;
class V2TIMSignalingManager;

class TIM_API V2TIMManager {
public:
    virtual ~V2TIMManager() {}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                               Initialization
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 1.1 Get the V2TIMManager instance
     */
    static V2TIMManager *GetInstance();

    /**
     * 1.2 Add IM listener
     */
    virtual void AddSDKListener(V2TIMSDKListener *listener) = 0;

    /**
     * 1.3 Remove IM listener
     */
    virtual void RemoveSDKListener(V2TIMSDKListener* listener) = 0;

    /**
     * 1.4 Initialize the SDK.
     *
     * It is deprecated and discouraged to call this function. Please call APIs ref initSDK defined in 1.2 and addIMSDKListener defined in 1.3 instead.
     */
    virtual bool InitSDK(uint32_t sdkAppID, const V2TIMSDKConfig &config) = 0;

    /**
     * 1.5 Uninitialize the SDK
     *
     */
    virtual void UnInitSDK() = 0;

    /**
     * 1.6 Get the SDK version
     * @return Return the SDK version in string format, for example: 5.0.10
     */
    virtual V2TIMString GetVersion() = 0;

    /**
     *  1.7 Get the server time
     *  @return Server time, in seconds
     */
    virtual int64_t GetServerTime() = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                               Login and logout
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 2.1 Login
     *
     * userID and userSig must be set for login. For the generation of userSig, please see [UserSig backend API](https://cloud.tencent.com/document/product/269/32688)。
     *
     *  @note Note the following special logic:
     *  - The ticket expires before login: the callback of the login function returns the error ERR_USER_SIG_EXPIRED (6206) or ERR_SVR_ACCOUNT_USERSIG_EXPIRED (70001), and the user needs to generate a new userSig and log in again.
     *  - The ticket expires when the user is online: the user can receive the V2TIMListener -> onUserSigExpired callback when online, and the user also needs to generate a new userSig and log in again.
     *  - An online user is kicked offline: the SDK notifies the user of the logout via the V2TIMListener -> onKickedOffline callback and displays the logout notification on the UI, and the user can call login() to log in again.
     */
    virtual void Login(const V2TIMString &userID, const V2TIMString &userSig,
                       V2TIMCallback *callback) = 0;

    /**
     *
     *  2.2 Logout
     *
     *  If the user logs out and switches the account, the user can log in again after the logout function calls back success or failure. Otherwise, login may fail.
     */
    virtual void Logout(V2TIMCallback *callback) = 0;

    /**
     * 2.3 Get the login user
     */
    virtual V2TIMString GetLoginUser() = 0;

    /**
     * 2.4 Get the login status
     *
     *  If the user is already in the "logged in" or "logging in" state, do not frequently call the login API to log in.
     *
     * @return login status
     */
    virtual V2TIMLoginStatus GetLoginStatus() = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                         Message receiving/sending
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 3.1 Set the event listener for simple messages (text messages and custom messages)
     *
     * @note For the event listener for advanced messages such as image, video, and voice messages, please see @ref V2TIMMessageManager.addAdvancedMsgListener(V2TIMAdvancedMsgListener).
     *
     */
    virtual void AddSimpleMsgListener(V2TIMSimpleMsgListener *listener) = 0;

    /**
     * 3.2 Remove the event listener for simple messages (text messages and custom messages)
     */
    virtual void RemoveSimpleMsgListener(V2TIMSimpleMsgListener *listener) = 0;

    /**
     * 3.3 Send a one-to-one text message (up to 12 KB)
     *
     *  Text messages support sensitive word filtering on the cloud. For example, if a text message sent by a user contains sensitive words, the callback will return the 80001 error code.
     *
     * @return Unique ID of the message
     */
    virtual V2TIMString SendC2CTextMessage(const V2TIMString &text, const V2TIMString &userID,
                                           V2TIMSendCallback *callback) = 0;

    /**
     *  3.4 Send a one-to-one custom (signaling) message (up to 12 KB)
     *
     *  A custom message is essentially a binary buffer on which you can freely organize your message format (often used to send signaling). However, custom messages do not support sensitive word filtering on the cloud.
     *
     * @return Unique ID of the message
     * @note Messages sent via this API are not pushed by default. To push the messages, call the @ref V2TIMMessageManager::SendMessage API.
     */
    virtual V2TIMString SendC2CCustomMessage(const V2TIMBuffer &customData,
                                             const V2TIMString &userID,
                                             V2TIMSendCallback *callback) = 0;

    /**
     *  3.5 Send a group text message (up to 12 KB)
     *
     *  @param priority Message priority. Though there is no way for all messages to 100% reach every user, higher-priority messages will have a higher delivery success rate.
     *      - HIGH ：the message will be transferred with high priority on the cloud. This setting is suitable for sending important messages in the group, such as text messages sent by host.
     *      - NORMAL ：the message will be transferred with the default priority on the cloud. This setting is suitable for sending unimportant messages in the group, such as on-screen comments sent by viewers.
     *  @return Unique ID of the message
     */
    virtual V2TIMString SendGroupTextMessage(const V2TIMString &text, const V2TIMString &groupID,
                                             V2TIMMessagePriority priority,
                                             V2TIMSendCallback *callback) = 0;

    /**
     *  3.6 Send a group custom (signaling) message (up to 12 KB)
     *
     * @param priority Message priority. Though there is no way for all messages to 100% reach every user, higher-priority messages will have a higher delivery success rate.
     *      - HIGH ：the message will be transferred with high priority on the cloud. This setting is suitable for sending important messages in the group, such as mic connect invitations, competition invitation, gift-giving, and other key signaling.
     *      - NORMAL ：the message will be transferred with the default priority on the cloud. This setting is suitable for sending unimportant signaling in the group, such as audience's like notifications.
     * @return Unique ID of the message
     * @note Messages sent via this API are not pushed by default. To push the messages, call the @ref V2TIMMessageManager::SendMessage API.
     */
    virtual V2TIMString SendGroupCustomMessage(const V2TIMBuffer &customData,
                                               const V2TIMString &groupID,
                                               V2TIMMessagePriority priority,
                                               V2TIMSendCallback *callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                        Group operations
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 4.1 Add the group listener
     */
    virtual void AddGroupListener(V2TIMGroupListener *listener) = 0;

    /**
     * 4.2 Remove the group listener
     */
    virtual void RemoveGroupListener(V2TIMGroupListener *listener) = 0;

    /**
     * 4.3 Create a group
     *
     * @param groupType
     * @param groupType Group type. The following several common group types are preset in the SDK. You can also customize desired group types in the console:
     *  - Work group (Work): supports up to 200 members; does not allow proactive group joining and only allows users to be invited to join the group by group members; suitable for groups like work groups created in WeChat (corresponding to Private groups in the earlier version)
     *  - Public group (Public): supports up to 2,000 members; allows anyone to apply to join the group, but requires group owner or admin approval for group joining; suitable for groups like interest groups managed by group owners in QQ
     *  - Meeting group (Meeting): supports up to 6,000 members; allows anyone to join and leave the group freely, without approval; suitable for scenarios such as video conference and online training (corresponding to ChatRoom groups in the earlier version)
     *  - Community : supports up to 100,000 members; allows anyone to join and leave the group freely, without approval; suitable for large community group chat scenarios such as knowledge sharing and game communication. supported only in 5.8 and later versions, need to buy Flagship Edition.
     *  - Audio-video group (AVChatRoom): supports an unlimited number of members; allows anyone to join and leave the group freely; features high message throughput and is suitable for use as a chat room with high-concurrency on-screen comments in live streaming scenarios
     *
     * @param groupID Custom group ID. "null" can be passed in. When "null" is passed in, the system automatically assigns a group ID and calls back the group ID via callback.
     *                Custom group ID of "Community" must be prefixed with "@TGS#_".
     * @param groupName Group name. The value cannot be "null" and can contain up to 30 bytes.
     *
     *  @note Note the following special logic:
     *  - Do not create groups with the same group ID under the same SDKAppID.
     *  - Audio-video group (AVChatRoom): After the process is restarted or logged in again, if you want to continue to receive messages from the Audio-video group, please call JoinGroup to rejoin the Audio-video group.
     */
    virtual void CreateGroup(const V2TIMString &groupType, const V2TIMString &groupID,
                             const V2TIMString &groupName,
                             V2TIMValueCallback<V2TIMString> *callback) = 0;

    /**
     *  4.4 Join a group
     *
     *  @note Note the following special logic:
     *  - Work group (Work): users cannot proactively join a Work group. Only group members can call the V2TIMGroupManager::InviteUserToGroup API to invite users to join the group.
     *  - Public group (Public): admin approval is required for users to join a Public group. When receiving the V2TIMGroupListener -> onReceiveJoinApplication callback, the admin needs to call the  V2TIMGroupListener::OnReceiveJoinApplication API to handle group joining requests.
     *  - Other groups: users can directly join such groups.
     *  - Audio-video group (AVChatRoom): After the process is restarted or logged in again, if you want to continue to receive messages from the Audio-video group, please call JoinGroup to rejoin the Audio-video group.
     */
    virtual void JoinGroup(const V2TIMString &groupID, const V2TIMString &message,
                           V2TIMCallback *callback) = 0;

    /**
     * 4.5 Quit a group
     *
     * @note For public groups (Public), meeting groups (Meeting), and audio-video groups (AVChatRoom), the group owner cannot quit the group and can only call DismissGroup to delete the group.
     */
    virtual void QuitGroup(const V2TIMString &groupID, V2TIMCallback *callback) = 0;

    /**
     * 4.6 Delete a group
     * @note Note the following special logic:
     *  - For a work group (Work), even the group owner does not have the privilege to delete the group. To delete the group, you must have your service server to call the RESTful API [Deleting a Group](https://cloud.tencent.com/document/product/269/1624) to delete the group.
     *  - For other group types, the group owner can delete the group.
     */
    virtual void DismissGroup(const V2TIMString &groupID, V2TIMCallback *callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                       Profile-related operations
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 5.1 Get user profiles
     *
     *  @note Notes:
     *   - To get your own profile, pass in your user ID.
     *   - You are advised to specify no more than 100 user IDs in userIDList at a time. A larger number may cause the request to be rejected by the backend due to an excessively large data packet. The maximum size of a data packet supported by the backend is 1 MB.
     */
    virtual void GetUsersInfo(const V2TIMStringVector &userIDList,
                              V2TIMValueCallback<V2TIMUserFullInfoVector> *callback) = 0;

    /**
     * 5.2  Modify one's own user profile
     */
    virtual void SetSelfInfo(const V2TIMUserFullInfo &info, V2TIMCallback *callback) = 0;

    /**
     *  5.3 Get user status information(supported only in 6.3 and later versions)
     *
     *  @param userIDList List of identifier of the users whose information is to be obtained.
     *
     *  @note ：
     *  - Passed yourself id to @userIDList, your custom status would be returned.
     *  - Only when all user's status obtained fail, @fail would be invoke.
     */
    virtual void GetUserStatus(const V2TIMStringVector &userIDList,
                               V2TIMValueCallback<V2TIMUserStatusVector> *callback) = 0;

    /**
     *  5.4 Setup user status for yourself (supported only in 6.3 and later versions)
     *
     *
     *  @note Only the customStatus field of V2TIMUserStatus can be set for yourself.
     */
    virtual void SetSelfStatus(const V2TIMUserStatus &status, V2TIMCallback *callback) = 0;

    /**
     *  5.5 Subscribe user status (supported only in 6.3 and later versions)
     *
     *  @param userIDList Identifiers for users whose status will be subscribed.
     *
     *  @note:
     *   - You will receive the status change notification by implement the onUserStatusChanged callback after succeffully subscribe user status.
     *   - You can subscribe status of your friends by open the switch at console without call this API.
     *   - Status subscription of yourself is not supported. You can implement the onUserStatusChanged callback to obtain the status change notification for yourself which has been set on other devices.
     *   - There is a limit on the number of subscription list. The older subscriber will be automatically eliminated after exceeding the limit.
     */
    virtual void SubscribeUserStatus(const V2TIMStringVector &userIDList, V2TIMCallback *callback) = 0;

    /**
     *  5.6 Unsubscribe user status (supported only in 6.3 and later versions)
     *
     *  @param userIDList Identifiers for users whose status will be unsubscribed. If useridList is empty, status of all users will be unsubscribed.
     */
    virtual void UnsubscribeUserStatus(const V2TIMStringVector &userIDList, V2TIMCallback *callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                         Advanced features
    //
    /////////////////////////////////////////////////////////////////////////////////

     /**
     * ## Advanced message feature entry
     *
     * @return Advanced message management class instance
     */
    virtual V2TIMMessageManager *GetMessageManager() = 0;

    /**
     * ## Advanced group feature entry
     *
     * @return Advanced group management class instance
     */
    virtual V2TIMGroupManager *GetGroupManager() = 0;

    /**
     * ## Conversation feature entry
     *
     * @return Conversation management class instance
     */
    virtual V2TIMConversationManager *GetConversationManager() = 0;

    /**
     * ## Relationship chain feature entry
     *
     * @return Relationship chain management class instance
     */
    virtual V2TIMFriendshipManager *GetFriendshipManager() = 0;

    /**
     * ## Offline push feature entry
     *
     * @return Offline push feature class instance
     */
    virtual V2TIMOfflinePushManager *GetOfflinePushManager() = 0;

    /**
     * ## Signaling feature entry
     *
     * @return Signaling management class instance
     */
    virtual V2TIMSignalingManager *GetSignalingManager() = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                        Extension function
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * Experimental API
     *
     * @param api API name
     * @param param API parameter
     *
     * @note This API provides some experimental features.
     */
    virtual void CallExperimentalAPI(const V2TIMString &api, const void *param,
                                     V2TIMValueCallback<V2TIMBaseObject> *callback) = 0;
};

#endif  // __V2TIM_MANAGER_H__
