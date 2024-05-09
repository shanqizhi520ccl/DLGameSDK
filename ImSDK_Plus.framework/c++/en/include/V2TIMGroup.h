// Copyright (c) 2021 Tencent. All rights reserved.

#ifndef __V2TIM_GROUP_H__
#define __V2TIM_GROUP_H__

#include "V2TIMCommon.h"
#include "V2TIMDefine.h"

/////////////////////////////////////////////////////////////////////////////////
//
//                     Enumeration definition
//
/////////////////////////////////////////////////////////////////////////////////

/// Group member role
enum V2TIMGroupMemberRole {
    /// Undefined (this field is not obtained)
    V2TIM_GROUP_MEMBER_UNDEFINED = 0,
    /// Group member
    V2TIM_GROUP_MEMBER_ROLE_MEMBER = 200,
    /// Group admin
    V2TIM_GROUP_MEMBER_ROLE_ADMIN = 300,
    /// Group owner
    V2TIM_GROUP_MEMBER_ROLE_SUPER = 400,
};

/// Change type to group information
enum V2TIMGroupInfoChangeType {
    /// Change the group name
    V2TIM_GROUP_INFO_CHANGE_TYPE_NAME = 0x01,
    /// Modify the group introduction
    V2TIM_GROUP_INFO_CHANGE_TYPE_INTRODUCTION = 0x02,
    /// Modify the group notice
    V2TIM_GROUP_INFO_CHANGE_TYPE_NOTIFICATION = 0x03,
    /// Modify the group profile photo
    V2TIM_GROUP_INFO_CHANGE_TYPE_FACE = 0x04,
    ///  Change the group owner
    V2TIM_GROUP_INFO_CHANGE_TYPE_OWNER = 0x05,
    /// Change the custom group field
    V2TIM_GROUP_INFO_CHANGE_TYPE_CUSTOM = 0x06,
    ///< Change the group muting field
    V2TIM_GROUP_INFO_CHANGE_TYPE_SHUT_UP_ALL  = 0x08, 
    ///< Change the group message receive option field
    V2TIM_GROUP_INFO_CHANGE_TYPE_RECEIVE_MESSAGE_OPT = 0x0A,
    ///< Change the group add option field
    V2TIM_GROUP_INFO_CHANGE_TYPE_GROUP_ADD_OPT = 0x0B, 
};

/// Group joining approval type
enum V2TIMGroupAddOpt {
    ///  Forbid anyone to join the group
    V2TIM_GROUP_ADD_FORBID = 0,
    /// Require admin approval
    V2TIM_GROUP_ADD_AUTH = 1,
    /// Anyone can join
    V2TIM_GROUP_ADD_ANY = 2,
};

// Group info modification flag
enum V2TIMGroupInfoModifyFlag {
    // Unknown
    V2TIM_GROUP_INFO_MODIFY_FLAG_UNKNOWN = 0x00,
    // Group name
    V2TIM_GROUP_INFO_MODIFY_FLAG_GROUP_NAME = 0x01,
    // Group notification
    V2TIM_GROUP_INFO_MODIFY_FLAG_NOTIFICATION = 0x01 << 1,
    // Group introduction
    V2TIM_GROUP_INFO_MODIFY_FLAG_INTRODUCTION = 0x01 << 2,
    // Group avatar
    V2TIM_GROUP_INFO_MODIFY_FLAG_FACE_URL = 0x01 << 3,
    // Add group option
    V2TIM_GROUP_INFO_MODIFY_FLAG_GROUP_ADD_OPTION = 0x01 << 4,
    // Mute all gorup members
    V2TIM_GROUP_INFO_MODIFY_FLAG_SHUTUP_ALL = 0x01 << 8,
    // Group info custom data
    V2TIM_GROUP_INFO_MODIFY_FLAG_CUSTOM_INFO = 0x01 << 9,
    // topic info custom data
    V2TIM_TOPIC_INFO_MODIFY_FLAG_CUSTOM_STRING = 0x1 << 11,
};

///  Operation result related to group members
enum V2TIMGroupMemberResult {
    /// Operation failed
    V2TIM_GROUP_MEMBER_RESULT_FAIL = 0,
    /// Operation succeeded
    V2TIM_GROUP_MEMBER_RESULT_SUCC = 1,
    /// Invalid operation: already in the group when being added to the group, or not in the group when being removed from the group
    V2TIM_GROUP_MEMBER_RESULT_INVALID = 2,
    /// To be processed: waiting to be processed by the peer party when being invited to join a group
    V2TIM_GROUP_MEMBER_RESULT_PENDING = 3,
    /// Operation failed: when specifying the initial group member list or inviting a user to join the group during group creation, the total number of groups that the invitee joins exceeds the limit
    V2TIM_GROUP_MEMBER_RESULT_OVERLIMIT = 4,
};

/// Filter type for group members
enum V2TIMGroupMemberFilter {
    /// All group members
    V2TIM_GROUP_MEMBER_FILTER_ALL = 0x00,
    /// Group owner
    V2TIM_GROUP_MEMBER_FILTER_OWNER = 0x01,
    /// Group admin
    V2TIM_GROUP_MEMBER_FILTER_ADMIN = 0x02,
    /// Group member
    V2TIM_GROUP_MEMBER_FILTER_COMMON = 0x04,
};

// Group member data modification flag
enum V2TIMGroupMemberInfoModifyFlag {
    // Unknown
    V2TIM_GROUP_MEMBER_INFO_MODIFY_FLAG_UNKNOWN = 0x00,
    // Group member role
    V2TIM_GROUP_MEMBER_INFO_MODIFY_FLAG_MEMBER_ROLE = 0x01 << 1,
    // Mute time
    V2TIM_GROUP_MEMBER_INFO_MODIFY_FLAG_SHUTUP_TIME = 0x01 << 2,
    // Group name card
    V2TIM_GROUP_MEMBER_INFO_MODIFY_FLAG_NAME_CARD = 0x01 << 3,
    // Group member custom data
    V2TIM_GROUP_MEMBER_INFO_MODIFY_FLAG_CUSTOM_INFO = 0x01 << 4,
};

/// Group request type
enum V2TIMGroupApplicationGetType {
    /// Request to join a group
    V2TIM_GROUP_APPLICATION_GET_TYPE_JOIN = 0x0,
    /// Be invited to join a group
    V2TIM_GROUP_APPLICATION_GET_TYPE_INVITE = 0x1,
};

/// Processing status for group request
enum V2TIMGroupApplicationHandleStatus {
    /// Not handled
    V2TIM_GROUP_APPLICATION_HANDLE_STATUS_UNHANDLED = 0,
    /// Handled by others
    V2TIM_GROUP_APPLICATION_HANDLE_STATUS_HANDLED_BY_OTHER = 1,
    /// Handled by yourself
    V2TIM_GROUP_APPLICATION_HANDLE_STATUS_HANDLED_BY_SELF = 2,
};

/// Process result for group request
enum V2TIMGroupApplicationHandleResult {
    /// Reject a request
    V2TIM_GROUP_APPLICATION_HANDLE_RESULT_REFUSE = 0,
    /// Accept a request
    V2TIM_GROUP_APPLICATION_HANDLE_RESULT_AGREE = 1,
};

///  @ type
enum V2TIMGroupAtType {
    ///< @me
    V2TIM_AT_ME = 1,
    ///< @all
    V2TIM_AT_ALL = 2,
    ///< @all in the group and @me alone
    V2TIM_AT_ALL_AT_ME = 3,
};

/////////////////////////////////////////////////////////////////////////////////
//
//                    Struct definition
//
/////////////////////////////////////////////////////////////////////////////////

/// Basic profile
struct TIM_API V2TIMGroupMemberInfo {
    /// User ID
    V2TIMString userID;
    /// User nickname
    V2TIMString nickName;
    /// Friend remarks
    V2TIMString friendRemark;
    /// Name card
    V2TIMString nameCard;
    /// Profile photo URL
    V2TIMString faceURL;

    V2TIMGroupMemberInfo();
    V2TIMGroupMemberInfo(const V2TIMGroupMemberInfo& groupMemberInfo);
    ~V2TIMGroupMemberInfo();
};

DEFINE_VECTOR(V2TIMGroupMemberInfo)
typedef TXV2TIMGroupMemberInfoVector V2TIMGroupMemberInfoVector;

/// Detail profile
struct TIM_API V2TIMGroupMemberFullInfo : public V2TIMGroupMemberInfo {
    /// Custom fields
    /// To configure the corresponding keys and permissions, go to [IM console](https://console.cloud.tencent.com/avc) -> Feature Configuration -> Custom Group Member Fields.
    V2TIMCustomInfo customInfo;
    ///  Group member role. To modify group member role, please call the V2TIMManagerGroup.h -> SetGroupMemberRole API.
    uint32_t role;
    /// End time of being mute. To mute group member, please call the V2TIMManagerGroup.h -> MuteGroupMember API.
    uint32_t muteUntil;
    /// Joining time of group members. The group joining time is automatically generated and cannot be modified.
    int64_t joinTime;
    // Group member data modification flag
    // Enumeration V2TIMGroupMemberInfoModifyFlag lists which fields support modification. 
    // If you modify group member information, please set this field value to support modifying multiple fields 
    // at the same time. Multiple enumeration values ​​are combined by bitwise OR, for example, 
    // modifying group member name card and group member role at the same time.
    // info.nameCard = "new name card";
    // info.role = V2TIM_GROUP_MEMBER_ROLE_ADMIN;
    // info.modifyFlag = V2TIM_GROUP_MEMBER_INFO_MODIFY_FLAG_NAME_CARD | V2TIM_GROUP_MEMBER_INFO_MODIFY_FLAG_MEMBER_ROLE;
    uint32_t modifyFlag;

    V2TIMGroupMemberFullInfo();
    V2TIMGroupMemberFullInfo(const V2TIMGroupMemberFullInfo& groupMemberFullInfo);
    ~V2TIMGroupMemberFullInfo();
};

DEFINE_VECTOR(V2TIMGroupMemberFullInfo)
typedef TXV2TIMGroupMemberFullInfoVector V2TIMGroupMemberFullInfoVector;

/// The result of obtaining group member info
struct TIM_API V2TIMGroupMemberInfoResult {
    // Get the seq of paginated pulls. If it is 0, it means the pull is over
    uint64_t nextSequence;
    // Group member info list
    V2TIMGroupMemberFullInfoVector memberInfoList;

    V2TIMGroupMemberInfoResult();
    V2TIMGroupMemberInfoResult(const V2TIMGroupMemberInfoResult& groupMemberInfoResult);
    ~V2TIMGroupMemberInfoResult();
};

/// Definition of V2TIMGroupChangeInfo
struct TIM_API V2TIMGroupChangeInfo {
    /// Group profile change type
    V2TIMGroupInfoChangeType type;
    /// Value has different meanings depending on the change type. For example, when type is V2TIM_GROUP_INFO_CHANGE_TYPE_NAME, value indicates the new group name.
    V2TIMString value;
    /// Value of key of the custom field modified (valid only when type is V2TIM_GROUP_INFO_CHANGE_TYPE_CUSTOM)
    /// For historical reasons, if only the custom group field is modified, the current message will not be saved to the roaming server or database.
    V2TIMString key;

    /// BoolValue has different meanings depending on the change type(valid only when type is V2TIM_GROUP_INFO_CHANGE_TYPE_SHUT_UP_ALL)
    bool boolValue;
    
    /// IntValue has different meanings depending on the change type(valid only when type is V2TIM_GROUP_INFO_CHANGE_TYPE_RECEIVE_MESSAGE_OPT or V2TIM_GROUP_INFO_CHANGE_TYPE_GROUP_ADD_OPT). (supported only in imsdk 6.5 and later versions)
    uint32_t intValue;

    V2TIMGroupChangeInfo();
    V2TIMGroupChangeInfo(const V2TIMGroupChangeInfo& groupChangeInfo);
    ~V2TIMGroupChangeInfo();
};

DEFINE_VECTOR(V2TIMGroupChangeInfo)
typedef TXV2TIMGroupChangeInfoVector V2TIMGroupChangeInfoVector;

/// Definition of V2TIMGroupMemberChangeInfo
struct TIM_API V2TIMGroupMemberChangeInfo {
    /// UserID of a group member
    V2TIMString userID;
    /// Muting duration which indicates how many seconds are left to speak.
    uint32_t muteTime;

    V2TIMGroupMemberChangeInfo();
    V2TIMGroupMemberChangeInfo(const V2TIMGroupMemberChangeInfo& groupMemberChangeInfo);
    ~V2TIMGroupMemberChangeInfo();
};

DEFINE_VECTOR(V2TIMGroupMemberChangeInfo)
typedef TXV2TIMGroupMemberChangeInfoVector V2TIMGroupMemberChangeInfoVector;

/// @ information in a group conversation
struct TIM_API V2TIMGroupAtInfo {
    /// Sequence of message which contain @ information
    uint64_t seq;
    /// @ type
    V2TIMGroupAtType atType;

    V2TIMGroupAtInfo();
    V2TIMGroupAtInfo(const V2TIMGroupAtInfo& groupAtInfo);
    V2TIMGroupAtInfo& operator=(const V2TIMGroupAtInfo& conversation);
    ~V2TIMGroupAtInfo();
};

DEFINE_VECTOR(V2TIMGroupAtInfo)
typedef TXV2TIMGroupAtInfoVector V2TIMGroupAtInfoVector;

///  Definition of V2TIMGroupInfo
struct TIM_API V2TIMGroupInfo {
    /// Group ID
    /// The custom group ID must be printable ASCII characters (0x20-0x7e) with a maximum length of 48 bytes. It cannot begin with @TGS# so as to avoid confusion with the default group IDs assigned by IM.
    V2TIMString groupID;
    /// Group type
    V2TIMString groupType;
    /// Get supporting topic of not. (valid only for Community)
    bool isSupportTopic;
    /// Group name
    /// The maximum length of the group name is 30 bytes.
    V2TIMString groupName;
    /// Group notice
    /// The maximum length of the group notice is 300 bytes.
    V2TIMString notification;
    /// Group introduction
    /// The maximum length of the group introduction is 240 bytes.
    V2TIMString introduction;
    /// Group profile photo URL
    /// The maximum length of the group profile photo URL is 100 bytes.
    V2TIMString faceURL;
    /// Whether to mute all group members
    bool allMuted;
    /// Get custom group fields
    /// To set a custom group field, perform the following steps:
    /// <p> 1. Go to the [console](https://console.cloud.tencent.com/im) (Feature Configuration -> Custom Group Field) to set the key value of the custom group field. The key field is of the String type, with a maximum length of 16 bytes.
    /// <p> 2. Call the setGroupInfo API to set the field. The field value is of the NSData type, with a maximum length of 512 bytes.
    /// @note This field is mainly used for compatibility with V1 and V2. If you are using V2 APIs, you are advised to use the initGroupAttributes API to set group attributes because the API is more flexible (requiring no configuration in the console) and supports a larger storage capacity (up to 16 KB). You are advised to use the initGroupAttributes API to set group attributes because the API is more flexible (requiring no configuration in the console) and supports a larger storage capacity (up to 16 KB).
    V2TIMCustomInfo customInfo;
    /// Group owner ID
    V2TIMString owner;
    /// Group creation time
    uint32_t createTime;
    /// Group joining approval type
    /// @note This operation can be performed only during group creation or group information modification and applies only to public groups.
    V2TIMGroupAddOpt groupAddOpt;
    /// Latest group data modification time of the group
    uint32_t lastInfoTime;
    /// Last time the group sends a message
    uint32_t lastMessageTime;
    /// Number of members that have joined the group
    uint32_t memberCount;
    /// Number of online group members
    uint32_t onlineCount;
    /// Maximum number of group members allowed to join
    /// @note For details on the number of members allowed for each group type, please see: https://intl.cloud.tencent.com/document/product/1047/33529 https://cloud.tencent.com/document/product/269/1502#.E7.BE.A4.E7.BB.84.E9.99.90.E5.88.B6.E5.B7.AE.E5.BC.82
    uint32_t memberMaxCount;
    /// Group member role of current user. To switch the role, please call the setGroupMemberRole API.
    uint32_t role;
    /// Current user's message receiving option in the group. To modify the group message receiving option, please call the setGroupReceiveMessageOpt API.
    V2TIMReceiveMessageOpt recvOpt;
    /// Time when the current user joins the group. The time is automatically generated by the system and cannot be set.
    uint32_t joinTime;
    /// Group info modification flag
    /// Enumeration V2TIMGroupInfoModifyFlag lists which fields support modification, 
    /// if you modify group information, please set the value of this field, if you modify multiple fields 
    /// at the same time, multiple enumeration values ​​are combined by bitwise OR, for example, 
    /// modify the group name and avatar at the same time.
    /// info.groupName = "new group name";
    /// info.faceURL = "new face url";
    /// info.modifyFlag = V2TIM_GROUP_INFO_MODIFY_FLAG_GROUP_NAME |
    /// V2TIM_GROUP_INFO_MODIFY_FLAG_FACE_URL;
    uint32_t modifyFlag;

    V2TIMGroupInfo();
    V2TIMGroupInfo(const V2TIMGroupInfo& groupInfo);
    ~V2TIMGroupInfo();
};

DEFINE_VECTOR(V2TIMGroupInfo)
typedef TXV2TIMGroupInfoVector V2TIMGroupInfoVector;

/// Definition of V2TIMGroupInfoResult
struct TIM_API V2TIMGroupInfoResult {
    /// Return code. 0: successful; other: failed
    int resultCode;
    /// Result information
    V2TIMString resultMsg;
    /// Group information
    V2TIMGroupInfo info;

    V2TIMGroupInfoResult();
    V2TIMGroupInfoResult(const V2TIMGroupInfoResult& groupInfoResult);
    ~V2TIMGroupInfoResult();
};

DEFINE_VECTOR(V2TIMGroupInfoResult)
typedef TXV2TIMGroupInfoResultVector V2TIMGroupInfoResultVector;

/////////////////////////////////////////////////////////////////////////////////
//
//             Definition of V2TIMTopicInfo
//
/////////////////////////////////////////////////////////////////////////////////

struct V2TIMMessage;

struct TIM_API V2TIMTopicInfo {
    /// Topic ID
    V2TIMString topicID;
    /// Topic name
    V2TIMString topicName;
    /// Topic face
    V2TIMString topicFaceURL;
    /// Topic introduction
    V2TIMString introduction;
    /// Topic notification
    V2TIMString notification;
    /// Whether to mute all members of this topic
    bool isAllMuted;
    /// Current user's mute time in the topic
    uint32_t selfMuteTime;
    /// Topic custom String
    V2TIMString customString;
    /// Current user's message receiving option in the topic. To modify the topic message receiving option, please call the setGroupReceiveMessageOpt API.
    V2TIMReceiveMessageOpt recvOpt;
    /// Topic draft
    V2TIMString draftText;
    /// Current user's unread message count in the topic
    uint64_t unreadCount;
    /// Topic lastMessage
    V2TIMMessage *lastMessage;
    /// Topic @ information list
    V2TIMGroupAtInfoVector groupAtInfoList;
    /// Topic info modification flag
    /// Enumeration V2TIMGroupInfoModifyFlag lists which fields support modification, 
    /// if you modify group information, please set the value of this field, if you modify multiple fields 
    /// at the same time, multiple enumeration values ​​are combined by bitwise OR, for example, 
    /// modify the group name and avatar at the same time.
    /// info.groupName = "new group name";
    /// info.faceURL = "new face url";
    /// info.modifyFlag = V2TIM_GROUP_INFO_MODIFY_FLAG_GROUP_NAME |
    /// V2TIM_GROUP_INFO_MODIFY_FLAG_FACE_URL;
    uint32_t modifyFlag;

    V2TIMTopicInfo();
    V2TIMTopicInfo(const V2TIMTopicInfo& topicInfo);
    V2TIMTopicInfo& operator =(const V2TIMTopicInfo& topicInfo);
    ~V2TIMTopicInfo();
};

/////////////////////////////////////////////////////////////////////////////////
//
//             Definition of V2TIMTopicOperationResult
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMTopicOperationResult {
    /// Return code. 0: successful; other: failed
    int errorCode;
    /// Result information
    V2TIMString errorMsg;
    /// TopicID
    V2TIMString topicID;

    V2TIMTopicOperationResult();
    V2TIMTopicOperationResult(const V2TIMTopicOperationResult& result);
    ~V2TIMTopicOperationResult();
};

DEFINE_VECTOR(V2TIMTopicOperationResult)
typedef TXV2TIMTopicOperationResultVector V2TIMTopicOperationResultVector;

/////////////////////////////////////////////////////////////////////////////////
//
//             Definition of V2TIMTopicInfoResult
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMTopicInfoResult {
    /// Return code. 0: successful; other: failed
    int32_t errorCode;
    /// Result information
    V2TIMString errorMsg;
    /// Topic information
    V2TIMTopicInfo topicInfo;

    V2TIMTopicInfoResult();
    V2TIMTopicInfoResult(const V2TIMTopicInfoResult& result);
    ~V2TIMTopicInfoResult();
};

DEFINE_VECTOR(V2TIMTopicInfoResult)
typedef TXV2TIMTopicInfoResultVector V2TIMTopicInfoResultVector;

///  Definition of V2TIMGroupApplication
struct TIM_API V2TIMGroupApplication : V2TIMBaseObject {
    /// Group ID
    V2TIMString groupID;
    /// For a request to join a group, it refers to the requester's ID. For a request to invite users to a group, it refers to the inviter's ID.
    V2TIMString fromUser;
    /// Requester's nickname
    V2TIMString fromUserNickName;
    /// Requester's profile photo
    V2TIMString fromUserFaceUrl;
    /// For a request to join a group, it is 0. For a request to invite users to a group, it refers to the invitee's ID.
    V2TIMString toUser;
    /// Time when the group pending request was added
    uint64_t addTime;
    /// Additional information added by the requester
    V2TIMString requestMsg;
    /// Additional information added by the handler
    V2TIMString handledMsg;
    /// Type of the group pending request
    V2TIMGroupApplicationGetType getType;
    /// Processing status of the group pending request
    V2TIMGroupApplicationHandleStatus handleStatus;
    /// Processing type of the group pending request
    V2TIMGroupApplicationHandleResult handleResult;

    V2TIMGroupApplication();
    V2TIMGroupApplication(const V2TIMGroupApplication& groupApplication);
    V2TIMGroupApplication& operator=(const V2TIMGroupApplication& groupApplication);
    ~V2TIMGroupApplication() override;
};

DEFINE_VECTOR(V2TIMGroupApplication)
typedef TXV2TIMGroupApplicationVector V2TIMGroupApplicationVector;

///  Definition of V2TIMGroupMemberOperationResult
struct TIM_API V2TIMGroupMemberOperationResult {
    /// UserID
    V2TIMString userID;
    /// Operation result
    V2TIMGroupMemberResult result;

    V2TIMGroupMemberOperationResult();
    V2TIMGroupMemberOperationResult(
        const V2TIMGroupMemberOperationResult& groupMemberOperationResult);
    ~V2TIMGroupMemberOperationResult();
};

DEFINE_VECTOR(V2TIMGroupMemberOperationResult)
typedef TXV2TIMGroupMemberOperationResultVector V2TIMGroupMemberOperationResultVector;

/// Definition of V2TIMCreateGroupMemberInfo
struct TIM_API V2TIMCreateGroupMemberInfo {
    //  Member's userID
    V2TIMString userID;
    /** Member type
     * 1. If role is left empty or set to V2TIMGroupMemberFullInfo.V2TIM_GROUP_MEMBER_UNDEFINED, a user becomes a group member when the user enters the group by default.
     * 2. Work groups do not allow role to be set as the admin.
     * 3. All groups do not allow role to be set as the group owner.
     */
    uint32_t role;

    V2TIMCreateGroupMemberInfo();
    V2TIMCreateGroupMemberInfo(const V2TIMCreateGroupMemberInfo& createGroupMemberInfo);
    ~V2TIMCreateGroupMemberInfo();
};

DEFINE_VECTOR(V2TIMCreateGroupMemberInfo)
typedef TXV2TIMCreateGroupMemberInfoVector V2TIMCreateGroupMemberInfoVector;

/// Definition of V2TIMGroupApplicationResult
struct TIM_API V2TIMGroupApplicationResult {
    /// Unread count of group joining requests
    uint64_t unreadCount;
    /// List of requests to join a group
    V2TIMGroupApplicationVector applicationList;

    V2TIMGroupApplicationResult();
    V2TIMGroupApplicationResult(const V2TIMGroupApplicationResult& groupApplicationResult);
    ~V2TIMGroupApplicationResult();
};

/// Definition of V2TIMGroupSearchParam
struct TIM_API V2TIMGroupSearchParam {
    /// Keyword list to search. Up to 5 keywords are supported.
    V2TIMStringVector keywordList;
    ///  Whether to search by group ID
    bool isSearchGroupID;
    /// Whether to search by group name
    bool isSearchGroupName;

    V2TIMGroupSearchParam();
    V2TIMGroupSearchParam(const V2TIMGroupSearchParam& groupSearchParam);
    ~V2TIMGroupSearchParam();
};

/// Definition of V2TIMGroupMemberSearchParam
struct TIM_API V2TIMGroupMemberSearchParam {
    ///  Group ID list to search. If null is passed in, group members of all groups are searched.
    V2TIMStringVector groupIDList;
    ///  Keyword list to search. Up to 5 keywords are supported.
    V2TIMStringVector keywordList;
    /// Whether to search by group member's userID
    bool isSearchMemberUserID;
    /// Whether to search by group member's nickname
    bool isSearchMemberNickName;
    /// Whether to search by group member's remarks
    bool isSearchMemberRemark;
    /// Whether to search by group member's name card
    bool isSearchMemberNameCard;

    V2TIMGroupMemberSearchParam();
    V2TIMGroupMemberSearchParam(const V2TIMGroupMemberSearchParam& groupMemberSearchParam);
    ~V2TIMGroupMemberSearchParam();
};

/// SearchGroupMembers Result
DEFINE_MAP(V2TIMString, V2TIMGroupMemberFullInfoVector)
typedef TXV2TIMStringToV2TIMGroupMemberFullInfoVectorMap V2TIMGroupSearchGroupMembersMap;

#endif /* __V2TIM_GROUP_H__ */
