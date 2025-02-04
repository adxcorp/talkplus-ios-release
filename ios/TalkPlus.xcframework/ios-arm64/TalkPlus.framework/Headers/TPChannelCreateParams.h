//  TPChannelCreateParams.h

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, TPChannelCreateType) {
    TPChannelPublic,
    TPChannelSuperPublic,
    TPChannelPrivate,
    TPChannelSuperPrivate,
    TPChannelInvitationOnly,
    TPChannelBroadCast,
    TPChannelSuperBroadCast,
};

@interface TPChannelCreateParams : NSObject
@property (strong) NSArray<NSString *> * targetIds;
@property (strong) NSString * channelId;
@property (assign) BOOL reuseChannel;
@property (assign) NSInteger maxMemberCount;
@property (assign) BOOL hideMessagesBeforeJoin;
@property (assign) TPChannelCreateType channelType;
@property (strong) NSString * channelName;
@property (strong) NSString * invitationCode;
@property (strong) NSString * category;
@property (strong) NSString * subcategory;
@property (strong) UIImage * image;
@property (strong) NSString * imageUrl;
@property (strong) NSDictionary * metaData;

- (instancetype)initWithChannelType:(TPChannelCreateType)channelType;
- (instancetype)initWithInvitationCode:(NSString *)invitationCode;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end
