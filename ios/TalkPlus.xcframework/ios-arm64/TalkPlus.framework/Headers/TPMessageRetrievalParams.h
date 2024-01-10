//
//  TPMessageRetrievalParams.h
//  TalkPlus
//
//  Created by JCLEE on 1/5/24.
//

#import <Foundation/Foundation.h>
#import <TalkPlus/TPChannel.h>
#import <TalkPlus/TPMessage.h>

@interface TPMessageRetrievalParams : NSObject
@property (strong) TPChannel * channel;
@property (strong) TPMessage * lastMessage;
@property (strong) NSString * messageId;
@property (strong) NSString * translationLanguage;

- (instancetype)initWithChannel:(TPChannel *)channel;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end
