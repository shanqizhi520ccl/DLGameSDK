// Copyright (c) 2021 Tencent. All rights reserved.

/////////////////////////////////////////////////////////////////////
//
//                      Tencent Cloud Instant Messaging SDK
//
//  Advanced relationship APIs, including the APIs for adding and deleting friends as well as blocklisting/unblocklisting
//
/////////////////////////////////////////////////////////////////////

#ifndef __V2TIM_FRIENDSHIP_MANAGER_H__
#define __V2TIM_FRIENDSHIP_MANAGER_H__

#include "V2TIMCallback.h"
#include "V2TIMDefine.h"
#include "V2TIMFriendship.h"
#include "V2TIMListener.h"

class TIM_API V2TIMFriendshipManager {
public:
    virtual ~V2TIMFriendshipManager() {}

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                          Relationship chain and user profile listener
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 1.1 Add the relationship chain listener
     */
    virtual void AddFriendListener(V2TIMFriendshipListener* listener) = 0;

    /**
     * 1.2 Remove the relationship chain listener
     */
    virtual void RemoveFriendListener(V2TIMFriendshipListener* listener) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                       Friend addition and deletion, list getting, and profile setting APIs
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 2.1 Get the friend list
     */
    virtual void GetFriendList(V2TIMValueCallback<V2TIMFriendInfoVector>* callback) = 0;

    /**
     * 2.2 Get the profiles of specified friends
     *
     * @param userIDList List of friends' userIDs
     *                   - You are advised to obtain a maximum of 100 user IDs at a time. A larger number may cause the request to be rejected by the backend due to an excessively large data packet. The maximum size of a data packet supported by the backend is 1 MB.
     */
    virtual void GetFriendsInfo(const V2TIMStringVector& userIDList,
                                V2TIMValueCallback<V2TIMFriendInfoResultVector>* callback) = 0;

    /**
     * 2.3 Set the profile of a specified friend
     */
    virtual void SetFriendInfo(const V2TIMFriendInfo& info, V2TIMCallback* callback) = 0;

    /**
     * 2.4 Search for friends (supported only in 5.4.666 and later versions and need to buy Flagship Edition)
     */
    virtual void SearchFriends(const V2TIMFriendSearchParam& searchParam,
                               V2TIMValueCallback<V2TIMFriendInfoResultVector>* callback) = 0;

    /**
     * 2.5  Add a friend
     */
    virtual void AddFriend(const V2TIMFriendAddApplication& application,
                           V2TIMValueCallback<V2TIMFriendOperationResult>* callback) = 0;

    /**
     * 2.6  Delete friends
     *
     * @param userIDList List of the friend userIDs to be deleted
     *                   - You are advised to obtain a maximum of 100 user IDs at a time. A larger number may cause the request to be rejected by the backend due to an excessively large data packet. The maximum size of a data packet supported by the backend is 1 MB.
     * @param deleteType Deletion type
     *                   - @ref V2TIM_FRIEND_TYPE_SINGLE： one-way friend
     *                   - @ref V2TIM_FRIEND_TYPE_BOTH：two-way friend
     */
    virtual void DeleteFromFriendList(
        const V2TIMStringVector& userIDList, V2TIMFriendType deleteType,
        V2TIMValueCallback<V2TIMFriendOperationResultVector>* callback) = 0;

    /**
     * 2.7 Check your relationships with specified users
     *
     *  @param userIDList List of the userIDs to be checked
     *  @param checkType Check type (one-way or two-way friend check)
     *
     *  @note  Notes for using checkType:
     *  - If V2TIM_FRIEND_TYPE_SINGLE is passed in for checkType, the possible results are V2TIM_FRIEND_RELATION_TYPE_NONE and V2TIM_FRIEND_RELATION_TYPE_IN_MY_FRIEND_LIST.
     *  - If V2TIM_FRIEND_TYPE_BOTH is passed in for checkType, the possible results are V2TIM_FRIEND_RELATION_TYPE_NONE, V2TIM_FRIEND_RELATION_TYPE_IN_MY_FRIEND_LIST, V2TIM_FRIEND_RELATION_TYPE_IN_OTHER_FRIEND_LIST, and V2TIM_FRIEND_RELATION_TYPE_BOTH_WAY. V2TIM_FRIEND_RELATION_TYPE_IN_OTHER_FRIEND_LIST、V2TIM_FRIEND_RELATION_TYPE_BOTH_WAY 
     */
    virtual void CheckFriend(const V2TIMStringVector& userIDList, V2TIMFriendType checkType,
                             V2TIMValueCallback<V2TIMFriendCheckResultVector>* callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                          Friend request and deletion APIs
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     *  3.1 Get the friend request list
     *
     *  @note
     *   - The friend request list includes the friend requests sent and received by yourself.
     *   - Up to 100 requests are supported.
     */
    virtual void GetFriendApplicationList(
        V2TIMValueCallback<V2TIMFriendApplicationResult>* callback) = 0;

    /**
     * 3.2 Accept friend requests
     *
     * @param application  Friend request information, which will be returned when calling getFriendApplicationList is successful
     * @param responseType Build one-way or two-way friend relationships
     */
    virtual void AcceptFriendApplication(
        const V2TIMFriendApplication& application, V2TIMFriendAcceptType acceptType,
        V2TIMValueCallback<V2TIMFriendOperationResult>* callback) = 0;

    /**
     * 3.3 Reject friend requests
     *
     * @param application Friend request information, which will be returned when calling @ref GetFriendApplicationList is successful
     */
    virtual void RefuseFriendApplication(
        const V2TIMFriendApplication& application,
        V2TIMValueCallback<V2TIMFriendOperationResult>* callback) = 0;

    /**
     * 3.4 Delete friend requests
     *
     * @param application Friend request information, which will be returned when calling @ref GetFriendApplicationList is successful
     */
    virtual void DeleteFriendApplication(const V2TIMFriendApplication& application,
                                         V2TIMCallback* callback) = 0;

    /**
     * 3.5 Set a friend request as read
     */
    virtual void SetFriendApplicationRead(V2TIMCallback* callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                          Blocklist APIs
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 4.1 Add users to the blocklist
     */
    virtual void AddToBlackList(const V2TIMStringVector& userIDList,
                                V2TIMValueCallback<V2TIMFriendOperationResultVector>* callback) = 0;

    /**
     * 4.2 Delete users from the blocklist
     */
    virtual void DeleteFromBlackList(
        const V2TIMStringVector& userIDList,
        V2TIMValueCallback<V2TIMFriendOperationResultVector>* callback) = 0;

    /**
     * 4.3 Get the blocklist
     */
    virtual void GetBlackList(V2TIMValueCallback<V2TIMFriendInfoVector>* callback) = 0;

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                          Friend group APIs
    //
    /////////////////////////////////////////////////////////////////////////////////

    /**
     * 5.1 Create a friend group
     *
     * @param groupName  Friend group name
     * @param userIDList List of the friend userIDs to be added to the friend group
     */
    virtual void CreateFriendGroup(
        const V2TIMString& groupName, const V2TIMStringVector& userIDList,
        V2TIMValueCallback<V2TIMFriendOperationResultVector>* callback) = 0;

    /**
     * 5.2 Get friend group information
     *
     * @param groupNameList List of the names of the friend groups whose information is to be obtained. If null is passed in, the information of all friend groups is obtained.
     */
    virtual void GetFriendGroups(const V2TIMStringVector& groupNameList,
                                 V2TIMValueCallback<V2TIMFriendGroupVector>* callback) = 0;

    /**
     * 5.3 Delete friend groups
     */
    virtual void DeleteFriendGroup(const V2TIMStringVector& groupNameList,
                                   V2TIMCallback* callback) = 0;

    /**
     * 5.4 Modify the name of a friend group
     *
     * @param oldName  old group name
     * @param newName  new group name
     * @param callback callback
     */
    virtual void RenameFriendGroup(const V2TIMString& oldName, const V2TIMString& newName,
                                   V2TIMCallback* callback) = 0;

    /**
     * 5.5 Add friends to a friend group
     */
    virtual void AddFriendsToFriendGroup(
        const V2TIMString& groupName, const V2TIMStringVector& userIDList,
        V2TIMValueCallback<V2TIMFriendOperationResultVector>* callback) = 0;

    /**
     * 5.6 Delete friends from a friend group
     */
    virtual void DeleteFriendsFromFriendGroup(
        const V2TIMString& groupName, const V2TIMStringVector& userIDList,
        V2TIMValueCallback<V2TIMFriendOperationResultVector>* callback) = 0;
};

#endif  // __V2TIM_FRIENDSHIP_MANAGER_H__
