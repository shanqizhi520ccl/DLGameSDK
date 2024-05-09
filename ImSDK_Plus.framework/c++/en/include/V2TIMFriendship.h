// Copyright (c) 2021 Tencent. All rights reserved.

#ifndef __V2TIM_FRIENDSHIP_H__
#define __V2TIM_FRIENDSHIP_H__

#include "V2TIMCommon.h"

/////////////////////////////////////////////////////////////////////////////////
//
//                    Enumeration definition
//
/////////////////////////////////////////////////////////////////////////////////

/// Enumeration definition of user status type
enum V2TIMUserStatusType {
    ///< Unknown status
    V2TIM_USER_STATUS_UNKNOWN = 0,
    ///< Online status
    V2TIM_USER_STATUS_ONLINE = 1,
    ///< Offline status
    V2TIM_USER_STATUS_OFFLINE = 2,
    ///< Unlogined status (such as logout or registering)
    V2TIM_USER_STATUS_UNLOGINED = 3,
};

/// Gender
enum V2TIMGender {
    /// Unknown gender
    V2TIM_GENDER_UNKNOWN = 0,
    /// Male
    V2TIM_GENDER_MALE = 1,
    /// Female
    V2TIM_GENDER_FEMALE = 2,
};

/// Friend verification method
enum V2TIMFriendAllowType {
    /// Automatically accept all new friend requests
    V2TIM_FRIEND_ALLOW_ANY = 0,
    /// Friend request verification is required
    V2TIM_FRIEND_NEED_CONFIRM = 1,
    /// Automatically reject all new friend requests
    V2TIM_FRIEND_DENY_ANY = 2,
};

/// Friend request type
enum V2TIMFriendApplicationType {
    /// Friend request received by me
    V2TIM_FRIEND_APPLICATION_COME_IN = 1,
    /// Friend request sent by me
    V2TIM_FRIEND_APPLICATION_SEND_OUT = 2,
    /// Friend requests received and sent by me. Valid only during pulling
    V2TIM_FRIEND_APPLICATION_BOTH = 3,
};

/// Friend type
enum V2TIMFriendType {
    /// One-way friend
    V2TIM_FRIEND_TYPE_SINGLE = 1,
    /// Two-way friend
    V2TIM_FRIEND_TYPE_BOTH = 2,
};

/// Relation type
enum V2TIMFriendRelationType {
    /// Not a friend
    V2TIM_FRIEND_RELATION_TYPE_NONE = 0x0,
    /// The peer party is on my friend list
    V2TIM_FRIEND_RELATION_TYPE_IN_MY_FRIEND_LIST = 0x1,
    /// I am on the peer party's friend list
    V2TIM_FRIEND_RELATION_TYPE_IN_OTHER_FRIEND_LIST = 0x2,
    /// Two-way friend
    V2TIM_FRIEND_RELATION_TYPE_BOTH_WAY = 0x3,
};

/// Friend acception type
enum V2TIMFriendAcceptType {
    /// Accept the friend request (build a one-way friend relationship)
    V2TIM_FRIEND_ACCEPT_AGREE = 0,
    /// Accept the friend request and add the peer party as a friend (build a two-way friend relationship)
    V2TIM_FRIEND_ACCEPT_AGREE_AND_ADD = 1,
};

// User Info modify flag
enum V2TIMUserInfoModifyFlag {
    // unknown
    V2TIM_USER_INFO_MODIFY_FLAG_UNKNOWN = 0,
    // nick name
    V2TIM_USER_INFO_MODIFY_FLAG_NICK = 1,
    // face URL
    V2TIM_USER_INFO_MODIFY_FLAG_FACE_URL = 2,
    // gender
    V2TIM_USER_INFO_MODIFY_FLAG_GENDER = 3,
    // birthdsay
    V2TIM_USER_INFO_MODIFY_FLAG_BIRTHDAY = 4,
    // self signature
    V2TIM_USER_INFO_MODIFY_FLAG_SELF_SIGNATURE = 7,
    // lever
    V2TIM_USER_INFO_MODIFY_FLAG_LEVEL = 8,
    // role
    V2TIM_USER_INFO_MODIFY_FLAG_ROLE = 9,
    // allow type
    V2TIM_USER_INFO_MODIFY_FLAG_ALLOW_TYPE = 10,
    // custom field
    V2TIM_USER_INFO_MODIFY_FLAG_CUSTOM = 11,
};

// Friend Info modify flag
enum V2TIMFriendInfoModifyFlag {
    // unknown
    V2TIM_FRIEND_INFO_MODIFY_FLAG_UNKNOWN = 0,
    // friend remark
    V2TIM_FRIEND_INFO_MODIFY_FLAG_REMARK = 1,
    // friend custom field
    V2TIM_FRIEND_INFO_MODIFY_FLAG_CUSTOM = 2,
};

/////////////////////////////////////////////////////////////////////////////////
//
//                      Struct definition
//
/////////////////////////////////////////////////////////////////////////////////

/// Basic profile
struct TIM_API V2TIMUserInfo {
    /// User ID
    V2TIMString userID;
    /// User nickname
    V2TIMString nickName;
    /// Profile photo URL
    V2TIMString faceURL;

    V2TIMUserInfo();
    V2TIMUserInfo(const V2TIMUserInfo& userInfo);
    virtual ~V2TIMUserInfo();
};

/// Detail profile
struct TIM_API V2TIMUserFullInfo : public V2TIMUserInfo {
    /// Signature
    V2TIMString selfSignature;
    /// Gender
    V2TIMGender gender;
    /// Role
    uint32_t role;
    /// Level
    uint32_t level;
    /// Birthday
    uint32_t birthday;
    /// Friend verification method
    V2TIMFriendAllowType allowType;
    /// Custom fields
    /// First, you need to set the custom friend field in the [console](https://console.cloud.tencent.com/im) (Feature Configuration -> Custom User Field). Then, you need to call this API to set the custom friend field. The value of key does not need the Tag_Profile_Custom_ prefix.
    V2TIMCustomInfo customInfo;
    // User Info modify flag
    // Enumeration V2TIMUserInfoModifyFlag lists which fields support modification, 
    // if you modify user information, please set this field value to support modifying multiple fields 
    // at the same time, multiple enumeration values ​​are combined by bitwise OR, 
    // for example, modify user nickname and user signature at the same time.
    // info.nickName = "new nickname";
    // info.selfSignature = "new self signature";
    // info.modifyFlag = V2TIM_USER_INFO_MODIFY_FLAG_NICK | V2TIM_USER_INFO_MODIFY_FLAG_SELF_SIGNATURE;
    uint32_t modifyFlag;

    V2TIMUserFullInfo();
    V2TIMUserFullInfo(const V2TIMUserFullInfo& userFullInfo);
    ~V2TIMUserFullInfo() override;
};

DEFINE_VECTOR(V2TIMUserFullInfo)
typedef TXV2TIMUserFullInfoVector V2TIMUserFullInfoVector;

/// Definition of V2TIMUserStatus
struct TIM_API V2TIMUserStatus {
    /// The identifier of status changed user
    V2TIMString userID;

    /// The status of user
    V2TIMUserStatusType statusType;

    /// Custom status, The maximum length of customStatus is 50 bytes.
    V2TIMString customStatus;

    V2TIMUserStatus();
    V2TIMUserStatus(const V2TIMUserStatus &);
    ~V2TIMUserStatus();
};

DEFINE_VECTOR(V2TIMUserStatus)
typedef TXV2TIMUserStatusVector V2TIMUserStatusVector;

///  Definition of V2TIMFriendInfo
struct TIM_API V2TIMFriendInfo {
    /// User's userID
    V2TIMString userID;
    /// Friend remarks
    /// The maximum length of friend remarks cannot exceed 96 bytes.
    /// For field descriptions, see
    /// [Console](https://cloud.tencent.com/document/product/269/1501#.E6.A0.87.E9.85.8D.E5.A5.BD.E5.8F.8B.E5.AD.97.E6.AE.B5)。
    V2TIMString friendRemark;
    /// Friend added time
    uint64_t friendAddTime;
    /// Custom friend fields
    /// First, you need to set the custom friend field in the [console](https://console.cloud.tencent.com/im) (Feature Configuration -> Custom Friend Field).
    /// Then you need to call this API to set the custom friend field. The value of key does not need the Tag_SNS_Custom_ prefix.
    V2TIMCustomInfo friendCustomInfo;
    /// Groups to which a friend belongs
    /// - A maximum of 32 lists are supported.
    /// - The list name cannot be empty.
    /// - The length of a list name cannot exceed 30 bytes
    /// - The same friend can belong to multiple different lists.
    /// - For field descriptions, see [Console](https://cloud.tencent.com/document/product/269/1501#.E6.A0.87.E9.85.8D.E5.A5.BD.E5.8F.8B.E5.AD.97.E6.AE.B5)。
    V2TIMStringVector friendGroups;
    /// User profile of a friend
    V2TIMUserFullInfo userFullInfo;
    // Friend Info modify flag
    // Enumeration V2TIMFriendInfoModifyFlag lists which fields support modification. 
    // If you modify friend information, please set this field value to support modifying multiple fields 
    // at the same time. Multiple enumeration values ​​are combined by bitwise OR, 
    // for example, modifying friend remark and friend custom fields at the same time.
    // info.friendRemark = "new friend remark";
    // info.friendCustomInfo = friendCustomInfo;
    // info.modifyFlag = V2TIM_FRIEND_INFO_MODIFY_FLAG_REMARK | V2TIM_FRIEND_INFO_MODIFY_FLAG_CUSTOM;
    uint32_t modifyFlag;

    V2TIMFriendInfo();
    V2TIMFriendInfo(const V2TIMFriendInfo& friendInfo);
    ~V2TIMFriendInfo();
};

DEFINE_VECTOR(V2TIMFriendInfo)
typedef TXV2TIMFriendInfoVector V2TIMFriendInfoVector;

///  Definition of V2TIMFriendInfoResult
struct TIM_API V2TIMFriendInfoResult {
    /// Result code
    int resultCode;
    /// Result description
    V2TIMString resultInfo;
    /// Relation type
    V2TIMFriendRelationType relation;
    ///User profile of a friend. If you are not a friend, only the userID has a value, and other fields are empty.
    V2TIMFriendInfo friendInfo;

    V2TIMFriendInfoResult();
    V2TIMFriendInfoResult(const V2TIMFriendInfoResult& friendInfoResult);
    ~V2TIMFriendInfoResult();
};

DEFINE_VECTOR(V2TIMFriendInfoResult)
typedef TXV2TIMFriendInfoResultVector V2TIMFriendInfoResultVector;

/// Definition of V2TIMFriendAddApplication
struct TIM_API V2TIMFriendAddApplication {
    /// UserID of a friend to be added
    V2TIMString userID;
    /// Preset remarks for a friend. Its length cannot exceed 96 bytes.
    V2TIMString friendRemark;
    /// Preset a friend group. Its length cannot exceed 96 bytes.
    V2TIMString friendGroup;
    /// Extra information for a friend request. Its length cannot exceed 120 bytes.
    V2TIMString addWording;
    /// Friend request source
    V2TIMString addSource;
    /// Friend request type (two-way by default)
    V2TIMFriendType addType;

    V2TIMFriendAddApplication();
    V2TIMFriendAddApplication(const V2TIMFriendAddApplication& friendAddApplication);
    ~V2TIMFriendAddApplication();
};

/// Friend application
struct TIM_API V2TIMFriendApplication {
    /// User ID of a friend
    V2TIMString userID;
    /// Nickname of a friend
    V2TIMString nickName;
    /// Profile photo of a friend
    V2TIMString faceUrl;
    /// Friend adding time
    uint64_t addTime;
    /// Source
    V2TIMString addSource;
    /// Extra information
    V2TIMString addWording;
    /// Request type
    V2TIMFriendApplicationType type;

    V2TIMFriendApplication();
    V2TIMFriendApplication(const V2TIMFriendApplication& friendApplication);
    ~V2TIMFriendApplication();
};

DEFINE_VECTOR(V2TIMFriendApplication)
typedef TXV2TIMFriendApplicationVector V2TIMFriendApplicationVector;

///Friend application list
struct TIM_API V2TIMFriendApplicationResult {
    /// Unread count of friend requests
    uint64_t unreadCount;
    /// Friend request list
    V2TIMFriendApplicationVector applicationList;

    V2TIMFriendApplicationResult();
    V2TIMFriendApplicationResult(const V2TIMFriendApplicationResult& friendApplicationResult);
    ~V2TIMFriendApplicationResult();
};

/// Definition of V2TIMFriendCheckResult
struct TIM_API V2TIMFriendCheckResult {
    /// Friend's ID
    V2TIMString userID;
    /// Result code
    int32_t resultCode;
    /// Result description
    V2TIMString resultInfo;
    /// Relationship type
    V2TIMFriendRelationType relationType;

    V2TIMFriendCheckResult();
    V2TIMFriendCheckResult(const V2TIMFriendCheckResult& friendCheckResult);
    ~V2TIMFriendCheckResult();
};

DEFINE_VECTOR(V2TIMFriendCheckResult)
typedef TXV2TIMFriendCheckResultVector V2TIMFriendCheckResultVector;

/// Definition of V2TIMFriendOperationResult
struct TIM_API V2TIMFriendOperationResult {
    /// Friend's ID
    V2TIMString userID;
    /// Result code
    int32_t resultCode;
    /// Result description
    V2TIMString resultInfo;

    V2TIMFriendOperationResult();
    V2TIMFriendOperationResult(const V2TIMFriendOperationResult& friendOperationResult);
    ~V2TIMFriendOperationResult();
};

DEFINE_VECTOR(V2TIMFriendOperationResult)
typedef TXV2TIMFriendOperationResultVector V2TIMFriendOperationResultVector;

/// Definition of V2TIMFriendGroup
struct TIM_API V2TIMFriendGroup {
    /// Friend group nam
    V2TIMString groupName;
    /// Number of members in the friend group
    uint64_t userCount;
    /// Members information in the friend group
    V2TIMStringVector friendList;

    V2TIMFriendGroup();
    V2TIMFriendGroup(const V2TIMFriendGroup& friendGroup);
    ~V2TIMFriendGroup();
};

DEFINE_VECTOR(V2TIMFriendGroup)
typedef TXV2TIMFriendGroupVector V2TIMFriendGroupVector;

//  Definition of V2TIMFriendSearchParam
struct TIM_API V2TIMFriendSearchParam {
    /// Keyword list for search. The keyword list can contain up to 5 keywords.
    V2TIMStringVector keywordList;
    /// Whether to search by userID
    bool isSearchUserID;
    /// Whether to search by nickname
    bool isSearchNickName;
    /// Whether to search by remarks
    bool isSearchRemark;

    V2TIMFriendSearchParam();
    V2TIMFriendSearchParam(const V2TIMFriendSearchParam& friendSearchParam);
    ~V2TIMFriendSearchParam();
};

#endif /* __V2TIM_FRIENDSHIP_H__ */
