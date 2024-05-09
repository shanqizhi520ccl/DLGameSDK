// Copyright (c) 2021 Tencent. All rights reserved.

/////////////////////////////////////////////////////////////////////
//
//                     Tencent Cloud Instant Messaging SDK
//
//  Advanced message APIs, including the APIs for message creation, sending and receiving logic
//
/////////////////////////////////////////////////////////////////////

#ifndef __V2TIM_MESSAGE_MANAGER_H__
#define __V2TIM_MESSAGE_MANAGER_H__

#include "V2TIMCallback.h"
#include "V2TIMDefine.h"
#include "V2TIMListener.h"
#include "V2TIMMessage.h"

class V2TIMMessageManager {
public:
    virtual ~V2TIMMessageManager() {}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //   Listen for advanced messages (including image, voice, and video messages)
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     *  1.1 Add an event listener for advanced messages
     */
    virtual void AddAdvancedMsgListener(V2TIMAdvancedMsgListener *listener) = 0;

    /**
     *  1.2 Remove the event listener for advanced messages
     */
    virtual void RemoveAdvancedMsgListener(V2TIMAdvancedMsgListener *listener) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //     Create advanced messages (including image, voice, and video messages)
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     *  2.1 Create a text message
     */
    virtual V2TIMMessage CreateTextMessage(const V2TIMString &text) = 0;

    /**
     *  2.2 Create a text message with the @ notification feature（This interface is deprecated, recommended to use the CreateAtSignedGroupMessage interface）
     *
     *  Notification messages are only applicable to messages sent in the group.
     *
     *  @param atUserList List of @ target users. To @all, please pass in the kImSDK_MesssageAtALL constant string.
     *  For example, if you want the current text message to @denny, @lucy, and @all, pass in ["denny","lucy",kImSDK_MesssageAtALL] for atUserList.
     *
     *  @note The following are use limits for atUserList:
     *  - The maximum number of @ target users is 30 by default. If this limit is exceeded, message sending will fail.
     *  - The total number of users specified by atUserList cannot exceed the default maximum number, including the case of @all.
     *  - AVChatRoom do not support sending @ messages.
     */
    virtual V2TIMMessage CreateTextAtMessage(const V2TIMString &text,
                                             const V2TIMStringVector &atUserList) = 0;

    /**
     *  2.3 Create a custom message
     */
    virtual V2TIMMessage CreateCustomMessage(const V2TIMBuffer &data) = 0;

    /**
     *  2.4 Create a custom message and set offline push information
     *
     * @param description Custom message description information to be displayed in text during offline push
     * @param extension Extension field information during offline push
     */
    virtual V2TIMMessage CreateCustomMessage(const V2TIMBuffer &data,
                                             const V2TIMString &description,
                                             const V2TIMString &extension) = 0;

    /**
     *  2.5 Create an image message (image size limit: 28 MB)
     */
    virtual V2TIMMessage CreateImageMessage(const V2TIMString &imagePath) = 0;

    /**
     *  2.6 Create a voice message (voice size limit: 28 MB)
     *
     * @param duration  Voice duration, in seconds
     */
    virtual V2TIMMessage CreateSoundMessage(const V2TIMString &soundPath, uint32_t duration) = 0;

    /**
     *  2.7 Create a video message (video size limit: 100 MB)
     *
     * @param type             Video type, such as mp4 and mov
     * @param duration         Video duration, in seconds
     * @param snapshotPath     Video cover image path
     */
    virtual V2TIMMessage CreateVideoMessage(const V2TIMString &videoFilePath,
                                            const V2TIMString &type, uint32_t duration,
                                            const V2TIMString &snapshotPath) = 0;

    /**
     *  2.8 Create a file message (file size limit: 100 MB)
     */
    virtual V2TIMMessage CreateFileMessage(const V2TIMString &filePath,
                                           const V2TIMString &fileName) = 0;

    /**
     *  2.9 Create a location message
     */
    virtual V2TIMMessage CreateLocationMessage(const V2TIMString &desc, double longitude,
                                               double latitude) = 0;

    /**
     *  2.10 Create an emoji message
     *
     *  The IM SDK does not provide an emoji package. Developers can use index to store the indexes of the emojis they have in their emoji packages. Alternatively, they can directly use data to store emoji binary data and the string key. Either way, developers can customize emojis. The IM SDK is only responsible for passing them through.
     *
     * @param index Emoji index
     * @param data  Custom data
     */
    virtual V2TIMMessage CreateFaceMessage(uint32_t index, const V2TIMBuffer &data) = 0;

    /**
     *  2.11 Create a combined message (supported only in 5.2.210 and later versions)
     *
     * <p> Usually when we receive a combined message, the chat screen will look like this:
     * <p> |Chat History of Vinson and Lynx                       |        -- title (Title)
     * <p> |Vinson: When is the new version of SDK scheduled to go online?            |        -- abstract1 (Digest information 1)
     * <p> |Lynx: Next Monday. The specific time depends on the system test result in these two days. |        -- abstract2 (Digest information 2)
     * <p> |Vinson: OK                               |        -- abstract3 (Digest information 3)
     * <p> The chat UI usually displays only the title and digest information of the combined message, and the complete combined message list will be displayed only when the user clicks the combined message on the UI.
     *
     * <p> You can create a combined message (V2TIMMessage) for multiple messages to be forwarded and call the sendMessage API to send the combined message. The procedure is as follows:
     * <p> 1. Call createMergerMessage to create a combined message V2TIMMessage.
     * <p> 2. Call sendMessage to send the forward message V2TIMMessage.
     *
     * <p> The procedure for parsing a combined message received is as follows:
     * <p> 1. Obtain mergerElem via V2TIMMessage.
     * <p> 2. Obtain title and abstractList via mergerElem for UI display.
     * <p> 3. When a user clicks the digest information on the UI, call downloadMessageList to get the list of forwarded messages.
     *
     *
     * @param messageList Message list (Up to 300 messages are supported. The message object must be in the V2TIM_MSG_STATUS_SEND_SUCC status. The message type cannot be V2TIMGroupTipsElem.)
     * @param title Source of the combined message, for example, "Chat History of Vinson and Lynx" and "xxx group chat history"
     * @param abstractList Combined message digest list (supports up to 5 digests, each containing a maximum of 100 characters) You can set digest information in different formats for different message types, for example:
     *                      For a text message, the digest can be in the "sender:text" format. For an image message, the digest can be in the "sender:[image]" format. For a file message, the digest can be in the "sender:[file]" format.
     * @param compatibleText Combined messages are compatible with text. SDKs of early versions do not support combined messages, and they will send a text message with the content compatibleText by default. The parameter cannot be empty string.
     */
    virtual V2TIMMessage CreateMergerMessage(const V2TIMMessageVector &messageList,
                                             const V2TIMString &title,
                                             const V2TIMStringVector &abstractList,
                                             const V2TIMString &compatibleText) = 0;

    /**
     *  2.12 Create a forward message (supported only in 5.2.210 and later versions)
     *
     *  If you need to forward a message, you cannot directly call the sendMessage API to send the original message. Instead, you need to call createForwardMessage to create a forward message first and send it.
     *
     *  @param message Message object to be forwarded. The message status must be V2TIM_MSG_STATUS_SEND_SUCC. The message type cannot be V2TIMGroupTipsElem.
     *  @return Forward message object. The elem content is the same as the original message.
     */
    virtual V2TIMMessage CreateForwardMessage(const V2TIMMessage &message) = 0;

    /**
     *  2.13 Create a targeted group message（supported only in 6.0 and later versions）
     *
     *  If you need to send a message to a specified group member list within a group, you can create a targeted group message. Only the specified group member can receive the targeted group message.
     *
     *  @param message Original message object
     *  @param receiverList Message receivers
     *  @return Targeted group message object
     *
     * @note Please note：
     * - The original message object does not support group @ message.
     * - The message receiver list supports up to 50.
     * - The targeted group message cannot be sent in community group and avchatroom group.
     * - The targeted group message will not be counted into the count of unread message for a group conversation.
     */
    virtual V2TIMMessage CreateTargetedGroupMessage(const V2TIMMessage &message, const V2TIMStringVector &receiverList) = 0;
    
    /**
     *  2.14 Create a @ signed group message（supported only in 7.0 and later versions）
     *
     *  If you need to send a group message with @ notification feature, you can create a @ signed group message.
     *
     *  @param message Original message object
     *  @param atUserList List of @ target users. To @all, please pass in the kImSDK_MesssageAtALL constant string.
     *  For example, if you want the current message to @denny, @lucy, and @all, pass in @[@"denny", @"lucy", kImSDK_MesssageAtALL] for atUserList.
     *  @return Group @ message object
     *
     *  @note The following are use limits for atUserList:
     *  - The maximum number of @ target users is 30 by default. If this limit is exceeded, message sending will fail.
     *  - The total number of users specified by atUserList cannot exceed the default maximum number, including the case of @all.
     *  - AVChatRoom do not support sending @ messages.
     */
    virtual V2TIMMessage CreateAtSignedGroupMessage(const V2TIMMessage &message, const V2TIMStringVector &atUserList) = 0;


    /////////////////////////////////////////////////////////////////////////////////
    //
    //      Send advanced messages (including image, voice, and video messages)
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     *  3.1 Send an advanced message (advanced version: provides the features of specifying message priorities and push information)
     *
     * @param message           Message object to be sent, which needs to be created via the corresponding message creation API
     * @param receiver          Message recipient's userID. For a one-to-one message, you only need to specify this field.
     * @param groupID           Target group ID For a group chat message, you only need to specify this field.
     * @param priority          Message priorities. This field is valid only for group chat messages. You are advised to set higher priorities for important messages (such as red packet and gift messages) and set lower priorities for frequent but unimportant messages (such as like messages).
     * @param onlineUserOnly    Whether the message can be received only by online users. If this field is set to true, the message cannot be pulled in recipient historical message pulling. This field is often used to implement weak notification features such as "The other party is typing" or unimportant notifications in the group. This field is not supported by audio-video groups (AVChatRoom).
     * @param offlinePushInfo   Title and voice carried when the message pushing offline.
     * @return Unique ID of the message
     * @note
     *  - Targeted group messages are supported in version 6.0 and later.  If groupID and receiver are set at the same time, the message will be sent to the specified receiver in the group. If you want to send message to multiple receivers in a group, you need to call CreateTargetedGroupMessage API to create a targeted group message with multiple receivers before sending.
     *  - Before setting the offlinePushInfo field, you need to enable push via V2TIMOfflinePushManager. After push is enabled, all messages except custom messages will be pushed by default.
     *  - If you want to push custom messages as well, set the desc field in offlinePushInfo so that the information specified by desc will be displayed by default during push.
     *  - Audio-video groups (AVChatRoom) do not support the onlineUserOnly field. You need to set onlineUserOnly to false for audio-video groups (AVChatRoom).
     *  - If onlineUserOnly is set to true, the message is an online message and is not counted as an unread message.
     */
    virtual V2TIMString SendMessage(V2TIMMessage &message, const V2TIMString &receiver,
                                    const V2TIMString &groupID, V2TIMMessagePriority priority,
                                    bool onlineUserOnly,
                                    const V2TIMOfflinePushInfo &offlinePushInfo,
                                    V2TIMSendCallback *callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    // Set the message receiving option (Receive | Receive but not notify | Not receive)
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     *  4.1 Set the one-to-one message receiving option for specified users (batch setting supported)
     * <p>Supported only in 5.3.425 and later versions.
     *
     *  @note Notes:
     *  - This API supports batch setting. You can use the userIDList field to specify up to 30 users for batch setting.
     *  - This API can be called for up to 5 times per second.
     *
     *
     *  @param opt    There are three message receiving options:
     *                V2TIMMessage.V2TIM_RECEIVE_MESSAGE: messages will be received when the user is online, and push notifications will be received when the user is offline.
     *                V2TIMMessage.V2TIM_NOT_RECEIVE_MESSAGE: no message will be received.
     *                V2TIMMessage.V2TIM_RECEIVE_NOT_NOTIFY_MESSAGE: messages will be received when the user is online, and no push notification will be received when the user is offline.
     *
     */
    virtual void SetC2CReceiveMessageOpt(const V2TIMStringVector &userIDList,
                                         V2TIMReceiveMessageOpt opt, V2TIMCallback *callback) = 0;

    /**
     *  4.2 Query the one-to-one message receiving option for specified users
     *  <p>Supported only in 5.3.425 and later versions.
     */
    virtual void GetC2CReceiveMessageOpt(
        const V2TIMStringVector &userIDList,
        V2TIMValueCallback<V2TIMReceiveMessageOptInfoVector> *callback) = 0;

    /**
     *  4.3 Set the group message receiving option
     */
    virtual void SetGroupReceiveMessageOpt(const V2TIMString &groupID, V2TIMReceiveMessageOpt opt,
                                           V2TIMCallback *callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    // Advanced APIs for getting historical messages, recalling messages, deleting messages, and marking messages as read
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 5.1 Get historical messages (advanced API)
     *
     * @param option   Message pulling option, which can be set to pull older or newer messages from local storage or the cloud
     *
     * @note Notes:
     * - If option is set to pull messages from the cloud, and the IM SDK detects that the network connection is unavailable, the IM SDK directly returns local data.
     * - Only meeting groups (Meeting) support pulling historical messages of members before they join the groups. For audio-video groups (AVChatRoom), messages are not saved to the roaming and local databases, and therefore this API does not take effect.
     */
    virtual void GetHistoryMessageList(const V2TIMMessageListGetOption &option,
                                       V2TIMValueCallback<V2TIMMessageVector> *callback) = 0;

    /**
     * 5.2 Recall messages
     *
     * @note Notes:
     *  - By default, you can recall only messages that are sent within 2 minutes. You can customize the time limit for message recall via the [console](https://console.cloud.tencent.com/im) (Feature Configuration -> Login and Message -> Message Recall Settings).
     *  - Only common messages sent in one-to-one chats and group chats can be recalled. Messages that can be received only by online users (onlineUserOnly is set to true) and audio-video group (AVChatRoom) messages cannot be recalled.
     *  - If the sender recalls a message, the recipient will receive the V2TIMAdvancedMsgListener::OnRecvMessageRevoked callback.
     */
    virtual void RevokeMessage(const V2TIMMessage &message, V2TIMCallback *callback) = 0;

    /**
     *  5.3 Modify message
     * 
     *  @note Notes：
     *  - If the message is modified successfully, both the user and the peer user (C2C) or group member (Group) will receive the onRecvMessageModified callback.
     *  - If the message has been modified by others during the process of modifying the message, the completion will return ERR_SDK_MSG_MODIFY_CONFLICT error.
     *  - Completion returns the latest message object regardless of whether the message is modified successfully or failed.
     */
    virtual void ModifyMessage(const V2TIMMessage &message, V2TIMCompleteCallback<V2TIMMessage> *callback) = 0;

    /**
     * 5.4 Mark one-to-one messages as read
     *
     * @note Notes:
     *  - After the API is successfully called, your unread count will be cleared to 0, and the peer user will receive the OnRecvC2CReadReceipt callback, which will carry the time marked conversation read.
     *  - If the userID is nil, all one-to-one messages wil be marked as read. More importantly, it only supported in 5.8 and later versions.
     */
    virtual void MarkC2CMessageAsRead(const V2TIMString &userID, V2TIMCallback *callback) = 0;

    /**
     * 5.5 Mark group messages as read
     *
     *  @note Notes:
     *  - After the API is successfully called, your unread count will be cleared to 0.
     *  - If the groupID is nil, all group messages wil be marked as read. More importantly, it only supported in 5.8 and later versions.
     */
    virtual void MarkGroupMessageAsRead(const V2TIMString &groupID, V2TIMCallback *callback) = 0;

    /**
     * 5.6 Mark all messages as read（Supported only in 5.8 and later versions）
     */
    virtual void MarkAllMessageAsRead(V2TIMCallback *callback) = 0;

    /**
     *  5.7 Delete a message from local storage
     *
     * @note Messages can only be deleted locally. After a message is deleted, the SDK marks the message as deleted locally, and the message can no longer be pulled via getHistoryMessage.
     * However, after the app is uninstalled and reinstalled, the local delete marker of the message will get lost, and the message can still be pulled via getHistoryMessage.
     */
    virtual void DeleteMessages(const V2TIMMessageVector &messages, V2TIMCallback *callback) = 0;

    /**
     * 5.8 Delete messages from local storage and the cloud
     * 
     *  @note In addition to deleting messages from the local storage (deleteMessageFromLocalStorage), this API simultaneously deletes messages from the cloud, and the deleted messages cannot be recovered. Please note that:
     *  - Up to 30 messages can be deleted at a time.
     *  - The messages to be deleted at a time must belong to the same conversation.
     *  - This API can be called only once per second.
     *  - If the account has pulled these messages from other devices, the messages will still be stored on those devices after this API is called to delete them. That is, the operation of message deletion cannot be synchronized across multiple devices.
     */
    virtual void ClearC2CHistoryMessage(const V2TIMString &userID, V2TIMCallback *callback) = 0;

    /**
     * 5.9 Clear chat history with a user from local storage and the cloud (without deleting the conversation)
     * <p> Supported only in 5.4.666 and later versions.
     *
     * @note Notes:
     * - When messages in a conversation are deleted from local storage, they are deleted simultaneously from the server.
     *
     */
    virtual void ClearGroupHistoryMessage(const V2TIMString &groupID, V2TIMCallback *callback) = 0;

    /**
     * 5.10 Add a message to the group message list
     *
     * This API is mainly used to meet the requirement of inserting informative messages, such as "you have exited the group", into a group chat conversation. Such messages need to be displayed in the chat interface but do not need to be sent to others.
     * Messages that need to be displayed in the chat interface but do not need to be sent to others.
     * Therefore, insertGroupMessageToLocalStorage() is equivalent to a sendMessage() API whose network sending capability is disabled.
     *
     * @return msgID   Unique ID of a message
     *
     * @note Messages saved via this API are saved only to the local storage and will get lost after the app is uninstalled.
     */
    virtual V2TIMString InsertGroupMessageToLocalStorage(
        V2TIMMessage &message, const V2TIMString &groupID, const V2TIMString &sender,
        V2TIMValueCallback<V2TIMMessage> *callback) = 0;

    /**
     *  5.11 Insert a message in a one-to-one chat
     *
     *  This API is mainly used to meet the requirement of inserting informative messages, such as "you have exited the group", into a one-to-one chat conversation. Such messages need to be displayed in the chat interface but do not need to be sent to the peer party.
     *  Messages that need to be displayed in the chat interface but do not need to be sent to others.
     *  Therefore, insertC2CMessageToLocalStorage() is equivalent to a sendMessage() API whose network sending capability is disabled.
     *
     *  @return msgID   Unique ID of a message
     *  @note Messages saved via this API are saved only to the local storage and will get lost after the app is uninstalled.
     */
    virtual V2TIMString InsertC2CMessageToLocalStorage(
        V2TIMMessage &message, const V2TIMString &userID, const V2TIMString &sender,
        V2TIMValueCallback<V2TIMMessage> *callback) = 0;

    /**
     * 5.12 Query local messages in a specified conversation by messageID
     * @param messageIDList  Message ID list
     */
    virtual void FindMessages(const V2TIMStringVector &messageIDList,
                              V2TIMValueCallback<V2TIMMessageVector> *callback) = 0;

    /**
     * 5.13 Search for local messages (supported only in 5.4.666 and later versions and need to buy Flagship Edition)
     * @param searchParam Message search parameter. For details, see the definition of V2TIMMessageSearchParam.
     */
    virtual void SearchLocalMessages(const V2TIMMessageSearchParam &searchParam,
                                     V2TIMValueCallback<V2TIMMessageSearchResult> *callback) = 0;

    /**
     *  5.14 Send read receipts to the message sender for message which have been received（Supported only in 6.1 and later versions and need to buy Flagship Edition）
     *  @param messageList Message list
     *
     * @note Notes:
     * - To send a read receipt to a group message, you need to go to the console and turn on the corresponding switch. 
     * - After the API is called successfully, the conversation unread count will not change, and the message sender will receive the OnRecvMessageReadReceipts callback, which will carry the latest read information of the message.
     */
    virtual void SendMessageReadReceipts(const V2TIMMessageVector &messageList, V2TIMCallback *callback) = 0;

    /**
     *  5.15 Get read receipts for messages which have been sent by myself（Supported only in 6.1 and later versions and need to buy Flagship Edition）
     *  @param messageList Message list
     *
     * @note Notes:
     * - To obtain the read receipt of group message, you need to go to the console and turn on the corresponding switch. 
     * - The messages in messageList must be in the same conversation.
     */
    virtual void GetMessageReadReceipts(const V2TIMMessageVector &messageList, V2TIMValueCallback<V2TIMMessageReceiptVector> *callback) = 0;

    /**
     * 5.16 Get group members profile who have read ths message（Supported only in 6.1 and later versions and need to buy Flagship Edition）
     * @param message group message
     * @param filter Specify the group message read members type.
     * @param nextSeq Pulling-by-page cursor. It is set to 0 when the information is pulled for the first time. The value of this field in the callback for the current paginated pulling is passed in  for the next pull.
     * @param count Number of read members pulled per page. Supports up to 100.
     *
     * @note Notes:
     * - Please go to the console and turn on the corresponding switch before using this feature.
     */
    virtual void GetGroupMessageReadMemberList(const V2TIMMessage &message, V2TIMGroupMessageReadMembersFilter filter, uint64_t nextSeq, uint32_t count, V2TIMValueCallback<V2TIMGroupMessageReadMemberList> *callback) = 0;

    /**
     * 5.17 Set message extensions (supported only in 6.7 and later versions)
     * @param message The target message must be sent successfully and its supportMessageExtension field must be set to YES before sending. In addition, Community and AVChatRoom message do not support this feature.
     * @param extensions The existing message extensions will be updated, and non-existing message extensions will be added directly.
     *
     * @note
     * - You need to buy Flagship Edition to use this feature. And you need to go to the IM console to enable this feature.
     * - The extension key supports a maximum of 100 bytes, the extension value supports a maximum of 1KB, a maximum of 20 extensions can be set at a time, and a maximum of 300 extensions can be set for a single message.
     * - When multiple users set or delete the same extension key at the same time, only the first user can execute it successfully, and other users will receive the 23001 error code and the newest extension information. A retry operation can be invoked after receiveing the newest information.
     * - We strongly recommend that different users set different extension keys, so that conflict will not appear in most scenarios. For example, you can use your userID as an extension key for voting, solitaire, and questionnaires.
     */
    virtual void SetMessageExtensions(const V2TIMMessage &message, const V2TIMMessageExtensionVector &extensions, V2TIMValueCallback<V2TIMMessageExtensionResultVector> *callback) = 0;

    /**
     * 5.18 Get message extensions (supported only in 6.7 and later versions)
     */
    virtual void GetMessageExtensions(const V2TIMMessage &message, V2TIMValueCallback<V2TIMMessageExtensionVector> *callback) = 0;

    /**
     * 5.19 Delete message extensions (supported only in 6.7 and later versions)
     * @param keys Message extension key list, A maximum of 20 message extensions can be deleted at a time , if set to nil , it means to delete all extensions of the message.
     *
     * @note
     * - When multiple users set or delete the same extension key at the same time, only the first user can execute it successfully, and other users will receive the 23001 error code and the newest extension information. A retry operation can be invoked after receiveing the newest information.
     */
    virtual void DeleteMessageExtensions(const V2TIMMessage &message, const V2TIMStringVector &keys, V2TIMValueCallback<V2TIMMessageExtensionResultVector> *callback) = 0;

    /**
     *  5.20 Translate text message.
     *
     *  @param sourceTextList Texts to be translated.
     *  @param sourceLanguage Source language. You can pass the specific language or "auto". "auto" means identifying the source language automatically. If you set it to nil, "auto" will be filled as default.
     *  @param targetLanguage Target language. Multi languages are supported, like: English-"en", Simplified Chinese-"zh", French-"fr", German-"ge" and so on. See the documentation for more details: [Language support](https://cloud.tencent.com/document/product/269/85380#.E6.96.87.E6.9C.AC.E7.BF.BB.E8.AF.91.E8.AF.AD.E8.A8.80.E6.94.AF.E6.8C.81).
     *  @param callback Translated result callback. The key represents the source text and value represents target text.
     */
    virtual void TranslateText(const V2TIMStringVector &sourceTextList,
                               const V2TIMString &sourceLanguage, const V2TIMString &targetLanguage,
                               V2TIMValueCallback<V2TIMStringToV2TIMStringMap> *callback) = 0;
};

#endif  // __V2TIM_MESSAGE_MANAGER_H__
