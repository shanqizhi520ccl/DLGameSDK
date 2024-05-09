// Copyright (c) 2021 Tencent. All rights reserved.

#ifndef __V2TIM_ERROR_CODE_H__
#define __V2TIM_ERROR_CODE_H__

enum V2TIMErrorCode {
    // ///////////////////////////////////////////////////////////////////////////////
    //
    // IM SDK error codes
    //
    // ///////////////////////////////////////////////////////////////////////////////

    // Common error codes

    ERR_SUCC                                    = 0,       // No error.
    ERR_IN_PROGESS                              = 6015,    // Operation in progress. Optimize the control over API calls. For example, if another initialization operation is performed before the first initialization operation is called back, the system returns this error code.
    ERR_INVALID_PARAMETERS                      = 6017,    // Invalid parameter. Check the error information to locate the invalid parameter.
    ERR_IO_OPERATION_FAILED                     = 6022,    // Local I/O operation error. Check whether you have the read/write permission or whether the disk is full.
    ERR_INVALID_JSON                            = 6027,    // Incorrect JSON format. Check the error information to locate the specific field.
    ERR_OUT_OF_MEMORY                           = 6028,    // Insufficient memory. A memory leak may occur. Analyze and identify the location with high memory usage by using the Instrument tool on the iOS platform or the Profiler tool on the Android platform.
    ERR_PARSE_RESPONSE_FAILED                   = 6001,    // PB parsing failed. Internal error. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1)  with the API, error code, and error information to technical support.
    ERR_SERIALIZE_REQ_FAILED                    = 6002,    // PB serialization failed. Internal error. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) with the API, error code, and error information to technical support.
    ERR_SDK_NOT_INITIALIZED                     = 6013,    // The IM SDK has not been initialized. Try again after the initialization success is called back.
    ERR_LOADMSG_FAILED                          = 6005,    // Failed to load the local database, possibly due to file corruption. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) to contact technical support to locate the problem.
    ERR_DATABASE_OPERATE_FAILED                 = 6019,    // Operation on the local database failed. This error may be caused by a lack of permissions for some directories or file corruption in the database.
    ERR_SDK_COMM_CROSS_THREAD                   = 7001,    // Cross-thread error. Cross-thread operations are not allowed. Internal error. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) with the API, error code, and error information to technical support.
    ERR_SDK_COMM_TINYID_EMPTY                   = 7002,    // TinyId is empty. Internal error. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) with the API, error code, and error information to technical support.
    ERR_SDK_COMM_INVALID_IDENTIFIER             = 7003,    // Invalid Identifier. Identifier cannot be empty and must be printable ASCII characters (0x20-0x7e) containing up to 32 bytes in length.
    ERR_SDK_COMM_FILE_NOT_FOUND                 = 7004,    // The file does not exist. Check whether the file path is correct.
    ERR_SDK_COMM_FILE_TOO_LARGE                 = 7005,    // The file size exceeds the limit. For an audio or image, the maximum limit is 28 MB. For a document or video, the maximum limit is 100 MB.
    ERR_SDK_COMM_FILE_SIZE_EMPTY                = 7006,    // The file is empty. The file cannot be 0 bytes. When uploading an image, audio, video, or document, ensure that the file is generated correctly.
    ERR_SDK_COMM_FILE_OPEN_FAILED               = 7007,    // Failed to open the file. Check whether the file exists or has been opened exclusively, which causes the SDK to fail to open it.
    ERR_SDK_COMM_API_CALL_FREQUENCY_LIMIT       = 7008,    // Exceeded the API call frequency limit.
    ERR_SDK_INTERFACE_NOT_SUPPORT               = 7013,    // The current package does not support this API. Please upgrade to the Flagship Edition package.

    // Account error codes

    ERR_SDK_NOT_LOGGED_IN                       = 6014,    // You have not logged in to the IM SDK or have been forcibly logged out. Log in to the IM SDK first and try again after a successful callback. To check whether you are online, use TIMManager getLoginUser.
    ERR_NO_PREVIOUS_LOGIN                       = 6026,    // This user account was not logged in during auto login. Call the login API to log in to the user account again.
    ERR_USER_SIG_EXPIRED                        = 6206,    // UserSig has expired. Get a new valid UserSig and log in again.
    ERR_LOGIN_KICKED_OFF_BY_OTHER               = 6208,    // You have been logged out because your account is logged in on another device. Please log in again.
    ERR_SDK_ACCOUNT_LOGIN_IN_PROCESS            = 7501,    // Login in process. For example, if another login or autoLogin operation is performed before the first login or autoLogin operation is called back, the system returns this error code.
    ERR_SDK_ACCOUNT_LOGOUT_IN_PROCESS           = 7502,    // Logout in process. For example, if another logout operation is performed before the first logout operation is called back, the system returns this error code.
    ERR_SDK_ACCOUNT_TLS_INIT_FAILED             = 7503,    // TLS SDK initialization failed. Internal error. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) with the API, error code, and error information to technical support.
    ERR_SDK_ACCOUNT_TLS_NOT_INITIALIZED         = 7504,    // The TLS SDK has not been initialized. Internal error. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) with the API, error code, and error information to technical support.
    ERR_SDK_ACCOUNT_TLS_TRANSPKG_ERROR          = 7505,    // The TRANS packet format of the TLS SDK is incorrect. Internal error. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) with the API, error code, and error information to technical support.
    ERR_SDK_ACCOUNT_TLS_DECRYPT_FAILED          = 7506,    // TLS SDK decryption failed. Internal error. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) with the API, error code, and error information to technical support.
    ERR_SDK_ACCOUNT_TLS_REQUEST_FAILED          = 7507,    // TLS SDK request failed. Internal error. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) with the API, error code, and error information to technical support.
    ERR_SDK_ACCOUNT_TLS_REQUEST_TIMEOUT         = 7508,    // TLS SDK request timed out. Internal error. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) with the API, error code, and error information to technical support.

    // Message error codes

    ERR_INVALID_CONVERSATION                    = 6004,    // The conversation is invalid. Check your login status when initiating getConversation. If you initiate getConversation offline, the system returns this error code.
    ERR_FILE_TRANS_AUTH_FAILED                  = 6006,    // File transfer authentication failed. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1)with the API, error code, and error information to technical support.
    ERR_FILE_TRANS_NO_SERVER                    = 6007,    // Failed to get the server list via FTP. You can [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) with the API, error code, and error information to technical support.
    ERR_FILE_TRANS_UPLOAD_FAILED                = 6008,    // Failed to upload the file via FTP. Check your network connection.
    ERR_IMAGE_UPLOAD_FAILED_NOTIMAGE            = 6031,    // Failed to upload the file via FTP. If you want to upload an image, ensure that the image can be opened.
    ERR_FILE_TRANS_DOWNLOAD_FAILED              = 6009,    // Failed to download the file via FTP. Check whether your network is connected or whether the file or audio has expired. Currently, resource files are stored for up to 7 days. |
    ERR_HTTP_REQ_FAILED                         = 6010,    // HTTP request failed. Check whether the URL is valid. You can try to access the URL via a web browser.
    ERR_INVALID_MSG_ELEM                        = 6016,    // Invalid message elem of the IM SDK. For more information, you can check the error information to locate the specific field.
    ERR_INVALID_SDK_OBJECT                      = 6021,    // Invalid object. The TIMImage object is user-generated or an incorrect value is assigned to the object.
    ERR_SDK_MSG_BODY_SIZE_LIMIT                 = 8001,    // The message length exceeds the limit of 12 KB. The length of a message is the sum of the length of all elements in the message, and the length of an element is the sum of the length of all fields of the element.
    ERR_SDK_MSG_KEY_REQ_DIFFER_RSP              = 8002,    // Message key error. This is an internal error. The key of the network request packet is not consistent with that of the response packet.
    ERR_SDK_IMAGE_CONVERT_ERROR                 = 8003,    // The image conversion HTTP request failed.
    ERR_MERGER_MSG_LAYERS_OVER_LIMIT            = 8005,    // The number of nested levels of combined messages exceeds the upper limit of 100.
    ERR_SDK_MSG_MODIFY_CONFLICT                 = 8006,    // Message modification conflict, the message you requested to modify has been modified by someone else.
    ERR_SDK_SIGNALING_INVALID_INVITE_ID         = 8010,    // The signaling request ID is invalid or has been processed.
    ERR_SDK_SIGNALING_NO_PERMISSION             = 8011,    // The signaling request is not authorized, such as canceling an invitation not initiated by the current user.
    ERR_SDK_SIGNALING_ALREADY_EXISTS            = 8012,    // The signaling invitation already exists.
    
    // Group error codes

    ERR_SDK_GROUP_INVALID_ID                    = 8501,    // Invalid group ID. A custom group ID must be printable ASCII characters (0x20-0x7e) containing up to 48 bytes in length. To avoid confusion with the default group IDs assigned by IM, a custom group ID cannot be prefixed with @TGS#.
    ERR_SDK_GROUP_INVALID_NAME                  = 8502,    // Invalid group name. A group name can be up to 30 bytes in length and must be encoded in UTF-8. If the group name contains a Chinese character, the Chinese character may be expressed in multiple bytes. Check the length of the string in bytes.
    ERR_SDK_GROUP_INVALID_INTRODUCTION          = 8503,    // Invalid group introduction. A group introduction can be up to 240 bytes in length and must be encoded in UTF-8. If the group introduction contains a Chinese character, the Chinese character may be expressed in multiple bytes. Check the length of the string in bytes.
    ERR_SDK_GROUP_INVALID_NOTIFICATION          = 8504,    // Invalid group notice. A group notice can be up to 300 bytes in length and must be encoded in UTF-8. If the group notice contains a Chinese character, the Chinese character may be expressed in multiple bytes. Check the length of the string in bytes.
    ERR_SDK_GROUP_INVALID_FACE_URL              = 8505,    // Invalid URL of the group profile photo. The URL of a group profile photo can be up to 100 bytes in length. You can try to access the URL via a web browser.
    ERR_SDK_GROUP_INVALID_NAME_CARD             = 8506,    // Invalid group name card. A group name card can be up to 50 bytes in length and must be encoded in UTF-8. If the group name card contains a Chinese character, the Chinese character may be expressed in multiple bytes. Check the length of the string in bytes.
    ERR_SDK_GROUP_MEMBER_COUNT_LIMIT            = 8507,    // The number of group members exceeds the limit allowed upon group creation and invitation. Private group: up to 200 members. Public group: up to 2,000 members. Chat room: up to 10,000 members. Audio-video chat room: unlimited. Broadcasting chat rooms: unlimited.
    ERR_SDK_GROUP_JOIN_PRIVATE_GROUP_DENY       = 8508,    // A private group cannot be joined via app. Any group member can invite non-members to join the group without the invitees' confirmation.
    ERR_SDK_GROUP_INVITE_SUPER_DENY             = 8509,    // You cannot invite a group member whose role is group owner. Ensure that the role field is entered correctly.
    ERR_SDK_GROUP_INVITE_NO_MEMBER              = 8510,    // You cannot invite 0 members. Ensure that the member field is entered correctly.
    ERR_SDK_GROUP_ATTR_FREQUENCY_LIMIT          = 8511,    // Group attribute API operation limits: the Create, Delete, and Update APIs each can be called by the backend for up to 5 times per second. The Query API can be called by the SDK for up to 20 times per 5 seconds.

    // Relationship chain error codes

    ERR_SDK_FRIENDSHIP_INVALID_PROFILE_KEY      = 9001,    // Invalid profile field. The profile supports standard fields and custom fields. The keyword in a custom field must contain letters and can be up to 8 bytes in length. A custom field cannot exceed 500 bytes in length.
    ERR_SDK_FRIENDSHIP_INVALID_ADD_REMARK       = 9002,    // Invalid remarks. The remarks field can be up to 96 bytes in length and must be encoded in UTF-8. If the remarks field contains a Chinese character, the Chinese character may be expressed in multiple bytes. Check the length of the string in bytes.
    ERR_SDK_FRIENDSHIP_INVALID_ADD_WORDING      = 9003,    // Invalid remarks field of the friend request. The field can be up to 120 bytes in length and must be encoded in UTF-8. If the friend request field contains a Chinese character, the Chinese character may be expressed in multiple bytes. Check the length of the string in bytes.
    ERR_SDK_FRIENDSHIP_INVALID_ADD_SOURCE       = 9004,    // The source field of the friend request is invalid. The source field must be prefixed with "AddSource_Type\_".
    ERR_SDK_FRIENDSHIP_FRIEND_GROUP_EMPTY       = 9005,    //  Invalid friend list name. A friend list name cannot be empty, can be up to 30 bytes in length, and must be encoded in UTF-8. If the friend list name contains a Chinese character, the Chinese character may be expressed in multiple bytes. Check the length of the string in bytes.

    // Network error codes

    ERR_SDK_NET_ENCODE_FAILED                   = 9501,    // Network data encryption failed. Internal error.
    ERR_SDK_NET_DECODE_FAILED                   = 9502,    // Network data decryption failed. Internal error.
    ERR_SDK_NET_AUTH_INVALID                    = 9503,    // Network has not been authenticated. The login process may not be completed. Complete the login process and then try again.
    ERR_SDK_NET_COMPRESS_FAILED                 = 9504,    // Failed to compress the data packet. Internal error.
    ERR_SDK_NET_UNCOMPRESS_FAILED               = 9505,    // Failed to decompress the data packet. Internal error.
    ERR_SDK_NET_FREQ_LIMIT                      = 9506,    // The call frequency exceeds the frequency limit. You can initiate up to 5 requests per second.
    ERR_SDK_NET_REQ_COUNT_LIMIT                 = 9507,    // The request queue is full. You can initiate up to 1,000 requests at a time.
    ERR_SDK_NET_DISCONNECT                      = 9508,    // The network is disconnected, no connection has been set up, or no network is detected when setting up a socket connection.
    ERR_SDK_NET_ALLREADY_CONN                   = 9509,    // A network connection has been established, but is created repeatedly. Internal error.
    ERR_SDK_NET_CONN_TIMEOUT                    = 9510,    // Network connection setup timed out. Try again after the network recovers.
    ERR_SDK_NET_CONN_REFUSE                     = 9511,    // The network connection setup has been rejected by the server due to frequent connection requests.
    ERR_SDK_NET_NET_UNREACH                     = 9512,    // No available route to the network. Try again after the network recovers.
    ERR_SDK_NET_SOCKET_NO_BUFF                  = 9513,    // Insufficient buffer capacity for calls. The system is too busy. Internal error.
    ERR_SDK_NET_RESET_BY_PEER                   = 9514,    // The peer end has reset the connection, possibly because the server is overloaded. The SDK automatically initiates reconnection. Try again after the network is reconnected and the callback function onConnSucc on iOS or onConnected on Android is called successfully.
    ERR_SDK_NET_SOCKET_INVALID                  = 9515,    // Invalid socket. Internal error.
    ERR_SDK_NET_HOST_GETADDRINFO_FAILED         = 9516,    // Failed to parse the IP address. Internal error. The local imsdk_config file may be corrupted and can cause the system to read an invalid IP address.
    ERR_SDK_NET_CONNECT_RESET                   = 9517,    // Invalid connection. The network is connected to an intermediate node or is reset by the server. This is an internal error. The SDK automatically initiates reconnection. Try again after the network is reconnected and the callback function onConnSucc on iOS or onConnected on Android is called successfully.
    ERR_SDK_NET_WAIT_INQUEUE_TIMEOUT            = 9518,    // The request packet timed out when waiting to enter the sending queue. This usually occurs when the network connection setup is slow or the network is frequently disconnected and reconnected. Check whether the network connection is normal.
    ERR_SDK_NET_WAIT_SEND_TIMEOUT               = 9519,    // The request packet entered the IM SDK sending queue but timed out while waiting to enter the network layer of the operating system. This usually occurs when the local network is restricted or disconnected or the local network and the IM SDK backend are not connected. We recommend that you run the IM SDK in different network environments to check whether this issue is caused by the current network environment.
    ERR_SDK_NET_WAIT_ACK_TIMEOUT                = 9520,    // The request packet entered the network layer of the operating system from the IM SDK sending queue but timed out while waiting for a response packet from the server. This usually occurs when the local network is restricted or disconnected or the local network and the IM SDK backend are not connected. We recommend that you run the IM SDK in different network environments to check whether this issue is caused by the current network environment.
    ERR_SDK_NET_WAIT_SEND_REMAINING_TIMEOUT     = 9521,    // The request packet has entered the sending queue, certain data has been sent, but the remaining data timed out when waiting to be sent. This usually occurs because the upstream bandwidth is insufficient or the network is connected when the error is called back. Internal error.
    ERR_SDK_NET_PKG_SIZE_LIMIT                  = 9522,    // The request packet length exceeds the maximum limit of 1 MB.
    ERR_SDK_NET_WAIT_SEND_TIMEOUT_NO_NETWORK    = 9523,    // The request packet has entered the sending queue but timed out when waiting to enter the network buffer of the system. This usually occurs because too many packets are to be sent, the sending thread is too busy to handle the packets, or the network is disconnected when the error is called back. Internal error.
    ERR_SDK_NET_WAIT_ACK_TIMEOUT_NO_NETWORK     = 9524,    // The request packet has entered the network buffer of the system but timed out when waiting for the server to return packets. This usually occurs because the request packet does not leave the client device, is discarded in an intermediate route, or is dropped accidentally by the server, the response packet is discarded by the network layer of the system, or the network is disconnected when the error is called back. Internal error.
    ERR_SDK_NET_SEND_REMAINING_TIMEOUT_NO_NETWORK = 9525,  // The request packet has entered the sending queue, certain data has been sent, but the remaining data timed out when waiting to be sent. This usually occurs because the upstream bandwidth is insufficient or the network is disconnected when the error is called back. Internal error.

    // ///////////////////////////////////////////////////////////////////////////////
    //
    //                             Server error codes
    //
    // ///////////////////////////////////////////////////////////////////////////////

    // Access layer error codes for network

    ERR_SVR_SSO_CONNECT_LIMIT                   = -302  ,  // The number of connections to the server exceeds the limit allowed. The server refused to provide services.
    ERR_SVR_SSO_VCODE                           = -10000,  // The delivered verification code is incorrect.
    ERR_SVR_SSO_D2_EXPIRED                      = -10001,  // Key expired. Key is an internal ticket generated according to UserSig, and the validity period of Key is less than or equal to the validity period of UserSig. Please call the V2TIMManager.getInstance().login again to generate a new Key.
    ERR_SVR_SSO_A2_UP_INVALID                   = -10003,  // Ticket expired. Ticket is an internal ticket generated according to UserSig, and the validity period of Ticket is less than or equal to the validity period of UserSig. Please call the V2TIMManager.getInstance().login again to generate a new Ticket.
    ERR_SVR_SSO_A2_DOWN_INVALID                 = -10004,  // Ticket verification failed or was hit by security. Please call the V2TIMManager.getInstance().login again to generate a new ticket.
    ERR_SVR_SSO_EMPTY_KEY                       = -10005,  // The Key used for encryption cannot be empty.
    ERR_SVR_SSO_UIN_INVALID                     = -10006,  // The account in the Key does not match the account in the request header.
    ERR_SVR_SSO_VCODE_TIMEOUT                   = -10007,  // Verification code delivery timed out.
    ERR_SVR_SSO_NO_IMEI_AND_A2                  = -10008,  // Key and Ticket must be contained.
    ERR_SVR_SSO_COOKIE_INVALID                  = -10009,  // Invalid cookie.
    ERR_SVR_SSO_DOWN_TIP                        = -10101,  // The Key expires when the prompt is issued. Key is an internal ticket generated according to UserSig, and the validity period of Key is less than or equal to the validity period of UserSig. Please call the V2TIMManager.getInstance().login again to generate a new Key.
    ERR_SVR_SSO_DISCONNECT                      = -10102,  // The screen is locked due to network disconnection.
    ERR_SVR_SSO_IDENTIFIER_INVALID              = -10103,  // Invalid identity.
    ERR_SVR_SSO_CLIENT_CLOSE                    = -10104,  // The device is logged out automatically.
    ERR_SVR_SSO_MSFSDK_QUIT                     = -10105,  // The MSFSDK is logged out automatically.
    ERR_SVR_SSO_D2KEY_WRONG                     = -10106,  // If the number of decryption failures exceeds the threshold, the client is notified that it needs to be reset. Please call the TIMManager.getInstance().login again to generate a new key.
    ERR_SVR_SSO_UNSURPPORT                      = -10107,  // he uniform error code is returned to the device because aggregation is not supported. The device stops aggregation on this TCP-based persistent connection.
    ERR_SVR_SSO_PREPAID_ARREARS                 = -10108,  // Overdue prepayment.
    ERR_SVR_SSO_PACKET_WRONG                    = -10109,  // The format of the request packet is incorrect.
    ERR_SVR_SSO_APPID_BLACK_LIST                = -10110,  // The SDKAppID is blocklisted.
    ERR_SVR_SSO_CMD_BLACK_LIST                  = -10111,  // The SDKAppID is on the service CMD blocklist.
    ERR_SVR_SSO_APPID_WITHOUT_USING             = -10112,  // The SDKAppID has been disabled.
    ERR_SVR_SSO_FREQ_LIMIT                      = -10113,  // Exceeded the frequency limit (user). The frequency limit is set for the number of requests per second based on a specific protocol.
    ERR_SVR_SSO_OVERLOAD                        = -10114,  // Packet loss due to overload (system). The connected server has too many requests to process and therefore refuses to provide services.
    ERR_SVR_SSO_FREQUENCY_LIMIT                 = -20009,  // Exceeded the client API call frequency limit。

    // Resource file error codes

    ERR_SVR_RES_NOT_FOUND                       = 114000,  // The resource file to be sent does not exist.
    ERR_SVR_RES_ACCESS_DENY                     = 114001,  // The resource file to be sent cannot be accessed.
    ERR_SVR_RES_SIZE_LIMIT                      = 114002,  // The file size exceeds the limit.
    ERR_SVR_RES_SEND_CANCEL                     = 114003,  // Sending canceled by the user. For example, the user logs out in the sending process.
    ERR_SVR_RES_READ_FAILED                     = 114004,  // Failed to read the file content.
    ERR_SVR_RES_TRANSFER_TIMEOUT                = 114005,  // Resource file (such as an image, document, audio, or video) transfer timed out, usually due to network issues.
    ERR_SVR_RES_INVALID_PARAMETERS              = 114011,  // Invalid parameter.
    ERR_SVR_RES_INVALID_FILE_MD5                = 115066,  // File MD5 verification failed.
    ERR_SVR_RES_INVALID_PART_MD5                = 115068,  // Segment MD5 verification failed.

    // Common backend error codes

    ERR_SVR_COMM_INVALID_HTTP_URL               = 60002,  // HTTP parsing error. Check the URL format of the HTTP request.
    ERR_SVR_COMM_REQ_JSON_PARSE_FAILED          = 60003,  // JSON parsing error. Check the JSON format of the HTTP request.
    ERR_SVR_COMM_INVALID_ACCOUNT                = 60004,  // Identifier or UserSig in the request URI or JSON packet is incorrect.
    ERR_SVR_COMM_INVALID_ACCOUNT_EX             = 60005,  // Identifier or UserSig in the request URI or JSON packet is incorrect.
    ERR_SVR_COMM_INVALID_SDKAPPID               = 60006,  // Invalid SDKAppID. Check the validity of SDKAppID.
    ERR_SVR_COMM_REST_FREQ_LIMIT                = 60007,  // Exceeded the RESTful API call frequency limit. Reduce your request frequency.
    ERR_SVR_COMM_REQUEST_TIMEOUT                = 60008,  // Service request timeout or HTTP request format error. Check and try again.
    ERR_SVR_COMM_INVALID_RES                    = 60009,  // Request resource error. Check the request URL.
    ERR_SVR_COMM_ID_NOT_ADMIN                   = 60010,  // Set the Identifier field of the RESTful API request to the admin account of the app.
    ERR_SVR_COMM_SDKAPPID_FREQ_LIMIT            = 60011,  // Exceeded the SDKAppID request frequency limit. Reduce your request frequency.
    ERR_SVR_COMM_SDKAPPID_MISS                  = 60012,  // SDKAppID is required for RESTful APIs. Check the SDKAppID parameter in the URL.
    ERR_SVR_COMM_RSP_JSON_PARSE_FAILED          = 60013,  // JSON parsing error in the HTTP response body.
    ERR_SVR_COMM_EXCHANGE_ACCOUNT_TIMEUT        = 60014,  // Account switching timeout.
    ERR_SVR_COMM_INVALID_ID_FORMAT              = 60015,  // The type of the Identifier in the request packet is incorrect. Ensure that the Identifier is in string format.
    ERR_SVR_COMM_SDKAPPID_FORBIDDEN             = 60016,  // The SDKAppID is disabled. Please [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) to confirm with technical support.
    ERR_SVR_COMM_REQ_FORBIDDEN                  = 60017,  // The request is disabled. Please [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1) to confirm with technical support.
    ERR_SVR_COMM_REQ_FREQ_LIMIT                 = 60018,  // Too many requests. Please try again later.
    ERR_SVR_COMM_REQ_FREQ_LIMIT_EX              = 60019,  // Too many requests. Please try again later.
    ERR_SVR_COMM_INVALID_SERVICE                = 60020,  // You have not purchased the package, or the package you purchased is currently being configured and has not yet taken effect. Please try again 5 minutes later.
    ERR_SVR_COMM_SENSITIVE_TEXT                 = 80001,  // The text is filtered out due to security policies. The text may contain sensitive words.
    ERR_SVR_COMM_BODY_SIZE_LIMIT                = 80002,  // The outgoing message packet exceeds the length limit of 12 KB. Reduce the packet size and try again.

    //  Account error codes

    ERR_SVR_ACCOUNT_USERSIG_EXPIRED             = 70001,  // UserSig expired. Please generate a new one. It is recommended that the UserSig validity period be set to no less than 24 hours.
    ERR_SVR_ACCOUNT_USERSIG_EMPTY               = 70002,  // The value of UserSig is 0 bytes. Check whether the passed-in UserSig is correct.
    ERR_SVR_ACCOUNT_USERSIG_CHECK_FAILED        = 70003,  // UserSig verification failed. Please check whether UserSig has been truncated due to short buffer length, etc.
    ERR_SVR_ACCOUNT_USERSIG_CHECK_FAILED_EX     = 70005,  // UserSig verification failed. Use a tool to check whether the generated UserSig is correct.
    ERR_SVR_ACCOUNT_USERSIG_MISMATCH_PUBLICKEY  = 70009,  // Failed to verify UserSig with the public key. Please check whether the private key and SDKAppID used to generate UserSig match.
    ERR_SVR_ACCOUNT_USERSIG_MISMATCH_ID         = 70013,  // The identifier in the request does not match the identifier used to generate the UserSig.
    ERR_SVR_ACCOUNT_USERSIG_MISMATCH_SDKAPPID   = 70014,  // The SDKAppID in the request does not match the SDKAppID used to generate the UserSig.
    ERR_SVR_ACCOUNT_USERSIG_PUBLICKEY_NOT_FOUND = 70016,  // The public key does not exist during UserSig verification. Please log in to the console to download the private key first. For details about how to download the private key, see [Downloading a Private Key for Signature](https://cloud.tencent.com/document/product/269/32688#.E4.B8.8B.E8.BD.BD.E7.AD.BE.E5.90.8D.E7.94.A8.E7.9A.84.E7.A7.81.E9.92.A5) 。
    ERR_SVR_ACCOUNT_SDKAPPID_NOT_FOUND          = 70020,  // SDKAppID not found. Check the app information in the IM console.
    ERR_SVR_ACCOUNT_INVALID_USERSIG             = 70052,  // UserSig has expired. Generate a new one and try again.
    ERR_SVR_ACCOUNT_NOT_FOUND                   = 70107,  // The requested user account does not exist.
    ERR_SVR_ACCOUNT_SEC_RSTR                    = 70114,  // Restricted for security reasons.
    ERR_SVR_ACCOUNT_INTERNAL_TIMEOUT            = 70169,  // Server timeout. Try again later.
    ERR_SVR_ACCOUNT_INVALID_COUNT               = 70206,  // Invalid batch number in request.
    ERR_SVR_ACCOUNT_INVALID_PARAMETERS          = 70402,  // Invalid parameter. Check whether the required fields are all set and whether the parameter settings meet the protocol requirements.
    ERR_SVR_ACCOUNT_ADMIN_REQUIRED              = 70403,  // The request requires app admin permissions.
    ERR_SVR_ACCOUNT_FREQ_LIMIT                  = 70050,  // This account is locked from login due to excessive login failures and retries. Please check whether the UserSig is correct and try again in one minute.
    ERR_SVR_ACCOUNT_BLACKLIST                   = 70051,  // The account is blocklisted.
    ERR_SVR_ACCOUNT_COUNT_LIMIT                 = 70398,  // The number of accounts created exceeds the limit of the Free Trial Edition. Please upgrade to the Pro Edition.
    ERR_SVR_ACCOUNT_INTERNAL_ERROR              = 70500,  // Internal server error. Please try again.
    ERR_SVR_ACCOUNT_USER_STATUS_DISABLED        = 72001,  // The user status is not supported, please enable the ability in the console.

    // Profile error codes

    ERR_SVR_PROFILE_INVALID_PARAMETERS          = 40001,  // Incorrect request parameters. Check the request parameters based on the error description.
    ERR_SVR_PROFILE_ACCOUNT_MISS                = 40002,  // Incorrect request parameters. You need to specify the user account whose profile is to be pulled.
    ERR_SVR_PROFILE_ACCOUNT_NOT_FOUND           = 40003,  // The requested user account does not exist.
    ERR_SVR_PROFILE_ADMIN_REQUIRED              = 40004,  // The request requires app admin permissions.
    ERR_SVR_PROFILE_SENSITIVE_TEXT              = 40005,  // Profile fields contain sensitive words.
    ERR_SVR_PROFILE_INTERNAL_ERROR              = 40006,  // Internal server error. Try again later.
    ERR_SVR_PROFILE_READ_PERMISSION_REQUIRED    = 40007,  // No permission to read profile fields. For more information, see [Profile Fields](https://cloud.tencent.com/document/product/269/1500#.E8.B5.84.E6.96.99.E5.AD.97.E6.AE.B5) 。
    ERR_SVR_PROFILE_WRITE_PERMISSION_REQUIRED   = 40008,  // No permission to write profile fields. For more information, see [Profile Fields](https://cloud.tencent.com/document/product/269/1500#.E8.B5.84.E6.96.99.E5.AD.97.E6.AE.B5) 。
    ERR_SVR_PROFILE_TAG_NOT_FOUND               = 40009,  // The tag of the profile field does not exist.
    ERR_SVR_PROFILE_SIZE_LIMIT                  = 40601,  // The value of the profile field exceeds the length limit of 500 bytes.
    ERR_SVR_PROFILE_VALUE_ERROR                 = 40605,  // Incorrect value of the standard profile field. For more information, see [Standard Profile Fields](https://cloud.tencent.com/doc/product/269/1500#.E6.A0.87.E9.85.8D.E8.B5.84.E6.96.99.E5.AD.97.E6.AE.B5) 。
    ERR_SVR_PROFILE_INVALID_VALUE_FORMAT        = 40610,  // Incorrect value type of the profile field. For more information, see [Standard Profile Fields](https://cloud.tencent.com/doc/product/269/1500#.E6.A0.87.E9.85.8D.E8.B5.84.E6.96.99.E5.AD.97.E6.AE.B5) 。

    //  Relationship chain error codes

    ERR_SVR_FRIENDSHIP_INVALID_PARAMETERS       = 30001,  // Incorrect request parameters. Check the request parameters based on the error description.
    ERR_SVR_FRIENDSHIP_INVALID_SDKAPPID         = 30002,  // SDKAppID mismatch.
    ERR_SVR_FRIENDSHIP_ACCOUNT_NOT_FOUND        = 30003,  // The requested user account does not exist.
    ERR_SVR_FRIENDSHIP_ADMIN_REQUIRED           = 30004,  // The request requires app admin permissions.
    ERR_SVR_FRIENDSHIP_SENSITIVE_TEXT           = 30005,  // The relationship chain field contains sensitive words.
    ERR_SVR_FRIENDSHIP_INTERNAL_ERROR           = 30006,  // Internal server error. Please try again.
    ERR_SVR_FRIENDSHIP_NET_TIMEOUT              = 30007,  // Network timeout. Please try again later.
    ERR_SVR_FRIENDSHIP_WRITE_CONFLICT           = 30008,  // A write conflict has occurred due to concurrent writes. You are advised to use batch processing.
    ERR_SVR_FRIENDSHIP_ADD_FRIEND_DENY          = 30009,  // The backend prohibits this user from initiating a friend request.
    ERR_SVR_FRIENDSHIP_COUNT_LIMIT              = 30010,  // Reached the maximum number of friends.
    ERR_SVR_FRIENDSHIP_GROUP_COUNT_LIMIT        = 30011,  // Reached the maximum number of friend lists.
    ERR_SVR_FRIENDSHIP_PENDENCY_LIMIT           = 30012,  // Reached the maximum number of pending friend requests.
    ERR_SVR_FRIENDSHIP_BLACKLIST_LIMIT          = 30013,  // Reached the maximum number of blocklisted users.
    ERR_SVR_FRIENDSHIP_PEER_FRIEND_LIMIT        = 30014,  // The other party has reached the maximum number of friends.
    ERR_SVR_FRIENDSHIP_IN_SELF_BLACKLIST        = 30515,  // This user cannot be added as a friend because this user is on your blocklist.
    ERR_SVR_FRIENDSHIP_ALLOW_TYPE_DENY_ANY      = 30516,  // The user you are trying to add has disabled friend requests.
    ERR_SVR_FRIENDSHIP_IN_PEER_BLACKLIST        = 30525,  // This user cannot be added as a friend because you are on this user's blocklist.
    ERR_SVR_FRIENDSHIP_ALLOW_TYPE_NEED_CONFIRM  = 30539,  // The request is pending. If user A sends a friend request to user B who has set the friend verification mode to AllowType_Type_NeedConfirm, only a pending relationship can be established between users A and B. This return code is used to distinguish from the return code indicating friending success. The caller can capture this error and send a notification to user A.
    ERR_SVR_FRIENDSHIP_ADD_FRIEND_SEC_RSTR      = 30540,  // You have sent too many friend requests in a short amount of time. Request filtered for security reasons.
    ERR_SVR_FRIENDSHIP_PENDENCY_NOT_FOUND       = 30614,  // The pending request does not exist.
    ERR_SVR_FRIENDSHIP_DEL_NONFRIEND            = 31704,  // The account you requested to delete is not your friend.
    ERR_SVR_FRIENDSHIP_DEL_FRIEND_SEC_RSTR      = 31707,  // The friend deletion request was filtered by the security policy. Do not initiate friend deletion requests too frequently.
    ERR_SVR_FRIENDSHIP_ACCOUNT_NOT_FOUND_EX     = 31804,  // The requested user account does not exist.

    //  Error codes for recent contacts

    ERR_SVR_CONV_ACCOUNT_NOT_FOUND              = 50001,  // The requested user account does not exist.
    ERR_SVR_CONV_INVALID_PARAMETERS             = 50002,  // Incorrect request parameters. Check the request parameters based on the error description.
    ERR_SVR_CONV_ADMIN_REQUIRED                 = 50003,  // The request requires app admin permissions.
    ERR_SVR_CONV_INTERNAL_ERROR                 = 50004,  // Internal server error. Please try again.
    ERR_SVR_CONV_NET_TIMEOUT                    = 50005,  // Network timeout. Please try again later.
    
    ERR_SVR_CONV_CONV_MARK_REQ_COUNT_EXCEED_LIMIT     = 51006,  //< The number of conversations for marking, grouping, setting custom data at one time exceeds the limit (maximum 100)
    ERR_SVR_CONV_CONV_MARK_OPERATE_FAILED             = 51007,  //< The group conversation operation is abnormal, the server has an internal error or the group has been dismissed
    ERR_SVR_CONV_CONV_MARK_TOTAL_COUNT_EXCEED_LIMIT   = 51008,  //< The total number of conversations for marking, grouping, setting custom data exceeds the limit (maximum 1000 supported)
    ERR_SVR_CONV_CONV_GROUP_NOT_EXIST                 = 51009,  //< The conversation group does not exist
    ERR_SVR_CONV_CONV_GROUP_TOTAL_COUNT_EXCEED_LIMIT  = 51010,  //< The number of conversation groups exceeds the upper limit (maximum 20)
    ERR_SVR_CONV_CONV_GROUP_NAME_EXCEED_LENGTH        = 51011,  //< The number of bytes of the conversation group name exceeds the upper limit (maximum supported 32 bytes)

    //  Message error codes

    ERR_SVR_MSG_PKG_PARSE_FAILED                = 20001,  // Invalid request packet. Check whether the sender and recipient accounts exist.
    ERR_SVR_MSG_INTERNAL_AUTH_FAILED            = 20002,  // Internal authentication failed.
    ERR_SVR_MSG_INVALID_ID                      = 20003,  // Invalid identifier, or the identifier is not imported into IM.
    ERR_SVR_MSG_NET_ERROR                       = 20004,  // Network exception. Please try again.
    ERR_SVR_MSG_INTERNAL_ERROR1                 = 20005,  // Internal server error. Please try again.
    ERR_SVR_MSG_PUSH_DENY                       = 20006,  // The callback before sending a one-to-one message was triggered, and the app backend returned a response to forbid delivering the message.
    ERR_SVR_MSG_IN_PEER_BLACKLIST               = 20007,  // The one-to-one chat message cannot be sent to the other party because the sender is on the blocklist of the other party.
    ERR_SVR_MSG_BOTH_NOT_FRIEND                 = 20009,  // The message cannot be sent because the sender and the intended recipient are not friends. This problem occurs only when friend verification is configured for one-to-one chats.
    ERR_SVR_MSG_NOT_PEER_FRIEND                 = 20010,  // The one-to-one chat message cannot be sent, because the sender is not a friend of the intended recipient (one-way relationship).
    ERR_SVR_MSG_NOT_SELF_FRIEND                 = 20011,  // The one-to-one chat message cannot be sent, because the intended recipient is not a friend of the sender (one-way relationship).
    ERR_SVR_MSG_SHUTUP_DENY                     = 20012,  // This message cannot be sent, because the sender has been muted.
    ERR_SVR_MSG_REVOKE_TIME_LIMIT               = 20016,  // The message cannot be recalled after the time limit is reached, which is 2 minutes by default.
    ERR_SVR_MSG_DEL_RAMBLE_INTERNAL_ERROR       = 20018,  // An internal error occurs when deleting roaming messages.
    ERR_SVR_MSG_EXTENSION_CONFLICT              = 23001,  // A conflict occurs when multiple people operate on the same message extension at the same time.
    ERR_SVR_MSG_EXTENSION_NOT_EXIST             = 23004,  // The deleted message extension does not exist.
    ERR_SVR_MSG_JSON_PARSE_FAILED               = 90001,  // Failed to parse the JSON format. Check whether the JSON request meets JSON specifications.
    ERR_SVR_MSG_INVALID_JSON_BODY_FORMAT        = 90002,  // The MsgBody field in the JSON request does not meet message format requirements or it is not an array. For more information, see the "Message Element TIMMsgElement" section in [Message Formats](https://cloud.tencent.com/document/product/269/2720#.E6.B6.88.E6.81.AF.E5.85.83.E7.B4.A0timmsgelement)
    ERR_SVR_MSG_INVALID_TO_ACCOUNT              = 90003,  // The JSON request does not contain the To_Account field or the To_Account field is not an integer.
    ERR_SVR_MSG_INVALID_RAND                    = 90005,  // The JSON request does not contain the MsgRandom field or the MsgRandom field is not an integer.
    ERR_SVR_MSG_INVALID_TIMESTAMP               = 90006,  // The MsgTimeStamp field is missing in the JSON request or it is not an integer.
    ERR_SVR_MSG_BODY_NOT_ARRAY                  = 90007,  // The MsgBody field in the JSON request is not an array. Change it to an array.
    ERR_SVR_MSG_ADMIN_REQUIRED                  = 90009,  // The request requires app admin permissions.
    ERR_SVR_MSG_INVALID_JSON_FORMAT             = 90010,  // The JSON request is not in the required message format. For more information, see the "Message Element TIMMsgElement" section in [Message Formats](https://cloud.tencent.com/document/product/269/2720#.E6.B6.88.E6.81.AF.E5.85.83.E7.B4.A0timmsgelement)
    ERR_SVR_MSG_TO_ACCOUNT_COUNT_LIMIT          = 90011,  // The number of target accounts exceeds 500. Delete some To_Account.
    ERR_SVR_MSG_TO_ACCOUNT_NOT_FOUND            = 90012,  // The account specified in To_Account does not exist or is not registered. Make sure the account has been imported to IM and is correct.
    ERR_SVR_MSG_TIME_LIMIT                      = 90026,  // Incorrect offline message storage period. The value cannot exceed 7 days.
    ERR_SVR_MSG_INVALID_SYNCOTHERMACHINE        = 90031,  // The SyncOtherMachine field in the JSON request is not an integer.
    ERR_SVR_MSG_INVALID_MSGLIFETIME             = 90044,  // The MsgLifeTime field in the JSON request is not an integer.
    ERR_SVR_MSG_ACCOUNT_NOT_FOUND               = 90048,  // The requested user account does not exist.
    ERR_SVR_MSG_INTERNAL_ERROR2                 = 90994,  // Internal service error. Please try again.
    ERR_SVR_MSG_INTERNAL_ERROR3                 = 90995,  // Internal service error. Please try again.
    ERR_SVR_MSG_INTERNAL_ERROR4                 = 91000,  // Internal service error. Please try again.
    ERR_SVR_MSG_INTERNAL_ERROR5                 = 90992,  // Internal service error. Please try again. If this error code is returned for all requests and the app has enabled third-party callback, check whether the app server returns callback results to the IM backend properly.
    ERR_SVR_MSG_BODY_SIZE_LIMIT                 = 93000,  // The JSON packet has exceeded the maximum size of 12 KB.
    ERR_SVR_MSG_LONGPOLLING_COUNT_LIMIT         = 91101,  // The web instance is forcibly logged out during long polling because the number of concurrent online web instances exceeds the limit allowed.
    // 120001 - 130000,  // Custom error code returned by third-party callback for a one-to-one chat.

    //  Group error codes

    ERR_SVR_GROUP_INTERNAL_ERROR                = 10002,  // Internal server error. Please try again.
    ERR_SVR_GROUP_API_NAME_ERROR                = 10003,  // Incorrect API name in the request. Check the API name and try again.
    ERR_SVR_GROUP_INVALID_PARAMETERS            = 10004,  // Invalid parameter. Check the error description and troubleshoot the issue.
    ERR_SVR_GROUP_ACOUNT_COUNT_LIMIT            = 10005,  // The request packet carries too many accounts.
    ERR_SVR_GROUP_FREQ_LIMIT                    = 10006,  // The operation exceeds the frequency limit. Please reduce the call frequency.
    ERR_SVR_GROUP_PERMISSION_DENY               = 10007,  // No operation permissions. This error occurs when, for example, a member in a public group tries to remove other users from the group (only the app admin can perform this operation).
    ERR_SVR_GROUP_INVALID_REQ                   = 10008,  // The request is invalid, probably because verification of the signing information in the request failed. Please try again or [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1)  to contact technical support.
    ERR_SVR_GROUP_SUPER_NOT_ALLOW_QUIT          = 10009,  // The group owner is not allowed to leave the group.
    ERR_SVR_GROUP_NOT_FOUND                     = 10010,  // The group does not exist or has been deleted.
    ERR_SVR_GROUP_JSON_PARSE_FAILED             = 10011,  // Failed to parse the JSON packet. Check whether the packet complies with JSON specifications.
    ERR_SVR_GROUP_INVALID_ID                    = 10012,  // Invalid identifier. Check whether the identifier of the user who initiated the operation is entered correctly.
    ERR_SVR_GROUP_ALLREADY_MEMBER               = 10013,  // The invited user is already a member of the group.
    ERR_SVR_GROUP_FULL_MEMBER_COUNT             = 10014,  // The users in the request cannot be added to the group because the group is already full. If you are adding group members in batches, try reducing the number of users being added.
    ERR_SVR_GROUP_INVALID_GROUPID               = 10015,  // Invalid group ID. Use a correct group ID.
    ERR_SVR_GROUP_REJECT_FROM_THIRDPARTY        = 10016,  // The app backend rejected this operation through a third-party callback.
    ERR_SVR_GROUP_SHUTUP_DENY                   = 10017,  // The message cannot be sent due to muting. Check whether the sender is muted.
    ERR_SVR_GROUP_RSP_SIZE_LIMIT                = 10018,  // The response packet exceeds the length limit of 1 MB due to excessive request content. Try to reduce the amount of data in a single request.
    ERR_SVR_GROUP_ACCOUNT_NOT_FOUND             = 10019,  // The requested user account does not exist.
    ERR_SVR_GROUP_GROUPID_IN_USED               = 10021,  // The group ID has already been used by another user. Select another group ID.
    ERR_SVR_GROUP_SEND_MSG_FREQ_LIMIT           = 10023,  // Exceeded the frequency limit for message sending. Try again later.
    ERR_SVR_GROUP_REQ_ALLREADY_BEEN_PROCESSED   = 10024,  // This invitation or app request has already been processed.
    ERR_SVR_GROUP_GROUPID_IN_USED_FOR_SUPER     = 10025,  // The group ID is already in use. The operator is the group owner and therefore can use the group ID directly.
    ERR_SVR_GROUP_SDKAPPID_DENY                 = 10026,  // The command word of the SDKAppID request is disabled. Please [submit a ticket](https://console.cloud.tencent.com/workorder/category?level1_id=29&level2_id=40&source=0&data_title=%E4%BA%91%E9%80%9A%E4%BF%A1%20%20IM&step=1)  to contact technical support.
    ERR_SVR_GROUP_REVOKE_MSG_NOT_FOUND          = 10030,  // The message to be recalled does not exist.
    ERR_SVR_GROUP_REVOKE_MSG_TIME_LIMIT         = 10031,  // The message cannot be recalled after the time limit is reached, which is 2 minutes by default.
    ERR_SVR_GROUP_REVOKE_MSG_DENY               = 10032,  // The message to be recalled cannot be recalled.
    ERR_SVR_GROUP_NOT_ALLOW_REVOKE_MSG          = 10033,  // This type of group does not support message recalling.
    ERR_SVR_GROUP_REMOVE_MSG_DENY               = 10034,  // This type of message cannot be deleted.
    ERR_SVR_GROUP_NOT_ALLOW_REMOVE_MSG          = 10035,  // Audio-video groups and broadcasting chat rooms do not support message deletion.
    ERR_SVR_GROUP_AVCHATROOM_COUNT_LIMIT        = 10036,  // Exceeded the limit on the number of audio-video chat rooms that can be created. To purchase the "IM audio-video group" prepaid plan, see [Pricing](https://cloud.tencent.com/document/product/269/11673)
    ERR_SVR_GROUP_COUNT_LIMIT                   = 10037,  //  Exceeded the limit on the number of groups a single user can create and join. To purchase or upgrade to the "Increasing the maximum number of groups a single user can create and join" prepaid plan, see [Pricing](https://cloud.tencent.com/document/product/269/11673)
    ERR_SVR_GROUP_MEMBER_COUNT_LIMIT            = 10038,  //  Exceeded the limit on the number of group members. To purchase or upgrade the "Increasing the maximum number of members in a single group" prepaid plan, see [Pricing](https://cloud.tencent.com/document/product/269/11673)
    ERR_SVR_GROUP_ATTRIBUTE_WRITE_CONFILCT      = 10056,  ///< Group attribute write conflict. Please get the latest group attribute before writing. This error code is supported in IM SDK 5.6 or above.

    /////////////////////////////////////////////////////////////////////////////////
    //
    //                      IM SDK V3 error codes
    //
    /////////////////////////////////////////////////////////////////////////////////

    ERR_NO_SUCC_RESULT                          = 6003,   ///< No success results for a batch operation.
    ERR_TO_USER_INVALID                         = 6011,   ///< Invalid recipient.
    ERR_REQUEST_TIME_OUT                        = 6012,   ///< Request timed out.
    ERR_INIT_CORE_FAIL                          = 6018,   ///< INIT CORE module failed.
    ERR_EXPIRED_SESSION_NODE                    = 6020,   ///< SessionNode is null.
    ERR_LOGGED_OUT_BEFORE_LOGIN_FINISHED        = 6023,   ///< This error is returned (during login) when you log out before login is completed.
    ERR_TLSSDK_NOT_INITIALIZED                  = 6024,   ///< The TLS SDK has not been initialized.
    ERR_TLSSDK_USER_NOT_FOUND                   = 6025,   ///< The TLS SDK failed to find the corresponding user information.
    ERR_BIND_FAIL_UNKNOWN                       = 6100,   ///< The QALSDK failed to perform the BIND operation due to unknown reasons.
    ERR_BIND_FAIL_NO_SSOTICKET                  = 6101,   ///< SSO ticket missing.
    ERR_BIND_FAIL_REPEATD_BIND                  = 6102,   ///< Repeated BIND.
    ERR_BIND_FAIL_TINYID_NULL                   = 6103,   ///< TinyId is empty.
    ERR_BIND_FAIL_GUID_NULL                     = 6104,   ///< GUID is empty.
    ERR_BIND_FAIL_UNPACK_REGPACK_FAILED         = 6105,   ///< Failed to parse the registration packet.
    ERR_BIND_FAIL_REG_TIMEOUT                   = 6106,   ///< Registration timed out.
    ERR_BIND_FAIL_ISBINDING                     = 6107,   ///< BIND operation in progress.
    ERR_PACKET_FAIL_UNKNOWN                     = 6120,   ///< An unknown error occurred when sending the packet.
    ERR_PACKET_FAIL_REQ_NO_NET                  = 6121,   ///< No network connection when sending the request packet.
    ERR_PACKET_FAIL_RESP_NO_NET                 = 6122,   ///< No network connection when sending the response packet.
    ERR_PACKET_FAIL_REQ_NO_AUTH                 = 6123,   ///< No permission when sending the request packet.
    ERR_PACKET_FAIL_SSO_ERR                     = 6124,   ///< SSO error.
    ERR_PACKET_FAIL_REQ_TIMEOUT                 = 6125,   ///< Request timed out.
    ERR_PACKET_FAIL_RESP_TIMEOUT                = 6126,   ///< Response timed out.
    ERR_PACKET_FAIL_REQ_ON_RESEND               = 6127,   ///< Resending failed.
    ERR_PACKET_FAIL_RESP_NO_RESEND              = 6128,   ///< Not actually sent during resending.
    ERR_PACKET_FAIL_FLOW_SAVE_FILTERED          = 6129,   ///< The stored data is filtered.
    ERR_PACKET_FAIL_REQ_OVER_LOAD               = 6130,   ///< Delivery overloaded.
    ERR_PACKET_FAIL_LOGIC_ERR                   = 6131,   ///< Data logic error.
    ERR_FRIENDSHIP_PROXY_NOT_SYNCED             = 6150,   ///< proxy_manager did not finish data sync to the server.
    ERR_FRIENDSHIP_PROXY_SYNCING                = 6151,   ///< proxy_manager is synchronizing data to the server.
    ERR_FRIENDSHIP_PROXY_SYNCED_FAIL            = 6152,   ///< proxy_manager failed to sync data.
    ERR_FRIENDSHIP_PROXY_LOCAL_CHECK_ERR        = 6153,   ///< The request parameters of proxy_manager were found to be invalid in local check.
    ERR_GROUP_INVALID_FIELD                     = 6160,   ///< Request fields from the group assistant contain non-preset fields.
    ERR_GROUP_STORAGE_DISABLED                  = 6161,   ///< The group assistant did not enable the local storage of the group profile.
    ERR_LOADGRPINFO_FAILED                      = 6162,   ///< Failed to load the group profile.
    ERR_REQ_NO_NET_ON_REQ                       = 6200,   ///< No network connection when sending the request.
    ERR_REQ_NO_NET_ON_RSP                       = 6201,   ///< No network connection when sending the response.
    ERR_SERIVCE_NOT_READY                       = 6205,   ///< QALSDK service not ready.
    ERR_LOGIN_AUTH_FAILED                       = 6207,   ///< Account authentication failed due to TinyId conversion failure.
    ERR_NEVER_CONNECT_AFTER_LAUNCH              = 6209,   ///< The app did not attempt to connect to the network after being started.
    ERR_REQ_FAILED                              = 6210,   ///< QALSDK execution failed.
    ERR_REQ_INVALID_REQ                         = 6211,   ///< Invalid request due to invalid toMsgService.
    ERR_REQ_OVERLOADED                          = 6212,   ///< The request queue is full.
    ERR_REQ_KICK_OFF                            = 6213,   ///< You have been logged out because your account is logged in on another device.
    ERR_REQ_SERVICE_SUSPEND                     = 6214,   ///< Service suspended.
    ERR_REQ_INVALID_SIGN                        = 6215,   ///< SSO signature error.
    ERR_REQ_INVALID_COOKIE                      = 6216,   ///< Invalid SSO cookie.
    ERR_LOGIN_TLS_RSP_PARSE_FAILED              = 6217,   ///< Incorrect packet length. This error occurs when the TLS SDK performs verification on response packets during login.
    ERR_LOGIN_OPENMSG_TIMEOUT                   = 6218,   ///< Status report from OPENSTATSVC to OPENMSG timed out during login.
    ERR_LOGIN_OPENMSG_RSP_PARSE_FAILED          = 6219,   ///< Failed to parse the response packet when OPENSTATSVC reported status to OPENMSG during login.
    ERR_LOGIN_TLS_DECRYPT_FAILED                = 6220,   ///< TLS SDK decryption during login failed.
    ERR_WIFI_NEED_AUTH                          = 6221,   ///< Wi-Fi requires authentication.
    ERR_USER_CANCELED                           = 6222,   ///< Canceled by the user.
    ERR_REVOKE_TIME_LIMIT_EXCEED                = 6223,   ///< The message cannot be recalled after the time limit is reached, which is 2 minutes by default.
    ERR_LACK_UGC_EXT                            = 6224,   ///< The UGC extension package is missing.
    ERR_AUTOLOGIN_NEED_USERSIG                  = 6226,   ///< Auto login failed because the local ticket expired. Manual login with the UserSig is needed.
    ERR_QAL_NO_SHORT_CONN_AVAILABLE             = 6300,   ///< No available SSO for short connections.
    ERR_REQ_CONTENT_ATTACK                      = 80101,  ///< Message content is filtered for security reasons.
    ERR_LOGIN_SIG_EXPIRE                        = 70101,  ///< Ticket expired. This error is returned during login.
    ERR_SDK_HAD_INITIALIZED                     = 90101,  ///< The IM SDK has been initialized and does not need to be re-initialized.
    ERR_OPENBDH_BASE                            = 115000, ///< OpenBDH error code.
    ERR_REQUEST_NO_NET_ONREQ                    = 6250,   ///< No network connection when sending the request. Please try again after the network connection is recovered.
    ERR_REQUEST_NO_NET_ONRSP                    = 6251,   ///< No network connection when sending the response. Please try again after the network connection is recovered.
    ERR_REQUEST_FAILED                          = 6252,   ///< QALSDK execution failed.
    ERR_REQUEST_INVALID_REQ                     = 6253,   ///< Invalid request due to invalid toMsgService.
    ERR_REQUEST_OVERLOADED                      = 6254,   ///< The request queue is full.
    ERR_REQUEST_KICK_OFF                        = 6255,   ///< You have been logged out because your account is logged in on another device.
    ERR_REQUEST_SERVICE_SUSPEND                 = 6256,   ///< Service suspended.
    ERR_REQUEST_INVALID_SIGN                    = 6257,   ///< SSO signature error.
    ERR_REQUEST_INVALID_COOKIE                  = 6258,   ///< Invalid SSO cookie.
};

#endif  // __V2TIM_ERROR_CODE_H__
