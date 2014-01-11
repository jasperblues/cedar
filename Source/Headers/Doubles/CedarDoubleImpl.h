#import <Foundation/Foundation.h>
#import "StubbedMethod.h"
#import "RejectedMethod.h"

@protocol CedarDouble;

typedef enum {
    CDRStubMethodNotStubbed = 0,
    CDRStubMethodInvoked,
    CDRStubWrongArguments,
} CDRStubInvokeStatus;

@interface CedarDoubleImpl : NSObject 

@property (nonatomic, retain, readonly) NSMutableArray *sent_messages;

+ (void)afterEach;

- (id)initWithDouble:(NSObject<CedarDouble> *)parent_double;

- (void)reset_sent_messages;

- (Cedar::Doubles::StubbedMethod &)add_stub:(const Cedar::Doubles::StubbedMethod &)stubbed_method;
- (void)reject_method:(const Cedar::Doubles::RejectedMethod &)rejected_method;

- (Cedar::Doubles::StubbedMethod::selector_map_t &)stubbed_methods;
- (CDRStubInvokeStatus)invoke_stubbed_method:(NSInvocation *)invocation;
- (void)record_method_invocation:(NSInvocation *)invocation;
- (BOOL)has_stubbed_method_for:(SEL)selector;
- (BOOL)has_rejected_method_for:(SEL)selector;

@end
