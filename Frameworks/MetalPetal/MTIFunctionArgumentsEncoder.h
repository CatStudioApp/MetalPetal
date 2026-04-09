//
//  MTIFunctionArgumentsEncoder.h
//  MetalPetal
//
//  Created by YuAo on 2020/7/11.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MTIFunctionArgumentEncodingProxy <NSObject>

- (void)encodeBytes:(const void *)bytes length:(NSUInteger)length;

@end

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

@protocol MTIFunctionArgumentEncoding <NSObject>

+ (BOOL)encodeValue:(id)value argument:(MTLArgument *)argument proxy:(id<MTIFunctionArgumentEncodingProxy>)proxy error:(NSError **)error;

@end

__attribute__((objc_subclassing_restricted))
@interface MTIFunctionArgumentsEncoder : NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

+ (BOOL)encodeArguments:(NSArray<MTLArgument *>*)arguments
                 values:(NSDictionary<NSString *, id> *)parameters
           functionType:(MTLFunctionType)functionType
                encoder:(id<MTLCommandEncoder>)encoder
                  error:(NSError **)error;

@end

#pragma clang diagnostic pop


NS_ASSUME_NONNULL_END
