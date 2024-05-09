// Copyright (c) 2021 Tencent. All rights reserved.

/////////////////////////////////////////////////////////////////////
//
//                     Tencent Cloud Instant Messaging SDK
//
//  Conversation APIs, including the APIs for getting, deleting, and updating conversations
//
/////////////////////////////////////////////////////////////////////

#ifndef __V2TIM_CONVERSATION_MANAGER_H__
#define __V2TIM_CONVERSATION_MANAGER_H__

#include "V2TIMCallback.h"
#include "V2TIMConversation.h"
#include "V2TIMDefine.h"
#include "V2TIMListener.h"

class TIM_API V2TIMConversationManager {
public:
    virtual ~V2TIMConversationManager() {}


    /////////////////////////////////////////////////////////////////////////////////
    //
    //    Conversation management APIs.
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 1.1 Add the conversation listener
     */
    virtual void AddConversationListener(V2TIMConversationListener* listener) = 0;

    /**
     * 1.2 Remove the conversation listener
     */
    virtual void RemoveConversationListener(V2TIMConversationListener* listener) = 0;

    /**
     * 1.3 Get the conversation list
     *
     * - Each conversation corresponds to a chat window. For example, a one-to-one chat or a chat group is a conversation.
     * - Since there may be a large number of historical conversations, you are advised to call this API in query-by-page mode and pull 100 historical conversations per page at a time.
     * - This API pulls locally cached conversations. If conversations on the server are updated, the SDK automatically synchronizes the updates internally and then notifies users via @ref V2TIMConversationListener callback.
     * - If all conversations are pulled, the value of the isFinished field in V2TIMConversationResult in the success callback is true.
     *
     * @note  Conversation sorting rules
     * - For 5.5.892 and later versions, conversations on the conversion list obtained by this API are sorted by orderKey by default. The larger the orderKey value, the higher the order of the conversation.
     * - For versions earlier than 5.5.892, conversations on the conversion list obtained by this API are sorted by "lastMessage -> timestamp" by default. The later the timestamp, the higher the order of the conversation.
     *
     * @param nextSeq   Pulling-by-page cursor. It is set to 0 when the information is pulled for the first time. The value of this field in the callback for the current paginated pulling is passed in for the next pull.
     * @param count     Number of conversations pulled per page. The value of this field cannot be too large; otherwise, the pulling speed is affected. We recommend that you pull 100 conversations per page.
     */
    virtual void GetConversationList(uint64_t nextSeq, uint32_t count,
                                     V2TIMValueCallback<V2TIMConversationResult>* callback) = 0;

    /**
     * 1.4 Get a single conversation
     *
     * @param conversationID  Unique ID of a conversation. For one-to-one chats, the value format is String.format("c2c_%s", "userID"). For group chats, the value format is String.format("group_%s", "groupID").
     */
    virtual void GetConversation(const V2TIMString& conversationID,
                                 V2TIMValueCallback<V2TIMConversation>* callback) = 0;

    /**
     * 1.5 Get a specified conversation list
     *
     * @param conversationIDList List of the unique IDs of conversations. For one-to-one chats, the value format is String.format("c2c_%s", "userID"). For group chats, the value format is String.format("group_%s", "groupID").
     */
    virtual void GetConversationList(const V2TIMStringVector& conversationIDList,
                                     V2TIMValueCallback<V2TIMConversationVector>* callback) = 0;

    /**
     *  1.6 Get the conversation list (advanced API，supported only in 6.5 and later versions)
     *
     * @param filter conversation filter
     * @param nextSeq The next pulling-by-page cursor
     * @param count Number of conversations to be pulled
     *
     */
    virtual void GetConversationListByFilter(const V2TIMConversationListFilter &filter,
                                             uint64_t nextSeq, uint32_t count,
                                             V2TIMValueCallback<V2TIMConversationResult>* callback) = 0;

    /**
     * 1.7 Delete a conversation
     *
     * @param conversationID Unique ID of a conversation. For one-to-one chats, the value format is String.format("c2c_%s", "userID"). For group chats, the value format is String.format("group_%s", "groupID").
     *
     * @note Notes:
     * - When a conversation is deleted from local storage, it is also deleted from the server.
     * - When messages in a conversation are deleted from local storage, they are also deleted from the server.
     */
    virtual void DeleteConversation(const V2TIMString& conversationID, V2TIMCallback* callback) = 0;

    /**
     * 1.8 Set a draft for a conversation
     *
     * @param conversationID Unique ID of a conversation. For one-to-one chats, the value format is String.format("c2c_%s", "userID"). For group chats, the value format is String.format("group_%s", "groupID").
     * @param draftText Draft content. The value empty indicates cancelling the draft.
     */
    virtual void SetConversationDraft(const V2TIMString& conversationID,
                                      const V2TIMString& draftText, V2TIMCallback* callback) = 0;


    /**
     *  1.9 Set conversation custom data（supported only in 6.5 and later versions）
     *
     * @param customData Maximum support 256 bytes
     */
    virtual void SetConversationCustomData(const V2TIMStringVector &conversationIDList, const V2TIMBuffer &customData,
                                           V2TIMValueCallback<V2TIMConversationOperationResultVector>* callback) = 0;

    /**
     * 1.10 Pin a conversion to the top (supported only in 5.3.425 and later versions)
     *
     * @param conversationID Unique ID of a conversation. For one-to-one chats, the value format is String.format("c2c_%s", "userID"). For group chats, the value format is String.format("group_%s", "groupID").
     * @param isPinned Whether to pin a conversation to the top
     */
    virtual void PinConversation(const V2TIMString& conversationID, bool isPinned,
                                 V2TIMCallback* callback) = 0;

    /**
     *  1.11 Mark conversation（supported only in 6.5 and later versions, need to buy Flagship Edition）
     *  @param conversationIDList conversation list
     *  @param markType mark type of the conversation. For the value, see the V2TIMConversationMarkType definition.
     *  @param enableMark true：mark false：unmark
     *
     *  <p>If the existing mark does not meet your needs, you can customize the extension mark. The extension mark needs to meet the following two conditions:
     *  <p>1、Extended mark values ​​must not conflict with existing mark values ​​in V2TIIMConversationMarkType.
     *  <p>2、Extended mark values must be a 0x1LL << n (32 <= n < 64, that is, n must be greater than or equal to 32 and less than 64), such as the extension mark value 0x1LL << 32 means "Windows is online".
     *
     *  @note: The extension mark value cannot be set to 0x1 << 32, it must be set to 0x1LL << 32, which explicitly tells the compiler that it is a 64-bit integer constant.
     */

    virtual void MarkConversation(const V2TIMStringVector &conversationIDList, uint64_t markType, bool enableMark,
                                  V2TIMValueCallback<V2TIMConversationOperationResultVector>* callback) = 0;

    /**
     * 1.12 Get the total message unread count of all conversations (supported only in 5.3.425 and later versions)
     * @note
     *  - After you call this API to obtain the total count of unread messages for all conversations, the newest value will be notified to you through the OnTotalUnreadMessageCountChanged callback when unread message count of any conversation changed.
     *  - The total unread message count excludes the unread message count of Do-Not-Disturb conversations (conversations whose message receiving option is V2TIM_NOT_RECEIVE_MESSAGE or V2TIM_RECEIVE_NOT_NOTIFY_MESSAGE).
     */
    virtual void GetTotalUnreadMessageCount(V2TIMValueCallback<uint64_t>* callback) = 0;

    /**
     *  1.13 Get the total message unread count in conversations by filter (supported only in 7.0 and later versions)
     *
     * @param filter conversation filter
     *
     * @note
     *  - The total unread message count excludes the unread message count of Do-Not-Disturb conversations (conversations whose message receiving option is V2TIM_NOT_RECEIVE_MESSAGE or V2TIM_RECEIVE_NOT_NOTIFY_MESSAGE).
     */
    virtual void GetUnreadMessageCountByFilter(const V2TIMConversationListFilter &filter,
        V2TIMValueCallback<uint64_t>* callback) = 0;

    /**
     *  1.14 Subscribe changing notification of total unread message count for conversations specified by filter parameter.(supported only in 7.0 and later versions)
     *
     * @param filter conversation filter
     *
     * @note
     *  - After you call this API, the newest value of total unread message count for conversations that match the filter parameter will be notified to you through the OnUnreadMessageCountChangedByFilter callback.
     */
    virtual void SubscribeUnreadMessageCountByFilter(const V2TIMConversationListFilter &filter) = 0;

    /**
     *  1.15 Unsubscribe changing notification of total unread message count for conversations specified by filter parameter.(supported only in 7.0 and later versions)
     *
     * @param filter conversation filter
     *
     */
    virtual void UnsubscribeUnreadMessageCountByFilter(const V2TIMConversationListFilter &filter) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //   Conversation group APIs （Only supported in 6.5 and later versions, need to buy Flagship Edition）
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 2.1 Create a conversation group.
     * @param groupName group name（Required parameters, length must be greater than 0, maximum support 32 bytes）
     * @param conversationIDList conversation ID list（Required parameters，can not be empty）
     *
     * @note A maximum of 20 conversation groups are supported. Please delete the groups that are no longer in use.
     */
    virtual void CreateConversationGroup(const V2TIMString &groupName, const V2TIMStringVector &conversationIDList,
                                         V2TIMValueCallback<V2TIMConversationOperationResultVector>* callback) = 0;

    /**
     * 2.2 Get a list of conversation groups.
     */
    virtual void GetConversationGroupList(V2TIMValueCallback<V2TIMStringVector>* callback) = 0;

    /**
     * 2.3 Delete a conversation group.
     */
    virtual void DeleteConversationGroup(const V2TIMString &groupName, V2TIMCallback* callback) = 0;

    /**
     * 2.4 Rename a conversation group.
     */
    virtual void RenameConversationGroup(const V2TIMString &oldName, const V2TIMString &newName,
                                         V2TIMCallback* callback) = 0;

    /**
     * 2.5 Add conversation list to a group.
     */
    virtual void AddConversationsToGroup(const V2TIMString &groupName, const V2TIMStringVector &conversationIDList,
                                         V2TIMValueCallback<V2TIMConversationOperationResultVector>* callback) = 0;

    /**
     * 2.6 Delete conversation list from a group.
     */
    virtual void DeleteConversationsFromGroup(const V2TIMString &groupName, const V2TIMStringVector &conversationIDList,
                                              V2TIMValueCallback<V2TIMConversationOperationResultVector>* callback) = 0;
};

#endif  // __V2TIM_CONVERSATION_MANAGER_H__
