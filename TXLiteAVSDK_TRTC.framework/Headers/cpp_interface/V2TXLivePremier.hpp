/**
 * Copyright (c) 2021 Tencent. All rights reserved.
 * Module:   V2TXLivePremier @ TXLiteAVSDK
 * Function: V2TXLive High-level interface
 */
#ifndef MODULE_CPP_V2TXLIVE_PREMIER_H_
#define MODULE_CPP_V2TXLIVE_PREMIER_H_

#include "V2TXLiveDef.hpp"

namespace liteav {
class V2TXLivePremier;
#ifdef _WIN32
class V2TXLivePremierObserver;
#endif
}  // namespace liteav

/**
 * Export the following C-style interface to facilitate “LoadLibrary()”
 *
 * You can use the following methods to create and destroy V2TXLivePremier instance.
 * <pre>
 * V2TXLivePremier *pV2TXLivePremier = getV2TXLivePremierShareInstance();
 * if(pV2TXLivePremier) {
 *     std::string version(pV2TXLivePremier->getSDKVersionStr());
 * }
 * destroyV2TXLivePremierShareInstance();
 * pV2TXLivePremier = nullptr;
 * </pre>
 */
extern "C" {
V2_API liteav::V2TXLivePremier* getV2TXLivePremierShareInstance();
V2_API void destroyV2TXLivePremierShareInstance();
}

/////////////////////////////////////////////////////////////////////////////////
//
//                      V2TXLive High-level interface
//
/////////////////////////////////////////////////////////////////////////////////

namespace liteav {
class V2TXLivePremier {
   protected:
    virtual ~V2TXLivePremier() {
    }

   public:
    /**
     * Create `V2TXLivePremier` instance (singleton mode)
     *
     * @note
     * If you use `delete V2TXLivePremier*`, a compilation error will occur. Please use `如果您使用 delete V2TXLivePremier* 会导致编译错误，请使用 destroyV2TXLivePremier 释放对象指针。
     * ` to release the object pointer.
     */
    V2_API static liteav::V2TXLivePremier* getV2TXLivePremierShareInstance();

    /**
     * Terminate `V2TXLivePremier` instance (singleton mode)
     */
    V2_API static void destroyV2TXLivePremierShareInstance();

    /**
     * Get the SDK version number
     */
    virtual const char* getSDKVersionStr() = 0;

/**
 * Set V2TXLivePremier callback interface
 */
#ifdef _WIN32
    virtual void setObserver(V2TXLivePremierObserver* observer) = 0;
#endif

/**
 * Set Log configuration information
 */
#ifdef _WIN32
    virtual int32_t setLogConfig(const V2TXLiveLogConfig& config) = 0;
#endif

    /**
     * Set up SDK access environment
     *
     * @note If your application has no special requirements, please do not call this interface for setting.
     * @param env currently supports two parameters "default" and "GDPR".
     *        - default: In the default environment, the SDK will find the best access point in the world for access.
     *        - GDPR: All audio and video data and quality statistics will not pass through servers in mainland China.
     */
    virtual int32_t setEnvironment(const char* env) = 0;

/**
 * Set SDK sock5 proxy config
 *
 * @param host sock5 sock5 proxy host.
 * @param port sock5 sock5 proxy port.
 * @param username sock5 sock5 proxy username.
 * @param password sock5 sock5 proxy password.
 */
#ifdef _WIN32
    virtual int32_t setSocks5Proxy(const char* host, unsigned short port, const char* username, const char* password) = 0;
#endif

/**
 * Enables/Disables audio capture callback
 *
 * @param enable `true`: enable; `false` (**default**): disable.
 * @param format audio frame format.
 * @note This API works only if you call it before {@link startPush}.
 */
#ifdef _WIN32
    virtual int32_t enableAudioCaptureObserver(bool enable, const V2TXLiveAudioFrameObserverFormat& format) = 0;
#endif

    /**
     * Set user id
     *
     * @param userId User/device id maintained by the service side itself.
     */
    virtual void setUserId(const char* userId) = 0;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                      V2TXLive Advanced callback interface
//
/////////////////////////////////////////////////////////////////////////////////

#ifdef _WIN32
class V2TXLivePremierObserver {
   public:
    virtual ~V2TXLivePremierObserver() {
    }

    /**
     * Custom Log output callback interface
     */
    virtual void onLog(V2TXLiveLogLevel level, const char* log){};

    /**
     * Raw audio data captured locally
     *
     * @param frame Audio frames in PCM format.
     * @note
     * 1. Please avoid time-consuming operations in this callback function. The SDK processes an audio frame every 20 ms, so if your operation takes more than 20 ms, it will cause audio exceptions.
     * 2. The audio data returned via this callback can be read and modified, but please keep the duration of your operation short.
     * 3. The audio data returned via this callback **does not include** pre-processing effects like background music, audio effects, or reverb, and therefore has a very short delay.
     */
    virtual void onCaptureAudioFrame(V2TXLiveAudioFrame* frame){};
};
#endif

}  // namespace liteav
#endif
