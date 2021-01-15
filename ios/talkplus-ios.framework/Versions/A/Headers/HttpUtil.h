//
//  HttpUtil.h
//  talkplus-ios
//
//  Created by 최치웅 on 2020/09/23.
//

#import <Foundation/Foundation.h>

#define TALKPLUS_ERROR_DOMAIN @"error.talkplus.io"

@interface HttpUtil : NSObject

+ (HttpUtil *)sharedInstance;
-(void)initWithAppId:(NSString *)appId;
-(void)setSessionToken:(NSString *)token;

-(void)postJsonRequest:(NSURL *) requestUrl data:(NSData *)jsonData success:(void (^)(NSDictionary * dict))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)putJsonRequest:(NSURL *) requestUrl data:(NSData *)jsonData success:(void (^)(NSDictionary * dict))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getRequest:(NSURL *) requestUrl success:(void (^)(NSDictionary * dict))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)getGZipRequest:(NSURL *)requestUrl success:(void (^)(NSDictionary * dict))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
-(void)deleteRequest:(NSURL *) requestUrl success:(void (^)(NSDictionary * dict))successBlock failure:(void (^)(int errorCode, NSError *error))failureBlock;
@end
