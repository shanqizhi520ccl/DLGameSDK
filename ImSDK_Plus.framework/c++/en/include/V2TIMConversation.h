// Copyright (c) 2021 Tencent. All rights reserved.

#ifndef __V2TIM_CONVERSATION_H__
#define __V2TIM_CONVERSATION_H__

#include "V2TIMCommon.h"
#include "V2TIMMessage.h"
#include "V2TIMString.h"

/////////////////////////////////////////////////////////////////////////////////
//
//                    Enumeration definition
//
/////////////////////////////////////////////////////////////////////////////////

/// Conversation type
enum V2TIMConversationType {
    ///< unknown
    V2TIM_UNKNOWN = 0,
    ///< One-to-one chat
    V2TIM_C2C = 1,
    ///< Group chat
    V2TIM_GROUP = 2,
};

/// Enumeration definition of conversation mark type
enum  V2TIMConversationMarkType {
    ///< Mark a conversation as star
    V2TIM_CONVERSATION_MARK_TYPE_STAR     = 0x1,
    ///< Mark a conversation as unread
    V2TIM_CONVERSATION_MARK_TYPE_UNREAD   = 0x1 << 1,
    ///< Fold a conversation
    V2TIM_CONVERSATION_MARK_TYPE_FOLD     = 0x1 << 2,
    ///< Hide a conversation
    V2TIM_CONVERSATION_MARK_TYPE_HIDE     = 0x1 << 3,
};

/////////////////////////////////////////////////////////////////////////////////
//
//                     Struct definition
//
/////////////////////////////////////////////////////////////////////////////////

DEFINE_VECTOR(uint64_t)
typedef TXuint64_tVector UInt64Vector;

///  Definition of V2TIMConversation
struct TIM_API V2TIMConversation {
    /// Conversation type.
    V2TIMConversationType type;
    /// Unique ID of a conversation. For one-to-one chats, the value format is String.format("c2c_%s", "userID"). For group chats, the value format is String.format("group_%s", "groupID").
    V2TIMString conversationID;
    /// If the conversation type is one-to-one chat, the userID stores the user ID of the peer; otherwise, the userID is nil
    V2TIMString userID;
    /// If the conversation type is group chat, the groupID stores the current group ID; otherwise, the groupID is nil
    V2TIMString groupID;
    ///  Group type of a conversation (valid for group conversations only)
    V2TIMString groupType;
    /// Display name of a conversation. Conversation display name priorities are as follows:
    /// - Group: group name
    /// - One-to-one: peer's remarks -> peer's nickname -> peer's userID
    V2TIMString showName;
    /// Conversation display profile photo.
    /// - Group: group profile photo
    /// - One-to-one: peer's profile photo
    V2TIMString faceUrl;
    /// Count of unread messages in a conversation.
    int unreadCount;
    /// Message receiving option for a conversation (Receive | Receive but not notify | Not receive)
    V2TIMReceiveMessageOpt recvOpt;
    /**
     * Last message of a conversation
     * @note For versions earlier than 5.5.892, please use "lastMessage -> timestamp" to sort conversations. The later the timestamp, the higher the order of the conversation.
     */
    V2TIMMessage *lastMessage;
    /// @ information list in a group conversation, which is used to display "someone@me" or "@All" notifications
    V2TIMGroupAtInfoVector groupAtInfolist;
    /// Draft information, please call SetConversationDraft() API to set draft information
    V2TIMString draftText;
    /// Time stamp of draft information
    uint64_t draftTimestamp;
    /// Whether to pin on top
    bool isPinned;
    /// orderKey (supported only in 5.5.892 and later)
    /// @note
    /// - The sorting field orderKey is a number that increases linearly according to the conversation activation time (note: this is not a timestamp because multiple conversations may be activated at the same time).
    /// - For 5.5.892 and later versions, it is recommended that you use this field to sort all conversations. The larger the orderKey value, the higher the order of the conversation.
    /// - When you clear all messages in a conversation at a time or delete all messages in the conversation one by one, the lastMessage of the conversation becomes empty, but the orderKey of the conversation will not change. In that case, if you want to keep the sorting positions of conversations unchanged, you can use this field to sort all conversations.
    uint64_t orderKey;
    /// Mark list of the conversation（supported only in 6.5 and later versions）
    UInt64Vector markList;
    /// Custom data of the conversation（supported only in 6.5 and later versions）
    V2TIMBuffer customData;
    /// Conversation group name list to which the conversation belongs.（supported only in 6.5 and later versions）
    V2TIMStringVector conversationGroupList;

    V2TIMConversation();
    V2TIMConversation(const V2TIMConversation& conversation);
    V2TIMConversation& operator=(const V2TIMConversation& conversation);
    ~V2TIMConversation();
};

DEFINE_VECTOR(V2TIMConversation)
typedef TXV2TIMConversationVector V2TIMConversationVector;

/// Conversation filter
struct TIM_API V2TIMConversationListFilter {
    /// The conversation type(fill in 0 means do not filter this item)
    V2TIMConversationType type;
    /// The Conversation group(Fill empty means do not filter this item)
    V2TIMString conversationGroup;
    /// Mark type, see @V2TIMConversationMarkType(fill in 0 means do not filter this item)
    uint64_t markType;

    V2TIMConversationListFilter();
    V2TIMConversationListFilter(const V2TIMConversationListFilter& filter);
    V2TIMConversationListFilter& operator =(const V2TIMConversationListFilter& filter);
    ~V2TIMConversationListFilter();
};

///  Definition of V2TIMConversationResult
struct TIM_API V2TIMConversationResult  {
    /// Next pulling-by-page cursor
    uint64_t nextSeq;
    /// Whether conversation list pulling is completed
    bool isFinished;
    /// Conversation list
    V2TIMConversationVector conversationList;

    V2TIMConversationResult();
    V2TIMConversationResult(const V2TIMConversationResult& conversationResult);
    ~V2TIMConversationResult();
    V2TIMConversationResult& operator=(const V2TIMConversationResult& conversationResult);
};

/// Conversation operation result
struct TIM_API V2TIMConversationOperationResult {
    /// Conversation ID
    V2TIMString conversationID;
    /// The return code
    int resultCode;
    /// The return result description
    V2TIMString resultInfo;

    V2TIMConversationOperationResult();
    V2TIMConversationOperationResult(const V2TIMConversationOperationResult &result);
    ~V2TIMConversationOperationResult();
    V2TIMConversationOperationResult& operator=(const V2TIMConversationOperationResult &result);
};

DEFINE_VECTOR(V2TIMConversationOperationResult)
typedef TXV2TIMConversationOperationResultVector V2TIMConversationOperationResultVector;

#endif /* __V2TIM_CONVERSATION_H__ */
