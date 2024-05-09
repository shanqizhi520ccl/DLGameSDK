// Copyright (c) 2021 Tencent. All rights reserved.

/////////////////////////////////////////////////////////////////////////////////
//
//                          IMSDK API callback class
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef __V2TIM_CALLBACK_H__
#define __V2TIM_CALLBACK_H__

#include "V2TIMDefine.h"
#include "V2TIMString.h"
#include "V2TIMMessage.h"

/////////////////////////////////////////////////////////////////////////////////
//
//                         Callback base class
//
/////////////////////////////////////////////////////////////////////////////////

class TIM_API V2TIMBaseCallback {
public:
    V2TIMBaseCallback();
    virtual ~V2TIMBaseCallback();
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         Common callback class
//
/////////////////////////////////////////////////////////////////////////////////

class V2TIMCallback : public V2TIMBaseCallback {
public:
    ~V2TIMCallback() override {}

    /**
     * Callback on success
     */
    virtual void OnSuccess() = 0;

    /**
     * Callback on failure
     *
     * @param error_code Error code (see the error code table for details)
     * @param error_message Error description
     */
    virtual void OnError(int error_code, const V2TIMString &error_message) = 0;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         Template callback class
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
class V2TIMValueCallback : public V2TIMBaseCallback {
public:
    ~V2TIMValueCallback() override {}

    /**
     * Callback on success，with parameter of type T
     */
    virtual void OnSuccess(const T &value) = 0;

     /**
     * Callback on failure
     *
     * @param error_code Error code (see the error code table for details)
     * @param error_message Error description
     */
    virtual void OnError(int error_code, const V2TIMString &error_message) = 0;
};

/////////////////////////////////////////////////////////////////////////////////
//
///                     Definition of V2TIMDownloadCallback
//
/////////////////////////////////////////////////////////////////////////////////

class V2TIMDownloadCallback : public V2TIMCallback {
public:
    ~V2TIMDownloadCallback() override {}

    /**
     * File download progress
     * 
     * @note Progress information
     */
    virtual void OnDownLoadProgress(uint64_t currentSize, uint64_t totalSize) = 0;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                    Definition of V2TIMSendCallback
//
/////////////////////////////////////////////////////////////////////////////////

class V2TIMSendCallback : public V2TIMValueCallback<V2TIMMessage> {
public:
    ~V2TIMSendCallback() override {}

    /**
     * File message sending progress
     * 
     * @note Progress
     */
    virtual void OnProgress(uint32_t progress) = 0;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMCompleteCallback
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
class V2TIMCompleteCallback : public V2TIMBaseCallback {
public:
    ~V2TIMCompleteCallback() override {}

    /**
     * complete callback
     */
    virtual void OnComplete(int error_code, const V2TIMString &error_message, const T &value) = 0;
};

#endif /* __V2TIM_CALLBACK_H__ */
