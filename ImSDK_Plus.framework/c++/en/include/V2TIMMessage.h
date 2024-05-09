// Copyright (c) 2021 Tencent. All rights reserved.

#ifndef __V2TIM_MESSAGE_H__
#define __V2TIM_MESSAGE_H__

#include "V2TIMCommon.h"
#include "V2TIMGroup.h"

/////////////////////////////////////////////////////////////////////////////////
//
//                    Enumeration definition
//
/////////////////////////////////////////////////////////////////////////////////

/// Message priority
enum V2TIMMessagePriority {
    /// Defaulted to normal priority
    V2TIM_PRIORITY_DEFAULT = 0,
    /// High priority, usually used for important messages such as gift messages
    V2TIM_PRIORITY_HIGH = 1,
    /// Normal priority, usually used for common messages
    V2TIM_PRIORITY_NORMAL = 2,
    /// Low priority, usually used for like messages
    V2TIM_PRIORITY_LOW = 3,
};

/// Message status
enum V2TIMMessageStatus {
    ///< Message being sent
    V2TIM_MSG_STATUS_SENDING = 1,
    ///< Message sent successfully
    V2TIM_MSG_STATUS_SEND_SUCC = 2,
    ///< Message fails to be sent
    V2TIM_MSG_STATUS_SEND_FAIL = 3,
    ///< Message deleted
    V2TIM_MSG_STATUS_HAS_DELETED = 4,
    ///< Message imported to local storage
    V2TIM_MSG_STATUS_LOCAL_IMPORTED = 5,
    ///< Message revoked
    V2TIM_MSG_STATUS_LOCAL_REVOKED = 6,
};

/// Message element type
enum V2TIMElemType {
    ///< No element
    V2TIM_ELEM_TYPE_NONE = 0,
    ///< Text message
    V2TIM_ELEM_TYPE_TEXT = 1,
    ///< Custom message
    V2TIM_ELEM_TYPE_CUSTOM = 2,
    ///< Image message
    V2TIM_ELEM_TYPE_IMAGE = 3,
    ///< Voice message
    V2TIM_ELEM_TYPE_SOUND = 4,
    ///< Video message
    V2TIM_ELEM_TYPE_VIDEO = 5,
    ///< File message
    V2TIM_ELEM_TYPE_FILE = 6,
    ///< Geographical location message
    V2TIM_ELEM_TYPE_LOCATION = 7,
    ///< Emoji message
    V2TIM_ELEM_TYPE_FACE = 8,
    ///< Group tip message
    V2TIM_ELEM_TYPE_GROUP_TIPS = 9,
    ///< Forward message
    V2TIM_ELEM_TYPE_MERGER = 10,
};

DEFINE_VECTOR(V2TIMElemType)
typedef TXV2TIMElemTypeVector V2TIMElemTypeVector;

/// Offline push flag
enum V2TIMOfflinePushFlag {
    ///< Push mesage when offline according to the default rules
    V2TIM_OFFLINE_PUSH_DEFAULT = 0,
    ///< Don't push mesage when offline
    V2TIM_OFFLINE_PUSH_NO_PUSH = 1,
};

/// Image type
enum V2TIMImageType {
    ///< Original image
    V2TIM_IMAGE_TYPE_ORIGIN = 0x01,
    ///< Thumbnail
    V2TIM_IMAGE_TYPE_THUMB = 0x02,
    ///< Large image
    V2TIM_IMAGE_TYPE_LARGE = 0x04,
};

/// Group tip type
enum V2TIMGroupTipsType {
    /// Undefined
    V2TIM_GROUP_TIPS_TYPE_NONE = 0x00,
    ///< Proactively join a group (memberList joins a group; valid only for non-Work groups)
    V2TIM_GROUP_TIPS_TYPE_JOIN = 0x01,
    ///< Be invited to a group (opMember invites memberList to join a group; valid only for Work groups)
    V2TIM_GROUP_TIPS_TYPE_INVITE = 0x02,
    ///< Quit a group
    V2TIM_GROUP_TIPS_TYPE_QUIT = 0x03,
    ///< Be kicked out of a group (opMember kicks memberList out of the group)
    V2TIM_GROUP_TIPS_TYPE_KICKED = 0x04,
    ///< Set an admin (opMember sets memberList as an admin)
    V2TIM_GROUP_TIPS_TYPE_SET_ADMIN = 0x05,
    ///< Cancel an admin (opMember cancels memberList as an admin)
    V2TIM_GROUP_TIPS_TYPE_CANCEL_ADMIN = 0x06,
    ///< Group profile change (opMember modifies group information：groupName & introduction & notification & faceUrl & owner & custom)
    V2TIM_GROUP_TIPS_TYPE_GROUP_INFO_CHANGE = 0x07,
    ///< Group member profile change (opMember modifies group member information：muteTime)
    V2TIM_GROUP_TIPS_TYPE_MEMBER_INFO_CHANGE = 0x08,
};

/// Message pull type
enum V2TIMMessageGetType {
    ///< Get older messages from the cloud
    V2TIM_GET_CLOUD_OLDER_MSG = 1,
    ///< Get newer messages from the cloud
    V2TIM_GET_CLOUD_NEWER_MSG = 2,
    ///< Get older messages from local storage
    V2TIM_GET_LOCAL_OLDER_MSG = 3,
    ///< Get newer messages from local storage
    V2TIM_GET_LOCAL_NEWER_MSG = 4,
};

/// Keyword list matching type when search message
enum V2TIMKeywordListMatchType {
    V2TIM_KEYWORD_LIST_MATCH_TYPE_OR = 0,
    V2TIM_KEYWORD_LIST_MATCH_TYPE_AND = 1
};

/// Group message read member list filter type
enum V2TIMGroupMessageReadMembersFilter {
    ///< Group message read member list
    V2TIM_GROUP_MESSAGE_READ_MEMBERS_FILTER_READ   = 0,
    ///< Group message unread member list
    V2TIM_GROUP_MESSAGE_READ_MEMBERS_FILTER_UNREAD = 1,
};

/// The type of offline push on iOS
enum V2TIMIOSOfflinePushType {
    ///< APNs
    V2TIM_IOS_OFFLINE_PUSH_TYPE_APNS = 0,
    ///< VoIP push
    V2TIM_IOS_OFFLINE_PUSH_TYPE_VOIP = 1,
};

/// The type of device token when register offline push
enum V2TIMOfflinePushTokenType {
    ///< Default is OEM token: APNS/xiaomi push/Huawei push etc.
    V2TIM_OFFLINE_PUSH_TOKEN_TYPE_DEFAULT = 0,
    ///< TPNS
    V2TIM_OFFLINE_PUSH_TOKEN_TYPE_TPNS    = 1,
    ///< VoIP push，only supported for iOS
    V2TIM_OFFLINE_PUSH_TOKEN_TYPE_VOIP    = 2,
};

/////////////////////////////////////////////////////////////////////////////////
//
//                     Struct definition
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMOfflinePushConfig {
    /// The token obtained when registering the application to the vendors.
    V2TIMBuffer token;
    /// IM console certificate ID.
    uint32_t businessID;
    /// Type type of device token，Default is V2TIM_OFFLINE_PUSH_TOKEN_TYPE_DEFAULT
    /// @note V2TIM_OFFLINE_PUSH_TOKEN_TYPE_TPNS field has been deprecated
    /// - If you have built offline push by TPNS and have setup configuration on the TPNS console, you can continue to use TPNS with setting this field to true.
    /// - If you have not built offline push by TPNS and have not setup configuration on the TPNS console，please not to use TPNS again. This feature has not been supported any more.
    ///   https://cloud.tencent.com/document/product/269/74284
    V2TIMOfflinePushTokenType token_type;

    V2TIMOfflinePushConfig();
    V2TIMOfflinePushConfig(const V2TIMOfflinePushConfig &);
    ~V2TIMOfflinePushConfig();
};

/// No sound will be played when receiving messages
#define kIOSOfflinePushNoSound "push.no_sound"
/// Play system sound when receiving messages
#define kIOSOfflinePushDefaultSound "default"

struct TIM_API V2TIMOfflinePushInfo {
    /// Notification title(This field must be set for custom message offline push)
    V2TIMString title;
    /// Notification content
    V2TIMString desc;
    /// Extended field passed through by offline push
    /// The party that receives the offline push can get this field in UIApplicationDelegate -> didReceiveRemoteNotification -> userInfo, and use this field to make UI jump logic.
    V2TIMString ext;
    /// Whether to disable push (push enabled by default)
    bool disablePush;
    /// The type of offline push on iOS (valid only for iOS)
    /// Default value is V2TIM_IOS_OFFLINE_PUSH_TYPE_APNS
    V2TIMIOSOfflinePushType iOSPushType;
    /**
     * Whether to ignore the badge count for offline push (valid only for iOS)
     *
     * If this parameter is set to YES, the unread message count on the app badge will not increase when the message is received by the iOS device.
     */
    bool ignoreIOSBadge;
    /**
     * Offline push sound setting (valid only for iOS)
     *
     * When iOSSound is kIOSOfflinePushNoSound, no sound is played when a message is received.
     * When iOSSound is kIOSOfflinePushDefaultSound, the system alert sound is played when a message is received.
     * To customize iOSSound, link the audio file to the Xcode project and set iOSSound to the audio filename (with the extension name).
    */
    V2TIMString iOSSound;
    /**
     * Offline push sound setting (valid only for Android, supported only in imsdk 6.1 and later versions)
     * 
     * Only Huawei and Google phones support setting ringtone. And Xiaomi needs refer to https://dev.mi.com/console/doc/detail?pId=1278%23_3_0 .
     * 
     * In addition, Google phones using FCM to set the sound prompt on Android 8.0 and above systems, which needs to be configured in notification channel,
     * please refer to the interface setAndroidFCMChannelID.
     * 
     * To customize AndroidSound: The ringtone file name in the raw directory of the Android project, no suffix is required.
     */
    V2TIMString AndroidSound;
    /// Offline push channel ID for OPPO phones that run Android 8.0 or later
    V2TIMString AndroidOPPOChannelID;
    /// Offline push channel ID for Google FCM phones that run Android 8.0 or later
    V2TIMString AndroidFCMChannelID;
    /// Offline push channel ID for XiaoMi phones that run Android 8.0 or later
    V2TIMString AndroidXiaoMiChannelID;
    /// Offline push setting for vivo phones
    /// Offline push message classification for vivo phones. 0: operation message; 1: system message. The default value is 1.
    int AndroidVIVOClassification;
    /// Offline push setting for HuaWei push category，See details：https://developer.huawei.com/consumer/cn/doc/development/HMSCore-Guides/message-classification-0000001149358835#section1076611477914
    V2TIMString AndroidHuaWeiCategory;

    V2TIMOfflinePushInfo();
    V2TIMOfflinePushInfo(const V2TIMOfflinePushInfo &);
    ~V2TIMOfflinePushInfo();
};

struct V2TIMElem;
struct V2TIMTextElem;
struct V2TIMCustomElem;
struct V2TIMImageElem;
struct V2TIMVideoElem;
struct V2TIMSoundElem;
struct V2TIMFileElem;
struct V2TIMFaceElem;
struct V2TIMLocationElem;
struct V2TIMMergerElem;
struct V2TIMGroupTipsElem;

DEFINE_POINT_VECTOR(V2TIMElem)
typedef TXPV2TIMElemVector V2TIMElemVector;

class V2TIMDownloadCallback;

template <class T>
class V2TIMValueCallback;

#define kImSDK_MesssageAtALL "__kImSDK_MesssageAtALL__"

/// Definition of V2TIMMessage
struct TIM_API V2TIMMessage : V2TIMBaseObject {
    /// Message ID
    V2TIMString msgID;
    /// Message timestamp
    int64_t timestamp;
    /// Sender's userID
    V2TIMString sender;
    /// Sender's nickname
    V2TIMString nickName;
    /// Sender's friend remark. If you have not pulled the friend information or are not a friend, nil is returned.
    V2TIMString friendRemark;
    /// For a group message, nameCard is the group name card of the sender.
    V2TIMString nameCard;
    /// Sender's profile photo URL
    V2TIMString faceURL;
    /// For a group message, groupID is the message receiving group ID. Otherwise, groupID is null.
    V2TIMString groupID;
    /// For a one-to-one message, userID is the conversation user ID. Otherwise, userID is null.
    /// Suppose you are chatting with userA, regardless of whether it is a message sent to userA by yourself or a message sent to yourself by userA, the userID here is userA.
    V2TIMString userID;
    /// Sequence number of the message
    /// Message sequence numbers in group chats are generated in the cloud and are strictly incremented and unique within the group.
    /// Message sequence numbers in one-to-one chats are generated locally and cannot be guaranteed to be strictly incremented and unique.
    uint64_t seq;
    /// Random number of the message
    uint64_t random;
    /// Message sending status
    V2TIMMessageStatus status;
    /// Whether to support message extension (supported only in 6.7 and later versions)
    /// @note
    /// <p> Community and AVChatRoom message do not support this feature.
    /// <p> You need to go to the IM console to enable this feature.
    /// <p> You need to buy Flagship Edition to use this feature.
    bool supportMessageExtension;
    /// Whether the message sender is the current user
    bool isSelf;
    /// Whether the message is read by the current user
    bool IsRead() const;
    /// Whether the message is read by the peer party (valid only for one-to-one messages)
    /// The condition for this field to be true is that the message timestamp <= the time when the peer marked conversation as read
    bool IsPeerRead() const;
    /// Whether a read receipt is required
    /// @note
    /// <p> This feature for group chats is supported in 6.1 and later version. And you need to go to the IM console to enable this feature for specific group type.
    /// <p> This feature for one-to-one chats is supported in 6.2 and later version.
    /// <p> You need to buy Flagship Edition to use this feature for both group and one-to-one chats.
    bool needReadReceipt;
    /// Whether the message is a kind of broadcast message
    /// Only supported in AVChatRoom
    /// Only supported in 6.5 and later versions and need to buy Flagship Edition
    bool isBroadcastMessage;
    /// Message priority (only V2TIMMessage received by onRecvNewMessage is valid)
    V2TIMMessagePriority priority;
    /// UserID list of users who has been @ in the group message
    V2TIMStringVector groupAtUserList;
    /// V2TIMElem list
    ///
    /// It is recommended to store only one elem in a message. When receiving this message, call elemList[0] to get this elem. The sample code is as follows:
    /// if (1 == message.elemList.Size()) {
    ///     V2TIMElem *elem = message.elemList[0];
    ///     switch (elem->elemType) {
    ///         case V2TIM_ELEM_TYPE_TEXT:
    ///             V2TIMTextElem *textElem = static_cast<V2TIMTextElem *>(elem);
    ///             break;
    ///         case V2TIM_ELEM_TYPE_CUSTOM:
    ///             V2TIMCustomElem *customElem = static_cast<V2TIMCustomElem *>(elem);
    ///             break;
    ///         case V2TIM_ELEM_TYPE_FACE:
    ///             V2TIMFaceElem *faceElem = static_cast<V2TIMFaceElem *>(elem);
    ///             break;
    ///         case V2TIM_ELEM_TYPE_LOCATION:
    ///             V2TIMLocationElem *locationElem = static_cast<V2TIMLocationElem *>(elem);
    ///             break;
    ///         default:
    ///             break;
    ///     }
    /// }
    ///
    /// If a message has multiple elems, traverse the elemList list to get all elem elements，the sample code is as follows:
    /// for (size_t i = 0; i < message.elemList.Size(); ++i) {
    ///     V2TIMElem *elem = message.elemList[i];
    ///     switch (elem->elemType) {
    ///         case V2TIM_ELEM_TYPE_TEXT:
    ///             V2TIMTextElem *textElem = static_cast<V2TIMTextElem *>(elem);
    ///             break;
    ///         case V2TIM_ELEM_TYPE_CUSTOM:
    ///             V2TIMCustomElem *customElem = static_cast<V2TIMCustomElem *>(elem);
    ///             break;
    ///         case V2TIM_ELEM_TYPE_FACE:
    ///             V2TIMFaceElem *faceElem = static_cast<V2TIMFaceElem *>(elem);
    ///             break;
    ///         case V2TIM_ELEM_TYPE_LOCATION:
    ///             V2TIMLocationElem *locationElem = static_cast<V2TIMLocationElem *>(elem);
    ///             break;
    ///         default:
    ///             break;
    ///     }
    /// }
    ///
    /// If your message requires multiple elems, you can call elemList.PushBack to add a new elem after creating the Message object.
    /// Here is the sample code to create a message object with two elements.
    /// V2TIMCustomElem *customElem = new V2TIMCustomElem();
    /// customElem->data = buffer; 
    /// V2TIMMessage message = messageManager.CreateTextMessage("text");
    /// message.elemList.PushBack(customElem);
    /// 
    V2TIMElemVector elemList;
    /// Local custom message data (saved locally, will not be sent to the peer end, and will become invalid after the app is uninstalled and reinstalled)
    V2TIMBuffer localCustomData;
    /// Local custom message data (saved locally, will not be sent to the peer end, and will become invalid after the app is uninstalled and reinstalled)
    int localCustomInt;
    /// Cloud custom data (saved in the cloud, will be sent to the peer end, and can still be pulled after the app is uninstalled and reinstalled)
    V2TIMBuffer cloudCustomData;
    /// Whether the message is excluded from the conversation unread message count. false (default): included in the unread message count of the conversation; true: excluded from the conversation unread message count
    /// <p> Supported only in 5.3.425 and later versions.
    bool isExcludedFromUnreadCount;
    /// Whether the message is excluded from the conversation lastMessage. false (default): included in the conversation lastMessage; true: excluded from the conversation lastMessage
    /// Supported only in 5.4.666 and later versions.
    bool isExcludedFromLastMessage;
    /// Offline push information of the message
    V2TIMOfflinePushInfo offlinePushInfo;
    /// This field is only used internally by the SDK. If you want to know whether the message is read by the current user, please use IsRead()
    bool isRead;
    /// This field is only used internally by the SDK. If you want to know whether the message is read by the peer party, please use IsPeerRead()
    bool isPeerRead;

    V2TIMMessage();
    V2TIMMessage(const V2TIMMessage &);
    V2TIMMessage &operator=(const V2TIMMessage &);
    ~V2TIMMessage() override;
};

DEFINE_VECTOR(V2TIMMessage)
typedef TXV2TIMMessageVector V2TIMMessageVector;

/////////////////////////////////////////////////////////////////////////////////
//
//                         Message element base class
//
/////////////////////////////////////////////////////////////////////////////////

/// Definition of V2TIMElem
struct TIM_API V2TIMElem : V2TIMBaseObject {
    /// element type
    V2TIMElemType elemType;

    V2TIMElem();
    V2TIMElem(const V2TIMElem &);
    ~V2TIMElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                        Definition of V2TIMTextElem
//
/////////////////////////////////////////////////////////////////////////////////
struct TIM_API V2TIMTextElem : public V2TIMElem {
    /// Message text
    V2TIMString text;

    V2TIMTextElem();
    V2TIMTextElem(const V2TIMTextElem &);
    V2TIMTextElem &operator=(const V2TIMTextElem &);
    ~V2TIMTextElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                        Definition of V2TIMCustomElem
//
/////////////////////////////////////////////////////////////////////////////////
struct TIM_API V2TIMCustomElem : public V2TIMElem {
    /// Custom data
    V2TIMBuffer data;
    /// Custom description
    V2TIMString desc;
    /// Custom extension
    V2TIMString extension;

    V2TIMCustomElem();
    V2TIMCustomElem(const V2TIMCustomElem &);
    V2TIMCustomElem &operator=(const V2TIMCustomElem &);
    ~V2TIMCustomElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMImage
//
/////////////////////////////////////////////////////////////////////////////////
struct TIM_API V2TIMImage {
    /// Image ID
    V2TIMString uuid;
    /// Image type
    V2TIMImageType type;
    /// Image file size
    uint64_t size;
    /// Image width
    uint32_t width;
    /// Image height
    uint32_t height;
    /// Image download url
    V2TIMString url;

    /**
     *  Download image
     *
     *  The downloaded image needs to be cached by the developer. IM SDK will re-download the image from the server every time when downloadImage is called. It is recommended to use the uuid of the image as the key to store the image file.
     *
     *  @param path Image save path, need to be specified externally.
     */
    void DownloadImage(const V2TIMString &path, V2TIMDownloadCallback *callback);

    V2TIMImage();
    V2TIMImage(const V2TIMImage &);
    ~V2TIMImage();
};

DEFINE_VECTOR(V2TIMImage)
typedef TXV2TIMImageVector V2TIMImageVector;

/// Definition of V2TIMImageElem
struct TIM_API V2TIMImageElem : public V2TIMElem {
    /// Local file path of the original image. This is valid only for the message sender.
    V2TIMString path;
    /// When receiving a picture message, this field will save all the specifications of the picture. Currently, it contains at most three specifications: original picture, large picture, and thumbnail. Each specification is stored in a V2TIMImage object.
    V2TIMImageVector imageList;

    V2TIMImageElem();
    V2TIMImageElem(const V2TIMImageElem &);
    V2TIMImageElem &operator=(const V2TIMImageElem &);
    ~V2TIMImageElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMSoundElem
//
/////////////////////////////////////////////////////////////////////////////////
struct TIM_API V2TIMSoundElem : public V2TIMElem {
    /// Voice file path（valid only for the message sender）
    V2TIMString path;
    /// Internal ID of the voice message
    V2TIMString uuid;
    /// Voice file size
    uint64_t dataSize;
    /// Voice duration (seconds)
    uint32_t duration;

    /// Get the voice download URL
    void GetUrl(V2TIMValueCallback<V2TIMString> *callback);

    /**
     * Download voice
     *
     * The downloadSound API downloads files from the server each time. If cache or storage is required, you can use UUIDs as keys for external storage. The IM SDK does not store resource files.
     *
     * @param path   Voice save path, which must be specified externally
     */
    void DownloadSound(const V2TIMString &path, V2TIMDownloadCallback *callback);

    V2TIMSoundElem();
    V2TIMSoundElem(const V2TIMSoundElem &);
    V2TIMSoundElem &operator=(const V2TIMSoundElem &);
    ~V2TIMSoundElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMVideoElem
//
/////////////////////////////////////////////////////////////////////////////////
struct TIM_API V2TIMVideoElem : public V2TIMElem {
    /// Video file path (valid only for the message sender)
    V2TIMString videoPath;
    /// Screenshot file path (valid only for the message sender)
    V2TIMString snapshotPath;
    /// Video ID which is an internal ID and can be used as an external cache key
    V2TIMString videoUUID;
    /// Video file size
    uint64_t videoSize;
    /// Video type
    V2TIMString videoType;
    /// Duration, in seconds
    uint32_t duration;
    /// Screenshot ID which is an internal ID and can be used as an external cache key
    V2TIMString snapshotUUID;
    /// Screenshot file size
    uint64_t snapshotSize;
    /// Screenshot width
    uint32_t snapshotWidth;
    /// Screenshot height
    uint32_t snapshotHeight;

    /// Get the video download URL
    void GetVideoUrl(V2TIMValueCallback<V2TIMString> *callback);

    /// Get the screenshot download URL
    void GetSnapshotUrl(V2TIMValueCallback<V2TIMString> *callback);

    /**
     * Download a video
     *
     * The downloadVideo API downloads videos from the server each time. If cache or storage is required, you can use UUIDs as keys for external storage. The IM SDK does not store resource files.
     *
     * @param path   Video save path, which must be specified externally
     */
    void DownloadVideo(const V2TIMString &path, V2TIMDownloadCallback *callback);

    /**
     * Download a video screenshot
     *
     * The downloadSnapshot API downloads screenshots from the server each time. If cache or storage is required, you can use UUIDs as keys for external storage. The IM SDK does not store resource files.
     *
     * @param path   Screenshot save path, which must be specified externally
     */
    void DownloadSnapshot(const V2TIMString &path, V2TIMDownloadCallback *callback);

    V2TIMVideoElem();
    V2TIMVideoElem(const V2TIMVideoElem &);
    V2TIMVideoElem &operator=(const V2TIMVideoElem &);
    ~V2TIMVideoElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMFileElem
//
/////////////////////////////////////////////////////////////////////////////////
struct TIM_API V2TIMFileElem : public V2TIMElem {
    /// Path to the local file sent（valid only for the message sender）
    V2TIMString path;
    /// File ID which is an internal ID and can be used as an external cache key
    V2TIMString uuid;
    /// File name
    V2TIMString filename;
    /// File size
    uint64_t fileSize;

    /// Get the file download URL
    void GetUrl(V2TIMValueCallback<V2TIMString> *callback);

    /**
    * Download a file
    *
    * The downloadFile API downloads files from the server each time. If cache or storage is required, you can use UUIDs as keys for external storage. The IM SDK does not store resource files.
    *
    * @param path   File save path, which must be specified externally
    */
    void DownloadFile(const V2TIMString &path, V2TIMDownloadCallback *callback);

    V2TIMFileElem();
    V2TIMFileElem(const V2TIMFileElem &);
    V2TIMFileElem &operator=(const V2TIMFileElem &);
    ~V2TIMFileElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                          Definition of V2TIMLocationElem
//
/////////////////////////////////////////////////////////////////////////////////
struct TIM_API V2TIMLocationElem : public V2TIMElem {
    /// Location description
    V2TIMString desc;
    /// Longitude
    double longitude;
    /// Latitude
    double latitude;

    V2TIMLocationElem();
    V2TIMLocationElem(const V2TIMLocationElem &);
    V2TIMLocationElem &operator=(const V2TIMLocationElem &);
    ~V2TIMLocationElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMFaceElem
//
/////////////////////////////////////////////////////////////////////////////////
struct TIM_API V2TIMFaceElem : public V2TIMElem {
    /**
     *  Custom emoji index
     *  1. The face message is defined by V2TIMFaceElem. The SDK does not provide face resource package. If the developer has face resource package, you can use index to mark a face, which can be customized by the user, or directly use data to store the expression binary information. All are defined by the user, and only transparent transmission is done inside the SDK.
     *  2. Index and data only need to be passed in one, the SDK only transparently transmits these two data.
     */
    uint32_t index;
    /// Custom emoji data
    V2TIMBuffer data;

    V2TIMFaceElem();
    V2TIMFaceElem(const V2TIMFaceElem &);
    V2TIMFaceElem &operator=(const V2TIMFaceElem &);
    ~V2TIMFaceElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMMergerElem
//
/////////////////////////////////////////////////////////////////////////////////
struct TIM_API V2TIMMergerElem : public V2TIMElem {
    /// When a combined message also contains combined messages, we call the situation combination nesting. The number of combination nesting levels cannot exceed 100. If the limit is exceeded, layersOverLimit will return true, title and abstractList will return an empty string, and downloadMergerMessage will return the ERR_MERGER_MSG_LAYERS_OVER_LIMIT error code.
    bool layersOverLimit;
    /// Title of a combined message
    V2TIMString title;
    /// Abstract list of the combined message
    V2TIMStringVector abstractList;

    /// Download the list of messages combined
    void DownloadMergerMessage(V2TIMValueCallback<V2TIMMessageVector> *callback);

    V2TIMMergerElem();
    V2TIMMergerElem(const V2TIMMergerElem &);
    V2TIMMergerElem &operator=(const V2TIMMergerElem &);
    ~V2TIMMergerElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                        Definition of V2TIMGroupTipsElem
//
/////////////////////////////////////////////////////////////////////////////////
struct TIM_API V2TIMGroupTipsElem : public V2TIMElem {
    /// Group ID
    V2TIMString groupID;
    /// Group event notification type
    V2TIMGroupTipsType type;
    /// Operator
    V2TIMGroupMemberInfo opMember;
    /// List of users to be operated on
    V2TIMGroupMemberInfoVector memberList;
    /// Group profile change information list. This is valid only when the value of type is V2TIM_GROUP_TIPS_TYPE_GROUP_INFO_CHANGE.
    V2TIMGroupChangeInfoVector groupChangeInfoList;
    /// Group member change information list. This is valid only when the value of tipsType is V2TIM_GROUP_TIPS_TYPE_MEMBER_INFO_CHANGE.
    V2TIMGroupMemberChangeInfoVector memberChangeInfoList;
    /// Number of current group members. This is valid only when the value of tipsType is V2TIM_GROUP_TIPS_TYPE_INVITE、TIM_GROUP_TIPS_TYPE_QUIT_GRP or TIM_GROUP_TIPS_TYPE_KICKED
    uint32_t memberCount;

    V2TIMGroupTipsElem();
    V2TIMGroupTipsElem(const V2TIMGroupTipsElem &);
    V2TIMGroupTipsElem &operator=(const V2TIMGroupTipsElem &);
    ~V2TIMGroupTipsElem() override;
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMMessageReceipt
//
/////////////////////////////////////////////////////////////////////////////////

/// Message read receipt
struct TIM_API V2TIMMessageReceipt {
    /// Unique ID of the message
    V2TIMString msgID;
    /// UserID of the other party who has read the message
    V2TIMString userID;
    /// Whether the message is read by the peer party (valid only for one-to-one messages)
    bool isPeerRead;
    /// The time when the other party marked the conversation read
    int64_t timestamp;
    /// Group ID
    V2TIMString groupID;
    /// Numbers of group members who have read the group message specified by seq
    int32_t readCount ;
    /// Numbers of group members who have not read the group message specified by seq
    int32_t unreadCount ;

    V2TIMMessageReceipt();
    V2TIMMessageReceipt(const V2TIMMessageReceipt &);
    ~V2TIMMessageReceipt();
};

DEFINE_VECTOR(V2TIMMessageReceipt)
typedef TXV2TIMMessageReceiptVector V2TIMMessageReceiptVector;

/////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMGroupMessageReadMemberList
//
/////////////////////////////////////////////////////////////////////////////////

/// Group 消息已读群成员信息
struct TIM_API V2TIMGroupMessageReadMemberList {
    /// Next pulling-by-page cursor
    uint64_t nextSeq;
    /// Whether group member list pulling is completed
    bool isFinished;
    /// Group members profile who have or have not read the group message.
    V2TIMGroupMemberInfoVector members;

    V2TIMGroupMessageReadMemberList();
    V2TIMGroupMessageReadMemberList(const V2TIMGroupMessageReadMemberList &);
    ~V2TIMGroupMessageReadMemberList();
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMReceiveMessageOptInfo
//
/////////////////////////////////////////////////////////////////////////////////
struct TIM_API V2TIMReceiveMessageOptInfo {
    /// UserID
    V2TIMString userID;
    /// Message receive option
    V2TIMReceiveMessageOpt receiveOpt;

    V2TIMReceiveMessageOptInfo();
    V2TIMReceiveMessageOptInfo(const V2TIMReceiveMessageOptInfo &);
    ~V2TIMReceiveMessageOptInfo();
};

DEFINE_VECTOR(V2TIMReceiveMessageOptInfo)
typedef TXV2TIMReceiveMessageOptInfoVector V2TIMReceiveMessageOptInfoVector;

/////////////////////////////////////////////////////////////////////////////////
//
//                          Definition of V2TIMMessageSearchParam
//
/////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMMessageSearchParam {
    /**
     * The keyword list can contain up to 5 keywords. When the sender and type of the message are not specified, the keyword list must be non-empty. Otherwise, the keyword list can be empty.
     */
    V2TIMStringVector keywordList;

    /**
     * Set the keyword list matching type, which can be the OR or AND relationship search.
     * The options are V2TIM_KEYWORD_LIST_MATCH_TYPE_OR (default) and V2TIM_KEYWORD_LIST_MATCH_TYPE_AND.
     */
    V2TIMKeywordListMatchType keywordListMatchType;

    /**
     * Set userIDs for message sending. Up to 5 userIDs are supported.
     */
    V2TIMStringVector senderUserIDList;

    /// Set the message types to search. If an empty array is passed in, all message types supported are searched (V2TIMFaceElem and V2TIMGroupTipsElem are not supported).
    V2TIMElemTypeVector messageTypeList;

    /**
     * Search all conversations or a specified conversation
     * <p> conversationID == null: search all conversations
     * <p> conversationID != null: search a specified conversation
     */
    V2TIMString conversationID;

    ///  Start time for search. The default value is 0, indicating to start search now. The value can also be the UTC timestamp, in seconds.
    uint32_t searchTimePosition;

    /// A time period in the past starting from the start time, in seconds. The default value 0 indicates that the time range is not limited. The value 24x60x60 indicates the past day.
    uint32_t searchTimePeriod;

    /**
     * Page number: used for the paginated display of the search results. Page numbers must start from 0.
     * For example, to display 10 results per page, call the API according to the following rules:
     * - First call: call searchLocalMessage with pageSize being set to 10 and pageIndex to 0. Then you can get the total number of results from totalCount in the callback.
     * - Page quantity calculation: totalPage = (totalCount % pageSize == 0) ? (totalCount / pageSize) : (totalCount / pageSize + 1)
     * - Second call: specify pageIndex (pageIndex < totalPage) to return the subsequent page number.
     */
    uint32_t pageIndex;

    /// Number of results per page: used for the paginated display of the search results. If you do not want to paginate the search results, set the parameter to 0. However, a large number of search results without pagination may cause performance issues.
    uint32_t pageSize;

    V2TIMMessageSearchParam();
    V2TIMMessageSearchParam(const V2TIMMessageSearchParam &);
    V2TIMMessageSearchParam &operator=(const V2TIMMessageSearchParam &);
    ~V2TIMMessageSearchParam();
};

struct TIM_API V2TIMMessageSearchResultItem {
    /// Get the conversation ID
    V2TIMString conversationID;
    /// Total number of eligible messages found in the current conversation
    uint32_t messageCount;

    /**
     * List of eligible messages
     * <p>If you search **a specified conversation**, messageList contains the list of all the eligible messages in the current conversation.
     * <p>If you search **all conversations**, there are two possibilities for the number of messages contained in messageList:
     * - If more than 1 eligible message is found in a conversation, messageList is empty, and the notification message "messageCount related messages" can be displayed on the UI.
     * - If 1 eligible message is found in a conversation, messageList contains the eligible message, and the message is displayed with the matching keywords highlighted on the UI.
     */
    V2TIMMessageVector messageList;

    V2TIMMessageSearchResultItem();
    V2TIMMessageSearchResultItem(const V2TIMMessageSearchResultItem &);
    ~V2TIMMessageSearchResultItem();
};

DEFINE_VECTOR(V2TIMMessageSearchResultItem)
typedef TXV2TIMMessageSearchResultItemVector V2TIMMessageSearchResultItemVector;

struct TIM_API V2TIMMessageSearchResult {
    /**
     * If you search **a specified conversation**, the total number of eligible messages is returned.
     * If you search **all conversations**, the total number of conversations where the eligible messages reside is returned.
     */
    uint32_t totalCount;

    /**
     * If you search **a specified conversation**, the result list contains only the results found in the conversation.
     * If you search **all conversations**, eligible messages are grouped by conversation ID and returned on multiple pages.
     */
    V2TIMMessageSearchResultItemVector messageSearchResultItems;

    V2TIMMessageSearchResult();
    V2TIMMessageSearchResult(const V2TIMMessageSearchResult &);
    V2TIMMessageSearchResult &operator=(const V2TIMMessageSearchResult &);
    ~V2TIMMessageSearchResult();
};

/////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMMessageListGetOption
//
/////////////////////////////////////////////////////////////////////////////////
struct TIM_API V2TIMMessageListGetOption {
    /**
     * Message pulling type, which can be set to pull older or newer messages from local storage or the cloud
     *
     * @note Notes:
     * <p>For pulling messages from the cloud, the locally stored and cloud stored message lists are combined and returned. If no network connection is available, only the locally stored message list is returned.
     * <p>The following are the instructions for getType and the start message and time range for message pulling:
     * - getType indicates the pulling direction: whether to pull older or newer messages.
     * - lastMsg and lastMsgSeq indicate the start point for message pulling. For first time pulling, they can be left empty or set to 0.
     * - getTimeBegin and getTimePeriod indicate the time range for message pulling. The start point of the time range is related to the pulling direction (getType).
     * - If both the start message and time range exist, the result set can be considered as the intersection of "result of pulling by start message alone" and "result of pulling by time range alone".
     * - If both the start message and time range do not exist, the result set can be considered as the result of pulling from the latest message of the current conversation in the pulling direction and mode specified by getType.
     *
     * @param getType   Pulling type. Valid values: V2TIM_GET_CLOUD_OLDER_MSG, V2TIM_GET_CLOUD_NEWER_MSG, V2TIM_GET_LOCAL_OLDER_MSG, V2TIM_GET_LOCAL_NEWER_MSG
     */
    V2TIMMessageGetType getType;

    /// Pull historical one-to-one chat messages
    V2TIMString userID;

    /// Pull historical group messages
    V2TIMString groupID;

    /// Number of messages to be pulled
    uint32_t count;

    /// Set the message types to pull, valid only when getType is V2TIM_GET_LOCAL_OLDER_MSG and V2TIM_GET_LOCAL_NEWER_MSG，If an empty array is passed in, all message types supported are pulled
    V2TIMElemTypeVector messageTypeList;

    /**
     * Start message for message pulling
     * @note Notes:
     * <p>When one-to-one messages are pulled, only lastMsg can be used to specify the start point for message pulling. If lastMsg is not specified, the IM SDK uses the newest message of the conversation as the start point for message pulling.
     * <p>When group messages are pulled, lastMsg or lastMsgSeq can be used to specify the start point for message pulling:
     * - If lastMsg is used to specify the start point for message pulling, the returned message list does not include the message specified by lastMsg.
     * - If lastMsgSeq is used to specify the start point for message pulling, the returned message list does not include the message specified by lastMsgSeq.
     *
     * @note When group messages are pulled:
     * <p>If both lastMsg and lastMsgSeq are specified, the IM SDK uses lastMsg to determine the start point for message pulling.
     * <p>If both lastMsg and lastMsgSeq are not specified, there are two cases for the start point for message pulling:
     * - If the time range for message pulling is specified, the IM SDK uses the point in time specified by @getTimeBegin as the start point for message pulling.
     * - If the time range for message pulling is not specified, the IM SDK uses the newest message of the conversation as the start point for message pulling.
     */
    V2TIMMessage *lastMsg;
    uint64_t lastMsgSeq;

    /**
     * Time range for message pulling
     * <p>getTimeBegin: indicates the start point of the time range. The default value is 0, indicating to start pulling now. The value can also be the UTC timestamp, in seconds.
     * <p>getTimePeriod: indicates the length of the time range, in seconds. The default value is 0, indicating that the time range is not limited.
     *
     * @note
     * <p> The direction of the time range is determined by the getType parameter:
     * <p> If getType is V2TIM_GET_CLOUD_OLDER_MSG/V2TIM_GET_LOCAL_OLDER_MSG, the time range is a period of time in the past, starting from getTimeBegin and with a length determined by getTimePeriod.
     * <p> If getType is V2TIM_GET_CLOUD_NEWER_MSG/V2TIM_GET_LOCAL_NEWER_MSG, the time range is a period of time in the future, starting from getTimeBegin and with a length determined by getTimePeriod.
     * <p> The value range is a closed range, including the start and end points in time. The relationship between the two is as follows:
     * - If getType specifies to pull older messages, the time range is [getTimeBegin-getTimePeriod, getTimeBegin].
     * - If getType specifies to pull newer messages, the time range is [getTimeBegin, getTimeBegin+getTimePeriod].
     */
    int64_t getTimeBegin;
    int64_t getTimePeriod;

    V2TIMMessageListGetOption();
    V2TIMMessageListGetOption(const V2TIMMessageListGetOption &);
    V2TIMMessageListGetOption &operator=(const V2TIMMessageListGetOption &);
    ~V2TIMMessageListGetOption();
};

/////////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMMessageExtension
//
/////////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMMessageExtension {
    /// Message extension key
    V2TIMString extensionKey;
    /// Message extension value
    V2TIMString extensionValue;

    V2TIMMessageExtension();
    V2TIMMessageExtension(const V2TIMMessageExtension &);
    V2TIMMessageExtension &operator=(const V2TIMMessageExtension &);
    ~V2TIMMessageExtension();
};

DEFINE_VECTOR(V2TIMMessageExtension)
typedef TXV2TIMMessageExtensionVector V2TIMMessageExtensionVector;

/////////////////////////////////////////////////////////////////////////////////////
//
//                         Definition of V2TIMMessageExtensionResult
//
/////////////////////////////////////////////////////////////////////////////////////

struct TIM_API V2TIMMessageExtensionResult {
    /// result code
    int32_t resultCode;
    /// result info
    V2TIMString resultInfo;
    /// Message extension
    V2TIMMessageExtension extension;

    V2TIMMessageExtensionResult();
    V2TIMMessageExtensionResult(const V2TIMMessageExtensionResult &);
    V2TIMMessageExtensionResult &operator=(const V2TIMMessageExtensionResult &);
    ~V2TIMMessageExtensionResult();
};

DEFINE_VECTOR(V2TIMMessageExtensionResult)
typedef TXV2TIMMessageExtensionResultVector V2TIMMessageExtensionResultVector;

#endif /* __V2TIM_MESSAGE_H__ */
