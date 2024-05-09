// Copyright (c) 2022 Tencent. All rights reserved.

/////////////////////////////////////////////////////////////////////
//
//                     Tencent Cloud Instant Messaging SDK
//
//                            APIs for offline push
//
/////////////////////////////////////////////////////////////////////

#ifndef __V2TIM_OFFLINE_PUSH_MANAGER_H__ 
#define __V2TIM_OFFLINE_PUSH_MANAGER_H__ 

#include "V2TIMCallback.h"
#include "V2TIMDefine.h"
#include "V2TIMListener.h"
#include "V2TIMMessage.h"

class V2TIMOfflinePushManager  {
public:
    virtual ~V2TIMOfflinePushManager () {}

    /**
     * Set offline push configuration
     * Note:
     *  - To disable offline push, set config to SetOfflinePushConfig().
     * @param config   Offline push configuration
     * @param callback   Callback
     */
    virtual void SetOfflinePushConfig(const V2TIMOfflinePushConfig &config, V2TIMCallback *callback) = 0;

    /**
     * This API can be called when the app detects that the app switches to the background. It can be used to specify the initial unread count of the desktop badge.
     *
     * - Starting from version 6.1, if offline push is configured, users can receive notification bar messages delivered by vendors or TPNS via the offline push channel.
     *
     * @param unreadCount   Unread count
     * @param callback   Callback
     */
    virtual void DoBackground(uint32_t unreadCount, V2TIMCallback *callback) = 0;

    /**
     * This API can be called when the app detects that the app switches to the foreground.
     *
     * - Starting from version 6.1, in contrast to DoBackground, this API stops offline pushes. However, if the app is killed, users can still receive offline pushes properly.
     *
     * @param callback   Callback
     */
    virtual void DoForeground(V2TIMCallback *callback) = 0;
};

#endif  // __V2TIM_OFFLINE_PUSH_MANAGER_H__ 
