//  TPChannelUpdateParams.h
#import <UIKit/UIKit.h>
#import <TalkPlus/TPChannel.h>

@interface TPChannelUpdateParams : NSObject
@property (assign) NSInteger maxMemberCount;
@property (assign) BOOL hideMessagesBeforeJoin;
@property (strong) TPChannel * channel;
@property (strong) NSString * channelName;
@property (strong) NSString * invitationCode;
@property (strong) NSString * category;
@property (strong) NSString * subcategory;
@property (strong) UIImage * image;
@property (strong) NSString * imageUrl;
@property (strong) NSDictionary * metaData;

- (instancetype)initWithChannel:(TPChannel *)channel;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end
