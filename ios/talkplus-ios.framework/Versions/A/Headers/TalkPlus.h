//
//  TalkPlus.h
//  talkplus-ios
//
//  Created by 최치웅 on 2020/09/21.
//

#import <Foundation/Foundation.h>
#import "TPUser.h"
#import "TPChannel.h"
#import "TPMessage.h"

@protocol TPChannelDelegate <NSObject>
@required

-(void)memberAdded:(TPChannel *)tpChannel users:(NSArray *)users;
-(void)memberLeft:(TPChannel *)tpChannel users:(NSArray *)users;
-(void)messageReceived:(TPChannel *)tpChannel message:(TPMessage *)tpMessage;
-(void)channelChanged:(TPChannel *)tpChannel;

@end

@interface TalkPlus : NSObject

+ (TalkPlus *)sharedInstance;

-(void)initWithAppId:(NSString *)appId;

-(TPUser *)getCurrentUser;

-(void)handleFCMMessage:(NSString *)payload;

-(void)loginWithAnonymous:(NSString *)userId username:(NSString *)username profileImageUrl:(NSString *)profileImageUrl success:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)loginWithToken:(NSString *)loginToken userId:(NSString *)userId username:(NSString *)username profileImageUrl:(NSString *)profileImageUrl success:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)logout:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)registerFCMToken:(NSString *)fcmToken success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)updateUserProfile:(NSString *)username profileImageUrl:(NSString *)profileImageUrl success:(void (^)(TPUser *tpUser))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)deleteUser:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getBlockedUserList:(TPUser *)lastUser success:(void (^)(NSArray * tpUserArray))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)blockUser:(NSString *)targetId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unblockUser:(NSString *)targetId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)getTotalUnreadCount:(void (^)(int totalCount))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getChannelList:(TPChannel *)lastChannel success:(void (^)(NSArray * tpChannelArray))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getHiddenChannelList:(TPChannel *)lastChannel success:(void (^)(NSArray * tpChannelArray))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)createChannelWithUserId:(NSString *)targetId channelId:(NSString *)channelId reuseChannel:(BOOL)reuseChannel channelType:(NSString *)channelType channelName:(NSString *)channelName invitationCode:(NSString *)invitationCode success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)createChannelWithUserIds:(NSArray *)targetIds channelId:(NSString *)channelId reuseChannel:(BOOL)reuseChannel channelType:(NSString *)channelType channelName:(NSString *)channelName invitationCode:(NSString *)invitationCode success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)updateChannel:(TPChannel *)tpChannel channelName:(NSString *)channelName invitationCode:(NSString *)invitationCode success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)sendMessage:(TPChannel *)tpChannel text:(NSString *)text type:(NSString *)type metaData:(NSDictionary *)metaData success:(void (^)(TPMessage * tpMessage))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getMessageList:(TPChannel *)tpChannel lastMessage:(TPMessage *)lastMessage success:(void (^)(NSArray * tpChannelArray))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)markAsReadChannel:(TPChannel *)tpChannel success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)markAsReadAllChannel:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)hideChannel:(NSString *)channelId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)hideAllChannel:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)showChannel:(NSString *)channelId success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)joinChannel:(NSString *)channelId success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)joinChannel:(NSString *)channelId invitationCode:(NSString *)invitationCode success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)leaveChannel:(TPChannel *)tpChannel success:(void (^)(void))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)addMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)addMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)removeMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)removeMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)banMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)banMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unBanMemberToChannel:(TPChannel *)tpChannel userId:(NSString *)userId success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)unBanMemberToChannel:(TPChannel *)tpChannel userIds:(NSArray *)userIds success:(void (^)(TPChannel * tpChannel))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;

-(void)addChannelDelegate:(id<TPChannelDelegate>)delegate tag:(NSString *)tag;
-(void)removeChannelDelegate:(NSString *)tag;
-(void)removeAllChannelDelegate;

-(void)fireMemberAdded:(NSDictionary *)channelDict users:(NSArray *)userDictArray;
-(void)fireMemberLeft:(NSDictionary *)channelDict users:(NSArray *)userDictArray;
-(void)fireMessageReceived:(NSDictionary *)channelDict message:(NSDictionary *)messageDict;
-(void)fireChannelChanged:(NSDictionary *)channelDict;

@end
