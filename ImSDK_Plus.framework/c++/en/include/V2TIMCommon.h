// Copyright (c) 2021 Tencent. All rights reserved.

#ifndef __V2TIM_COMMON_H__
#define __V2TIM_COMMON_H__

#include "V2TIMBuffer.h"
#include "V2TIMDefine.h"
#include "V2TIMString.h"

/////////////////////////////////////////////////////////////////////////////////
//
//                    Enumeration definition
//
/////////////////////////////////////////////////////////////////////////////////

/// Login status
enum V2TIMLoginStatus {
    /// Logged in
    V2TIM_STATUS_LOGINED = 1,
    /// Logging in
    V2TIM_STATUS_LOGINING = 2,
    /// Logged out
    V2TIM_STATUS_LOGOUT = 3,
};

/// Log level
enum V2TIMLogLevel {
    /// Do not output any SDK logs
    V2TIM_LOG_NONE = 0,
    /// Output logs at the DEBUG, INFO, WARNING, and ERROR levels
    V2TIM_LOG_DEBUG = 3,
    /// Output logs at the INFO, WARNING, and ERROR levels
    V2TIM_LOG_INFO = 4,
    /// Output logs at the WARNING and ERROR levels
    V2TIM_LOG_WARN = 5,
    /// Output logs at the ERROR level
    V2TIM_LOG_ERROR = 6,
};

/// Message receive option
enum V2TIMReceiveMessageOpt {
    ///< Messages will be received when the user is online, and offline push notifications will be received when the user is offline
    V2TIM_RECEIVE_MESSAGE = 0,
    ///< No message will be received
    V2TIM_NOT_RECEIVE_MESSAGE = 1,
    ///< Messages will be received when the user is online, and no push notification will be received when the user is offline
    V2TIM_RECEIVE_NOT_NOTIFY_MESSAGE = 2,
};

/////////////////////////////////////////////////////////////////////////////////
//
//                      Struct definition
//
/////////////////////////////////////////////////////////////////////////////////

DEFINE_VECTOR(V2TIMString)
typedef TXV2TIMStringVector V2TIMStringVector;

DEFINE_MAP(V2TIMString, V2TIMBuffer)
typedef TXV2TIMStringToV2TIMBufferMap V2TIMCustomInfo;

DEFINE_MAP(V2TIMString, V2TIMString)
typedef TXV2TIMStringToV2TIMStringMap V2TIMStringToV2TIMStringMap;
typedef TXV2TIMStringToV2TIMStringMap V2TIMGroupAttributeMap;

DEFINE_MAP(V2TIMString, int64_t)
typedef TXV2TIMStringToint64_tMap V2TIMStringToInt64Map;

class V2TIMLogListener;

struct TIM_API V2TIMBaseObject {
    void *obj_ptr;

    V2TIMBaseObject();
    V2TIMBaseObject(const V2TIMBaseObject &);
    virtual ~V2TIMBaseObject();
};

///  Definition of V2TIMSDKConfig
struct TIM_API V2TIMSDKConfig {
    /// Initialize path, must be set in for Android platform, optional for other platforms.
    V2TIMString initPath;

    /// log path，must be set in for Android platform, optional for other platforms
    V2TIMString logPath;

    /// Log level to write file. Its default value is DEBUG.
    V2TIMLogLevel logLevel;

    /// Log callback listener. The callback is in the main thread. Log callbacks can be quite frequent, so be careful not to do too many time-consuming tasks in the callback, which may block the main thread.
    V2TIMLogListener *logListener;

    V2TIMSDKConfig();
    V2TIMSDKConfig(const V2TIMSDKConfig &);
    ~V2TIMSDKConfig();
};

#endif /* __V2TIM_COMMON_H__ */
