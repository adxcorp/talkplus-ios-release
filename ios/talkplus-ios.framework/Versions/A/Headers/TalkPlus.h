//
//  TalkPlus.h
//  talkplus-ios
//
//  Created by 최치웅 on 2020/09/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "TPUser.h"
#import "TPChannel.h"
#import "TPMessage.h"

@protocol TPChannelDelegate <NSObject>
@required

-(void)memberAdded:(TPChannel *)tpChannel users:(NSArray<TPUser *> *)users;
-(void)memberLeft:(TPChannel *)tpChannel users:(NSArray<TPUser *> *)users;
-(void)messageReceived:(TPChannel *)tpChannel message:(TPMessage *)tpMessage;
-(void)channelAdded:(TPChannel *)tpChannel;
-(void)channelChanged:(TPChannel *)tpChannel;
-(void)channelRemoved:(TPChannel *)tpChannel;

@end

@interface TalkPlus : NSObject

+ (TalkPlus *)sharedInstance;

-(void)initWithAppId:(NSString *)appId;

-(TPUser *)getCurrentUser;

#pragma mark - User Auth
-(void)loginWithAnonymous:(NSString *)userId username:(NSString *)username profileImageUrl:(NSString *)profileImageUrl metaData:(NSDictionary *)metaData success:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)loginWithAnonymous:(NSString *)userId username:(NSString *)username profileImage:(UIImage *)profileImage metaData:(NSDictionary *)metaData success:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)loginWithToken:(NSString *)loginToken userId:(NSString *)userId username:(NSString *)username profileImageUrl:(NSString *)profileImageUrl metaData:(NSDictionary *)metaData success:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)loginWithToken:(NSString *)loginToken userId:(NSString *)userId username:(NSString *)username profileImage:(UIImage *)profileImage metaData:(NSDictionary *)metaData success:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - User Update
-(void)updateUserProfile:(NSString *)username profileImageUrl:(NSString *)profileImageUrl metaData:(NSDictionary *)metaData success:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)updateUserProfile:(NSString *)username profileImage:(UIImage *)profileImage metaData:(NSDictionary *)metaData success:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Push Notification Enable/Disable
-(void)enablePushNotification:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)disablePushNotification:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - User Block / Unblock
-(void)blockUser:(NSString *)targetId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unblockUser:(NSString *)targetId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getBlockedUserList:(TPUser *)lastUser success:(void (^)(NSArray<TPUser *> *tpUsers))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - User Delete / Logout
-(void)logout:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)deleteUser:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Create / Update
-(void)createChannelWithUserId:(NSString *)targetId channelId:(NSString *)channelId reuseChannel:(BOOL)reuseChannel maxMemberCount:(int)maxMemberCount hideMessagesBeforeJoin:(BOOL)hideMessagesBeforeJoin channelType:(NSString *)channelType channelName:(NSString *)channelName invitationCode:(NSString *)invitationCode imageUrl:(NSString *)imageUrl metaData:(NSDictionary *)metaData success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)createChannelWithUserIds:(NSArray *)targetIds channelId:(NSString *)channelId reuseChannel:(BOOL)reuseChannel maxMemberCount:(int)maxMemberCount hideMessagesBeforeJoin:(BOOL)hideMessagesBeforeJoin channelType:(NSString *)channelType channelName:(NSString *)channelName invitationCode:(NSString *)invitationCode imageUrl:(NSString *)imageUrl metaData:(NSDictionary *)metaData success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)updateChannel:(TPChannel *)tpChannel maxMemberCount:(int)maxMemberCount hideMessagesBeforeJoin:(BOOL)hideMessagesBeforeJoin channelName:(NSString *)channelName invitationCode:(NSString *)invitationCode imageUrl:(NSString *)imageUrl metaData:(NSDictionary *)metaData success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel List
-(void)getPublicChannelList:(TPChannel *)lastChannel success:(void (^)(NSArray<TPChannel *> *tpChannels))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getChannelList:(TPChannel *)lastChannel success:(void (^)(NSArray<TPChannel *> *tpChannels))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getHiddenChannelList:(TPChannel *)lastChannel success:(void (^)(NSArray<TPChannel *> *tpChannels))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getTotalUnreadCount:(void (^)(int totalCount))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Member
-(void)addMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)addMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)removeMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)removeMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)banMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)banMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unBanMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unBanMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)muteMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)muteMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unMuteMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unMuteMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Join / Leave
-(void)joinChannel:(NSString *)channelId success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)joinChannel:(NSString *)channelId invitationCode:(NSString *)invitationCode success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)leaveChannel:(TPChannel *)tpChannel deleteChannelIfEmpty:(BOOL)deleteChannelIfEmpty success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Message
-(void)getMessageList:(TPChannel *)tpChannel lastMessage:(TPMessage *)lastMessage success:(void (^)(NSArray<TPMessage *> *tpMessages))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)sendMessage:(TPChannel *)tpChannel text:(NSString *)text type:(NSString *)type metaData:(NSDictionary *)metaData success:(void (^)(TPMessage *tpMessage))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)sendFileMessage:(TPChannel *)tpChannel text:(NSString *)text type:(NSString *)type metaData:(NSDictionary *)metaData filePath:(NSString *)filePath  success:(void (^)(TPMessage * tpMessage))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)markAsReadChannel:(TPChannel *)tpChannel success:(void (^)(TPChannel *tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)markAsReadAllChannel:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Hide / Show
-(void)hideChannel:(NSString *)channelId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)hideAllChannel:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)showChannel:(NSString *)channelId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - Channel Freeze / Unfreeze
-(void)freezeChannel:(NSString *)channelId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unfreezeChannel:(NSString *)channelId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

#pragma mark - TPChannelDelegate
-(void)addChannelDelegate:(id<TPChannelDelegate>)delegate tag:(NSString *)tag;
-(void)removeChannelDelegate:(NSString *)tag;
-(void)removeAllChannelDelegate;

#pragma mark - Push Notification
-(void)registerFCMToken:(NSString *)fcmToken success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)handleFCMMessage:(NSString *)payload;

@end
