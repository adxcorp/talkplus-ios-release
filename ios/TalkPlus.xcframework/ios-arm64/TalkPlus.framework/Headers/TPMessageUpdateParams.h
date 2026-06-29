//
//  TPMessageUpdateParams.h
//  TalkPlus
//
//  Created by choiseungmyeong on 6/23/26.
//

#import <Foundation/Foundation.h>
#import <TalkPlus/TPMessageSendParams.h>
#import <TalkPlus/TPChannel.h>
#import <TalkPlus/TPMessage.h>

@interface TPMessageUpdateParams : NSObject

@property (copy, readonly, nonnull) NSString *messageId;
@property (copy, readonly, nonnull) NSString *channelId;
@property (strong, nullable) NSString *messageType;
@property (copy, nullable) NSString *updatedTextMessage;
@property (copy, nullable) NSDictionary *metaData;
@property (copy, nullable) NSArray<NSString *> *mentionUserIDs;
@property (assign) BOOL clearReactions;
@property (assign) BOOL clearTranslations;

- (instancetype _Nonnull)initWithMessageId:(NSString * _Nonnull)messageId
                                  channelId:(NSString * _Nonnull)channelId;

- (instancetype _Nonnull)initWithTargetMessage:(TPMessage * _Nonnull)message;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
+ (instancetype _Nonnull)new NS_UNAVAILABLE;

@end

