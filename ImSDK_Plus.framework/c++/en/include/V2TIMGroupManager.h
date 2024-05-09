// Copyright (c) 2021 Tencent. All rights reserved.

/////////////////////////////////////////////////////////////////////
//
//                     Tencent Cloud Instant Messaging SDK
//
//  Advanced group APIs, including APIs for advanced group features such as group member invitation and group joining request
//
/////////////////////////////////////////////////////////////////////

#ifndef __V2TIM_GROUP_MANAGER_H__
#define __V2TIM_GROUP_MANAGER_H__

#include "V2TIMCallback.h"
#include "V2TIMDefine.h"
#include "V2TIMGroup.h"
#include "V2TIMListener.h"

/**
 * ## Advanced group APIs, including APIs for advanced group features such as group member invitation and group joining request
 */
class TIM_API V2TIMGroupManager {
public:
    virtual ~V2TIMGroupManager() {}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                         Advanced group APIs
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     *  1.1 Create a custom group (the advanced version API allows you to specify initial group members)
     *
     * @param info       Custom group information, including the groupID, groupType, groupName, notification, introduction, and faceURL fields
     * @param memberList Specify initial group members (Audio-video groups do not support specifying initial group members. Pass in null for memberList.)
     *
     * @note For other limits, please see @ref V2TIMManager.h -> CreateGroup remarks
     */
    virtual void CreateGroup(const V2TIMGroupInfo& info,
                             const V2TIMCreateGroupMemberInfoVector& memberList,
                             V2TIMValueCallback<V2TIMString>* callback) = 0;

    /**
     * 1.2 Get the list of groups that the current user has joined
     *
     * @note
     *  - Audio-video groups (AVChatRoom) do not support this API.
     *  - This API implements frequency limit checks. It can be called by the SDK for up to 10 times per second. When the limit is exceeded, the error ERR_SDK_COMM_API_CALL_FREQUENCY_LIMIT (7008) is reported.
     */
    virtual void GetJoinedGroupList(V2TIMValueCallback<V2TIMGroupInfoVector>* callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //                         Group profile and advanced settings
    /////////////////////////////////////////////////////////////////////////////////

    /**
     *  2.1 Pull group profiles
     *
     *  @param groupIDList List of group IDs
     */
    virtual void GetGroupsInfo(const V2TIMStringVector& groupIDList,
                               V2TIMValueCallback<V2TIMGroupInfoResultVector>* callback) = 0;

    /**
     * 2.2 Search for group profiles (supported only in 5.4.666 and later versions and need to buy Flagship Edition)
     *
     * This API will search all the groups whose group name is included in the keyword list specifed in searchParam and return the group profiles list. The keyword list supports up to 5 keywords.
     * @param searchParam Search parameters
     */
    virtual void SearchGroups(const V2TIMGroupSearchParam& searchParam,
                              V2TIMValueCallback<V2TIMGroupInfoVector>* callback) = 0;

    /**
     * 2.3 Modify group profiles
     */
    virtual void SetGroupInfo(const V2TIMGroupInfo& info, V2TIMCallback* callback) = 0;

    /**
     * 2.4 Initialize group attributes (this operation will clear the existing group attribute list)
     *
     * @note
     * Use limits of attributes:：
     *  - Group attribute is supported only for audio-video groups (AVChatRoom) by 6.7 and earlier versions.
     *  - Group attribute is supported for 4 group types (AVChatRoom、Public、Meeting、Work groups) at the same time in 6.8 and later versions.
     *  - Group attribute is supported for all group types except topics in 7.0 and later versions.
     *  - Up to 16 keys are supported, with a length limit of 32 bytes.
     *  - The length limit for value is 4 KB.
     *  - The total length limit for attributes (including keys and values) is 16 KB.
     *  - The initGroupAttributes, setGroupAttributes, and deleteGroupAttributes APIs each can be called by the SDK for up to 10 times per 5 seconds, and the 8511 error code will be called back if the limit is exceeded. The APIs each can be called by the backend for up to 5 times per second, and the 10049 error code will be called back if the limit is exceeded.
     *  - The getGroupAttributes API can be called by the SDK for up to 20 times per 5 seconds.
     *  - Starting from version 5.6, when you modify group attributes for the first time after the app is started, please call getGroupAttributes to pull the latest group attributes before you initiate the modification operation.
     *  - Starting from version 5.6, when multiple users modify the same group attributes at the same time, only the first user can execute successfully, and other users will receive the 10056 error code. After receiving this error code, please call getGroupAttributes to update the locally stored group attributes to the latest before you initiate the modification operation.
     */
    virtual void InitGroupAttributes(const V2TIMString& groupID,
                                     const V2TIMGroupAttributeMap& attributes,
                                     V2TIMCallback* callback) = 0;

    /**
     * 2.5 Set group attributes. (If the group attributes already exist, their values are updated. Otherwise, the group attributes are added.)
     * @note
     *  - Group attribute is supported only for audio-video groups (AVChatRoom) by 6.7 and earlier versions.
     *  - Group attribute is supported for 4 group types (AVChatRoom、Public、Meeting、Work groups) at the same time in 6.8 and later versions.
     *  - Group attribute is supported for all group types except topics in 7.0 and later versions.
     */
    virtual void SetGroupAttributes(const V2TIMString& groupID,
                                    const V2TIMGroupAttributeMap& attributes,
                                    V2TIMCallback* callback) = 0;

    /**
     * 2.6 Delete specified group attributes (If size 0 is passed in for keys, all group attributes are cleared.)
     * @note
     *  - Group attribute is supported only for audio-video groups (AVChatRoom) by 6.7 and earlier versions.
     *  - Group attribute is supported for 4 group types (AVChatRoom、Public、Meeting、Work groups) at the same time in 6.8 and later versions.
     *  - Group attribute is supported for all group types except topics in 7.0 and later versions.
     */
    virtual void DeleteGroupAttributes(const V2TIMString& groupID, const V2TIMStringVector& keys,
                                       V2TIMCallback* callback) = 0;

    /**
     * 2.7 Get specified group attributes (If size 0 is passed in for keys, all group attributes are obtained.)
     * @note
     *  - Group attribute is supported only for audio-video groups (AVChatRoom) by 6.7 and earlier versions.
     *  - Group attribute is supported for 4 group types (AVChatRoom、Public、Meeting、Work groups) at the same time in 6.8 and later versions.
     *  - Group attribute is supported for all group types except topics in 7.0 and later versions.
     */
    virtual void GetGroupAttributes(const V2TIMString& groupID, const V2TIMStringVector& keys,
                                    V2TIMValueCallback<V2TIMGroupAttributeMap>* callback) = 0;

    /**
     * 2.8 Get the number of online members of a group
     *
     * @note Notes:
     *  - Currently, this API is supported only by audio-video groups (AVChatRoom).
     *  - This API implements frequency limit checks. It can be called by the SDK for up to once per 60 seconds.
     */
    virtual void GetGroupOnlineMemberCount(const V2TIMString& groupID,
                                           V2TIMValueCallback<uint32_t>* callback) = 0;

    /**
     * 2.9 Set group counters (supported only in 7.0 and later versions)
     *
     * @note
     *  - If the group counters already exist, their values will be updated. Otherwise, the group counters will be added.
     *  - When group counter is set successfully, their newest information will be returned in the succ callback.
     *  - Group counter is supported for all group types except community and topics.
     */
    virtual void SetGroupCounters(const V2TIMString& groupID, const V2TIMStringToInt64Map& counters,
                                  V2TIMValueCallback<V2TIMStringToInt64Map>* callback) = 0;

    /**
     * 2.10 Get group counters (supported only in 7.0 and later versions)
     *
     * @note
     *  - If keys is empty or nil, it means to obtain all counters in the group.
     *  - Group counter is supported for all group types except community and topics.
     */
    virtual void GetGroupCounters(const V2TIMString& groupID, const V2TIMStringVector& keys,
                                  V2TIMValueCallback<V2TIMStringToInt64Map>* callback) = 0;

    /**
     * 2.11 Increase group counters (supported only in 7.0 and later versions)
     *
     * @param groupID Group ID
     * @param key The key of counter
     * @param value Increment of group counter, the value will be updated as new_value = old_value + value
     * @param succ Callback of success，returns the value of the current counter after increment
     * @param fail Callback of failure
     *
     * @note
     *  - If the key of the counters specified by the parameters already exist, their values will be increased directly according to the parameters. Otherwise, new counters will be added firstly with value 0, then their value will be increased by the  parameters.
     *  - Group counter is supported for all group types except community and topics.
     */
    virtual void IncreaseGroupCounter(const V2TIMString& groupID,
                                      const V2TIMString& key, int64_t value,
                                      V2TIMValueCallback<V2TIMStringToInt64Map>* callback) = 0;

    /**
     * 2.12 Decrease group counters (supported only in 7.0 and later versions)
     *
     * @param groupID Group ID
     * @param key The key of counter
     * @param value Decrement of group counter,  the value will be updated as new_value = old_value - value
     * @param succ Callback of success，returns the value of the current counter after decrement
     * @param fail Callback of failure
     *
     * @note
     *  - If the key of the counters specified by the parameters already exist, their values will be decreased directly according to the parameters. Otherwise, new counters will be added firstly with value 0, then their value will be decreased by the  parameters.
     *  - Group counter is supported for all group types except community and topics.
     */
    virtual void DecreaseGroupCounter(const V2TIMString& groupID,
                                      const V2TIMString& key, int64_t value,
                                      V2TIMValueCallback<V2TIMStringToInt64Map>* callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //                         Group member management
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 3.1 Get the group member list
     *
     * @param filter   Specify the group member type
     * @param nextSeq  Pulling-by-page flag. It is set to 0 when the information is pulled for
     *                 the first time. If the callback succeeds and nextSeq is not 0,
     *                 pagination is needed. The value of this field is passed in for
     *                 the next pull until the value becomes 0.
     *
     *  @note
     *  - Restrictions for normal groups(Work, Meeting, Public, Community):
     *  1. The filter field can only be set to the value defined in V2TIMGroupMemberFilter,
     *    then you can get the members of the corresponding role.
     * 
     *  - Restrictions for audio-video groups(AVChatRoom):
     *  1. If you set the filter to the value defined in V2TIMGroupMemberFilter, you will
     *    get all the members. The maximum number of group members supported
     *    in Flagship Edition is 1000, new members will be placed at the top of the list.
     *    You need to login in [IM Console] (https://console.cloud.tencent.com/im) to
     *    enable this feature. If you don't enable, you will still get 31 members
     *    at the most like the Non-Flagship (supported only in 6.3 and later versions).
     *    The maximum number of group members supported in Non-Flagship Edition is 31,
     *    new members will be placed at the top of the list.
     *  2. If you set the filter to custom markType defined by yourself, you can get the members of
     *    the corresponding markType in the Flagship Edition. 
     *    Please refer to the API MarkGroupMemberList.
     *  3. After the app is restarted, please join the group again. Otherwise,
     *    the 10007 error code will be reported when you pull the group member list.
     *  4. Only the following fields are supported in group member profiles:
     *    userID, nickName, faceURL, and role.
     */
    virtual void GetGroupMemberList(const V2TIMString& groupID, uint32_t filter,
                                    uint64_t nextSeq,
                                    V2TIMValueCallback<V2TIMGroupMemberInfoResult>* callback) = 0;

    /**
     * 3.2 Get the profiles of specified group members
     */
    virtual void GetGroupMembersInfo(
        const V2TIMString& groupID, V2TIMStringVector memberList,
        V2TIMValueCallback<V2TIMGroupMemberFullInfoVector>* callback) = 0;

    /**
     * 3.3 Search for group members (supported only in 5.4.666 and later versions and need to buy Flagship Edition)
     *
     * @param param Search parameters
     */
    virtual void SearchGroupMembers(
        const V2TIMGroupMemberSearchParam& param,
        V2TIMValueCallback<V2TIMGroupSearchGroupMembersMap>* callback) = 0;

    /**
     * 3.4 Modify the profiles of specified group members
     */
    virtual void SetGroupMemberInfo(const V2TIMString& groupID,
                                    const V2TIMGroupMemberFullInfo& info,
                                    V2TIMCallback* callback) = 0;

    /**
     * 3.5 Mute (this API can be called by the admin or group owner)
     *
     * @param seconds Time period in seconds from calling this API which indicates how many seconds the mute user will be forbidden to speak.
     */
    virtual void MuteGroupMember(const V2TIMString& groupID, const V2TIMString& userID,
                                 uint32_t seconds,
                                 V2TIMCallback* callback) = 0;

    /**
     * 3.6 Invite users to a group
     *
     * @note The limits for different types of groups are as follows:
     *  - Work group (Work): anyone in the group can invite others to the group.
     *  - Meeting group (Meeting) and public group (Public): only the app admin can invite others to the group via the RESTful API.
     *  - Audio-video group (AVChatRoom): inviting users to a group is not supported.
     */
    virtual void InviteUserToGroup(
        const V2TIMString& groupID, const V2TIMStringVector& userList,
        V2TIMValueCallback<V2TIMGroupMemberOperationResultVector>* callback) = 0;

    /**
     *  3.7 Remove a member from a group(Removing a member from AVChatRoom is supported only in 6.6 and later versions and need to buy Flagship Edition)
     *
     *  @note The limits for different types of groups are as follows:
     * - Work group (Work): only the group owner or app admin can remove a member from a group.
     * - Meeting group (Meeting) and public group (Public): the group owner, group admin, and app admin can remove a member from a group.
     * - Audio-video group (AVChatRoom): only muting(MuteGroupMember) is supported in versions prior to 6.6. Both muting(MuteGroupMember) and kicking(KickGroupMember) are supported in 6.6 and later versions.
     */
    virtual void KickGroupMember(
        const V2TIMString& groupID, const V2TIMStringVector& memberList, const V2TIMString& reason,
        V2TIMValueCallback<V2TIMGroupMemberOperationResultVector>* callback) = 0;

    /**
     *  3.8 Set the role of a group member
     *
     *  @note The limits for different types of groups are as follows:
     *  - Meeting group (Meeting) and public group (Public): only the group owner can switch the role of a group member between common member and admin.
     *  - Other types of groups do not support group member role setting.
     *  - To transfer a group, please call the @ref transferGroupOwner API.
     *  - For a meeting group (Meeting), after a group member role is set, there will be no onGrantAdministrator or onRevokeAdministrator callback.
     *  - Roles that can be set are common member (V2TIM_GROUP_MEMBER_ROLE_MEMBER) and admin (V2TIM_GROUP_MEMBER_ROLE_ADMIN).
     */
    virtual void SetGroupMemberRole(const V2TIMString& groupID, const V2TIMString& userID,
        uint32_t role, V2TIMCallback* callback) = 0;

    /**
     *  3.9 Set or remove the custom roles of group member(supported only in 6.6 and
     *  later versions and need to buy Flagship Edition)
     *
     *  @param groupID Group's identifier.
     *  @param memberList Group member's identifier list.
     *  @param markType The mark type is uint32_t, and the value must be equal or greater than 1000.
     *  You can customize it. A maximum of 10 marks are allowed to be defined in an AVChatRoom.
     *  @param enableMark Set or remove. true means setting the mark, and false means removing the mark.
     *
     *  @note Attention please:
     *  - Only supported in Audio-video group (AVChatRoom).
     *  - Only the group owner has permission to mark other members in the group.
     */
    virtual void MarkGroupMemberList(const V2TIMString& groupID,
        const V2TIMStringVector& memberList, uint32_t markType,
        bool enableMark, V2TIMCallback* callback) = 0;

    /**
     *  3.10 Change the group owner
     *
     *  @note The limits for different types of groups are as follows:
     *  - Common groups (Work, Public, and Meeting): only the group owner has the permission to change the group owner.
     *  - Audio-video group (AVChatRoom): changing the group owner is not supported.
     */
    virtual void TransferGroupOwner(const V2TIMString& groupID, const V2TIMString& userID,
                                    V2TIMCallback* callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                         Group joining request
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 4.1 Get the group joining request list
     * @note Up to 50 requests are supported
     */
    virtual void GetGroupApplicationList(
        V2TIMValueCallback<V2TIMGroupApplicationResult>* callback) = 0;

    /**
     * 4.2 Approve a group joining request
     */
    virtual void AcceptGroupApplication(const V2TIMGroupApplication& application,
                                        const V2TIMString& reason, V2TIMCallback* callback) = 0;

    /**
     * 4.3 Reject a group joining request
     */
    virtual void RefuseGroupApplication(const V2TIMGroupApplication& application,
                                        const V2TIMString& reason, V2TIMCallback* callback) = 0;

    /**
     * 4.4 Mark the group joining request list as read
     */
    virtual void SetGroupApplicationRead(V2TIMCallback* callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                         Community-Topic
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 5.1 Get the list of Community-groups that the current user has joined
     */
    virtual void GetJoinedCommunityList(V2TIMValueCallback<V2TIMGroupInfoVector> *callback) = 0;

    /**
     * 5.2 Create topic
     */
    virtual void CreateTopicInCommunity(const V2TIMString &groupID, const V2TIMTopicInfo &topicInfo,
        V2TIMValueCallback<V2TIMString> *callback) = 0;

    /**
     * 5.3 Delete topic
     */
    virtual void DeleteTopicFromCommunity(const V2TIMString &groupID,
        const V2TIMStringVector &topicIDList,
        V2TIMValueCallback<V2TIMTopicOperationResultVector> *callback) = 0;

    /**
     * 5.4 Modify topic information
     */
    virtual void SetTopicInfo(const V2TIMTopicInfo &topicInfo, V2TIMCallback *callback) = 0;

    /**
     * 5.5 Get topic list
     * @note: When the topicIDList is empty，it means to get the list of all topics in this Community.
     */
    virtual void GetTopicInfoList(const V2TIMString &groupID, const V2TIMStringVector &topicIDList,
        V2TIMValueCallback<V2TIMTopicInfoResultVector> *callback) = 0;

};

#endif  // __V2TIM_GROUP_MANAGER_H__
